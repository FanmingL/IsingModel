#ifndef _ISINGMODEL_H_
#define _ISINGMODEL_H_

class IsingModel{
public:	
	IsingModel(const int NumX,const int NumY,double T,const int n=4000,const double J=1e-22,double H=1e-24);
	void OnePointCal();
	double getS(int x,int y);
	void StartCal();
	double getAver();
	void ChangeT(double T);
	void ChangeH(double H);
	void ResetS();
private:
	enum{MAX_NUM=100};
	const int NumX,NumY,n;
	const double J;
	int X_Now,Y_Now;
	double T,M,H;
	double S[MAX_NUM][MAX_NUM];		
	void RefreshPoint();
};





#endif

