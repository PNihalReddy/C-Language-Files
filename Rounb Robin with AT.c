#include <stdio.h>
#include <stdbool.h> 

struct Process 
{
    int pid;        
    int arrival_time; 
    int burst_time;   
    int remaining_burst_time; 
    int completion_time; 
    int waiting_time;   
    int turnaround_time; 
};

int main()
{
    int n; 
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++)
    {
        processes[i].pid = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_burst_time = processes[i].burst_time;
    }

    int quantum; 
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    int current_time = 0;
    int completed_processes = 0;
    bool done_processes[n]; 
    
    for(int i=0; i<n; i++) 
    {
        done_processes[i] = false;
    }

    while (completed_processes < n) 
    {
        bool process_executed_in_this_cycle = false;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && !done_processes[i]) {
                process_executed_in_this_cycle = true;

                if (processes[i].remaining_burst_time > quantum) 
                {
                    current_time += quantum;
                    processes[i].remaining_burst_time -= quantum;
                }
                else 
                {
                    current_time += processes[i].remaining_burst_time;
                    processes[i].remaining_burst_time = 0;
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    done_processes[i] = true;
                    completed_processes++;
                }
            }
        }
        
        if (!process_executed_in_this_cycle && completed_processes < n)
        {
            current_time++;
        }
    }
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n",
               processes[i].pid,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].turnaround_time,
               processes[i].waiting_time);
    }

    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    for (int i = 0; i < n; i++) 
    {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);

}
