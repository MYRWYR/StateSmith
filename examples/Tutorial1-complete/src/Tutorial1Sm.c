// Autogenerated with StateSmith
#include "Tutorial1Sm.h"
// Some user .c file comment...
#include "light.h"
#include <stdbool.h> // required for `consume_event` flag
#include <string.h> // for memset

static void ROOT_enter(Tutorial1Sm* self);
static void ROOT_exit(Tutorial1Sm* self);

static void BOOM_enter(Tutorial1Sm* self);
static void BOOM_exit(Tutorial1Sm* self);

static void OFF_enter(Tutorial1Sm* self);
static void OFF_exit(Tutorial1Sm* self);
static void OFF_increase(Tutorial1Sm* self);

static void ON_GROUP_enter(Tutorial1Sm* self);
static void ON_GROUP_exit(Tutorial1Sm* self);
static void ON_GROUP_off(Tutorial1Sm* self);

static void ON1_enter(Tutorial1Sm* self);
static void ON1_exit(Tutorial1Sm* self);
static void ON1_dim(Tutorial1Sm* self);
static void ON1_increase(Tutorial1Sm* self);

static void ON2_enter(Tutorial1Sm* self);
static void ON2_exit(Tutorial1Sm* self);
static void ON2_dim(Tutorial1Sm* self);
static void ON2_increase(Tutorial1Sm* self);

static void ON3_enter(Tutorial1Sm* self);
static void ON3_exit(Tutorial1Sm* self);
static void ON3_dim(Tutorial1Sm* self);
static void ON3_increase(Tutorial1Sm* self);

// This function is used when StateSmith doesn't know what the active leaf state is at compile time due to sub states
// or when multiple states need to be exited.
static void exit_up_to_state_handler(Tutorial1Sm* self, const Tutorial1Sm_Func desired_state_exit_handler);


void Tutorial1Sm_ctor(Tutorial1Sm* self)
{
    memset(self, 0, sizeof(*self));
}

static void exit_up_to_state_handler(Tutorial1Sm* self, const Tutorial1Sm_Func desired_state_exit_handler)
{
    while (self->current_state_exit_handler != desired_state_exit_handler)
    {
        self->current_state_exit_handler(self);
    }
}

void Tutorial1Sm_start(Tutorial1Sm* self)
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
        // uml: TransitionTo(OFF)
        {
            // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition). Already at LCA, no exiting required.
            
            // Step 2: Transition action: ``.
            
            // Step 3: Enter/move towards transition target `OFF`.
            OFF_enter(self);
            
            // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
            self->state_id = Tutorial1Sm_StateId_OFF;
            self->ancestor_event_handler = NULL;
            return;
        } // end of behavior for ROOT.InitialState
    } // end of behavior for ROOT
}

void Tutorial1Sm_dispatch_event(Tutorial1Sm* self, enum Tutorial1Sm_EventId event_id)
{
    Tutorial1Sm_Func behavior_func = self->current_event_handlers[event_id];
    
    while (behavior_func != NULL)
    {
        self->ancestor_event_handler = NULL;
        behavior_func(self);
        behavior_func = self->ancestor_event_handler;
    }
}

const char* Tutorial1Sm_state_id_to_string(const enum Tutorial1Sm_StateId id)
{
    switch (id)
    {
        case Tutorial1Sm_StateId_ROOT: return "ROOT";
        case Tutorial1Sm_StateId_BOOM: return "BOOM";
        case Tutorial1Sm_StateId_OFF: return "OFF";
        case Tutorial1Sm_StateId_ON_GROUP: return "ON_GROUP";
        case Tutorial1Sm_StateId_ON1: return "ON1";
        case Tutorial1Sm_StateId_ON2: return "ON2";
        case Tutorial1Sm_StateId_ON3: return "ON3";
        default: return "?";
    }
}

////////////////////////////////////////////////////////////////////////////////
// event handlers for state ROOT
////////////////////////////////////////////////////////////////////////////////

static void ROOT_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ROOT_exit;
}

static void ROOT_exit(Tutorial1Sm* self)
{
    // State machine root is a special case. It cannot be exited.
    (void)self;  // nothing to see here compiler. move along!
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state BOOM
////////////////////////////////////////////////////////////////////////////////

static void BOOM_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = BOOM_exit;
    
    // BOOM behavior
    // uml: enter / { light_boom(); }
    {
        // Step 1: execute action `light_boom();`
        light_boom();
    } // end of behavior for BOOM
}

static void BOOM_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state OFF
////////////////////////////////////////////////////////////////////////////////

static void OFF_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = OFF_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = OFF_increase;
    
    // OFF behavior
    // uml: enter / { light_off(); }
    {
        // Step 1: execute action `light_off();`
        light_off();
    } // end of behavior for OFF
}

static void OFF_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = NULL;  // no ancestor listens to this event
}

static void OFF_increase(Tutorial1Sm* self)
{
    // No ancestor state handles `INCREASE` event.
    
    // OFF behavior
    // uml: INCREASE TransitionTo(ON1)
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
        OFF_exit(self);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `ON1`.
        ON_GROUP_enter(self);
        ON1_enter(self);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        self->state_id = Tutorial1Sm_StateId_ON1;
        self->ancestor_event_handler = NULL;
        return;
    } // end of behavior for OFF
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ON_GROUP
////////////////////////////////////////////////////////////////////////////////

static void ON_GROUP_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ON_GROUP_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_OFF] = ON_GROUP_off;
}

static void ON_GROUP_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ROOT_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_OFF] = NULL;  // no ancestor listens to this event
}

static void ON_GROUP_off(Tutorial1Sm* self)
{
    // No ancestor state handles `OFF` event.
    
    // ON_GROUP behavior
    // uml: OFF TransitionTo(OFF)
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
        exit_up_to_state_handler(self, ROOT_exit);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `OFF`.
        OFF_enter(self);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        self->state_id = Tutorial1Sm_StateId_OFF;
        self->ancestor_event_handler = NULL;
        return;
    } // end of behavior for ON_GROUP
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ON1
////////////////////////////////////////////////////////////////////////////////

static void ON1_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ON1_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = ON1_dim;
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = ON1_increase;
    
    // ON1 behavior
    // uml: enter / { light_on1(); }
    {
        // Step 1: execute action `light_on1();`
        light_on1();
    } // end of behavior for ON1
}

static void ON1_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ON_GROUP_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = NULL;  // no ancestor listens to this event
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = NULL;  // no ancestor listens to this event
}

static void ON1_dim(Tutorial1Sm* self)
{
    // No ancestor state handles `DIM` event.
    
    // ON1 behavior
    // uml: DIM TransitionTo(OFF)
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
        exit_up_to_state_handler(self, ROOT_exit);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `OFF`.
        OFF_enter(self);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        self->state_id = Tutorial1Sm_StateId_OFF;
        self->ancestor_event_handler = NULL;
        return;
    } // end of behavior for ON1
}

static void ON1_increase(Tutorial1Sm* self)
{
    // No ancestor state handles `INCREASE` event.
    
    // ON1 behavior
    // uml: INCREASE TransitionTo(ON2)
    {
        // Step 1: Exit states until we reach `ON_GROUP` state (Least Common Ancestor for transition).
        ON1_exit(self);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `ON2`.
        ON2_enter(self);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        self->state_id = Tutorial1Sm_StateId_ON2;
        self->ancestor_event_handler = NULL;
        return;
    } // end of behavior for ON1
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ON2
////////////////////////////////////////////////////////////////////////////////

static void ON2_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ON2_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = ON2_dim;
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = ON2_increase;
    
    // ON2 behavior
    // uml: enter / { light_on2(); }
    {
        // Step 1: execute action `light_on2();`
        light_on2();
    } // end of behavior for ON2
}

static void ON2_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ON_GROUP_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = NULL;  // no ancestor listens to this event
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = NULL;  // no ancestor listens to this event
}

static void ON2_dim(Tutorial1Sm* self)
{
    // No ancestor state handles `DIM` event.
    
    // ON2 behavior
    // uml: DIM TransitionTo(ON1)
    {
        // Step 1: Exit states until we reach `ON_GROUP` state (Least Common Ancestor for transition).
        ON2_exit(self);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `ON1`.
        ON1_enter(self);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        self->state_id = Tutorial1Sm_StateId_ON1;
        self->ancestor_event_handler = NULL;
        return;
    } // end of behavior for ON2
}

static void ON2_increase(Tutorial1Sm* self)
{
    // No ancestor state handles `INCREASE` event.
    
    // ON2 behavior
    // uml: INCREASE TransitionTo(ON3)
    {
        // Step 1: Exit states until we reach `ON_GROUP` state (Least Common Ancestor for transition).
        ON2_exit(self);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `ON3`.
        ON3_enter(self);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        self->state_id = Tutorial1Sm_StateId_ON3;
        self->ancestor_event_handler = NULL;
        return;
    } // end of behavior for ON2
}


////////////////////////////////////////////////////////////////////////////////
// event handlers for state ON3
////////////////////////////////////////////////////////////////////////////////

static void ON3_enter(Tutorial1Sm* self)
{
    // setup trigger/event handlers
    self->current_state_exit_handler = ON3_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = ON3_dim;
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = ON3_increase;
    
    // ON3 behavior
    // uml: enter / { count = 0;\nlight_on3(); }
    {
        // Step 1: execute action `count = 0;\nlight_on3();`
        self->vars.count = 0;
        light_on3();
    } // end of behavior for ON3
}

static void ON3_exit(Tutorial1Sm* self)
{
    // adjust function pointers for this state's exit
    self->current_state_exit_handler = ON_GROUP_exit;
    self->current_event_handlers[Tutorial1Sm_EventId_DIM] = NULL;  // no ancestor listens to this event
    self->current_event_handlers[Tutorial1Sm_EventId_INCREASE] = NULL;  // no ancestor listens to this event
}

static void ON3_dim(Tutorial1Sm* self)
{
    // No ancestor state handles `DIM` event.
    
    // ON3 behavior
    // uml: DIM TransitionTo(ON2)
    {
        // Step 1: Exit states until we reach `ON_GROUP` state (Least Common Ancestor for transition).
        ON3_exit(self);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `ON2`.
        ON2_enter(self);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        self->state_id = Tutorial1Sm_StateId_ON2;
        self->ancestor_event_handler = NULL;
        return;
    } // end of behavior for ON3
}

static void ON3_increase(Tutorial1Sm* self)
{
    // No ancestor state handles `INCREASE` event.
    
    // ON3 behavior
    // uml: 1. INCREASE / { count++; }
    {
        // note: no ancestor consumes this event, but we output `bool consume_event` anyway because a user's design might rely on it.
        bool consume_event = true; // events other than `do` are normally consumed by any event handler. Other event handlers in *this* state may still handle the event though.
        
        // Step 1: execute action `count++;`
        self->vars.count++;
        
        // Step 2: determine if ancestor gets to handle event next.
        // No ancestor handles event. Ignore `consume_event` flag.
    } // end of behavior for ON3
    
    // ON3 behavior
    // uml: 2. INCREASE [count >= 3] TransitionTo(BOOM)
    if (self->vars.count >= 3)
    {
        // Step 1: Exit states until we reach `ROOT` state (Least Common Ancestor for transition).
        exit_up_to_state_handler(self, ROOT_exit);
        
        // Step 2: Transition action: ``.
        
        // Step 3: Enter/move towards transition target `BOOM`.
        BOOM_enter(self);
        
        // Step 4: complete transition. Ends event dispatch. No other behaviors are checked.
        self->state_id = Tutorial1Sm_StateId_BOOM;
        self->ancestor_event_handler = NULL;
        return;
    } // end of behavior for ON3
}


