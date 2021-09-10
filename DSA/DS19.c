//  DSLab Assignment19              interpolationSearch

#include <stdio.h>

int interpolationSearch(int ray[], int low, int high, int num)
{
    int pos;
    if(low <= high && num >= ray[low] && num <= ray[high])
    {
        pos = low + (((double) (high - low) / (ray[high] - ray[low])) * (num - ray[low]));
        
        if(ray[pos] == num)
            return pos;
        
        if(ray[pos] < num)
            return interpolationSearch(ray, pos + 1, high, num);
        
        if(ray[pos] > num)
            return interpolationSearch(ray, low, pos - 1, num);
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
    
    int found = interpolationSearch(ray, 0, n - 1, num);
    (found == -1) ? printf("Element is not present in array\n") : printf("Element is found at position %d\n",found+1);
    return 0;
}
