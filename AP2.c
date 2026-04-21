#include <stdio.h>
int main(){
	int n;
	printf("Enter number of employees:");
	scanf("%d",&n);
	int empl[n];
	printf("Enter salaries of %d employees:",n);
	int i;

	for(i=0;i<=n-1;i=i+1){
		scanf("%d",&empl[i]);
	}
	
	printf("Normal order of salaries");
	for(i=0;i<=n-1;i=i+1){
		printf("%d \n",empl[i]);
	}
	
	printf("Reverse order of salaries");
	for(i=n-1;i>=0;i=i-1){
		printf("%d \n",empl[i]);
	}
}
