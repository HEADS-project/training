/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing ClockLinux
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef ClockLinux_H_
#define ClockLinux_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : ClockLinux
 *****************************************************************************/

// Definition of the instance stuct:
struct ClockLinux_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int ClockLinux_ClockImpl_State;
// Variables for the properties of the instance
int Clock_period__var;
};

// Declaration of prototypes outgoing messages:
void ClockLinux_ClockImpl_OnEntry(int state, struct ClockLinux_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_ClockLinux_send_signal_clock_tick_listener(void (*_listener)(struct ClockLinux_Instance*));

// Definition of the states:
#define CLOCKLINUX_CLOCKIMPL_STATE 0
#define CLOCKLINUX_CLOCKIMPL_TICKING_STATE 1



#ifdef __cplusplus
}
#endif

#endif //ClockLinux_H_