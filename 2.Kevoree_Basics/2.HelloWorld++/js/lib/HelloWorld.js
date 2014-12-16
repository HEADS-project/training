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
    dic_greetMessage: {
        optional: true,
        defaultValue: 'Hello, world!'
    },

    /**
     * this method will be called by the Kevoree platform when your component has to start
     * @param {Function} done   call this when you are done starting your component
     */
    start: function (done) {
        this._super(function () {
            var greetMessage = this.dictionary.getValue('greetMessage');
            this.log.info(this.toString(), greetMessage);
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
            done();
        }.bind(this));
    }
});

module.exports = HelloWorld;
