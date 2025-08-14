#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    printf("How many processes: ");
    scanf("%d", &n);

    char pid[n][10]; // process IDs as strings
    int at[n], bt[n], pri[n], ct[n], tat[n], wt[n];
    bool done[n];

    for (int i = 0; i < n; i++) {
        printf("Pid: ");
        scanf("%s", pid[i]);
        printf("AT: ");
        scanf("%d", &at[i]);
        printf("BT: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pri[i]);
        done[i] = false;
        ct[i] = tat[i] = wt[i] = 0;
    }

    int time = 0;
    for (int completed = 0; completed < n; ) {
        int chosen_process = -1;

        // Find the process with the highest priority (lowest number)
        for (int i = 0; i < n; i++) {
            if (!done[i] && at[i] <= time) {
                if (chosen_process == -1 || pri[i] < pri[chosen_process]) {
                    chosen_process = i;
                }
            }
        }

        if (chosen_process == -1) {
            time++;
            continue;
        }

        time += bt[chosen_process];
        ct[chosen_process] = time;
        tat[chosen_process] = ct[chosen_process] - at[chosen_process];
        wt[chosen_process] = tat[chosen_process] - bt[chosen_process];
        done[chosen_process] = true;
        completed++;
    }

    // Calculate average waiting time
    float avg_wt = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
    }
    avg_wt /= n;

    printf("\nPid\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pri[i], ct[i], tat[i], wt[i]);
    }
    printf("Average WT: %.2f\n", avg_wt);

    return 0;
}
