//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     ANTLR Version: 4.9.2
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from PlantumlGrammar.g4 by ANTLR 4.9.2

// Unreachable code detected
#pragma warning disable 0162
// The variable '...' is assigned but its value is never used
#pragma warning disable 0219
// Missing XML comment for publicly visible type or member '...'
#pragma warning disable 1591
// Ambiguous reference in cref attribute
#pragma warning disable 419

using Antlr4.Runtime.Misc;
using IParseTreeListener = Antlr4.Runtime.Tree.IParseTreeListener;
using IToken = Antlr4.Runtime.IToken;

/// <summary>
/// This interface defines a complete listener for a parse tree produced by
/// <see cref="PlantumlGrammarParser"/>.
/// </summary>
[System.CodeDom.Compiler.GeneratedCode("ANTLR", "4.9.2")]
[System.CLSCompliant(false)]
public interface IPlantumlGrammarListener : IParseTreeListener {
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.optional_any_space"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterOptional_any_space([NotNull] PlantumlGrammarParser.Optional_any_spaceContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.optional_any_space"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitOptional_any_space([NotNull] PlantumlGrammarParser.Optional_any_spaceContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.ohs"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterOhs([NotNull] PlantumlGrammarParser.OhsContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.ohs"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitOhs([NotNull] PlantumlGrammarParser.OhsContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.some_ws"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterSome_ws([NotNull] PlantumlGrammarParser.Some_wsContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.some_ws"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitSome_ws([NotNull] PlantumlGrammarParser.Some_wsContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.line_end_with_hs"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterLine_end_with_hs([NotNull] PlantumlGrammarParser.Line_end_with_hsContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.line_end_with_hs"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitLine_end_with_hs([NotNull] PlantumlGrammarParser.Line_end_with_hsContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.start_end_state"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterStart_end_state([NotNull] PlantumlGrammarParser.Start_end_stateContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.start_end_state"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitStart_end_state([NotNull] PlantumlGrammarParser.Start_end_stateContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.state_id"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterState_id([NotNull] PlantumlGrammarParser.State_idContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.state_id"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitState_id([NotNull] PlantumlGrammarParser.State_idContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.vertex"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterVertex([NotNull] PlantumlGrammarParser.VertexContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.vertex"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitVertex([NotNull] PlantumlGrammarParser.VertexContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.edge"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterEdge([NotNull] PlantumlGrammarParser.EdgeContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.edge"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitEdge([NotNull] PlantumlGrammarParser.EdgeContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.transition"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterTransition([NotNull] PlantumlGrammarParser.TransitionContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.transition"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitTransition([NotNull] PlantumlGrammarParser.TransitionContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.state_contents_string"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterState_contents_string([NotNull] PlantumlGrammarParser.State_contents_stringContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.state_contents_string"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitState_contents_string([NotNull] PlantumlGrammarParser.State_contents_stringContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.state_contents"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterState_contents([NotNull] PlantumlGrammarParser.State_contentsContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.state_contents"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitState_contents([NotNull] PlantumlGrammarParser.State_contentsContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.ignore"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterIgnore([NotNull] PlantumlGrammarParser.IgnoreContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.ignore"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitIgnore([NotNull] PlantumlGrammarParser.IgnoreContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.diagram_element"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterDiagram_element([NotNull] PlantumlGrammarParser.Diagram_elementContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.diagram_element"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitDiagram_element([NotNull] PlantumlGrammarParser.Diagram_elementContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.startuml"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterStartuml([NotNull] PlantumlGrammarParser.StartumlContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.startuml"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitStartuml([NotNull] PlantumlGrammarParser.StartumlContext context);
	/// <summary>
	/// Enter a parse tree produced by <see cref="PlantumlGrammarParser.diagram"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void EnterDiagram([NotNull] PlantumlGrammarParser.DiagramContext context);
	/// <summary>
	/// Exit a parse tree produced by <see cref="PlantumlGrammarParser.diagram"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	void ExitDiagram([NotNull] PlantumlGrammarParser.DiagramContext context);
}
