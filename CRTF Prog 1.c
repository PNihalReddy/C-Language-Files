#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rem_bt[n];
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    printf("Enter process ID, arrival time, and burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &pid[i], &at[i], &bt[i]);
        rem_bt[i] = bt[i];
    }

    int completed = 0, current_time = 0, shortest_job;
    int min_rem_bt = INT_MAX;

    while (completed != n)
    {
        shortest_job = -1;
        min_rem_bt = INT_MAX;

        for (i = 0; i < n; i++)
        {
            if (at[i] <= current_time && rem_bt[i] < min_rem_bt && rem_bt[i] > 0)
            {
                min_rem_bt = rem_bt[i];
                shortest_job = i;
            }
        }

        if (shortest_job == -1)
        {
            current_time++;
            continue;
        }

        rem_bt[shortest_job]--;
        current_time++;

        if (rem_bt[shortest_job] == 0)
        {
            completed++;
            int finish_time = current_time;
            wt[shortest_job] = finish_time - bt[shortest_job] - at[shortest_job];
            if (wt[shortest_job] < 0)
            {
                wt[shortest_job] = 0;
            }
            tat[shortest_job] = bt[shortest_job] + wt[shortest_job];
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
