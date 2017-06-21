#include "main.h"

using namespace std;
int main(int argc,char** argv)
{
	int X=20,Y=20,T_INIT=5,N_INIT=100000;
	int MODE,default_args;
	double Steps;
	cout<<"Please Key In The Mode You Choose(1 or 0)"<<endl;
	cin>>MODE;
	if (MODE){cout<<"You Choose IsingModel\n\n";Steps=1000;}
	else {cout<<"You Choose MagnetModel\n\n";Steps=0.0005;}
	cout<<"Using Default Args?(1 or 0)"<<endl;
	cin>>default_args;
	if (!default_args){
		cout<<"Please Configurate The Args:X Y T N Steps"<<endl;
		cin>>X>>Y>>T_INIT>>N_INIT>>Steps;
	}else{
		cout<<"Using Default Configuration"<<endl;
	}
	if (MODE){
	char filename[]="dataIsing";
	IsingModel MyModel(X,Y,T_INIT,N_INIT);
	ofstream fout(filename);
		for (int i=0;i<Steps;i++){
			double ARG=i*0.05;
			MyModel.ChangeT(ARG);
			MyModel.StartCal();
			fout<<ARG<<" "<<MyModel.getAver()<<endl;
			cout<<"Step: "<<i<<"/"<<Steps<<"\t\tT: "<<ARG<<"\t\tP: "<<MyModel.getAver()<<endl;
			MyModel.ResetS();
		}
	}else{
		char filename[]="dataMagnet";
		IsingModel MyModel(X,Y,T_INIT,N_INIT);
		ofstream fout(filename);
		double ARG=0;
		fout<<ARG<<" "<<0<<endl;
		for (int i=0;ARG<1e-22;i++){
			ARG=i*1e-22*Steps;
			MyModel.ChangeH(ARG);
			MyModel.StartCal();
			fout<<ARG<<" "<<MyModel.getAver()<<endl;
			cout<<"Step: "<<i<<"/"<<1/Steps<<"\t\tH: "<<ARG<<"\t\tP: "<<MyModel.getAver()<<endl;
		}
		for (int i=0;ARG>-1e-22;i++){
			ARG=-i*1e-22*Steps+1e-22;
			MyModel.ChangeH(ARG);
			MyModel.StartCal();
			fout<<ARG<<" "<<MyModel.getAver()<<endl;
			cout<<"Step: "<<2/Steps-i<<"/"<<2/Steps<<"\t\tH: "<<ARG<<"\t\tP: "<<MyModel.getAver()<<endl;
		}
		for (int i=0;ARG<1e-22;i++){
			ARG=i*1e-22*Steps-1e-22;
			MyModel.ChangeH(ARG);
			MyModel.StartCal();
			fout<<ARG<<" "<<MyModel.getAver()<<endl;
			cout<<"Step: "<<i<<"/"<<2/Steps<<"\t\tH: "<<ARG<<"\t\tP: "<<MyModel.getAver()<<endl;
		}
	}



	system("python isingplot.py");
	return 0;




}


