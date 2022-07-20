#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void ins(int n[],int length){
	int temp;
	for(int i=1;i<length;i++){
		int j=i;
		while(j>=1 && n[j-1]>n[j]){
			temp=n[j];
			n[j]=n[j-1];
			n[j-1]=temp;
			j--;
			//for(int i=0;i<length;i++){
				//printf("%3d",n[i]);
			//}
			//printf("\n");
		}
	}
}
/*void selection(int n[],int length){
	int lowest,lowkey,temp;
	for(int i=0;i<length-1;i++){
		lowest=i;
		lowkey=n[i];
		for(int j=i+1;j<length;j++){
			if(n[j]<lowkey){
				lowest=j;lowkey=n[j];
			}	
		}
		temp=n[i];
		n[i]=n[lowest];
		n[lowest]=temp;	
		for(int i=0;i<length;i++){
				printf("%3d",n[i]);
		}
		printf("\n");
	}
}

void bubble(int n[],int length){
	for(int i=0;i<length-1;i++){
		for(int j=length-1;j>=0;j--){
			if(n[i]>n[j]){
				int temp=n[i];
				n[i]=n[j];
				n[j]=temp;
			}
		}
		for(int i=0;i<length;i++){
		printf("%3d",n[i]);
		}
		printf("\n");
	}
	
}
*/
int main(){
	int n=10;
	int A[10]={3,8,1,25,9,0,34,7,10,4};
	clock_t end,start;
	start=clock();
	printf("変化前\n");
	for(int i=0;i<n;i++){
		printf("%3d",A[i]);
	}
	printf("\n");
	ins(A,n);
	end=clock();
	printf("変化後\n");
	for(int i=0;i<n;i++){
		printf("%3d",A[i]);
	}
	printf("\n%d[ms]\n",(end-start));
	return 0;
}