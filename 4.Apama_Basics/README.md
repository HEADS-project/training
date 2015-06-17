HEADS Complex Event Processing basics with Apama
===

![HEADS](http://heads-project.eu/sites/default/files/heads_large.png)

Learn the basics of Complex Event Processing (CEP) with Apama. Apama is the CEP engine of Software AG. For the product offering see 
http://www.softwareag.com/corporate/products/apama_webmethods/analytics/overview/default.asp or 
https://www.softwareag.com/corporate/res/download/default.asp for a free trial download.

**This tutorial covers:**

* Installing Apama 5.3 (CEP Engine and Eclipse based Apama Studio) on Windows.
* Using the tutorial on EPL monitor scripts.
* Running the included demos.
* Exploring the samples.
* Exercises for Apama queries.

### 0. Installing Apama 5.3

Unpack the apama_5.3.0.0_win_64.zip and run apama_5.3.0.0_win_64.exe according to Installing_Apama.pdf (also in zip). Have the license file you 
got from Software AG in hand.
Install the developers option. Administrative privileges are needed.
The installation for this tutorial requires Windows, because Apama Studio is not supported on other platforms. 

### 1. Exploring the samples

In Apama Studio open the Welcome page, go to the Samples section. These six samples can be imported into an Eclipse workspace as Apama projects. 
From the Apama Workbench perspective you can launch these samples, one at a time. The Readme files suggest small exercises to modify these samples. 
The source of the samples is the folder 'demos' in the Apama installation. The folder 'samples' contains more in-depth examples for components 
of Apama and the connection with other products like Universal Messaging or Terracotta BigMemory.  

### 2. Using the tutorial on EPL monitor scripts

In Apama Studio open the Welcome page, go to the Tutorials section. There are three tutorials. The last one with the title 'Developing an 
Application with MonitorScript' is the most important one. It explains the Apama Event Programming Language (EPL), called "MonitorScript". 
A Cheat Sheet guides you through this tutorial. 

### 3. Exercises for Apama queries
  
For the Apama queries, a newly integrated feature of Apama 5.3, there are seven example projects in the folder 'samples/queries' of the 
Apama installation. These projects can be imported into an Eclipse workspace. The Apama Query File Editor offers a Design view, where you 
can specify the various sections of a query. The Source view of this editor shows the query in textual form. In an Apama project, the queries 
are in the 'queries' folder and each query is stored in a separate file with extension qry.   
  
## Reporting issues, getting support, etc

If you encounter any problem, find a bug or have suggestions for additional features, please use 
the [HEADS IDE bug tracker](https://github.com/HEADS-project/heads_ide/issues). This is the best and preferred way of getting in touch with us.

## Contact us

For any other issue feel free to contact any of us by email.

* HEADS project: Franck FLEUREY (franck.fleurey@sintef.no)
* CEP and Apama: Martin Skorsky (martin.skorsky@softwareag.com)  