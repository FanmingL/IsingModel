#include "main.h"
using namespace std;

void IsingModel::ResetS(){
	for (int i=0;i<this->MAX_NUM;i++){
		for (int ii=0;ii<this->MAX_NUM;ii++){
			this->S[i][ii]=0;
		}
	}
	for (int i=1;i<NumX+1;i++){
		for (int ii=1;ii<NumY+1;ii++){
			this->S[i][ii]=1;
		}
	}

}
IsingModel::IsingModel(const int NumX,const int NumY,double T,const int n,const double J,double H):NumX(NumX),NumY(NumY),T(T),n(n),J(J),H(H){
	this->X_Now=1;
	this->Y_Now=1;
	this->ResetS();
	cout<<"Size:("<<this->NumX<<","<<this->NumY<<")"<<endl
		<<"CircleTimes:"<<this->n<<endl
		<<"TempratureNow:"<<this->T<<endl
		<<"J:"<<this->J<<endl
		<<"H:"<<this->H<<endl
		<<"Starting......"<<endl;
}

void IsingModel::RefreshPoint(){
	this->X_Now=(int)(rand()*1.0/((double)RAND_MAX+1)*this->NumX+1);
	this->Y_Now=(int)(rand()*1.0/((double)RAND_MAX+1)*this->NumY+1);
}

void IsingModel::OnePointCal(){
	this->RefreshPoint();
	double E1=-this->J*this->S[X_Now][Y_Now]*(this->S[X_Now][Y_Now-1]+
						this->S[X_Now][Y_Now+1]+
						this->S[X_Now-1][Y_Now]+
						this->S[X_Now+1][Y_Now])-
						this->H*this->S[X_Now][Y_Now];

	double E2=this->J*this->S[X_Now][Y_Now]*(this->S[X_Now][Y_Now-1]+
						this->S[X_Now][Y_Now+1]+
						this->S[X_Now-1][Y_Now]+
						this->S[X_Now+1][Y_Now])+
						this->H*this->S[X_Now][Y_Now];
	double P=exp(-(E2-E1)/(1.38e-23*this->T));
	if (rand()*1.0/RAND_MAX<P)this->S[X_Now][Y_Now]=-this->S[X_Now][Y_Now];
	
}

double IsingModel::getS(int x,int y){
	return this->S[x+1][y+1];
}

void IsingModel::StartCal(){
	for (int i=0;i<this->n;i++){
	this->OnePointCal();
	}
}

double IsingModel::getAver(){
	double sum=0;
	for (int i=0;i<this->NumX;i++){
		for (int ii=0;ii<this->NumY;ii++){
			sum+=this->S[i+1][ii+1];
		}
	}
	this->M = sum*1.0/(NumX*NumY);
	return this->M;
}

void IsingModel::ChangeT(double T){
	this->T = T;
}

void IsingModel::ChangeH(double H){
	this->H = H;
}

