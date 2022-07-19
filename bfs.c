#include <stdio.h>

int main(){
	int queue[6];
	int check[6];
	int start = 0;
	int count =0 ;
	int G[6][6] =  {{0,1,0,0,1,0},{1,0,1,0,1,1},{0,1,0,1,0,0},{0,0,1,0,1,1},{1,1,0,1,0,0},{0,1,0,1,0,0}};

	for(int i=0;i<6;i++)check[i]=0;

	queue[count] = start;
	check[start] = 1;
	while(count<5){
		for(int i=0;i<6;i++){
			if(G[start][i] == 1 && check[i] == 0){
				count++;
				queue[count]=i;
				check[i] = 1;
			}
		}
		start = queue[start+1];
	}
	for(int i=0;i<6;i++){
		printf("%d\n",queue[i]+1);
	}
	return 0;
}