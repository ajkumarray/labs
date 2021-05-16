//  DoA Assignment1     binarySearch using Divide and conquer
//  Created by Ajit Kumar on May15//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int ray[],int l, int r, int num)
{
    if(r >= l)
    {
        int mid = l + (r - l) / 2;
        
        if(ray[mid] == num)         //if element is present at the middle itself
            return mid;
        
        if(ray[mid] > num)          //if element is smaller than mid
            return binarySearch(ray, l, mid-1, num);
                                    
                                    //if element is larger than mid
        return binarySearch(ray, mid+1, r, num);
    }
    return -1;                      //return -1 if not present
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
    
    int found = binarySearch(ray, 0, n-1, num);
    
    (found == -1) ? printf("Element is not present in array\n") : printf("%d is present at position: %d\n",num, found+1);
    return 0;
}
