//  DSLab Assignment13          linearSearch

#include <stdio.h>
#include <stdlib.h>

int linearSearch(int ray[],int n,int num)       //function for linear search
{
    for(int i=0;i<n;i++)
    {
        if(ray[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    int ray[n];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&ray[i]);
    
    int num;
    printf("Enter element to be searched: ");
    scanf("%d",&num);
    
    int found = linearSearch(ray, n, num);
    (found == -1) ? printf("Element is not present in array\n") : printf("Element is present at position %d\n",found+1);
    
    return 0;
}
