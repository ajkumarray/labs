package assignment2;
import java.util.*;
//Assignment 2.1 OPD Lab

/**
 * @author ajkumarray
 */

public class Assignment2 {
    public static void maxInray(int [] ray,int n) {         //to find largest and second largest element in array
        int max = Integer.MIN_VALUE;
        int max2 = Integer.MIN_VALUE;
        for(int i=0;i<n;i++)
        {
            if(ray[i]>max)
            {
                max2 = max;
                max = ray[i];
            }
            else {
                if(ray[i]>max2 && ray[i]!=max)
                    max2 = ray[i];
            }
        }
        System.out.println("The largest element is: "+max+" and second largest element is: "+max2);
    }
    
    public static void minInray(int [] ray,int n) {         //to find smallest and second smallest element in array
        int min = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;
        for(int i=0; i<n; i++)
        {
            if(ray[i]<min)
            {
                min2 = min;
                min = ray[i];
            }
            else
                if(ray[i]<min2 && ray[i]!=min)
                    min2=ray[i];
        }
        System.out.println("The smallest element is: "+min+" and second smallest element is: "+min2);
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int num = scan.nextInt();
        if(num<2)
        {
            System.out.println("Invalid input.");
            System.exit(0);
        }
        int[] ray = new int[num];
        System.out.print("Enter elements: ");
        for(int i=0; i<num; i++)            //reading elements
            ray[i] = scan.nextInt();
        maxInray(ray,num);
        minInray(ray,num);
        
        /*
        Arrays.sort(ray);
        System.out.println("The largest element is: "+ray[num-1]+" and second largest element is: "+ray[num-2]);
        System.out.println("The smallest element is: "+ray[0]+" and second smallest element is: "+ray[1]);
        */
        
    }
}
