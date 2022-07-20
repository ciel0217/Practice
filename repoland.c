#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top,S[1000];

void push(int x){
	S[++top]=x;
}

int pop(){
	top--;
	return S[top+1];
}

int main(){
	int a,b;
	int top=0;
	char s[100];

	while(scanf("%s",s)!=-1){//CTRL+Cで終わり
		if(s[0]=='+'){
			a=pop();
			b=pop();
			push(a+b);
		}else if(s[0]=='-'){
			a=pop();
			b=pop();
			push(a-b);
		}else if(s[0]=='*'){
			a=pop();
			b=pop();
			push(a*b);
		}else if(s[0]=='/'){
			a=pop();
			b=pop();
			push(a/b);
		}else{
			push(atoi(s));//文字列を数字に変える
		}
	}

	printf("%d\n",pop());
	return 0;
}