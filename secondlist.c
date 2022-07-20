#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Fori(g) for(int i=0;i<g;i++)
#define	Forj(g) for(int j=0;j<g;j++)
#define min(aa,bb) return (aa<bb)?aa:bb
#define max(aa,bb) return (aa<bb)?bb:aa


struct cell{
	struct cell *next,*prev;
	int key;
};

struct cell *nil,*head;

struct cell *search(int key){
	struct cell *cur=nil->next;
	while(cur != nil && cur->key!=key){
		cur=cur->next;
	}

	return cur;
}

void init(){
	nil=(struct cell *)malloc(sizeof(struct cell));
	nil->next = NULL;//NULLにすると循環じゃなくなる
	nil->prev = NULL;//NULLにすると循環じゃなくなる
	head=nil;
}

void printList(){
	struct cell *cur=head->next;
	int isf = 0;
	while(1){
		if(cur == NULL)break;
		//if(cur == nil)break;
		if(isf++ > 0)printf("");
		printf("%d",cur->key);
		cur=cur->next;
	}
	printf("\n");
}

void deleteNode(struct cell *t){
	if(t==nil){
		printf("先頭なので無理\n");
		return;
	}
	t->prev->next=t->next;
	t->next->prev=t->prev;
	free(t);
}

void deleteFirst(){//keyが指す値の一個次の値(next)を消す
	printf("First\n");
	deleteNode(nil->next);
}

void deleteLast(){//keyが指す値の一個前の値	(prev)を消す
	printf("Last\n");
	deleteNode(nil->prev);
}

void deleteKey(int key){//keyが指す値を消す
	deleteNode(search(key));
}

void insert(int key){
	struct cell *x=(struct cell *)malloc(sizeof(struct cell));
	x->key=key;
	//x->next=nil->next;//NULLにすると循環じゃない
	x->next=NULL;
	//nil->next->prev=x;//ここを消す
	nil->next=x;
	x->prev=nil;
	nil=nil->next;
}

int main(){
	int key,n,i;
	int size=0;
	char com[20];
	int np=0,nd=0;
	scanf("%d",&n);
	init();
	for(i=0;i<n;i++){
		scanf("%s%d",com,&key);//keyの値を消すときはd、それ以外はdL、dFと入力
		if(com[0]=='i'){
			insert(key);
			np++;
			size++;
		}else if(com[0]=='d'){
			if(com[1]=='F'){
				deleteFirst();
			}else if(com[1]=='L'){
				deleteLast();
			}else{
				deleteKey(key);
				nd++;
			}
			size--;
		}
	}
	printList();
	return 0;
}