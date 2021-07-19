//  selectionSort
//  Created by Ajit Kumar on March13//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

/*
 *** Selection sort considering ascending order ***
 The Selection Sort algorithm sorts an array by repeatedly finding the minimum element from unsorted part and putting it at the beginning.
 The algorithm maintains two subarrays in a given array.
    1. The subarray which is already sorted.
    2. Remaining subarray which is unsorted.
 In every iteration of selection sort, the minimum element from the unsorted subarray is picked and moved to the sorted subarray.
 
 Time Complexity: O(n^2) as there are two nested loops.
    one in smallest() function and other in traversing the array in selectionSort() function.
 */

#include <stdio.h>
#include <stdlib.h>

int smallest(int ray[],int k,int n)         //find the minimum element in unsorted array
{
    int j = k, s = ray[k];
    for(int i = k+1;i<n;i++)
    {
        if(ray[i] < s)
        {
            s = ray[i];
            j=i;
        }
    }
    return j;
}
void selectionSort(int ray[],int n)         //function to sort an array using selection sort
{
    for(int i=0;i<n;i++)                    //one by one move the boundary of unsorted array
    {
        int j = smallest(ray,i,n);          //find the minimum element in unsorted array
        int temp = ray[i];                  //swapping the minimum found element with first element
        ray[i] = ray[j];
        ray[j] = temp;
    }
}

void printArrray(int ray[],int n)           //function to print an array
{
    for(int i=0;i<n;i++)
        printf("%d ",ray[i]);
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    int ray[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&ray[i]);
    
    selectionSort(ray, n);
    printf("Sorted in ascending order: ");
    printArrray(ray, n);
    
    return 0;
}
