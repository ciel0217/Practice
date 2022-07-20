#include <stdio.h>
#include <stdlib.h>

struct cell {
	int key;
	struct cell *next;
};

struct cell *n il;

void init(){
	nil=(struct cell *)malloc(sizeof(struct cell));
	nil->next=NULL;//nilにすると循環
}

void add(int a){
	struct cell *p=(struct cell *)malloc(sizeof(struct cell));
	struct cell *header,*prev;
	p->next=NULL;//nilにすると循環
	p->key=a;
	prev=nil;
	for(header=nil->next;header!=NULL;header=header->next){
		prev=header;
	}
	//printf("ok\n");
	prev->next=p;
	//printf("%d\n",p->key);
}

void deleteKey(int b){
	struct cell *header,*prev
	prev=nil;
	for(header=nil->next;header!=NULL;header=header->next){
		if(header->key==b){
			if(header->next!=NULL){
				prev->next=header->next;
				free(header);
				return ;
			}
			prev->next=nil;
			free(header);
		}
		prev=header;
	}
}

void printList(){
	struct cell *cur=nil->next;
	int isf = 0;
	while(1){
		if(cur == NULL)break;
		if(isf++ > 0)printf("");
		printf("%d",cur->key);
		cur=cur->next;
	}
	printf("\n");
	return ;
}

int main(){
	int n,num;
	int check;
	init();
	printf("入力数\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		add(num);
	}
	printf("表示:0\n削除:1\n");
	scanf("%d",&n);
	switch(n){
		case 0:
			printList();
			return 0;
			break;
		case 1:
			scanf("%d",&check);
			deleteKey(check);
			break;
		default:
			break;
	}
	printList();
	return 0;
}
