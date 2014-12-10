/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing PIFEnder
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef PIFEnder_H_
#define PIFEnder_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : PIFEnder
 *****************************************************************************/

// Definition of the instance stuct:
struct PIFEnder_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int PIFEnder_behavior_State;
// Variables for the properties of the instance
int PIFEnder_behavior_tmp__var;
};

// Declaration of prototypes outgoing messages:
void PIFEnder_behavior_OnEntry(int state, struct PIFEnder_Instance *_instance);
void PIFEnder_handle_from_starter_pif_token(struct PIFEnder_Instance *_instance, int token);
// Declaration of callbacks for incomming messages:
void register_PIFEnder_send_to_starter_pif_token_listener(void (*_listener)(struct PIFEnder_Instance*, int));
void register_PIFEnder_send_Print_customPrintS_listener(void (*_listener)(struct PIFEnder_Instance*, char *));
void register_PIFEnder_send_Print_customPrintI_listener(void (*_listener)(struct PIFEnder_Instance*, int));

// Definition of the states:
#define PIFENDER_BEHAVIOR_STATE 0
#define PIFENDER_BEHAVIOR_INIT_STATE 1



#ifdef __cplusplus
}
#endif

#endif //PIFEnder_H_