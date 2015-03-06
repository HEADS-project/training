1. Generate Java code with `HEADS / ThingML --> Plain Java` on file _java/JavaPrint.thingml.
* Build with `mvn clean package`. 
* Run example with `mvn exec:java -Dexec.mainClass=com.softwareag.research.heads.Main`.
You should see 
```
Light Actuator Start
Motion Sensor Start
Light is ON
Light is OFF
``` 
Stop the app with ctrl-C.