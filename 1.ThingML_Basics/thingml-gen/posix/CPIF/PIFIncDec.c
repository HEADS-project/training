/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing PIFIncDec
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "PIFIncDec.h"

/*****************************************************************************
 * Implementation for type : PIFIncDec
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void PIFIncDec_behavior_OnExit(int state, struct PIFIncDec_Instance *_instance);
void PIFIncDec_send_to_ender_pif_token(struct PIFIncDec_Instance *_instance, int token);
void PIFIncDec_send_to_starter_pif_token(struct PIFIncDec_Instance *_instance, int token);
void PIFIncDec_send_Print_customPrintS(struct PIFIncDec_Instance *_instance, char * myString);
void PIFIncDec_send_Print_customPrintI(struct PIFIncDec_Instance *_instance, int myInt);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void PIFIncDec_behavior_OnEntry(int state, struct PIFIncDec_Instance *_instance) {
switch(state) {
case PIFINCDEC_BEHAVIOR_STATE:
_instance->PIFIncDec_behavior_State = PIFINCDEC_BEHAVIOR_INIT_STATE;
PIFIncDec_behavior_OnEntry(_instance->PIFIncDec_behavior_State, _instance);
break;
case PIFINCDEC_BEHAVIOR_INIT_STATE:
break;
default: break;
}
}

// On Exit Actions:
void PIFIncDec_behavior_OnExit(int state, struct PIFIncDec_Instance *_instance) {
switch(state) {
case PIFINCDEC_BEHAVIOR_STATE:
PIFIncDec_behavior_OnExit(_instance->PIFIncDec_behavior_State, _instance);
break;
case PIFINCDEC_BEHAVIOR_INIT_STATE:
break;
default: break;
}
}

// Event Handlers for incoming messages:
void PIFIncDec_handle_from_starter_pif_token(struct PIFIncDec_Instance *_instance, int token) {
uint8_t PIFIncDec_behavior_State_event_consumed = 0;
if (_instance->PIFIncDec_behavior_State == PIFINCDEC_BEHAVIOR_INIT_STATE) {
if (PIFIncDec_behavior_State_event_consumed == 0 && 1) {
PIFIncDec_behavior_OnExit(PIFINCDEC_BEHAVIOR_INIT_STATE, _instance);
_instance->PIFIncDec_behavior_State = PIFINCDEC_BEHAVIOR_INIT_STATE;
{
_instance->PIFIncDec_behavior_tmp__var = token;
PIFIncDec_send_Print_customPrintI(_instance, _instance->PIFIncDec_behavior_tmp__var);
_instance->PIFIncDec_behavior_tmp__var = _instance->PIFIncDec_behavior_tmp__var + 1;
PIFIncDec_send_to_ender_pif_token(_instance, _instance->PIFIncDec_behavior_tmp__var);
}
PIFIncDec_behavior_OnEntry(PIFINCDEC_BEHAVIOR_INIT_STATE, _instance);
PIFIncDec_behavior_State_event_consumed = 1;
}
}
}
void PIFIncDec_handle_from_ender_pif_token(struct PIFIncDec_Instance *_instance, int token) {
uint8_t PIFIncDec_behavior_State_event_consumed = 0;
if (_instance->PIFIncDec_behavior_State == PIFINCDEC_BEHAVIOR_INIT_STATE) {
if (PIFIncDec_behavior_State_event_consumed == 0 && 1) {
PIFIncDec_behavior_OnExit(PIFINCDEC_BEHAVIOR_INIT_STATE, _instance);
_instance->PIFIncDec_behavior_State = PIFINCDEC_BEHAVIOR_INIT_STATE;
{
_instance->PIFIncDec_behavior_tmp__var = token;
PIFIncDec_send_Print_customPrintI(_instance, _instance->PIFIncDec_behavior_tmp__var);
_instance->PIFIncDec_behavior_tmp__var = _instance->PIFIncDec_behavior_tmp__var - 1;
PIFIncDec_send_to_starter_pif_token(_instance, _instance->PIFIncDec_behavior_tmp__var);
}
PIFIncDec_behavior_OnEntry(PIFINCDEC_BEHAVIOR_INIT_STATE, _instance);
PIFIncDec_behavior_State_event_consumed = 1;
}
}
}

// Observers for outgoing messages:
void (*PIFIncDec_send_to_ender_pif_token_listener)(struct PIFIncDec_Instance*, int)= 0x0;
void register_PIFIncDec_send_to_ender_pif_token_listener(void (*_listener)(struct PIFIncDec_Instance*, int)){
PIFIncDec_send_to_ender_pif_token_listener = _listener;
}
void PIFIncDec_send_to_ender_pif_token(struct PIFIncDec_Instance *_instance, int token){
if (PIFIncDec_send_to_ender_pif_token_listener != 0x0) PIFIncDec_send_to_ender_pif_token_listener(_instance, token);
}
void (*PIFIncDec_send_to_starter_pif_token_listener)(struct PIFIncDec_Instance*, int)= 0x0;
void register_PIFIncDec_send_to_starter_pif_token_listener(void (*_listener)(struct PIFIncDec_Instance*, int)){
PIFIncDec_send_to_starter_pif_token_listener = _listener;
}
void PIFIncDec_send_to_starter_pif_token(struct PIFIncDec_Instance *_instance, int token){
if (PIFIncDec_send_to_starter_pif_token_listener != 0x0) PIFIncDec_send_to_starter_pif_token_listener(_instance, token);
}
void (*PIFIncDec_send_Print_customPrintS_listener)(struct PIFIncDec_Instance*, char *)= 0x0;
void register_PIFIncDec_send_Print_customPrintS_listener(void (*_listener)(struct PIFIncDec_Instance*, char *)){
PIFIncDec_send_Print_customPrintS_listener = _listener;
}
void PIFIncDec_send_Print_customPrintS(struct PIFIncDec_Instance *_instance, char * myString){
if (PIFIncDec_send_Print_customPrintS_listener != 0x0) PIFIncDec_send_Print_customPrintS_listener(_instance, myString);
}
void (*PIFIncDec_send_Print_customPrintI_listener)(struct PIFIncDec_Instance*, int)= 0x0;
void register_PIFIncDec_send_Print_customPrintI_listener(void (*_listener)(struct PIFIncDec_Instance*, int)){
PIFIncDec_send_Print_customPrintI_listener = _listener;
}
void PIFIncDec_send_Print_customPrintI(struct PIFIncDec_Instance *_instance, int myInt){
if (PIFIncDec_send_Print_customPrintI_listener != 0x0) PIFIncDec_send_Print_customPrintI_listener(_instance, myInt);
}

