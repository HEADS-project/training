// if you have already created your own Component extending AbstractComponent
// you can replace AbstractComponent here and use your own
// ex: var MyComp = require('./path/to/MyComp')
// the only thing needed is that the top level component extends AbstractComponent :)
var AbstractComponent = require('kevoree-entities').AbstractComponent;
var mraa = require('mraa');

/**
 * Kevoree component
 * @type {BlinkLED}
 */
var BlinkLED = AbstractComponent.extend({
    toString: 'BlinkLED',
	
	//Attributes to blink the LED
	myLed: null,
	ledState: true,
	timer: null,
	
	periodicActivity: function() {
		console.log("periodicAtivity");
		setInterval(function(){
			if (this.myLed != null) {
				console.log("LED is " + this.ledState);
				this.myLed.write(this.ledState?1:0);
				this.ledState = !this.ledState;
			} else {
				console.log("LED not initialized...");
			}
		}.bind(this), 1000);
	},

    /* This is an example of dictionary attribute that you can set for your entity */
    //dic_yourAttrName: {
    //  optional: true,
    //  defaultValue: false
    //},

    /**
     * this method will be called by the Kevoree platform when your component has to start
     * @param {Function} done
     */
    start: function (done) {
        this._super(function () {
            this.log.debug(this.toString(), 'STARTING...');
			this.myLed = new mraa.Gpio(13);
			this.myLed.dir(mraa.DIR_OUT);
			this.ledState = true;
			this.myLed.write(1);
			this.myLed.write(0);
			this.myLed.write(1);
			this.log.debug(this.toString(), 'STARTED!');
			console.log("Calling periodicActivity");
			var f = this.periodicActivity.bind(this);
			f();
            done();
        }.bind(this));
    },

    /**
     * this method will be called by the Kevoree platform when your component has to stop
     * @param {Function} done
     */
    stop: function (done) {
        this._super(function () {
            this.log.debug(this.toString(), 'STOPPING...');
			if (this.timer != null) {
				clearInterval(this.timer);
			}
			if (this.myLed != null) {
				this.myLed.write(0);
			}
			this.log.debug(this.toString(), 'STOPPED...');
            done();
        }.bind(this));
    }
});

module.exports = BlinkLED;
