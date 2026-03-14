#include <stdio.h>
int main()
{
	int age;
	printf("Enter age:");
	scanf("%d",&age);
	switch(age){
		case 1:printf("Age is 1");
			break;
		case 2:printf("Age is 2");
			break;
		default:printf("Not a valid day");
	}
		
}
