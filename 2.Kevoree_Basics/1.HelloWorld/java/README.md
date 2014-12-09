#### First step
In order to develop Kevoree Java components you will need [Maven](http://maven.apache.org/download.cgi)  

#### Purpose of the HelloWorld component
The `HelloWorld` component has a basic behavior to help users understand the concepts and code/project structures of Kevoree Java.

**Component start:** supposed to say "Hello, world!"  
**Component stop:** supposed to say "Bye, world!"

This behavior is translated in a Kevoree component with this code:  
```java
package org.kevoree.example;

import org.kevoree.annotation.ComponentType;
import org.kevoree.annotation.Start;
import org.kevoree.annotation.Stop;
import org.kevoree.log.Log;

@ComponentType
public class HelloWorld {

    @Start
    public void start() {
        Log.info("Hello, world!");
    }

    @Stop
    public void stop() {
        Log.info("Bye, world!");
    }
}
```

#### How to compile the project
```sh
mvn install
```
This command will compile your Java sources to `target/`

#### How to run the project
```sh
mvn kev:run
```
This command starts a new Kevoree Java Runtime.  
By default, it will use the KevScript `src/main/kevs/main.kevs`.  
If you have a look at that KevScript file, you can see that it defines a Kevoree model using your own component "HelloWorld":
```txt
// the node that hosts your component
add node0 : JavaNode

// create and add your HelloWorld component (named "myComp") in "node0"
add node0.myComp : org.kevoree.example.HelloWorld
```

Output of the `mvn kev:run` command:
```txt
╭─leiko@kevtop /tmp/HelloWorld
╰─➤  mvn kev:run
# ... many logs ...
00:00 INFO: Hello, world!
00:00 INFO: JavaNode Update completed in 15 ms
00:00 INFO: End deploy result=true-13
00:00 INFO: Bootstrap completed
```

If you can see **"Bootstrap completed"** then you have successfully started a new Kevoree Java runtime using your `src/main/kevs/main.kevs` model.

#### Understand the HelloWorld component
Kevoree Java is using annotations to let you specify what's what in your code.  
When Kevoree will have to **start** your component, it will call the method annotated with `@Start`
```java
@Start
public void start() {
    Log.info("Hello, world!");
}
```
When Kevoree will have to **stop** your component, it will call the method annotated with `@Stop`
```java
@Stop
public void stop() {
    Log.info("Bye, world!");
}
```

Kevoree Java knows several other `annotations` but they will be explained in a later tutorial.

To access Kevoree Logger, you just have to use:
```java
// import org.kevoree.log.Log;
Log.info("Hello, world!");
```

#### How to stop the runtime
In order to gracefully stop your Kevoree Java runtime you just have to do a `Ctrl-c`. This action will trigger a stopping adaptation in the Kevoree Java core which will ask for every components to stop, and then exit.

```txt
00:00 INFO: Bootstrap completed
^C06:01 INFO: Stopping Kevoree
06:01 INFO: Stopping /nodes[node0]/components[myComp]
06:01 INFO: Bye, world!
06:01 INFO: Stopping node type of node0
06:01 INFO: Kevoree core stopped
06:01 INFO: Stopped.
```
