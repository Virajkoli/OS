//LRU
#include <stdio.h>

#define MAX_FRAMES 3

int isInFrame(int page, int frame[], int occupied) {
    for (int i = 0; i < occupied; i++) {
        if (page == frame[i]) {
            return 1; // Page found in frame
        }
    }
    return 0; // Page not found in frame
}

void printFrames(int frame[], int occupied) {
    for (int i = 0; i < occupied; i++) {
        printf("%d\t\t\t", frame[i]);
    }
}

int main() {
    int incomingStream[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3};
    int n = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int occupied = 0;

    printf("Page\tFrame1\tFrame2\tFrame3\n");

    for (int i = 0; i < n; i++) {
        printf("%d:\t\t", incomingStream[i]);

        if (isInFrame(incomingStream[i], frames, occupied)) {
            printFrames(frames, occupied);
        } else {
            if (occupied < MAX_FRAMES) {
                frames[occupied] = incomingStream[i];
                occupied++;
            } else {
                int index = 0;
                int maxDistance = 0;
                for (int j = 0; j < MAX_FRAMES; j++) {
                    int distance = 0;
                    for (int k = i - 1; k >= 0; k--) {
                        distance++;
                        if (frames[j] == incomingStream[k]) {
                            break;
                        }
                    }
                    if (distance > maxDistance) {
                        maxDistance = distance;
                        index = j;
                    }
                }
                frames[index] = incomingStream[i];
            }
            printFrames(frames, occupied);
            pageFaults++;
        }
        printf("\n");
    }

    printf("Page Fault: %d\n", pageFaults);

    return 0;
}
