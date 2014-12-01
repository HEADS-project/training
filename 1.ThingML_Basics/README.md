HEADS ThingML modelling language basics
===

![HEADS](http://heads-project.eu/sites/default/files/heads_large.png)

Learn the basics of ThingML. How to write you first program in a platform independent way and compile it to different platfroms ranging from an Arduino microcontroller to a plan Java program. Also learn how to write platform specific components and link to exiting APIs or libraries.

**This tutorial covers:**

* Installing the ThingML tools (editor and compilers)
* Basic ThingML syntax and constructs (through a set of examples)
* Compiling to 4 different platforms (Java, NodeJS, Posix C, Arduino)
* Running the compiled code on the 4 different platforms
* Writing ThingML platform independent components
* Specializing ThingML platform independent components to different platforms
* Writing an additional example program in ThingML


### 0. Installing the HEADS tools for ThingML

To follow this tutorial, you need to have the ThingML editor and compilers. They are released as plugins for the Eclipse IDE. There are two options for installing the ThingML tools: 

* Download the latest HEADS IDE Eclipse bundle. This bundle contains all the HEADS plugins already installed. Information on downloading and installing can be found at  https://github.com/HEADS-project/heads_ide/issues.

* Install the ThingML plugin in your own installation of Eclipse. Follow the instructions on how to install the eclipse plugins at http://thingml.org/pmwiki.php?n=Main.OnlineDemo.

To check if the ThingML editor is properly installed, open a sample ".thingml" file. It should open with the ThingML editor (text editor with syntax highlighting). To check if the compilers are properly installed, right-click on a ".thingml" file. You should have a "HEADS / ThingML" sub-menu in the context menu. This sub-menu allows calling the different ThingML compilers.


### 1. Hello World!

The first step of this totorial is a simple Hello Wold example in ThingML. This examples shows the smallest possible ThingML program. It is composed of a "Thing" which defines a component type and a Configuration which creates a single instance of this component type.

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


### 2. Asynchronous messaging with the Ping Pong Example

### 3. Platform independent vs. platform specific

### 4. Defining Timers for different platforms

### 5. Writing your own program!

In this last step of the tutorial, your task is to write your own program in ThingML. 

**Your program should contains:**

* At least two components (thing)
* bi-directional communication through messages with at least one parameter
* Should include at least one platform independent component
* Should be compilable and executable on at least 2 platforms
* Should use some platform specific features

Submit your program by forking the training repository (https://github.com/HEADS-project/training), adding to example in a sub-folder in the Contribs directory and making pull request. If you have no idea how to do this, send your example to Brice Morin (brice.morin@sintef.no). The best examples will be added as additional examples in this tutorial. Think about what examples you would have liked to get!

## Reporting issues, getting support, etc

If you encouter any problem, find a bug or have suggestions for additional features, please use the HEADS IDE bug tracker at https://github.com/HEADS-project/heads_ide/issues. This is the best and prefered way of getting in touch with us.



## Contact us

For any other issue feel free to contact any of us by email.

* HEADS project: Franck FLEUREY (franck.fleurey@sintef.no)
* ThingML tools: Brice MORIN (brice.morin@sintef.no)
* Kevoree tools: Olivier Barais (obarais@irisa.fr)
