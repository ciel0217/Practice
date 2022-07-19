#include <stdio.h>
int inner(int *,int *,int);
int main(){
	int n;
	scanf("%d",&n);
	int v[n],v2[n];
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	for(int j=0;j<n;j++){
		scanf("%d",&v2[j]);
	}
	printf("内積:%d",inner(v,v2,n));
	return 0;
}

