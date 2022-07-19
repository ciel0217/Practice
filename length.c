#include <stdio.h>
int main(void){
	char a[100];
	int c,b=0,d=0;
	while((a[b]=getchar()) != '\n'){
	b++;
	}
	for(d=0;d<=b;d++){
	printf("%s",a[d]);
	}
	printf("%d",b);
	return 0;
}