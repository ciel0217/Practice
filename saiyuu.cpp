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
#define N 500.0
using namespace std;
using namespace Eigen;
using Eigen::MatrixXd;

int main(){
	random_device rd;
	default_random_engine engine(rd());
	normal_distribution<> dist(0.0,1.0);
	int n=N;
	double set[n+1],fx[n+1];
	double i=0;
	double myu,sigma2;
	int j=0;
	for(j=0;j<=n;j++){
		set[j]=dist(engine);
	}

	for(j=0;j<=n;j++){
		myu+=set[j];
	}
	myu/=N;
	cout<<myu<<'\n';
	for(j=0;j<=n;j++){
		sigma2+=pow(set[j]-myu,2);
	}

	sigma2/=N;
	cout<<sigma2<<'\n';;
	for(j=0;j<=n;j++){
		fx[j]=(1.0/(sqrt(2.0*M_PI*sigma2)))*exp(-(1.0/(2.0*sigma2))*(pow(set[j]-myu,2)));
	}

	
	FILE *fp;
	fp=popen("gnuplot5-x11 -persist","w");
      //  fp = stdout;
	fprintf(fp,"plot '-', '-' with lines\n");

	for(j=0;j<=n;j++){
		fprintf(fp, "%lf\t%lf\n",set[j],fx[j]);
	}
	fprintf(fp,"e\n");
	for(i=-4;i<=4;i+=8.0/1000.0){
		fprintf(fp, "%lf\t%lf\n",i,(1.0/sqrt(2.0*M_PI))*exp(-0.5*pow(i,2)));
	}
	fprintf(fp,"e\n");

	return 0;
}

