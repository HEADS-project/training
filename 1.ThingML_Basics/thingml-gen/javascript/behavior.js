var state_js = require('./lib/state.js');
function buildStateMachine(name) {
return new state_js.StateMachine(name);
}

function buildRegion(name, container){
return new state_js.Region(name, container);
}

function buildInitialState(name, container){
return new state_js.PseudoState(name, state_js.PseudoStateKind.Initial, container);
}

function buildFinalState(name, container){
return new state_js.PseudoState(name, state_js.PseudoStateKind.Final, container);
}

function buildHistoryState(name, container){
return new state_js.PseudoState(name, state_js.PseudoStateKind.ShallowHistory, container);
}

function buildSimpleState(name, container){
return new state_js.SimpleState(name, container);
}

function buildCompositeState(name, container){
return new state_js.CompositeState(name, container);
}

function buildOrthogonalState(name, container){
return new state_js.OrthogonalState(name, container);
}

function buildEmptyTransition(source, target){
return new state_js.Transition(source, target);
}

function buildTransition(source, target, guard){
return new state_js.Transition(source, target, guard);
}

function Connector(client, server, clientPort, serverPort) {
this.client = client;
this.server = server;
this.clientPort = clientPort;
this.serverPort = serverPort;
}

Connector.prototype.forward = function(message) {//JSONified messsage, we need to update port before we send to server
var json = JSON.parse(message);
if (json.port === this.clientPort) {
json.port = this.serverPort;
this.server._receive(JSON.stringify(json));
} else {
json.port = this.clientPort;
this.client._receive(JSON.stringify(json));
}
}


/**
 * Definition for type : PIFStarter
 **/
function PIFStarter(PIFStarter_period__var) {

this.ready = false;
//Attributes
this.PIFStarter_period__var =PIFStarter_period__var;//bindings
var connectors = [];
this.getConnectors = function() {
return connectors;
}

//message queue
var queue = [];
this.getQueue = function() {
return queue;
}

//callbacks for third-party listeners
//ThingML-defined functions
//Internal functions
function _send(message) {
var arrayLength = connectors.length;
for (var i = 0; i < arrayLength; i++) {
connectors[i].forward(message);
}
}

function sendTimer_startOnTimer(delay) {
var msg = '{"message":"timer_start","port":"timer_c", "delay":' + delay + '}';
_send(msg);
}

function sendTimer_cancelOnTimer() {
var msg = '{"message":"timer_cancel","port":"timer_c"}';
_send(msg);
}

function sendPif_tokenOnTo_ender(token) {
var msg = '{"message":"pif_token","port":"to_ender_c", "token":' + token + '}';
_send(msg);
}

function sendCustomPrintSOnPrint(myString) {
var msg = '{"message":"customPrintS","port":"Print_c", "myString":"' + myString.replace("\n", "\\n") + '"}';
_send(msg);
}

function sendCustomPrintIOnPrint(myInt) {
var msg = '{"message":"customPrintI","port":"Print_c", "myInt":' + myInt + '}';
_send(msg);
}

//State machine (states and regions)
this.PIFStarter_behavior = buildRegion("behavior");
this._initial_PIFStarter_behavior = buildInitialState("_initial", this.PIFStarter_behavior);
var PIFStarter_behavior_Init = buildSimpleState("Init", this.PIFStarter_behavior);
PIFStarter_behavior_Init.entry = [PIFStarter_behavior_Init_entry];
var PIFStarter_behavior_Wait = buildSimpleState("Wait", this.PIFStarter_behavior);
var t0 = new buildEmptyTransition(this._initial_PIFStarter_behavior, PIFStarter_behavior_Init);
//State machine (transitions)
var t1 = buildTransition(PIFStarter_behavior_Init, PIFStarter_behavior_Wait, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_timeout"});
t1.effect = [t1_effect];
var t2 = buildTransition(PIFStarter_behavior_Wait, PIFStarter_behavior_Init, function (s, c) {var json = JSON.parse(c); return json.port === "from_ender_s" && json.message === "pif_token"});
t2.effect = [t2_effect];
//State machine (actions on states and transitions)
function PIFStarter_behavior_Init_entry(context, message) {
sendTimer_startOnTimer(PIFStarter_period__var);
}

function t1_effect(context, message) {
var json = JSON.parse(message);
sendCustomPrintSOnPrint("Sender sends token ... ");
sendPif_tokenOnTo_ender(1);
}

function t2_effect(context, message) {
var json = JSON.parse(message);
sendCustomPrintSOnPrint(" Sender got token back \n");
}

}
//Public API for lifecycle management
PIFStarter.prototype._stop = function() {
}

//Public API for third parties
PIFStarter.prototype._init = function() {
this.PIFStarter_behavior.initialise( this._initial_PIFStarter_behavior );
var msg = this.getQueue().shift();
while(msg != null) {
this.PIFStarter_behavior.process(this._initial_PIFStarter_behavior, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

PIFStarter.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.PIFStarter_behavior.process(this._initial_PIFStarter_behavior, msg);
msg = this.getQueue().shift();
}
}
}
PIFStarter.prototype.getName = function() {
return "PIFStarter";
}


/**
 * Definition for type : PIFEnder
 **/
function PIFEnder(PIFEnder_behavior_tmp__var) {

this.ready = false;
//Attributes
this.PIFEnder_behavior_tmp__var =PIFEnder_behavior_tmp__var;//bindings
var connectors = [];
this.getConnectors = function() {
return connectors;
}

//message queue
var queue = [];
this.getQueue = function() {
return queue;
}

//callbacks for third-party listeners
//ThingML-defined functions
//Internal functions
function _send(message) {
var arrayLength = connectors.length;
for (var i = 0; i < arrayLength; i++) {
connectors[i].forward(message);
}
}

function sendPif_tokenOnTo_starter(token) {
var msg = '{"message":"pif_token","port":"to_starter_c", "token":' + token + '}';
_send(msg);
}

function sendCustomPrintSOnPrint(myString) {
var msg = '{"message":"customPrintS","port":"Print_c", "myString":"' + myString.replace("\n", "\\n") + '"}';
_send(msg);
}

function sendCustomPrintIOnPrint(myInt) {
var msg = '{"message":"customPrintI","port":"Print_c", "myInt":' + myInt + '}';
_send(msg);
}

//State machine (states and regions)
this.PIFEnder_behavior = buildRegion("behavior");
this._initial_PIFEnder_behavior = buildInitialState("_initial", this.PIFEnder_behavior);
var PIFEnder_behavior_Init = buildSimpleState("Init", this.PIFEnder_behavior);
var t0 = new buildEmptyTransition(this._initial_PIFEnder_behavior, PIFEnder_behavior_Init);
//State machine (transitions)
var t1 = buildTransition(PIFEnder_behavior_Init, PIFEnder_behavior_Init, function (s, c) {var json = JSON.parse(c); return json.port === "from_starter_s" && json.message === "pif_token"});
t1.effect = [t1_effect];
//State machine (actions on states and transitions)
function t1_effect(context, message) {
var json = JSON.parse(message);
PIFEnder_behavior_tmp__var = json.token;
sendCustomPrintSOnPrint(" ... Ender returns token ... ");
PIFEnder_behavior_tmp__var = PIFEnder_behavior_tmp__var - 1;
sendPif_tokenOnTo_starter(PIFEnder_behavior_tmp__var);
}

}
//Public API for lifecycle management
PIFEnder.prototype._stop = function() {
}

//Public API for third parties
PIFEnder.prototype._init = function() {
this.PIFEnder_behavior.initialise( this._initial_PIFEnder_behavior );
var msg = this.getQueue().shift();
while(msg != null) {
this.PIFEnder_behavior.process(this._initial_PIFEnder_behavior, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

PIFEnder.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.PIFEnder_behavior.process(this._initial_PIFEnder_behavior, msg);
msg = this.getQueue().shift();
}
}
}
PIFEnder.prototype.getName = function() {
return "PIFEnder";
}


/**
 * Definition for type : PIFIncDec
 **/
function PIFIncDec(PIFIncDec_behavior_tmp__var) {

this.ready = false;
//Attributes
this.PIFIncDec_behavior_tmp__var =PIFIncDec_behavior_tmp__var;//bindings
var connectors = [];
this.getConnectors = function() {
return connectors;
}

//message queue
var queue = [];
this.getQueue = function() {
return queue;
}

//callbacks for third-party listeners
//ThingML-defined functions
//Internal functions
function _send(message) {
var arrayLength = connectors.length;
for (var i = 0; i < arrayLength; i++) {
connectors[i].forward(message);
}
}

function sendPif_tokenOnTo_ender(token) {
var msg = '{"message":"pif_token","port":"to_ender_c", "token":' + token + '}';
_send(msg);
}

function sendPif_tokenOnTo_starter(token) {
var msg = '{"message":"pif_token","port":"to_starter_c", "token":' + token + '}';
_send(msg);
}

function sendCustomPrintSOnPrint(myString) {
var msg = '{"message":"customPrintS","port":"Print_c", "myString":"' + myString.replace("\n", "\\n") + '"}';
_send(msg);
}

function sendCustomPrintIOnPrint(myInt) {
var msg = '{"message":"customPrintI","port":"Print_c", "myInt":' + myInt + '}';
_send(msg);
}

//State machine (states and regions)
this.PIFIncDec_behavior = buildRegion("behavior");
this._initial_PIFIncDec_behavior = buildInitialState("_initial", this.PIFIncDec_behavior);
var PIFIncDec_behavior_Init = buildSimpleState("Init", this.PIFIncDec_behavior);
var t0 = new buildEmptyTransition(this._initial_PIFIncDec_behavior, PIFIncDec_behavior_Init);
//State machine (transitions)
var t1 = buildTransition(PIFIncDec_behavior_Init, PIFIncDec_behavior_Init, function (s, c) {var json = JSON.parse(c); return json.port === "from_starter_s" && json.message === "pif_token"});
t1.effect = [t1_effect];
var t2 = buildTransition(PIFIncDec_behavior_Init, PIFIncDec_behavior_Init, function (s, c) {var json = JSON.parse(c); return json.port === "from_ender_s" && json.message === "pif_token"});
t2.effect = [t2_effect];
//State machine (actions on states and transitions)
function t1_effect(context, message) {
var json = JSON.parse(message);
PIFIncDec_behavior_tmp__var = json.token;
sendCustomPrintIOnPrint(PIFIncDec_behavior_tmp__var);
PIFIncDec_behavior_tmp__var = PIFIncDec_behavior_tmp__var + 1;
sendPif_tokenOnTo_ender(PIFIncDec_behavior_tmp__var);
}

function t2_effect(context, message) {
var json = JSON.parse(message);
PIFIncDec_behavior_tmp__var = json.token;
sendCustomPrintIOnPrint(PIFIncDec_behavior_tmp__var);
PIFIncDec_behavior_tmp__var = PIFIncDec_behavior_tmp__var - 1;
sendPif_tokenOnTo_starter(PIFIncDec_behavior_tmp__var);
}

}
//Public API for lifecycle management
PIFIncDec.prototype._stop = function() {
}

//Public API for third parties
PIFIncDec.prototype._init = function() {
this.PIFIncDec_behavior.initialise( this._initial_PIFIncDec_behavior );
var msg = this.getQueue().shift();
while(msg != null) {
this.PIFIncDec_behavior.process(this._initial_PIFIncDec_behavior, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

PIFIncDec.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.PIFIncDec_behavior.process(this._initial_PIFIncDec_behavior, msg);
msg = this.getQueue().shift();
}
}
}
PIFIncDec.prototype.getName = function() {
return "PIFIncDec";
}


/**
 * Definition for type : JSPrinter
 **/
function JSPrinter() {

this.ready = false;
//Attributes
//bindings
var connectors = [];
this.getConnectors = function() {
return connectors;
}

//message queue
var queue = [];
this.getQueue = function() {
return queue;
}

//callbacks for third-party listeners
//ThingML-defined functions
//Internal functions
function _send(message) {
var arrayLength = connectors.length;
for (var i = 0; i < arrayLength; i++) {
connectors[i].forward(message);
}
}

//State machine (states and regions)
this.JSPrinter_behavior = buildRegion("behavior");
this._initial_JSPrinter_behavior = buildInitialState("_initial", this.JSPrinter_behavior);
var JSPrinter_behavior_greetings = buildSimpleState("greetings", this.JSPrinter_behavior);
var t0 = new buildEmptyTransition(this._initial_JSPrinter_behavior, JSPrinter_behavior_greetings);
//State machine (transitions)
var t1 = buildTransition(JSPrinter_behavior_greetings, null, function (s, c) {var json = JSON.parse(c); return json.port === "Print_s" && json.message === "customPrintS"});
t1.effect = [t1_effect];
var t2 = buildTransition(JSPrinter_behavior_greetings, null, function (s, c) {var json = JSON.parse(c); return json.port === "Print_s" && json.message === "customPrintI"});
t2.effect = [t2_effect];
//State machine (actions on states and transitions)
function t1_effect(context, message) {
var json = JSON.parse(message);
console.log(json.myString);
}

function t2_effect(context, message) {
var json = JSON.parse(message);
console.log(json.myInt);
}

}
//Public API for lifecycle management
JSPrinter.prototype._stop = function() {
}

//Public API for third parties
JSPrinter.prototype._init = function() {
this.JSPrinter_behavior.initialise( this._initial_JSPrinter_behavior );
var msg = this.getQueue().shift();
while(msg != null) {
this.JSPrinter_behavior.process(this._initial_JSPrinter_behavior, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

JSPrinter.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.JSPrinter_behavior.process(this._initial_JSPrinter_behavior, msg);
msg = this.getQueue().shift();
}
}
}
JSPrinter.prototype.getName = function() {
return "JSPrinter";
}


/**
 * Definition for type : TimerJS
 **/
function TimerJS() {

this.ready = false;
//Attributes
//bindings
var connectors = [];
this.getConnectors = function() {
return connectors;
}

//message queue
var queue = [];
this.getQueue = function() {
return queue;
}

//callbacks for third-party listeners
//ThingML-defined functions
function cancel() {
clearTimeout(this.timer);
}

this.cancel = function() {
cancel();}

function start(TimerJS_start_delay__var) {
this.timer = setTimeout(onTimeout,TimerJS_start_delay__var);
}

this.start = function(TimerJS_start_delay__var) {
start(TimerJS_start_delay__var);}

function onTimeout() {
sendTimer_timeoutOnTimer();
}

this.onTimeout = function() {
onTimeout();}

//Internal functions
function _send(message) {
var arrayLength = connectors.length;
for (var i = 0; i < arrayLength; i++) {
connectors[i].forward(message);
}
}

function sendTimer_timeoutOnTimer() {
var msg = '{"message":"timer_timeout","port":"timer_c"}';
_send(msg);
}

//State machine (states and regions)
this.TimerJS_SoftTimer = buildRegion("SoftTimer");
this._initial_TimerJS_SoftTimer = buildInitialState("_initial", this.TimerJS_SoftTimer);
var TimerJS_SoftTimer_default = buildSimpleState("default", this.TimerJS_SoftTimer);
var t0 = new buildEmptyTransition(this._initial_TimerJS_SoftTimer, TimerJS_SoftTimer_default);
//State machine (transitions)
var t1 = buildTransition(TimerJS_SoftTimer_default, null, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_start" && json.delay > 0});
t1.effect = [t1_effect];
var t2 = buildTransition(TimerJS_SoftTimer_default, null, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_cancel"});
t2.effect = [t2_effect];
//State machine (actions on states and transitions)
function t1_effect(context, message) {
var json = JSON.parse(message);
start(json.delay);
}

function t2_effect(context, message) {
var json = JSON.parse(message);
cancel();
}

}
//Public API for lifecycle management
TimerJS.prototype._stop = function() {
}

//Public API for third parties
TimerJS.prototype._init = function() {
this.TimerJS_SoftTimer.initialise( this._initial_TimerJS_SoftTimer );
var msg = this.getQueue().shift();
while(msg != null) {
this.TimerJS_SoftTimer.process(this._initial_TimerJS_SoftTimer, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

TimerJS.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.TimerJS_SoftTimer.process(this._initial_TimerJS_SoftTimer, msg);
msg = this.getQueue().shift();
}
}
}
TimerJS.prototype.getName = function() {
return "TimerJS";
}

process.stdin.resume();//to keep Node.js alive even when it is nothing more to do...
var JSPIF_pif4 = new PIFIncDec(0);
var JSPIF_pif2 = new PIFIncDec(0);
var JSPIF_timer = new TimerJS();
var JSPIF_pif1 = new PIFIncDec(0);
var JSPIF_starter = new PIFStarter(5000);
var JSPIF_pif6 = new PIFIncDec(0);
var JSPIF_pif5 = new PIFIncDec(0);
var JSPIF_pif3 = new PIFIncDec(0);
var JSPIF_ender = new PIFEnder(0);
var JSPIF_printer = new JSPrinter();
JSPIF_pif1.getConnectors().push(new Connector(JSPIF_pif1, JSPIF_printer, "Print_c", "Print_s"));
JSPIF_pif5.getConnectors().push(new Connector(JSPIF_pif5, JSPIF_pif6, "to_ender_c", "from_starter_s"));
JSPIF_pif4.getConnectors().push(new Connector(JSPIF_pif4, JSPIF_printer, "Print_c", "Print_s"));
JSPIF_pif3.getConnectors().push(new Connector(JSPIF_pif3, JSPIF_pif4, "to_ender_c", "from_starter_s"));
JSPIF_pif2.getConnectors().push(new Connector(JSPIF_pif2, JSPIF_printer, "Print_c", "Print_s"));
JSPIF_pif1.getConnectors().push(new Connector(JSPIF_pif1, JSPIF_starter, "to_starter_c", "from_ender_s"));
JSPIF_pif6.getConnectors().push(new Connector(JSPIF_pif6, JSPIF_ender, "to_ender_c", "from_starter_s"));
JSPIF_pif4.getConnectors().push(new Connector(JSPIF_pif4, JSPIF_pif3, "to_starter_c", "from_ender_s"));
JSPIF_pif6.getConnectors().push(new Connector(JSPIF_pif6, JSPIF_printer, "Print_c", "Print_s"));
JSPIF_starter.getConnectors().push(new Connector(JSPIF_starter, JSPIF_pif1, "to_ender_c", "from_starter_s"));
JSPIF_pif5.getConnectors().push(new Connector(JSPIF_pif5, JSPIF_printer, "Print_c", "Print_s"));
JSPIF_pif2.getConnectors().push(new Connector(JSPIF_pif2, JSPIF_pif3, "to_ender_c", "from_starter_s"));
JSPIF_starter.getConnectors().push(new Connector(JSPIF_starter, JSPIF_timer, "timer_c", "timer_s"));
JSPIF_timer.getConnectors().push(new Connector(JSPIF_timer, JSPIF_starter, "timer_c", "timer_s"));
JSPIF_pif4.getConnectors().push(new Connector(JSPIF_pif4, JSPIF_pif5, "to_ender_c", "from_starter_s"));
JSPIF_pif2.getConnectors().push(new Connector(JSPIF_pif2, JSPIF_pif1, "to_starter_c", "from_ender_s"));
JSPIF_pif3.getConnectors().push(new Connector(JSPIF_pif3, JSPIF_pif2, "to_starter_c", "from_ender_s"));
JSPIF_ender.getConnectors().push(new Connector(JSPIF_ender, JSPIF_printer, "Print_c", "Print_s"));
JSPIF_pif6.getConnectors().push(new Connector(JSPIF_pif6, JSPIF_pif5, "to_starter_c", "from_ender_s"));
JSPIF_pif5.getConnectors().push(new Connector(JSPIF_pif5, JSPIF_pif4, "to_starter_c", "from_ender_s"));
JSPIF_pif1.getConnectors().push(new Connector(JSPIF_pif1, JSPIF_pif2, "to_ender_c", "from_starter_s"));
JSPIF_ender.getConnectors().push(new Connector(JSPIF_ender, JSPIF_pif6, "to_starter_c", "from_ender_s"));
JSPIF_starter.getConnectors().push(new Connector(JSPIF_starter, JSPIF_printer, "Print_c", "Print_s"));
JSPIF_pif3.getConnectors().push(new Connector(JSPIF_pif3, JSPIF_printer, "Print_c", "Print_s"));
JSPIF_starter._init();
JSPIF_pif4._init();
JSPIF_timer._init();
JSPIF_pif2._init();
JSPIF_pif3._init();
JSPIF_printer._init();
JSPIF_pif1._init();
JSPIF_pif5._init();
JSPIF_ender._init();
JSPIF_pif6._init();
//terminate all things on SIGINT (e.g. CTRL+C)
process.on('SIGINT', function() {
JSPIF_starter._stop();
JSPIF_pif2._stop();
JSPIF_printer._stop();
JSPIF_pif5._stop();
JSPIF_pif6._stop();
JSPIF_pif3._stop();
JSPIF_timer._stop();
JSPIF_pif1._stop();
JSPIF_ender._stop();
JSPIF_pif4._stop();
});

