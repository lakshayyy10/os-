#include <stdio.h>

struct Process {
    int id;             // Process ID
    int bt;             // Burst Time
    int wt;             // Waiting Time
    int tat;            // Turnaround Time
};

void calculateWaitingTime(struct Process proc[], int n, int quantum) {
    int remaining_bt[n];
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = proc[i].bt; // Copy burst time to remaining burst time
        proc[i].wt = 0; // Initialize waiting time to 0
    }

    int t = 0; // Time
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                done = 0; // If there are processes left to execute
                if (remaining_bt[i] > quantum) {
                    t += quantum;
                    remaining_bt[i] -= quantum;
                } else {
                    t += remaining_bt[i];
                    proc[i].wt = t - proc[i].bt;
                    remaining_bt[i] = 0;
                }
            }
        }
        if (done == 1) break; // Exit loop when all processes are done
    }
}

void calculateTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt; // Turnaround Time = Burst Time + Waiting Time
    }
}

void findAvgTime(struct Process proc[], int n, int quantum) {
    int total_wt = 0, total_tat = 0;

    // Calculate waiting time and turnaround time
    calculateWaitingTime(proc, n, quantum);
    calculateTurnaroundTime(proc, n);

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }

    // Calculate and print average waiting time and average turnaround time
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

void printProcessDetails(struct Process proc[], int n) {
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].bt, proc[i].wt, proc[i].tat);
    }
}

int main() {
    int n, quantum;

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Get the details of each process
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Assign Process ID starting from 1
        printf("\nEnter Burst Time for Process %d: ", i + 1);
        scanf("%d", &proc[i].bt);
    }

    // Get the time quantum for Round Robin
    printf("\nEnter Time Quantum: ");
    scanf("%d", &quantum);

    // Print process details
    printProcessDetails(proc, n);

    // Calculate and print average waiting time and turnaround time
    findAvgTime(proc, n, quantum);

    return 0;
}
