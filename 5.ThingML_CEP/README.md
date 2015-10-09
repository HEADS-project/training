HEADS ThingML modelling language: Complex Event Processing
===

![HEADS](http://heads-project.eu/sites/default/files/heads_large.png)

### 0. Prerequisites

**You should, at least, have done [Tutorial #1](https://github.com/HEADS-project/training/tree/master/1.ThingML_Basics)**. In other words, you should be comfortable with using the HEADS IDE and the ThingML language in particular, and should know how to generate, compile and run Java and/or JavaScript code.

### 1. Background

In the context of the HEADS project, ThingML has been extended with Complex Event Processing capabilities, which complement the existing state machines.

We use the [ReactiveX library](http://reactivex.io) in the Java and JavaScript code we generate. Though you do not really need to know ReactiveX to use CEP in ThingML, it might be a good idea to visit their pages if you are new to CEP. The ReactiveX library will automatically be imported as a Maven or NPM dependency in the generated code.

> We do not support C/C++, yet, though it exists a C++ library for ReactiveX (less official and less documented than the Java/JS ones...)

In terms of syntax, we choose a declarative approach, much closer than ThingML and Apama (see Tutorial #4) instead of the programmatic approach chosen by ReactiveX. The main advantage is that we can use the exact same syntax to target Java, JavaScript or C/C++ (in the future). Without this model-driven generative approach, you would need to learn the APIs of ReactiveX for each programming language you want to target!

### 1. Exercises

This tutorial is organized in a set of exercices:

1. Basics: Learn the syntax to express streams
2. Join: Learn how to join events
3. Merge: Learn how to merge event
4. Operators: Learn how to apply filters, etc

## Contact us

For any other issue feel free to contact any of us by email.

* HEADS project: Franck FLEUREY (franck.fleurey@sintef.no)
* CEP in ThingML: Brice MORIN (brice.morin@sintef.no)
* CEP in general: Martin Skorsky (martin.skorsky@softwareag.com)
