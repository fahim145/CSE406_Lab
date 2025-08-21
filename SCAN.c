#include <stdio.h>
#include <stdlib.h>

void scan_disk_scheduling(int requests[], int n, int head) {
    int seek_count = 0;
    int accessed[n];
    int accessed_index = 0;

  
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (requests[j] > requests[j + 1]) {
                int temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    
    int left[n], right[n];
    int lsize = 0, rsize = 0;
    for (int i = 0; i < n; i++) {
        if (requests[i] <= head)
            left[lsize++] = requests[i];
        else
            right[rsize++] = requests[i];
    }

    for (int i = lsize - 1; i >= 0; i--) {
        seek_count += abs(head - left[i]);
        head = left[i];
        accessed[accessed_index++] = left[i];
    }

    for (int i = 0; i < rsize; i++) {
        seek_count += abs(head - right[i]);
        head = right[i];
        accessed[accessed_index++] = right[i];
    }

  
    printf("Accessed track sequence: ");
    for (int i = 0; i < accessed_index; i++) {
        printf("%d ", accessed[i]);
    }
    printf("\nTotal seek time: %d\n", seek_count);
}

int main() {
    int requests[] = {82, 170, 43, 140, 24, 16, 190};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 50;

    scan_disk_scheduling(requests, n, head);

    return 0;
}
