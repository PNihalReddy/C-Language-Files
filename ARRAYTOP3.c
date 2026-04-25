#include <stdio.h>
int main(){
	int n;
	printf("Enter size of array:");
	scanf("%d",&n);
	int student[n];
	printf("Enter elements of the array:");
	int i,j,temp;
	for(i=0;i<=n-1;i++){
		scanf("%d",&student[i]);
	}
	// Bubble Sort
	for(i=1;i<=n-1;i++){
		for(j=0;j<=n-i-1;j++){
			if(student[j]>student[j+1]){
			
				temp=student[j];
				student[j]=student[j+1];
				student[j+1]=temp;
			}
		}
	}
	printf("The top 3 elements in the array are - \n");
	for(i=0;i<=2;i++){
		printf("%d\n",student[i]);
	}

}

