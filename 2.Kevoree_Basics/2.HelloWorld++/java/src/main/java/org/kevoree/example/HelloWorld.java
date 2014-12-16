package org.kevoree.example;

import org.kevoree.annotation.*;
import org.kevoree.log.Log;

@ComponentType
public class HelloWorld {

    @Param(defaultValue = "Hello, world!")
    private String greetMessage;

    @Start
    public void start() {
        Log.info(greetMessage);
    }

    @Stop
    public void stop() {
        Log.info("Bye, world!");
    }
}
