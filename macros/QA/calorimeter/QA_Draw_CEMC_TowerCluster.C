// $Id: $

/*!
 * \file QA_Draw_CEMC_TowerCluster.C
 * \brief
 * \author Jin Huang <jhuang@bnl.gov>
 * \version $Revision:   $
 * \date $Date: $
 */

#include <TFile.h>
#include <TLine.h>
#include <TString.h>
#include <TTree.h>
#include <cassert>
#include <cmath>

//some common style files
#include "QA_Draw_Utility.C"
#include "SetOKStyle.C"
using namespace std;

void QA_Draw_CEMC_TowerCluster(
    const char *qa_file_name_new =
        "/phenix/u/jinhuang/links/ePHENIX_work/sPHENIX_work/production_analysis_updates/spacal1d/fieldmap/G4Hits_sPHENIX_pi-_eta0.30_32GeV-0000.root_qa.root",
    const char *qa_file_name_ref =
        "/phenix/u/jinhuang/links/ePHENIX_work/sPHENIX_work/production_analysis_updates/spacal1d/fieldmap/G4Hits_sPHENIX_pi+_eta0.30_32GeV-0000.root_qa.root")

{
  SetOKStyle();
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(1111);
  TVirtualFitter::SetDefaultFitter("Minuit2");

  TFile *qa_file_new = new TFile(qa_file_name_new);
  assert(qa_file_new->IsOpen());

  TFile *qa_file_ref = NULL;
  if (qa_file_name_ref)
  {
    qa_file_ref = new TFile(qa_file_name_ref);
    assert(qa_file_ref->IsOpen());
  }

  TCanvas *c1 = new TCanvas("QA_Draw_CEMC_TowerCluster", "QA_Draw_CEMC_TowerCluster", 1800, 900);
  c1->Divide(4, 2);
  int idx = 1;
  TPad *p;

  p = (TPad *) c1->cd(idx++);
  c1->Update();
  p->SetLogx();
  p->SetLogy();

  {
    TH1F *h_new = (TH1F *) qa_file_new->GetObjectChecked(
        "h_QAG4Sim_CEMC_Tower_1x1", "TH1F");
    assert(h_new);

    h_new->Scale(1. / h_new->GetSum());

    TH1F *h_ref = NULL;
    if (qa_file_ref)
    {
      TH1F *h_ref = (TH1F *) qa_file_ref->GetObjectChecked(
          "h_QAG4Sim_CEMC_Tower_1x1", "TH1F");
      assert(h_ref);

      h_ref->Scale(1. / h_ref->GetSum());
    }

    h_new->GetYaxis()->SetTitleOffset(1.5);
    h_new->GetYaxis()->SetTitle("Normalized tower count per bin");
    //      h_new->GetXaxis()->SetRangeUser(-0, .1);

    DrawReference(h_new, h_ref);
  }

  p = (TPad *) c1->cd(idx++);
  c1->Update();
  p->SetLogx();
  p->SetLogy();

  {
    TH1F *h_new = (TH1F *) qa_file_new->GetObjectChecked(
        "h_QAG4Sim_CEMC_Tower_3x3", "TH1F");
    assert(h_new);

    h_new->Scale(1. / h_new->GetSum());

    TH1F *h_ref = NULL;
    if (qa_file_ref)
    {
      TH1F *h_ref = (TH1F *) qa_file_ref->GetObjectChecked(
          "h_QAG4Sim_CEMC_Tower_3x3", "TH1F");
      assert(h_ref);

      h_ref->Scale(1. / h_ref->GetSum());
    }

    h_new->GetYaxis()->SetTitleOffset(1.5);
    h_new->GetYaxis()->SetTitle("Normalized tower count per bin");
    //      h_new->GetXaxis()->SetRangeUser(-0, .1);

    DrawReference(h_new, h_ref);
  }

  p = (TPad *) c1->cd(idx++);
  c1->Update();
  //    p->SetLogx();
  p->SetLogy();

  {
    TH1F *h_new = (TH1F *) qa_file_new->GetObjectChecked(
        "h_QAG4Sim_CEMC_Tower_1x1_max", "TH1F");
    assert(h_new);

    h_new->Rebin(40);
    h_new->Sumw2();
    h_new->Scale(1. / h_new->GetSum());

    TH1F *h_ref = NULL;
    if (qa_file_ref)
    {
      TH1F *h_ref = (TH1F *) qa_file_ref->GetObjectChecked(
          "h_QAG4Sim_CEMC_Tower_1x1_max", "TH1F");
      assert(h_ref);

      h_ref->Rebin(40);
      h_ref->Scale(1. / h_ref->GetSum());
    }

    h_new->GetYaxis()->SetTitleOffset(1.5);
    h_new->GetYaxis()->SetTitle("Probability per bin");
    //      h_new->GetXaxis()->SetRangeUser(-0, .1);

    DrawReference(h_new, h_ref);
  }

  p = (TPad *) c1->cd(idx++);
  c1->Update();
  //    p->SetLogx();
  p->SetLogy();

  {
    TH1F *h_new = (TH1F *) qa_file_new->GetObjectChecked(
        "h_QAG4Sim_CEMC_Tower_4x4_max", "TH1F");
    assert(h_new);

    h_new->Rebin(40);
    h_new->Sumw2();
    h_new->Scale(1. / h_new->GetSum());

    TH1F *h_ref = NULL;
    if (qa_file_ref)
    {
      TH1F *h_ref = (TH1F *) qa_file_ref->GetObjectChecked(
          "h_QAG4Sim_CEMC_Tower_4x4_max", "TH1F");
      assert(h_ref);

      h_ref->Rebin(40);
      h_ref->Scale(1. / h_ref->GetSum());
    }

    h_new->GetYaxis()->SetTitleOffset(1.5);
    h_new->GetYaxis()->SetTitle("Probability per bin");
    //      h_new->GetXaxis()->SetRangeUser(-0, .1);

    DrawReference(h_new, h_ref);
  }

  p = (TPad *) c1->cd(idx++);
  c1->Update();
  p->SetLogz();

  TH2F *h_QAG4Sim_CEMC_Cluster_LateralTruthProjection =
      (TH2F *) qa_file_new->GetObjectChecked(
          "h_QAG4Sim_CEMC_Cluster_LateralTruthProjection", "TH2F");
  assert(h_QAG4Sim_CEMC_Cluster_LateralTruthProjection);
  h_QAG4Sim_CEMC_Cluster_LateralTruthProjection->GetYaxis()->SetTitleOffset(
      1.5);
  h_QAG4Sim_CEMC_Cluster_LateralTruthProjection->GetXaxis()->SetRangeUser(-5,
                                                                          5);
  h_QAG4Sim_CEMC_Cluster_LateralTruthProjection->GetYaxis()->SetRangeUser(-5,
                                                                          5);
  h_QAG4Sim_CEMC_Cluster_LateralTruthProjection->Draw("COLZ");

  p = (TPad *) c1->cd(idx++);
  c1->Update();
  //  p->SetLogz();

  {
    TH2F *h_QAG4Sim_CEMC_Cluster_LateralTruthProjection =
        (TH2F *) qa_file_new->GetObjectChecked(
            "h_QAG4Sim_CEMC_Cluster_LateralTruthProjection", "TH2F");
    assert(h_QAG4Sim_CEMC_Cluster_LateralTruthProjection);

    TH1D *proj_new =
        h_QAG4Sim_CEMC_Cluster_LateralTruthProjection->ProjectionX(
            "qa_file_new_h_QAG4Sim_CEMC_Cluster_LateralTruthProjection_px");

    proj_new->Scale(1. / proj_new->GetSum());

    TH1D *proj_ref = NULL;
    if (qa_file_ref)
    {
      TH2F *h_QAG4Sim_CEMC_Cluster_LateralTruthProjection =
          (TH2F *) qa_file_ref->GetObjectChecked(
              "h_QAG4Sim_CEMC_Cluster_LateralTruthProjection", "TH2F");
      assert(h_QAG4Sim_CEMC_Cluster_LateralTruthProjection);

      proj_ref = h_QAG4Sim_CEMC_Cluster_LateralTruthProjection->ProjectionX(
          "qa_file_ref_h_QAG4Sim_CEMC_Cluster_LateralTruthProjection_px");
      proj_ref->Scale(1. / proj_ref->GetSum());
    }

    proj_new->GetYaxis()->SetTitleOffset(1.);
    proj_new->GetXaxis()->SetTitleOffset(1.);
    proj_new->GetYaxis()->SetTitle("Normalized energy distribution");
    proj_new->GetXaxis()->SetRangeUser(-10, 10);

    DrawReference(proj_new, proj_ref);
  }

  p = (TPad *) c1->cd(idx++);
  c1->Update();
  //  p->SetLogz();

  {
    TH2F *h_QAG4Sim_CEMC_Cluster_LateralTruthProjection =
        (TH2F *) qa_file_new->GetObjectChecked(
            "h_QAG4Sim_CEMC_Cluster_LateralTruthProjection", "TH2F");
    assert(h_QAG4Sim_CEMC_Cluster_LateralTruthProjection);

    TH1D *proj_new =
        h_QAG4Sim_CEMC_Cluster_LateralTruthProjection->ProjectionY(
            "qa_file_new_h_QAG4Sim_CEMC_Cluster_LateralTruthProjection_py");

    proj_new->Scale(1. / proj_new->GetSum());

    TH1D *proj_ref = NULL;
    if (qa_file_ref)
    {
      TH2F *h_QAG4Sim_CEMC_Cluster_LateralTruthProjection =
          (TH2F *) qa_file_ref->GetObjectChecked(
              "h_QAG4Sim_CEMC_Cluster_LateralTruthProjection", "TH2F");
      assert(h_QAG4Sim_CEMC_Cluster_LateralTruthProjection);

      proj_ref = h_QAG4Sim_CEMC_Cluster_LateralTruthProjection->ProjectionY(
          "qa_file_ref_h_QAG4Sim_CEMC_Cluster_LateralTruthProjection_py");
      proj_ref->Scale(1. / proj_ref->GetSum());
    }

    proj_new->GetYaxis()->SetTitleOffset(1.);
    proj_new->GetXaxis()->SetTitleOffset(1.);
    proj_new->GetYaxis()->SetTitle("Normalized energy distribution");
    proj_new->GetXaxis()->SetRangeUser(-10, 10);

    DrawReference(proj_new, proj_ref);
  }

  p = (TPad *) c1->cd(idx++);
  c1->Update();
  p->SetLogy();

  {
    TH1F *h_new = (TH1F *) qa_file_new->GetObjectChecked(
        "h_QAG4Sim_CEMC_Cluster_BestMatchERatio", "TH1F");
    assert(h_new);

    h_new->Rebin(2);
    h_new->Sumw2();
    h_new->Scale(1. / h_new->GetSum());

    TH1F *h_ref = NULL;
    if (qa_file_ref)
    {
      TH1F *h_ref = (TH1F *) qa_file_ref->GetObjectChecked(
          "h_QAG4Sim_CEMC_Cluster_BestMatchERatio", "TH1F");
      assert(h_ref);

      h_ref->Rebin(2);
      h_ref->Scale(1. / h_ref->GetSum());
    }

    h_new->GetYaxis()->SetTitleOffset(1.5);
    h_new->GetYaxis()->SetTitle("Probability per bin");
    //          h_new->GetXaxis()->SetRangeUser(-0, .1);

    DrawReference(h_new, h_ref);
  }

  PutInputFileName(c1, .04, qa_file_name_new, qa_file_name_ref);
  SaveCanvas(c1, TString(qa_file_name_new) + TString(c1->GetName()), true);
}
