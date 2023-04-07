// Autogenerated with StateSmith 0.8.14-alpha.
// Algorithm: Balanced1. See https://github.com/StateSmith/StateSmith/wiki/Algorithms

#pragma once
#include <stdint.h>

// Some user .h file comment...
typedef enum Tutorial1Sm_EventId
{
    Tutorial1Sm_EventId_DIM = 0,
    Tutorial1Sm_EventId_INCREASE = 1,
    Tutorial1Sm_EventId_OFF = 2,
} Tutorial1Sm_EventId;

enum
{
    Tutorial1Sm_EventIdCount = 3
};

typedef enum Tutorial1Sm_StateId
{
    Tutorial1Sm_StateId_ROOT = 0,
    Tutorial1Sm_StateId_BOOM = 1,
    Tutorial1Sm_StateId_OFF = 2,
    Tutorial1Sm_StateId_ON_GROUP = 3,
    Tutorial1Sm_StateId_ON1 = 4,
    Tutorial1Sm_StateId_ON2 = 5,
    Tutorial1Sm_StateId_ON3 = 6,
} Tutorial1Sm_StateId;

enum
{
    Tutorial1Sm_StateIdCount = 7
};


// Generated state machine
// forward declaration
typedef struct Tutorial1Sm Tutorial1Sm;

// State machine variables. Can be used for inputs, outputs, user variables...
typedef struct Tutorial1Sm_Vars
{
    uint8_t count;  // some user description for count field
} Tutorial1Sm_Vars;


// event handler type
typedef void (*Tutorial1Sm_Func)(Tutorial1Sm* sm);

// State machine constructor. Must be called before start or dispatch event functions. Not thread safe.
void Tutorial1Sm_ctor(Tutorial1Sm* sm);

// Starts the state machine. Must be called before dispatching events. Not thread safe.
void Tutorial1Sm_start(Tutorial1Sm* sm);

// Dispatches an event to the state machine. Not thread safe.
void Tutorial1Sm_dispatch_event(Tutorial1Sm* sm, Tutorial1Sm_EventId event_id);

// Thread safe.
char const * Tutorial1Sm_state_id_to_string(Tutorial1Sm_StateId id);

// Thread safe.
char const * Tutorial1Sm_event_id_to_string(Tutorial1Sm_EventId id);

// Generated state machine
struct Tutorial1Sm
{
    // Used internally by state machine. Feel free to inspect, but don't modify.
    Tutorial1Sm_StateId state_id;
    
    // Used internally by state machine. Don't modify.
    Tutorial1Sm_Func ancestor_event_handler;
    
    // Used internally by state machine. Don't modify.
    Tutorial1Sm_Func current_event_handlers[Tutorial1Sm_EventIdCount];
    
    // Used internally by state machine. Don't modify.
    Tutorial1Sm_Func current_state_exit_handler;
    
    // Variables. Can be used for inputs, outputs, user variables...
    Tutorial1Sm_Vars vars;
};

