//  DoA Assignment4     mergeSort using Divide and Conquer
#include <stdio.h>
#include <stdlib.h>

void merge(int ray[],int low,int mid,int high)          //merges two subarrays of ray[].
{
    int n1 = mid-low+1;         //first subarray is L[low ... mid]
    int n2 = high-mid;          //second subarray is R[mid+1 ... high]
    
    int L[n1],R[n2];            //creating the two temp arrays
    
    for(int i=0;i<n1;i++)       //copy data to temp arrays
        L[i] = ray[low+i];
    for(int j=0;j<n2;j++)
        R[j] = ray[mid+1+j];
                                //merge the temp arrays back into ray[low ... high]
    int i=0;                    //initial index of first subarray
    int j=0;                    //initial index of second subarray
    int k=low;                  //initial index of merged subarray
    while(i<n1 && j<n2)
    {
        if(L[i] <= R[j])
        {
            ray[k] = L[i];
            i++;
        }
        else
        {
            ray[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)                 //copy the remaining elements of L[], if there any
    {
        ray[k] = L[i];
        i++;
        k++;
    }
    
    while(j<n2)                 //copy the remaining elements of R[], if there any
    {
        ray[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int ray[],int low,int high)
{
    if(low<high)
    {
        int mid = low + (high-low)/2;           //same as (low+high)/2, but avoids overflow for large values
        
        mergeSort(ray,low,mid);                 //sort first and second halves
        mergeSort(ray,mid+1,high);
        
        merge(ray,low,mid,high);
    }
}
void printArray(int ray[],int n)                //function to print an array
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
    
    printf("Given array is:\n");
    printArray(ray,n);
    
    mergeSort(ray,0,n-1);
    
    printf("Sorted array is:\n");
    printArray(ray,n);
    
    return 0;
}
