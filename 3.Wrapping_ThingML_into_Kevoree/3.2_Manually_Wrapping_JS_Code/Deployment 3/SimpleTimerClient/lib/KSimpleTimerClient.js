var SimpleTimerClient = require('./SimpleTimerClient');
var AbstractComponent = require('kevoree-entities').AbstractComponent;

/**
 * Kevoree component
 * @type {KSimpleTimerClient}
 */
var KSimpleTimerClient = AbstractComponent.extend({
	toString: 'KSimpleTimerClient',

	//ADDED: Reference to the wrapped things
	construct: function() {
		this.timer = null;
	},

	/**
	 * this method will be called by the Kevoree platform when your component has to start
	 * @param {Function} done
	 */
	start: function (done) {
		this._super(function () {
			//ADDED: Main (instantiation of things and connectors) from the generated code
			//TODO: instances should be accessed with this.X
			this.timer = new SimpleTimerClient(1000, 5000);
			this.timer.setThis(this.timer);

			//register listeners to allow wrapped things to send on Kevoree ports
			this.timer.getTimerListeners().push(this.out_TestTimerJS_client_timer_out.bind(this));

			this.timer._init();
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
			this.timer._stop();
			done();
		}.bind(this));
	},

	//TODO: Generate ports that are not connected

	in_TestTimerJS_client_timer_in: function (msg) {
		console.log(this.getName() + '>' + msg);
		var json = JSON.parse(msg);
		if (json.port === "timer_c") {
			if (json.message === "timer_timeout") {
				this.timer.receivetimer_timeoutOntimer();
			}
		} //else another port
	},

	out_TestTimerJS_client_timer_out: function (msg) { /* This will be overwritten @runtime by Kevoree JS */ }
});

module.exports = KSimpleTimerClient;
