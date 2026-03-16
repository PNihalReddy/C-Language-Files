#include <stdio.h>
int main(){
	int n;
	printf("Enter array size:");
	scanf("%d",&n);
	int student[n];
	printf("Enter elements of the array:");
	int i;
	for(i=0;i<=n-1;i++){
		scanf("%d",&student[i]);
	}
	
	int max=student[0],min=student[0],second_max=student[0],second_min=student[0];
	for(i=0;i<=n-1;i++){
		if(student[i]>max){
			second_max=max;
			max=student[i];
		}
		else if(second_max>student[i] && second_max!=max){
			second_max=student[i];
		}
	}
	
	for(i=0;i<=n-1;i++){
		if(student[i]<min){
			second_min=min;
			min=student[i];
		}
		else if(second_min<student[i] && second_min!=min){
			second_min=student[i];
		}
	}	
	
	printf("The second max element is:%d\n",second_max);
	printf("The second min element is:%d\n",second_min);
		
}
