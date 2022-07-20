#include <stdio.h>

int main(){
	int a[5]={3,75,65,87,1};
	int b[5],min,c,tmp; 
	for(int i=0;i<5;i++){
		min=a[i];
		for(int j=i;j<5;j++){
			if(min>a[j]){
				min=a[j];
				c=j;
			}
		}
			tmp=a[i];	
			a[i]=a[c];
			a[c]=tmp;
	}
	for(int i=0;i<5;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}