#include<stdio.h>

struct employee{
  int eno;
  char ename[20];
  float salary;
};

int main(){
  int n,i;
  printf("Enter number of employees\n");
  scanf("%d",&n);
  
  struct employee e[n];
  for(i=0;i<=n-1;i++){
  printf("Enter employee e[%d] information\n",i+1);
  scanf("%d",&e[i].eno);
  scanf(" %[^\n]s",&e[i].ename);
  scanf("%f",&e[i].salary);
    }
  
  for(i=0;i<=n-1;i++){
  printf("e[%d] information is\n",i+1);
  printf("%d   %s    %.2f ",e[i].eno,e[i].ename,e[i].salary);
  if(e[i].salary > 30000.00){
    printf("IT is there\n");
  }
  else{
    printf("NO IT\n");
  }
  }
}
