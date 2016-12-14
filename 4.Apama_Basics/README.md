HEADS Complex Event Processing basics with Apama
===

![HEADS](http://heads-project.eu/sites/default/files/heads_large.png)

Learn the basics of Complex Event Processing (CEP) with Apama. Apama is the CEP engine of Software AG. For the product offering see 
http://www.softwareag.com/corporate/products/apama_webmethods/analytics/overview/default.asp. 

For the Apama Community Edition see http://www.apamacommunity.com/. Apama Community Edition is a freemium version of Apama by Software AG that can be used to learn about, develop and put streaming analytics applications into production. Find the latest version of Apama for download at http://www.apamacommunity.com/downloads/. The complete documentation is http://www.apamacommunity.com/docs/. A brief description of the functionality and technical key features are described in a 20-page white paper http://www.apamacommunity.com/wp-content/uploads/2016/06/SAG_The_Apama_Platform_20PG_WP_Jun16-Web.pdf.


**This tutorial covers:**

* Installing Apama (CEP Engine and Eclipse based Software AG Designer with Apama Studio) on Windows.
* Using the tutorial on EPL monitor scripts.
* Running the included demos.
* Exploring the samples.
* Exercises for Apama queries.

### 0. Installing Apama

The Apama Community Edition can be installed without a license file.
Install the developers option. Administrative privileges are needed.
The installation for this tutorial requires Windows, because Apama Studio is not supported on other platforms. Please complain, if this is a show stopper.

Installation verification: 

* Import demo project 'Weather' from the samples of the welcome page.
* This opens the Apama Workbench perspective with the Launch Control Panel on the lower left corner of the window and the readme.htm in the editor area.
* Start the Apama correlator with the default settings.
* If you start Apama with a license file, you see in the Eclipse console log of this application 
```
2015-**-** xx:xx:xx.342 ##### [1384] - License information:
2015-**-** xx:xx:xx.342 ##### [1384] -   D:\Users\xxxx\SoftwareAG\ApamaWork_5.3\license\license.txt
2015-**-** xx:xx:xx.342 ##### [1384] -   Expiration date:   2015-07-18
2015-**-** xx:xx:xx.343 ##### [1384] -   Monitor limit:     unlimited
2015-**-** xx:xx:xx.346 ##### [1384] -   Context limit:     unlimited
2015-**-** xx:xx:xx.349 ##### [1384] -   Event rate limit:  unlimited
2015-**-** xx:xx:xx.355 ##### [1384] -   Connect Allowed:   true
2015-**-** xx:xx:xx.357 ##### [1384] -   Version prefix:    "5"
2015-**-** xx:xx:xx.359 ##### [1384] -   Platforms:        
2015-**-** xx:xx:xx.363 ##### [1384] -     "*"
```
* This shows that the license file is correctly installed and Apama is working.
* Stop Apama correlator with the stop button in the Launch Control Panel.

  

### 1. Exploring the samples

In Apama Studio open the Welcome page, go to the Samples section. These six samples can be imported into an Eclipse workspace as Apama projects. 
From the Apama Workbench perspective you can launch these samples, one at a time. The Readme files suggest small exercises to modify these samples. 
The source of the samples is the folder 'demos' in the Apama installation. The folder 'samples' contains more in-depth examples for components 
of Apama and the connection with other products like Universal Messaging or Terracotta BigMemory. 

Steps to perform for a sample:

* Import project into workspace
* Explore files in the Apama Workbench perspective. Toggle on the 'Show All Folders' button in the toolbar of the 'Workbench Project View'.
* Launch the sample with the 'Launch Control Panel'. This starts a correlator (Apama CEP runtime process) listening on port localhost:15903 (default). 
In addition a dashboard viewer is started in a separate window and events are sent to the correlator. 
 

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