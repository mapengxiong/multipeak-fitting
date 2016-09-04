#include "iostream"
#include "fstream"
#include "TH1.h"
#include "TF1.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TPostScript.h"
#include "TAxis.h"
using namespace std;
void correction();

int main(){
	correction();
	return 0;
}


void correction(){
	TFile *f = new TFile("/data/data/usr/mapx/PsdPara/2016-7654321-quenching.root");
	char title[40],hname[40],title0[40];
	TH1F* h[2][41];
	for(int l =0;l<2;l++){
		for(int b =0;b<41;b++){
			sprintf(hname,"%02dL%02dBarCharge11",l,b);
			sprintf(title,"%02dL%02dBarC",l,b);
			h[l][b] = new TH1F(hname,title,800,0,40);
			h[l][b]->GetXaxis()->SetTitle("Charge");
			sprintf(title0,"%02dL%02dBarCharge",l,b);
			h[l][b] =(TH1F*)f->Get(title0);
		}
	}
	TCanvas *c1 = new TCanvas("mixed","5 strips",800,800);
	c1->SetLogy();
	h[0][6]->SetLineColor(kRed);
	h[0][10]->SetLineColor(kBlue);
	h[0][20]->SetLineColor(kGreen);
	h[0][22]->SetLineColor(3);
	h[0][24]->SetLineColor(30);
	h[0][6]->Draw();
	h[0][10]->Draw("same");
	h[0][20]->Draw("same");
	h[0][22]->Draw("same");
	h[0][24]->Draw("same");
	h[1][6]->SetLineColor(0);
	h[1][10]->SetLineColor(5);
	h[1][20]->SetLineColor(6);
	h[1][22]->SetLineColor(7);
	h[1][24]->SetLineColor(1);
	h[1][6]->Draw("same");
	h[1][10]->Draw("same");
	h[1][20]->Draw("same");
	h[1][22]->Draw("same");
	h[1][24]->Draw("same");
	c1->SaveAs("0-1layer ten strips Multi Peak.pdf");

	TF1 *g1 = new TF1("f1","gaus",3.2,3.8);//Li element
	TF1 *g2 = new TF1("f2","gaus",3.90,4.65);//Be element
	TF1 *g3 = new TF1("f3","gaus",4.5,5.6);//B element
	TF1 *g4 = new TF1("f4","gaus",5.5,6.4); //C element
	TF1 *g5 = new TF1("f5","gaus",6.5,7.2);//N element
	TF1 *g6 = new TF1("f6","gaus",7.23,8.15);//O element
	TF1 *g7 = new TF1("f7","gaus",8.5,9.5);//Ne element
	TF1 *g8 = new TF1("f8","gaus",10,11.2);//Mg element
	TF1 *g9 = new TF1("f9","gaus",11.2,12.35);//Si element
	TF1 *g10 = new TF1("f10","gaus",12.8,13.6);//S element
	TF1 *g11 = new TF1("f12","gaus",15.2,16.5);//Fe element
	TF1 *g12 = new TF1("f11","gaus",18.5,21);//Ca element
	//-------------------------------------------
	TF1 *g13 = new TF1("f13","gaus",0.5,1.4);//H element
	TF1 *g14 = new TF1("f14","gaus",1,6,2,3);//He element



	TF1 *fun1 = new TF1("func1","gaus",3.8,4.65);//Be
	TF1 *fun2 = new TF1("func2","gaus",4.65,5.55);//B
	TF1 *fun3 = new TF1("func3","gaus",5.55,6.55);//C
	TF1 *fun4 = new TF1("func4","gaus",6.55,7.20);//N
	TF1 *fun5 = new TF1("func5","gaus",7.23,8.15);//O
	TF1 *fun6 = new TF1("func6","gaus",8.65,9.90);//Ne
	TF1 *fun7 =new TF1("func7","gaus",10.25,11.10);//Mg
	TF1 *fun8 =new TF1("func8","gaus",11.55,12.60);//Si
	TF1 *fun9 =new TF1("func9","gaus",12.95,14.10);//S
	TF1 *fun10 = new TF1("fun10","gaus",15.2,16.7);//Ca
	TF1 *fun11 =new TF1("func11","gaus",19.05,21.10);//Fe
	//-----------------------------------------------
	TF1 *fun12 = new TF1("func12","gaus",);//Li
	TF1 *fun13 = new TF1("func13","gaus",);//H
	TF1 *fun14 = new TF1("func14","gaus",);//He


    g1->SetLineColor(kGreen);
    g2->SetLineColor(kGreen);
    g3->SetLineColor(kGreen);
    g4->SetLineColor(kGreen);
    g5->SetLineColor(kGreen);
    g6->SetLineColor(kGreen);
    g7->SetLineColor(kGreen);
    g8->SetLineColor(kGreen);
    g9->SetLineColor(kGreen);
    g10->SetLineColor(kGreen);
    g11->SetLineColor(kGreen);
    g12->SetLineColor(kGreen);
    g13->SetLineColor(kGreen);
    g14->SetLineColor(kGreen);

	TF1 *pl7 = new TF1("pol","pol2",2,35);
	double par[35];
	double par1[33];

    ofstream out("quenching-correction-layer0.dat");
    ofstream out1("quenching-correction-layer1.dat");
    TCanvas* c = new TCanvas("cc","dd",800,800);
	c->Print("FitMultiPeak.pdf[");
	for(int l =0;l<2;l++){
		for(int b =0;b<41;b++){
			c->SetGrid();
			c->SetLogy();
			if(l==0){
			h[l][b]->Fit(g1,"R");
			h[l][b]->Fit(g2,"R+");
			h[l][b]->Fit(g3,"R+");
			h[l][b]->Fit(g4,"R+");
			h[l][b]->Fit(g5,"R+");
			h[l][b]->Fit(g6,"R+");
			h[l][b]->Fit(g7,"R+");
			h[l][b]->Fit(g8,"R+");
			h[l][b]->Fit(g9,"R+");
			h[l][b]->Fit(g10,"R+");
			h[l][b]->Fit(g11,"R+");
			h[l][b]->Fit(g12,"R+");
			h[l][b]->Fit(g13,"R+");
			h[l][b]->Fit(g14,"R+");

     		g1->GetParameters(&par[0]);
			g2->GetParameters(&par[3]);
			g3->GetParameters(&par[6]);
			g4->GetParameters(&par[9]);
			g5->GetParameters(&par[12]);
			g6->GetParameters(&par[15]);
			g7->GetParameters(&par[18]);
			g8->GetParameters(&par[21]);
			g9->GetParameters(&par[24]);
			g10->GetParameters(&par[27]);
			g11->GetParameters(&par[30]);
			g12->GetParameters(&par[33]);
			//-----------------------
			g13->GetParameters(&par[36]);
			g14->GetParameters(&par[39]);
			c->Print("FitMultiPeak.pdf");
			for(int m=0;m<42;m++){
				out<<par[m]<<"\t";

			}
			out<<endl;
			}
		if(l==1){
			h[l][b]->Fit(fun1,"R");
			h[l][b]->Fit(fun2,"R+");
			h[l][b]->Fit(fun3,"R+");
			h[l][b]->Fit(fun4,"R+");
			h[l][b]->Fit(fun5,"R+");
			h[l][b]->Fit(fun6,"R+");
			h[l][b]->Fit(fun7,"R+");
			h[l][b]->Fit(fun8,"R+");
			h[l][b]->Fit(fun9,"R+");
			h[l][b]->Fit(fun10,"R+");
			h[l][b]->Fit(fun11,"R+");
			//-------------------
			h[l][b]->Fit(fun12,"R+");
			h[l][b]->Fit(fun13,"R+");
			h[l][b]->Fit(fun14,"R+");


     		fun1->GetParameters(&par1[0]);
			fun2->GetParameters(&par1[3]);
			fun3->GetParameters(&par1[6]);
			fun4->GetParameters(&par1[9]);
			fun5->GetParameters(&par1[12]);
			fun6->GetParameters(&par1[15]);
			fun7->GetParameters(&par1[18]);
			fun8->GetParameters(&par1[21]);
			fun9->GetParameters(&par1[24]);
			fun10->GetParameters(&par1[27]);
			fun11->GetParameters(&par1[30]);
			fun11->GetParameters(&par1[33]);
			fun11->GetParameters(&par1[36]);
			fun11->GetParameters(&par1[39]);
	        c->Print("FitMultiPeak.pdf");	
			for(int m=0;m<42;m++){
				out1<<par1[m]<<"\t";

			}
			out1<<endl;
		}
		}
	}
	c->Print("FitMultiPeak.pdf]");
}

