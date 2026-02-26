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
	int x,index;
	printf("Enter element to add into the array:%d",x);
	scanf("%d",&x);
	printf("Enter the index for adding element into the array");
	scanf("%d",&index);
	//Shifting all the elements one position further
	n=n+1;
	for(i=n-1;i>=index;i--){
		student[i+1]=student[i];
	}
	student[index]=x;
	printf("The updated array is\n");
	for(i=0;i<=n-1;i++){
		printf("%d \n",student[i]);
	}
}
