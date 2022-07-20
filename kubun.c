#include <stdio.h>
double kubun(double (*pfunc)(double x),double st,double fin){
	double men;
	double N=10000;
		for(int k=1;k<=N;k++){
			men+=(*pfunc)(k*(fin-st)/N+st)*((fin-st)/N);
		}
	return men;
}
double func(double x){
	return x*x;
}
int main(){
	double st,fin;
	scanf("%lf,%lf",&st,&fin);
	printf("%lf",kubun(func,st,fin));
return 0;
}
/*
3,6
63.004050
*/