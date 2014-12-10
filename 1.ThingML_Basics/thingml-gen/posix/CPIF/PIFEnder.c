/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing PIFEnder
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "PIFEnder.h"

/*****************************************************************************
 * Implementation for type : PIFEnder
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void PIFEnder_behavior_OnExit(int state, struct PIFEnder_Instance *_instance);
void PIFEnder_send_to_starter_pif_token(struct PIFEnder_Instance *_instance, int token);
void PIFEnder_send_Print_customPrintS(struct PIFEnder_Instance *_instance, char * myString);
void PIFEnder_send_Print_customPrintI(struct PIFEnder_Instance *_instance, int myInt);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void PIFEnder_behavior_OnEntry(int state, struct PIFEnder_Instance *_instance) {
switch(state) {
case PIFENDER_BEHAVIOR_STATE:
_instance->PIFEnder_behavior_State = PIFENDER_BEHAVIOR_INIT_STATE;
PIFEnder_behavior_OnEntry(_instance->PIFEnder_behavior_State, _instance);
break;
case PIFENDER_BEHAVIOR_INIT_STATE:
break;
default: break;
}
}

// On Exit Actions:
void PIFEnder_behavior_OnExit(int state, struct PIFEnder_Instance *_instance) {
switch(state) {
case PIFENDER_BEHAVIOR_STATE:
PIFEnder_behavior_OnExit(_instance->PIFEnder_behavior_State, _instance);
break;
case PIFENDER_BEHAVIOR_INIT_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void PIFEnder_handle_from_starter_pif_token(struct PIFEnder_Instance *_instance, int token) {
uint8_t PIFEnder_behavior_State_event_consumed = 0;
if (_instance->PIFEnder_behavior_State == PIFENDER_BEHAVIOR_INIT_STATE) {
if (PIFEnder_behavior_State_event_consumed == 0 && 1) {
PIFEnder_behavior_OnExit(PIFENDER_BEHAVIOR_INIT_STATE, _instance);
_instance->PIFEnder_behavior_State = PIFENDER_BEHAVIOR_INIT_STATE;
{
_instance->PIFEnder_behavior_tmp__var = token;
PIFEnder_send_Print_customPrintS(_instance, " ... Ender returns token ... ");
_instance->PIFEnder_behavior_tmp__var = _instance->PIFEnder_behavior_tmp__var - 1;
PIFEnder_send_to_starter_pif_token(_instance, _instance->PIFEnder_behavior_tmp__var);
}
PIFEnder_behavior_OnEntry(PIFENDER_BEHAVIOR_INIT_STATE, _instance);
PIFEnder_behavior_State_event_consumed = 1;
}
}
}

// Observers for outgoing messages:
void (*PIFEnder_send_to_starter_pif_token_listener)(struct PIFEnder_Instance*, int)= 0x0;
void register_PIFEnder_send_to_starter_pif_token_listener(void (*_listener)(struct PIFEnder_Instance*, int)){
PIFEnder_send_to_starter_pif_token_listener = _listener;
}
void PIFEnder_send_to_starter_pif_token(struct PIFEnder_Instance *_instance, int token){
if (PIFEnder_send_to_starter_pif_token_listener != 0x0) PIFEnder_send_to_starter_pif_token_listener(_instance, token);
}
void (*PIFEnder_send_Print_customPrintS_listener)(struct PIFEnder_Instance*, char *)= 0x0;
void register_PIFEnder_send_Print_customPrintS_listener(void (*_listener)(struct PIFEnder_Instance*, char *)){
PIFEnder_send_Print_customPrintS_listener = _listener;
}
void PIFEnder_send_Print_customPrintS(struct PIFEnder_Instance *_instance, char * myString){
if (PIFEnder_send_Print_customPrintS_listener != 0x0) PIFEnder_send_Print_customPrintS_listener(_instance, myString);
}
void (*PIFEnder_send_Print_customPrintI_listener)(struct PIFEnder_Instance*, int)= 0x0;
void register_PIFEnder_send_Print_customPrintI_listener(void (*_listener)(struct PIFEnder_Instance*, int)){
PIFEnder_send_Print_customPrintI_listener = _listener;
}
void PIFEnder_send_Print_customPrintI(struct PIFEnder_Instance *_instance, int myInt){
if (PIFEnder_send_Print_customPrintI_listener != 0x0) PIFEnder_send_Print_customPrintI_listener(_instance, myInt);
}

