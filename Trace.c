#include <stdio.h>

int main(){
	int m1,n1;
	printf("Enter number of rows and columns of the matrix\n");
	scanf("%d %d",&m1,&n1);
	
	int a[m1][n1];
	printf("Enter the elements for the matrix \n");
	
	int i,j;
	for(i=0;i<=m1-1;i++){
		for(j=0;j<=n1-1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	int sum=0;
	for(i=0;i<=m1-1;i++){
		sum=sum+a[i][i];
	}
	
	printf("The trace of the matrix is %d\n",sum);
	
}
