#include <stdio.h>

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum) {
    // Make a copy of burst times bt[] to store remaining burst times.
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];
    int t = 0; // Current time

    // Keep traversing processes in round robin manner until all of them are not done.
    while (1) {
        int done = 1; // Initialize done as true
        
        // Traverse all processes one by one repeatedly
        for (int i = 0; i < n; i++) {
            // If burst time of a process is greater than 0 then only need to process further
            if (rem_bt[i] > 0) {
                done = 0; // There is a pending process

                // If remaining burst time is greater than quantum, process next quantum time
                if (rem_bt[i] > quantum) {
                    // Increase the value of t i.e. shows how much time a process has been processed
                    t += quantum;
                    // Decrease the burst_time of current process by quantum
                    rem_bt[i] -= quantum;
                } else {
                    // If remaining burst time is smaller than or equal to quantum. Last cycle for this process
                    // Increase the value of t i.e. shows how much time a process has been processed
                    t = t + rem_bt[i];
                    // Waiting time is current time minus time used by this process
                    wt[i] = t - bt[i];
                    // As the process gets fully executed make its remaining burst time = 0
                    rem_bt[i] = 0;
                }
            }
        }
        // If all processes are done
        if (done == 1)
            break;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Function to find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, quantum);

    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("PN\tBT\tWT\tTAT\n");

    // Calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t%d\t%d\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %f\n", (float)total_wt / (float)n);
    printf("Average turn around time = %f\n", (float)total_tat / (float)n);
}

// Driver code
int main() {
    // Input number of processes
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process id's and burst time for each process
    int processes[n], burst_time[n];
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d burst time: ", i + 1);
        scanf("%d", &burst_time[i]);
        processes[i] = i + 1; // Assuming process ID starts from 1
    }

    // Input time quantum
    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Calculate and display average waiting time and turn around time
    findavgTime(processes, n, burst_time, quantum);

    return 0;
}