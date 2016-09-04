#include "iostream"
#include "fstream"
#include "TCanvas.h"
#include "TGraph.h"
#include "TF1.h"
#include "TPostScript.h"
#include "TStyle.h"
#include "TAxis.h"
using namespace std;
void read();
int main(){
	read();
	return 0;
}

void read(){
	ifstream iput;
	ifstream iput1;
	ofstream out("0layercorrection.dat");
	ofstream out1("1layercorrection.dat");
	iput.open("quenching-correction-layer0.dat",ios::in);
	iput1.open("quenching-correction-layer1.dat",ios::in);
	TGraph *gh;
	TGraph *gh1;
	double Charge[14],RecoC[14];
	double Charge1[14],RecoC1[14];
	double a[42];
	double b[42];
	double para[3];
	double parameter[3];
	gStyle->SetOptFit(1111);
	TCanvas *c = new TCanvas();
	c->Print("Relation.pdf[");
	for(int i=0;i<41;i++){

		for(int j=0;j<42;j++){
			iput>>a[j];
		}
		Charge[11] = a[1];
		RecoC[11] = 3;
		
		Charge[0] = a[4];
		RecoC[0] = 4;
		Charge[1] = a[7];
		RecoC[1] = 5;
		Charge[2] = a[10];
		RecoC[2] = 6;
		Charge[3] = a[13];
		RecoC[3] = 7;
		Charge[4] = a[16];
		RecoC[4] = 8;
		Charge[5] = a[19];
		RecoC[5] = 10;
		Charge[6] = a[22];
		RecoC[6] = 12;
		Charge[7] = a[25];
		RecoC[7] = 14;
		Charge[8] = a[28];
		RecoC[8] = 16;
		Charge[9] = a[31];
		RecoC[9] = 20;
		Charge[10] = a[34];
		RecoC[10] = 26;

		Charge[12] = a[37];
		RecoC[12] = 1;
		Charge[13] = a[40];
		RecoC[13] = 2;
		gh = new TGraph(14,Charge,RecoC);
		gh->GetYaxis()->SetRangeUser(0,50);
		gh->Fit("pol2");
		TF1* fit0 = gh->GetFunction("pol2");
		para[0]=fit0->GetParameter(0);
		para[1]=fit0->GetParameter(1);
		para[2]=fit0->GetParameter(2);
		out<<para[0]<<"\t"<<para[1]<<"\t"<<para[2]<<endl;
		gh->SetTitle("Layer 0 Quenching Effect;Reco Charge Number;Charge");
		gh->Draw("A*");
		c->Print("Relation.pdf");
		for(int n=0;n<42;n++){
			iput1>>b[n];
		}
		RecoC1[0] = b[1];
		Charge1[0] = 4;
		RecoC1[1] = b[4];
		Charge1[1] = 5;
		RecoC1[2] = b[7];
		Charge1[2] = 6;
		RecoC1[3] = b[10];
		Charge1[3] = 7;
		RecoC1[4] = b[13];
		Charge1[4] = 8;
		RecoC1[5] = b[16];
		Charge1[5] = 10;
		RecoC1[6] = b[19];
		Charge1[6] = 12;
		RecoC1[7] = b[22];
		Charge1[7] = 14;
		RecoC1[8] = b[25];
		Charge1[8] = 16;
		RecoC1[9] = b[28];
		Charge1[9] = 20;
		RecoC1[10] = b[31];
		Charge1[10] = 26;
		RecoC1[11] = b[34];
		Charge1[11] = 3;
		RecoC1[12] = b[37];
		Charge1[12] = 1;
		RecoC1[13] = b[40];
		Charge1[13] = 2;
		gh1 = new TGraph(14,RecoC1,Charge1);
		gh1->GetYaxis()->SetRangeUser(0,50);
		gh1->Fit("pol2");
		TF1 *fit1 = gh1->GetFunction("pol2");
		parameter[0] = fit1->GetParameter(0);
		parameter[1] = fit1->GetParameter(1);
		parameter[2] = fit1->GetParameter(2);
		out1<<parameter[0]<<"\t"<<parameter[1]<<"\t"<<parameter[2]<<endl;
		gh1->SetTitle("Layer 1 Quenching Effect;Reco Charge Number;Charge");
		gh1->Draw("A*");

		c->Print("Relation.pdf");
   
		
	}
		c->Print("Relation.pdf]");

}
