#include <stdio.h>

void input_array(int a[],int n);
int bsearch(int a[],int n,int x);

int main(){
	int n,x,Z;
	printf("Enter size of array:\n");
	scanf("%d",&n);
	
	int a[n];
	
	printf("Enter array elements:\n");
	input_array(a,n);
	
	printf("Enter element to be searched for:\n");
	scanf("%d",&x);
	
	
	Z=bsearch(a,n,x);
	if(Z==-1){
		printf("The element was not found\n");
	}
	else{
		printf("The element was found at index %d\n",Z);
	}
}


void input_array(int a[],int n){
	int i;
	for(i=0;i<=n-1;i++){
		scanf("%d",&a[i]);
	}
}

int bsearch(int a[],int n,int x){
	int si=0,ei=n-1,mi=0;
	while(si<=ei){
		mi=(si+ei)/2;
		if(x==a[mi]){
			return mi;
		}
		else if(x>a[mi]){
			mi=ei-1;
		}
		else if(x<a[mi]){
			si=si+1;
		}
		
	}
}
