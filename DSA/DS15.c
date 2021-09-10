//  DoA Assignment15      bubbleSort

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int ray[], int n)
{
    for(int i = 0; i < (n - 1); i++)
    {
        int swap = 0;
        for(int j = 0; j < (n - i - 1); j++)
        {
            if(ray[j] > ray[j + 1])
            {
                int temp = ray[j];
                ray[j] = ray[j + 1];
                ray[j + 1] = temp;
                swap = 1;
            }
        }
        if(swap == 0)
            break;
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
    
    bubbleSort(ray, n);
    printf("Sorted in ascending order: ");
    printArrray(ray, n);
    
    return 0;
}
