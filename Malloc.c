#include <stdio.h>
#include <stdlib.h>

#define MAX_PARTITIONS 10

int main() 
{
    int total_memory, os_memory, available_memory;
    int num_partitions;
    int partition_size[MAX_PARTITIONS];
    int process_size[MAX_PARTITIONS];
    int num_processes;
    int i, j;
    int internal_fragmentation = 0;
    int external_fragmentation = 0;
    int allocated_partitions = 0;
    int partition_allocated[MAX_PARTITIONS] = {0};

    printf("Enter total memory size (in KB): ");
    scanf("%d", &total_memory);

    printf("Enter memory occupied by OS (in KB): ");
    scanf("%d", &os_memory);

    available_memory = total_memory - os_memory;

    printf("Enter the number of fixed partitions: ");
    scanf("%d", &num_partitions);

    if (num_partitions > MAX_PARTITIONS) 
	{
        printf("Error: Maximum number of partitions exceeded. Setting to %d.\n", MAX_PARTITIONS);
        num_partitions = MAX_PARTITIONS;
    }

    // Calculate partition sizes (assuming equal size for simplicity)
    for (i = 0; i < num_partitions; i++) 
	{
        partition_size[i] = available_memory / num_partitions;
    }

    printf("\nMemory Partitions:\n");
    
	for (i = 0; i < num_partitions; i++)
	 {
        printf("Partition %d: %d KB\n", i + 1, partition_size[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) 
	{
        printf("Enter size of Process %d (in KB): ", i + 1);
        scanf("%d", &process_size[i]);
    }

    printf("\nProcess Allocation:\n");
    for (i = 0; i < num_processes; i++) 
	{
        int allocated = 0;
        for (j = 0; j < num_partitions; j++) 
		{
            if (partition_allocated[j] == 0 && process_size[i] <= partition_size[j]) 
			{
                printf("Process %d (Size: %d KB) allocated to Partition %d (Size: %d KB)\n",
                       i + 1, process_size[i], j + 1, partition_size[j]);
                internal_fragmentation += (partition_size[j] - process_size[i]);
                partition_allocated[j] = 1;
                allocated_partitions++;
                allocated = 1;
                break;
            }
        }
        if (!allocated)
		 {
            printf("Process %d (Size: %d KB) could not be allocated.\n", i + 1, process_size[i]);
        }
    }

    // Calculate external fragmentation
    for (i = 0; i < num_partitions; i++) 
	{
        if (partition_allocated[i] == 0) 
		{
            external_fragmentation += partition_size[i];
        }
    }

    printf("\n--- Fragmentation Analysis ---\n");
    printf("Total Internal Fragmentation: %d KB\n", internal_fragmentation);
    printf("Total External Fragmentation: %d KB\n", external_fragmentation);

    return 0;
}
