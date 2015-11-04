var AbstractComponent = require('kevoree-entities').AbstractComponent;

/**
 * Kevoree component
 * @type {HelloWorld}
 */
var HelloWorld = AbstractComponent.extend({
    toString: 'HelloWorld',
            
    /* This is an example of dictionary attribute that you can set for your entity */
    dic_yourAttrName: {
        optional: false,
        defaultValue: 'aDefaultValue',
    },

    /**
     * this method will be called by the Kevoree platform when your component has to start
     * @param {Function} done
     */
    start: function (done) {
        this.log.debug(this.toString(), 'START');
        done();
    },

    /**
     * this method will be called by the Kevoree platform when your component has to stop
     * @param {Function} done
     */
    stop: function (done) {
        this.log.debug(this.toString(), 'STOP');
        done();
    }
    
});

module.exports = HelloWorld;
