#include <stdio.h>
int main(){
	int n,i;
	float diff=0.0,max,min;
	printf("Enter the number of students:");
	scanf("%d",&n);
	float student[n];
	printf("Enter the float CGPAs of %d students:",n);
	for(i=0;i<=n-1;i=i+1){
		scanf("%f",&student[i]);
	}
	max=student[0];
	min=student[0];
	for(i=0;i<=n-1;i=i+1){
		if(student[i]>max){
			max=student[i];
		}
	}
	
	for(i=0;i<=n-1;i=i+1){
		if(student[i]<min){
			min=student[i];
		}
	}
	
	diff=max-min;
	printf("The difference between the highest and lowest CGPAs in the class is%.2f",diff);
	
}
