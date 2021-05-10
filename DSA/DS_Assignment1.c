//  DS Lab Assignment 1
//
//  Created by Ajit Kumar on May10//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

/*
 Assignment 1
 Program to find the number of elementsin an array.
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int ray[] = {00, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int raySize = sizeof(ray) / sizeof(ray[0]);
    printf("Number of elements in Array is: %d\n",raySize);
    return 0;
}
