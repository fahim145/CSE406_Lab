#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n, quantum;
    char process[MAX][10];
    int at[MAX], bt[MAX], rt[MAX], ct[MAX], tat[MAX], wt[MAX];
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    int time = 0, done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        printf("Enter process name: ");
        scanf("%s", process[i]);
        printf("Enter arrival time: ");
        scanf("%d", &at[i]);
        printf("Enter burst time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    while (done < n) {
        // Enqueue new processes
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if (front < rear) {
            int p = queue[front++];
            if (rt[p] > quantum) {
                time += quantum;
                rt[p] -= quantum;
            } else {
                time += rt[p];
                rt[p] = 0;
                ct[p] = time;
                done++;
            }

         
            for (int i = 0; i < n; i++) {
                if (at[i] <= time && rt[i] > 0 && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            if (rt[p] > 0) {
                queue[rear++] = p;
            }
        } else {
            time++;  // idle time
        }
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", process[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
