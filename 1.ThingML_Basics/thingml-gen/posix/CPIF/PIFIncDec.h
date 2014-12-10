/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing PIFIncDec
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef PIFIncDec_H_
#define PIFIncDec_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : PIFIncDec
 *****************************************************************************/

// Definition of the instance stuct:
struct PIFIncDec_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int PIFIncDec_behavior_State;
// Variables for the properties of the instance
int PIFIncDec_behavior_tmp__var;
};

// Declaration of prototypes outgoing messages:
void PIFIncDec_behavior_OnEntry(int state, struct PIFIncDec_Instance *_instance);
void PIFIncDec_handle_from_starter_pif_token(struct PIFIncDec_Instance *_instance, int token);
void PIFIncDec_handle_from_ender_pif_token(struct PIFIncDec_Instance *_instance, int token);
// Declaration of callbacks for incomming messages:
void register_PIFIncDec_send_to_ender_pif_token_listener(void (*_listener)(struct PIFIncDec_Instance*, int));
void register_PIFIncDec_send_to_starter_pif_token_listener(void (*_listener)(struct PIFIncDec_Instance*, int));
void register_PIFIncDec_send_Print_customPrintS_listener(void (*_listener)(struct PIFIncDec_Instance*, char *));
void register_PIFIncDec_send_Print_customPrintI_listener(void (*_listener)(struct PIFIncDec_Instance*, int));

// Definition of the states:
#define PIFINCDEC_BEHAVIOR_STATE 0
#define PIFINCDEC_BEHAVIOR_INIT_STATE 1



#ifdef __cplusplus
}
#endif

#endif //PIFIncDec_H_