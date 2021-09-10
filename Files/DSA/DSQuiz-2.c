//  DSLab Quiz2      BST insertion and search

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node         //node definition
{
    int value;
    struct node *left, *right;
};

struct node* createNode(int value)      //function to create a new BST node
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->value = value;
    temp->left = temp->right = NULL;
    
    return temp;
}

void printBST(struct node* root)        //function to print BST in inorder traversal
{
    if(root != NULL)
    {
        printBST(root->left);
        printf("%d->", root->value);
        printBST(root->right);
    }
}

struct node* insert(struct node* node, int value)       //function to insert new node in BST
{
    if(node == NULL)
        return createNode(value);
    
    if(value < node->value)
        node->left = insert(node->left, value);
    else
        if(value > node->value)
            node->right = insert(node->right, value);
    
    return node;
}

void searchInorder(struct node* node, int value)        //function for inorder search
{
    if(node == NULL)
        return;
    searchInorder(node->left, value);
    if(node->value == value)
    {
        printf("Element found in BST\n");
        return;
    }
    searchInorder(node->right, value);
}

void searchPreorder(struct node* node, int value)       //function for preorder search
{
    if(node == NULL)
        return;
    if(value == node->value)
    {
        printf("Element found in BST\n");
        return;
    }
    searchPreorder(node->left, value);
    searchPreorder(node->right, value);
}

void searchPostorder(struct node* node, int value)      //function for postorder search
{
    if(node == NULL)
        return;
    searchPostorder(node->left, value);
    searchPostorder(node->right, value);
    if(value == node->value)
    {
        printf("Element found in BST\n");
        return;
    }
}

int main()
{
    struct node* root = NULL;
    int value;
    printf("Enter the root element: ");
    scanf("%d",&value);
    root = insert(root, value);
    for(;;)
    {
        int n;
        printf("1. Enter new node \t2. Search element using In-order \t3. Serach element using Pre-order \t4. Search element using Post-order \t5. Print BST \t6. Exit\n");
        printf("Enter your response: ");
        scanf("%d", &n);
        
        switch(n)
        {
            case 1: printf("Enter value of node to be entered: ");
                scanf("%d", &value);
                insert(root, value);
                break;
            case 2: printf("Enter element to be searched: ");
                scanf("%d", &value);
                searchInorder(root, value);
                break;
            case 3: printf("Enter element to be searched: ");
                scanf("%d", &value);
                searchPreorder(root, value);
                break;
            case 4: printf("Enter element to be searched: ");
                scanf("%d", &value);
                searchPostorder(root, value);
                break;
            case 5: printf("BST contains: ");
                printBST(root);
                printf("END\n");
                break;
            default: exit(0);
        }
    }
    return 0;
}
