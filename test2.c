#include <stdio.h>
int div(int a,int b){
    return b==0?a:div(b,a%b); 
}
int com(int a,int b){
	return a*b/div(a,b);
}
int main(void){
	printf("%d\n",div(1071,1029) );
	printf("%d\n",div(12707,12319) );
	printf("%d\n",com(1071,1029));
	printf("%d\n",com(12707,12319));
		
	return 0;
}
/*
21
97
52479
1613789
*/