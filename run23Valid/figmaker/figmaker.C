#include "/sphenix/u/bseidlitz/plotstyle/AtlasStyle.C"
#include "/sphenix/u/bseidlitz/plotstyle/AtlasUtils.C"



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

    TFile* fin = new TFile(Form("../output/%d.root",run));

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

    c1->SaveAs(Form("../plots/emcal_mbd_correlation_%d.pdf",run));


    TCanvas* c2 = new TCanvas("c2", "c2", 600, 600);
    h_ihcal_mbd_correlation ->Draw("COLZ");
    h_ihcal_mbd_correlation ->SetXTitle("#Sigma #it{E}^{ihcal} [Arb]");
    h_ihcal_mbd_correlation ->SetYTitle("#Sigma #it{E}^{MBD} [Arb]");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);

    c2->SaveAs(Form("../plots/ihcal_mbd_correlation_%d.pdf",run));

    TCanvas* c3 = new TCanvas("c3", "c3", 600, 600);
    h_ohcal_mbd_correlation ->Draw("COLZ");
    h_ohcal_mbd_correlation ->SetXTitle("#Sigma #it{E}^{ohcal} [Arb]");
    h_ohcal_mbd_correlation ->SetYTitle("#Sigma #it{E}^{MBD} [Arb]");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);

    c3->SaveAs(Form("../plots/ohcal_mbd_correlation_%d.pdf",run));


    TCanvas* c4 = new TCanvas("c4", "c4", 600, 600);
    h_emcal_hcal_correlation->Draw("COLZ");
    h_emcal_hcal_correlation->SetXTitle("#Sigma #it{E}^{EMCal} [Arb]");
    h_emcal_hcal_correlation->SetYTitle("#Sigma #it{E}^{HCal} [Arb]");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);

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
    h_cemc_etaphi           ->SetXTitle("#it{#eta}_{i}");
    h_cemc_etaphi           ->SetYTitle("ir{#phi}_{i}");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);

    c6->SaveAs(Form("../plots/cemc_etaphi_%d.pdf",run));


    TCanvas* c7 = new TCanvas("c7", "c7", 600, 600);
    h_ihcal_etaphi          ->Draw("COLZ");
    h_ihcal_etaphi          ->SetXTitle("#it{#eta}_{i}");
    h_ihcal_etaphi          ->SetYTitle("#it{#phi}_{i}");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);

    c7->SaveAs(Form("../plots/ihcal_etaphi_%d.pdf",run));


    TCanvas* c8 = new TCanvas("c8", "c8", 600, 600);
    h_ohcal_etaphi          ->Draw("COLZ");
    h_ohcal_etaphi          ->SetXTitle("#it{#eta}_{i}");
    h_ohcal_etaphi          ->SetYTitle("#it{#eta}_{i}");
    myText(0.22, 0.9, 1, "#it{#bf{sPHENIX}} Internal");
    myText(0.22, 0.85, 1, Form("run %d", run));
    gPad->SetRightMargin(0.15);

    c8->SaveAs(Form("../plots/ohcal_etaphi_%d.pdf",run));

  }




}
