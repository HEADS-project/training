package org.kevoree.example;

import org.kevoree.annotation.ComponentType;
import org.kevoree.annotation.Param;
import org.kevoree.annotation.Start;
import org.kevoree.annotation.Stop;
import org.kevoree.annotation.Update;
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

    @Update
    public void update() {
        Log.info("Update: {}", greetMessage);
    }
}
