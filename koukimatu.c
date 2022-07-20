#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct NODE{
	int data, height;
	struct NODE *left, *right;
}NODE;

NODE *search(int key);
NODE *insert(NODE **node, int key);

NODE *rightRotate(NODE **y);
NODE *leftRotate(NODE **y);

int keyequall(int a, int b);
int keylt(int a, int b);
int height(NODE *p);
int getBalance(NODE *p);
int max(int a, int b);

void preorder(NODE *p);
void inorder(NODE *p);

NODE *root=NULL;

int keyequall(int a, int b){
	if (a==b)
		return 1;
	else
		return 0;
}

int keylt(int a, int b){
	if(a<b)
		return 1;
	else
		return 0;
}

int getBalance(NODE *p){
	return (p==NULL) ? 0 : height(p->left) - height(p->right);
}

int height(NODE *p){
	return (p==NULL) ? 0 :p->height;
}

int max(int a, int b){
	return (a>b) ? a : b;
}

NODE *search(int key){
	NODE *p;

	p = root;
	while(p != NULL){
		if(keyequall(key, p->data))
			return p;
		else if(keylt(key, p->data))
			p = p->left;
		else
			p = p->right;
	}
	return NULL;
}

NODE *insert(NODE **node, int key){
	NODE **p, *new;
	int balance;

	p = &(*node);
	if (*p == NULL){
		if((new = (NODE*)malloc(sizeof(NODE))) == NULL){
			printf("Out of memory!\n");
			return NULL;
		}
		new->left = NULL;
		new->right = NULL;
		new->data = key;
		*node = new;
		return new;
	}
	else if (keylt(key, (*p)->data))
		(*p)->left = insert(&(*p)->left, key);
	else if (!keylt(key, (*p)->data))
		(*p)->right = insert(&(*p)->right, key);
	else
		return *node;

	/*2.祖先ノードの高さを更新 */
	(*node)->height = 1 + max(height((*node)->left), height((*node)->right));

	/*3.この祖先ノードのバランスファクタを返す */
	balance = getBalance(*node);
	//printf("%d\n",balance );
	/*
	平衡していない状態には4つの場合がある
	*/
	// (左、左) ：左部分木の左部分木が長い場合
	printf("key=%d\n",key);
	if((*node)->left != NULL && (*node)->right == NULL){
		if(balance > 1 && key < (*node)->left->data){
			return rightRotate(&(*node));
		}else if(balance < -1 && key < (*node)->left->data){
			printf("a\n");
		    return leftRotate(&(*node));
		}
	}else if((*node)->right != NULL && (*node)->left == NULL){
		if(balance > 1 && key > (*node)->right->data){
			printf("b\n");
	    	return leftRotate(&(*node));
	    }else if(balance < -1 && key > (*node)->right->data){
	    	printf("(*node)->right->data) = %d\n",(*node)->right->data);
			return leftRotate(&(*node));
	    }
	}else{
		if(balance > 1 && key < (*node)->left->data){
			printf("a\n");
			return rightRotate(&(*node));
		}else if(balance > 1 && key > (*node)->right->data){
			printf("b\n");
	    	return leftRotate(&(*node));
		}else if(balance < -1 && key < (*node)->left->data){
			printf("c\n");
			return rightRotate(&(*node));
		}else if(balance < -1 && key > (*node)->right->data){
			printf("d\n");
			return leftRotate(&(*node));
		}
	}
	/*if(balance > 1 && key < (*node)->left->data){
		printf("node->data:%d  key:%d < (*node)->left->data:%d\n",(*node)->data,key,(*node)->left->data );
		return rightRotate(&(*node));
	}else if(balance > 1 && key > (*node)->right->data){
	    return leftRotate(&(*node));
	}else if(balance < -1 && key < (*node)->left->data){
		return rightRotate(&(*node));
	}else if(balance < -1 && key > (*node)->right->data){
		return leftRotate(&(*node));
	}
	*/
	printf("node->data=%d\n",(*node)->data);
	return *node;
}

void preorder(NODE *p){
	if(p == NULL)
		return ;
	printf("%d\n", p->data);
	preorder(p->left);
	printf("NULL\n");
	preorder(p->right);
}

void inorder(NODE *p){
	if(p == NULL)
		return;
	inorder(p->left);
	printf("%d\n", p->data);
	inorder(p->right);
}

/**
*木を右回転する
*@param y 右回転したい部分木の根
*@return 右回転後の根
**/
NODE *rightRotate(NODE **y){
	NODE *x, *t;

	x = (*y)->left;

	t = x->right;

	x->right = (*y); //回転を行う

	(*y)->left = t;

	(*y)->height = max(height((*y)->left), height((*y)->right)) - 1;
	x->height = max(height(x->left), height(x->right)) - 1;
	printf("x->data=%d\n",x->data);
	return x;//新しい木の根を返す
}

NODE *leftRotate(NODE **y){
	NODE *x, *t;

	x = (*y)->right;

	t = x->left;

	x->left = (*y);
	(*y)->right = t;

	(*y)->height = max(height((*y)->right),height((*y)->left)) - 1;
	x->height = max(height(x->right), height(x->left)) - 1;
	printf("x->data=%d\n",x->data);
	return x;
}
int main(void){

	NODE *pt;

	root = insert(&root, 5);
	root = insert(&root, 4);
	root = insert(&root, 3);
	/*root = insert(&root, 8);
	root = insert(&root, 9);
	/*root = insert(&root, 15);
	*/
	printf("inorder\n");
	inorder(root);
	printf("preorder\n");

	preorder(root);

	return 0;
}