#include <stdio.h>

int main(){
	int dp[10];
	dp[0]=0;
	for(int i=1;i<10;i++){
		if(i==1 || i==2)dp[i]=1;
		else dp[i]=dp[i-1]+dp[i-2];
	}

	for(int i=0;i<10;i++){
		printf("%d\t",dp[i]);
	}
	return 0;
}