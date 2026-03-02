#include <stdio.h>

int main()
 {
    int n, frame_size;

    printf("Enter number of pages: ");
    scanf("%d", &n);
		
	int i,j;
    int pages[n];
    printf("Enter page reference string (space separated): ");
    for (i = 0; i < n; i++) 
	{
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frame_size);

    int frames[frame_size];
    int last_used[frame_size];
    int page_faults = 0;
    int time = 0;

    for ( i = 0; i < frame_size; i++)
	{
        frames[i] = -1;      
        last_used[i] = -1;    
    }

    for ( i = 0; i < n; i++) 
	{
        int page = pages[i];
        int found = 0;
        time++;

        for ( j = 0; j < frame_size; j++) 
		{
            if (frames[j] == page)
			{
                found = 1;
                last_used[j] = time;  
                break;
            }
        }

        if (!found) 
		{
            page_faults++;

            int lru_index = 0;
            int min_time = last_used[0];
            for ( j = 1; j < frame_size; j++)
			 {
                if (last_used[j] < min_time) 
				{
                    min_time = last_used[j];
                    lru_index = j;
                }
            }

            frames[lru_index] = page;
            last_used[lru_index] = time;
        }

        for ( j = 0; j < frame_size; j++)
		 {
            if (frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("Total page faults: %d\n", page_faults);

    return 0;
    
}
