// Autogenerated with StateSmith.
// Algorithm: Balanced2. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#pragma once  // You can also specify normal include guard. See https://github.com/StateSmith/StateSmith/issues/112
#include <stdint.h>

typedef enum Ex1_EventId
{
    Ex1_EventId_DO = 0 // The `do` event is special. State event handlers do not consume this event (ancestors all get it too) unless a transition occurs.
} Ex1_EventId;

enum
{
    Ex1_EventIdCount = 1
};

typedef enum Ex1_StateId
{
    Ex1_StateId_ROOT = 0,
    Ex1_StateId_STATE_1 = 1,
    Ex1_StateId_STATE_2 = 2
} Ex1_StateId;

enum
{
    Ex1_StateIdCount = 3
};


// Generated state machine
// forward declaration
typedef struct Ex1 Ex1;

// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void Ex1_ctor(Ex1* sm);

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void Ex1_start(Ex1* sm);

// Dispatches an event to the state machine. Not thread safe.
// Note! This function assumes that the `event_id` parameter is valid.
void Ex1_dispatch_event(Ex1* sm, Ex1_EventId event_id);


// Thread safe.
char const * Ex1_event_id_to_string(Ex1_EventId id);

// Generated state machine
struct Ex1
{
    // Used internally by state machine. Feel free to inspect, but don't modify.
    Ex1_StateId state_id;
};

