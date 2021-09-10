//  DSlab Assignment 3  queue using array
#include <stdio.h>
#include <stdlib.h>
#define maximum 5

int ray[maximum],front=0,rear=-1;

void insert(void)        //function to insert values in queue
{
    int v;
    if(rear==(maximum-1))
        printf("\nQueue Overflow\n");
    else
    {
        printf("Enter value to be inserted: ");
        scanf("%d",&v);
        rear++;
        ray[rear]=v;
    }
}

void delet()                //function to delete values from queue
{
    if(front>rear)
        printf("\nQueue underflow\n");
    else
    {
        printf("The value deleted from Queue is %d\n",ray[front]);
        front++;
    }
}

void display()              //function to display values in queue
{
    int i;
    if(front>rear)
        printf("Queue empty\n");
    else
    {
        printf("Queue contains: ");
        for(i=front;i<=rear;i++)
            printf("%d ",ray[i]);
        printf("\n");
    }
}

int main()
{
    int n;
    printf("1. Insert\t2. Delete\t3. Display\t4. Exit\n");
    for(;;)
    {
        printf("Enter your response: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1:insert();
                break;
            case 2:delet();
                break;
            case 3:display();
                break;
            case 4:exit(0);
        }
    }
}
