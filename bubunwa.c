#include <stdio.h>
#define max(a,b)a>b?a:b
int main(){
	int dp[51][51],n,A,a[51];
	scanf("%d%d",&n,&A);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	
	for(int i=0;i<n;i++){
		for(int j=0;j<=A;j++){
			dp[i][j]=0;
		}
	}
	dp[0][0]=1;

	for(int i=0;i<n;i++){
		for(int j=0;j<=A;j++){
			if(j>=a[i]){
				dp[i+1][j]=max(dp[i][j-a[i]]+dp[i][j],dp[i][j]);
			}else {
				dp[i+1][j]=dp[i][j];
			}
		}
	}
	printf("%d\n",dp[n][A]);
	return 0;
}