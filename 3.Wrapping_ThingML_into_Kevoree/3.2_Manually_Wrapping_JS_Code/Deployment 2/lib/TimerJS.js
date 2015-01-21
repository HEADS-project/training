// Created by leiko on 21/01/15 13:05
var StateFactory = require('./state-factory');

/**
 * Definition for type : TimerJS
 **/
function TimerJS() {

    var _this;
    this.setThis = function(__this) {
        _this = __this;
    };

    this.ready = false;
//Attributes
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
    function cancel() {
        clearTimeout(this.timer);
    }

    this.cancel = function() {
        cancel();
    };

    function start(TimerJS_start_delay__var) {
        this.timer = setTimeout(onTimeout,TimerJS_start_delay__var);
    }

    this.start = function(TimerJS_start_delay__var) {
        start(TimerJS_start_delay__var);
    };

    function onTimeout() {
        process.nextTick(sendTimer_timeoutOnTimer.bind(_this));
    }

    this.onTimeout = function() {
        onTimeout();
    };

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
//notify listeners
        var arrayLength = timerListeners.length;
        for (var i = 0; i < arrayLength; i++) {
            timerListeners[i](msg);
        }
    }

//State machine (states and regions)
    this.TimerJS_SoftTimer = StateFactory.buildRegion("SoftTimer");
    this._initial_TimerJS_SoftTimer = StateFactory.buildInitialState("_initial", this.TimerJS_SoftTimer);
    var TimerJS_SoftTimer_default = StateFactory.buildSimpleState("default", this.TimerJS_SoftTimer);
    var t0 = new StateFactory.buildEmptyTransition(this._initial_TimerJS_SoftTimer, TimerJS_SoftTimer_default);
//State machine (transitions)
    var t1 = StateFactory.buildTransition(TimerJS_SoftTimer_default, null, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_cancel"});
    t1.effect = [t1_effect];
    var t2 = StateFactory.buildTransition(TimerJS_SoftTimer_default, null, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_start" && json.delay > 0});
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
};

//Public API for third parties
TimerJS.prototype._init = function() {
    this.TimerJS_SoftTimer.initialise( this._initial_TimerJS_SoftTimer );
    var msg = this.getQueue().shift();
    while(msg != null) {
        this.TimerJS_SoftTimer.process(this._initial_TimerJS_SoftTimer, msg);
        msg = this.getQueue().shift();
    }
    this.ready = true;
};

TimerJS.prototype._receive = function(message) {//takes a JSONified message
    this.getQueue().push(message);
    if (this.ready) {
        var msg = this.getQueue().shift();
        while(msg != null) {
            this.TimerJS_SoftTimer.process(this._initial_TimerJS_SoftTimer, msg);
            msg = this.getQueue().shift();
        }
    }
};
TimerJS.prototype.receivetimer_startOntimer = function(delay) {
    this._receive('{"message":"timer_start","port":"timer_s", "delay":' + delay + '}');
};

TimerJS.prototype.receivetimer_cancelOntimer = function() {
    this._receive('{"message":"timer_cancel","port":"timer_s"}');
};

TimerJS.prototype.getName = function() {
    return "TimerJS";
};

module.exports = TimerJS;