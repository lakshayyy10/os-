#include <stdio.h>

struct Process {
    int id;             // Process ID
    int bt;             // Burst Time
    int priority;       // Priority
    int wt;             // Waiting Time
    int tat;            // Turnaround Time
};

void calculateWaitingTime(struct Process proc[], int n) {
    proc[0].wt = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        proc[i].wt = proc[i - 1].bt + proc[i - 1].wt; // Waiting time is sum of burst time and previous process waiting time
    }
}

void calculateTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].bt + proc[i].wt; // Turnaround time is burst time + waiting time
    }
}

void findAvgTime(struct Process proc[], int n) {
    int total_wt = 0, total_tat = 0;

    // Calculate waiting time and turnaround time
    calculateWaitingTime(proc, n);
    calculateTurnaroundTime(proc, n);

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }

    // Calculate average waiting time and average turnaround time
    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

void sortByPriority(struct Process proc[], int n) {
    struct Process temp;
    // Sort processes by priority (ascending order of priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                // Swap the processes
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void printProcessDetails(struct Process proc[], int n) {
    printf("Process ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].bt, proc[i].priority, proc[i].wt, proc[i].tat);
    }
}

int main() {
    int n;

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Get the details of each process
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Assign Process ID starting from 1
        printf("\nEnter Burst Time and Priority for Process %d: ", i + 1);
        scanf("%d %d", &proc[i].bt, &proc[i].priority);
    }

    // Sort processes based on priority
    sortByPriority(proc, n);

    // Print process details
    printProcessDetails(proc, n);

    // Calculate and print average waiting time and turnaround time
    findAvgTime(proc, n);

    return 0;
}
