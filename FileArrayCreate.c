#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *fp;
    int arr[10]; // Array to store data
    int i;

    // Open the file in write mode ("w")
    fp = fopen("Sample1.txt", "w");

    // Check if the file was opened successfully
    if (fp == NULL) 
	{
        printf("Error opening file!\n");
        return 1; // Indicate an error
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) 
	{
        scanf("%d", &arr[i]);
    }

    // Write the array elements to the file, separated by spaces
    for (i = 0; i < 10; i++) 
	{
        fprintf(fp, "%d ", arr[i]);
    }
    fprintf(fp,"\n");

     // Write the array elements to the file, separated by new lines
    for (i = 0; i < 10; i++) 
	{
        fprintf(fp, "%d\n", arr[i]);
    }

    printf("Data written to file successfully.\n");
    fclose(fp); // Close the file

    //Code to read the data from the file
    fp = fopen("Sample1.txt", "r");
    if (fp == NULL) 
	{
        printf("Error opening file!\n");
        return 1; // Indicate an error
    }
    char c;
    while((c=fgetc(fp))!=EOF)
	{
        printf("%c",c);
    }
    fclose(fp);
    return 0; // Indicate success
}
