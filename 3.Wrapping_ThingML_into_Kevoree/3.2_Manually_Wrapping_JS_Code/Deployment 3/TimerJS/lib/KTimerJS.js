var TimerJS = require('./TimerJS');
var Connector = require('./Connector');
var AbstractComponent = require('kevoree-entities').AbstractComponent;

/**
 * Kevoree component
 * @type {KTimerJS}
 */
var KTimerJS = AbstractComponent.extend({
    toString: 'KTimerJS',

	//TODO: update of Kevoree attributes should be propagated to things
    /* This is an example of dictionary attribute that you can set for your entity */
    //dic_yourAttrName: {
    //  optional: true,
    //  defaultValue: false
    //},
	
	//ADDED: Reference to the wrapped things
	construct: function() {
		this.TestTimerJS_timer = null;
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
		
		//register listeners to allow wrapped things to send on Kevoree ports
		this.TestTimerJS_timer.getTimerListeners().push(this.out_TestTimerJS_timer_timer_out.bind(this));
		
		this.TestTimerJS_timer._init();
        
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
	
	out_TestTimerJS_timer_timer_out: function (msg) { /* This will be overwritten @runtime by Kevoree JS */ }
});

module.exports = KTimerJS;
