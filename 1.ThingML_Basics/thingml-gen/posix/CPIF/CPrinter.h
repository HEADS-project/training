/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing CPrinter
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef CPrinter_H_
#define CPrinter_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : CPrinter
 *****************************************************************************/

// Definition of the instance stuct:
struct CPrinter_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int CPrinter_behavior_State;
// Variables for the properties of the instance
};

// Declaration of prototypes outgoing messages:
void CPrinter_behavior_OnEntry(int state, struct CPrinter_Instance *_instance);
void CPrinter_handle_Print_customPrintS(struct CPrinter_Instance *_instance, char * myString);
void CPrinter_handle_Print_customPrintI(struct CPrinter_Instance *_instance, int myInt);
// Declaration of callbacks for incomming messages:

// Definition of the states:
#define CPRINTER_BEHAVIOR_STATE 0
#define CPRINTER_BEHAVIOR_GREETINGS_STATE 1



#ifdef __cplusplus
}
#endif

#endif //CPrinter_H_