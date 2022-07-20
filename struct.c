#include <stdio.h>
typedef struct person{
	int age;
	double weight;
	double height;
}person;

int main(){
	person person[1];
	printf("年齢");
	scanf("%d",&person[0].age);
	printf("体重");
	scanf("%lf",&person[0].weight);
	printf("身長");
	scanf("%lf",&person[0].height);
	printf("年齢:%d,体重:%lf,身長:%lf",person[0].age,person[0].weight,person[0].height);

	return 0;
}