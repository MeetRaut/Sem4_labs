#include<stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n], i, j;
    for (i = 0; i < n; i++)
        allocation[i] = -1;
    for (i = 0; i < n; i++) {
        int bestIdx = -1;
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[bestIdx] > blockSize[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n], i, j;
    for (i = 0; i < n; i++)
        allocation[i] = -1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {    
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n], i, j;
    for (i = 0; i < n; i++)
        allocation[i] = -1;
    for (i = 0; i < n; i++) {
        int wstIdx = -1;
        for (j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (wstIdx == -1 || blockSize[wstIdx] < blockSize[j])
                    wstIdx = j;
            }
        }
        if (wstIdx != -1) {
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int m, n;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);

    int blockSize[m];
    printf("Enter the sizes of memory blocks:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processSize[n];
    printf("Enter the sizes of processes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    printf("\nFirst Fit:\n");
    firstFit(blockSize, m, processSize, n);

    printf("\nBest Fit:\n");
    bestFit(blockSize, m, processSize, n);

    printf("\nWorst Fit:\n");
    worstFit(blockSize, m, processSize, n);

    return 0;
}