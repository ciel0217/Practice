#include <stdio.h>
int test();
int zzz();
int main(){
	int ret,ret2;
	ret = test();
	ret2=zzz();

	printf("%d,%d\n",ret,ret2);
	return 0;
}