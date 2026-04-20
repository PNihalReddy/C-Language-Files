#include <stdio.h>
int main(){
	int n;
	printf("Enter array size:");
	scanf("%d",&n);
	int student[n];
	printf("Enter elements of the array");
	
	int i;
	for(i=0;i<=n-1;i=i+1){
		scanf("%d",&student[i]);
	}
	int x,count=0;
	printf("Enter element to be searched for");
	scanf("%d",&x);
	
	for(i=0;i<=n-1;i=i+1){
		if(student[i]==x){
			count=count+1;
		}
	}
	if(count==0){
		printf("Element not found");
	}
	else{
		printf("Element found %d times in the array",count);
	}
}
