#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EMPTY (KEY)0
#define DELETED (KEY)1

/*ハッシュ表の定義*/
#define BUCKET_SIZE 10


typedef int KEY;
typedef char DATA;

typedef struct bucket{
	KEY key;
	DATA data;
} BUCKET;

BUCKET table[BUCKET_SIZE];


/*rehash -- 再ハッシュを行う*/
int rehash(int h){
	return ((h + 1) % BUCKET_SIZE);
}
int hash(int h){
	return ((h + 1) % BUCKET_SIZE);
}

/*init -- ハッシュ表を初期化する */
void init(){
	int i;
	for (i = 0; i < BUCKET_SIZE; i++){
		table[i].key = EMPTY;
	}
}

int keyequal(KEY a,KEY b){
	return (a == b)?1:0;
}

/* find -- ハッシュ表を探索する 			*/
/*			DATAへのポインタを返す		*/
/*			見つからなければNULLを返す	*/
DATA *find(KEY key){
	int hh,count;
	KEY k;

	count = 0;
	hh = hash(key);
	while ((k = table[hh].key) != EMPTY){
		if (k != DELETED && keyequal(key, k))
			return &table[hh].data;
		if (++count > BUCKET_SIZE)
			return NULL;
		hh = rehash(hh);
	}
	return NULL;
}

/* insert -- ハッシュ表にデータを挿入する				*/
/*			 登録に成功したら1を返す					*/
/*			 登録に失敗(すでに同じキーを持つデータがある)	*/
/*			 したら0を返す							*/
int insert(KEY key, DATA *data){
	int count=0;
	KEY k;

	int h1 = hash(key);
	while ((k = table[h1].key) != EMPTY && k != DELETED){
		if (keyequal(key, k)){
			h1 = rehash(h1);
			break;
		}
		if (++count > BUCKET_SIZE){
			fprintf(stderr, "hash table overflow\n");
			exit(1);
		}
		h1 = rehash(h1);
	}
	table[h1].key = key;
	table[h1].data = *data;
	return 1;
}

/* delete -- ハッシュ表から削除する			*/
/*			 削除が成功したら1を返す			*/
/*			 データが見つからなければ0を返す	*/
int delete(KEY key){
	int h, count;
	KEY k;

	count = 0;
	h = hash(key);
	while ((k = table[h].key) != EMPTY){
		if (k != DELETED && keyequal(key, k)){
			table[h].key = DELETED;
			return 1;
		}
		if (++count > BUCKET_SIZE)
			return 0;
		h = rehash(h);
	}
	return 0;
}

int main(void){
	init();
	insert(1,"a");
	insert(2,"b");
	insert(3,"c");
	insert(3,"d");
	for(int i=0;i<BUCKET_SIZE;i++){
		printf("%d:%c\n",table[i].key,table[i].data );
	}
	return 0;
}