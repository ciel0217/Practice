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
#define N 100
using namespace std;
using namespace Eigen;
using Eigen::MatrixXd;

int main(){
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<> rand(-20,20);
	VectorXd w(3);
	MatrixXd fai(3,N+1);
	VectorXd d(3);
	double x[N],y[N];
	double t[N],count=0;
	double E,a;
	w(0)=w(1)=w(2)=0.0;
	for(int i=0;i<N;i++){
		x[i]=rand(mt);
		y[i]=rand(mt);
		fai(0,i)=1.0;
		fai(1,i)=x[i];
		fai(2,i)=y[i];
	}
	while(1){
		E=0;
		for(int i=0;i<N;i++){
			a=w.transpose()*fai.col(i);
			if(a>=0){
				t[i]=1;
			}else {
				t[i]=-1;
			}
			if(a*t[i]<=0){
				E+=t[i]*a*-1;
			    w+=t[i]*fai.col(i);
				cout<<w<<"\n";
			}

		}
		count++;
		if(E==0)break;
		if(count==50)break;
	}
	
	FILE *fp;
	fp=popen("gnuplot5-x11 -persist","w");
	fprintf(fp, "set yrange[-20:20]\n");
	fprintf(fp,"plot %lf*x+%lf\n",-(w(1)/w(2)),-(w(0)/w(2)));
	fprintf(fp, "replot '-' with points pt 7,'-'\n");
	for(int j=0;j<N;j++){
		if(t[j]==1)fprintf(fp,"%lf\t%lf\n",x[j],y[j]);
	}
	fprintf(fp,"e\n");

	for(int j=0;j<N;j++){
		if(t[j]==-1)fprintf(fp,"%lf\t%lf\n",x[j],y[j]);
	}
	fprintf(fp,"e\n");
	return 0;
}

	




	
