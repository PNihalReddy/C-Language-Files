#include <stdio.h>

int main(){
	int m1,n1;
	printf("Enter the number of rows and columns of the first matrix:\n");
	scanf("%d %d",&m1,&n1);
	
	int a[m1][n1];
	printf("Enter the elements for the first array:\n");
	
	int i,j;
	for(i=0;i<=m1-1;i++){
		for(j=0;j<=n1-1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	int m2,n2;
	printf("Enter the number of rows and columns of the second matrix:\n");
	scanf("%d %d",&m2,&n2);
	int b[m2][n2];
	
	if(n1!=m2){
		printf("Matrix multiplication is not possible\n");
	}
	
	else{
		printf("Enter the elements for the second matrix\n");
		
		for(i=0;i<=m2-1;i++){
			for(j=0;j<=m2-1;j++){
				scanf("%d",&b[i][j]);
			}
		}
		
		int c[m2][n1];
		int k;
		for(i=0;i<=m2-1;i++){
			for(j=0;j<=n1-1;j++){
				c[i][j]=0;
				for(k=0;k<=n1-1;k++){
					c[i][j]=c[i][j]+a[i][k]*b[k][j];
				}
			}
		}
		
		printf("The final matrix after multiplication is \n");
		
		for(i=0;i<=m2-1;i++){
			for(j=0;j<=n1-1;j++){
				printf("%d	",c[i][j]);
			}
			printf("\n");
		}
		
	}
}
