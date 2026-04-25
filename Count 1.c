#include <stdio.h>
int main(){
	int n,count=0;
	printf("Enter the number of students:");
	scanf("%d",&n);
	float result[n];
	printf("Enter CGPA of %d students:");
	int i;
	for(i=0;i<=n-1;i=i+1){
		scanf("%f",&result[i]);
	}
	
	for(i=0;i<=n-1;i=i+1){
		if(result[i]>=9.0){
			count=count+1;
		}
	}
	
	printf("%d students are eligible for placement",count);
}
