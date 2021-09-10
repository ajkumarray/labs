//  DSLab Assignment11      BST insertion and deletion

#include <stdio.h>
#include <stdlib.h>

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

struct node* minNode(struct node* node)     //function to find node with minimum value
{
    struct node* temp = node;
    while(temp && temp->left != NULL)
        temp = temp->left;
    
    return temp;
}

struct node* deleteNode(struct node* root, int value)       //function to delete node
{
    if(root == NULL)
        return root;
    
    if(value < root->value)
        root->left = deleteNode(root->left, value);
    else
        if(value > root->value)
            root->right = deleteNode(root->right, value);
    
    else
    {
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else
            if(root->right == NULL)
            {
                struct node* temp = root->left;
                free(root);
                return temp;
            }
        struct node* temp = minNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
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
        printf("1. Enter new node \t2. Delete a node \t3. Print Inorder traversal of BST \t4. Exit\n");
        printf("Enter your response: ");
        scanf("%d", &n);
        
        switch(n)
        {
            case 1: printf("Enter value of node to be entered: ");
                scanf("%d", &value);
                insert(root, value);
                break;
            case 2: printf("Enter value of node to be deleted: ");
                scanf("%d", &value);
                printf("%d is deleted\n",value);
                deleteNode(root, value);
                break;
            case 3: printf("Inorder traversal of BST: ");
                printBST(root);
                printf("END\n");
                break;
            case 4: exit(0);
        }
    }
    return 0;
}
