//  DOA Assignment9     Kruskal's minimum spanning tree

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
    graph->V = V;
    graph->E = E;
    
    graph->edge = (struct Edge*)(malloc(sizeof(struct Edge)));
    
    return graph;
}

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if(subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    
    if(subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if(subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void* a, const void* b)        //function to compare two edges according to their weights
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}

void printMST(struct Edge result[], int e)      //function to print result MST
{
    int minimumCost = 0;
    printf("Edge \tWeight\n");
    for(int i = 0; i < e; ++i)
    {
        printf("%d -- %d \t %d \n", result[i].src, result[i].dest, result[i].weight);
        minimumCost += result[i].weight;
    }
    printf("Cost of minimum spanning tree is: %d\n", minimumCost);
}

void kruskalMST(struct Graph* graph)        //  function to construct MST
{
    int V = graph->V;
    struct Edge result[V];      //to store resultant MST
    int e = 0;
    int i = 0;
    
    //  sorting all the edges in non-decreasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    
    struct subset* subsets = (struct subset*)malloc(V * sizeof(struct subset));
    
    for(int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    while(e < V - 1 && i < graph->E)
    {
        struct Edge next_edge = graph->edge[i++];
        
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        if(x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    printMST(result, e);
}

int main()
{
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d",&V);
    printf("Enter number of edges: ");
    scanf("%d",&E);
    struct Graph* graph = createGraph(V, E);
    
     printf("Enter graph data:\n");
    printf("Src Dest Weight\n");
    for(int i = 0; i < E; i++)
    {
        scanf("%d",&graph->edge[i].src);
        scanf("%d",&graph->edge[i].dest);
        scanf("%d",&graph->edge[i].weight);
    }
    kruskalMST(graph);
}
