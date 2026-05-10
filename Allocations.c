#include <stdio.h>
#include <stdlib.h>

int main()
 {
    int n, i, *ptr, sum = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory dynamically using malloc()
    // n * sizeof(int) calculates the total bytes needed for n integers
    ptr = (int*) malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (ptr == NULL) 
	{
        printf("Error! Memory not allocated.\n");
        exit(0); // Exit the program if allocation fails
    }

    // Get elements from the user and calculate their sum
    printf("Enter elements:\n");
    for (i = 0; i < n; ++i) 
	{
        scanf("%d", ptr + i); // Read into the dynamically allocated memory
        sum += *(ptr + i);    // Add the element to the sum
    }

    // Print the calculated sum
    printf("Sum = %d\n", sum);

    // Free the dynamically allocated memory
    free(ptr);
    ptr = NULL; // Set the pointer to NULL after freeing to avoid dangling pointers

    return 0;
}
