#include<stdio.h>
int main()
{
  int n,i,j,s;
  printf("Enter number of lines");
  scanf("%d",&n);
  
  for(i=1;i<=n;i++)
  {
    s =i;
    for(j=1;j<=n;j++)
    {
    printf("%2d ",s);
    s=s+n;  
    
    }
    printf("\n");
  }
}
