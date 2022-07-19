#include <stdio.h>
int main(){
	char wd[100];
	int leng=0;
	int num=0;

	scanf("%s",wd);
	while(wd[leng] != '\0'){
		if(wd[leng] == 'a'){
			num++;
		}
		leng++;
	}
	printf("%d,%d",leng,num);
	return 0;
}