/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application CPIF
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
#include "PIFIncDec.h"
#include "CPrinter.h"
#include "PIFStarter.h"
#include "ClockLinux.h"
#include "PIFEnder.h"
#include "TimerLinux.h"


// NO C_HEADERS Annotation


/*****************************************************************************
 * Definitions for configuration : CPIF
 *****************************************************************************/

//Declaration of instance variables
struct CPrinter_Instance CPIF_printer_var;
struct PIFEnder_Instance CPIF_ender_var;
struct TimerLinux_Instance CPIF_timer_var;
struct PIFIncDec_Instance CPIF_pif3_var;
struct PIFIncDec_Instance CPIF_pif6_var;
struct PIFIncDec_Instance CPIF_pif5_var;
struct ClockLinux_Instance CPIF_clock_var;
struct PIFStarter_Instance CPIF_starter_var;
struct PIFIncDec_Instance CPIF_pif1_var;
struct PIFIncDec_Instance CPIF_pif4_var;
struct PIFIncDec_Instance CPIF_pif2_var;

// Enqueue of messages PIFStarter::timer::timer_start
void enqueue_PIFStarter_send_timer_timer_start(struct PIFStarter_Instance *_instance, int delay){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter delay
_fifo_enqueue((delay>>8) & 0xFF);
_fifo_enqueue(delay & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFStarter::timer::timer_cancel
void enqueue_PIFStarter_send_timer_timer_cancel(struct PIFStarter_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFStarter::to_ender::pif_token
void enqueue_PIFStarter_send_to_ender_pif_token(struct PIFStarter_Instance *_instance, int token){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter token
_fifo_enqueue((token>>8) & 0xFF);
_fifo_enqueue(token & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFStarter::Print::customPrintS
void enqueue_PIFStarter_send_Print_customPrintS(struct PIFStarter_Instance *_instance, char * myString){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter myString
ptr_union_t __ptrunion_myString;
__ptrunion_myString.pointer = (void*)myString;
_fifo_enqueue( __ptrunion_myString.buffer[0] );
_fifo_enqueue( __ptrunion_myString.buffer[1] );
_fifo_enqueue( __ptrunion_myString.buffer[2] );
_fifo_enqueue( __ptrunion_myString.buffer[3] );
_fifo_enqueue( __ptrunion_myString.buffer[4] );
_fifo_enqueue( __ptrunion_myString.buffer[5] );
_fifo_enqueue( __ptrunion_myString.buffer[6] );
_fifo_enqueue( __ptrunion_myString.buffer[7] );
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFStarter::Print::customPrintI
void enqueue_PIFStarter_send_Print_customPrintI(struct PIFStarter_Instance *_instance, int myInt){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter myInt
_fifo_enqueue((myInt>>8) & 0xFF);
_fifo_enqueue(myInt & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFEnder::to_starter::pif_token
void enqueue_PIFEnder_send_to_starter_pif_token(struct PIFEnder_Instance *_instance, int token){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter token
_fifo_enqueue((token>>8) & 0xFF);
_fifo_enqueue(token & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFEnder::Print::customPrintS
void enqueue_PIFEnder_send_Print_customPrintS(struct PIFEnder_Instance *_instance, char * myString){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter myString
ptr_union_t __ptrunion_myString;
__ptrunion_myString.pointer = (void*)myString;
_fifo_enqueue( __ptrunion_myString.buffer[0] );
_fifo_enqueue( __ptrunion_myString.buffer[1] );
_fifo_enqueue( __ptrunion_myString.buffer[2] );
_fifo_enqueue( __ptrunion_myString.buffer[3] );
_fifo_enqueue( __ptrunion_myString.buffer[4] );
_fifo_enqueue( __ptrunion_myString.buffer[5] );
_fifo_enqueue( __ptrunion_myString.buffer[6] );
_fifo_enqueue( __ptrunion_myString.buffer[7] );
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFEnder::Print::customPrintI
void enqueue_PIFEnder_send_Print_customPrintI(struct PIFEnder_Instance *_instance, int myInt){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter myInt
_fifo_enqueue((myInt>>8) & 0xFF);
_fifo_enqueue(myInt & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFIncDec::to_ender::pif_token
void enqueue_PIFIncDec_send_to_ender_pif_token(struct PIFIncDec_Instance *_instance, int token){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (9 >> 8) & 0xFF );
_fifo_enqueue( 9 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter token
_fifo_enqueue((token>>8) & 0xFF);
_fifo_enqueue(token & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFIncDec::to_starter::pif_token
void enqueue_PIFIncDec_send_to_starter_pif_token(struct PIFIncDec_Instance *_instance, int token){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (10 >> 8) & 0xFF );
_fifo_enqueue( 10 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter token
_fifo_enqueue((token>>8) & 0xFF);
_fifo_enqueue(token & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFIncDec::Print::customPrintS
void enqueue_PIFIncDec_send_Print_customPrintS(struct PIFIncDec_Instance *_instance, char * myString){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (11 >> 8) & 0xFF );
_fifo_enqueue( 11 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter myString
ptr_union_t __ptrunion_myString;
__ptrunion_myString.pointer = (void*)myString;
_fifo_enqueue( __ptrunion_myString.buffer[0] );
_fifo_enqueue( __ptrunion_myString.buffer[1] );
_fifo_enqueue( __ptrunion_myString.buffer[2] );
_fifo_enqueue( __ptrunion_myString.buffer[3] );
_fifo_enqueue( __ptrunion_myString.buffer[4] );
_fifo_enqueue( __ptrunion_myString.buffer[5] );
_fifo_enqueue( __ptrunion_myString.buffer[6] );
_fifo_enqueue( __ptrunion_myString.buffer[7] );
}
fifo_unlock_and_notify();
}
// Enqueue of messages PIFIncDec::Print::customPrintI
void enqueue_PIFIncDec_send_Print_customPrintI(struct PIFIncDec_Instance *_instance, int myInt){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (12 >> 8) & 0xFF );
_fifo_enqueue( 12 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter myInt
_fifo_enqueue((myInt>>8) & 0xFF);
_fifo_enqueue(myInt & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages ClockLinux::signal::clock_tick
void enqueue_ClockLinux_send_signal_clock_tick(struct ClockLinux_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (13 >> 8) & 0xFF );
_fifo_enqueue( 13 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages TimerLinux::timer::timer_timeout
void enqueue_TimerLinux_send_timer_timer_timeout(struct TimerLinux_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (14 >> 8) & 0xFF );
_fifo_enqueue( 14 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
fifo_unlock_and_notify();
}

// Dispatch for messages PIFIncDec::to_ender::pif_token
void dispatch_PIFIncDec_send_to_ender_pif_token(struct PIFIncDec_Instance *_instance, int token){
if (_instance == &CPIF_pif4_var) {
PIFIncDec_handle_from_starter_pif_token(&CPIF_pif5_var, token);
}
if (_instance == &CPIF_pif5_var) {
PIFIncDec_handle_from_starter_pif_token(&CPIF_pif6_var, token);
}
if (_instance == &CPIF_pif3_var) {
PIFIncDec_handle_from_starter_pif_token(&CPIF_pif4_var, token);
}
if (_instance == &CPIF_pif2_var) {
PIFIncDec_handle_from_starter_pif_token(&CPIF_pif3_var, token);
}
if (_instance == &CPIF_pif6_var) {
PIFEnder_handle_from_starter_pif_token(&CPIF_ender_var, token);
}
if (_instance == &CPIF_pif1_var) {
PIFIncDec_handle_from_starter_pif_token(&CPIF_pif2_var, token);
}
}
// Dispatch for messages PIFIncDec::to_starter::pif_token
void dispatch_PIFIncDec_send_to_starter_pif_token(struct PIFIncDec_Instance *_instance, int token){
if (_instance == &CPIF_pif2_var) {
PIFIncDec_handle_from_ender_pif_token(&CPIF_pif1_var, token);
}
if (_instance == &CPIF_pif4_var) {
PIFIncDec_handle_from_ender_pif_token(&CPIF_pif3_var, token);
}
if (_instance == &CPIF_pif3_var) {
PIFIncDec_handle_from_ender_pif_token(&CPIF_pif2_var, token);
}
if (_instance == &CPIF_pif1_var) {
PIFStarter_handle_from_ender_pif_token(&CPIF_starter_var, token);
}
if (_instance == &CPIF_pif5_var) {
PIFIncDec_handle_from_ender_pif_token(&CPIF_pif4_var, token);
}
if (_instance == &CPIF_pif6_var) {
PIFIncDec_handle_from_ender_pif_token(&CPIF_pif5_var, token);
}
}
// Dispatch for messages PIFIncDec::Print::customPrintS
void dispatch_PIFIncDec_send_Print_customPrintS(struct PIFIncDec_Instance *_instance, char * myString){
if (_instance == &CPIF_pif4_var) {
CPrinter_handle_Print_customPrintS(&CPIF_printer_var, myString);
}
if (_instance == &CPIF_pif5_var) {
CPrinter_handle_Print_customPrintS(&CPIF_printer_var, myString);
}
if (_instance == &CPIF_pif6_var) {
CPrinter_handle_Print_customPrintS(&CPIF_printer_var, myString);
}
if (_instance == &CPIF_pif1_var) {
CPrinter_handle_Print_customPrintS(&CPIF_printer_var, myString);
}
if (_instance == &CPIF_pif3_var) {
CPrinter_handle_Print_customPrintS(&CPIF_printer_var, myString);
}
if (_instance == &CPIF_pif2_var) {
CPrinter_handle_Print_customPrintS(&CPIF_printer_var, myString);
}
}
// Dispatch for messages PIFIncDec::Print::customPrintI
void dispatch_PIFIncDec_send_Print_customPrintI(struct PIFIncDec_Instance *_instance, int myInt){
if (_instance == &CPIF_pif4_var) {
CPrinter_handle_Print_customPrintI(&CPIF_printer_var, myInt);
}
if (_instance == &CPIF_pif5_var) {
CPrinter_handle_Print_customPrintI(&CPIF_printer_var, myInt);
}
if (_instance == &CPIF_pif6_var) {
CPrinter_handle_Print_customPrintI(&CPIF_printer_var, myInt);
}
if (_instance == &CPIF_pif1_var) {
CPrinter_handle_Print_customPrintI(&CPIF_printer_var, myInt);
}
if (_instance == &CPIF_pif3_var) {
CPrinter_handle_Print_customPrintI(&CPIF_printer_var, myInt);
}
if (_instance == &CPIF_pif2_var) {
CPrinter_handle_Print_customPrintI(&CPIF_printer_var, myInt);
}
}
// Dispatch for messages ClockLinux::signal::clock_tick
void dispatch_ClockLinux_send_signal_clock_tick(struct ClockLinux_Instance *_instance){
if (_instance == &CPIF_clock_var) {
TimerLinux_handle_clock_clock_tick(&CPIF_timer_var);
}
}
// Dispatch for messages PIFStarter::timer::timer_start
void dispatch_PIFStarter_send_timer_timer_start(struct PIFStarter_Instance *_instance, int delay){
if (_instance == &CPIF_starter_var) {
TimerLinux_handle_timer_timer_start(&CPIF_timer_var, delay);
}
}
// Dispatch for messages PIFStarter::timer::timer_cancel
void dispatch_PIFStarter_send_timer_timer_cancel(struct PIFStarter_Instance *_instance){
if (_instance == &CPIF_starter_var) {
TimerLinux_handle_timer_timer_cancel(&CPIF_timer_var);
}
}
// Dispatch for messages PIFStarter::to_ender::pif_token
void dispatch_PIFStarter_send_to_ender_pif_token(struct PIFStarter_Instance *_instance, int token){
if (_instance == &CPIF_starter_var) {
PIFIncDec_handle_from_starter_pif_token(&CPIF_pif1_var, token);
}
}
// Dispatch for messages PIFStarter::Print::customPrintS
void dispatch_PIFStarter_send_Print_customPrintS(struct PIFStarter_Instance *_instance, char * myString){
if (_instance == &CPIF_starter_var) {
CPrinter_handle_Print_customPrintS(&CPIF_printer_var, myString);
}
}
// Dispatch for messages PIFStarter::Print::customPrintI
void dispatch_PIFStarter_send_Print_customPrintI(struct PIFStarter_Instance *_instance, int myInt){
if (_instance == &CPIF_starter_var) {
CPrinter_handle_Print_customPrintI(&CPIF_printer_var, myInt);
}
}
// Dispatch for messages PIFEnder::to_starter::pif_token
void dispatch_PIFEnder_send_to_starter_pif_token(struct PIFEnder_Instance *_instance, int token){
if (_instance == &CPIF_ender_var) {
PIFIncDec_handle_from_ender_pif_token(&CPIF_pif6_var, token);
}
}
// Dispatch for messages PIFEnder::Print::customPrintS
void dispatch_PIFEnder_send_Print_customPrintS(struct PIFEnder_Instance *_instance, char * myString){
if (_instance == &CPIF_ender_var) {
CPrinter_handle_Print_customPrintS(&CPIF_printer_var, myString);
}
}
// Dispatch for messages PIFEnder::Print::customPrintI
void dispatch_PIFEnder_send_Print_customPrintI(struct PIFEnder_Instance *_instance, int myInt){
if (_instance == &CPIF_ender_var) {
CPrinter_handle_Print_customPrintI(&CPIF_printer_var, myInt);
}
}
// Dispatch for messages TimerLinux::timer::timer_timeout
void dispatch_TimerLinux_send_timer_timer_timeout(struct TimerLinux_Instance *_instance){
if (_instance == &CPIF_timer_var) {
PIFStarter_handle_timer_timer_timeout(&CPIF_starter_var);
}
}

void processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
byte mbuf[10];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 1:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFStarter_send_timer_timer_start((struct PIFStarter_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* delay */ );
break;
case 2:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFStarter_send_timer_timer_cancel((struct PIFStarter_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 3:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFStarter_send_to_ender_pif_token((struct PIFStarter_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* token */ );
break;
case 4:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFStarter_send_Print_customPrintS((struct PIFStarter_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* myString */ );
break;
case 5:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFStarter_send_Print_customPrintI((struct PIFStarter_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* myInt */ );
break;
case 9:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFIncDec_send_to_ender_pif_token((struct PIFIncDec_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* token */ );
break;
case 10:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFIncDec_send_to_starter_pif_token((struct PIFIncDec_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* token */ );
break;
case 11:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFIncDec_send_Print_customPrintS((struct PIFIncDec_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* myString */ );
break;
case 12:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFIncDec_send_Print_customPrintI((struct PIFIncDec_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* myInt */ );
break;
case 13:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_ClockLinux_send_signal_clock_tick((struct ClockLinux_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 14:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_TimerLinux_send_timer_timer_timeout((struct TimerLinux_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 6:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFEnder_send_to_starter_pif_token((struct PIFEnder_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* token */ );
break;
case 7:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFEnder_send_Print_customPrintS((struct PIFEnder_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* myString */ );
break;
case 8:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_PIFEnder_send_Print_customPrintI((struct PIFEnder_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* myInt */ );
break;
}
}

void initialize_configuration_CPIF() {
// Initialize connectors
register_TimerLinux_send_timer_timer_timeout_listener(enqueue_TimerLinux_send_timer_timer_timeout);
register_PIFEnder_send_to_starter_pif_token_listener(enqueue_PIFEnder_send_to_starter_pif_token);
register_PIFEnder_send_Print_customPrintS_listener(enqueue_PIFEnder_send_Print_customPrintS);
register_PIFEnder_send_Print_customPrintI_listener(enqueue_PIFEnder_send_Print_customPrintI);
register_PIFIncDec_send_to_ender_pif_token_listener(enqueue_PIFIncDec_send_to_ender_pif_token);
register_PIFIncDec_send_to_starter_pif_token_listener(enqueue_PIFIncDec_send_to_starter_pif_token);
register_PIFIncDec_send_Print_customPrintS_listener(enqueue_PIFIncDec_send_Print_customPrintS);
register_PIFIncDec_send_Print_customPrintI_listener(enqueue_PIFIncDec_send_Print_customPrintI);
register_PIFStarter_send_timer_timer_start_listener(enqueue_PIFStarter_send_timer_timer_start);
register_PIFStarter_send_timer_timer_cancel_listener(enqueue_PIFStarter_send_timer_timer_cancel);
register_PIFStarter_send_to_ender_pif_token_listener(enqueue_PIFStarter_send_to_ender_pif_token);
register_PIFStarter_send_Print_customPrintS_listener(enqueue_PIFStarter_send_Print_customPrintS);
register_PIFStarter_send_Print_customPrintI_listener(enqueue_PIFStarter_send_Print_customPrintI);
register_ClockLinux_send_signal_clock_tick_listener(enqueue_ClockLinux_send_signal_clock_tick);

// Init the ID, state variables and properties for instance CPIF_pif2
CPIF_pif2_var.id = add_instance( (void*) &CPIF_pif2_var);
CPIF_pif2_var.PIFIncDec_behavior_State = PIFINCDEC_BEHAVIOR_INIT_STATE;

// Init the ID, state variables and properties for instance CPIF_ender
CPIF_ender_var.id = add_instance( (void*) &CPIF_ender_var);
CPIF_ender_var.PIFEnder_behavior_State = PIFENDER_BEHAVIOR_INIT_STATE;

// Init the ID, state variables and properties for instance CPIF_pif1
CPIF_pif1_var.id = add_instance( (void*) &CPIF_pif1_var);
CPIF_pif1_var.PIFIncDec_behavior_State = PIFINCDEC_BEHAVIOR_INIT_STATE;

// Init the ID, state variables and properties for instance CPIF_pif3
CPIF_pif3_var.id = add_instance( (void*) &CPIF_pif3_var);
CPIF_pif3_var.PIFIncDec_behavior_State = PIFINCDEC_BEHAVIOR_INIT_STATE;

// Init the ID, state variables and properties for instance CPIF_pif4
CPIF_pif4_var.id = add_instance( (void*) &CPIF_pif4_var);
CPIF_pif4_var.PIFIncDec_behavior_State = PIFINCDEC_BEHAVIOR_INIT_STATE;

// Init the ID, state variables and properties for instance CPIF_pif5
CPIF_pif5_var.id = add_instance( (void*) &CPIF_pif5_var);
CPIF_pif5_var.PIFIncDec_behavior_State = PIFINCDEC_BEHAVIOR_INIT_STATE;

// Init the ID, state variables and properties for instance CPIF_clock
CPIF_clock_var.id = add_instance( (void*) &CPIF_clock_var);
CPIF_clock_var.ClockLinux_ClockImpl_State = CLOCKLINUX_CLOCKIMPL_TICKING_STATE;
CPIF_clock_var.Clock_period__var = 100;

// Init the ID, state variables and properties for instance CPIF_printer
CPIF_printer_var.id = add_instance( (void*) &CPIF_printer_var);
CPIF_printer_var.CPrinter_behavior_State = CPRINTER_BEHAVIOR_GREETINGS_STATE;

// Init the ID, state variables and properties for instance CPIF_pif6
CPIF_pif6_var.id = add_instance( (void*) &CPIF_pif6_var);
CPIF_pif6_var.PIFIncDec_behavior_State = PIFINCDEC_BEHAVIOR_INIT_STATE;

// Init the ID, state variables and properties for instance CPIF_timer
CPIF_timer_var.id = add_instance( (void*) &CPIF_timer_var);
CPIF_timer_var.TimerLinux_ClockTimerImpl_State = TIMERLINUX_CLOCKTIMERIMPL_IDLE_STATE;
CPIF_timer_var.TimerLinux_millisecond__var = 1;
CPIF_timer_var.TimerLinux_period__var = 100;
CPIF_timer_var.TimerLinux_ClockTimerImpl_remaining__var = 0;

// Init the ID, state variables and properties for instance CPIF_starter
CPIF_starter_var.id = add_instance( (void*) &CPIF_starter_var);
CPIF_starter_var.PIFStarter_behavior_State = PIFSTARTER_BEHAVIOR_INIT_STATE;
CPIF_starter_var.PIFStarter_period__var = 5000;

PIFEnder_behavior_OnEntry(PIFENDER_BEHAVIOR_STATE, &CPIF_ender_var);
CPrinter_behavior_OnEntry(CPRINTER_BEHAVIOR_STATE, &CPIF_printer_var);
PIFIncDec_behavior_OnEntry(PIFINCDEC_BEHAVIOR_STATE, &CPIF_pif2_var);
PIFStarter_behavior_OnEntry(PIFSTARTER_BEHAVIOR_STATE, &CPIF_starter_var);
PIFIncDec_behavior_OnEntry(PIFINCDEC_BEHAVIOR_STATE, &CPIF_pif6_var);
PIFIncDec_behavior_OnEntry(PIFINCDEC_BEHAVIOR_STATE, &CPIF_pif3_var);
PIFIncDec_behavior_OnEntry(PIFINCDEC_BEHAVIOR_STATE, &CPIF_pif5_var);
PIFIncDec_behavior_OnEntry(PIFINCDEC_BEHAVIOR_STATE, &CPIF_pif4_var);
PIFIncDec_behavior_OnEntry(PIFINCDEC_BEHAVIOR_STATE, &CPIF_pif1_var);
TimerLinux_ClockTimerImpl_OnEntry(TIMERLINUX_CLOCKTIMERIMPL_STATE, &CPIF_timer_var);
ClockLinux_ClockImpl_OnEntry(CLOCKLINUX_CLOCKIMPL_STATE, &CPIF_clock_var);
}


// NO C_GLOBALS Annotation

int main(int argc, char *argv[]) {
  init_runtime();
  // NO C_MAIN Annotation
  initialize_configuration_CPIF();

  while (1) {
    
    processMessageQueue();
  }
}