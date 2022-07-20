#include<iostream>
#include<random>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define EIGEN_NO_DEBUG // コード内のassertを無効化．
#define EIGEN_DONT_VECTORIZE // SIMDを無効化．
#define EIGEN_DONT_PARALLELIZE // 並列を無効化．
#define EIGEN_MPL2_ONLY // LGPLライセンスのコードを使わない
#include </mnt/c/Users/shieru/documents/eigen/Eigen/core>
#include </mnt/c/Users/shieru/documents/eigen/Eigen/Dense>
#define M 3
#define N 5
using namespace std;
using namespace Eigen;
using Eigen::MatrixXd;

int main(){
	random_device rd;
	default_random_engine engine(rd());
	VectorXd w(3);
	VectorXd fai(3);
	VectorXd d(3);
	double x[N],y[N];
	double t[N],count=0;
	double E,a;
	int n1=0,n2=0;
	w(0)=w(1)=w(2)=0.0;
	/*
	for(int i=0;i<N;i++){
		x[i]=engine()%100*0.5+0.5;
		y[i]=engine()%100*0.5+0.5;
		if(y[i]<0){
			x[i]=-1*(abs(x[i]));
			y[i]=-1*(abs(y[i]));
		}else{
			x[i]=abs(x[i]);
			y[i]=abs(y[i]);
		}
	}
	*/
	x[0]=-3;x[1]=9;x[2]=0;x[3]=5;x[4]=4;
	y[0]=2;y[1]=5;y[2]=5;y[3]=5;y[4]=14;
	//*/
	
	while(1){
		E=0;
		for(int i=0;i<N;i++){
			fai(0)=1.0;
			fai(1)=x[i];
			fai(2)=y[i];
			a=w.transpose()*fai;
			if(a>=0){
				t[i]=1;
				n1++;
			}else {
				t[i]=-1;
				n2++;
			}
			if(a*t[i]<=0){
				E+=t[i]*a*-1;
				d=t[i]*fai.array();
			    w+=d;
				cout<<w<<"\n";
			}
		}
		count++;
		if(E==0)break;
		if(count==50)break;
	}
	
	FILE *fp;
	fp=popen("gnuplot5-x11 -persist","w");
	fprintf(fp,"plot '-','-'with points pt 7,'-' with lines\n");
	for(int j=0;j<N;j++){
		if(t[j]==-1)fprintf(fp,"%lf\t%lf\n",x[j],y[j]);
	}
	fprintf(fp,"e\n");

	for(int j=0;j<N;j++){
		if(t[j]==1)fprintf(fp,"%lf\t%lf\n",x[j],y[j]);
	}
	fprintf(fp,"e\n");
	for(int j=0;j<N;j++){
		fprintf(fp,"%lf\t%lf\n",x[j],-1*(w(0)+w(1)*x[j])/w(2));
	}

	fprintf(fp,"e\n");
	return 0;
}

	




	
