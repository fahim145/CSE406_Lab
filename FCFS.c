#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    char pid[n][5];
    int at[n], bt[n], ct[n], tat[n], wt[n];

    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Process ID: ");
        scanf("%s", pid[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // Sort by Arrival Time (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                // Swap arrival time
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process ID
                char tempId[5];
                strcpy(tempId, pid[i]);
                strcpy(pid[i], pid[j]);
                strcpy(pid[j], tempId);
            }
        }
    }

    // First process
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    // Remaining processes
    for (int i = 1; i < n; i++) {
        if (ct[i - 1] < at[i]) {
            ct[i] = at[i] + bt[i];
        } else {
            ct[i] = ct[i - 1] + bt[i];
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Print Table
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Average TAT and WT
    float total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
    printf("Average Waiting Time   : %.2f\n", total_wt / n);

    return 0;
}
