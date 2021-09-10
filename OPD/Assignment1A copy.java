package assignment1a;
import java.util.*;

//Assignment 1.1 OPD Lab

/**
 * @author ajkumarray
 */

public class Assignment1A {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);      //making object of scanner class
        System.out.print("Enter a character: ");
        char var = scan.next().charAt(0);           //character input
        if((var >= 'a' && var <= 'z') || (var >= 'A' && var <= 'Z'))        //checking for "alphabets"
            System.out.println("Alphabet");
        else
            if(var >= '0' && var <= '9')                                        //checking for digits
                System.out.println("Digit");
        else                                                                //special characters
                System.out.println("Special Character");
    }
}