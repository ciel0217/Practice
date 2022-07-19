#include <stdio.h>

int check[6];
int G[6][6] =  {{0,1,0,0,1,0},{1,0,1,0,1,1},{0,1,0,1,0,0},{0,0,1,0,1,1},{1,1,0,1,0,0},{0,1,0,1,0,0}};

int bfs(int v){
	check[v]=1;
	for(int i=v;i<6;i++)
		if(check[i]==0 && G[v][i]==1){
			printf("%d\n",i+1);
			bfs(i);
		}
	return 0;
}

int main(){
	int s=0;
	for(int i=0;i<6;i++)check[i]=0;
	printf("%d\n",s+1);
	bfs(s);
	return 0;
}