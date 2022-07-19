#include <stdio.h>


int or(int* ch,int a){
	for(int i=0;i<6;i++){
		if(ch[i] == a)return 0;
	}
	return 1;
}

int main(){
	int d[6],start,check[6]; 
	int c[6][6] = {{0,3,0,0,2,0},{3,0,4,0,2,1},{0,4,0,6,0,0},{0,0,6,0,1,2},{2,2,0,1,0,0},{0,1,0,2,0,0}};
	printf("start:");
	scanf("%d",&start);
	for(int i = 0;i<6;i++){
		check[i]=0;
		d[i]=100;
	}

	check[0]=start;
	d[start-1]=0;
	int head=1,tail=1;
	for(int i=0;i<6;i++){
		if(c[start-1][i] > 0 ){
			check[tail++]=i+1;
			d[i]=(d[i]>d[start-1]+c[start-1][i]) ? d[start-1]+c[start-1][i] : d[i];
		}
	}

	for(int i=head;i<=tail;i++){
		int u=(check[i]-1);
		for(int j=0;j<6;j++){
			if(c[u][j] > 0 ){
				d[j]=(d[j]>d[u]+c[u][j]) ? d[u]+c[u][j] : d[j];
				if(or(check,j+1))check[tail++]=j+1;
			}
		}
	}

	for(int i=0;i<6;i++)printf("v[%d]:cost=%d\n",i+1,d[i]);
	return 0;
}