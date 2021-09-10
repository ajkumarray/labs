package assignment2;
import java.util.*;

//Assignment 2.3 OPD Lab

/**
 * @author ajkumarray
 */

public class Assignment2c {
    public static void bubbleSort(int [] ray,int n)         //bubble sort
    {
        int temp;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<(n-i-1); j++)
            {
                if(ray[j] < ray[j+1])
                {
                    temp = ray[j];
                    ray[j] = ray[j+1];
                    ray[j+1] = temp;
                }
            }
        }
        System.out.println("Sorted using Bubble sort.");
        System.out.print("Sorted in descending order:");
        for(int i=0; i<n; i++)
            System.out.print(ray[i]+" ");
    }
    
    public static void insertionSort(int [] ray,int n)          //insertion sort
    {
        for(int i=1; i<n; i++)
        {
            int temp = ray[i];
            int j = i-1;
            while(temp>ray[j] && j>=0)
            {
                ray[j+1] = ray[j];
                j--;
            }
            ray[j+1] = temp;
        }
        System.out.println("Sorted using Insertion sort.");
        System.out.print("Sorted in descending order:");
        for(int i=0; i<n; i++)
            System.out.print(ray[i]+" ");
    }
    
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = scan.nextInt();
        int[] ray = new int[n];
        System.out.print("Enter elements to be sorted: ");
        for(int i=0; i<n; i++)          //reading elements
            ray[i] = scan.nextInt();
        bubbleSort(ray,n);              //bubble sort
        System.out.println("");
        insertionSort(ray,n);           //insertion sort
    }
}
