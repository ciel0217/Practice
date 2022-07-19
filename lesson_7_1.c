#include <stdio.h>
#define NUM 5

int main(){
	int k[NUM];
	int max=0;

	for(int i=0;i<NUM;i++){
		printf("入力\n");
		scanf("%d",&k[i]);
	}
	for(int i=0;i<NUM;i++){
		if(max < k[i]){
			max=k[i];

		}
	}
		printf("%d",max);
		return 0;
}
