//  DSLab Quiz1       linkedListMerge
//  Created by Ajit Kumar on June01//2021 AD.
//  Copyright © 2021 Ajit Kumar. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Node             //node definition
{
    int data;
    struct Node* next;
};

struct Node* create(struct Node *head)          //function to create a linked list
{
    struct Node* last;
    char c;
    int value;
    do
    {
        printf("Enter value to be inserted: ");
        scanf("%d",&value);
        if(head == NULL)
        {
            head = (struct Node *)malloc(sizeof(struct Node));
            head->data = value;
            head->next = NULL;
        }
        else
        {
            last = head;
            while(last->next != NULL)
                last = last->next;
            last->next = (struct Node *)malloc(sizeof(struct Node));
            last->next->data = value;
            last->next->next = NULL;
        }
        printf("Do you want to continue?(y/n): ");
        fflush(stdin);
        scanf("%c", &c);
    }
    while(c == 'y');
    return head;
}

void display(struct Node *head)             //function to print elements of linked list
{
    if(head == NULL)
        printf("List is empty\n");
    else
    {
        while(head != NULL)
        {
            printf("%d->",head->data);
            head = head->next;
        }
        printf("END\n");
    }
}

struct Node* merge(struct Node *head1, struct Node *head2)          //function to merge two linked lists
{
    struct Node* last = head1;
    while(last->next != NULL)
        last = last->next;
    last->next = head2;
    last = head1;
    return head1;
    
}

int main(int argc, const char * argv[]) {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    printf("Enter values for 1st list:\n");
    head1 = create(head1);
    printf("1st list contains: ");
    display(head1);
    
    printf("Enter values for 2nd list:\n");
    head2 = create(head2);
    printf("2nd list contains: ");
    display(head2);
    
    printf("After Merge:\n");
    head1 = merge(head1, head2);
    display(head1);
    
    return 0;
}
