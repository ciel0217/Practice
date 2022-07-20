#include <stdio.h>

int x=1;
int main(){
	printf("%d\n",x);
	sub1();
	printf("%d\n",x);
	x++;
	printf("%d\n",x);
	sub2();
	printf("%d\n",x);
	return 0;
}