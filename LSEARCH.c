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
	int x;
	printf("Enter element to be searched for");
	scanf("%d",&x);
	
	for(i=0;i<=n-1;i=i+1){
		if(student[i]==x){
			break;
		}
	}
	if(i<=n-1){
		printf("Element found at index %d",i);
	}
	else{
		printf("Element not found");
	}
}
