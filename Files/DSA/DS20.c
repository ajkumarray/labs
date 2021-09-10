//  DSLab Assignment20              heapSort

#include <stdio.h>

void swap(int* a,int* b)                //function to swap two elements
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int ray[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if(left < n && ray[left] > ray[largest])
        largest = left;
    
    if(right < n && ray[right] > ray[largest])
        largest = right;
    
    if(largest != i)
    {
        swap(&ray[i], &ray[largest]);
        heapify(ray, n, largest);
    }
}

void heapSort(int ray[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(ray, n, i);
    
    for(int i = n - 1; i > 0; i--)
    {
        swap(&ray[0], &ray[i]);
        heapify(ray, i, 0);
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
    
    heapSort(ray, n);
    
    printf("Sorted array is:\n");
    printArray(ray,n);
    
    return 0;
}
