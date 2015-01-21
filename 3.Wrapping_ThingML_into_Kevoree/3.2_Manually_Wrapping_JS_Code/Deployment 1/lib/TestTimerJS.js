var SimpleTimerClient = require('./SimpleTimerClient');
var TimerJS = require('./TimerJS');
var Connector = require('./Connector');
var AbstractComponent = require('kevoree-entities').AbstractComponent;

/**
 * Kevoree component
 * @type {TestTimerJS}
 */
var TestTimerJS = AbstractComponent.extend({
    toString: 'TestTimerJS',

    //ADDED: Reference to the wrapped things
    construct: function() {
        this.timerClient = null;
        this.timerTimer = null;
    },

    /**
     * this method will be called by the Kevoree platform when your component has to start
     * @param {Function} done
     */
    start: function (done) {
        this._super(function () {
            this.log.debug(this.toString(), 'STARTING...');
            //ADDED: Main (instantiation of things and connectors) from the generated code
            this.timerClient = new SimpleTimerClient(1000, 5000);
            this.timerClient.setThis(this.timerClient);
            this.timerTimer = new TimerJS();
            this.timerTimer.setThis(this.timerTimer);
            this.timerClient.getConnectors().push(new Connector(this.timerClient, this.timerTimer, "timer_c", "timer_s"));
            this.timerTimer.getConnectors().push(new Connector(this.timerTimer, this.timerClient, "timer_c", "timer_s"));
            this.timerClient._init();
            this.timerTimer._init();
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
            this.timerClient._stop();
            this.timerTimer._stop();
            this.log.debug(this.toString(), 'STOPPED!');
            done();
        }.bind(this));
    }
});

module.exports = TestTimerJS;
