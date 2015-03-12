ATC's contribution presents an example of combining ThingML and Kevoree components. It implements a very simple mock-up of the actual NewsAsset use case. NewsAsset provides Sender and Receiver components. A Receiver receives news items from various sources. It then moves them into NewsAsset for archiving and processing. A Sender forwards NewsAsset news items to various channels, based on subscription information. In the real world both components are implemented in .NET technology. Here are emulated with Java.

**ThingML Components**

* **Timer**: ThingML timer implementation in Java. Taken from tutorial 1.
* **Sender**: ThingML component that receives time out events and sends news items in a receiver. This component wasn't used in the final configuration. It is kept here, because it provides some data types and the design for the Kevoree component.
* **Receiver**: ThingML component that receives news item messages.

The ThingML configurations contain no port connection information. All connections are done in Kevoree level.

** Kevoree Components**
* **NewsMLSender**: Java Sender component wrapped in Kevoree. It connects to an online NewsML provider, retrieves a NewsML XML, parses it and sends the items to a receiver. It merges the Kevoree Java code (generated with HEADS IDE) of Timer and Receiver components. The connections are performed in the main.kevs file.


