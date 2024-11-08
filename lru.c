#include <stdio.h>
#include <stdlib.h>



#define MAX_PAGES 100

#define MAX_FRAMES 100     



// Function prototypes

void FIFO(int pages[], int n, int frames);

void LRU(int pages[], int n, int frames);

void LFU(int pages[], int n, int frames);



int main() {

    int pages[MAX_PAGES];

    int n, frames;



    printf("Enter number of pages: ");

    scanf("%d", &n);

    printf("Enter page numbers:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d", &pages[i]);

    }

    printf("Enter number of frames: ");

    scanf("%d", &frames);



    printf("\nFIFO Page Replacement:\n");

    FIFO(pages, n, frames);

    printf("\nLRU Page Replacement:\n");

    LRU(pages, n, frames);

    printf("\nLFU Page Replacement:\n");

    LFU(pages, n, frames);



    return 0;

}



void FIFO(int pages[], int n, int frames) {

    int frame[MAX_FRAMES], front = 0, count = 0, hit = 0;

    for (int i = 0; i < frames; i++) {

        frame[i] = -1; // Initialize frame

    }



    for (int i = 0; i < n; i++) {

        int page = pages[i];

        int found = 0;



        // Check if page is already in frame

        for (int j = 0; j < frames; j++) {

            if (frame[j] == page) {

                found = 1;

                hit++;

                break;

            }

        }



        if (!found) {

            frame[front] = page; // Replace page

            front = (front + 1) % frames; // Move to next frame

            count++;

        }

    }



    printf("Total page faults: %d\n", count - hit);

}



void LRU(int pages[], int n, int frames) {

    int frame[MAX_FRAMES], lastUsed[MAX_FRAMES], count = 0, hit = 0;

    for (int i = 0; i < frames; i++) {

        frame[i] = -1; // Initialize frame

    }



    for (int i = 0; i < n; i++) {

        int page = pages[i];

        int found = 0, lruIndex = 0, minTime = i;



        // Check if page is already in frame

        for (int j = 0; j < frames; j++) {

            if (frame[j] == page) {

                found = 1;

                hit++;

                break;

            }

        }



        if (!found) {

            // Find the LRU page

            for (int j = 0; j < frames; j++) {

                if (frame[j] == -1) {

                    lruIndex = j; // If there is empty space

                    break;

                }

                if (lastUsed[j] < minTime) {

                    minTime = lastUsed[j];

                    lruIndex = j;

                }

            }



            frame[lruIndex] = page; // Replace page

            lastUsed[lruIndex] = i; // Update last used time

            count++;

        } else {

            lastUsed[i % frames] = i; // Update last used time for existing page

        }

    }



    printf("Total page faults: %d\n", count - hit);

}



void LFU(int pages[], int n, int frames) {

    int frame[MAX_FRAMES], freq[MAX_FRAMES] = {0}, count = 0, hit = 0;



    for (int i = 0; i < frames; i++) {

        frame[i] = -1; // Initialize frame

    }



    for (int i = 0; i < n; i++) {

        int page = pages[i];

        int found = 0, minFreq = 1000, lfuIndex = -1;



        // Check if page is already in frame

        for (int j = 0; j < frames; j++) {

            if (frame[j] == page) {

                found = 1;

                hit++;

                freq[j]++;

                break;

            }

        }



        if (!found) {

            // Find the LFU page

            for (int j = 0; j < frames; j++) {

                if (frame[j] == -1) {

                    lfuIndex = j; // If there is empty space

                    break;

                }

                if (freq[j] < minFreq) {

                    minFreq = freq[j];

                    lfuIndex = j;

                }

            }



            frame[lfuIndex] = page; // Replace page

            freq[lfuIndex] = 1; // Initialize frequency for new page

            count++;

        }

    }



    printf("Total page faults: %d\n", count - hit);

}