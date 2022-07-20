#include <stdio.h>
extern int x;
int sub2(){
	printf("%d\n",x);
	x+= 2;
	return 0;

}