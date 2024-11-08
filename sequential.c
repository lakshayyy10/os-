#include <stdio.h>
#include <string.h>



#define DISK_SIZE 10  // Define the size of the disk



// Define a File structure

typedef struct {

    char name[10];   // Name of the file

    int start;       // Starting block of the file

    int length;      // Number of blocks occupied by the file

} File;



// Disk blocks - initialized to NULL to indicate free blocks

char disk_blocks[DISK_SIZE][10];



// Function to initialize disk blocks to "Free"

void initialize_disk() {

    for (int i = 0; i < DISK_SIZE; i++) {

        strcpy(disk_blocks[i], "Free");

    }

}



// Function to allocate a file on the disk

int allocate_file(File file) {

    // Check if the file can fit in the available disk space

    if (file.start + file.length > DISK_SIZE) {

        printf("Error: Not enough space to allocate file %s\n", file.name);

        return -1;

    }



    // Check if the required blocks are free

    for (int i = file.start; i < file.start + file.length; i++) {

        if (strcmp(disk_blocks[i], "Free") != 0) {

            printf("Error: Block %d is already occupied\n", i);

            return -1;

        }

    }



    // Allocate blocks for the file

    for (int i = file.start; i < file.start + file.length; i++) {

        strcpy(disk_blocks[i], file.name);

    }



    printf("File %s allocated from block %d to block %d\n", file.name, file.start, file.start + file.length - 1);

    return 0;

}



// Function to display the status of each block on the disk

void display_disk_status() {

    printf("\nDisk Status:\n");

    for (int i = 0; i < DISK_SIZE; i++) {

        printf("Block %d: %s\n", i, disk_blocks[i]);

    }

}



// Main function

int main() {

    initialize_disk();  // Initialize the disk blocks



    // Define files

    File file1 = {"File1", 0, 3};  // File1 starts at block 0 and has length 3

    File file2 = {"File2", 3, 4};  // File2 starts at block 3 and has length 4

    File file3 = {"File3", 7, 2};  // File3 starts at block 7 and has length 2



    // Allocate files on the disk

    allocate_file(file1);

    allocate_file(file2);

    allocate_file(file3);



    // Display disk status

    display_disk_status();



    return 0;

}