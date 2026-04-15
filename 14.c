#include <stdio.h>

int main(){
	int n;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	
	int i,a[n];
	printf("Enter array elements:\n");
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]);
	}
	
	int x,index=-1;
	printf("Enter element to be deleted:\n");
	scanf("%d",&x);
	
	for(i=0;i<=n-1;i++){
		if(x==a[i]){
			index=i;
			break;
		}
	}
	
	if(index==-1){
		printf("Element not found in the array\n");
		return 1;
	}
	
	for(i=index;i<n-1;i++){
		a[i]=a[i+1];
	}
	n=n-1;
	
	printf("The array after deletion is - \n");
	
	for(i=0;i<=n-1;i++){
		printf("%d\n",a[i]);
	}
	return 0;
	
}
