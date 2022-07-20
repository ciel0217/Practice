#include<iostream>
#include<random>
#include <cmath>
#include <complex>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <png++/png.hpp>
#define EIGEN_NO_DEBUG // コード内のassertを無効化．
#define EIGEN_DONT_VECTORIZE // SIMDを無効化．
#define EIGEN_DONT_PARALLELIZE // 並列を無効化．
#define EIGEN_MPL2_ONLY // LGPLライセンスのコードを使わない
#include </mnt/c/Users/shieru/documents/eigen/Eigen/core>
#include </mnt/c/Users/shieru/documents/eigen/Eigen/Dense>
//#define k 3
using namespace std;
using namespace Eigen;
using Eigen::MatrixXd;
#define N 1000 //train-data size ; limit 60000
//#define K 6 //k-mean 
int main(){
	int height,width;
	height=28;
	width=28;//28*28 pixels
	MatrixXd image(height*width,N);
	VectorXd label(N);
	MatrixXd myu(height*width,10);
	MatrixXd x(height*width,N);
	MatrixXd p(N,10);
	MatrixXd px(height*width,10);
	VectorXd pai(10);
	ifstream if_image("data/train-images.txt");
	ifstream if_label("data/train-labels.txt");
	MatrixXd rnk(N,10);
	for(int i=0 ; i<10 ; i++ ){
		pai(i)=0.1;
		for(int j=0 ; j<height*width ; j++ )
			myu(j,i)=(double)rand()/RAND_MAX;
	} 
	//cout<<myu<<endl;
	for(int j=0 ; j<N ; j++ ){
		if_label >> label(j);
		for(int k=0 ; k<height*width ; k++ ){
			if_image >> image(k,j);
		}
	}

	for(int i=0;i<10;i++)
		for(int j=0;j<N;j++)
			for(int z=0;z<height*width;z++){
				p(j,i)*=pow(myu(z,i),(image(z,j)>170?1:0))*pow((1-myu(z,i)),1-(image(z,j)>170?1:0));
			}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<10;j++){
			px(i)+=pai(j)*p(i,j);
		}
	}

	for(int i=0;i<10;i++){
		for(int j=0;j<N;j++){
			rnk(j,i)=pai(i)*p(j,i)/px(j);
		}
	}
	
	VectorXd tmp(10);
	for(int i=0;i<10;i++){
		for(int j=0;j<N;j++){
			tmp(i)+=rnk(j,i);
		}
		pai(i)=tmp(i)/N;
	}
	MatrixXd tmp2(N,10);
	for(int i=0;i<10;i++){
		for(int j=0;j<N;j++){
			tmp2.col(i)+=rnk(j,i)*x.col(i);
		}
		myu.col(i)=tmp2.col(i)/tmp(i);
	}

	png::image<png::rgb_pixel>output(width*10,height);

	for(int i=0;i<10;i++){
		VectorXd prime=myu.col(i);
		for(int j=0;j<height;j++){
			for(int z=0;z<width;z++){
				double t=255-(prime[j*width+(z+17)%width])*255;
				output[j][z+i*width]=png::rgb_pixel(t,t,t);
			}
		}
	}
	output.write("pic/prime.png");


	//cout<<image<<endl;
return 0; 
}





