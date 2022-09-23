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
using Antlr4.Runtime.Tree;
using IToken = Antlr4.Runtime.IToken;

/// <summary>
/// This interface defines a complete generic visitor for a parse tree produced
/// by <see cref="PlantumlGrammarParser"/>.
/// </summary>
/// <typeparam name="Result">The return type of the visit operation.</typeparam>
[System.CodeDom.Compiler.GeneratedCode("ANTLR", "4.9.2")]
[System.CLSCompliant(false)]
public interface IPlantumlGrammarVisitor<Result> : IParseTreeVisitor<Result> {
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.optional_any_space"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitOptional_any_space([NotNull] PlantumlGrammarParser.Optional_any_spaceContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.ohs"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitOhs([NotNull] PlantumlGrammarParser.OhsContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.some_ws"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitSome_ws([NotNull] PlantumlGrammarParser.Some_wsContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.line_end_with_hs"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitLine_end_with_hs([NotNull] PlantumlGrammarParser.Line_end_with_hsContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.start_end_state"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitStart_end_state([NotNull] PlantumlGrammarParser.Start_end_stateContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.state_id"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitState_id([NotNull] PlantumlGrammarParser.State_idContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.vertex"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitVertex([NotNull] PlantumlGrammarParser.VertexContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.edge"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitEdge([NotNull] PlantumlGrammarParser.EdgeContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.transition_event_guard_code"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTransition_event_guard_code([NotNull] PlantumlGrammarParser.Transition_event_guard_codeContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.transition"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitTransition([NotNull] PlantumlGrammarParser.TransitionContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.state_child_states"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitState_child_states([NotNull] PlantumlGrammarParser.State_child_statesContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.stereotype"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitStereotype([NotNull] PlantumlGrammarParser.StereotypeContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.state_explicit"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitState_explicit([NotNull] PlantumlGrammarParser.State_explicitContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.rest_of_line"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitRest_of_line([NotNull] PlantumlGrammarParser.Rest_of_lineContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.state_contents"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitState_contents([NotNull] PlantumlGrammarParser.State_contentsContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.ignore"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitIgnore([NotNull] PlantumlGrammarParser.IgnoreContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.diagram_element"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitDiagram_element([NotNull] PlantumlGrammarParser.Diagram_elementContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.note_short"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNote_short([NotNull] PlantumlGrammarParser.Note_shortContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.note_multiline_contents"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNote_multiline_contents([NotNull] PlantumlGrammarParser.Note_multiline_contentsContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.note_multiline"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNote_multiline([NotNull] PlantumlGrammarParser.Note_multilineContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.note_floating"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNote_floating([NotNull] PlantumlGrammarParser.Note_floatingContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.note"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitNote([NotNull] PlantumlGrammarParser.NoteContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.startuml"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitStartuml([NotNull] PlantumlGrammarParser.StartumlContext context);
	/// <summary>
	/// Visit a parse tree produced by <see cref="PlantumlGrammarParser.diagram"/>.
	/// </summary>
	/// <param name="context">The parse tree.</param>
	/// <return>The visitor result.</return>
	Result VisitDiagram([NotNull] PlantumlGrammarParser.DiagramContext context);
}
