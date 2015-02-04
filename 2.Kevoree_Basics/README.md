HEADS Kevoree runtime management basics
===

![HEADS](http://heads-project.eu/sites/default/files/heads_large.png)

Learn the basics of Kevoree. How to write your own components targeting the Kevoree Java or Kevoree JavaScript platforms, and use the different Kevoree tools in order to apply some reconfigurations over your running systems.

> You need a **JDK 8** in order to compile and run Kevoree for **Java**  
> You also need the **.NET** framework to be installed on Windows for the JavaScript platform


**This tutorial covers:**

* Basic Kevoree syntax (through a set of examples)
* Compiling to 2 different platforms (Java, JavaScript)
* Running the compiled code on the 2 different platforms (using Kevoree Script)
* Apply some reconfigurations over your running system (using the Kevoree Web Editor)

**Note:**

* Some documentation on the Kevoree syntax can be found on the [Kevoree Book website](http://kevoree.github.io/kevoree-book/) . It is currently incomplete but might be useful.
* A lot of Kevoree example programs can be found [here](https://github.com/kevoree/kevoree-library) and also [here](https://github.com/kevoree/kevoree-samples). Be warned that they might be outdated.

### 0.General features of the HEADS IDE
  - **New Kevoree Java Project**
    - *From existing sources*: **File** > **Import** > **Maven** > **Existing Maven Project**  
      - Select a java tutorial folder like  `path/to/2.Kevoree_Basics/1.HelloWorld/java` and import it  
      - **Right-click** on the project name > **Configure** > Then be sure it says *Remove Kevoree nature*  
        If it says *Add Kevoree nature*, then click on it, otherwise you are good to go.
    - *From scratch*: **File** > **New** > **Project** > **Kevoree** > **New Kevoree Project** > **Next**  
      - Give a project name
      - [optional] Set the location of your new project
      - Click **Finish**


  - **New Kevoree JavaScript Project**  
    - *From existing sources*: **File** > **New** > **Project** > **Kevoree JS** > **Kevoree JS Project**  
      - Set the project name
      - Set the location of your sources (**unckeck Default location and specify the proper path**)
      - Use template HelloWorld
      - Click **Finish**
    - *From scratch*:
      - Follow the [first step](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/1.HelloWorld/js) of the Kevoree JavaScript Tutorial n°1
      - Now use the same process as for *From existing sources*


> Nb: if you have imported your project and it is still not recognized as a Kevoree project (i.e the orange Kevoree Logo), then right-click on the project name  `Configure > Add Kevoree Nature`

> Nb2: if the right-click on `package.json > Run as > npm install` throws an exception, then be sure that `Nodeclipse` is well configured.

### 1.HelloWorld
[Java Tutorial](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/1.HelloWorld/java)  
[JavaScript Tutorial](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/1.HelloWorld/js)

### 2.HelloWorld++
[Java Tutorial](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/2.HelloWorld++/java)  
[JavaScript Tutorial](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/2.HelloWorld++/js)

### 3.Runtime reconfigurations using the Kevoree Web Editor
[Java Tutorial](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/3.Runtime_Reconfigurations/java)  
[JavaScript Tutorial](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/3.Runtime_Reconfigurations/js)

### 4.It's about sending a message
[Java Tutorial](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/4.Its_About_Sending_A_Message/java)  
[JavaScript Tutorial](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/4.Its_About_Sending_A_Message/js)

### 5.Distributed System
[Tutorial](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/5.Distributed_System)

### 6.Contrib
[DIY](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/6.Contrib)
