> :warning: This tutorial is the sequel of [1.HelloWorld - Dotnet](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/1.HelloWorld/dotnet), be sure to do the previous tutorial first.

#### Purpose of the HelloWorld++ component
Now we want to extend the previous [HelloWorld component](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/1.HelloWorld/dotnet)
so that you can dynamically change the content of the displayed "Hello, world!" message.
For that, you will use the Kevoree concept: **dictionary attribute**

#### Add a dictionary attribute
In order to give some parameters to a component Kevoree provides a concept called
**dictionary attributes**.
Dictionary attributes can be added to a component in Kevoree Dotnet by using the **[Param]** attribute.

```dotnet
using Org.Kevoree.Annotation;
using System;
using System.ComponentModel.Composition;

[ComponentType]
[Serializable]
[Export(typeof(DeployUnit))]
public class HelloWorld : MarshalByRefObject, DeployUnit
{
    [Param(Optional = false)] public String _greetMessage;

    // [...]
}
```

By doing so, you will be able to set the value of "greetMessage" when you defines your Kevoree model.

For example a KevScript would looks like this :

```txt
add node0 : DotnetNode
add node0.myComp : HelloWorld

set node0.myComp.greetMessage = 'Hello, HEADS!'
```

#### Retrieve a dictionary attribute value
Now that you have defined a new dictionary attribute named `greetMessage` you will want to use it within your component code.
To retrieve an attribute value at runtime in Kevoree Dotnet you just have to use the reference of your annotated field

```java
[Param(Optional = false)] public String greetMessage;

[KevoreeInject] private ILogger logger;

[Start]
public void Start()
{
    logger.Info(this.greetMessage);
}```

#### Run the HelloWorld component
To deploy and run this improved version of the HelloWorld component you can follow the steps described in the first part of this tutorial.

#### Improve the "greetMessage" attribute
> What if I want to set a default value to my attribute without using KevScript ?

For starters we have set the value of `greetMessage` to `null` because it was enough, but you can be more descriptive about your attribute too.
You can specify 3 different properties in the `@Param(...)` annotation for your dictionary attributes:
  - **optional**
    - Whether or not your attribute is mandatory (eg. if `true` a value **has to** be set,
      so if there is no `defaultValue` set and no value set in your KevScript,
      the interpreter will throw an error)
  - **defaultValue**
    - Your attribute default value
  - **fragmentDependant**
    - This property is only used by **Groups** and **Channels** (it makes no sense to set that for Components or Nodes)
      Whether or not your attribute is fragment dependent, if `true` then there will be a dictionary attribute with that name for each relation between group and channels or channels and nodes.

Ok, let's be more descriptive about `greetMessage`

```java
[Param(Optional = false, DefaultValue = "Hello, world")]
public String greetMessage;
```

By doing so, you can remove the `set node0.myComp.greetMessage = 'Hello, HEADS!'` from the KevScript, and it will, by default, output "Hello, world!" on start-up.
