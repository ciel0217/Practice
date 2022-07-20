#include <stdio.h>
int len(char *);

int main(){
	char num[100];
	scanf("%s",num);
	printf("%d\n",len(num));
	return 0;
}

int len(char str[]){
	int p;
	p=0;
	while(*str != '\0'){
		p++;
		str++;
	}
	return p;
}
