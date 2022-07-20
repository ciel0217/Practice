#include <stdio.h>
int main(){
	int num,num2;
	int num3,num4;
	int sum=0;
	int sum2=0;
	int sum3=0;
	int sum4=0;
	printf("一つ目は何行:  何列:\n");
	scanf("%d,%d",&num,&num2);
	printf("二つ目は何行:  何列:\n");
	scanf("%d,%d",&num3,&num4);
	int v[num][num2];//gccのみ可能
	int v2[num3][num4];//gccのみ可能
	//入力
	printf("一つ目\n");
	for(int i=0;i<num;i++){
		for(int j=0;j<num2;j++){
			scanf("%d",&v[i][j]);
		}
	}
	//入力
	printf("二つ目\n");
	for(int i=0;i<num3;i++){
		for(int j=1;j<=num4;j++){
			scanf("%d",&v2[i][j]);
		}
	}
	//足し算
	if(num==num3 && num2==num4){
	printf("足し算\n");
	for(int i=0;i<num;i++){
		for(int j=0;j<num2;j++){
			sum=v[i][j]+v2[i][j];
			printf("%d,",sum);
			sum=0;
		}
		printf("\n");
	}
	//引き算
	printf("引き算\n");
	for(int i=0;i<num;i++){
		for(int j=0;j<num2;j++){
			sum2=v[i][j]-v2[i][j];
			printf("%d,",sum2);
			sum2=0;
		}
		printf("\n");
	}
}else{
	printf("足し算と引き算計算不可\n");
}	
	if(num2==num3){    				//掛け算、ベクトル計算できるか
			printf("掛け算\n");
			for(int i=0;i<num;i++){
				for(int j=0;j<num4;j++){
					for(int k=0;k<num2;k++){
						sum3+=v[i][k]*v2[k][j];
					}
		printf("%d,",sum3 );
			sum3=0;
		}
		printf("\n");
	}
}				
	return 0;
}
/*一つ目は何行:  何列:
3,3
二つ目は何行:  何列:
3,2
一つ目
8 4 2
1 3 -6
-7 0 5
二つ目
5 2
3 1
4 -1
足し算と引き算計算不可
掛け算
60,18,
-10,11,
-15,-19,

一つ目は何行:  何列:
3,3
二つ目は何行:  何列:
3,1
一つ目
1 2 3
1 2 3
1 2 3
二つ目
1
2
3
足し算と引き算計算不可
掛け算
14,
14,
14,
*/