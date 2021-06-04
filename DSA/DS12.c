//  DSLab Assignment12      AVL tree insertion and deletion

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value, height;
    struct Node *left, *right;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node *node)
{
    if(node == NULL)
        return 0;
    
    return node->height;
}

struct Node* createNode(int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = node->right = NULL;
    node->height = 1;
    
    return node;
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

int getBalance(struct Node *node)
{
    if(node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* insert(struct Node* node, int value)
{
    if(node == NULL)
        return (createNode(value));
    
    if(value < node->value)
        node->left = insert(node->left, value);
    else
        if(value > node->value)
            node->right = insert(node->right, value);
    else
        return node;
    
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    
    if(balance > 1 && value < node->left->value)
        return rightRotate(node);
    
    if(balance < -1 && value > node->right->value)
        return leftRotate(node);
    
    if(balance > 1 && value > node->left->value)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    if(balance < -1 && value < node->right->value)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

struct Node * minNode(struct Node* node)
{
    struct Node* temp = node;
    while(temp->left != NULL)
        temp = temp->left;
    
    return temp;
}

struct Node* deleteNode(struct Node* root, int value)
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
        if((root->left == NULL) || (root->right == NULL))
        {
            struct Node *temp = root->left ? root->left : root->right;
            
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct Node* temp = minNode(root->right);
            
            root->value = temp->value;
            
            root->right = deleteNode(root->right, temp->value);
        }
    }
    if(root == NULL)
        return root;
    
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    
    if(balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    
    if(balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    if(balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    
    if(balance -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

void printPreOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d->",root->value);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

int main(int argc, const char * argv[]) {
    struct Node *root = NULL;
    int value;
    printf("Enter the root element: ");
    scanf("%d",&value);
    root = insert(root, value);
    for(;;)
    {
        int n;
        printf("1. Enter new node \t2. Delete a node \t3. Print Preorder traversal of AVL Tree \t4. Exit\n");
        printf("Enter your response: ");
        scanf("%d", &n);
        
        switch(n)
        {
            case 1: printf("Enter value of node to be entered: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2: printf("Enter value of node to be deleted: ");
                scanf("%d", &value);
                printf("%d is deleted\n",value);
                deleteNode(root, value);
                break;
            case 3: printf("Preorder traversal of AVL Tree: ");
                printPreOrder(root);
                printf("END\n");
                break;
            case 4: exit(0);
        }
    }
    return 0;
}
