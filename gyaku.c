#include <stdio.h>
int main(void){
	int A[7]={1,2,3,4,5,6,7};
	int B[7];
	for(int a=0;a<7;a++){
		B[a]=A[6-a];
	}
	for(int c=0;c<7;c++){
		printf("%d",B[c] );
	}
	return 0;
}