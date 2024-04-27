// N Queen

#include <stdio.h>
#include <stdlib.h> // For abs()

int x[100]; // Array to store the column position of queens

// Function to check if a queen can be placed in a given column
int place(int k, int i) {
    int j;
    for (j = 1; j <= k - 1; j++) {
        // Check if there is a queen in the same column or diagonals
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0; // Queen cannot be placed here
    }
    return 1; // Queen can be placed here
}

// Function to find all solutions to the N-queens problem
void Nqueen(int k, int n) {
    int i;
    for (i = 1; i <= n; i++) {
        if (place(k, i)) {
            x[k] = i; // Place queen in this column
            if (k == n) { // All queens are placed
                // Print the solution
                printf("Solution: ");
                for (int j = 1; j <= n; j++) {
                    printf("(%d,%d) ", j, x[j]);
                }
                printf("\n");
            } else {
                Nqueen(k + 1, n); // Place next queen
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input!\n");
        return 1;
    }
    Nqueen(1, n); // Start with placing the first queen
    return 0;
}