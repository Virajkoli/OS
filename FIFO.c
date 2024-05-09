//FIFO
#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int incomingStream[] = {4, 1, 2, 4, 5};
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int pages = sizeof(incomingStream) / sizeof(incomingStream[0]);

    printf("Incoming\tFrame 1\tFrame 2\tFrame 3\n");
    
    for (int i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1; // Initialize frames with -1
    }

    for (int i = 0; i < pages; i++) {
        int pageFound = 0;

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (incomingStream[i] == frames[j]) {
                pageFound = 1;
                break;
            }
        }

        if (!pageFound) {
            pageFaults++;

            if (pageFaults <= MAX_FRAMES) {
                frames[pageFaults - 1] = incomingStream[i];
            } else {
                for (int j = 0; j < MAX_FRAMES; j++) {
                    if (frames[j] == -1) {
                        frames[j] = incomingStream[i];
                        break;
                    }
                }
            }
        }

        printf("%d\t\t", incomingStream[i]);

        for (int j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] != -1) {
                printf("%d\t\t", frames[j]);
            } else {
                printf("-\t\t");
            }
        }

        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}
