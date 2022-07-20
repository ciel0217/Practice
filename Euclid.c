#include <stdio.h>

int main(){
	int n,r,a,b,c,tmp;
	printf("個数:");
	scanf("%d",&n);
	if(n==3){
		scanf("%d%d%d",&a,&b,&c);
		r=a%b;
		while(r!=0){
			tmp=b;
			b=r;
			a=tmp;
			r=a%b;
		}
		r=c%b;
		while(r!=0){
			tmp=b;
			b=r;
			c=tmp;
			r=c%b;
		}
		printf("%d\n",b);

	}else if(n==2){
		scanf("%d%d",&a,&b);
		r=a%b;
		while(r!=0){
			tmp=b;
			b=r;
			a=tmp;
			r=a%b;
		}
		printf("%d\n",b);
	}
	return 0;
}