#include <stdio.h>

struct employee{
	char name[15];
	int empid;
	float salary;
};

int main(){
	int i,n;
	printf("Enter the number of employees:\n");
	scanf("%d",&n);
	
	struct employee e[n];
	for(i=0;i<=n-1;i++){
		printf("Enter employee e[%d] information - \n",i+1);
		scanf(" %[^\n]s",&e[i].name);
		scanf("%d",&e[i].empid);
		scanf("%f",&e[i].salary);	
	}
	
	for(i=0;i<=n-1;i++){
		printf("Employee e[%d] information is - \n",i+1);
		printf("%s	%d	%.2f\n",e[i].name,e[i].empid,e[i].salary);
	}
}
