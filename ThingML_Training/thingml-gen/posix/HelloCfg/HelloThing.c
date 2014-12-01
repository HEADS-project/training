/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing HelloThing
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "HelloThing.h"

/*****************************************************************************
 * Implementation for type : HelloThing
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void HelloThing_HelloWorld_OnExit(int state, struct HelloThing_Instance *_instance);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void HelloThing_HelloWorld_OnEntry(int state, struct HelloThing_Instance *_instance) {
switch(state) {
case HELLOTHING_HELLOWORLD_STATE:
_instance->HelloThing_HelloWorld_State = HELLOTHING_HELLOWORLD_GREETINGS_STATE;
HelloThing_HelloWorld_OnEntry(_instance->HelloThing_HelloWorld_State, _instance);
break;
case HELLOTHING_HELLOWORLD_GREETINGS_STATE:
break;
case HELLOTHING_HELLOWORLD_BYE_STATE:
fprintf(stdout, "Bye.\n");

break;
default: break;
}
}

// On Exit Actions:
void HelloThing_HelloWorld_OnExit(int state, struct HelloThing_Instance *_instance) {
switch(state) {
case HELLOTHING_HELLOWORLD_STATE:
HelloThing_HelloWorld_OnExit(_instance->HelloThing_HelloWorld_State, _instance);
break;
case HELLOTHING_HELLOWORLD_GREETINGS_STATE:
break;
case HELLOTHING_HELLOWORLD_BYE_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void HelloThing_handle_empty_event(struct HelloThing_Instance *_instance) {
if (_instance->HelloThing_HelloWorld_State == HELLOTHING_HELLOWORLD_GREETINGS_STATE) {
if (1) {
HelloThing_HelloWorld_OnExit(HELLOTHING_HELLOWORLD_GREETINGS_STATE, _instance);
_instance->HelloThing_HelloWorld_State = HELLOTHING_HELLOWORLD_BYE_STATE;
fprintf(stdout, "Hello World!\n");

HelloThing_HelloWorld_OnEntry(HELLOTHING_HELLOWORLD_BYE_STATE, _instance);
}
}
}

// Observers for outgoing messages:

