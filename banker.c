#include <stdio.h>


int main() {

    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int allocation[n][m], max[n][m], available[m], need[n][m], finish[n], safe_sequence[n];
    int count = 0;
    printf("Enter allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    printf("Enter max matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    printf("Enter available resources:\n");
    for (j = 0; j < m; j++)
        scanf("%d", &available[j]);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
        finish[i] = 0;
    }
    while (count < n) {

        int found = 0;

        for (i = 0; i < n; i++) {

            if (finish[i] == 0) {

                int can_allocate = 1;

                for (j = 0; j < m; j++) {

                    if (need[i][j] > available[j]) {

                        can_allocate = 0;

                        break;

                    }

                }

                if (can_allocate) {

                    for (k = 0; k < m; k++)

                        available[k] += allocation[i][k];

                    safe_sequence[count++] = i;

                    finish[i] = 1;

                    found = 1;

                }

            }

        }

        if (found == 0) {

            printf("System is not in a safe state\n");

            return 1;

        }

    }



    printf("System is in a safe state.\nSafe sequence: ");

    for (i = 0; i < n; i++)

        printf("%d ", safe_sequence[i]);

    printf("\n");



    return 0;

}