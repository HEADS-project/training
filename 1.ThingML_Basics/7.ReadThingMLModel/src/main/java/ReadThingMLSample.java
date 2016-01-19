import org.eclipse.emf.common.util.URI;
import org.eclipse.emf.ecore.resource.Resource;
import org.eclipse.emf.ecore.resource.ResourceSet;
import org.eclipse.emf.ecore.resource.impl.ResourceSetImpl;
import org.sintef.thingml.StateMachine;
import org.sintef.thingml.State;
import org.sintef.thingml.Thing;
import org.sintef.thingml.ThingMLModel;
import org.sintef.thingml.resource.thingml.mopp.ThingmlResourceFactory;

import java.io.File;

/**
 * Created by ffl on 26.11.15.
 */
public class ReadThingMLSample {

    public static void main(String[] args) {

        File input = new File("models/Basics/Timer/PingPong.thingml");

        // Parse and build a model of the thingml program

        try {

        Resource.Factory.Registry reg = Resource.Factory.Registry.INSTANCE;
        reg.getExtensionToFactoryMap().put("thingml", new ThingmlResourceFactory());


        System.out.println("Loading input file: " + input.getAbsolutePath() + "...");


        ResourceSet rs = new ResourceSetImpl();
        URI xmiuri = URI.createFileURI(input.getAbsolutePath());
        Resource model = rs.createResource(xmiuri);
        model.load(null);

        if (model.getErrors().size() > 0) {
            System.out.println("ERROR: The input model contains " + model.getErrors().size() + " errors:");
            for (Resource.Diagnostic d : model.getErrors()) {
                System.out.println("  " + d.getLocation() + " : " + d.getMessage());
            }
            return;
        }

        ThingMLModel input_model = (ThingMLModel) model.getContents().get(0);

        System.out.println("Model loaded successfully.");


            // Do somthing random with the model (just as an example)
            processThingMLModel(input_model);

        }
        catch(Throwable t) {
            System.err.println(t.getMessage());
            t.printStackTrace();
        }

    }

    public static void processThingMLModel(ThingMLModel input_model) {

        System.out.println("The model contains " + input_model.allThings().size() + " Things");
        System.out.println("Here is the list: ");

        for (Thing t : input_model.allThings()) {
            processThing(t);
        }

    }

    public static void processThing(Thing t) {
        System.out.println("  *" + t.getName());
        // Check if there are any state machines
        if (t.allStateMachines().size() > 0) {
            System.out.println("    -> Found a state machine");
            processStateMachine(t.allStateMachines().get(0));
        }
    }

    public static void processStateMachine(StateMachine sm) {
        for (State s : sm.allStates()) {
            System.out.println("        - State " + s.getName());
        }
    }

}
