#include <stdio.h>
#define MAX 10
typedef struct{
	int key;
	char string[256];
}Item;
Item bag[MAX];
int check=0;
void add(Item e){
	bag[check]=e;
	check++;
}
int isEmpty(){
	return check>0?0:1;
}

int size(){
	return check;
}
int main(){
	Item a={0,"ad"},b={1,"cd"};
	add(a);
	if(isEmpty()){
		printf("空\n");
	}else{
		printf("%d:%s\n",size(),bag[0].string);
	}
	return 0;
}