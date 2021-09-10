//  DSLab Assignment8       stackUsingLinkedList

#include <stdio.h>
#include <stdlib.h>

struct node{              //declaration of node
    int data;
    struct node* next;
};

struct node *head=NULL;

void push()                         //function to push values in stack
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

void display(struct node *last)         //function to display elements of stack
{
    if(head==NULL)
        printf("Stack is empty.\n");
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

void pop()                          //function to pop/delete values from stack
{
    struct node *temp;
    if(head==NULL)
        printf("Stack underflow\n");
    else
    {
        if(head->next==NULL)
        {
            printf("%d is deleted\n",head->data);
            head=NULL;
        }
        else
        {
            temp=head;
            while(temp->next->next!=NULL)
                temp=temp->next;
            printf("%d is deleted\n",temp->next->data);
            free(temp->next);
            temp->next=NULL;
        }
    }
}

int main()
{
    int n;
    printf("1. Push \t2. Pop \t3. Display \t4. Exit\n");
    for(;;)
    {
        printf("Enter your response: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: display(head);
                break;
            case 4: exit(0);
        }
    }
}
