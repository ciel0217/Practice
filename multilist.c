#include<stdio.h>
#include <stdlib.h>
#include <string.h>
/* データ型の定義 */
#define MAX_GAKUSEI 2000
#define MAX_KAMOKU  400

struct SEISEKI {
    struct SEISEKI *glink;
    struct SEISEKI *klink;
    struct GAKUSEI *gakusei;
    struct KAMOKU *kamoku;
    short seiseki;
};

struct GAKUSEI {
    struct SEISEKI *glink;
    char *name;
} gakusei[MAX_GAKUSEI];

struct KAMOKU {
    struct SEISEKI *klink;
    char *name;
} kamoku[MAX_KAMOKU];


/* 初期化 */
void init(){
    int i;
    for (i = 0; i < MAX_GAKUSEI; i++){
        gakusei[i].glink = NULL;
    }
    for (i = 0; i < MAX_KAMOKU; i++){
        kamoku[i].klink = NULL;
    }
    return;
}

/* 学生番号x, 課目番号yの成績をaにする */
void add(int x,char *q, int y, char *w, short a){
    struct SEISEKI *p;
    if ((p = (struct SEISEKI*)malloc(sizeof(struct SEISEKI))) == NULL){
        /* エラー処理 */
        printf("error\n");
        return ;
    }
    gakusei[x].name = (char *)malloc(sizeof(char)*256);
    kamoku[x].name = (char *)malloc(sizeof(char)*256);
    p->glink = gakusei[x].glink;
    gakusei[x].glink = p;
    strncpy(gakusei[x].name,q,strlen(q));          //学校の教科書はここが書いてないから文字が入力できない
    p->klink = kamoku[y].klink;
    kamoku[y].klink = p;
    strncpy(kamoku[x].name,w,strlen(w));
    p->gakusei = &gakusei[x];
    p->kamoku  = &kamoku[y];
    p->seiseki = a;
    //printf("%s\n",gakusei[x].name);
    return;
}

/* 学生xの課目yの成績を得る（履修していないときは、-1を返す）*/
short get_seiseki(int x, int y){
    struct SEISEKI *p;
    for (p = gakusei[x].glink; p != NULL; p = p->glink){
        if (p->kamoku == &kamoku[y]){
            return (p->seiseki);
        }
    }
    return(-1);
}

/* ある課目（課目番号x）を履修している学生の名前と成績をプリントする */
void print_gakusei(int x){
    struct SEISEKI *p;
    for (p = kamoku[x].klink; p != NULL; p = p->klink){
        printf("%s\n", p->gakusei->name);
    }
    return;
}

int main(){
    init();
    char s[40],kname[40];
    int num,knum,grade,check,n,i=0;
    printf("入力数:");
    scanf("%d",&n);
    while(i<n){
        printf("名前と番号\n");
        scanf("%s%d",s,&num);
        printf("課目番号と科目名と点数\n");
        scanf("%d%s%d",&knum,kname,&grade);//日本語入力はできない気がする
       // printf("%s:%s",s,kname);
        add(num,s,knum,kname,grade);  
        i++; 
    }
    check=0;
    i=0;
    while(i<n){
        printf("見たい学生の番号と科目番号\n");
        scanf("%d%d",&num,&knum);
        printf("点数:%d\n",get_seiseki(num,knum));
        printf("履修している人\n");
        print_gakusei(knum);
        i++;
    }
    return 0;
}