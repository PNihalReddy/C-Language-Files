#include <stdio.h>

int main()
{
    int n,quantum;
    printf("Enter number of processes:");
    scanf("%d",&n);
    
    int burst_time[n],remaining_burst_time[n],waiting_time[n],turnaround_time[n];
    int process_id[n];
    
    printf("Enter burst time for each process:\n");
    
    int i;
    for(i=0;i<n;i++)
    {
        process_id[i]=i+1;
        printf("P:%d ",i+1);
        scanf("%d",&burst_time[i]);
        remaining_burst_time[i]=burst_time[i];
    }
    
    printf("ENter time quantum");
    scanf("%d",&quantum);
    
    int current_time=0;
    int completed_processes=0;
    
    while(completed_processes<n)
    {
        for(i=0;i<n;i++)
        {
            if(remaining_burst_time[i]>0)
            {
                if(remaining_burst_time[i]>quantum)
                {
                    current_time+=quantum;
                    remaining_burst_time[i]-=quantum;
                }
                
                else
                {
                    current_time+=remaining_burst_time[i];
                    waiting_time[i]=current_time-burst_time[i];
                    remaining_burst_time[i]=0;
                    completed_processes++;
                    
                }
            }
        }
    }
    
    float total_waiting_time=0;
    float total_turnaround_time=0;
    
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for(i=0;i<n;i++)
    {
        turnaround_time[i]=burst_time[i]+waiting_time[i];
        total_waiting_time+=waiting_time[i];
        total_turnaround_time+=turnaround_time[i];
        printf("P%d\t%d\t%d\t%d\t\n",process_id[i],burst_time[i],waiting_time[i],turnaround_time[i]);
    }
    
    printf("\nAverage Waiting Time :%.2f\n",total_waiting_time);
    printf("Average Turnaround Time:%.2f\n",total_turnaround_time);
    
    return 0;
}
