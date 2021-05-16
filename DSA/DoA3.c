//  DoA Assignment1     binarySearch using Divide and conquer
//  Created by Ajit Kumar on May16//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

void swap(int* a,int* b)                //function to swap two elements
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int ray[],int low,int high)
{
    /*
     This function takes last element as pivot, places the pivot element at its correct
     position in sorted array, and places all smaller (smaller than pivot) to left
     of pivot and all greater elements to right of pivot.
     */
    int pivot = ray[high];              //pivot
    int i = low-1;                      //index of smaller element
    for(int j=low;j <= high-1;j++)
    {
        if(ray[j] < pivot)              //if current element is smaller then the pivot
        {
            i++;                        //increment index of smaller elements
            swap(&ray[i],&ray[j]);
        }
    }
    swap(&ray[i+1],&ray[high]);
    return (i+1);
}

void quickSort(int ray[],int low,int high)          //low --> starting index
{                                                   //high --> ending index
    if(low<high)
    {
        int pi = partition(ray,low,high);           //pi is partitioning index
        
        quickSort(ray,low,pi-1);                    //separetely sort elements before
        quickSort(ray,pi+1,high);                   //partition and after partition
    }
}

void printArray(int ray[],int n)            //function to print an array
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
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&ray[i]);
    
    quickSort(ray,0,n-1);
    
    printf("Sorted array is:\n");
    printArray(ray,n);
    
    return 0;
}
