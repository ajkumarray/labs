//   DoA Assignment7        single source shortest path by Dijkstra's algorithm
//  here vertex 0 is considered as source node

#include <stdio.h>
#include <limits.h>

int vertex;

void printSolution(int dist[])      //function to print the distance array
{
    printf("Vertex \t Distance from source: \n");
    for(int i = 0; i < vertex; i++)
        printf("%d \t\t %d \n", i, dist[i]);
}

int minDistance(int dist[], int sptSet[])   //function to find vertex with minimum distance value
{
    int min = INT_MAX, min_index;
    
    for(int v = 0; v < vertex; v++)
        if(sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    
    return min_index;
}

void dijkstra(int graph[vertex][vertex], int src)
{
    int dist[vertex];               //contains distance of nodes from src node
    int sptSet[vertex];             //to keep track of nodes added into shortest path tree
    
    for(int i = 0; i < vertex; i++) //initializing all distance as infinity and no node added
    {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    
    dist[src] = 0;                  //distance of src node from itself is 0
    
    //finding shortest path for all vertices
    for(int count = 0;count < vertex - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for(int v = 0; v < vertex; v++)
            if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printSolution(dist);            //printing the distance array
}

int main(int args, const char * argv[])
{
    printf("Enter number of vertex: ");
    scanf("%d",&vertex);
    int graph[vertex][vertex];
    printf("Enter the cost matrix:\n");
    for(int i = 0; i < vertex; i++)
        for(int j = 0; j < vertex; j++)
            scanf("%d",&graph[i][j]);
    int src = 0;                        //src is the source node
    dijkstra(graph,src);
    return 0;
}





