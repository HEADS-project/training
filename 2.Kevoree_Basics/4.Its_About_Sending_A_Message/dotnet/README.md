> :warning: This tutorial is the sequel of [3.Runtime_Reconfigurations - Dotnet](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/3.Runtime_Reconfigurations/dotnet), be sure to do the previous tutorial first.  

#### Purpose of this tutorial
In a distributed system what you want to do is sending messages between your different components.  
With Kevoree, components can send messages to other components without implementing any communication protocol inside a component.  
Communications in Kevoree introduce 2 new concepts:
  - **Port**: you create them in your component, they can be of two types
    - Input - receives messages from outside in your components
    - Output - sends messages from your component to "outside"
  - **Channel**: this is where the communication protocol is implemented  
    Channels can implement any type of communication protocol, the only job they do, is receiving messages from the connected **output** ports and broadcasting them to the connected **input** ports

The Kevoree Standard Library already provides different type of channels so you do not have to create a channel from scratch to get started.
In this tutorial, you will use a channel named **LocalChannel**  

In order to use those 2 new concepts, you will extend your **HelloWorld** component so that it will send messages on an **output port** named **hello**.
You will also add a LocalChannel to your model in order to handle the communications.
The component that will receive the messages will be one of the Kevoree Std Lib, named **ConsolePrinter** (which prints any received message to the console)

#### How to create an output port
In Kevoree JS, to declare a new **output port** you have to add a new field to your class using the **[Output]** attribute.

```dotnet
using Org.Kevoree.Annotation;
using System;
using System.ComponentModel.Composition;
using Org.Kevoree.Core.Api;
using Org.Kevoree.Log.Api;

namespace Org.Kevoree.Library.Comp.HelloWorld
{
    [ComponentType]
    [Serializable]
    [Export(typeof(DeployUnit))]
    public class HelloWorld : MarshalByRefObject, DeployUnit
    {

        [Output]
        private Port hello;

        // [...]
    }
}
```

#### How to use an output port
In order to send messages using the `hello` output port you have to use the send function **hello** field. Kevoree Dotnet will inject a Port implementation at runtime into the **hello** field.

```dotnet
using Org.Kevoree.Annotation;
using System;
using System.ComponentModel.Composition;
using System.Threading;
using Org.Kevoree.Core.Api;
using Org.Kevoree.Log.Api;

namespace Org.Kevoree.Library.Comp.HelloWorld
{
    [ComponentType]
    [Serializable]
    [Export(typeof(DeployUnit))]
    public class HelloWorld : MarshalByRefObject, DeployUnit
    {

        [Output]
        private Port hello;

        [Param(Optional = false, DefaultValue = "Hello, World!")]
        public String greetMessage;

        [KevoreeInject]
        private ILogger logger;

        private Timer timer;

        [Start]
        public void Start()
        {
            logger.Debug("Start");
            this.timer = new System.Threading.Timer(new TimerCallback(SendMessage), null, 0, 5000);
        }

        private void SendMessage(object state)
        {
            hello.send(this.greetMessage, null);
        }

      // [...]
    }
}

```

At this point, you have created a new output port for your component,
and you are sending the greet message every 5 seconds to whatever is connected to it.

#### Improve your KevScript
You can now integrate you **HelloWorld** component with any component which defines an **Input** port.
For example the following KevScript connect the **HelloWorld** component to the **ConsolePrinter** unsing a **LocalChannel**.

```txt
add node0 : DotnetNode/1.0.4
add node0.console : ConsolePrinter/5.3.0
add node0.myComp : HelloWorld/1.0.4
add sync : WSGroup/5.3.0
add localChan : LocalChannel/5.0.2

attach node0 sync

bind node0.myComp.hello localChan
bind node0.console.input localChan
```

#### Run your project
When you deploy the previous KevScript in a running **DotnetNode** you'll see the *greetMessage* printed every five seconds in your console.

#### What just happened ?
You are using **LocalChannel** in your model, this channel is able to receive/send messages "locally", by locally I mean **only on the same** node platform.
It only works locally because LocalChannel does not use any client/server logic. It just tries to broadcast the messages to the connected input ports bound to it on the same node host.  
If you want to move the `printer : ConsolePrinter` component to another node, you will have to use another channel that is able to relay the communications over the network (see [5.Distributed_System](https://github.com/HEADS-project/training/tree/master/2.Kevoree_Basics/5.Distributed_System))  

#### Input port creation
In order to create an input port in Kevoree Dotnet you have to add the **Input** attribute to a method with one string parameter.
Because your HelloWorld component does not have to have an input port, I will just give the example from the **ConsolePrinter** component

```dotnet
[KevoreeInject] private Context context;

[Input]
public void input(String msg)
{
    if (this.allowPrint)
    {
        Console.WriteLine(context.getInstanceName() + ">" + msg);
    }
}
```

Every time the **ConsolePrinter** component receives a message, the `input(msg)` method is called with the `msg` parameter set with the content of the received message.  
You can see that the behavior is really basic: it uses the Dotnet native `System.Console.WriteLine` method to output the content to the standard output.

> `[KevoreeInject] private Context context;` asks for the Dotnet core to inject the local context of the component. It provides some information to the node, for example its current name in the model.
> `context.getInstanceName()` is the method which returns the current name of the component.
