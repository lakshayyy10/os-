#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    int total_bt = 0;
    for (int i = 0; i < n; i++) {
        total_bt += bt[i];
    }
    int completed[n];
    int min_index, min_bt, time = 0, completed_count = 0;

    while (completed_count < n) {
        min_index = -1;
        min_bt = 9999;
        for (int i = 0; i < n; i++) {
            if (completed[i] == 0 && bt[i] < min_bt && total_bt >= time) {
                min_bt = bt[i];
                min_index = i;
            }
        }
        if (min_index != -1) {
            time += bt[min_index];
            completed[min_index] = 1;
            completed_count++;
            wt[min_index] = time - bt[min_index];
        } else {
            time++;
        }
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAverageTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("Processes Burst Time Waiting Time Turnaround Time\n");
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf(" %d ", i + 1);
        printf(" %d ", bt[i]);
        printf(" %d ", wt[i]);
        printf(" %d\n", tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {6, 8, 7, 3};
    
    findAverageTime(processes, n, burst_time);

    return 0;
}
