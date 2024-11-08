#include <stdio.h>
#include <stdlib.h>



void FCFS(int requests[], int n, int head) {

    int totalMovement = 0;

    printf("FCFS Disk Scheduling:\n");

    for (int i = 0; i < n; i++) {

        printf("Move from %d to %d with Seek %d\n", head, requests[i], abs(head - requests[i]));

        totalMovement += abs(head - requests[i]);

        head = requests[i];

    }

    printf("Total Head Movement for FCFS: %d\n\n", totalMovement);

}



void SCAN(int requests[], int n, int head, int disk_size, int direction) {

    int totalMovement = 0;

    int temp, current, i, j;



    // Sort requests

    for (i = 0; i < n - 1; i++) {

        for (j = i + 1; j < n; j++) {

            if (requests[i] > requests[j]) {

                temp = requests[i];

                requests[i] = requests[j];

                requests[j] = temp;

            }

        }

    }



    printf("SCAN Disk Scheduling:\n");



    // SCAN in the specified direction

    if (direction == 1) { // Moving towards end

        for (i = 0; i < n && requests[i] < head; i++); // Find starting point

        for (j = i; j < n; j++) { // Move right

            printf("Move from %d to %d with Seek %d\n", head, requests[j], abs(head - requests[j]));

            totalMovement += abs(head - requests[j]);

            head = requests[j];

        }

        if (head != disk_size - 1) { // Reach end

            printf("Move from %d to %d with Seek %d\n", head, disk_size - 1, abs(head - (disk_size - 1)));

            totalMovement += abs(head - (disk_size - 1));

            head = disk_size - 1;

        }

        for (j = i - 1; j >= 0; j--) { // Move left after reaching end

            printf("Move from %d to %d with Seek %d\n", head, requests[j], abs(head - requests[j]));

            totalMovement += abs(head - requests[j]);

            head = requests[j];

        }

    } else { // Moving towards start

        for (i = n - 1; i >= 0 && requests[i] > head; i--); // Find starting point

        for (j = i; j >= 0; j--) { // Move left

            printf("Move from %d to %d with Seek %d\n", head, requests[j], abs(head - requests[j]));

            totalMovement += abs(head - requests[j]);

            head = requests[j];

        }

        if (head != 0) { // Reach start

            printf("Move from %d to %d with Seek %d\n", head, 0, abs(head - 0));

            totalMovement += abs(head - 0);

            head = 0;

        }

        for (j = i + 1; j < n; j++) { // Move right after reaching start

            printf("Move from %d to %d with Seek %d\n", head, requests[j], abs(head - requests[j]));

            totalMovement += abs(head - requests[j]);

            head = requests[j];

        }

    }



    printf("Total Head Movement for SCAN: %d\n\n", totalMovement);

}



void C_SCAN(int requests[], int n, int head, int disk_size) {

    int totalMovement = 0;

    int temp, i, j;



    // Sort requests

    for (i = 0; i < n - 1; i++) {

        for (j = i + 1; j < n; j++) {

            if (requests[i] > requests[j]) {

                temp = requests[i];

                requests[i] = requests[j];

                requests[j] = temp;

            }

        }

    }



    printf("C-SCAN Disk Scheduling:\n");



    // Move towards the end and wrap around to the beginning

    for (i = 0; i < n && requests[i] < head; i++); // Find starting point

    for (j = i; j < n; j++) { // Move right

        printf("Move from %d to %d with Seek %d\n", head, requests[j], abs(head - requests[j]));

        totalMovement += abs(head - requests[j]);

        head = requests[j];

    }

    if (head != disk_size - 1) { // Reach end

        printf("Move from %d to %d with Seek %d\n", head, disk_size - 1, abs(head - (disk_size - 1)));

        totalMovement += abs(head - (disk_size - 1));

        head = 0;

        printf("Move from %d to %d with Seek %d\n", disk_size - 1, head, disk_size - 1);

        totalMovement += disk_size - 1;

    }

    for (j = 0; j < i; j++) { // Move right from start

        printf("Move from %d to %d with Seek %d\n", head, requests[j], abs(head - requests[j]));

        totalMovement += abs(head - requests[j]);

        head = requests[j];

    }



    printf("Total Head Movement for C-SCAN: %d\n\n", totalMovement);

}



int main() {

    int n, head, disk_size, direction;

    printf("Enter number of requests: ");

    scanf("%d", &n);

    int requests[n];

    printf("Enter the requests: ");

    for (int i = 0; i < n; i++)

        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");

    scanf("%d", &head);

    printf("Enter disk size: ");

    scanf("%d", &disk_size);

    printf("Enter SCAN direction (1 for high, 0 for low): ");

    scanf("%d", &direction);



    FCFS(requests, n, head);

    SCAN(requests, n, head, disk_size, direction);

    C_SCAN(requests, n, head, disk_size);



    return 0;

}