// TSP 

#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices (cities)

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve the TSP using dynamic programming
int tsp(int graph[V][V]) {
    // dp[mask][i] stores the minimum cost to visit all cities in mask ending at city i
    int dp[1 << V][V];

    // Initialize dp array with maximum values
    for (int i = 0; i < (1 << V); i++) {
        for (int j = 0; j < V; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    // Initialize dp for the starting city (city 0)
    dp[1][0] = 0;

    // Iterate over all possible subsets of cities
    for (int mask = 1; mask < (1 << V); mask++) {
        for (int i = 0; i < V; i++) {
            // Check if city i is in the subset represented by mask
            if (mask & (1 << i)) {
                for (int j = 0; j < V; j++) {
                    // Check if city j is not in the subset and there is a direct edge from i to j
                    if (!(mask & (1 << j)) && graph[i][j]) {
                        // Update the minimum cost to visit all cities in the subset ending at city j
                        dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + graph[i][j]);
                    }
                }
            }
        }
    }

    // Find the minimum cost to visit all cities starting and ending at city 0
    int minCost = INT_MAX;
    for (int i = 0; i < V; i++) {
        if (graph[i][0]) {
            minCost = min(minCost, dp[(1 << V) - 1][i] + graph[i][0]);
        }
    }
    
    return minCost;
}

int main() {
    int graph[V][V];

    // Input: Getting the adjacency matrix from the user
    printf("\nEnter the adjacency matrix for size of %d x %d:\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Finding and printing the minimum cost of traversal
    printf("\nMinimum cost of traversal: %d\n", tsp(graph));

    return 0;
}