#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findClosest(int requests[], int n, int head, int visited[]) {
    int minDist = 1e9, index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int dist = abs(requests[i] - head);
            if (dist < minDist) {
                minDist = dist;
                index = i;
            }
        }
    }
    return index;
}

void sstf_scheduling(int requests[], int n, int head) {
    int seek_count = 0;
    int cur_head = head;
    int visited[n];
    int sequence[n];

    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < n; i++) {
        int idx = findClosest(requests, n, cur_head, visited);
        visited[idx] = 1;

        int distance = abs(requests[idx] - cur_head);
        seek_count += distance;
        cur_head = requests[idx];
        sequence[i] = requests[idx];
    }

    printf("Total Seek Count: %d\n", seek_count);
    printf("Seek Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");
}

int main() {
    int requests[] = {11, 34, 41, 50, 52, 69, 70, 114};
    int n = sizeof(requests) / sizeof(requests[0]);
    int head = 50;

    sstf_scheduling(requests, n, head);

    return 0;
}
