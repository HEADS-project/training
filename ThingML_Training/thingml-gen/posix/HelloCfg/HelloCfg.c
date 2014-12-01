/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application HelloCfg
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <pthread.h>
#include "thingml_typedefs.h"
#include "runtime.h"
#include "HelloThing.h"


// NO C_HEADERS Annotation


/*****************************************************************************
 * Definitions for configuration : HelloCfg
 *****************************************************************************/

//Declaration of instance variables
struct HelloThing_Instance HelloCfg_my_instance_var;



void processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
byte mbuf[2];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
}
}

void initialize_configuration_HelloCfg() {
// Initialize connectors

// Init the ID, state variables and properties for instance HelloCfg_my_instance
HelloCfg_my_instance_var.id = add_instance( (void*) &HelloCfg_my_instance_var);
HelloCfg_my_instance_var.HelloThing_HelloWorld_State = HELLOTHING_HELLOWORLD_GREETINGS_STATE;

HelloThing_HelloWorld_OnEntry(HELLOTHING_HELLOWORLD_STATE, &HelloCfg_my_instance_var);
}


// NO C_GLOBALS Annotation

int main(int argc, char *argv[]) {
  init_runtime();
  // NO C_MAIN Annotation
  initialize_configuration_HelloCfg();

  while (1) {
    HelloThing_handle_empty_event(&HelloCfg_my_instance_var);

    processMessageQueue();
  }
}