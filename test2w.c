#include <stdio.h>
int main(void){
	int a,b,c,d,r,tmp,com;
	scanf("%d,%d",&a,&b);
	d = a;
	c = b;
	if(d<c){
       tmp = d;
       d = c;
       c = tmp;
	}
	r = d % c;
	while(r != 0){
       d = c;
       c = r;
       r = d % c;
	}
    com = a*b/c;
    printf("%d\n",c);
    printf("%d\n",com);

    return 0;
}