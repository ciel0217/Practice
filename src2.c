#include <stdio.h>
extern int x;
int sub1(){
	x++;
	printf("%d\n",x);
	return 0;
}