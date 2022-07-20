#include <stdio.h>
int main(){
	int test[5];
	int tmp,i,n;
	for (i = 0;i<5;i++){
	scanf("%d",&test[i]);
	}
	for(n = 0;n<5;n++){
	for(i = n+1;i<5;i++){
		if( test[n]<test[i]){
			tmp = test[n];
			test[n]=test[i];
			test[i]=tmp;

		}
	}
}
for(i=0;i<5;i++){
	printf("%d\n",test[i]);
}
	return 0;
}	
    
	