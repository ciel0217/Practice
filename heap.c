#include <stdio.h>

int swap(int *a, int *b){//入れ替えてるだけ
	int temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

int heapsort(int a[], int n){
	int Cnode, Pnode;//子のノード、親ノード

	while (n > 0){
		printf("n = %d\n", n);
		Pnode = n - 1;

		while (Pnode >= 0){
			Cnode = Pnode * 2 + 1;			//Pnodeの左のCnodeの添え字
			printf("親の値:a[%d]=%d\n",Pnode,a[Pnode]);
			printf("子の値:a[%d]=%d\n",Cnode,a[Cnode]);
			if (Cnode < n){
				if (a[Cnode] < a[Cnode + 1] && Cnode + 1 < n)		//左右で大きいほうを左の子にする
					swap(&a[Cnode], &a[Cnode + 1]);

				if (a[Cnode] > a[Pnode])			//子が親より大きければ入れ替え
					printf("子の値:a[%d]=%d > 親の値:a[%d]=%d\n",Cnode,a[Cnode],Pnode,a[Pnode]);
					swap(&a[Cnode], &a[Pnode]);
			}

			for(int i=0;i<n;i++){
				printf("%3d",a[i]);
			}
			printf("\n");
			Pnode--;
		}
		swap(&a[0], &a[n - 1]);
		for(int i=0;i<n;i++){
			printf("%3d",a[i]);
		}
		printf("\n");

		n--;
	}
	
	return 0;
}


int main(){
	int n=10;
	int a[10] = { 7, 9, 6, 8, 0, 1, 5, 10, 3, 2 };
	printf("変化前\n");
	for(int i=0;i<n;i++){
		printf("%3d",a[i]);
	}
	printf("\n");

	heapsort(a, n);

	printf("変化後\n");
	for(int i=0;i<n;i++){
		printf("%3d",a[i]);
	}
	return 0;
}