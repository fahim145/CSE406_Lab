#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("How many processes: ");
    scanf("%d", &n);

    char pid[n][5];
    int at[n], bt[n], ct[n], tat[n], wt[n], done[n];
    int time = 0, finished = 0;

    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Process ID: ");
        scanf("%s", pid[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        done[i] = 0;
    }

    while (finished < n) {
        int small = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && done[i] == 0) {
                if (small == -1 || bt[i] < bt[small]) {
                    small = i;
                }
            }
        }

        if (small == -1) {
            time++;
        } else {
            time += bt[small];
            ct[small] = time;
            tat[small] = ct[small] - at[small];
            wt[small] = tat[small] - bt[small];
            done[small] = 1;
            finished++;
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    float total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++) {
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAvg TAT: %.2f\n", total_tat / n);
    printf("Avg WT : %.2f\n", total_wt / n);

    return 0;
}
