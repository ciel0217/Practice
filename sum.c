#include <stdio.h>
#include <math.h>
int main(){
int n;
float sum=0;
float sum2=0;
float sum3=0;
float sum4=0;
float sum5=0;
printf("何列ずつ入力しますか\n");
scanf("%d",&n);
int v[n];
int v2[n];
printf("一つ目\n");
for(int i=0;i<n;i++){
	scanf("%d",&v[i]);
}
printf("二つ目\n");
for(int a=0;a<n;a++){
	scanf("%d",&v2[a]);
}
for(int b=0;b<n;b++){
	sum=v[b]+v2[b];
	sum2=v[b]-v2[b];
	sum3+=v[b]*v2[b];
	sum4+=v[b]*v[b];
	sum5+=v2[b]*v2[b];
	printf("足し算:%f:::引き算:%f\n",sum,sum2);
	}
	printf("内積:%f\n",sum3);
	printf("cosθ=%f\n",sum3/(sqrt(sum5)*sqrt(sum4)));
return 0;
}
/*足し算:3.000000:::引き算:-1.000000
足し算:2.000000:::引き算:2.000000
足し算:4.000000:::引き算:2.000000
内積:5.000000
cosθ=0.597614
*/