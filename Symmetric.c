#include <stdio.h>

int main(){
	int m1,n1;
	printf("Enter the number of rows and columns of first matrix\n");
	scanf("%d %d",&m1,&n1);
	
	int a[m1][n1];
	printf("Enter elements of the first matrix\n");
	
	int i,j;
	for(i=0;i<=m1-1;i++){
		for(j=0;j<=n1-1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	
	int issymmetric=1;
	for(i=0;i<=m1-1;i++){
		for(j=0;j<=n1-1;j++){
			if(a[i][j]!=a[j][i]){
				issymmetric=0;
				break;
			}
		}
	}
	
	if(issymmetric==1){
		printf("The matrix is symmetric\n");
	}
	
	else{
		printf("The matrix is not symmetric\n");
	}
}
