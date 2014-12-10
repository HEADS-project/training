/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing CPrinter
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "CPrinter.h"

/*****************************************************************************
 * Implementation for type : CPrinter
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void CPrinter_behavior_OnExit(int state, struct CPrinter_Instance *_instance);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void CPrinter_behavior_OnEntry(int state, struct CPrinter_Instance *_instance) {
switch(state) {
case CPRINTER_BEHAVIOR_STATE:
_instance->CPrinter_behavior_State = CPRINTER_BEHAVIOR_GREETINGS_STATE;
CPrinter_behavior_OnEntry(_instance->CPrinter_behavior_State, _instance);
break;
case CPRINTER_BEHAVIOR_GREETINGS_STATE:
break;
default: break;
}
}

// On Exit Actions:
void CPrinter_behavior_OnExit(int state, struct CPrinter_Instance *_instance) {
switch(state) {
case CPRINTER_BEHAVIOR_STATE:
CPrinter_behavior_OnExit(_instance->CPrinter_behavior_State, _instance);
break;
case CPRINTER_BEHAVIOR_GREETINGS_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void CPrinter_handle_Print_customPrintS(struct CPrinter_Instance *_instance, char * myString) {
uint8_t CPrinter_behavior_State_event_consumed = 0;
if (_instance->CPrinter_behavior_State == CPRINTER_BEHAVIOR_GREETINGS_STATE) {
if (CPrinter_behavior_State_event_consumed == 0 && 1) {
{
fprintf(stdout, myString);
}
CPrinter_behavior_State_event_consumed = 1;
}
}
}
void CPrinter_handle_Print_customPrintI(struct CPrinter_Instance *_instance, int myInt) {
uint8_t CPrinter_behavior_State_event_consumed = 0;
if (_instance->CPrinter_behavior_State == CPRINTER_BEHAVIOR_GREETINGS_STATE) {
if (CPrinter_behavior_State_event_consumed == 0 && 1) {
{
fprintf(stdout, " %d ",myInt);
}
CPrinter_behavior_State_event_consumed = 1;
}
}
}

// Observers for outgoing messages:

