#include <stdio.h>
void add(int *px1,int *px2){
		int a;
		printf("加算する点数を入力してください");
		scanf("%d",&a);
		*px1 = *px1+a;
		*px2 = *px2+a;
}
int main(){
	int x1,x2;
	printf("2科目分の点数を入力してください");
	scanf("%d,%d",&x1,&x2);
	add(&x1,&x2);
	printf("科目１は%dになりました",x1);
	printf("科目2は%dになりました",x2);
	return 0;
}
	