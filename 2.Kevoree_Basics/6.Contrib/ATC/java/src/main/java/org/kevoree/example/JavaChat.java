package org.kevoree.example;

import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import org.kevoree.annotation.ComponentType;
import org.kevoree.annotation.Input;
import org.kevoree.annotation.Output;
import org.kevoree.annotation.Param;
import org.kevoree.annotation.Start;
import org.kevoree.annotation.Stop;
import org.kevoree.annotation.Update;
import org.kevoree.api.Port;
import org.kevoree.log.Log;

@ComponentType
public class JavaChat {

	private ChatPanel chatPanel;
	
    @Param(defaultValue = "Kevoree Chat")
    private String name;

    @Output
    private Port messageOut;

    @Input
    private void messageIn(Object msg) {
    	chatPanel.addMessage(msg.toString());
    }
    
    @Start
    public void start() {
        Log.info(name + ": started");

        javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                createAndShowGUI();
            }
        });
    }

    @Stop
    public void stop() {
        Log.info("Bye, world!");
    }

    @Update
    public void update() {
        Log.info("Update: {}", name);
    }
    
    /**
     * Create the GUI and show it.  For thread safety,
     * this method should be invoked from the
     * event-dispatching thread.
     */
    private void createAndShowGUI() {
        //Create and set up the window.
        JFrame frame = new JFrame(name);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
 
        chatPanel = new ChatPanel();
        frame.getContentPane().add(chatPanel);
 
		frame.setResizable(false);
		Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
		int width = 500;
		int height = 470;
		frame.setBounds((screen.width - width)/2, 
				  ((screen.height - height)/2)-10, width, height);
		chatPanel.setPreferredSize(new Dimension(width, height));
        
        //Display the window.
        frame.pack();
        frame.setVisible(true);
    }
    
    
    class ChatPanel extends JPanel implements ActionListener {

		private static final long serialVersionUID = 1L;

		protected JTextField textField;
	    protected JTextArea textArea;
	    private final static String newline = "\n";
	    
	    public ChatPanel() {
	        super(new GridBagLayout());
	        
	        textField = new JTextField(20);
	        textField.addActionListener(this);
	 
	        textArea = new JTextArea(5, 20);
	        textArea.setEditable(false);
	        JScrollPane scrollPane = new JScrollPane(textArea);
	 
	        //Add Components to this panel.
	        GridBagConstraints c = new GridBagConstraints();
	        c.gridwidth = GridBagConstraints.REMAINDER;
	 
	        c.fill = GridBagConstraints.HORIZONTAL;
	        add(textField, c);
	 
	        c.fill = GridBagConstraints.BOTH;
	        c.weightx = 1.0;
	        c.weighty = 1.0;
	        add(scrollPane, c);	        
	    }
		
		@Override
		public void actionPerformed(ActionEvent arg0) {
	        String text = textField.getText();
	        textArea.append("Sent: " + text + newline);
	        //textField.selectAll();

	        textArea.setCaretPosition(textArea.getDocument().getLength());			
	        messageOut.send(text, null);
		}
    	
		public void addMessage(String message) {
	        textArea.append("Received: " + message + newline);
	        textArea.setCaretPosition(textArea.getDocument().getLength());
		}
		
    }
}
