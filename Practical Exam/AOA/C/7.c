// Floyd Warshall
#include<stdio.h>
#include<stdlib.h>

int cost[10][10], dist[10][10], n;

// Function to find the minimum of two integers
int minimum(int a, int b){
    return (a < b) ? a : b;
}

// Function to find shortest paths between all pairs of vertices
void path(){
    int i, j, k;
    // Loop through all vertices as intermediates
    for(k = 0; k < n; k++){
        // Consider all pairs (i, j) of vertices
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                // Update distance if there's a shorter path through vertex k
                dist[i][j] = minimum(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    int i, j;
    // Input: Getting the number of vertices from the user
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input: Getting the adjacency matrix from the user
    printf("\nEnter the allocation matrix:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];
        }
    }

    // Finding shortest paths
    path();

    // Output: Displaying the final distance matrix
    printf("\nThe final Distance matrix showing the shortest distances between every pair of vertices is:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}