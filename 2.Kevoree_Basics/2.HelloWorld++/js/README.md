> :warning: This tutorial is the sequel of [1.HelloWorld - JavaScript](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/1.HelloWorld/js), be sure to do the previous tutorial first.

#### Purpose of the HelloWorld++ component
Now we want to extend the previous [HelloWorld component](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/1.HelloWorld/js)
so that you can dynamically change the content of the displayed "Hello, world!" message.  
For that, you will use the Kevoree concept: **dictionary attribute**

#### Add a dictionary attribute
In order to give some parameters to a component Kevoree provides a concept called
**dictionary attributes**.  
Dictionary attributes can be added to a component in Kevoree JS by using the naming-convention **dic_**

```js
var HelloWorld = AbstractComponent.extend({
    toString: 'HelloWorld',

    /**
     * Dictionary attribute named "greetMessage"
     */
    dic_greetMessage: null,

    // ....
});
```
By doing so, you will be able to set the value of "greetMessage" using the KevScript `kevs/main.kevs`

```txt
// the node that hosts your component
add node0 : JavascriptNode

// create and add your HelloWorld component (named "myComp") in "node0"
add node0.myComp : org.kevoree.example.HelloWorld

// change the value of "greetMessage" attribute
set node0.myComp.greetMessage = "Hello, HEADS!"

// set the node log level to 'info' so that we do not get the debug logs
set node0.logLevel = 'info'
```
So now you know that the `set node0.logLevel = 'info'` is modifying the value of the `logLevel` attribute of the JavascriptNode instance.
Just like you changed the value of "greetMessage" to "Hello, HEADS!" in your HelloWorld component instance.

#### Retrieve a dictionary attribute value
Now that you have defined a new dictionary attribute named `greetMessage` you will want to use it within your component code.
To retrieve an attribute value at runtime, Kevoree JS provides a class called `Dictionary` that you can use in your component with `this.dictionary`  (just like you used `this.log.info(...)`)

```js
start: function (done) {
    this._super(function () {
        // retrieve the value of attribute "greetMessage"
        var greetMessage = this.dictionary.getValue('greetMessage');
        // display the attribute value
        this.log.info(this.toString(), greetMessage);
        done();
    }.bind(this));
}
```

The **Dictionary** API provides 3 helper methods to retrieve values from the dictionary
depending on the type you are expecting.

#### Strings
```js
// if "myAttr" value is not set, it will return "foo"
var value = this.dictionary.getString('myAttr', 'foo');
```

##### Number
```js
// if "myAttr" value is not set, it will return 42
var value = this.dictionary.getNumber('myAttr', 42);
```

##### Boolean
```js
// if "myAttr" value is not set, it will return false
var value = this.dictionary.getBoolean('myAttr', false);
```

The purpose of those helper is to give a one-liner to attribute null-checking and type-checking

```js
// using getValue() you have to do the checks yourself
var value = this.dictionary.getValue('attrName');
if (value == null) {
    // no value set
    value = 42; // defaulting to 42
} else {
    // value is set
    if (isNaN(Number(value))) {
        // value is Not a Number
        value = 42; // defaulting to 42
    } else {
        // value is a number
        value = Number(value);
    }
}

// now use "value" ...
```

All this could have been made by using

```js
var value = this.dictionary.getNumber('attrName', 42);
```


#### Run the HelloWorld component
Ok, let's run the project

```sh
╭─leiko@kevtop /tmp/HelloWorld
╰─➤  grunt kevoree
# ... many logs ...
13:19:11  INFO   HelloWorld       Hello, HEADS!
>> Bootstrap model deployed successfully
```

You can see in the logs that the log output is using the value set within the KevScript file for "greetMessage".

#### Improve the "greetMessage" attribute
> What if I want to set a default value to my attribute without using KevScript ?

For starters we have set the value of `dic_greetMessage` to `null` because it was enough, but you can be more descriptive about your attribute too.  
You can specify 4 different properties for your dictionary attributes:  
  - **optional**
    - Whether or not your attribute is mandatory (eg. if `true` a value **has to** be set,
      so if there is no `defaultValue` set and no value set in your KevScript,
      the interpreter will throw an error)
  - **defaultValue**
    - Your attribute default value
  - **datatype**
    - Your attribute value type (if `defaultValue` is set, KevoreeJS will try to guess this type so `datatype` can be optional.
      But if you want your attribute value to be a `float` or a `long`, or anything that Javascript does not handle natively,
      then you will have to specify it explicitly)
  - **fragmentDependant**
    - This property is only used by **Groups** and **Channels** (it makes no sense to set that for Components or Nodes)  
      Whether or not your attribute is fragment dependent, if `true` then there will be a dictionary attribute with that name for each relation between group and channels or channels and nodes.  

Ok, let's be more descriptive about `greetMessage`

```js
dic_greetMessage: {
    optional: true, // this is not necessery as "optional: true" is the default
    defaultValue: 'Hello, world!'
}
```

By doing so, you can remove the `set node0.myComp.greetMessage = 'Hello, HEADS!'` from the KevScript, and it will, by default, output "Hello, world!" on start-up.
