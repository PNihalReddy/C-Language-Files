#include <stdio.h>

void input_array(int a[],int n);
void lsearch(int a[],int n,int x);

int main(){
	int n,x;
	printf("Enter array size:\n");
	scanf("%d",&n);
	
	int a[n];
	
	printf("Enter array elements:\n");
	input_array(a,n);
	
	printf("Enter element to be searched for:\n");
	scanf("%d",&x);
	
	lsearch(a,n,x);
	
}

void input_array(int a[],int n){
	int i;
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]);
	}
}

void lsearch(int a[],int n,int x){
	int i;
	for(i=0;i<=n-1;i++){
		if(a[i]==x){
			break;
		}
	}
	
	if(i<=n){
		printf("The element was found at index %d",i);
	}
	
	else{
		printf("The element is not in the array");
	}
}

