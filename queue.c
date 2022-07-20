#include <stdio.h>
#define MAX 4
int head,tail,n,Q[MAX],x;

int isFull(){
	return head==((tail+1)%MAX);//条件を満たしていたら1
}

void enqueue(int y){
	if(isFull()){
		printf("isFull\n");
	}
	Q[tail]=y;
	if (tail+1 ==MAX){
		tail=0;
	}else{
		tail++;
	}
}

int dequeue(){
	x=Q[head];
	printf("head:%d\n",head);
	if(head+1==MAX){
		head=0;
	}else{
		head=(head+1)%MAX;//一応条件分岐しているが、別にしなくても同じ動きをすると思う
	}

	return x;
}

int main(){
	int q,d;
	scanf("%d",&n);
	head=0;
	tail=0;
	for(int i=0;i<n;i++){
		scanf("%d",&q);
		enqueue(q);
	}
	printf("#############\n");
	for(int i=0;i<MAX;i++){
		d=dequeue();
		printf("%d\n",d);
	}
	return 0;
}