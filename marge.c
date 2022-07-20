#include <stdio.h>
int work[8]; // 作業用配列
void show(int [],int,int);
void show(int [],int,int);
void merge_sort(int [],int,int);
void show(int work[],int s,int n){
  printf("workを表示\n");
  for(int i=0;i<=n;i++){
    printf("work[%d]:%1d\t",i,work[i]);
  }
  printf("\n");
  return ;
}
void show2(int array[],int s,int n){
  printf("arrayを表示\n");
  for(int i=0;i<=n;i++){
    printf("array[%d]:%1d\t",i,array[i]);
  }
  printf("\n");
  return ;
}

void merge_sort (int array[], int low, int high) {
  int i, j, k, mid;
  if(low>=high)return;
  mid=(low+high)/2;
  printf("low=%d,mid=%d,high=%d\n",low,mid,high);
  merge_sort(array,low,mid);
  printf("右を整列\n");
  printf("low=%d,mid+1=%d,high=%d\n",low,mid+1,high);
  merge_sort(array,mid+1,high);
  printf("前半の要素を代入\n");
  for(int i=low;i<=mid;i++){
    work[i]=array[i];
    printf("work[%d]=%d\t",i,array[i]);
  }
  printf("\n");
  show(work,low,mid);
  printf("後半の要素を逆順に代入\n");
  for(int i=mid+1,j=high;i<=high;i++,j--){
    work[i]=array[j];
    printf("work[%d]=%d\t",i,array[j]);
  }
  printf("\n");
  show(work,mid+1,high);
  i=low;
  j=high;
  for(int k=low;k<=high;k++){
    if(work[i]<=work[j]){
      array[k]=work[i++];
    }else{
      array[k]=work[j--];
    }
   
  }
  show2(array,k,high);
  printf("\n");
}

int main(){
  int n=8;
  int array[8] = {55, 13, 3, 45, 74, 87, 46, 30};
  printf("変化前\n");
  for(int i=0;i<n;i++){
    printf("%3d",array[i]);
  }
  printf("\n");

  merge_sort(array,0,n-1);
  printf("work\n");
    for(int i=0;i<n;i++){
      printf("%3d",work[i]);
    }
    printf("\n");
  printf("変化後\n");
  for(int i=0;i<n;i++){
    printf("%3d",array[i]);
  }
  return 0;
}
