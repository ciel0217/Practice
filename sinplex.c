#include <stdio.h>

int main(){
	int matrix,n;
	int column,line;
	printf("xの数は\n");
	scanf("%d",&n);
	printf("制約式の数は\n");
	scanf("%d",&matrix);

	double a[matrix+1][n+matrix+1],min;

	/*入力方法
	_______________________________________________________________________
	|    \    |  x_1  | x_2  |  x_3 | ... | λ_1 | λ_2 | λ_3 | ... | 定数項 |
	-------------------------------------------------------------------
	| 目的関数 |  (1)  | (2)  | (3)  | ...| (4) |  (5) | (6) | ... |  (7)  |
	----------------------------------------------------------------------
	| 制約式1  |  (8)  | (9)  | (10) | ...| (11) | (12)| (13)| ... |  (14) |
	-----------------------------------------------------------------------
	| 制約式2  |  (15) .................................
	.
	.
	.
	________________________________________________________________________
	この()の中の数字順に入力して
	目的関数は、マイナスにして入力して->28だったら-28と入力する。
	*/
	for(int i=0;i<matrix+1;i++){
		for(int j=0;j<n+matrix+1;j++){
			scanf("%lf",&a[i][j]);
		}
	}
	while(1){
		min = 10000;
		for (int i=0;i<n;i++){	//目的変数の中で最小を見つけて、その時の列を変数に格納する。
			if(min > a[0][i]){
				min=a[0][i];
				column = i;
			}
		}
		
		if(min >= 0)break; //すべて非負であったとき、目的変数の値はこれ以上増加しないため、計算終了
		printf("最小値:%lf\n",min);

		min = 100000;
		for (int i=1;i<matrix+1;i++){  //基底変数を決定する
			if(min > a[i][n+matrix]/a[i][column] && a[i][column] > 0){
				min = a[i][n+matrix]/a[i][column];//増加限界を計算し、そのうち最小の増加限界を持つ行を変数に格納する。
				line = i; 
			}
		}
		double p = a[line][column];

		for (int i=0;i<matrix+1;i++){ //先ほど変数に格納した(行,列)の値をピボットとして掃き出し計算を行い、新しいシンプレックス表を作る。
			double i_column = a[i][column];
			for (int j=0;j<n+matrix+1;j++){
				if(line != i){
					a[i][j] = a[i][j]-a[line][j]*(i_column/p);
					
				}
				printf("%lf\t",a[i][j]);
			}
			printf("\n");
		}
		for(int j=0;j<n+matrix+1;j++){
			a[line][j] = a[line][j]/p;
		}
	}
	printf("シンプレックス表\n");
	for(int i=0;i<matrix+1;i++){
		for(int j=0;j<n+matrix+1;j++){
			printf("%lf\t",a[i][j]);
		}
		printf("\n");
	}
	printf("最大値は%lf\n",a[0][n+matrix]);
	for(int i=1;i<matrix+1;i++){
		for(int j=0;j<n;j++){
			if(a[i][j] == 1){
				printf("x_%d = %lf\n",j+1,a[i][n+matrix]);
			}
		}
	}
	return 0;
}