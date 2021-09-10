//  DSLab Assignment14      binarySearch

#include <stdio.h>

int binarySearch(int ray[], int n, int num)     //function for binary search
{
    int beg = 0;
    int end = n - 1;
    while(beg <= end)
    {
        int mid = beg + (end - beg) / 2;
        if(ray[mid] == num)
            return mid;
        
        if(ray[mid] < num)
            beg = mid + 1;
        else
            end = mid - 1;
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
    scanf("%d", &num);
    
    int found = binarySearch(ray, n, num);
    (found == -1) ? printf("Element is not present in array\n") : printf("Element is present at position %d\n", found + 1);
    
    return 0;
}
