//  DS Assignment1
//  Created by Ajit Kumar on May14//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <stdio.h>
#include <limits.h>

int main(int argc, const char * argv[]) {
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int ray[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d",&ray[i]);
    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(ray[i] < min)
            min = ray[i];
        if(ray[i] > max)
            max = ray[i];
    }
    printf("The maximum element of array: %d\nThe minimum element of array: %d\n",max,min);
    return 0;
}
