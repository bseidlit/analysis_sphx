#include "/sphenix/u/bseidlitz/plotstyle/AtlasStyle.C"
#include "/sphenix/u/bseidlitz/plotstyle/AtlasUtils.C"


TH1F* proj(TH2F* h2){

  int x = h2->GetXaxis()->GetNbins();
  int y = h2->GetYaxis()->GetNbins();
  TH1F* h = (TH1F*) h2->ProjectionX("temp");
  h->Reset();
  for (int ix=1; ix<x+1; ix++){
    float sum = 0;
    float cc = 0;
    for(int iy=1; iy<y+1; iy++){
      float bc = h2->GetBinContent(ix,iy);
      if (bc==0) cc+=1;
      sum += bc;
    }
    if (cc==y) continue;
    float sum_cor = sum*y/(y-cc);
    h->SetBinContent(ix,sum_cor);
  }
      
  return h;
}



void figmaker(){

  SetAtlasStyle();

  const int Nruns = 15;

  int runList[Nruns]={  
    21518,
    21520,
    21598,
    21599,
    21615,
    21626,
    21796,
    21813,
    21889,
    21891,
    22949,
    22950,
    22951,
    22979,
    22982
  };



  for (int ir=0; ir<Nruns; ir++){

    int run = runList[ir];

    TFile* fin = new TFile(Form("output/%d.root",run));

    TH2F* h_emcal_mbd_correlation  = (TH2F*) fin->Get("h_emcal_mbd_correlation" );
    TH2F* h_ihcal_mbd_correlation  = (TH2F*) fin->Get("h_ihcal_mbd_correlation" );
    TH2F* h_ohcal_mbd_correlation  = (TH2F*) fin->Get("h_ohcal_mbd_correlation" );
    TH2F* h_emcal_hcal_correlation = (TH2F*) fin->Get("h_emcal_hcal_correlation");
    TH1F* h_InvMass                = (TH1F*) fin->Get("h_InvMass"               );
    TH2F* h_cemc_etaphi            = (TH2F*) fin->Get("h_cemc_etaphi"           );
    TH2F* h_ihcal_etaphi           = (TH2F*) fin->Get("h_ihcal_etaphi"          );
    TH2F* h_ohcal_etaphi           = (TH2F*) fin->Get("h_ohcal_etaphi"          );

    TCanvas* c1 = new TCanvas("c1", "c1", 600, 600);
    h_emcal_mbd_correlation ->Draw("COLZ");
    h_emcal_mbd_correlation ->SetXTitle("#Sigma #it{E}^{EMCal} [Arb]");
    h_emcal_mbd_correlation ->SetYTitle("#Sigma #it{E}^{MBD} [Arb]");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);
    gPad->SetLogz();

    c1->SaveAs(Form("../plots/emcal_mbd_correlation_%d.pdf",run));


    TCanvas* c2 = new TCanvas("c2", "c2", 600, 600);
    h_ihcal_mbd_correlation ->Draw("COLZ");
    h_ihcal_mbd_correlation ->SetXTitle("#Sigma #it{E}^{ihcal} [Arb]");
    h_ihcal_mbd_correlation ->SetYTitle("#Sigma #it{E}^{MBD} [Arb]");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);
    gPad->SetLogz();

    c2->SaveAs(Form("../plots/ihcal_mbd_correlation_%d.pdf",run));

    TCanvas* c3 = new TCanvas("c3", "c3", 600, 600);
    h_ohcal_mbd_correlation ->Draw("COLZ");
    h_ohcal_mbd_correlation ->SetXTitle("#Sigma #it{E}^{ohcal} [Arb]");
    h_ohcal_mbd_correlation ->SetYTitle("#Sigma #it{E}^{MBD} [Arb]");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);
    gPad->SetLogz();

    c3->SaveAs(Form("../plots/ohcal_mbd_correlation_%d.pdf",run));


    TCanvas* c4 = new TCanvas("c4", "c4", 600, 600);
    h_emcal_hcal_correlation->Draw("COLZ");
    h_emcal_hcal_correlation->SetXTitle("#Sigma #it{E}^{EMCal} [Arb]");
    h_emcal_hcal_correlation->SetYTitle("#Sigma #it{E}^{HCal} [Arb]");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);
    gPad->SetLogz();

    c3->SaveAs(Form("../plots/emcal_hcal_correlation_%d.pdf",run));


    TCanvas* c5 = new TCanvas("c5", "c5", 600, 600);
    h_InvMass               ->Draw("");
    h_InvMass               ->SetXTitle("#it{M}_{#gamma#gamma}");
    h_InvMass               ->SetYTitle("counts");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));

    c5->SaveAs(Form("../plots/InvMass_%d.pdf",run));


    TCanvas* c6 = new TCanvas("c6", "c6", 600, 600);
    h_cemc_etaphi           ->Draw("COLZ");
    h_cemc_etaphi           ->SetXTitle("#it{#eta}_{i} EMCal");
    h_cemc_etaphi           ->SetYTitle("it{#phi}_{i} EMCal");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);

    c6->SaveAs(Form("../plots/cemc_etaphi_%d.pdf",run));




    TCanvas* c7 = new TCanvas("c7", "c7", 600, 600);
    h_ihcal_etaphi          ->Draw("COLZ");
    h_ihcal_etaphi          ->SetXTitle("#it{#eta}_{i} iHcal");
    h_ihcal_etaphi          ->SetYTitle("#it{#phi}_{i} iHcal");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);

    c7->SaveAs(Form("../plots/ihcal_etaphi_%d.pdf",run));


    TCanvas* c8 = new TCanvas("c8", "c8", 600, 600);
    h_ohcal_etaphi          ->Draw("COLZ");
    h_ohcal_etaphi          ->SetXTitle("#it{#eta}_{i} oHcal");
    h_ohcal_etaphi          ->SetYTitle("#it{#phi}_{i} oHcal");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);

    c8->SaveAs(Form("../plots/ohcal_etaphi_%d.pdf",run));


    TH1F* h_emcal_proj = (TH1F*) proj(h_cemc_etaphi)->Clone("h_emcal_proj");

    TCanvas* c9 = new TCanvas("c9", "c9", 600, 300);
    h_emcal_proj->Draw("hist");
    h_emcal_proj->SetYTitle("N^{twr}(E_{T} > 1 GeV)");

    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    
    c9->SaveAs(Form("../plots/cemc_proj_%d.pdf",run));


    TH1F* h_ohcal_proj = (TH1F*) proj(h_ohcal_etaphi)->Clone("h_ohcal_proj");

    TCanvas* c10 = new TCanvas("c10", "c10", 600, 300);
    h_ohcal_proj->Draw("hist");
    h_ohcal_proj->SetYTitle("N^{twr}(E_{T} > 1 GeV)");
     h_ohcal_proj->GetYaxis()->SetRangeUser(0, h_ohcal_proj->GetMaximum()*1.05);

    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    
    c10->SaveAs(Form("../plots/ohcal_proj_%d.pdf",run));


    TH1F* h_ihcal_proj = (TH1F*) proj(h_ihcal_etaphi)->Clone("h_ihcal_proj");

    TCanvas* c11 = new TCanvas("c11", "c10", 600, 300);
    h_ihcal_proj->Draw("hist");
    h_ihcal_proj->SetYTitle("N^{twr}(E_{T} > 1 GeV)");

    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    
    c11->SaveAs(Form("../plots/ihcal_proj_%d.pdf",run));
  }




}
