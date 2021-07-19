//  quickSort
//  Created by Ajit Kumar on March08//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

/*
 QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
 Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements before x, and put all greater elements after x.
 All this should be done in linear time.
 
 In partition, we start from the leftmost element and keep track of index of smaller elements as i. While traversing, if we find a smaller element, we swap current element with ray[i]. Otherwise we ignore current element.
*/
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
    
    printf("Entered array is:\n");
    printArray(ray,n);
    
    quickSort(ray,0,n-1);
    
    printf("Sorted array is:\n");
    printArray(ray,n);
    
    return 0;
}
