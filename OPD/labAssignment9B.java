//  OPD Lab Assignment 9B

import java.io.*;
import java.util.*;

public class labAssignment9B {
    public static void main(String[] args) {
        try {
            File myObj = new File("student.txt");
            if (myObj.createNewFile()) {
                System.out.println("File created: " + myObj.getName() + "\n");
            } else {
                System.out.println(" File already exists.\n");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        while (true) {
            System.out.println("Want to enter record ? (Y/N)");
            Scanner scchoice = new Scanner(System.in);
            char a = scchoice.nextLine().charAt(0);
            if (a == 'Y' || a == 'y') {
                rollnum();
                name();
                bday();
                hometown();
            } else
                break;
        }
        System.out.print("Enter Roll to search for a record: ");
        Scanner scchoice = new Scanner(System.in);
        String roll = scchoice.nextLine();

        System.out.println();
        try {
            File myObjj = new File("student.txt");
            Scanner myReader = new Scanner(myObjj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                if (data.contains(roll))
                    System.out.println(data);
                else
                    continue;
            }
            myReader.close();
        } catch (Exception e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    static void rollnum() {
        try {
            FileWriter fstream = new FileWriter("student.txt", true);
            BufferedWriter out = new BufferedWriter(fstream);
            System.out.print("Enter Roll: ");
            Scanner scroll = new Scanner(System.in);
            out.write(scroll.nextLine() + " ");
            out.close();
            System.out.println("Successfully wrote roll number to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

    static void name() {
        try {
            FileWriter fstream = new FileWriter("student.txt", true);
            BufferedWriter out = new BufferedWriter(fstream);
            System.out.print("Enter Name: ");
            Scanner scroll = new Scanner(System.in);
            out.write(scroll.nextLine() + " ");
            out.close();
            System.out.println("Successfully wrote name of Student to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

    static void bday() {
        try {
            FileWriter fstream = new FileWriter("student.txt", true);
            BufferedWriter out = new BufferedWriter(fstream);
            System.out.print("Enter Birthday: ");
            Scanner scroll = new Scanner(System.in);
            out.write(scroll.nextLine() + " ");
            out.close();
            System.out.println("Successfully wrote birth day to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }

    static void hometown() {
        try {
            FileWriter fstream = new FileWriter("student.txt", true);
            BufferedWriter out = new BufferedWriter(fstream);
            System.out.print("Enter HomeTown: ");
            Scanner scroll = new Scanner(System.in);
            out.write(scroll.nextLine() + "\n");
            out.close();
            System.out.println("Successfully wrote home town of student to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

    }
}