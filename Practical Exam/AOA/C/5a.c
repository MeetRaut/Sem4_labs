// Prims Algo (Greedy)

#include<stdio.h>
#include<stdlib.h>

// Function to find minimum cost spanning tree using Prim's algorithm
void prims(int n, int cost[10][10]) {
    int i, j, u, v, min, mincost = 0, visited[10], ne = 1;
    
    // Initialize visited array to mark vertices as visited or not
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("\nThe edges considered for MST are:\n");
    visited[0] = 1; // Mark the first vertex as visited

    // Loop until all vertices are visited
    while(ne < n) {
        min = 999; // Initialize minimum cost
        // Find the minimum cost edge that connects visited and unvisited vertices
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                // Check if edge exists and cost is minimum
                if(cost[i][j] < min && visited[i] == 1 && visited[j] == 0) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Print the edge and update minimum cost
        printf("Edge(%d, %d) = %d\n", u + 1, v + 1, min);
        mincost += min;
        visited[v] = 1; // Mark the newly visited vertex
        cost[u][v] = cost[v][u] = 999; // Mark the edge as visited
        ne++; // Increment the number of edges
    }

    printf("\nCost of constructing MST is %d", mincost);
}

int main() {
    int i, j, n, cost[10][10];
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    printf("Cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("At %d, %d: ", i+1, j+1);
            scanf("%d", &cost[i][j]);
            // If cost is 0, replace with a large value (999)
            if (cost[i][j] == 0) {
                cost[i][j] = 999;
            }
        }
    }
    prims(n, cost);
    return 0;
}