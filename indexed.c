#include <stdio.h>


#define MAX_FILES 10

#define MAX_BLOCKS 50



int blocks[MAX_BLOCKS]; // Represents the disk blocks (1 means allocated, 0 means free)

int indexBlock[MAX_FILES][MAX_BLOCKS]; // Index blocks for each file

int fileLength[MAX_FILES]; // Length of each file in blocks



void allocateFile(int fileIndex, int length) {

    int allocatedBlocks = 0;

    for (int i = 0; i < MAX_BLOCKS && allocatedBlocks < length; i++) {

        if (blocks[i] == 0) { // Check if block is free

            blocks[i] = 1; // Mark block as allocated

            indexBlock[fileIndex][allocatedBlocks] = i; // Add block to index

            allocatedBlocks++;

        }

    }

    fileLength[fileIndex] = allocatedBlocks;

    if (allocatedBlocks < length) {

        printf("Could only allocate %d blocks for File %d. Disk is full.\n", allocatedBlocks, fileIndex);

    } else {

        printf("Allocated %d blocks for File %d successfully.\n", length, fileIndex);

    }

}



void displayFile(int fileIndex) {

    printf("File %d: ", fileIndex);

    for (int i = 0; i < fileLength[fileIndex]; i++) {

        printf("%d ", indexBlock[fileIndex][i]);

    }

    printf("\n");

}



int main() {

    for (int i = 0; i < MAX_BLOCKS; i++) {

        blocks[i] = 0; // Initialize all blocks as free

    }

    

    int choice, fileIndex, length;

    

    while (1) {

        printf("\n1. Allocate File\n2. Display File Allocation\n3. Exit\nEnter your choice: ");

        scanf("%d", &choice);

        

        switch (choice) {

            case 1:

                printf("Enter File Index (0 to %d): ", MAX_FILES - 1);

                scanf("%d", &fileIndex);

                printf("Enter File Length in Blocks: ");

                scanf("%d", &length);

                if (fileIndex < MAX_FILES && length > 0) {

                    allocateFile(fileIndex, length);

                } else {

                    printf("Invalid file index or length.\n");

                }

                break;

            case 2:

                printf("Enter File Index to display: ");

                scanf("%d", &fileIndex);

                if (fileIndex < MAX_FILES) {

                    displayFile(fileIndex);

                } else {

                    printf("Invalid file index.\n");

                }

                break;

            case 3:

                printf("Exiting program.\n");

                return 0;

            default:

                printf("Invalid choice.\n");

                break;

        }

    }

    return 0;

}