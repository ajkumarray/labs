import java.applet.*;
import java.awt.*;
import java.awt.event.*;

public class labAssignment11A extends java.applet.Applet {
    public void init() {
        Panel panel;
        setLayout(new FlowLayout());
        panel = new Panel();
        panel.add(new TextArea());
        add("Center", panel);
        panel = new Panel();
        panel.add(new Button("Main Menu"));
        panel.add(new Button("Options"));
        Choice choice = new Choice();
        choice.addItem("Main Menu");
        choice.addItem("Options");
        choice.addItem("Settings");
        panel.add(choice);
        add("South", panel);
    }

    public void paint(Graphics graph) {
        graph.setColor(Color.DARK_GRAY);
        graph.drawString("Sample Java Applet", 200, 400);
    }

    public static void main(String[] args) {
        Frame frame = new Frame("Sample Java Applet");
        labAssignment11A ray = new labAssignment11A();
        ray.init();
        frame.add("Center", ray);
        frame.pack();
        frame.show();
        frame.setSize(600, 600);
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        frame.setVisible(true);
    }
}