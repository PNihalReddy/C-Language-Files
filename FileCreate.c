#include <stdio.h>

int main(){
	FILE *fp;
	int age;
	printf("Enter age:\n");
	scanf("%d",&age);
	fp=fopen("C:\\Users\\NIHAL\\OneDrive\\Desktop\\C Programs\\CO-4\\File Handling\\numbers.txt","ab");
	fprintf(fp,"\n %d",age);
	fclose(fp);
}
