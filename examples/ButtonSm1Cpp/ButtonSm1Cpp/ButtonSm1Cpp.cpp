// Autogenerated with StateSmith
#include "ButtonSm1Cpp.h"
#include "Arduino.h"
#include <stdbool.h> // required for `consume_event` flag
#include <string.h> // for memset

static void ROOT_enter(ButtonSm1Cpp* self);
static void ROOT_exit(ButtonSm1Cpp* self);

static void NOT_PRESSED_enter(ButtonSm1Cpp* self);
static void NOT_PRESSED_exit(ButtonSm1Cpp* self);
static void NOT_PRESSED_do(ButtonSm1Cpp* self);

static void PRESSED_enter(ButtonSm1Cpp* self);
static void PRESSED_exit(ButtonSm1Cpp* self);
static void PRESSED_do(ButtonSm1Cpp* self);

static void CONFIRMING_HELD_enter(ButtonSm1Cpp* self);
static void CONFIRMING_HELD_exit(ButtonSm1Cpp* self);
static void CONFIRMING_HELD_do(ButtonSm1Cpp* self);

static void HELD_enter(ButtonSm1Cpp* self);
static void HELD_exit(ButtonSm1Cpp* self);

// This function is used when StateSmith doesn't know what the active leaf state is at compile time due to sub states
// or when multiple states need to be exited.
static void exit_up_to_state_handler(ButtonSm1Cpp* self, const ButtonSm1Cpp_Func desired_state_exit_handler);


void ButtonSm1Cpp_ctor(ButtonSm1Cpp* self)
{
    memset(self, 0, sizeof(*self));
}

static void exit_up_to_state_handler(ButtonSm1Cpp* self, const ButtonSm1Cpp_Func desired_state_exit_handler)
{
    while (self->current_state_exit_handler != desired_state_exit_handler)
    {
        self->current_state_exit_handler(self);
    }
}

void ButtonSm1Cpp_start(ButtonSm1Cpp* self)
{
    ROOT_enter(self);
    // ROOT behavior
    // uml: TransitionTo(ROOT.InitialState)
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
        exit_up_to_state_handler(self, ROOT_exit);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `ROOT.InitialState`.
        // ROOT.InitialState is a pseudo state and cannot have an `enter` trigger.
        
        // ROOT.InitialState behavior
        // uml: TransitionTo(NOT_PRESSED)
        {
            // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
            
            // Step 2: Transition action: ``.
            
            // Step 3: Enter/move towards transition target `NOT_PRESSED`.
            NOT_PRESSED_enter(self);
            
            // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
            self->state_id = ButtonSm1Cpp_StateId_NOT_PRESSED;
            // No ancestor handles event. Can skip nulling `self->ancestor_event_handler`.
            return;
        } // end of behavior for ROOT.InitialState
    } // end of behavior for ROOT
}

void ButtonSm1Cpp_dispatch_event(ButtonSm1Cpp* self, enum ButtonSm1Cpp_EventId event_id)
{
    ButtonSm1Cpp_Func behavior_func = self->current_event_handlers[event_id];
    
    while (behavior_func != NULL)
    {
        self->ancestor_event_handler = NULL;
        behavior_func(self);
        behavior_func = self->ancestor_event_handler;
    }
}

const char* ButtonSm1Cpp_state_id_to_string(const enum ButtonSm1Cpp_StateId id)
{
    switch (id)
    {
        case ButtonSm1Cpp_StateId_ROOT: return "ROOT";
        case ButtonSm1Cpp_StateId_NOT_PRESSED: return "NOT_PRESSED";
        case ButtonSm1Cpp_StateId_PRESSED: return "PRESSED";
        case ButtonSm1Cpp_StateId_CONFIRMING_HELD: return "CONFIRMING_HELD";
        case ButtonSm1Cpp_StateId_HELD: return "HELD";
        default: return "?";
    }
}

////////////////////////////////////////////////////////////////////////////////
// event handlers for state ROOT
////////////////////////////////////////////////////////////////////////////////

static void ROOT_enter(ButtonSm1Cpp* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ROOT_exit;
}

static void ROOT_exit(ButtonSm1Cpp* self)
{
    // State machine root is a special case. It cannot be exited.
    (void)self;  // nothing to see here compiler. move along!
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state NOT_PRESSED
////////////////////////////////////////////////////////////////////////////////

static void NOT_PRESSED_enter(ButtonSm1Cpp* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = NOT_PRESSED_exit;
    self->current_event_handlers[ButtonSm1Cpp_EventId_DO] = NOT_PRESSED_do;
    
    // NOT_PRESSED behavior
    // uml: enter / { reset_debounce_timer(); }
    {
        // Step 1: execute action `reset_debounce_timer();`
        self->vars.debounce_started_at_ms = millis();
    } // end of behavior for NOT_PRESSED
}

static void NOT_PRESSED_exit(ButtonSm1Cpp* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
    self->current_event_handlers[ButtonSm1Cpp_EventId_DO] = NULL;  // no ancestor listens to this event
}

static void NOT_PRESSED_do(ButtonSm1Cpp* self)
{
    // No ancestor state handles `do` event.
    
    // NOT_PRESSED behavior
    // uml: do [is_pressed\n  && is_debounced] TransitionTo(PRESSED)
    if (self->vars.input_is_pressed
  && (( (millis() - self->vars.debounce_started_at_ms) >= 20 )))
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
        NOT_PRESSED_exit(self);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `PRESSED`.
        PRESSED_enter(self);
        
        // PRESSED.InitialState behavior
        // uml: TransitionTo(CONFIRMING_HELD)
        {
            // Step 1: Exit states until we reach `PRESSED` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
            
            // Step 2: Transition action: ``.
            
            // Step 3: Enter/move towards transition target `CONFIRMING_HELD`.
            CONFIRMING_HELD_enter(self);
            
            // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
            self->state_id = ButtonSm1Cpp_StateId_CONFIRMING_HELD;
            // No ancestor handles event. Can skip nulling `self->ancestor_event_handler`.
            return;
        } // end of behavior for PRESSED.InitialState
    } // end of behavior for NOT_PRESSED
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state PRESSED
////////////////////////////////////////////////////////////////////////////////

static void PRESSED_enter(ButtonSm1Cpp* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = PRESSED_exit;
    self->current_event_handlers[ButtonSm1Cpp_EventId_DO] = PRESSED_do;
    
    // PRESSED behavior
    // uml: enter / { reset_debounce_timer();\noutput_event(press); }
    {
        // Step 1: execute action `reset_debounce_timer();\noutput_event(press);`
        self->vars.debounce_started_at_ms = millis();
        self->vars.output_event_press = true;
    } // end of behavior for PRESSED
}

static void PRESSED_exit(ButtonSm1Cpp* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
    self->current_event_handlers[ButtonSm1Cpp_EventId_DO] = NULL;  // no ancestor listens to this event
}

static void PRESSED_do(ButtonSm1Cpp* self)
{
    // No ancestor state handles `do` event.
    
    // PRESSED behavior
    // uml: do [is_released && is_debounced] / { if (debounce_ms() <= 200) {\n  output_event(tap);\n}\noutput_event(release); } TransitionTo(NOT_PRESSED)
    if ((!self->vars.input_is_pressed) && (( (millis() - self->vars.debounce_started_at_ms) >= 20 )))
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
        exit_up_to_state_handler(self, ROOT_exit);
        
        // Step 2: Transition action: `if (debounce_ms() <= 200) {\n  output_event(tap);\n}\noutput_event(release);`.
        if ((millis() - self->vars.debounce_started_at_ms) <= 200) {
          self->vars.output_event_tap = true;
        }
        self->vars.output_event_release = true;
        
        // Step 3: Enter/move towards transition target `NOT_PRESSED`.
        NOT_PRESSED_enter(self);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        self->state_id = ButtonSm1Cpp_StateId_NOT_PRESSED;
        // No ancestor handles event. Can skip nulling `self->ancestor_event_handler`.
        return;
    } // end of behavior for PRESSED
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state CONFIRMING_HELD
////////////////////////////////////////////////////////////////////////////////

static void CONFIRMING_HELD_enter(ButtonSm1Cpp* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = CONFIRMING_HELD_exit;
    self->current_event_handlers[ButtonSm1Cpp_EventId_DO] = CONFIRMING_HELD_do;
}

static void CONFIRMING_HELD_exit(ButtonSm1Cpp* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = PRESSED_exit;
    self->current_event_handlers[ButtonSm1Cpp_EventId_DO] = PRESSED_do;  // the next ancestor that handles this event is PRESSED
}

static void CONFIRMING_HELD_do(ButtonSm1Cpp* self)
{
    // Setup handler for next ancestor that listens to `do` event.
    self->ancestor_event_handler = PRESSED_do;
    
    // CONFIRMING_HELD behavior
    // uml: do [debounce_ms() > 800] TransitionTo(HELD)
    if ((millis() - self->vars.debounce_started_at_ms) > 800)
    {
        // Step 1: Exit states until we reach `PRESSED` state (Least Common Ancestor for transition).
        CONFIRMING_HELD_exit(self);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `HELD`.
        HELD_enter(self);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        self->state_id = ButtonSm1Cpp_StateId_HELD;
        self->ancestor_event_handler = NULL;
        return;
    } // end of behavior for CONFIRMING_HELD
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state HELD
////////////////////////////////////////////////////////////////////////////////

static void HELD_enter(ButtonSm1Cpp* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = HELD_exit;
    
    // HELD behavior
    // uml: enter / { output_event(held); }
    {
        // Step 1: execute action `output_event(held);`
        self->vars.output_event_held = true;
    } // end of behavior for HELD
}

static void HELD_exit(ButtonSm1Cpp* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = PRESSED_exit;
}


