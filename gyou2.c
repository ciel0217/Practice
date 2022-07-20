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
	int v[num+1][num2+1];
	int v2[num3+1][num4+1];
	//入力
	for(int i=1;i<=num;i++){
		for(int j=1;j<=num2;j++){
			scanf("%d",&v[i][j]);
		}
	}
	//入力
	for(int i=1;i<=num3;i++){
		for(int j=1;j<=num4;j++){
			scanf("%d",&v2[i][j]);
		}
	}
	//足し算
	if(num==num3 && num2==num4){
	printf("足し算\n");
	for(int i=1;i<=num;i++){
		for(int j=1;j<=num2;j++){
			sum=v[i][j]+v2[i][j];
			printf("%d,",sum);
			sum=0;
		}
		printf("\n");
	}
	//引き算
	printf("引き算\n");
	for(int i=1;i<=num;i++){
		for(int j=1;j<=num2;j++){
			sum2=v[i][j]-v2[i][j];
			printf("%d,",sum2);
			sum2=0;
		}
		printf("\n");
	}
}else{
	printf("足し算と引き算計算不可\n");
}
	
	if(num2==num3){    				//掛け算できるか			//ベクトルと行列かどうか
			printf("ベクトルと行列\n");
			for(int i=1;i<=num;i++){
				for(int j=1;j<=num2;j++){
					for(int k=1;k<=num4;k++){
						sum3+=v[k][i]*v2[j][k];
					}
		printf("%d\n",sum3);
			sum3=0;
		}
	}
			}else{
			}
		
return 0;
}