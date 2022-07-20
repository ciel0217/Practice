#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*ハッシュ表の定義*/
#define BUCKET_SIZE 50
typedef int KEY;
typedef char DATA;

typedef struct cell{
	KEY key;
	DATA data;
	struct cell *next;
} CELL;
CELL *table[BUCKET_SIZE];

/* init --ハッシュ表を初期化する */
void init(){
	int i;

	for(i = 0;i<BUCKET_SIZE;i++)
		table[i] = NULL;
}
int hash(int h){
	return ((h + 1) % BUCKET_SIZE);
}
int keyequal(KEY a,KEY b){
	return (a == b)?1:0;
}

/* find --ハッシュ表を探索する		 */
/*		  DATAへのポインタを返す		 */
/*		  見つからなければ、NULLを返す */
DATA *find(KEY key){
	CELL *p;
	
	for(p = table[hash(key)];p != NULL; p = p->next)
		if(keyequal(key, p->key))
			return &p->data;
	return NULL;
}

/* insert --ハッシュ表にデータを挿入する */
/*			登録に成功したら1を返す */
/*			登録に失敗(すでに同じキーを持つデータがある) */
/*			したら0を返す */
int insert(KEY key, DATA *data){
	CELL *p;
	int h;

	if(find(key) != NULL)
		return 0;
	if((p = malloc(sizeof(CELL))) == NULL){
		fprintf(stderr, "out of memory\n");
		exit(2);
	}
	h = hash(key);
	p->key = key;
	p->data = *data;
	p->next = table[h];
	table[h] = p;
	return 1;
}

/* delete --ハッシュ表から削除する */
/*			削除が成功したら1を返す */
/*			データが見つからなければ0を返す */
int delete(KEY key){
	int h;
	CELL *p, *q;

	h = hash(key);
	/*そのパケットは空か? */
	if(table[h] == NULL)
		return 0;
	/*リストの先頭のセルが削除すべきデータか? */
	if(keyequal(key, table[h]->key)){
		p = table[h];
		table[h] = p->next;
		free(p);
		return 1;
	}
	/*リストの2番目以降のセルについて順番にチェックする */
	for (q = table[h], p = q->next; p != NULL; q = p, p = p->next){
		if(keyequal(key, p->key)){
			q->next = p->next;
			free(p);
			return 1;
		}
		return 0;
	}
}


int main(){
	init();
	CELL *p;
	insert(1,"a");
	insert(1,"b");
	insert(2,"c");
	for(int i=0;i<BUCKET_SIZE;i++){
		if(table[i] != NULL){
			printf("table[%d]:{",i);
			p=table[i];
			for(; p != NULL;p=p->next){
				printf("{%c:",p->data);
				printf("%d}", p->key);
			}
			printf("}\n");
		}
	}
	return 0;
}
