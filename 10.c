#include <stdio.h>
#include <math.h>
int main(){
	int n;
	printf("Enter array size\n");
	scanf("%d",&n);
	int student[n];
	printf("Enter elements of the array:\n");
	
	int i;
	for(i=0;i<=n-1;i++){
		scanf("%d",&student[i]);
	}
	
	float sq_root;
	float square_root[n];
	for(i=0;i<=n-1;i++){
		sq_root=sqrt(student[i]);
		square_root[i]=sq_root;
	}
	
	printf("Original array - \n");
	for(i=0;i<=n-1;i++){
		printf("%d\n",student[i]);
	}
	
	
	printf("Square Root Array - \n");
	for(i=0;i<=n-1;i++){
		printf("%.2f\n",square_root[i]);
	}
				
}
