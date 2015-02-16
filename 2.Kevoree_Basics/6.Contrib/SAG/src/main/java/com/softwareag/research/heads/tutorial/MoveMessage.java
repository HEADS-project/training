/**
 * 
 */
package com.softwareag.research.heads.tutorial;

import org.kevoree.annotation.ComponentType;
import org.kevoree.annotation.Input;
import org.kevoree.annotation.KevoreeInject;
import org.kevoree.annotation.Output;
import org.kevoree.annotation.Param;
import org.kevoree.annotation.Start;
import org.kevoree.annotation.Stop;
import org.kevoree.annotation.Update;
import org.kevoree.api.Context;
import org.kevoree.api.Port;
import org.kevoree.log.Log;

/**
 *
 */
@ComponentType
public class MoveMessage {

	@KevoreeInject
    private Context context;

	@Param(defaultValue = "0")
	private String nodeId;

	private String text;
	
	@Output
	private Port outQueue;
	
	@Input
	public void inQueue(Object message){
		if (message instanceof String) {
			text = (String) message;
		} else if (message == null){
			text = "null";
		} else {
			text = message.toString();
		}
		Log.info("Got '" + text + "'");
		outQueue.send(text + nodeId, null);
	}
	
	@Start
	public void start() {
		Log.info("Start with node Id " + nodeId + ", " + context.getInstanceName() + ", " + context.getNodeName());
		outQueue.send(nodeId, null);
	}

	@Update
	public void update() {
		Log.info("Update: {}", nodeId);
		outQueue.send(nodeId, null);
	}

	@Stop
	public void stop() {
		Log.info("Stop node " + nodeId.replace("Hello", "Bye"));
	}

}
