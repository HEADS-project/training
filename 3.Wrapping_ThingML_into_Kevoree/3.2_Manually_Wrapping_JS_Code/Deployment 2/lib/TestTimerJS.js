///COPIED FROM THINGML GENERATED CODE
var state_js = require('state.js');
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

//TODO: Could be removed if no internal connectors are defined in the ThingML configuration
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
 * Definition for type : TimerJS
 **/
function TimerJS() {

var _this;
this.setThis = function(__this) {
_this = __this;
}

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
var timerListeners = [];
this.getTimerListeners = function() {
return timerListeners;
}
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
process.nextTick(sendTimer_timeoutOnTimer.bind(_this));
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
var arrayLength = timerListeners.length;
for (var i = 0; i < arrayLength; i++) {
	timerListeners[i](msg);
}
}

//State machine (states and regions)
this.TimerJS_SoftTimer = buildRegion("SoftTimer");
this._initial_TimerJS_SoftTimer = buildInitialState("_initial", this.TimerJS_SoftTimer);
var TimerJS_SoftTimer_default = buildSimpleState("default", this.TimerJS_SoftTimer);
var t0 = new buildEmptyTransition(this._initial_TimerJS_SoftTimer, TimerJS_SoftTimer_default);
//State machine (transitions)
var t1 = buildTransition(TimerJS_SoftTimer_default, null, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_cancel"});
t1.effect = [t1_effect];
var t2 = buildTransition(TimerJS_SoftTimer_default, null, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_start" && json.delay > 0});
t2.effect = [t2_effect];
//State machine (actions on states and transitions)
function t1_effect(context, message) {
var json = JSON.parse(message);
cancel();
}

function t2_effect(context, message) {
var json = JSON.parse(message);
start(json.delay);
}

}
//Public API for lifecycle management
TimerJS.prototype._stop = function() {
this.TimerJS_SoftTimer.beginExit(this._initial_TimerJS_SoftTimer );
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
TimerJS.prototype.receivetimer_startOntimer = function(delay) {
this._receive('{"message":"timer_start","port":"timer_s", "delay":' + delay + '}');
}

TimerJS.prototype.receivetimer_cancelOntimer = function() {
this._receive('{"message":"timer_cancel","port":"timer_s"}');
}

TimerJS.prototype.getName = function() {
return "TimerJS";
}

/**
 * Definition for type : SimpleTimerClient
 **/
function SimpleTimerClient(SimpleTimerClient_t1__var, SimpleTimerClient_t2__var) {

var _this;
this.setThis = function(__this) {
_this = __this;
}

this.ready = false;
//Attributes
this.SimpleTimerClient_t1__var = SimpleTimerClient_t1__var;
this.SimpleTimerClient_t2__var = SimpleTimerClient_t2__var;
var SimpleTimerClient_Default_counter__var = 0;
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
var timerListeners = [];
this.getTimerListeners = function() {
return timerListeners;
}
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
//notify listeners
var arrayLength = timerListeners.length;
for (var i = 0; i < arrayLength; i++) {
timerListeners[i](msg);
}
}

function sendTimer_cancelOnTimer() {
var msg = '{"message":"timer_cancel","port":"timer_c"}';
_send(msg);
//notify listeners
var arrayLength = timerListeners.length;
for (var i = 0; i < arrayLength; i++) {
timerListeners[i](msg);
}
}

//State machine (states and regions)
this.SimpleTimerClient_Default = buildRegion("Default");
this._initial_SimpleTimerClient_Default = buildInitialState("_initial", this.SimpleTimerClient_Default);
var SimpleTimerClient_Default_Tick = buildSimpleState("Tick", this.SimpleTimerClient_Default);
SimpleTimerClient_Default_Tick.entry = [SimpleTimerClient_Default_Tick_entry];
var t0 = new buildEmptyTransition(this._initial_SimpleTimerClient_Default, SimpleTimerClient_Default_Tick);
//State machine (transitions)
var t1 = buildTransition(SimpleTimerClient_Default_Tick, SimpleTimerClient_Default_Tick, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_timeout" && SimpleTimerClient_Default_counter__var % 2 == 0});
t1.effect = [t1_effect];
var t2 = buildTransition(SimpleTimerClient_Default_Tick, null, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_timeout" && SimpleTimerClient_Default_counter__var % 2 == 1});
t2.effect = [t2_effect];
//State machine (actions on states and transitions)
function SimpleTimerClient_Default_Tick_entry(context, message) {
console.log("sending timer_start\n");
process.nextTick(sendTimer_startOnTimer.bind(_this, _this.SimpleTimerClient_t1__var));
console.log("sending timer_cancel\n");
process.nextTick(sendTimer_cancelOnTimer.bind(_this));
console.log("sending timer_start\n");
process.nextTick(sendTimer_startOnTimer.bind(_this, _this.SimpleTimerClient_t1__var));
}

function t1_effect(context, message) {
var json = JSON.parse(message);
console.log("tick\n");
console.log(SimpleTimerClient_Default_counter__var);
console.log("\n");
SimpleTimerClient_Default_counter__var = SimpleTimerClient_Default_counter__var + 1;
}

function t2_effect(context, message) {
var json = JSON.parse(message);
console.log("tock\n");
console.log(SimpleTimerClient_Default_counter__var);
console.log("\n");
SimpleTimerClient_Default_counter__var = SimpleTimerClient_Default_counter__var + 1;
console.log("sending timer_start\n");
process.nextTick(sendTimer_startOnTimer.bind(_this, _this.SimpleTimerClient_t2__var));
console.log("sending timer_cancel\n");
process.nextTick(sendTimer_cancelOnTimer.bind(_this));
console.log("sending timer_start\n");
process.nextTick(sendTimer_startOnTimer.bind(_this, _this.SimpleTimerClient_t2__var));
}

}
//Public API for lifecycle management
SimpleTimerClient.prototype._stop = function() {
this.SimpleTimerClient_Default.beginExit(this._initial_SimpleTimerClient_Default );
}

//Public API for third parties
SimpleTimerClient.prototype._init = function() {
this.SimpleTimerClient_Default.initialise( this._initial_SimpleTimerClient_Default );
var msg = this.getQueue().shift();
while(msg != null) {
this.SimpleTimerClient_Default.process(this._initial_SimpleTimerClient_Default, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

SimpleTimerClient.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.SimpleTimerClient_Default.process(this._initial_SimpleTimerClient_Default, msg);
msg = this.getQueue().shift();
}
}
}
SimpleTimerClient.prototype.receivetimer_timeoutOntimer = function() {
//TODO: should be called from Kevoree input port
this._receive('{"message":"timer_timeout","port":"timer_s"}');//BUG: _c should be _s
}

SimpleTimerClient.prototype.getName = function() {
return "SimpleTimerClient";
}

///END COPIED



// if you have already created your own Component extending AbstractComponent
// you can replace AbstractComponent here and use your own
// ex: var MyComp = require('./path/to/MyComp')
// the only thing needed is that the top level component extends AbstractComponent :)
var AbstractComponent = require('kevoree-entities').AbstractComponent;

/**
 * Kevoree component
 * @type {TestTimerJS}
 */
var TestTimerJS = AbstractComponent.extend({
    toString: 'TestTimerJS',

	//TODO: update of Kevoree attributes should be propagated to things
    /* This is an example of dictionary attribute that you can set for your entity */
    //dic_yourAttrName: {
    //  optional: true,
    //  defaultValue: false
    //},
	
	//ADDED: Reference to the wrapped things
	construct: function() {
		var TestTimerJS_client = null;
		var TestTimerJS_timer = null;
	},

    /**
     * this method will be called by the Kevoree platform when your component has to start
     * @param {Function} done
     */
    start: function (done) {
        this._super(function () {
		this.log.debug(this.toString(), 'STARTING...');
		//ADDED: Main (instantiation of things and connectors) from the generated code
		//TODO: instances should be accessed with this.X
		this.TestTimerJS_timer = new TimerJS();
		this.TestTimerJS_timer.setThis(this.TestTimerJS_timer);
		this.TestTimerJS_client = new SimpleTimerClient(1000, 5000);
		this.TestTimerJS_client.setThis(this.TestTimerJS_client);
		/*TestTimerJS_client.getConnectors().push(new Connector(TestTimerJS_client, TestTimerJS_timer, "timer_c", "timer_s"));
		TestTimerJS_timer.getConnectors().push(new Connector(TestTimerJS_timer, TestTimerJS_client, "timer_c", "timer_s"));*/
		
		//register listeners to allow wrapped things to send on Kevoree ports
		this.TestTimerJS_timer.getTimerListeners().push(this.out_TestTimerJS_timer_timer_out.bind(this));
		this.TestTimerJS_client.getTimerListeners().push(this.out_TestTimerJS_client_timer_out.bind(this));
		
		this.TestTimerJS_timer._init();
		this.TestTimerJS_client._init();
        
		this.log.debug(this.toString(), 'STARTED!');
            done();
        }.bind(this));
    },

    /**
     * this method will be called by the Kevoree platform when your component has to stop
     * @param {Function} done
     */
    stop: function (done) {
        this._super(function () {
			//ADDED: On SIG-INT hook
            this.log.debug(this.toString(), 'STOPPING!');
			TestTimerJS_client._stop();
			TestTimerJS_timer._stop();
            this.log.debug(this.toString(), 'STOPPED!');
            done();
        }.bind(this));
    },
	
	//TODO: Generate ports that are not connected
	in_TestTimerJS_timer_timer_in: function (msg) {
		console.log(this.getName() + '>' + msg);
		var json = JSON.parse(msg);
		if (json.port === "timer_c") {
			if (json.message === "timer_start") {
				this.TestTimerJS_timer.receivetimer_startOntimer(json.delay);
			} else if (json.message === "timer_cancel") {
				this.TestTimerJS_timer.receivetimer_cancelOntimer();
			}
		} //else another port        
    },
	
	in_TestTimerJS_client_timer_in: function (msg) {
        console.log(this.getName() + '>' + msg);
		var json = JSON.parse(msg);
		if (json.port === "timer_c") {
			if (json.message === "timer_timeout") {
				this.TestTimerJS_client.receivetimer_timeoutOntimer();
			}
		} //else another port        
    },
	
	out_TestTimerJS_timer_timer_out: function (msg) { /* This will be overwritten @runtime by Kevoree JS */ },
	
	out_TestTimerJS_client_timer_out: function (msg) { /* This will be overwritten @runtime by Kevoree JS */ }
});

module.exports = TestTimerJS;
