package assignment1a;
import java.util.*;

//Assignment 1.2 OPD Lab

/**
 * @author ajkumarray
 */

public class Assignment1_B {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);          //object of scanner class
        System.out.print("Enter number: ");
        int number = scan.nextInt();                    //number input
        int sum = getSum(number);                       //calling the getSum() function to get sum of digits
        boolean prime = isPrime(sum);                   //calling isPrime() function to check wheather sum is prime or not
        System.out.println(number+"->"+sum+" is prime: "+prime);
    }
    public static int getSum(int number) {          //function to find sum of digits of input number
        int sum=0;
        while(number != 0) {
            sum = sum + number % 10;
            number = number/10;
        }
        return sum;
    } 
    public static boolean isPrime(int num) {        //checkimg if the sum of digits is prime or not
        if(num <= 1)
            return false;
        for(int i=2;i<= Math.sqrt(num);i++) {
            if(num % i == 0)
                return false;
        }
        return true;
    }
}
