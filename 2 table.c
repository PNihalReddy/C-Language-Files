#include <stdio.h>
int main(){
	int n;
	do{
		printf("Enter the number:");
		scanf("%d",&n);
		printf("%d \n",n);
		if(n%7==0){
			break;
		}
	} while(1);
	printf("Thank You");
	return 0;
}
