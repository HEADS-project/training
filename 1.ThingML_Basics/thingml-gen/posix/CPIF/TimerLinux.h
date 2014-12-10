/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing TimerLinux
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef TimerLinux_H_
#define TimerLinux_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : TimerLinux
 *****************************************************************************/

// Definition of the instance stuct:
struct TimerLinux_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int TimerLinux_ClockTimerImpl_State;
// Variables for the properties of the instance
uint8_t TimerLinux_millisecond__var;
int TimerLinux_period__var;
int TimerLinux_ClockTimerImpl_remaining__var;
};

// Declaration of prototypes outgoing messages:
void TimerLinux_ClockTimerImpl_OnEntry(int state, struct TimerLinux_Instance *_instance);
void TimerLinux_handle_timer_timer_start(struct TimerLinux_Instance *_instance, int delay);
void TimerLinux_handle_timer_timer_cancel(struct TimerLinux_Instance *_instance);
void TimerLinux_handle_clock_clock_tick(struct TimerLinux_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_TimerLinux_send_timer_timer_timeout_listener(void (*_listener)(struct TimerLinux_Instance*));

// Definition of the states:
#define TIMERLINUX_CLOCKTIMERIMPL_STATE 0
#define TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE 1
#define TIMERLINUX_CLOCKTIMERIMPL_COUNTING_STATE 2



#ifdef __cplusplus
}
#endif

#endif //TimerLinux_H_