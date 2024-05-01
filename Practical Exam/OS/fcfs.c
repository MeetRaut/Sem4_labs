#include <stdio.h>

void calculateTimes(int n, int bt[], int at[], int wt[], int tat[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
}

void displayResults(int n, int bt[], int at[], int wt[], int tat[]) {
    printf("+---------------------------------------+\n");
    printf("|\tP\t|\tAT\t|\tBT\t|\tWT\t|\tTT\t|\n");
    printf("+=======|=======|=======|=======|=======+\n");
    for (int i = 0; i < n; i++) {
        printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n", i + 1, at[i], bt[i], wt[i], tat[i]);
        if(i != n-1){
            printf("+-------|-------|-------|-------|-------+\n");
        }
    }
    printf("+---------------------------------------+\n");
}

int main() {
    int n;
    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int BT[20], AT[20], WT[20], TT[20];
    printf("Enter the arrival times and burst times of processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
    }
    calculateTimes(n, BT, AT, WT, TT);
    displayResults(n, BT, AT, WT, TT);
    return 0;
}