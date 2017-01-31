HEADS The Room Tutorial
================================

![HEADS](http://heads-project.eu/sites/default/files/heads_large.png)

This tutorial shows through a number of versions how ThingML can be used to model a thermostat to control the temperature of a room.
Each version can be run in a simulated environment and some versions can even be run in a real environment built on [Telldus technology](http://telldus.se) using 433MHz radio communication between a Tellstick, thermometers and simple on/off switches.
The tutorial consists of a series of lectures where the slides are presented in pdf and the associated ThingML source code.
The idea is to solve some real problems and also introduce new ThingML constructs when solving these.

## List of lectures
### L0: Installation and ThingML basics
Just to get the system up and running on the simulated environment
### L1: The Room X1.
This version only lets the user observe temperature and actuate the switches. Since this is a simulated environment, the temperatures must also be input from the user.
### M1: Modeling and Consistency
We have added one general lecture on modeling and consistency
### L2: The Room X2 Thermostat.
We make a very simple thermostat.
### L3: The Room X3 Externals.
We can control our own system, but we cannot control the users or external technical devices. What impact does this have on our ThingML system?
### L4: The Room X4 Watchdogs.
There are still some risks that should be mitigated. We show how concurrent monitoring processes can help coping with the most critical hazards of our room.


