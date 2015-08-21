Complex Event Processing
===
Building...

> **Last updated:** August 15th 2015

# Tutorial - A heating control system

To describe all the feature avaible on the end of august, we are going to take an example: an heating control system.

## Running example
Marc supervises the electric consumption of a building aiming at reducing the electric consumption. His first step to achieve this goal is to implement alerts when heating is on in a room while the window is open.

To be accepted by the inhabitants of the building, the alert system should be flexible enough. For example, an alert should not be triggered as soon as the window is opened while the heating is on, to allow inhabitants to turn the heating off on their own shorty after, without a reminder, which could be perceived negatively. Also, as the building offers limited automation (windows cannot be automatically opened/closed and heating cannot be automatically turned on/off), Marc wants to be able to detect the presence of a person in a room using the available sensors (light, temperature, humidity and a sensor detecting whether heating is on or off), which do not include a motion sensor. This way, alerts can be triggered when the person is in the room so that the person can close the window or turn off the heating.

As Marc is not allowed to buy extra sensors, he should rely on the sensors available in each room, in addition to a global temperature sensor installed on the roof, to implement his alert system. The final system is depicted in the following figure.

**TODO: add image**

On the figure, all the blue elements are virtual sensors whereas the other are physical sensors, except the two hands in the bottom. These elements represent the alert system. The physical sensors send the value regularly. The virtual sensor are micro-controllers which receive values from other sensors, physical or virtual, and apply the rules defined by an user. On the center, the virtual sensor is a micro-controller which turn on the alert system, shown by the hand with a green card, or turn off, shown by the hand with a red card.

On the left of the figure, there is an indoor temperature sensor, a humidity sensor and a light sensor. All these sensors send a value to a micro-controller, shown by the person with a question mark on the figure. This device behaves as a person sensor : based on the values send by the three sensors, it can compute a boolean which is true when a person is in the room, false otherwise. To compute these values, it applies on the last values from each sensors an algorithm to get a temporary values. After, it analyzes the evolution of this value during a time windows. And, for example, if the mean of the temporary values are greater than a threshold during 30s, so the sensor sends a true boolean, which mean that a person is in the piece.

On the top of the figure, we have the heating sensor which send regularly its values, without any modification. The value is just a boolean which is true when the heating is on, false otherwise.

On the right of the figure, there is an indoor temperature and an outdoor temperature. The sensors values are sent to the virtual sensor shown by a blue window, which is also a micro-controller. Based on this two values, the device can detect if a window is open or not. To do this, it compare the last value of both temperature sensors. Then, it sends a true boolean if a window is open, false otherwise.

On the middle, we have a virtual sensor which combine the values from the person sensor, the heating sensor and the window sensor. This virtual sensor combine the last values of each source sensors. If, in a room, there is a person with a open window and a heating on during at least a predefined time (e.g five minutes), then the micro-controller turn on the alert system, shown by the red card.

As we can see, the micro-controllers combine values received from different sensors, with sometimes the time window concept. There is no easy way to implement that with just state machine. Indeed, the developers must implement time window manually, use temporary values, use booleans to combine values. However, it already exists some technique to do this : complex event processing (CEP). To ease such development, in the HEADS project we are implementing a new approach which combine state machine and CEP, with resources constraints (device with a few KB of RAM and a few MHz of clock speed). We describe this method in the next section.

## How to implement this in ThingML
All the code of this example can be find here. **TODO : add 

### The heating sensor - on the top
To declare a stream, two things should be specified: the input event (or source) and the output event. In ThingML, there is two keywords: **from** to declare the source and **action** to declare the output. Both must be in a **stream** declaration, in the same level as function declation : 
```
stream heatingSensor do
    from rcvPort?heatingIsOn
    action sendPort!cepHeatingStatus()
end
```

This piece of code allows to send a "cepHeatingStatus" when a "heatingIsOn" message is received. The language permits also to add some values to the output event (and get the values of the sources) with the **select** clause. **ATTENTION:** all the output parameters must be in the **select** clause, even if it is a literal. Thus, the below code shows how to forward the value of a message in ThingML:

```
stream heatingSensor do
    from heating : [rcvPort?heatingIsOn]
    select v : heating.value
    action sendPort!cepHeatingStatus(v)
end
```

Any expression (complex arithmetic expression, function call, ...) can be added in this clause. If there is more than once parameter, the declarations are separated by a coma. This clause is executed just before the action. In following paragraphs, we will see some operators. Thus, the select clause occurs after all of them. 


### The windows-open detector (on the right) and the person-presence detector (on the left)
Currently, two events can be joined to create a unique output. More than declare this two messages, the result message with its new parameters must be specified (on the below example, all the code after the arrow). Any expression can be added to compute the new parameter. FOr exemple, here we put a function call. 

```
stream windowOpenDetector do
   from w : [ indoor : rcvPort?indoorTemp & outdoor : rcvPort?outdoorTemp -> windowOpen(complexAlgo(indoor.value,outdoor.value))]
   select windowIsOpen: w.v
   action sendPort!cepWindowOpen(windowIsOpen) 
end
```

However, currently we can join only two events. So, for the person-presence detector, two streams have to be created, like in the below code:

```
stream joinTempHumidity do
   from jTH : [ temp: rcvPort?indoorTemp & humi: rcvPort?humidity -> cepJTH(temp.v,humi.v) ]
   select tempV : jTH.temp, humiV : jTH.humi
   action sendPort!cepJTH(tempV,humiV)
end

stream personPresenseDetector do
   from person : [ joinTH: rcvPort?cepJTH & light : rcvPort?light -> cepPerson(complexAlgo(joinTH.temp,joinTH.humi,light.v)) ]
   select isPresent: person.v
   action sendPort!cepPersonIsPresent(isPresent)
end
```

**ATTENTION: ** the semantic of the join is the one of [ReactiveX](http://reactivex.io/documentation/operators/join.html). 
It is not possible (currently) to customize the time in ThingML. Currently, you have to modify the generated source code. 

### Merge multiple window-open detector
We can imagine that there is a window-open detecting device on each window. But, in our example, if one window is open, it does'nt matter about which, we notify the system. To developp this, the ThingML language support the **merge** feature. The output event is sent as soon as one event of the source list is received. Contrary to the join feature, the merge feature support an "infinite" number of merged messages. **ATTENTION: ** However, all the messages must have the same footprint (i.e: same parameters type).

Since the message parameters could have different name, we introduce a new syntax element: "#i", where i is the index of the parameter (we start to count at 0). The following code show how to merge three window-open detectors:

```
stream mergeWindowOpenDetector do
    from merge: [ window1?cepWindowOpen | window2?cepWindowOpen | window3?cepWindowOpen -> cepWindowOpen(#0)]
    select oneWindowOpen: merge.v
    action room1!cepWindowOpen(oneWindowOpen)
end
```

This syntax can be also used in the **select** clause. For example, here the select could be : `select oneWindowOpen: #0 `.

### Operators
In all the previous code, the output event is sent whatever is value. However, we can filter these messages to send only message that interested in the system. It can be done thanks to the **filter** operator. It needs one thing: a special "function" which take a message as parameter and return a boolean. We talk about **operator**. 


