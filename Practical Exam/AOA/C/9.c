// TSP (Dynamic Approach)

#include <stdio.h>
#include <limits.h>

// Function to find the minimum of two integers
int min(int x, int y) {
    return (x < y) ? x : y;
}

// Function to solve the Travelling Salesperson Problem using dynamic programming
int tsp(int n, int graph[][n], int mask, int pos, int dp[][n]) {
    if (mask == ((1 << n) - 1))
        return graph[pos][0];
    if (dp[mask][pos] != -1)
        return dp[mask][pos];
    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(n, graph, mask | (1 << city), city, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

// Main function
int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    int graph[V][V];
    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++)
        for (int j = 0; j < V; j++)
            dp[i][j] = -1;
    printf("Minimum cost for travelling salesman = %d\n", tsp(V, graph, 1, 0, dp));
    return 0;
}