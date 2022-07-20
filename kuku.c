#include <stdio.h>
int main(char argc,char *argv[]){
	int i,j;
	FILE *fp;
	fp=fopen(argv[1],"w");

	for(i=1;i<=5;i++){
		for(j=1;j<=5;j++){
			fprintf(fp,"%3d",i*j);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
	return 0;
}