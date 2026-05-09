#include <stdio.h>
int main(){
	int m,n;
	printf("Enter number of rows and number of columns for the 1st array:\n");
	scanf("%d %d",&m,&n);
	int student[m][n];
	printf("Enter %d student roll numbers and %d marks:\n",m,n);
	
	int i,j;
	for(i=0;i<=m-1;i++){
		for(j=0;j<=n-1;j++){
			scanf("%d",&student[i][j]);
		}
	}
	int m2,n2;
	printf("Enter rows and columns of 2nd array:\n");
	scanf("%d %d",&m2,&n2);
	if(m!=m2 || n!=n2){
		printf("Addition is not possible for these two arrays \n");
		return 1;
	}
	int teacher[m][n];
	printf("Enter %d roll numbers and %d marks:\n",m,n);
	for(i=0;i<=m-1;i++){
		for(j=0;j<=n-1;j++){
			scanf("%d",&teacher[i][j]);
		}
	}
	
	int parent[m][n];
	for(i=0;i<=m-1;i++){
		for(j=0;j<=n-1;j++){
			parent[i][j]=student[i][j]+teacher[i][j];
		}
	}
	
	printf("The final 3rd array is - \n");
	for(i=0;i<=m-1;i++){
		for(j=0;j<=n-1;j++){
			printf("%d  ",parent[i][j]);

		}
	printf("\n");
	}
	return 0;
}
