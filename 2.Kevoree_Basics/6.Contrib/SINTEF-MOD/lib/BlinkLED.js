var AbstractComponent = require('kevoree-entities').AbstractComponent;
var mraa = require('mraa');

/**
 * Kevoree component
 * @type {BlinkLED}
 */
var BlinkLED = AbstractComponent.extend({
    toString: 'BlinkLED',
	
	periodicActivity: function() {
		this.timer = setInterval(function(){
			if (this.myLed != null) {
				console.log("LED is " + this.ledState);
				this.myLed.write(this.ledState?1:0);
				this.ledState = !this.ledState;
			} else {
				console.log("LED not initialized...");
			}
		}.bind(this), 1000);
	},

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
		this.periodicActivity();
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
