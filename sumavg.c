#include <stdio.h>

void sum_and_avg(int a[],int n);
void input_array(int a[],int n);

int main(){
	int n;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	int a[n];
	
	printf("Enter the elements:\n");
	input_array(a,n);
	
	sum_and_avg(a,n);
}


void input_array(int a[],int n){
	int i;
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]);
	}
}
void sum_and_avg(int a[],int n){
	int i,sum=0,avg=0;
	for(i=0;i<=n-1;i++){
		sum=sum+a[i];
	}
	
	avg=sum/n;
	printf("The sum of elements is %d\n",sum);
	printf("The average of elements is %d\n",avg);
}
