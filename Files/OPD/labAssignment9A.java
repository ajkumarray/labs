//  OPD Lab Assignment 9A

import java.io.*;
import java.util.*;

public class labAssignment9A {
    public static void main(String[] args) throws IOException {

        Scanner scan = new Scanner(System.in);

        System.out.print("Enter the name of source file: ");
        String fileSource = scan.nextLine();

        System.out.print("Enter the name of destination file: ");
        String fileDestination = scan.nextLine();

        System.out.print("Enter the character to be counted: ");
        char word = scan.nextLine().charAt(0);

        File filein = new File(fileSource); // input/source file
        File fileout = new File(fileDestination); // output/destination file

        BufferedReader reader = new BufferedReader(new FileReader(filein)); // buffered reader
        BufferedWriter writer = new BufferedWriter(new FileWriter(fileout)); // buffered writer

        int ch;
        int charCount = 0;
        do {
            ch = reader.read(); // reading from file

            writer.write(ch); // writing into the destination file

            if (ch >= 65 && ch <= 90) // handling case sensitivity
                ch += 32;

            if (word >= 65 && word <= 90)
                word += 32;

            if (ch == word)
                charCount++;
        } while (ch != -1);

        System.out.println("File " + filein + " has " + charCount + " instance of letter " + word + ".");
        System.out.println(filein + " has been copied to " + fileout);

        reader.close();
        writer.close();
        scan.close();
    }
}