#include <stdio.h>

struct Process {
    int pid; // Process ID
    int bt;  // Burst Time
    int art; // Arrival Time
};

// Function to find the waiting time for all processes
void findWaitingTime(struct Process proc[], int n, int wt[]) {
    int rt[n];
    for (int i = 0; i < n; i++){
        rt[i] = proc[i].bt;
    }
    int complete = 0, t = 0, minm = _INT_MAX_;
    int shortest = 0, finish_time;
    int check = 0;
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = 1;
            }
        }
        if (check == 0) {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = _INT_MAX_;
        if (rt[shortest] == 0) {
            complete++;
            check = 0;
            finish_time = t + 1;
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

// Function to calculate average time
void findavgTime(struct Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    printf(" P\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d\t%d\t%d\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);
    }
    printf("\nAverage waiting time = %f", (float)total_wt / (float)n);
    printf("\nAverage turn around time = %f", (float)total_tat / (float)n);
}

// Driver code
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    printf("Enter process details (PID, Burst Time, Arrival Time):\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &proc[i].pid);
        printf("Burst Time: ");
        scanf("%d", &proc[i].bt);
        printf("Arrival Time: ");
        scanf("%d", &proc[i].art);
    }
    findavgTime(proc, n);
    return 0;
}