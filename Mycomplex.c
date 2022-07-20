#include "Mycomplex.h"
#include <stdio.h>
#include <math.h>

void add(struct math *p3,struct math *p4){
	double ans=0.0;
	double ans2=0.0;
	ans=((p3->real)+(p4->real));
	ans2=((p3->imagin)+(p4->imagin));
	printf("足し算:");
	printf("%lf+%lfi\n",ans,ans2);
}

void dec(struct math *p3,struct math *p4){
	double ans=0.0;
	double ans2=0.0;
	ans=((p3->real)-(p4->real));
	ans2=((p3->imagin)-(p4->imagin));
	printf("引き算:");
	printf("%lf+%lfi\n",ans,ans2);
}

void abso(struct math *p3,struct math *p4){
	double ans=0.0;
	double ans2=0.0;
	ans=(sqrt(pow((p3->real),2)+pow((p3->imagin),2)));
	ans2=(sqrt(pow((p4->real),2)+pow((p4->imagin),2)));
	printf("絶対値:");
	printf("%lf:%lf\n",ans,ans2);
}
