HEADS ThingML modelling language basics
===

![HEADS](http://heads-project.eu/sites/default/files/heads_large.png)

Learn the basics of ThingML. How to write you first program in a platform independent way and compile it to different platforms ranging from an Arduino microcontroller to a plain Java program. Also learn how to write platform specific components and link to exiting APIs or libraries.

**This tutorial covers:**

* Installing the ThingML tools (editor and compilers)
* Basic ThingML syntax and constructs (through a set of examples)
* Compiling to 4 different platforms (Java, NodeJS, Posix C, Arduino)
* Running the compiled code on the 4 different platforms
* Writing ThingML platform independent components
* Specializing ThingML platform-independent components to different platforms
* Writing an additional example program in ThingML

**Note:**

* Some documentation on the ThingML syntax can be found on the [ThingML web site](http://thingml.org/) . It is currently incomplete but might be useful.
* A lot of ThingML example programs can be found [here](https://github.com/SINTEF-9012/ThingML/tree/master/org.thingml.samples/src/main/thingml).


### 0. Installing the HEADS tools for ThingML

To follow this tutorial, you need to have the ThingML editor and compilers. They are released as plugins for the Eclipse IDE. There are two different options for installing the ThingML tools: 

* [Download the latest HEADS IDE Eclipse bundle](http://coreff5.istic.univ-rennes1.fr/jenkins/job/headside/ws/products.minimal/target/products/). This bundle contains all the HEADS plugins already installed.

* Install the ThingML plugin in your own installation of Eclipse. [Follow the instructions](http://thingml.org/pmwiki.php?n=Main.OnlineDemo) on how to install the eclipse plugins.

To check if the ThingML editor is properly installed, open a sample ".thingml" file. It should open with the ThingML editor (text editor with syntax highlighting). To check if the compilers are properly installed, right-click on a ".thingml" file. You should have a "HEADS / ThingML" sub-menu in the context menu. This sub-menu allows calling the different ThingML compilers.

> Note: To run the generated Java code, we assume you have a JDK properly installed, as well as Maven. For Node.JS code, you need to install Node.JS. For Posix C, you need a GCC-Make toolchain (also possible on Windows using CygWin). Finally, to run the arduino code you need to install the Arduino IDE and have an Arduino board. You will find more details later in this document.

### 1. Hello World!

The first step of this tutorial is a simple Hello World example in ThingML. This examples shows the smallest possible ThingML program. It is composed of a "Thing" which defines a component type: 

	thing HelloThing {
		statechart HelloWorld init Greetings {
			state Greetings {
				transition -> Bye action print "Hello World!\n"
			}
			state Bye {
				on entry print "Bye.\n"
			}
		}
	}

This example is fully platform independent and only uses ThingML statements. The behavior of the `HelloThing` component is described by a state machine with two states and one transition between those states. The program is expected to print "*Hello World*" followed by "*Bye*". After printing "*Bye*" the program remains in the `Bye` state but will not terminate. ThingML programs are typically processes which do not have an exit point.

To compile and run a ThingML program, the components (or Things) need to be instantiated and connected together (if there are more than one). The following Configuration creates a single instance of this component `HelloThing`:

	configuration HelloCfg 
	@arduino_stdout "Serial"
	{
		instance my_instance: HelloThing
	}

This configuration can now be compiled for different platforms and executed. The different compilers can be called from the "HEADS / ThingML" context menu. Do do so:

* Right-Click on the ThingML file to compile (it should be the file which contains the Configuration to be compiled)
* Select the target platform in the "HEADS / ThingML" context menu
* Check for any output message or errors in the ThingML Console (You might need to show the Eclipse Console View if it is hidden, select Window- > Show View -> Others... -> General -> Console).
* The code will be generated in an src-gen folder within the same eclipse project as the ThingML source file. One sub-folder is created for each different target platform and an additional sub-folder is created for each configuration 

#### Generating to Java, Building and running with Maven

The Java code generator produces a standard Maven project. To compile and execute the generated code all you you need to have a JDK and [Maven](http://maven.apache.org/) installed. 

To compile and execute, go to the generated directory and run:

	mvn clean package exec:java -Dexec.mainClass=org.thingml.generated.Main

You may also open the generated project in your favorite IDE. Netbeans and IntelliJ work great with Maven projects. Eclipse typically requires some additional plugins but can also work. 

Hit Ctrl+C to stop the execution of the ThingML program.


#### Compiling to C/C++, Building and running with GCC and Make

The Posix C/C++ code generator produces a standard Linux project which includes a Makefile. You need to have GCC and Make installed in order to build the generated code. If you are running linux you probably already have these installed or can install them very easily. If you are running windows you can follow [these instructions](http://cs.calvin.edu/curriculum/cs/112/resources/installingEclipse/cygwin/) in order to get up and running.

To compile and execute, go to the generated directory and run:

	make
	./HelloCfg


Hit Ctrl+C to stop the execution of the ThingML program.

#### Compiling to Arduino, Building and running with the Arduino IDE

The Arduino code generator produces a single .ino file which contains the complete source code for the ThingML configuration. This file can be directly opened with the Arduino IDE.

Use the arduino IDE to compile and upload the code to your arduino board.

The Hello World example writes to the Arduino serial interface. You should open the serial console in the Arduino IDE in order to see the messages. 

Note: The "print" statement in ThingML normally prints messages to the standard output for the program. In the case of an Arduino board, there are no standard output so by default the code generator will not generate any code for the print statement. The annotation `@arduino_stdout "Serial"` on the Configuration tells the Arduino compiler to use the Serial device as the output for prints and errors.

#### Compiling to Javascript, Building and running with NodeJS

The Javascript compiler produces code which is meant to run with NodeJS. In order to run the generated code you need to install NodeJS. On Ubuntu Linux NodeJS can be installed by running `apt-get install nodejs`. On Windows it can be downloaded from [the NodeJS web page](http://nodejs.org/) and will seamlessly.

To run the generated code, go to the generated directory and run:

	node behavior.js

That is it!

### 2. Asynchronous messaging with the Ping Pong Example

The second example of the tutorial show how to define and use two components exchanging asynchronous messages. As synchronous messages is the absolute only way two ThingML components can communicate and all communication has to go through properly defined messages and ports.

As for the `Hello World` example, this `Ping Pong` program is fully platform independent and can be compiled to any of the supported target platforms.

### 3. Platform independent vs. platform specific

This example presents a simple example of how statements or APIs of the target platforms can be used within ThingML components.

### 4. Defining Timers for different platforms

This example presents a more complete example of how an abstract platform independent component components can be specialized for different platform. The example is the definition of a simple `Timer` library which has to be implemented differently on different target platforms.

### 5. Writing your own program!

In this last step of the tutorial, your task is to write your own program in ThingML. 

**Your program should contains:**

* At least two components (thing)
* bi-directional communication through messages with at least one parameter
* Should include at least one platform independent component
* Should be compilable and executable on at least 2 platforms
* Should use some platform specific features

Submit your program by forking the [training repository](https://github.com/HEADS-project/training), adding to example in a sub-folder in the Contribs directory and making pull request. If you have no idea how to do this, send your example to Brice Morin (brice.morin@sintef.no). The best examples will be added as additional examples in this tutorial. Think about what examples you would have liked to get!

## Reporting issues, getting support, etc

If you encounter any problem, find a bug or have suggestions for additional features, please use the [HEADS IDE bug tracker](https://github.com/HEADS-project/heads_ide/issues). This is the best and preferred way of getting in touch with us.

## Contact us

For any other issue feel free to contact any of us by email.

* HEADS project: Franck FLEUREY (franck.fleurey@sintef.no)
* ThingML tools: Brice MORIN (brice.morin@sintef.no)
* Kevoree tools: Olivier BARAIS (barais@irisa.fr)
