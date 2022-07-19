#include <stdio.h>
int min(int x,int y);


int main(){
	int x,y;
	scanf("%d,%d",&x,&y);
	int ans = min(x,y);
	printf("%d",ans);
	return 0;
}

int min(int x,int y){
	if(x > y)
		return y;
	else 
		return x;
}