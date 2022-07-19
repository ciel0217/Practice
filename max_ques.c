#include <stdio.h>
#include <stdlib.h>
#define max(x,y)x>y?x:y
int main(){
	int n,*a,dp[50],x,y;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	dp[0]=0;
	for(int i=0;i<n;i++){
		dp[i+1]=max(dp[i]+a[i],dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}