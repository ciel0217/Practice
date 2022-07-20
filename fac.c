#include <stdio.h>
int fac(int a){
		return a==1?a:fac(a-1)*a;
}
int main(){
	int a;
	scanf("%d",&a);
	if(a==0){
		printf("1");
	}else{
		printf("%d",fac(a));
	}
	return 0;	
}
/*
5
120
*/