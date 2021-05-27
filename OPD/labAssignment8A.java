//OPD Lab Assignment 8A

import java.io.*;
import java.util.*;

public class labAssignment8A {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String[] name = new String[10];
        int[] roll = new int[10];
        int i = 0, j;
        System.out.println("Enter the details of Student");
        while (i < 10) {
            System.out.print("Enter Roll number of Student " + (i + 1) + ": ");
            roll[i] = in.nextInt();
            System.out.print("Enter Name of Student " + (i + 1) + ": ");
            name[i] = in.next();
            i++;
        }
        System.out.println("Enter the index of the student of whom you want to see deatils of: ");
        j = in.nextInt();
        try {
            System.out.println("Roll number: " + roll[j]);
            System.out.println("Name: " + name[j]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("You have entered an invalid index resulting in Array index Out of Bound");
        }
    }
}
