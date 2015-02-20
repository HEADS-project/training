package org.kevoree.example;

import org.kevoree.annotation.*;
import org.kevoree.api.Port;
import org.kevoree.log.Log;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

@ComponentType
public class Trunkmux {

    @Input
    public void in1(Object msg) {
		Log.info("in1 got <" + msg + ">");
		muxout.send("#1", null);
		muxout.send(""+msg, null);
    }

    @Input
    public void in2(Object msg){
		Log.info("in2 got <" + msg + ">");
		muxout.send("#2", null);
		muxout.send(""+msg, null);
    }

    @Input
    public void in3(Object msg){
		Log.info("in3 got <" + msg + ">");
		muxout.send("#3", null);
		muxout.send(""+msg, null);
    }

    @Output
    private Port muxout;

    @Start
    public void start() {
		Log.info("Trunkmux started");
    }

    @Stop
    public void stop() {
        Log.info("Trunkmux end");
    }

}
