/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing PIFStarter
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef PIFStarter_H_
#define PIFStarter_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : PIFStarter
 *****************************************************************************/

// Definition of the instance stuct:
struct PIFStarter_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int PIFStarter_behavior_State;
// Variables for the properties of the instance
int PIFStarter_period__var;
};

// Declaration of prototypes outgoing messages:
void PIFStarter_behavior_OnEntry(int state, struct PIFStarter_Instance *_instance);
void PIFStarter_handle_from_ender_pif_token(struct PIFStarter_Instance *_instance, int token);
void PIFStarter_handle_timer_timer_timeout(struct PIFStarter_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_PIFStarter_send_timer_timer_start_listener(void (*_listener)(struct PIFStarter_Instance*, int));
void register_PIFStarter_send_timer_timer_cancel_listener(void (*_listener)(struct PIFStarter_Instance*));
void register_PIFStarter_send_to_ender_pif_token_listener(void (*_listener)(struct PIFStarter_Instance*, int));
void register_PIFStarter_send_Print_customPrintS_listener(void (*_listener)(struct PIFStarter_Instance*, char *));
void register_PIFStarter_send_Print_customPrintI_listener(void (*_listener)(struct PIFStarter_Instance*, int));

// Definition of the states:
#define PIFSTARTER_BEHAVIOR_STATE 0
#define PIFSTARTER_BEHAVIOR_INIT_STATE 1
#define PIFSTARTER_BEHAVIOR_WAIT_STATE 2



#ifdef __cplusplus
}
#endif

#endif //PIFStarter_H_