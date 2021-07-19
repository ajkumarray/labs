
//  labAssignment10     Simple Calculator
import java.awt.*;
import java.awt.event.*;

public class MyCalculator extends Frame implements ActionListener {
    TextField textFieldInput;
    Panel panel;

    String buttonString[] = { "7", "8", "9", "DEL", "AC", "4", "5", "6", "*", "/", "1", "2", "3", "+", "-", "0", ".",
            "=", "EXIT" };
    Button btn[] = new Button[19];
    double num1 = 0, num2 = 0, result = 0;
    char operation;

    public MyCalculator() {
        Font font = new Font("Cambria", Font.BOLD, 18);

        textFieldInput = new TextField(30);
        textFieldInput.setFont(font);

        panel = new Panel();

        add(textFieldInput, "North");
        add(panel, "Center");

        panel.setLayout(new GridLayout(4, 5));

        for (int i = 0; i < 19; i++) {
            btn[i] = new Button(buttonString[i]);
            btn[i].setFont(font);
            btn[i].addActionListener(this);
            panel.add(btn[i]);
        }

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    public void actionPerformed(ActionEvent ae) {
        String str = ae.getActionCommand();
        if (str.equals("+")) {
            operation = '+';
            num1 = Double.parseDouble(textFieldInput.getText());
            textFieldInput.setText("");
        } else if (str.equals("-")) {
            operation = '-';
            num1 = Double.parseDouble(textFieldInput.getText());
            textFieldInput.setText("");
        } else if (str.equals("*")) {
            operation = '*';
            num1 = Double.parseDouble(textFieldInput.getText());
            textFieldInput.setText("");
        } else if (str.equals("=")) {
            num2 = Double.parseDouble(textFieldInput.getText());

            switch (operation) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    result = (double) ((num1 / num2) + (num1 % num2));
                    break;
            }
            textFieldInput.setText(result + "");
            result = 0;
        } else if (str.equals("AC")) {
            textFieldInput.setText("");
            num1 = num2 = result = 0;
        } else if (str.equals("EXIT")) {
            System.exit(0);
        } else if (str.equals("DEL")) {
            String Res = textFieldInput.getText();
            String temp = "";
            for (int i = 0; i < Res.length() - 1; i++)
                temp += Res.charAt(i);
            textFieldInput.setText(temp);
        } else {
            textFieldInput.setText(textFieldInput.getText() + str);
        }
    }

    public static void main(String[] args) {
        MyCalculator m = new MyCalculator();
        m.setTitle("Simple Calculator");
        m.setSize(350, 300);
        m.setVisible(true);
    }
}