// Created by leiko on 21/01/15 13:03
var StateFactory = require('./state-factory');

/**
 * Definition for type : SimpleTimerClient
 **/
function SimpleTimerClient(SimpleTimerClient_t1__var, SimpleTimerClient_t2__var) {

    var _this;
    this.setThis = function(__this) {
        _this = __this;
    };

    this.ready = false;
//Attributes
    this.SimpleTimerClient_t1__var = SimpleTimerClient_t1__var;
    this.SimpleTimerClient_t2__var = SimpleTimerClient_t2__var;
    var SimpleTimerClient_Default_counter__var = 0;
//bindings
    var connectors = [];
    this.getConnectors = function() {
        return connectors;
    };

//message queue
    var queue = [];
    this.getQueue = function() {
        return queue;
    };

//callbacks for third-party listeners
    var timerListeners = [];
    this.getTimerListeners = function() {
        return timerListeners;
    };
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
    this.SimpleTimerClient_Default = StateFactory.buildRegion("Default");
    this._initial_SimpleTimerClient_Default = StateFactory.buildInitialState("_initial", this.SimpleTimerClient_Default);
    var SimpleTimerClient_Default_Tick = StateFactory.buildSimpleState("Tick", this.SimpleTimerClient_Default);
    SimpleTimerClient_Default_Tick.entry = [SimpleTimerClient_Default_Tick_entry];
    var t0 = new StateFactory.buildEmptyTransition(this._initial_SimpleTimerClient_Default, SimpleTimerClient_Default_Tick);
//State machine (transitions)
    var t1 = StateFactory.buildTransition(SimpleTimerClient_Default_Tick, SimpleTimerClient_Default_Tick, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_timeout" && SimpleTimerClient_Default_counter__var % 2 == 0});
    t1.effect = [t1_effect];
    var t2 = StateFactory.buildTransition(SimpleTimerClient_Default_Tick, null, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_timeout" && SimpleTimerClient_Default_counter__var % 2 == 1});
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
};

//Public API for third parties
SimpleTimerClient.prototype._init = function() {
    this.SimpleTimerClient_Default.initialise( this._initial_SimpleTimerClient_Default );
    var msg = this.getQueue().shift();
    while(msg != null) {
        this.SimpleTimerClient_Default.process(this._initial_SimpleTimerClient_Default, msg);
        msg = this.getQueue().shift();
    }
    this.ready = true;
};

SimpleTimerClient.prototype._receive = function(message) {//takes a JSONified message
    this.getQueue().push(message);
    if (this.ready) {
        var msg = this.getQueue().shift();
        while(msg != null) {
            this.SimpleTimerClient_Default.process(this._initial_SimpleTimerClient_Default, msg);
            msg = this.getQueue().shift();
        }
    }
};
SimpleTimerClient.prototype.receivetimer_timeoutOntimer = function() {
    this._receive('{"message":"timer_timeout","port":"timer_s"}');
};

SimpleTimerClient.prototype.getName = function() {
    return "SimpleTimerClient";
};

module.exports = SimpleTimerClient;