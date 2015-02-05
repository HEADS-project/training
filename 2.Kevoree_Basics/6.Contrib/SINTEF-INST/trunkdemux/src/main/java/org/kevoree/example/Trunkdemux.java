package org.kevoree.example;

import org.kevoree.annotation.*;
import org.kevoree.api.Port;
import org.kevoree.log.Log;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

@ComponentType
public class Trunkdemux {

    @Output
    private Port out1;

    @Output
    private Port out2;

    @Output
    private Port out3;

    @Input
    public void muxin(Object msg){
	Log.info("muxin got <" + msg + ">");
    }

    @Start
    public void start() {
	Log.info("Trunkdemux started");
    }

    @Stop
    public void stop() {
	Log.info("Trunkdemux end");
    }

}
