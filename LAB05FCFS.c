#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int requests[n];


    printf("Enter request sequence (space separated): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

   
    printf("Enter initial head position: ");
    scanf("%d", &head);

    int total_seek = 0;
    int current = head;

    
    printf("Head Movement Path: %d", head);

    for (int i = 0; i < n; i++) {
        int distance = abs(requests[i] - current);
        total_seek += distance;
        current = requests[i];
        printf(" -> %d", current);
    }

    printf("\nTotal Seek Operations: %d\n", total_seek);

    return 0;
}
