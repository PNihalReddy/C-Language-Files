#include <stdio.h>

int main(){
	int m1,n1;
	printf("Enter the number of rows and columns of first matrix\n");
	scanf("%d %d",&m1,&n1);
	
	int a[m1][n1];
	printf("Enter matrix 1 elements\n");
	
	int i,j;
	for(i=0;i<=m1-1;i++){
		for(j=0;j<=n1-1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	int m2,n2;
	printf("Enter the number of rows and columns of second matrix\n");
	scanf("%d %d",&m2,&n2);
	int b[m2][n2];
	
	if(m1!=m2 || n1!=n2){
		printf("Matrix addition and subtraction is not possible\n");
	}
	
	else{
		for(i=0;i<=m2-1;i++){
			for(j=0;j<=n2-1;j++){
				scanf("%d",&b[i][j]);
			}
		}
		
		int c[m1][n1];
		for(i=0;i<=m1-1;i++){
			for(j=0;j<=n1-1;j++){
				c[i][j]=a[i][j]+b[i][j];
			}
		}
		
		printf("The final array after addition is \n");
		
		for(i=0;i<=m1-1;i++){
			for(j=0;j<=n1-1;j++){
				printf("%d	",c[i][j]);
			}
			printf("\n");
		}
		
		int d[m1][n1];
		
		for(i=0;i<=m1-1;i++){
			for(j=0;j<=n1-1;j++){
				scanf("%d",&d[i][j]);
			}
		}
		
		
		for(i=0;i<=m1-1;i++){
			for(j=0;j<=n1-1;j++){
				d[i][j]=a[i][j]-b[i][j];
			}
		}
		
		printf("The final array after subtraction is \n");
		
		for(i=0;i<=m1-1;i++){
			for(j=0;j<=n1-1;j++){
				printf("%d	",d[i][j]);
			}
			printf("\n");
		}
	}
}
