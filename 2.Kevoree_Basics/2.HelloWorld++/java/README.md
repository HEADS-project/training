> :warning: This tutorial is the sequel of [1.HelloWorld - Java](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/1.HelloWorld/java), be sure to do the previous tutorial first.

#### Purpose of the HelloWorld++ component
Now we want to extend the previous [HelloWorld component](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/1.HelloWorld/java)
so that you can dynamically change the content of the displayed "Hello, world!" message.  
For that, you will use the Kevoree concept: **dictionary attribute**

#### Add a dictionary attribute
In order to give some parameters to a component Kevoree provides a concept called
**dictionary attributes**.  
Dictionary attributes can be added to a component in Kevoree Java by using the annotation **@Param**

```java
package org.kevoree.example;

import org.kevoree.annotation.*;

@ComponentType
public class HelloWorld {

    @Param
    private String greetMessage;

    // ...
}

```
By doing so, you will be able to set the value of "greetMessage" using the KevScript `src/main/kevs/main.kevs`

```txt
// the node that hosts your component
add node0 : JavaNode

// create and add your HelloWorld component (named "myComp") in "node0"
add node0.myComp : org.kevoree.example.HelloWorld

// set the content of the dictionary attribute 'greetMessage' to "Hello, HEADS!"
set node0.myComp.greetMessage = 'Hello, HEADS!'
```

#### Retrieve a dictionary attribute value
Now that you have defined a new dictionary attribute named `greetMessage` you will want to use it within your component code.
To retrieve an attribute value at runtime in Kevoree Java you just have to use the reference of your annotated field

```java
@Param
private String greetMessage;

@Start
public void start() {
    Log.info(greetMessage);
}
```

#### Run the HelloWorld component
In order to run the project, first you have to compile it

```sh
mvn install
```

Ok, let's run the project

```sh
mvn kev:run

```

You can see in the logs that the log output is using the value set within the KevScript file for "greetMessage".

```sh
╭─leiko@kevtop /tmp/HelloWorld
╰─➤  mvn kev:run
# ... many logs ...
00:00 INFO: Hello, HEADS!
00:00 INFO: JavaNode Update completed in 21 ms
00:00 INFO: End deploy result=true-18
00:00 INFO: Bootstrap completed
```

#### Improve the "greetMessage" attribute
> What if I want to set a default value to my attribute without using KevScript ?

For starters we have set the value of `greetMessage` to `null` because it was enough, but you can be more descriptive about your attribute too.  
You can specify 3 different properties in the `@Param(...)` annotation for your dictionary attributes:  
  - **optional**
    - Whether or not your attribute is mandatory (eg. if `true` a value **has to** be set,
      so if there is no `defaultValue` set and no value set in your KevScript,
      the interpreter will throw an error)
  - **defaultValue**
    - Your attribute default value
  - **fragmentDependant**
    - This property is only used by **Groups** and **Channels** (it makes no sense to set that for Components or Nodes)  
      Whether or not your attribute is fragment dependent, if `true` then there will be a dictionary attribute with that name for each relation between group and channels or channels and nodes.  

Ok, let's be more descriptive about `greetMessage`

```java
@Param(defaultValue = "Hello, world!")
private String greetMessage;
```

By doing so, you can remove the `set node0.myComp.greetMessage = 'Hello, HEADS!'` from the KevScript, and it will, by default, output "Hello, world!" on start-up.
