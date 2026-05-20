#include <stdio.h>

int main(){
	FILE *fp;
	int age;
	fp=fopen("C:\\Users\\NIHAL\\OneDrive\\Desktop\\C Programs\\CO-4\\File Handling\\numbers.txt","rb");
	while(!feof(fp)){
		fscanf(fp,"%d  ",&age);
		printf("\n %d",age);
	}
	fclose(fp);
	return 0;
}
