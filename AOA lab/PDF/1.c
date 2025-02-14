#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
// Number of vertices in the graph
#define V 9
int minDistance(int dist[], bool sptSet[])
{
// Initialize min value
int min = INT_MAX, min_index;
for (int v = 0; v < V; v++)
if (sptSet[v] == false && dist[v] <= min)
min = dist[v], min_index = v;
return min_index;
}
// A utility function to print the constructed distance arr
void printSolution(int dist[])
{
    printf("Meet Raut\nS21 \n84\n");
    printf("+-------------------------------+-------------------------------+\n"); 
    printf("|             Vertex            |     Distance from Source      |\n");
    printf("+-------------------------------+-------------------------------+\n"); 
    for (int i = 0; i < V; i++)
    {
        printf("|\t\t\t\t%d\t\t\t\t|\t\t\t\t%d\t\t\t\t|\n", i, dist[i]);
        printf("+-------------------------------+-------------------------------+\n");     
    }
}

void dijkstra(int graph[V][V], int src)
    {
    int dist[V]; 
    bool sptSet[V]; 
    for (int i = 0; i < V; i++)
    dist[i] = INT_MAX, sptSet[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
    int u = minDistance(dist, sptSet);
    sptSet[u] = true;
    for (int v = 0; v < V; v++)
    if (!sptSet[v] && graph[u][v]
    && dist[u] != INT_MAX
    && dist[u] + graph[u][v] < dist[v])
    dist[v] = dist[u] + graph[u][v];
    }
    // print the constructed distance array
    printSolution(dist);
}
// driver's code
int main()
{
/* Let us create the example graph discussed above */
int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
// Function call
dijkstra(graph, 0);
return 0;
}