#include <stdio.h>
#include <time.h>
int n,G[30],count=0,g;
int ins(int A[],int n,int g){			//挿入ソート
	for(int i=g;i<n;i++){
		int v=A[i];
		//printf("v=A[%d]=%d\n",i,v);
		int j=i-g;
		while(A[j]>v && j>=0){			//なんでここがwhileなのかっていうと最後のh=1の時の
			//printf("%2d>%2d\n",A[j],v); //ため。h=1のときvの値より小さい値が見つかるまで左に
			A[j+g]=A[j];				//移動し続けるから。
			//printf("A[%d]=%d\n",j+g,A[j]);
			/*for(int i=0;i<n;i++){
				printf("%3d",A[i]);
			}*/
		//	printf("\n");
			j-=g;							//見てみればわかるが、シェルソートの時は意味をなしていない
		}									//値を交換するだけならバブルソートみたいにやればいい。
											//だけど挿入ソートは小さい値が見つかるまで繰り返すためそんなこと
											//いちいちやってたら計算時間が延びる。だからこの手法を使った。
		A[j+g]=v;
		//printf("vの値を代入:A[%d]=%d\n",j+g,A[j+g]);
		/*for(int i=0;i<n;i++){
			printf("%3d",A[i]);
		}
		printf("\n");*/
	}
	return 0;
}
/*
int sh(int A[],int n){//シェルソート
		G[0]=1;
	for(int h=1;h<n/9;h=h*3+1){
		G[count]=h;//{1,4,13,...}の作成
		count++;
	}
	for(int i=count;i>=0;i--){
		//printf("h=%d\n",G[i]);
		ins(A,n,G[i]);
	}
	return 0;
}
*/
//上のやつは要素数が馬鹿でかいときに有効。試したいなら頑張って配列入力してね。

int sh(int A[],int n){			//こっちの方が要素数少なくても上のやつと
	for(int h=1;;){				//同じ動きするから実用的
		if(h>n)break;
		G[count]=h;
		count++;
		h=h*3+1;
	}
	for(int i=count-1;i>=0;i--){//一回countが余分に回ってるから-1
		//printf("h=%d\n",G[i]);
		ins(A,n,G[i]);
	}
	return 0;
}


int main(){
	n=10;
	int A[10]={3,8,1,25,9,0,34,7,10,4};
	clock_t end,start;
	start=clock();
	printf("変化前\n");
	for(int i=0;i<n;i++){
		printf("%3d",A[i]);
	}
	printf("\n");
	sh(A,n);
	printf("変化後\n");
	for(int i=0;i<n;i++){
		printf("%3d",A[i]);
	}
	printf("\n");
	end=clock();
	printf("処理時間:%lf[ms]\n",(double)(end-start));
	return 0;
}