#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


int main(){
	srand((unsigned int)time(0));
	int i,m,j;
	double pai=0;
	for(i=0;i<10000;i++){
		m=0;
		for(j=0;j<=100000;j++){
			if((pow((double)rand()/RAND_MAX,2))+(pow((double)rand()/RAND_MAX,2))<=1){
				m+=1;
			}
		}
		pai+=(4.0*m)/j;
	}
	pai=pai/i;
	printf("%lf",pai);
	return 0;
}
//3.141235