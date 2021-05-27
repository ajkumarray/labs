//  DSLab Assignment9       queueUsingLinkedList

#include <stdio.h>
#include <stdlib.h>

struct node{              //declaration of node
    int data;
    struct node* next;
};

struct node *head=NULL;

void insert()                   //function to insert elements in queue
{
    struct node *last;
    int val;
    printf("Enter value to be inserted: ");
    scanf("%d",&val);
    if(head==NULL)
    {
        head=(struct node *)malloc(sizeof(struct node));
        head->data=val;
        head->next=NULL;
    }
    else
    {
        last=head;
        while(last->next!=NULL)
            last=last->next;
        last->next=(struct node *)malloc(sizeof(struct node));
        last->next->data=val;
        last->next->next=NULL;
    }
}

void display(struct node *last)         //function to display elements of queue
{
    if(head==NULL)
        printf("Queue is empty\n");
    else
    {
        while(last!=NULL)
        {
            printf("%d->",last->data);
            last=last->next;
        }
        printf("END\n");
    }
}

void delet()                            //function to delete elements of queue
{
    struct node *temp;
    if(head==NULL)
        printf("Queue underflow\n");
    else
    {
        temp=head;
        printf("%d is deleted\n",head->data);
        head=head->next;
        free(temp);
    }
}

int main()
{
    int n;
    printf("1. Insert \t2. Delete \t3. Display \t4. Exit\n");
    for(;;)
    {
        printf("Enter your response: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: insert();
                break;
            case 2: delet();
                break;
            case 3: display(head);
                break;
            case 4: exit(0);
        }
    }
}
