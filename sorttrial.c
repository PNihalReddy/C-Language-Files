#include <stdio.h>
int main(){
	int n;
	printf("Enter array size:");
	scanf("%d",&n);
	int student[n];
	printf("Enter the elements:");
	int i;
	for(i=0;i<=n-1;i++){
		scanf("%d",&student[i]);
	}
	
	int sum=0;
	float mean=0,median=0;
	for(i=0;i<=n-1;i++){
		sum=sum+student[i];
	}
	
	mean=(float)sum/n;
	printf("The mean is %.2f",mean);
	
	if(n%2==0){
		median=(float)(student[n/2-1]+student[n/2])/2;
	}
	else{
		median=(float)(student[n/2]);
	}
	printf("The median is %.2f",median);
	
	
	
	
}
