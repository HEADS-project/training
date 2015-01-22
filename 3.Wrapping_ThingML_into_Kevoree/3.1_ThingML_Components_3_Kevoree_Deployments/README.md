### Introduction

In this first exercice, we'll use a simple application composed of:

- a timer
- a timer client, which start/cancel/re-start the timer and prints a tick on timeout

The application itself is trivial/useless. The point of this tutorial is simply **to understand how an application written in ThingML can be wrapped into Kevoree**.

### How to?

In this first exercise, you will be using the ThingML to Kevoree/Java compiler as follows:

- compile the default Java behavior, as you did in Tutorial 1
- compile the Kevoree wrapper

Open the `_java/timer.thingML` file in the HEADS IDE and compile the three different configurations using this procedure. Then import the result in the Kevoree editor and deploy it! It is recommended you look at the code in the `kevoree` package to understand how we map ThingML configurations to Kevoree deployment models. 

### How ThingML configurations map to Kevoree deployment model?

Though the timer application is trivial, it is complex enough to understand the different mappings between a ThingML configuration and a Kevoree deployment model.

#### All components are defined and connected in the ThingML configuration

If all your components are defined in a single ThingML configuration, and if all the ports are connected, it will generate a single Kevoree component with no exposed port. Everything will be internally managed by ThingML and seen as a black box by Kevoree. 

> In general, it might not be a good idea to bind instantiate and connect everything in your ThingML configuration, as it reduces the flexibility you will have at runtime to manage your application. However, in more complex configurations (involving more than two components), it is a good idea to hide some *things*, which you just consider as implementation details.

#### All components are defined, but only partially (or not at all) connected in the ThingML configuration

This will also lead to one single Kevoree component, but the ports that are connected within the ThingML configuration will be exposed as Kevoree ports. It is then up to you to properly bind them using the Kevoree editor (or KevScript). This approach is a bit more flexible as it allows you to choose and dynamically change the communication semantics (channels) between your ports. 

> Note that if a ThingML port can both send and receive messages, it will be split into two Kevoree ports, which either send or receive messages. We might re-align the ThingML and Kevoree semantics by leveraging the Kevoree callbacks in a later release of the wrapper.

#### All components are defined in their own ThingML configurations

In this case, we will generate one Kevoree component per ThingML configuration. It is then up to you to load these individual components into the Kevoree editor (or Kevscript) and connect them. This approach is the most flexible. You can change the communication semantics, and you are now able to manage components individually at runtime (e.g. stop the client or replace it by another component).

#### In general

In general, you will most likely use a combination of those three mappings.
