/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing TimerLinux
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "TimerLinux.h"

/*****************************************************************************
 * Implementation for type : TimerLinux
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void TimerLinux_ClockTimerImpl_OnExit(int state, struct TimerLinux_Instance *_instance);
void TimerLinux_send_timer_timer_timeout(struct TimerLinux_Instance *_instance);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void TimerLinux_ClockTimerImpl_OnEntry(int state, struct TimerLinux_Instance *_instance) {
switch(state) {
case TIMERLINUX_CLOCKTIMERIMPL_STATE:
_instance->TimerLinux_ClockTimerImpl_State = TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE;
TimerLinux_ClockTimerImpl_OnEntry(_instance->TimerLinux_ClockTimerImpl_State, _instance);
break;
case TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE:
break;
case TIMERLINUX_CLOCKTIMERIMPL_COUNTING_STATE:
break;
default: break;
}
}

// On Exit Actions:
void TimerLinux_ClockTimerImpl_OnExit(int state, struct TimerLinux_Instance *_instance) {
switch(state) {
case TIMERLINUX_CLOCKTIMERIMPL_STATE:
TimerLinux_ClockTimerImpl_OnExit(_instance->TimerLinux_ClockTimerImpl_State, _instance);
break;
case TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE:
break;
case TIMERLINUX_CLOCKTIMERIMPL_COUNTING_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void TimerLinux_handle_timer_timer_start(struct TimerLinux_Instance *_instance, int delay) {
uint8_t TimerLinux_ClockTimerImpl_State_event_consumed = 0;
if (_instance->TimerLinux_ClockTimerImpl_State == TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE) {
if (TimerLinux_ClockTimerImpl_State_event_consumed == 0 && 1) {
TimerLinux_ClockTimerImpl_OnExit(TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE, _instance);
_instance->TimerLinux_ClockTimerImpl_State = TIMERLINUX_CLOCKTIMERIMPL_COUNTING_STATE;
_instance->TimerLinux_ClockTimerImpl_remaining__var = delay;
TimerLinux_ClockTimerImpl_OnEntry(TIMERLINUX_CLOCKTIMERIMPL_COUNTING_STATE, _instance);
TimerLinux_ClockTimerImpl_State_event_consumed = 1;
}
}
}
void TimerLinux_handle_timer_timer_cancel(struct TimerLinux_Instance *_instance) {
uint8_t TimerLinux_ClockTimerImpl_State_event_consumed = 0;
if (_instance->TimerLinux_ClockTimerImpl_State == TIMERLINUX_CLOCKTIMERIMPL_COUNTING_STATE) {
if (TimerLinux_ClockTimerImpl_State_event_consumed == 0 && 1) {
TimerLinux_ClockTimerImpl_OnExit(TIMERLINUX_CLOCKTIMERIMPL_COUNTING_STATE, _instance);
_instance->TimerLinux_ClockTimerImpl_State = TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE;
TimerLinux_ClockTimerImpl_OnEntry(TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE, _instance);
TimerLinux_ClockTimerImpl_State_event_consumed = 1;
}
}
}
void TimerLinux_handle_clock_clock_tick(struct TimerLinux_Instance *_instance) {
uint8_t TimerLinux_ClockTimerImpl_State_event_consumed = 0;
if (_instance->TimerLinux_ClockTimerImpl_State == TIMERLINUX_CLOCKTIMERIMPL_COUNTING_STATE) {
if (TimerLinux_ClockTimerImpl_State_event_consumed == 0 && _instance->TimerLinux_ClockTimerImpl_remaining__var == 0) {
TimerLinux_ClockTimerImpl_OnExit(TIMERLINUX_CLOCKTIMERIMPL_COUNTING_STATE, _instance);
_instance->TimerLinux_ClockTimerImpl_State = TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE;
TimerLinux_send_timer_timer_timeout(_instance);
TimerLinux_ClockTimerImpl_OnEntry(TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE, _instance);
TimerLinux_ClockTimerImpl_State_event_consumed = 1;
}
else if (TimerLinux_ClockTimerImpl_State_event_consumed == 0 && _instance->TimerLinux_ClockTimerImpl_remaining__var > 0) {
{
if( !_instance->TimerLinux_millisecond__var) _instance->TimerLinux_ClockTimerImpl_remaining__var = _instance->TimerLinux_ClockTimerImpl_remaining__var - 1;
if(_instance->TimerLinux_millisecond__var) _instance->TimerLinux_ClockTimerImpl_remaining__var = _instance->TimerLinux_ClockTimerImpl_remaining__var - _instance->TimerLinux_period__var;
}
TimerLinux_ClockTimerImpl_State_event_consumed = 1;
}
}
}

// Observers for outgoing messages:
void (*TimerLinux_send_timer_timer_timeout_listener)(struct TimerLinux_Instance*)= 0x0;
void register_TimerLinux_send_timer_timer_timeout_listener(void (*_listener)(struct TimerLinux_Instance*)){
TimerLinux_send_timer_timer_timeout_listener = _listener;
}
void TimerLinux_send_timer_timer_timeout(struct TimerLinux_Instance *_instance){
if (TimerLinux_send_timer_timer_timeout_listener != 0x0) TimerLinux_send_timer_timer_timeout_listener(_instance);
}

