package assignment2;
import java.util.*;

//Assignment 2.2 OPD Lab
/**
 * @author ajkumarray
 */

public class Assignment2b {
    public static void freqCount(int [] ray,int n)      //frequency counter
    {
        int maxCount=0,ans=-1;
        for(int i=0; i<n; i++)
        {
            int count=1;
            for(int j=i+1; j<n; j++)
            {
                if(ray[j] == ray[i])
                    count++;
            }
            if(maxCount<count)
            {
                maxCount=count;
                ans=ray[i];
            }
        }
        System.out.println("The most frequent element is "+ans+" occurred "+maxCount+" times.");
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int num = scan.nextInt();
        int[] ray = new int[num];
        System.out.print("Enter elements: ");
        for(int i=0; i<num; i++)            //reading elements
            ray[i] = scan.nextInt();
        freqCount(ray,num);                 //frequency counter
    }
}
