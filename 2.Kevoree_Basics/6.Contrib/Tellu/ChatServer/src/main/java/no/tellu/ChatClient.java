package no.tellu;



import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

import org.kevoree.annotation.*;
import org.kevoree.log.Log;

@ComponentType
public class ChatClient {

	
	private ScheduledExecutorService scheduledThreadPool = Executors.newScheduledThreadPool(1);
    
	@Param(defaultValue = "Default Content")
    String chatMessage;
	int i;

    @KevoreeInject
    org.kevoree.api.Context context;

    @Output
    org.kevoree.api.Port chatServerOut;

    @Input
    public void in(Object in) {
        String msg = in+" from "+context.getInstanceName()+"@"+context.getNodeName();
        Log.info(msg);
    }

   
    @Start    
    public void start() {
        Log.info("Chatclient starting up!");

        scheduledThreadPool.scheduleAtFixedRate(new Runnable() {

			public void run() {				
	        	chatServerOut.send(chatMessage, null);
	            Log.info("Chat message no: "+i+++"sent from ChatClient: " + chatMessage);
				
			}
           
        }, 0, 5, TimeUnit.SECONDS);
    }

    @Stop
    public void stop() {
        Log.info("Bye, chat!");
        scheduledThreadPool.shutdown();
    }

    @Update
    public void update() {
        Log.info("Update: {}", chatMessage);
    }

}

