#include <stdio.h>
int main(){
	int n,i;
	printf("Enter the number of marks:");
	scanf("%d",&n);
	int student[n];
	printf("Enter %d student marks:",n);
	for(i=0;i<=n-1;i=i+1){
		scanf("%d",&student[i]);
	}
	
	int max=student[0],min=student[0];
	int second_max=student[0],second_min=student[1];
	for(i=0;i<=n-1;i=i+1){
		if(student[i]>max){
			second_max=max;
			max=student[i];
		}
		else if(student[i]>second_max && student[i]!=max){
			second_max=student[i];
		}
	}
	
	for(i=2;i<n;i=i+1){
		if(student[i]<min){
			second_min=min;
			min=student[i];
		}
		else if(student[i]<second_min && student[i]!=min){
			second_min=student[i];
		}
	}
	
	printf("The maximum value is %d \n",max);
	printf("The second maximum value is %d \n",second_max);
	printf("The minimum value is %d \n",min);
	printf("The second minimum value is %d \n",second_min);
	
}
