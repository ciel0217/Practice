#include <stdio.h>
int sum=0;
int mod(int n){
	int num = n/10;
	int num2 = n%10;
	sum+=num2;
	return num==0 ? sum:mod(n/10);
}

int main(){
	int N,A,B,ss,sum2=0;
	scanf("%d %d %d",&N,&A,&B);
	for(int i=0;i<=N;i++){
		ss=mod(i);
		if(A<=ss && ss<=B){
			sum2+=i;
		}
		sum=0;
	}	
	printf("%d\n",sum2);
	return 0;
}