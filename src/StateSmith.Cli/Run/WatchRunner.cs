using StateSmith.Cli.Utils;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Threading;

namespace StateSmith.Cli.Run;

public class WatchRunner
{
    private RunConsole _console;
    private CsxRunner _csxRunner;
    private DiagramRunner _diagramRunner;
    private readonly RunInfo _runInfo;
    private List<string> _csxFilesToRun = new();
    private List<string> _diagramFilesToRun = new();
    private readonly RunHandlerOptions _runHandlerOptions;
    private readonly RunInfoDataBase _runInfoDataBase;
    private readonly string _searchDirectory;

    private SuccessTracker _successTracker = new();

    private bool IsVerbose => _runHandlerOptions.Verbose;
    private bool IsNoCsx => _runHandlerOptions.NoCsx;

    public WatchRunner(RunConsole console, CsxRunner csxRunner, DiagramRunner diagramRunner, RunInfo runInfo, RunHandlerOptions runHandlerOptions, RunInfoDataBase runInfoDataBase, string searchDirectory)
    {
        _console = console;
        var silentConsole = console.CloneWithoutSettings();
        silentConsole.SetSilent(true);

        _csxRunner = csxRunner;
        _csxRunner.SetConsole(silentConsole);
        _diagramRunner = diagramRunner;

        _runInfo = runInfo;
        _runHandlerOptions = runHandlerOptions;
        _runInfoDataBase = runInfoDataBase;
        _searchDirectory = searchDirectory;
    }

    public void Run(SsCsxDiagramFileFinder.ScanResults scanResults)
    {
        if (!IsNoCsx)
        {
            _csxFilesToRun.AddRange(scanResults.targetCsxFiles);
        }
        else
        {
            if (IsVerbose)
            {
                _console.QuietMarkupLine("Ignoring all .csx scripts for --no-csx.");
            }
        }

        _diagramFilesToRun.AddRange(scanResults.targetDiagramFiles);

        RunInner();
    }

    private void RunInner()
    {
        bool noFilesToRun = true;

        if (_diagramFilesToRun.Count > 0)
        {
            _console.MarkupLine("Watching the following diagram files:");
            foreach (var diagramFile in _diagramFilesToRun)
            {
                _console.MarkupLine($"- {diagramFile}");
                noFilesToRun = false;
            }
        }

        noFilesToRun = SetupAndPrintCsxFiles(noFilesToRun);

        if (noFilesToRun)
        {
            _console.MarkupLine("No files to watch.");
        }
        else
        {
            Stopwatch messageStopwatch = new();
            messageStopwatch.Start();
            UiHelper.AddSectionLeftHeader(_console.GetIAnsiConsole(), "Watching Files");

            while (true)
            {
                WatchIterate(messageStopwatch);
                Thread.Sleep(1000);
            }
        }
    }

    private void WatchIterate(Stopwatch messageStopwatch)
    {
        bool ranFiles = false;

        // scan through files and see if they need to be run
        foreach (var relPath in _diagramFilesToRun)
        {
            ranFiles |= RunDiagramFileIfNeeded(ranFiles, relPath);
        }

        if (ranFiles)
        {
            messageStopwatch.Start();
        }

        if (messageStopwatch.ElapsedMilliseconds > 1000)
        {
            if (_successTracker.SuccessfulSources.Count > 0)
            {
                _console.MarkupLine($"[green]Successful sources: {_successTracker.SuccessfulSources.Count} [/]");
            }

            if (_successTracker.FailedSources.Count > 0)
            {
                _console.MarkupLine("[red]Failed sources:[/]");
                foreach (var source in _successTracker.FailedSources)
                {
                    _console.MarkupLine($"- [red]{source}[/]");
                }
            }
            messageStopwatch.Reset();
            _console.QuietMarkupLine("Watching files for changes...\n");
        }
    }

    private bool RunDiagramFileIfNeeded(bool ranFiles, string diagramRelPath)
    {
        var diagramAbsPath = MakeAbsolute(diagramRelPath);
        if (_runInfo.FindCsxWithDiagram(diagramAbsPath) != null)
        {
            return false;
        }
        _runInfo.diagramRuns.TryGetValue(diagramAbsPath, out var runInfo);

        DateTime lastRun;

        if (runInfo == null)
        {
            lastRun = DateTime.MinValue;
        }
        else
        {
            lastRun = runInfo.lastCodeGenStartDateTime;
        }

        var fileInfo = new FileInfo(diagramRelPath);
        if (fileInfo.Exists && fileInfo.LastWriteTime >= lastRun)
        {
            ranFiles = true;

            try
            {
                //UiHelper.AddSectionLeftHeader(_console.GetIAnsiConsole(), "Change detected: " + diagramRelPath);
                _console.QuietMarkupLine($"Change detected: {diagramRelPath}");
                _diagramRunner.RunDiagramFile(shortPath: diagramRelPath, absolutePath: diagramAbsPath, _runInfo);
                _successTracker.AddSuccess(diagramRelPath);
            }
            catch (Exception)
            {
                _console.ErrorMarkupLine($"Error running diagram file: {diagramRelPath}");
                _successTracker.AddFailure(diagramRelPath);
                //_console.WriteException(e);
            }
            _console.WriteLine("");

            _runInfoDataBase.PersistRunInfo(_runInfo);
        }

        return ranFiles;
    }

    private string MakeAbsolute(string path)
    {
        return Path.GetFullPath(Path.Combine(_searchDirectory, path));
    }

    private bool SetupAndPrintCsxFiles(bool noFilesToRun)
    {
        if (_csxFilesToRun.Count > 0)
        {
            _console.MarkupLine("Watching the following csx files:");
            foreach (var csxFile in _csxFilesToRun)
            {
                _console.MarkupLine($"- {csxFile}");
                noFilesToRun = false;
            }
        }

        (string? versionString, Exception? exception) = DotnetScriptProgram.TryGetVersionString();
        if (versionString == null)
        {
            _console.ErrorMarkupLine($"Did not detect `{DotnetScriptProgram.Name}` program.");
            _console.WarnMarkupLine($"Not attempting to run StateSmith .csx scripts:");
            foreach (var path in _csxFilesToRun)
            {
                _console.WarnMarkupLine("    " + path);
            }
            _console.WriteLine("");

            if (IsVerbose)
            {
                _console.WriteLine("Attempted command to detect version:");
                _console.WriteException(exception!);
                _console.WriteLine("");
            }

            _csxFilesToRun.Clear();
        }

        if (_csxFilesToRun.Count > 0)
        {
            UiHelper.AddSectionLeftHeader(_console.GetIAnsiConsole(), "Checking .csx file dependencies");

            foreach (var csxRelPath in _csxFilesToRun)
            {
                try
                {
                    _csxRunner.RunScriptsIfNeeded(_csxFilesToRun, _runInfo, out var _);
                    _successTracker.AddSuccess(csxRelPath);
                }
                catch (Exception e)
                {
                    _console.WriteException(e);
                    _successTracker.AddFailure(csxRelPath);
                }
            }

            _runInfoDataBase.PersistRunInfo(_runInfo);  // todolow - only do if needed
            _console.WriteLine("done checking dependencies");
        }

        return noFilesToRun;
    }
}
