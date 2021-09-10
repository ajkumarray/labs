//  DS Assignment2
//  Created by Ajit Kumar on May14//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.

#include <stdio.h>    //stack using array
#include <stdlib.h>
#define max 5

int ray[max],top=-1;

void push(void)                     //function to push values in stack
{
    int v;
    if(top==(max-1))
        printf("Stack Overflow.\n");
    else
    {
        printf("Enter value to be pushed: ");
        scanf("%d",&v);
        top++;
        ray[top]=v;
    }
}

void pop(void)                      //function to delete values from stack
{
    if(top==-1)
        printf("Stack Underflow.\n");
    else
    {
        printf("The value deleted from stack is: %d\n",ray[top]);
        top--;
    }
}

void display(void)                  //function to display values in stack
{
    int i;
    if(top==-1)
        printf("Stack Empty.\n");
    else
    {
        printf("Stack contains: ");
        for(i=0;i<=top;i++)
            printf("%d ",ray[i]);
        printf("\n");
    }
}

int main()
{
    int n;
    printf("1. Push\t2. Pop\t3. Display\t4. Exit\n");
    for(;;)
    {
        printf("Enter your response: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:display();
                break;
            case 4:exit(0);
        }
    }
}
