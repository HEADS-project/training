var AbstractComponent = require('kevoree-entities').AbstractComponent;

/**
* Kevoree component
* @type {HelloWorld}
*/
var HelloWorld = AbstractComponent.extend({
    toString: 'HelloWorld',

    /**
     * Dictionary attribute named "greetMessage"
     */
    dic_greetMessage: { defaultValue: 'Hello, world!' },

    /**
     * this method will be called by the Kevoree platform when your component has to start
     * @param {Function} done   call this when you are done starting your component
     */
    start: function (done) {
        this._super(function () {
            var greetMessage = this.dictionary.getValue('greetMessage');
            this.log.info(this.toString(), greetMessage);

            this.id = setInterval(function () {
                // send the greetMessage every 5 seconds
                this.out_hello(this.dictionary.getValue('greetMessage'));
            }.bind(this), 5000);

            done();
        }.bind(this));
    },

    /**
     * this method will be called by the Kevoree platform when your component has to stop
     * @param {Function} done   call this when you are done stopping your component
     */
    stop: function (done) {
        this._super(function () {
            this.log.info(this.toString(), 'Bye, world!');
            clearInterval(this.id);
            done();
        }.bind(this));
    },

    update: function (done) {
        // retrieve the new attribute value
        var greetMessage = this.dictionary.getString('greetMessage');
        // display the value in the logs
        this.log.info(this.toString(), 'Update: '+greetMessage);
        done();
    },

    /**
     * Output port declaration - "hello"
     * @param {String} msg    Greeting message to send to others
     */
    out_hello: function (msg) { /* This will be overwritten @runtime by Kevoree JS */ }
});

module.exports = HelloWorld;
