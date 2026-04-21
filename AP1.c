#include <stdio.h>
int main(){
	int n;
	printf("Enter the number of students:");
	scanf("%d",&n);
	int student[n];
	printf("Enter marks of %d students:",n);
	int i;

	for(i=0;i<=n-1;i=i+1){
		scanf("%d", &student[i]);
	}
	
	printf("Marks in regular order:");
	for(i=0;i<=n-1;i=i+1){
		printf("%d \n",student[i]);
	}
	
	printf("Marks in reverse order:");
	for(i=n-1;i>=0;i=i-1){
		printf("%d \n",student[i]);
	}
}
