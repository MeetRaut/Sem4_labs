// Dijkstra's algorithm
#include<stdio.h>

// Function to find the minimum of two integers
int minimum(int a, int b) {
    if(a < b) {
        return a;
    } else {
        return b;
    }
}

// Function to print the distances from the source vertex
void printSolution(int distance[], int v) {
    printf("\nVertex          Distance from Source\n");
    for (int i = 0; i < v; i++) {
        printf("%d               %d\n", i, distance[i]);
    }
}

// Dijkstra's algorithm implementation
void dijkstra(int cost[][100], int distance[], int v) {
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            if(cost[i][j] != 0) {
                distance[j] = minimum(distance[j], (distance[i] + cost[i][j]));
            }
        }
    }
    printSolution(distance, v);
}

int main() {
    int v;
    
    // Input: Getting the number of vertices from the user
    printf("\nEnter the number of vertices: ");
    scanf("%d", &v);
    
    int cost[100][100];
    int distance[100];

    // Input: Getting the adjacency matrix from the user
    printf("\nEnter the adjacency matrix:\n");
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            printf("At %d, %d: ", i, j);
            scanf("%d", &cost[i][j]);
        }
    }

    // Initializing distance array to be infinity 
    distance[0] = 0;
    for(int i = 1; i < v; i++) {
        distance[i] = 999; 
    }

    // Applying Dijkstra's algorithm
    dijkstra(cost, distance, v);

    return 0;
}
