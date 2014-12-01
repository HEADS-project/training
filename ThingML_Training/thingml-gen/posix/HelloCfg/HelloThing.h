/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing HelloThing
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef HelloThing_H_
#define HelloThing_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : HelloThing
 *****************************************************************************/

// Definition of the instance stuct:
struct HelloThing_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int HelloThing_HelloWorld_State;
// Variables for the properties of the instance
};

// Declaration of prototypes outgoing messages:
void HelloThing_HelloWorld_OnEntry(int state, struct HelloThing_Instance *_instance);
// Declaration of callbacks for incomming messages:

// Definition of the states:
#define HELLOTHING_HELLOWORLD_STATE 0
#define HELLOTHING_HELLOWORLD_GREETINGS_STATE 1
#define HELLOTHING_HELLOWORLD_BYE_STATE 2



#ifdef __cplusplus
}
#endif

#endif //HelloThing_H_