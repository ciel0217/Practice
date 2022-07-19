#include <stdio.h>

int main(){
	int N,Q;
	char s[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char ch;
	char ans[25];
	char check='\0';


	scanf("%d%d",&N,&Q);
	
for(int i=0;i<N;i++){
	for(int j=0;j<N-1;j++){
		if(i==(j+1) || (j+1)<i){
		}else{
		printf("?%c%c\n",s[i],s[j+1]);
		fflush(stdout);
		scanf("%c",&check);
		scanf("%c",&check);
			if(check == '>'){
				ch=s[i];
				s[i]=s[j+1];
				s[j+1]=ch;
			}
		}
	}
}
		printf("!");
		for(int i=0;i<N;i++){
		printf("%c",s[i]);
		fflush(stdout);
		}
		printf("\n");
		return 0;
}
