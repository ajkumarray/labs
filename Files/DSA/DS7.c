//  DSLab Assignment7       doubleLinkedList

#include <stdio.h>
#include <stdlib.h>

struct node{              //declaration of node
    int data;
    struct node* next;
    struct node* prev;
};

struct node *head=NULL;

void create()                   //function to create the list
{
    struct node *last;
    char c;int val;
    do
    {
        printf("Enter value to be inserted: ");
        scanf("%d",&val);
        if(head==NULL)
        {
            head=(struct node *)malloc(sizeof(struct node));
            head->data=val;
            head->next=NULL;
            head->prev=NULL;
        }
        else
        {
            last=head;
            while(last->next!=NULL)
                last=last->next;
            last->next=(struct node *)malloc(sizeof(struct node));
            last->next->data=val;
            last->next->next=NULL;
            last->next->prev=last;
        }
        printf("Do you want to continue?(y/n): ");
        fflush(stdin);
        scanf("%c",&c);
    }
    while(c=='y');
}

void insert(struct node *last)              //function to insert elements in list
{
    int val,pos;
    struct node *temp;
    printf("Enter the position at which value will be inserted: ");
    scanf("%d",&pos);
    printf("Enter value to be inserted: ");
    scanf("%d",&val);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=NULL;
    temp->prev=NULL;
    
    if(pos==1)
    {
        temp->next=head;
        last->prev=temp;
        head=temp;
        temp->prev=NULL;
    }
    else
    {
        pos--;
        while(pos!=1)
        {
            last=last->next;
            pos--;
        }
        if(last->next==NULL)
        {
            temp->next=last->next;
            last->next=temp;
            temp->prev=last;
        }
        else
        {
            temp->next=last->next;
            last->next=temp;
            temp->next->prev=temp;
            temp->prev=last;
        }
    }
}

void display(struct node *last)                 //function to display elements of list
{
    if(head==NULL)
        printf("Linked list is empty.\n");
    else
    {
        printf("List contains: ");
        while(last!=NULL)
        {
            printf("%d->",last->data);
            last=last->next;
        }
        printf("END\n");
    }
}

void delet(struct node *last)                   //function to delete elements of list
{
    int pos;
    struct node *temp;
    if(head==NULL)
        printf("List is empty.\n");
    else
    {
        printf("Enter the position of data to be deleted: ");
        scanf("%d",&pos);
        if(pos==1)
        {
            printf("%d is deleted\n",head->data);
            head=head->next;
            free(last);
            head->prev=NULL;
        }
        else
        {
            pos--;
            while(pos!=1)
            {
                last=last->next;
                pos--;
            }
            if(last->next->next==NULL)
            {
                temp=last->next;
                printf("%d is deleted\n",temp->data);
                last->next=NULL;
                free(temp);
            }
            else
            {
                temp=last->next;
                printf("%d is deleted\n",temp->data);
                last->next=temp->next;
                free(temp);
                last->next->prev=last;
            }
        }
    }
}

int main()
{
    int n;
    printf("1.Create \t2. Insert \t3. Display \t4. Delete \t5. Exit\n");
    for(;;)
    {
        printf("Enter your response: ");
        scanf("%d",&n);
        switch(n)
        {
            case 1: create();
                break;
            case 2: insert(head);
                break;
            case 3: display(head);
                break;
            case 4: delet(head);
                break;
            case 5: exit(0);
        }
    }
}
