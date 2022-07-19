#include "header.h"

int inner(int *p1,int *p2,int num){
	int sum=0;
	for(int b=0;b<num;b++){
	sum += p1[b]*p2[b];
	}
	return sum;
}