#include <stdio.h>
char c[502][502];
int check[100][100];
int flag=0;
int H,W;
void search(int x,int y){
	if(c[x][y]=='#' || x<0 || y<0 || W<=x || H<=y)return;
	if(check[x][y])return;
	if(c[x][y]=='g')flag=1;
	check[x][y]=1;
	search(x+1,y);
	search(x-1,y);
	search(x,y+1);
	search(x,y-1);
	return;
}

int main(){
	scanf("%d%d",&H,&W);
	for(int i=0;i<H;i++){
		scanf("%s",c[i]);
	}

	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(c[i][j]=='s'){
				search(i,j);
			}
		}
	}
	if(flag)printf("Yes\n");
	else printf("No\n");
	return 0;

}