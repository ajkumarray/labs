//  DOA Quiz1 huffmanCoding
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

struct heapNode
{
    char data;
    unsigned frequency;
    struct heapNode *left, *right;
};

struct minHeap
{
    unsigned size;
    unsigned capacity;
    struct heapNode** array;
};

struct heapNode* newNode(char data, unsigned frequency)
{
    struct heapNode* temp = (struct heapNode*)malloc(sizeof(struct heapNode));
    
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = frequency;
    
    return temp;
}

struct minHeap* createMinHeap(unsigned capacity)
{
    struct minHeap* mHeap = (struct minHeap*)malloc(sizeof(struct minHeap));
    
    mHeap->size = 0;
    mHeap->capacity = capacity;
    mHeap->array = (struct heapNode**)malloc(mHeap->capacity * sizeof(struct heapNode*));
    return mHeap;
}

void swapHeapNode(struct heapNode** a, struct heapNode** b)
{
    struct heapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct minHeap* mHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if(left < mHeap->size && mHeap->array[left]->frequency < mHeap->array[smallest]->frequency)
        smallest = left;
    
    if(right < mHeap->size && mHeap->array[right]->frequency < mHeap->array[smallest]->frequency)
        smallest = right;
    
    if(smallest != idx)
    {
        swapHeapNode(&mHeap->array[smallest], &mHeap->array[idx]);
        minHeapify(mHeap, smallest);
    }
}

int isSizeOne(struct minHeap* mHeap)
{
    return (mHeap->size == 1);
}

struct heapNode* extractMin(struct minHeap* mHeap)
{
    struct heapNode* temp = mHeap->array[0];
    mHeap->array[0] = mHeap->array[mHeap->size - 1];
    
    --mHeap->size;
    minHeapify(mHeap, 0);
    
    return temp;
}

void insertMinHeap(struct minHeap* mHeap, struct heapNode* minHeapNode)
{
    ++mHeap->size;
    int i = mHeap->size - 1;
    
    while(i && minHeapNode->frequency < mHeap->array[(i - 1) / 2]->frequency)
    {
        mHeap->array[i] = mHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    mHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct minHeap* mHeap)
{
    int n = mHeap->size - 1;
    int i;
    for(i = (n - 1) / 2; i >= 0; --i)
        minHeapify(mHeap, i);
}

void printArray(int ray[], int n)
{
    int i;
    for(i = 0; i < n; ++i)
        printf("%d", ray[i]);
    printf("\n");
}

int isLeaf(struct heapNode* root)
{
    return !(root->left) && !(root->right);
}

struct minHeap* createAndBuildMinHeap(char data[], int freq[], int size)
{
    struct minHeap* mHeap = createMinHeap(size);
    
    for(int i = 0; i < size; i++)
        mHeap->array[i] = newNode(data[i], freq[i]);
    
    mHeap->size = size;
    buildMinHeap(mHeap);
    
    return mHeap;
}

struct heapNode* buildHuffmanTree(char data[], int frequency[], int size)
{
    struct heapNode *left, *right, *top;
    struct minHeap* mHeap = createAndBuildMinHeap(data, frequency, size);
    
    while(!isSizeOne(mHeap))
    {
        left = extractMin(mHeap);
        right = extractMin(mHeap);
        
        top = newNode('$', left->frequency + right->frequency);
        
        top->left = left;
        top->right = right;
        
        insertMinHeap(mHeap, top);
    }
    return extractMin(mHeap);
}

void printCodes(struct heapNode* root, int ray[], int top)
{
    if(root->left)
    {
        ray[top] = 0;
        printCodes(root->left, ray, top + 1);
    }
    
    if(root->right)
    {
        ray[top] = 1;
        printCodes(root->right, ray, top + 1);
    }
    
    if(isLeaf(root))
    {
        printf("%c: ",root->data);
        printArray(ray,top);
    }
}

void huffmanCode(char data[], int freq[], int size)
{
    struct heapNode* root = buildHuffmanTree(data, freq, size);
    int ray[MAX_TREE_HT], top = 0;
    printCodes(root, ray, top);
}

int main()
{
    int size;
    printf("Enter number of unique characters: ");
    scanf("%d",&size);
    char ray[size];
    int freq[size];
    for(int i = 0; i < size; i++)
    {
        printf("Enter character and their frequency: ");
        scanf("%s%d", &ray[i],&freq[i]);
    }
    huffmanCode(ray, freq, size);
    
    return 0;
}
