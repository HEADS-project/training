/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing PIFStarter
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "PIFStarter.h"

/*****************************************************************************
 * Implementation for type : PIFStarter
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void PIFStarter_behavior_OnExit(int state, struct PIFStarter_Instance *_instance);
void PIFStarter_send_timer_timer_start(struct PIFStarter_Instance *_instance, int delay);
void PIFStarter_send_timer_timer_cancel(struct PIFStarter_Instance *_instance);
void PIFStarter_send_to_ender_pif_token(struct PIFStarter_Instance *_instance, int token);
void PIFStarter_send_Print_customPrintS(struct PIFStarter_Instance *_instance, char * myString);
void PIFStarter_send_Print_customPrintI(struct PIFStarter_Instance *_instance, int myInt);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void PIFStarter_behavior_OnEntry(int state, struct PIFStarter_Instance *_instance) {
switch(state) {
case PIFSTARTER_BEHAVIOR_STATE:
_instance->PIFStarter_behavior_State = PIFSTARTER_BEHAVIOR_INIT_STATE;
PIFStarter_behavior_OnEntry(_instance->PIFStarter_behavior_State, _instance);
break;
case PIFSTARTER_BEHAVIOR_INIT_STATE:
{
PIFStarter_send_timer_timer_start(_instance, _instance->PIFStarter_period__var);
}
break;
case PIFSTARTER_BEHAVIOR_WAIT_STATE:
break;
default: break;
}
}

// On Exit Actions:
void PIFStarter_behavior_OnExit(int state, struct PIFStarter_Instance *_instance) {
switch(state) {
case PIFSTARTER_BEHAVIOR_STATE:
PIFStarter_behavior_OnExit(_instance->PIFStarter_behavior_State, _instance);
break;
case PIFSTARTER_BEHAVIOR_INIT_STATE:
break;
case PIFSTARTER_BEHAVIOR_WAIT_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void PIFStarter_handle_from_ender_pif_token(struct PIFStarter_Instance *_instance, int token) {
uint8_t PIFStarter_behavior_State_event_consumed = 0;
if (_instance->PIFStarter_behavior_State == PIFSTARTER_BEHAVIOR_WAIT_STATE) {
if (PIFStarter_behavior_State_event_consumed == 0 && 1) {
PIFStarter_behavior_OnExit(PIFSTARTER_BEHAVIOR_WAIT_STATE, _instance);
_instance->PIFStarter_behavior_State = PIFSTARTER_BEHAVIOR_INIT_STATE;
{
PIFStarter_send_Print_customPrintS(_instance, " Sender got token back \n");
}
PIFStarter_behavior_OnEntry(PIFSTARTER_BEHAVIOR_INIT_STATE, _instance);
PIFStarter_behavior_State_event_consumed = 1;
}
}
}
void PIFStarter_handle_timer_timer_timeout(struct PIFStarter_Instance *_instance) {
uint8_t PIFStarter_behavior_State_event_consumed = 0;
if (_instance->PIFStarter_behavior_State == PIFSTARTER_BEHAVIOR_INIT_STATE) {
if (PIFStarter_behavior_State_event_consumed == 0 && 1) {
PIFStarter_behavior_OnExit(PIFSTARTER_BEHAVIOR_INIT_STATE, _instance);
_instance->PIFStarter_behavior_State = PIFSTARTER_BEHAVIOR_WAIT_STATE;
{
PIFStarter_send_Print_customPrintS(_instance, "Sender sends token ... ");
PIFStarter_send_to_ender_pif_token(_instance, 1);
}
PIFStarter_behavior_OnEntry(PIFSTARTER_BEHAVIOR_WAIT_STATE, _instance);
PIFStarter_behavior_State_event_consumed = 1;
}
}
}

// Observers for outgoing messages:
void (*PIFStarter_send_timer_timer_start_listener)(struct PIFStarter_Instance*, int)= 0x0;
void register_PIFStarter_send_timer_timer_start_listener(void (*_listener)(struct PIFStarter_Instance*, int)){
PIFStarter_send_timer_timer_start_listener = _listener;
}
void PIFStarter_send_timer_timer_start(struct PIFStarter_Instance *_instance, int delay){
if (PIFStarter_send_timer_timer_start_listener != 0x0) PIFStarter_send_timer_timer_start_listener(_instance, delay);
}
void (*PIFStarter_send_timer_timer_cancel_listener)(struct PIFStarter_Instance*)= 0x0;
void register_PIFStarter_send_timer_timer_cancel_listener(void (*_listener)(struct PIFStarter_Instance*)){
PIFStarter_send_timer_timer_cancel_listener = _listener;
}
void PIFStarter_send_timer_timer_cancel(struct PIFStarter_Instance *_instance){
if (PIFStarter_send_timer_timer_cancel_listener != 0x0) PIFStarter_send_timer_timer_cancel_listener(_instance);
}
void (*PIFStarter_send_to_ender_pif_token_listener)(struct PIFStarter_Instance*, int)= 0x0;
void register_PIFStarter_send_to_ender_pif_token_listener(void (*_listener)(struct PIFStarter_Instance*, int)){
PIFStarter_send_to_ender_pif_token_listener = _listener;
}
void PIFStarter_send_to_ender_pif_token(struct PIFStarter_Instance *_instance, int token){
if (PIFStarter_send_to_ender_pif_token_listener != 0x0) PIFStarter_send_to_ender_pif_token_listener(_instance, token);
}
void (*PIFStarter_send_Print_customPrintS_listener)(struct PIFStarter_Instance*, char *)= 0x0;
void register_PIFStarter_send_Print_customPrintS_listener(void (*_listener)(struct PIFStarter_Instance*, char *)){
PIFStarter_send_Print_customPrintS_listener = _listener;
}
void PIFStarter_send_Print_customPrintS(struct PIFStarter_Instance *_instance, char * myString){
if (PIFStarter_send_Print_customPrintS_listener != 0x0) PIFStarter_send_Print_customPrintS_listener(_instance, myString);
}
void (*PIFStarter_send_Print_customPrintI_listener)(struct PIFStarter_Instance*, int)= 0x0;
void register_PIFStarter_send_Print_customPrintI_listener(void (*_listener)(struct PIFStarter_Instance*, int)){
PIFStarter_send_Print_customPrintI_listener = _listener;
}
void PIFStarter_send_Print_customPrintI(struct PIFStarter_Instance *_instance, int myInt){
if (PIFStarter_send_Print_customPrintI_listener != 0x0) PIFStarter_send_Print_customPrintI_listener(_instance, myInt);
}

