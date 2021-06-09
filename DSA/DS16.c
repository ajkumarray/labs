//  DSLab Assignment16      insertionSort

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int ray[], int n)        //function to sort an array using insertioSort
{
    for(int i = 0; i < n; i++)
    {
        int temp = ray[i];
        int j = i - 1;
        while(temp < ray[j] && j >= 0)
        {
            ray[j + 1] = ray[j];
            j--;
        }
        ray[j + 1] = temp;
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
    
    insertionSort(ray, n);
    printf("Sorted in ascending order: ");
    printArrray(ray, n);
    
    return 0;
}
