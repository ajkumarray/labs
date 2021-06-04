//  DOA Assignment8         Prim's minimum spanning tree

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
int V;

void printMST(int parent[], int graph[V][V])        //function to print the constructed MST
{
    int minimumCost = 0;
    printf("Edge \tWeight\n");
    for(int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        minimumCost += graph[i][parent[i]];
    }
    printf("Cost of minimum spanning tree is: %d\n",minimumCost);
}

int minKey(int key[], bool mstSet[])        //function to find the vertex with minimum key value, vertices not included in MST
{
    int min = INT_MAX, min_index;
    for(int v = 0; v < V; v++)
        if(mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

void primMST(int graph[V][V])               //function to construct MST
{
    int parent[V];          //array to store constructed MST
    int key[V];             //array to store key value
    bool mstSet[V];         //array to store vertices included in MST
    
    for(int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    
    key[0] = 0;             //first node is always included in MST
    parent[0] = -1;         //first node is always the root of MST
    
    for(int count = 0; count < V-1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        
        for(int v = 0; v < V; v++)
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }
    printMST(parent, graph);
}

int main()
{
    printf("Enter number of vertices: ");
    scanf("%d",&V);
    int graph[V][V];
    printf("Enter cost matrix:\n");
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            scanf("%d",&graph[i][j]);
    primMST(graph);
    return  0;
}
