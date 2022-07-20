#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Fori(g) for(int i=0;i<g;i++)
#define	Forj(g) for(int j=0;j<g;j++)
#define min(aa,bb) (aa<bb)?aa:bb
#define max(aa,bb) (aa<bb)?bb:aa

#define num 10
int main(){
	int data[num],left=0,right=num,harf,ch,tmp;
	Fori(num)scanf("%d",&data[i]);
	Fori(num)for(int j=num-1;j>i;j--){
		if(data[i]>data[j]){
			tmp=data[j];
			data[j]=data[i];
			data[i]=tmp;
		}
	}
	printf("見つける値\n");
	scanf("%d",&ch);
	printf("ソート後\n");
	Fori(num)printf("%d\n",data[i]);
	while(right-left>1){
		harf=(right+left)/2;
		if(data[harf]>ch){
			right=harf;
			printf("right=%d\n",right);
		}else if(data[harf]<ch){
			left=harf;
			printf("left=%d\n",left);
		}else{
			printf("%d番目にミッケ\n",harf+1);
			return 0;
		}
	}
	printf("%d番目と%d番目の間に入る\n",left+1,right+1);
	return 0;
}