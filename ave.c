#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#define nm 100000
#define clo 100
int *num;

int set(){
    srand(time(NULL));
    for(int i=0;i<=nm;i++){
        num[i]=rand()%100000;
    }
    return 0;
}

int swap(int *a, int *b){//入れ替えてるだけ
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
int buble(int n){
     for(int i=0;i<n;++i){
        for(int j=n-1;j>i;--j){
            if(num[j]<num[j-1]){
                swap(&num[j],&num[j-1]);
            }
        }
    }
    return 0;
}

void selection_sort (int array_size) {
  int i, j, min_index;
    for (i = 0; i < array_size-1; i++) {
        min_index = i;   
        for (j = i + 1; j < array_size; j++) {
            if (num[j] < num[min_index]) {
                min_index = j; 
            }  
        }
    swap(&num[min_index], &num[i]);   
    }
}

int insertionSort( int array_size){
   int i, j, temp;
    for (i = 1; i < array_size; i++) {      /* i 番目の要素をソート済みの配列に挿入 */
        temp = num[i];             /* i 番目の要素を temp に保存 */
        for (j = i; j > 0 && num[j-1] > temp; j--) /* このループで */
            num[j] = num[j -1]; 
                               /* temp を挿入する位置を決める */
        num[j] = temp; 
    }
return 0;
}

void shell_sort ( int array_size) {
  int i, j, h,t;

  for (h = 1; h <= array_size/9; h = 3*h + 1);   // 間隔hを決める

  for ( ; h > 0; h /= 3) {  
    for (i = h; i < array_size; i++) {
      j = i;
      while ((j >= h ) && (num[j-h] > num[j])) {
        t=num[j];num[j]=num[j-h];num[j-h]=t;
        j -= h;
      }
    }
  }
}

void pushdown (int p[],int first, int last) {
  int parent = first;   // 親
  int child = 2*parent;   // 左の子
  while (child <= last) {
    if ((child < last) && (p[child] < p[child+1])) {
       child++;   // 右の子の方が大きいとき、右の子を比較対象に設定
    }
    if (p[child] <= p[parent]) { break; }   // ヒープ済み
    swap(&p[child], &p[parent]);
    parent = child;
    child = 2* parent;
  }
}

/* ヒープソート */
void heap_sort ( int array_size) {
  int i;
  for (i = array_size/2; i >= 1; i--) {
    pushdown(num, i, array_size);   // 全体をヒープ化
  }
  for (i = array_size; i >= 2; i--) {
    swap(&num[1], &num[i]);   // 最大のものを最後に
    pushdown(num, 1, i-1);   // ヒープ再構築
  }
}

void merge_sort (int p[],int work[], int low, int high) {
  int i, j, k, mid;
  if(low>=high)return;
  mid=(low+high)/2;
  merge_sort(p,work,low,mid);
  merge_sort(p,work,mid+1,high);
  for(int i=low;i<=mid;i++){
    work[i]=p[i];
  }
  for(int i=mid+1,j=high;i<=high;i++,j--){
    work[i]=p[j];
  }
  i=low;
  j=high;
  for(int k=low;k<=high;k++){
    if(work[i]<=work[j]){
      p[k]=work[i++];
    }else{
      p[k]=work[j--];
    }
   
  }
}

void q_sort( int left, int right)
{
    int pivot, l_hold, r_hold;

    l_hold = left;
    r_hold = right;
    pivot = num[left];
    while (left < right)
    {
        while ((num[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            num[left] = num[right];
            left++;
        }
        while ((num[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            num[right] = num[left];
            right--;
        }
    }
    num[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        q_sort(left, pivot-1);
    if (right > pivot)
        q_sort(pivot+1, right);
}
int main(){
    double *quick;
    int *work;
    work=(int *)malloc(sizeof(int)*nm);
    num=(int *)malloc(sizeof(int)*nm);
    quick=(double *)malloc(sizeof(double)*nm);
    clock_t start,end;
    for(int i=1;i<=nm;i*=2){
        quick[i]=0;
    }
    for(int i=0;i<10;i++){
        for(int j=1;j<=nm;j*=2){
            set();
            start=clock();
            q_sort(0,j);
            end=clock();
            quick[j]+=((double)end-(double)start)/CLOCKS_PER_SEC;
        }
    }

    for(int i=1;i<=nm;i*=2){
        quick[i]/=10;
    }

    FILE *fp;
    fp=popen("gnuplot5-x11 -persist","w");
    fprintf(fp, "set table 'quick.txt'\n");
    fprintf(fp, "plot '-' with lines\n");
    for(int i=1;i<=nm;i*=2){
        fprintf(fp, "%d\t%lf\n",i,quick[i]);
    }
    fprintf(fp, "unset table\n");
    fprintf(fp, "e\n");
    return 0;
}