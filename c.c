#include <stdio.h>
int main(void){
	int a;
	unsigned char *p = (unsigned char *)&a;
	printf("sizeof(a)=%d\n",sizeof(a));

	a = 0x1234ABCD;
	printf("a = 0x%08X\n",a);
	//printf("p = %p\n",p);
	printf("a(0) = 0x%02X\n",*p);
	printf("a(1)=0x%02X\n",*(p+1));
	printf("a(2) = 0x%02X\n",*(p+2));
	printf("a(3)=0x%02X\n",*(p+3));
	return 0;
}