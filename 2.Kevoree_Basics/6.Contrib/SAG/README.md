Example with three nodes (JavaNodes).
Each node receives a message, adds it's Id and sends the message to the output queue.

Currently the example does not work. Some messages are sent and then the configuration crashes.
Current issue #53.

* How to build
`mvn clean install`

* How to start
Use four command shells, one for the broker and three for the three Java nodes.
```
wsbrokerserver 9050
mvn kev:run -Dnode.name=node0
mvn kev:run -Dnode.name=node1
mvn kev:run -Dnode.name=node2
```

or 
```
wsbrokerserver 9050
mvn kev:run -Dnode.name=node0 > node0.log
mvn kev:run -Dnode.name=node1 > node1.log
mvn kev:run -Dnode.name=node2 > node2.log
```
to get log files for each node.