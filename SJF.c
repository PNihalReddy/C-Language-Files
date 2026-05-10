#include <stdio.h>

int main() 
{
    int pid[15];
    int bt[15];
    int n, temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process id of all the processes: ");
    int i;
    for( i = 0; i < n; i++) 
	{
        scanf("%d", &pid[i]);
    }

    printf("Enter burst time of all the processes: ");
    for( i = 0; i < n; i++) 
	{
        scanf("%d", &bt[i]);
    }
	
	int j;
	
    for(i = 0; i < n; i++) 
	{
        for(j = i + 1; j < n; j++) 
		{
            if (bt[i] > bt[j])
			{
                // Swap burst times
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    int wt[15];
    float twt = 0.0;
    float tat = 0.0;
    wt[0] = 0;

    for( i = 1; i < n; i++) 
	{
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for ( i = 0; i < n; i++) 
	{
        printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], bt[i] + wt[i]);
        twt += wt[i];
        tat += bt[i] + wt[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", twt / n);
    printf("Average Turnaround Time: %.2f\n", tat / n);

    return 0;
}
