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