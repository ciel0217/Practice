#include <stdio.h>
#include <stdlib.h>
struct node{
	int label;
	struct node *right,*left;
};

struct node *Node,*root;

void initL(struct node *x){
	root =(struct node *)malloc(sizeof(struct node));
	root->right=NULL;
	root->left=NULL;
	x->left=root;
}

void initR(struct node *a){
	root=(struct node *)malloc(sizeof(struct node));
	root->right=NULL;
	root->left=NULL;
	a->right=root;
}
/*void bfs(){						//幅優先探索(テスト出ないけど面白いよ)
	int tail=0,head=0;
	struct node *cur=Node,*q[100];
	while(1){
		printf("%d",cur->label);
		if(cur->right != NULL ){
			q[tail]=cur->right;
			tail++;
			printf("-");
		}
		if(cur->left != NULL){
			q[tail]=cur->left;
			tail++;
			printf("\n|\n");
		}
		if(head>5)break;
		cur=q[head];
		head++;
	}
}
*/
void Inorder(struct node *x){
	if (x == NULL) return;
	Inorder(x->left);
	printf("%d\n",x->label);
	Inorder(x->right);
	return;
}

void Preorder(struct node *x){
	if (x == NULL) return;
	printf("%d\n",x->label);
	Preorder(x->left);
	Preorder(x->right);
	return;
}

void Postorder(struct node *x){
	if (x == NULL) return;
	Postorder(x->left);
	Postorder(x->right);
	printf("%d\n",x->label);
	return;
}



int main(){
	Node=(struct node *)malloc(sizeof(struct node));
	Node->right=NULL;
	Node->left=NULL;
	Node->label=1;
	printf("%d\n",Node->label);
	printf("|\n");
	initL(Node);
	Node->left->label=2;
	printf("%d\t",Node->left->label);
	printf("---");
	initR(Node->left);
	Node->left->right->label=7;
	printf("\t%d\n",Node->left->right->label);
	printf("|\n");
	initL(Node->left);
	Node->left->left->label=3;
	printf("%d\t",Node->left->left->label);
	printf("---");
	initR(Node->left->left);
	Node->left->left->right->label=4;
	printf("\t%d\t",Node->left->left->right->label);
	printf("---");
	initR(Node->left->left->right);
	Node->left->left->right->right->label=5;
	printf("\t%d\n",Node->left->left->right->right->label);
	printf("\t\t|\n");
	initL(Node->left->left->right);
	Node->left->left->right->left->label=6;
	printf("\t\t%d\n",Node->left->left->right->left->label);
	printf("Preorder\n");
	Preorder(Node);
	printf("\n");
	printf("Inorder\n");
	Inorder(Node);
	printf("Postorder\n");
	Postorder(Node);

	return 0;
}