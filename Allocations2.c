#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr = (int *)malloc(sizeof(int));
	
	if(ptr==NULL)
	{
		printf("Memory allocation failed\n");
		return 1;
	}
	
	*ptr = 10;
	printf("Value before freeing : %d\n",*ptr);
	
	free(ptr);
	printf("Value after freeing : %d\n",*ptr);
	
	return 0;
	
}
