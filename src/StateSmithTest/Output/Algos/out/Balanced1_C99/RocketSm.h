// Autogenerated with StateSmith.
// Algorithm: Balanced1. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#pragma once  // You can also specify normal include guard. See https://github.com/StateSmith/StateSmith/issues/112
#include <stdint.h>

typedef enum RocketSm_EventId
{
    RocketSm_EventId_DO = 0 // The `do` event is special. State event handlers do not consume this event (ancestors all get it too) unless a transition occurs.
} RocketSm_EventId;

enum
{
    RocketSm_EventIdCount = 1
};

typedef enum RocketSm_StateId
{
    RocketSm_StateId_ROOT = 0,
    RocketSm_StateId_C1 = 1
} RocketSm_StateId;

enum
{
    RocketSm_StateIdCount = 2
};


// Generated state machine
// forward declaration
typedef struct RocketSm RocketSm;

// event handler type
typedef void (*RocketSm_Func)(RocketSm* sm);

// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void RocketSm_ctor(RocketSm* sm);

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void RocketSm_start(RocketSm* sm);

// Dispatches an event to the state machine. Not thread safe.
// Note! This function assumes that the `event_id` parameter is valid.
void RocketSm_dispatch_event(RocketSm* sm, RocketSm_EventId event_id);

// Thread safe.
char const * RocketSm_state_id_to_string(RocketSm_StateId id);

// Thread safe.
char const * RocketSm_event_id_to_string(RocketSm_EventId id);

// Generated state machine
struct RocketSm
{
    // Used internally by state machine. Feel free to inspect, but don't modify.
    RocketSm_StateId state_id;
    
    // Used internally by state machine. Don't modify.
    RocketSm_Func ancestor_event_handler;
    
    // Used internally by state machine. Don't modify.
    RocketSm_Func current_event_handlers[RocketSm_EventIdCount];
    
    // Used internally by state machine. Don't modify.
    RocketSm_Func current_state_exit_handler;
};

