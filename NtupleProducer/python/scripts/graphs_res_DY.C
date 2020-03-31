#include <stdio.h>
#include <fstream>

	const int n = 290000;
	
	 float agen[n];
	  float apf[n];
	  float apu[n];
	float acopf[n];
	float acopu[n];

	 float agenpu0[n];
	  float apfpu0[n];
	  float apupu0[n];
	float acopfpu0[n];
	float acopupu0[n];

	 float agenphi[n];
	  float apfphi[n];
	  float apuphi[n];
	float acopfphi[n];
	float acopuphi[n];

	 float agenpu0phi[n];
	  float apfpu0phi[n];
	  float apupu0phi[n];
	float acopfpu0phi[n];
	float acopupu0phi[n];

	float aMu1[n][4];
	float aMu2[n][4];
	float aMu1_pu0[n][4];
	float aMu2_pu0[n][4];

	TString sName = "mets_DY";
	TString sDir = "DY_resPlots";
	TString tNum = "";

void graphs_res_DY()
{

	TH1F *hInv = new TH1F("hInv", "Invariant Mass of two muons PU200;Mass [GeV];Events", 100, 0, 150);
	TH1F *hInv_pu0 = new TH1F("hInv_pu0", "Invariant Mass of two muons PU0;Mass [GeV];Events", 100, 0, 150);

	ifstream gen;
	ifstream   pf;
	ifstream pu;
	ifstream copf;
	ifstream copu;
	
	ifstream genpu0;
	ifstream pfpu0;
	ifstream pupu0;
	ifstream copfpu0;
	ifstream copupu0;

	ifstream  genphi;
	ifstream   pfphi;
	ifstream   puphi;
	ifstream copfphi;
	ifstream copuphi;
	
	ifstream  genpu0phi;
	ifstream   pfpu0phi;
	ifstream   pupu0phi;
	ifstream copfpu0phi;
	ifstream copupu0phi;

	ifstream fmu1;
	ifstream fmu2;
	ifstream fmu1_pu0;
	ifstream fmu2_pu0;

	 gen.open("./"+sName+tNum+"/GenMET.txt");
	  pf.open("./"+sName+tNum+"/PFMET.txt");
	  pu.open("./"+sName+tNum+"/PuMET.txt");
	copf.open("./"+sName+tNum+"/CoPFMET.txt");
	copu.open("./"+sName+tNum+"/CoPuMET.txt");
	
	 genpu0.open("./"+sName+tNum+"/GenMET_pu0.txt");
	  pfpu0.open("./"+sName+tNum+"/PFMET_pu0.txt");
	  pupu0.open("./"+sName+tNum+"/PuMET_pu0.txt");
	copfpu0.open("./"+sName+tNum+"/CoPFMET_pu0.txt");
	copupu0.open("./"+sName+tNum+"/CoPuMET_pu0.txt");

	 genphi.open("./"+sName+tNum+"/GenMETphi.txt");
	  pfphi.open("./"+sName+tNum+"/PFMETphi.txt");
	  puphi.open("./"+sName+tNum+"/PuMETphi.txt");
	copfphi.open("./"+sName+tNum+"/CoPFMETphi.txt");
	copuphi.open("./"+sName+tNum+"/CoPuMETphi.txt");
	
	 genpu0phi.open("./"+sName+tNum+"/GenMET_pu0phi.txt");
	  pfpu0phi.open("./"+sName+tNum+"/PFMET_pu0phi.txt");
	  pupu0phi.open("./"+sName+tNum+"/PuMET_pu0phi.txt");
	copfpu0phi.open("./"+sName+tNum+"/CoPFMET_pu0phi.txt");
	copupu0phi.open("./"+sName+tNum+"/CoPuMET_pu0phi.txt");

	fmu1.open("./"+sName+tNum+"/GenMu1.txt");
	fmu2.open("./"+sName+tNum+"/GenMu2.txt");
	fmu1_pu0.open("./"+sName+tNum+"/GenMu1_pu0.txt");
	fmu2_pu0.open("./"+sName+tNum+"/GenMu2_pu0.txt");

	for (int i = 0; i < n ; i ++)
	{
	  gen >> agen[i];
	    pf >> apf[i];
	    pu >> apu[i];
	copf >> acopf[i];
	copu >> acopu[i];

	  genpu0 >> agenpu0[i];
	    pfpu0 >> apfpu0[i];
	    pupu0 >> apupu0[i];
	copfpu0 >> acopfpu0[i];
	copupu0 >> acopupu0[i];

	  genphi >> agenphi[i];
	    pfphi >> apfphi[i];
	    puphi >> apuphi[i];
	copfphi >> acopfphi[i];
	copuphi >> acopuphi[i];

	 genpu0phi >> agenpu0phi[i];
	  pfpu0phi >> apfpu0phi[i];
      pupu0phi >> apupu0phi[i];
	copfpu0phi >> acopfpu0phi[i];
	copupu0phi >> acopupu0phi[i];

		fmu1 >> aMu1[i][0] >> aMu1[i][1] >> aMu1[i][2] >> aMu1[i][3];
		fmu2 >> aMu2[i][0] >> aMu2[i][1] >> aMu2[i][2] >> aMu2[i][3];
	fmu1_pu0 >> aMu1_pu0[i][0] >> aMu1_pu0[i][1] >> aMu1_pu0[i][2] >> aMu1_pu0[i][3];
	fmu2_pu0 >> aMu2_pu0[i][0] >> aMu2_pu0[i][1] >> aMu2_pu0[i][2] >> aMu2_pu0[i][3];
	}

/*
	for (int i = 0 ; i < 5 ; i++)
	{
	cout << "pt: "<<aMu1[i][0]<<", eta: "<<aMu1[i][1]<<", phi: "<<aMu1[i][2]<<endl;

	}
*/
	const int bin = 10;

	float mini = 0;
	float maxi = 400;
    
	float binning_le = (maxi - mini)/(bin);

	TH1F        *hZ[bin];
	TH1F      *hGen[bin];
	TH1F  *hParaGen[bin];
	TH1F  *hPerpGen[bin];
	TH1F   *hParaPF[bin];
	TH1F   *hPerpPF[bin];
	TH1F   *hParaPu[bin];
	TH1F   *hPerpPu[bin];
	TH1F *hParaCoPF[bin];
	TH1F *hPerpCoPF[bin];
	TH1F *hParaCoPu[bin];
	TH1F *hPerpCoPu[bin];

	TH1F        *hZ_pu0[bin];
	TH1F      *hGen_pu0[bin];
	TH1F  *hParaGen_pu0[bin];
	TH1F  *hPerpGen_pu0[bin];
	TH1F   *hParaPF_pu0[bin];
	TH1F   *hPerpPF_pu0[bin];
	TH1F   *hParaPu_pu0[bin];
	TH1F   *hPerpPu_pu0[bin];
	TH1F *hParaCoPF_pu0[bin];
	TH1F *hPerpCoPF_pu0[bin];
	TH1F *hParaCoPu_pu0[bin];
	TH1F *hPerpCoPu_pu0[bin];

	const int nameN = 50;
	const int titleN = 100;    

	float ext = 400;

	char        nameH[nameN];
	char      nameGen[nameN];
	char  nameParaGen[nameN];
	char  namePerpGen[nameN];
	char   nameParaPF[nameN];
	char   namePerpPF[nameN];
	char   nameParaPu[nameN];
	char   namePerpPu[nameN];
	char nameParaCoPF[nameN];
	char namePerpCoPF[nameN];
	char nameParaCoPu[nameN];
	char namePerpCoPu[nameN];
	
	char		titleH[titleN];
	char      titleGen[titleN];
	char  titleParaGen[titleN];
	char  titlePerpGen[titleN];
	char   titleParaPF[titleN];
	char   titlePerpPF[titleN];
	char   titleParaPu[titleN];
	char   titlePerpPu[titleN];
	char titleParaCoPF[titleN];
	char titlePerpCoPF[titleN];
	char titleParaCoPu[titleN];
	char titlePerpCoPu[titleN];

	char        nameHpu0[nameN];
	char      nameGenpu0[nameN];
	char  nameParaGenpu0[nameN];
	char  namePerpGenpu0[nameN];
	char   nameParaPFpu0[nameN];
	char   namePerpPFpu0[nameN];
	char   nameParaPupu0[nameN];
	char   namePerpPupu0[nameN];
	char nameParaCoPFpu0[nameN];
	char namePerpCoPFpu0[nameN];
	char nameParaCoPupu0[nameN];
	char namePerpCoPupu0[nameN];
	
	char		titleHpu0[titleN];
	char      titleGenpu0[titleN];
	char  titleParaGenpu0[titleN];
	char  titlePerpGenpu0[titleN];
	char   titleParaPFpu0[titleN];
	char   titlePerpPFpu0[titleN];
	char   titleParaPupu0[titleN];
	char   titlePerpPupu0[titleN];
	char titleParaCoPFpu0[titleN];
	char titlePerpCoPFpu0[titleN];
	char titleParaCoPupu0[titleN];
	char titlePerpCoPupu0[titleN];

    for (int i = 0 ; i < bin ; i++)
    {
      sprintf(nameH, "hZ%d", i);
      sprintf(nameGen, "hGen%d", i);
      sprintf(nameParaGen, "hParaGen%d", i);
      sprintf(nameParaPF, "hParaPF%d", i);
      sprintf(nameParaPu, "hParaPu%d", i);
      sprintf(nameParaCoPF, "hParaCoPF%d", i);
      sprintf(nameParaCoPu, "hParaCoPu%d", i);
      sprintf(namePerpGen, "hPerpGen%d", i);
      sprintf(namePerpPF,   "hPerpPF%d", i);
      sprintf(namePerpPu,   "hPerpPu%d", i);
      sprintf(namePerpCoPF, "hPerpCoPF%d", i);
      sprintf(namePerpCoPu, "hPerpCoPu%d", i);

      sprintf(titleH, "hZ%d", i);
      sprintf(titleGen, "hGen%d", i);
      sprintf(titleParaGen, "hParaGen%d", i);
      sprintf(titleParaPF, "hParaPF%d", i);
      sprintf(titleParaPu, "hParaPu%d", i);
      sprintf(titleParaCoPF, "hParaCoPF%d", i);
      sprintf(titleParaCoPu, "hParaCoPu%d", i);
      sprintf(titlePerpGen, "hPerpGen%d", i);
      sprintf(titlePerpPF,   "hPerpPF%d", i);
      sprintf(titlePerpPu,   "hPerpPu%d", i);
      sprintf(titlePerpCoPF, "hPerpCoPF%d", i);
      sprintf(titlePerpCoPu, "hPerpCoPu%d", i);
      //hGe[i]= new TH1F(nameGe, titleGe, 160, mini+(i*binning_le), mini+((i+1)*binning_le));
          hZ[i]= new TH1F(nameH, titleH, 160, -1.*(maxi + ext), (maxi + ext));
        hGen[i]= new TH1F(nameGen, titleGen, 160, -1.*(maxi + ext), (maxi + ext));
        hParaGen[i]= new TH1F(nameParaGen, titleParaGen, 160, -1.*(maxi + ext), (maxi + ext));
        hPerpGen[i]= new TH1F(namePerpGen, titlePerpGen, 160, -1.*(maxi + ext), (maxi + ext));
          hParaPF[i]= new TH1F(nameParaPF, titleParaPF, 160, -1.*(maxi + ext), (maxi + ext));
          hParaPu[i]= new TH1F(nameParaPu, titleParaPu, 160, -1.*(maxi + ext), (maxi + ext));
      hParaCoPF[i]= new TH1F(nameParaCoPF, titleParaCoPF, 160, -1.*(maxi + ext), (maxi + ext));
      hParaCoPu[i]= new TH1F(nameParaCoPu, titleParaCoPu, 160, -1.*(maxi + ext), (maxi + ext));
          hPerpPF[i]= new TH1F(namePerpPF, titlePerpPF, 160, -1.*(maxi + ext), (maxi + ext));
          hPerpPu[i]= new TH1F(namePerpPu, titlePerpPu, 160, -1.*(maxi + ext), (maxi + ext));
      hPerpCoPF[i]= new TH1F(namePerpCoPF, titlePerpCoPF, 160, -1.*(maxi + ext), (maxi + ext));
      hPerpCoPu[i]= new TH1F(namePerpCoPu, titlePerpCoPu, 160, -1.*(maxi + ext), (maxi + ext));
    }

    for (int i = 0 ; i < bin ; i++)
    {
		 	 sprintf(nameHpu0,		  "hZ%d_pu0", i);
		   sprintf(nameGenpu0,		"hGen%d_pu0", i);
		   sprintf(nameParaGenpu0,		"hParaGen%d_pu0", i);
		sprintf(nameParaPFpu0,   "hParaPF%d_pu0", i);
		sprintf(nameParaPupu0,   "hParaPu%d_pu0", i);
      sprintf(nameParaCoPFpu0, "hParaCoPF%d_pu0", i);
      sprintf(nameParaCoPupu0, "hParaCoPu%d_pu0", i);
		   sprintf(namePerpGenpu0,		"hPerpGen%d_pu0", i);
		sprintf(namePerpPFpu0,   "hPerpPF%d_pu0", i);
		sprintf(namePerpPupu0,   "hPerpPu%d_pu0", i);
      sprintf(namePerpCoPFpu0, "hPerpCoPF%d_pu0", i);
      sprintf(namePerpCoPupu0, "hPerpCoPu%d_pu0", i);

			 sprintf(titleHpu0,		   "hZ%d_pu0", i);
		   sprintf(titleGenpu0,	     "hGen%d_pu0", i);
		   sprintf(titleParaGenpu0,	     "hParaGen%d_pu0", i);
		sprintf(titleParaPFpu0,   "hParaPF%d_pu0", i);
		sprintf(titleParaPupu0,   "hParaPu%d_pu0", i);
      sprintf(titleParaCoPFpu0, "hParaCoPF%d_pu0", i);
      sprintf(titleParaCoPupu0, "hParaCoPu%d_pu0", i);
		   sprintf(titlePerpGenpu0,	     "hPerpGen%d_pu0", i);
		sprintf(titlePerpPFpu0,   "hPerpPF%d_pu0", i);
		sprintf(titlePerpPupu0,   "hPerpPu%d_pu0", i);
      sprintf(titlePerpCoPFpu0, "hPerpCoPF%d_pu0", i);
      sprintf(titlePerpCoPupu0, "hPerpCoPu%d_pu0", i);
      //hGe[i]= new TH1F(nameGe, titleGe, 160, mini+(i*binning_le), mini+((i+1)*binning_le));
			   hZ_pu0[i]= new TH1F(		  nameHpu0,		   titleHpu0, 160, -1.*(maxi + ext), (maxi + ext));
			 hGen_pu0[i]= new TH1F(	    nameGenpu0,	     titleGenpu0, 160, -1.*(maxi + ext), (maxi + ext));
			 hParaGen_pu0[i]= new TH1F(	    nameParaGenpu0,	     titleParaGenpu0, 160, -1.*(maxi + ext), (maxi + ext));
			 hPerpGen_pu0[i]= new TH1F(	    namePerpGenpu0,	     titlePerpGenpu0, 160, -1.*(maxi + ext), (maxi + ext));
          hParaPF_pu0[i]= new TH1F(	 nameParaPFpu0,   titleParaPFpu0, 160, -1.*(maxi + ext), (maxi + ext));
          hParaPu_pu0[i]= new TH1F(	 nameParaPupu0,   titleParaPupu0, 160, -1.*(maxi + ext), (maxi + ext));
		hParaCoPF_pu0[i]= new TH1F(nameParaCoPFpu0, titleParaCoPFpu0, 160, -1.*(maxi + ext), (maxi + ext));
		hParaCoPu_pu0[i]= new TH1F(nameParaCoPupu0, titleParaCoPupu0, 160, -1.*(maxi + ext), (maxi + ext));
          hPerpPF_pu0[i]= new TH1F(	 namePerpPFpu0,   titlePerpPFpu0, 160, -1.*(maxi + ext), (maxi + ext));
          hPerpPu_pu0[i]= new TH1F(	 namePerpPupu0,   titlePerpPupu0, 160, -1.*(maxi + ext), (maxi + ext));
		hPerpCoPF_pu0[i]= new TH1F(namePerpCoPFpu0, titlePerpCoPFpu0, 160, -1.*(maxi + ext), (maxi + ext));
		hPerpCoPu_pu0[i]= new TH1F(namePerpCoPupu0, titlePerpCoPupu0, 160, -1.*(maxi + ext), (maxi + ext));
    }

// PU200
    for(int j = 0 ; j < n; j++)
    {
		TVector2 vZ;
		TVector2 vGen;
		TVector2 vPF;
		TVector2 vPu;
		TVector2 vCoPF;
		TVector2 vCoPu;

		TLorentzVector vMu1;
		TLorentzVector vMu2;
	
		vMu1.SetPtEtaPhiM(aMu1[j][0], aMu1[j][1], aMu1[j][2], aMu1[j][3]);
		vMu2.SetPtEtaPhiM(aMu2[j][0], aMu2[j][1], aMu2[j][2], aMu2[j][3]);

		TLorentzVector vZ_tmp = vMu1 + vMu2;

		if( aMu1[j][0] == 0 && aMu1[j][1] == 0 && aMu1[j][2] == 0 && aMu1[j][3] == 0) continue;
		hInv->Fill(vZ_tmp.M());

		if(fabs(vZ_tmp.M()) - 91. > 15. ) continue;

		vZ.SetMagPhi(vZ_tmp.Pt(), vZ_tmp.Phi());

		 vGen.SetMagPhi(agen[j], agenphi[j]);
		  vPF.SetMagPhi(apf[j], apfphi[j]);
		  vPu.SetMagPhi(apu[j], apuphi[j]);
		vCoPF.SetMagPhi(acopf[j], acopfphi[j]);
		vCoPu.SetMagPhi(acopu[j], acopuphi[j]);
		
		
		TVector2 vRGen   = -1.*(vGen + vZ);
		TVector2 vRPF     = -1.*(vPF + vZ);
		TVector2 vRPu     = -1.*(vPu + vZ);
		TVector2 vRCoPF = -1.*(vCoPF + vZ);
		TVector2 vRCoPu = -1.*(vCoPu + vZ);

		TVector2 vParaGen	= vRGen.Proj(vZ);
		TVector2 vParaPF	= vRPF.Proj(vZ);
		TVector2 vParaPu	= vRPu.Proj(vZ);
		TVector2 vParaCoPF = vRCoPF.Proj(vZ);
		TVector2 vParaCoPu = vRCoPu.Proj(vZ);
		TVector2 vPerpGen	= vRGen.Norm(vZ);
		TVector2 vPerpPF	= vRPF.Norm(vZ);
		TVector2 vPerpPu	= vRPu.Norm(vZ);
		TVector2 vPerpCoPF = vRCoPF.Norm(vZ);
		TVector2 vPerpCoPu = vRCoPu.Norm(vZ);

		for(int i = 0 ; i < bin; i++)
		{
			if( vZ.Mod() > mini + (i * binning_le) && vZ.Mod() <= mini + ( (i+1) * binning_le) ) 
			{
				  hZ[i]->Fill(vZ.Mod());
				  hGen[i]->Fill(vGen.Mod());


// Parallel
              if (fabs(vParaGen.DeltaPhi(vZ)) > TMath::Pi()/2)
              {
                  hParaGen[i]->Fill(vParaGen.Mod());
              } else {
                  hParaGen[i]->Fill(vParaGen.Mod()*-1.);
              }
              if (fabs(vParaPF.DeltaPhi(vZ)) > TMath::Pi()/2)
              {
                  hParaPF[i]->Fill(vParaPF.Mod());
              } else {
                  hParaPF[i]->Fill(vParaPF.Mod()*-1.);
              }
              if (fabs(vParaPu.DeltaPhi(vZ)) > TMath::Pi()/2)
              {
                  hParaPu[i]->Fill(vParaPu.Mod());
              } else {
                  hParaPu[i]->Fill(vParaPu.Mod()*-1.);
              }
              if (fabs(vParaCoPF.DeltaPhi(vZ)) > TMath::Pi()/2)
              {
                  hParaCoPF[i]->Fill(vParaCoPF.Mod());
              } else {
                  hParaCoPF[i]->Fill(vParaCoPF.Mod()*-1.);
              }
              if (fabs(vParaCoPu.DeltaPhi(vZ)) > TMath::Pi()/2)
              {
                  hParaCoPu[i]->Fill(vParaCoPu.Mod());
              } else {
                  hParaCoPu[i]->Fill(vParaCoPu.Mod()*-1.);
              }

// Perpendicular
              if (fabs(vPerpGen.DeltaPhi(vZ)) > TMath::Pi()/2)
              {
                  hPerpGen[i]->Fill(vPerpGen.Mod());
              } else {
                  hPerpGen[i]->Fill(vPerpGen.Mod()*-1.);
              }
              if (fabs(vPerpPF.DeltaPhi(vZ)) > TMath::Pi()/2)
              {
                  hPerpPF[i]->Fill(vPerpPF.Mod());
              } else {
                  hPerpPF[i]->Fill(vPerpPF.Mod()*-1.);
              }
              if (fabs(vPerpPu.DeltaPhi(vZ)) > TMath::Pi()/2)
              {
                  hPerpPu[i]->Fill(vPerpPu.Mod());
              } else {
                  hPerpPu[i]->Fill(vPerpPu.Mod()*-1.);
              }
              if (fabs(vPerpCoPF.DeltaPhi(vZ)) > TMath::Pi()/2)
              {
                  hPerpCoPF[i]->Fill(vPerpCoPF.Mod());
              } else {
                  hPerpCoPF[i]->Fill(vPerpCoPF.Mod()*-1.);
              }
              if (fabs(vPerpCoPu.DeltaPhi(vZ)) > TMath::Pi()/2)
              {
                  hPerpCoPu[i]->Fill(vPerpCoPu.Mod());
              } else {
                  hPerpCoPu[i]->Fill(vPerpCoPu.Mod()*-1.);
              }

			}

		}
	}

// PU0
    for(int j = 0 ; j < n; j++)
    {
		TVector2 vZ_pu0;
		TVector2 vGen_pu0;
		TVector2 vPF_pu0;
		TVector2 vPu_pu0;
		TVector2 vCoPF_pu0;
		TVector2 vCoPu_pu0;

		TLorentzVector vMu1_pu0;
		TLorentzVector vMu2_pu0;
	
		vMu1_pu0.SetPtEtaPhiM(aMu1_pu0[j][0], aMu1_pu0[j][1], aMu1_pu0[j][2], aMu1_pu0[j][2]);
		vMu2_pu0.SetPtEtaPhiM(aMu2_pu0[j][0], aMu2_pu0[j][1], aMu2_pu0[j][2], aMu2_pu0[j][2]);

		TLorentzVector vZ_tmp_pu0 = vMu1_pu0 + vMu2_pu0;

		if(aMu1_pu0[j][0] == 0 && aMu1_pu0[j][1] == 0 && aMu1_pu0[j][2] == 0 && aMu1_pu0[j][3] == 0) continue;
		hInv_pu0->Fill(vZ_tmp_pu0.M());

		if(fabs(vZ_tmp_pu0.M()) - 91. > 15.) continue;

		vZ_pu0.SetMagPhi(vZ_tmp_pu0.Pt(), vZ_tmp_pu0.Phi());

		  vGen_pu0.SetMagPhi(agenpu0[j], agenpu0phi[j]);
		   vPF_pu0.SetMagPhi(apfpu0[j], apfpu0phi[j]);
		   vPu_pu0.SetMagPhi(apupu0[j], apupu0phi[j]);
		vCoPF_pu0.SetMagPhi(acopfpu0[j], acopfpu0phi[j]);
		vCoPu_pu0.SetMagPhi(acopupu0[j], acopupu0phi[j]);


		TVector2 vRGen_pu0   = -1.*(vGen_pu0 + vZ_pu0);
		TVector2 vRPF_pu0     = -1.*(vPF_pu0 + vZ_pu0);
		TVector2 vRPu_pu0     = -1.*(vPu_pu0 + vZ_pu0);
		TVector2 vRCoPF_pu0 = -1.*(vCoPF_pu0 + vZ_pu0);
		TVector2 vRCoPu_pu0 = -1.*(vCoPu_pu0 + vZ_pu0);
		
		TVector2 vParaGen_pu0		= vRGen_pu0.Proj(vZ_pu0);
		//cout << "Para Gen pu0 : "<< vParaGen_pu0.Mod() << endl;
		TVector2 vParaPF_pu0		= vRPF_pu0.Proj(vZ_pu0);
		TVector2 vParaPu_pu0		= vRPu_pu0.Proj(vZ_pu0);
		TVector2 vParaCoPF_pu0	  = vRCoPF_pu0.Proj(vZ_pu0);
		TVector2 vParaCoPu_pu0   = vRCoPu_pu0.Proj(vZ_pu0);
		TVector2 vPerpGen_pu0		= vRGen_pu0.Norm(vZ_pu0);
		//cout << "Perp Gen pu0 : "<< vPerpGen_pu0.Mod() << endl;
		TVector2 vPerpPF_pu0		= vRPF_pu0.Norm(vZ_pu0);
		TVector2 vPerpPu_pu0		= vRPu_pu0.Norm(vZ_pu0);
		TVector2 vPerpCoPF_pu0   = vRCoPF_pu0.Norm(vZ_pu0);
		TVector2 vPerpCoPu_pu0   = vRCoPu_pu0.Norm(vZ_pu0);

		for(int i = 0 ; i < bin; i++)
		{
			if( vZ_pu0.Mod() > mini + (i * binning_le) && vZ_pu0.Mod() <= mini + ( (i+1) * binning_le) ) 
			{
				  hZ_pu0[i]->Fill(vZ_pu0.Mod());
				  hGen_pu0[i]->Fill(vGen_pu0.Mod());

// Parallel
              if (fabs(vParaGen_pu0.DeltaPhi(vZ_pu0)) > TMath::Pi()/2)
              {
                  hParaGen_pu0[i]->Fill(vParaGen_pu0.Mod());
		//cout << "Para Gen pu0 in histo : "<< vParaGen_pu0.Mod() << endl;
              } else {
                  hParaGen_pu0[i]->Fill(vParaGen_pu0.Mod()*-1.);
		//cout << "Para Gen pu0 in histo : "<< vParaGen_pu0.Mod()*-1. << endl;
              }
              if (fabs(vParaPF_pu0.DeltaPhi(vZ_pu0)) > TMath::Pi()/2)
              {
                  hParaPF_pu0[i]->Fill(vParaPF_pu0.Mod());
              } else {
                  hParaPF_pu0[i]->Fill(vParaPF_pu0.Mod()*-1.);
              }
              if (fabs(vParaPu_pu0.DeltaPhi(vZ_pu0)) > TMath::Pi()/2)
              {
                  hParaPu_pu0[i]->Fill(vParaPu_pu0.Mod());
              } else {
                  hParaPu_pu0[i]->Fill(vParaPu_pu0.Mod()*-1.);
              }
              if (fabs(vParaCoPF_pu0.DeltaPhi(vZ_pu0)) > TMath::Pi()/2)
              {
                  hParaCoPF_pu0[i]->Fill(vParaCoPF_pu0.Mod());
              } else {
                  hParaCoPF_pu0[i]->Fill(vParaCoPF_pu0.Mod()*-1.);
              }
              if (fabs(vParaCoPu_pu0.DeltaPhi(vZ_pu0)) > TMath::Pi()/2)
              {
                  hParaCoPu_pu0[i]->Fill(vParaCoPu_pu0.Mod());
              } else {
                  hParaCoPu_pu0[i]->Fill(vParaCoPu_pu0.Mod()*-1.);
              }

// Perpendicular
              if (fabs(vPerpGen_pu0.DeltaPhi(vZ_pu0)) > TMath::Pi()/2)
              {
                  hPerpGen_pu0[i]->Fill(vPerpGen_pu0.Mod());
		//cout << "Perp Gen pu0 in histo : "<< vPerpGen_pu0.Mod() << endl;
              } else {
                  hPerpGen_pu0[i]->Fill(vPerpGen_pu0.Mod()*-1.);
		//cout << "Perp Gen pu0 in histo : "<< vPerpGen_pu0.Mod()*-1. << endl;
              }
              if (fabs(vPerpPF_pu0.DeltaPhi(vZ_pu0)) > TMath::Pi()/2)
              {
                  hPerpPF_pu0[i]->Fill(vPerpPF_pu0.Mod());
              } else {
                  hPerpPF_pu0[i]->Fill(vPerpPF_pu0.Mod()*-1.);
              }
              if (fabs(vPerpPu_pu0.DeltaPhi(vZ_pu0)) > TMath::Pi()/2)
              {
                  hPerpPu_pu0[i]->Fill(vPerpPu_pu0.Mod());
              } else {
                  hPerpPu_pu0[i]->Fill(vPerpPu_pu0.Mod()*-1.);
              }
              if (fabs(vPerpCoPF_pu0.DeltaPhi(vZ_pu0)) > TMath::Pi()/2)
              {
                  hPerpCoPF_pu0[i]->Fill(vPerpCoPF_pu0.Mod());
              } else {
                  hPerpCoPF_pu0[i]->Fill(vPerpCoPF_pu0.Mod()*-1.);
              }
              if (fabs(vPerpCoPu_pu0.DeltaPhi(vZ_pu0)) > TMath::Pi()/2)
              {
                  hPerpCoPu_pu0[i]->Fill(vPerpCoPu_pu0.Mod());
              } else {
                  hPerpCoPu_pu0[i]->Fill(vPerpCoPu_pu0.Mod()*-1.);
              }

			}
		}
	}

	float        aZMean[bin];
	float      aGenMean[bin];
	float   aParaGenMean[bin];
	float   aParaPFMean[bin];
	float   aParaPuMean[bin];
	float aParaCoPFMean[bin];
	float aParaCoPuMean[bin];
	float   aPerpGenMean[bin];
	float   aPerpPFMean[bin];
	float   aPerpPuMean[bin];
	float aPerpCoPFMean[bin];
	float aPerpCoPuMean[bin];
	
	float        aZMean_pu0[bin];
	float      aGenMean_pu0[bin];
	float   aParaGenMean_pu0[bin];
	float   aParaPFMean_pu0[bin];
	float   aParaPuMean_pu0[bin];
	float aParaCoPFMean_pu0[bin];
	float aParaCoPuMean_pu0[bin];
	float   aPerpGenMean_pu0[bin];
	float   aPerpPFMean_pu0[bin];
	float   aPerpPuMean_pu0[bin];
	float aPerpCoPFMean_pu0[bin];
	float aPerpCoPuMean_pu0[bin];

	float        aZMeanEr[bin];
	float      aGenMeanEr[bin];
	float   aParaGenMeanEr[bin];
	float   aParaPFMeanEr[bin];
	float   aParaPuMeanEr[bin];
	float aParaCoPFMeanEr[bin];
	float aParaCoPuMeanEr[bin];
	float   aPerpGenMeanEr[bin];
	float   aPerpPFMeanEr[bin];
	float   aPerpPuMeanEr[bin];
	float aPerpCoPFMeanEr[bin];
	float aPerpCoPuMeanEr[bin];
	
	float        aZMean_pu0Er[bin];
	float      aGenMean_pu0Er[bin];
	float   aParaGenMean_pu0Er[bin];
	float   aParaPFMean_pu0Er[bin];
	float   aParaPuMean_pu0Er[bin];
	float aParaCoPFMean_pu0Er[bin];
	float aParaCoPuMean_pu0Er[bin];
	float   aPerpGenMean_pu0Er[bin];
	float   aPerpPFMean_pu0Er[bin];
	float   aPerpPuMean_pu0Er[bin];
	float aPerpCoPFMean_pu0Er[bin];
	float aPerpCoPuMean_pu0Er[bin];

	float   aGenRes[bin];
	float   aPFRes[bin];
	float   aPuRes[bin];
	float aCoPFRes[bin];
	float aCoPuRes[bin];

	float   aGenResEr[bin];
	float   aPFResEr[bin];
	float   aPuResEr[bin];
	float aCoPFResEr[bin];
	float aCoPuResEr[bin];

	float   aGenRes_pu0[bin];
	float   aPFRes_pu0[bin];
	float   aPuRes_pu0[bin];
	float aCoPFRes_pu0[bin];
	float aCoPuRes_pu0[bin];

	float   aGenResEr_pu0[bin];
	float   aPFResEr_pu0[bin];
	float   aPuResEr_pu0[bin];
	float aCoPFResEr_pu0[bin];
	float aCoPuResEr_pu0[bin];

	float    aGenParaSol[bin];
	float     aPFParaSol[bin];
	float     aPuParaSol[bin];
	float   aCoPFParaSol[bin];
	float   aCoPuParaSol[bin];

	float    aGenParaSolEr[bin];
	float     aPFParaSolEr[bin];
	float     aPuParaSolEr[bin];
	float   aCoPFParaSolEr[bin];
	float   aCoPuParaSolEr[bin];

	float    aGenParaSol_pu0[bin];
	float     aPFParaSol_pu0[bin];
	float     aPuParaSol_pu0[bin];
	float   aCoPFParaSol_pu0[bin];
	float   aCoPuParaSol_pu0[bin];

	float    aGenParaSolEr_pu0[bin];
	float     aPFParaSolEr_pu0[bin];
	float     aPuParaSolEr_pu0[bin];
	float   aCoPFParaSolEr_pu0[bin];
	float   aCoPuParaSolEr_pu0[bin];

	float    aGenPerpSol[bin];
	float     aPFPerpSol[bin];
	float     aPuPerpSol[bin];
	float   aCoPFPerpSol[bin];
	float   aCoPuPerpSol[bin];

	float    aGenPerpSolEr[bin];
	float     aPFPerpSolEr[bin];
	float     aPuPerpSolEr[bin];
	float   aCoPFPerpSolEr[bin];
	float   aCoPuPerpSolEr[bin];

	float    aGenPerpSol_pu0[bin];
	float     aPFPerpSol_pu0[bin];
	float     aPuPerpSol_pu0[bin];
	float   aCoPFPerpSol_pu0[bin];
	float   aCoPuPerpSol_pu0[bin];

	float    aGenPerpSolEr_pu0[bin];
	float     aPFPerpSolEr_pu0[bin];
	float     aPuPerpSolEr_pu0[bin];
	float   aCoPFPerpSolEr_pu0[bin];
	float   aCoPuPerpSolEr_pu0[bin];

	TFile *f1 = new TFile("binHists.root", "RECREATE");
float total;
cout << "Number of Events" << endl;
	for(int i = 0 ; i < bin ; i++)
	{
cout <<i<<"th bin: "<< hZ[i]->GetEntries() <<endl;
	        aZMean[i] =        hZ[i]->GetMean();
	      aGenMean[i] =      hGen[i]->GetMean();
	   aParaGenMean[i] =   hParaGen[i]->GetMean();
	   aParaPFMean[i] =   hParaPF[i]->GetMean();
	   aParaPuMean[i] =   hParaPu[i]->GetMean();
	 aParaCoPFMean[i] =   hParaCoPF[i]->GetMean();
	 aParaCoPuMean[i] =   hParaCoPu[i]->GetMean();
	   aPerpGenMean[i] = hPerpGen[i]->GetMean();
	   aPerpPFMean[i] = hPerpPF[i]->GetMean();
	   aPerpPuMean[i] = hPerpPu[i]->GetMean();
	 aPerpCoPFMean[i] = hPerpCoPF[i]->GetMean();
	 aPerpCoPuMean[i] = hPerpCoPu[i]->GetMean();

	        aZMean_pu0[i] =        hZ_pu0[i]->GetMean();
	      aGenMean_pu0[i] =      hGen_pu0[i]->GetMean();
	   aParaGenMean_pu0[i] =   hParaGen_pu0[i]->GetMean();
	   aParaPFMean_pu0[i] =   hParaPF_pu0[i]->GetMean();
	   aParaPuMean_pu0[i] =   hParaPu_pu0[i]->GetMean();
	 aParaCoPFMean_pu0[i] =   hParaCoPF_pu0[i]->GetMean();
	 aParaCoPuMean_pu0[i] =   hParaCoPu_pu0[i]->GetMean();
	   aPerpGenMean_pu0[i] = hPerpGen_pu0[i]->GetMean();
	   aPerpPFMean_pu0[i] = hPerpPF_pu0[i]->GetMean();
	   aPerpPuMean_pu0[i] = hPerpPu_pu0[i]->GetMean();
	 aPerpCoPFMean_pu0[i] = hPerpCoPF_pu0[i]->GetMean();
	 aPerpCoPuMean_pu0[i] = hPerpCoPu_pu0[i]->GetMean();

	        aZMeanEr[i] =        hZ[i]->GetRMS();
	      aGenMeanEr[i] =      hGen[i]->GetRMS();
	   aParaGenMeanEr[i] =   hParaGen[i]->GetRMS();
	   aParaPFMeanEr[i] =   hParaPF[i]->GetRMS();
	   aParaPuMeanEr[i] =   hParaPu[i]->GetRMS();
	 aParaCoPFMeanEr[i] =   hParaCoPF[i]->GetRMS();
	 aParaCoPuMeanEr[i] =   hParaCoPu[i]->GetRMS();
	   aPerpGenMeanEr[i] = hPerpGen[i]->GetRMS();
	   aPerpPFMeanEr[i] = hPerpPF[i]->GetRMS();
	   aPerpPuMeanEr[i] = hPerpPu[i]->GetRMS();
	 aPerpCoPFMeanEr[i] = hPerpCoPF[i]->GetRMS();
	 aPerpCoPuMeanEr[i] = hPerpCoPu[i]->GetRMS();
	
	        aZMean_pu0Er[i] =        hZ_pu0[i]->GetRMS();
	      aGenMean_pu0Er[i] =      hGen_pu0[i]->GetRMS();
	   aParaGenMean_pu0Er[i] =   hParaGen_pu0[i]->GetRMS();
	   aParaPFMean_pu0Er[i] =   hParaPF_pu0[i]->GetRMS();
	   aParaPuMean_pu0Er[i] =   hParaPu_pu0[i]->GetRMS();
	 aParaCoPFMean_pu0Er[i] =   hParaCoPF_pu0[i]->GetRMS();
	 aParaCoPuMean_pu0Er[i] =   hParaCoPu_pu0[i]->GetRMS();
	   aPerpGenMean_pu0Er[i] = hPerpGen_pu0[i]->GetRMS();
	   aPerpPFMean_pu0Er[i] = hPerpPF_pu0[i]->GetRMS();
	   aPerpPuMean_pu0Er[i] = hPerpPu_pu0[i]->GetRMS();
	 aPerpCoPFMean_pu0Er[i] = hPerpCoPF_pu0[i]->GetRMS();
	 aPerpCoPuMean_pu0Er[i] = hPerpCoPu_pu0[i]->GetRMS();
		
	  aGenRes[i] =   aParaGenMean[i] / aZMean[i];
	  aPFRes[i] =   aParaPFMean[i] / aZMean[i];
	  aPuRes[i] =   aParaPuMean[i] / aZMean[i];
//cout << " Pu Mean: "<< aParaPuMean[i] << endl;
	aCoPFRes[i] = aParaCoPFMean[i] / aZMean[i];
	aCoPuRes[i] = aParaCoPuMean[i] / aZMean[i];

	  aGenRes_pu0[i] =   aParaGenMean_pu0[i] / aZMean[i];
	  aPFRes_pu0[i] =   aParaPFMean_pu0[i] / aZMean[i];
	  aPuRes_pu0[i] =   aParaPuMean_pu0[i] / aZMean[i];
//cout << "pu0 Pu Mean: "<< aParaPuMean_pu0[i] << endl;
	aCoPFRes_pu0[i] = aParaCoPFMean_pu0[i] / aZMean[i];
	aCoPuRes_pu0[i] = aParaCoPuMean_pu0[i] / aZMean[i];

	float Hx =  hZ[i]->GetRMS() / sqrt(hZ[i]->GetEntries());
	float Genx = hParaGen[i]->GetRMS() / sqrt(hParaGen[i]->GetEntries());
	float PFx = hParaPF[i]->GetRMS() / sqrt(hParaPF[i]->GetEntries());
	float Pux = hParaPu[i]->GetRMS() / sqrt(hParaPu[i]->GetEntries());
	float CoPFx = hParaCoPF[i]->GetRMS() / sqrt(hParaCoPF[i]->GetEntries());
	float CoPux = hParaCoPu[i]->GetRMS() / sqrt(hParaCoPu[i]->GetEntries());

	float Hx_pu0 =  hZ_pu0[i]->GetRMS() / sqrt(hZ_pu0[i]->GetEntries());
	float Genx_pu0 = hParaGen_pu0[i]->GetRMS() / sqrt(hParaGen_pu0[i]->GetEntries());
	float PFx_pu0 = hParaPF_pu0[i]->GetRMS() / sqrt(hParaPF_pu0[i]->GetEntries());
	float Pux_pu0 = hParaPu_pu0[i]->GetRMS() / sqrt(hParaPu_pu0[i]->GetEntries());
	float CoPFx_pu0 = hParaCoPF_pu0[i]->GetRMS() / sqrt(hParaCoPF_pu0[i]->GetEntries());
	float CoPux_pu0 = hParaCoPu_pu0[i]->GetRMS() / sqrt(hParaCoPu_pu0[i]->GetEntries());

		aGenResEr[i] = (aParaGenMean[i]/aZMean[i]) * sqrt( pow( Genx/aParaGenMean[i] , 2) + pow( Hx/aZMean[i], 2) );
		aPFResEr[i] = (aParaPFMean[i]/aZMean[i]) * sqrt( pow( PFx/aParaPFMean[i] , 2) + pow( Hx/aZMean[i], 2) );
		aPuResEr[i] = (aParaPuMean[i]/aZMean[i]) * sqrt( pow( Pux/aParaPuMean[i] , 2) + pow( Hx/aZMean[i], 2) );
		aCoPFResEr[i] = (aParaCoPFMean[i]/aZMean[i]) * sqrt( pow( CoPFx/aParaCoPFMean[i] , 2) + pow( Hx/aZMean[i], 2) );
		aCoPuResEr[i] = (aParaCoPuMean[i]/aZMean[i]) * sqrt( pow( CoPux/aParaCoPuMean[i] , 2) + pow( Hx/aZMean[i], 2) );

		aGenResEr_pu0[i] = (aParaGenMean_pu0[i]/aZMean_pu0[i]) * sqrt( pow( Genx_pu0/aParaGenMean_pu0[i] , 2) + pow( Hx_pu0/aZMean_pu0[i], 2) );
		aPFResEr_pu0[i] = (aParaPFMean_pu0[i]/aZMean_pu0[i]) * sqrt( pow( PFx_pu0/aParaPFMean_pu0[i] , 2) + pow( Hx_pu0/aZMean_pu0[i], 2) );
		aPuResEr_pu0[i] = (aParaPuMean_pu0[i]/aZMean_pu0[i]) * sqrt( pow( Pux_pu0/aParaPuMean_pu0[i] , 2) + pow( Hx_pu0/aZMean_pu0[i], 2) );
		aCoPFResEr_pu0[i] = (aParaCoPFMean_pu0[i]/aZMean_pu0[i]) * sqrt( pow( CoPFx_pu0/aParaCoPFMean_pu0[i] , 2) + pow( Hx_pu0/aZMean_pu0[i], 2) );
		aCoPuResEr_pu0[i] = (aParaCoPuMean_pu0[i]/aZMean_pu0[i]) * sqrt( pow( CoPux_pu0/aParaCoPuMean_pu0[i] , 2) + pow( Hx_pu0/aZMean_pu0[i], 2) );

// Para Resolution
	    aGenParaSol[i]  = hParaGen[i]->GetRMS();
	     aPFParaSol[i]   = hParaPF[i]->GetRMS();
	     aPuParaSol[i]   = hParaPu[i]->GetRMS();
	   aCoPFParaSol[i] = hParaCoPF[i]->GetRMS();
	   aCoPuParaSol[i] = hParaCoPu[i]->GetRMS();

	    aGenParaSolEr[i]  = hParaGen[i]->GetRMSError();
	     aPFParaSolEr[i]   = hParaPF[i]->GetRMSError();
	     aPuParaSolEr[i]   = hParaPu[i]->GetRMSError();
	   aCoPFParaSolEr[i] = hParaCoPF[i]->GetRMSError();
	   aCoPuParaSolEr[i] = hParaCoPu[i]->GetRMSError();

	    aGenParaSol_pu0[i]  = hParaGen_pu0[i]->GetRMS();
	     aPFParaSol_pu0[i]   = hParaPF_pu0[i]->GetRMS();
	     aPuParaSol_pu0[i]   = hParaPu_pu0[i]->GetRMS();
	   aCoPFParaSol_pu0[i] = hParaCoPF_pu0[i]->GetRMS();
	   aCoPuParaSol_pu0[i] = hParaCoPu_pu0[i]->GetRMS();

	    aGenParaSolEr_pu0[i]  = hParaGen_pu0[i]->GetRMSError();
	     aPFParaSolEr_pu0[i]   = hParaPF_pu0[i]->GetRMSError();
	     aPuParaSolEr_pu0[i]   = hParaPu_pu0[i]->GetRMSError();
	   aCoPFParaSolEr_pu0[i] = hParaCoPF_pu0[i]->GetRMSError();
	   aCoPuParaSolEr_pu0[i] = hParaCoPu_pu0[i]->GetRMSError();

// Perpendicular Resolution
	    aGenPerpSol[i] = hPerpGen[i]->GetRMS();
	     aPFPerpSol[i] = hPerpPF[i]->GetRMS();
	     aPuPerpSol[i] = hPerpPu[i]->GetRMS();
	   aCoPFPerpSol[i] = hPerpCoPF[i]->GetRMS();
	   aCoPuPerpSol[i] = hPerpCoPu[i]->GetRMS();

	    aGenPerpSolEr[i] = hPerpGen[i]->GetRMSError();
	     aPFPerpSolEr[i] = hPerpPF[i]->GetRMSError();
	     aPuPerpSolEr[i] = hPerpPu[i]->GetRMSError();
	   aCoPFPerpSolEr[i] = hPerpCoPF[i]->GetRMSError();
	   aCoPuPerpSolEr[i] = hPerpCoPu[i]->GetRMSError();

	    aGenPerpSol_pu0[i] = hPerpGen_pu0[i]->GetRMS();
	     aPFPerpSol_pu0[i] = hPerpPF_pu0[i]->GetRMS();
	     aPuPerpSol_pu0[i] = hPerpPu_pu0[i]->GetRMS();
	   aCoPFPerpSol_pu0[i] = hPerpCoPF_pu0[i]->GetRMS();
	   aCoPuPerpSol_pu0[i] = hPerpCoPu_pu0[i]->GetRMS();

	    aGenPerpSolEr_pu0[i] = hPerpGen_pu0[i]->GetRMSError();
	     aPFPerpSolEr_pu0[i] = hPerpPF_pu0[i]->GetRMSError();
	     aPuPerpSolEr_pu0[i] = hPerpPu_pu0[i]->GetRMSError();
	   aCoPFPerpSolEr_pu0[i] = hPerpCoPF_pu0[i]->GetRMSError();
	   aCoPuPerpSolEr_pu0[i] = hPerpCoPu_pu0[i]->GetRMSError();
	}

	f1->Close();

	float linx[2] = {0, maxi};
	float liny[2] = {1, 1};
	

	TGraphErrors *gHGen=   new TGraphErrors(bin, aZMean, aGenRes  , 0, aGenResEr  );
	TGraphErrors *gHPF =   new TGraphErrors(bin, aZMean, aPFRes  , 0, aPFResEr  );
	TGraphErrors *gHPu =   new TGraphErrors(bin, aZMean, aPuRes  , 0, aPuResEr  );
	TGraphErrors *gHCoPF = new TGraphErrors(bin, aZMean, aCoPFRes, 0, aCoPFResEr);
	TGraphErrors *gHCoPu = new TGraphErrors(bin, aZMean, aCoPuRes, 0, aCoPuResEr);

	  gHGen->GetXaxis()->SetRangeUser(0, maxi+20);
	  gHPF->GetXaxis()->SetRangeUser(0, maxi+20);
	  gHPu->GetXaxis()->SetRangeUser(0, maxi+20);
	gHCoPF->GetXaxis()->SetRangeUser(0, maxi+20);
	gHCoPu->GetXaxis()->SetRangeUser(0, maxi+20);

	  gHGen->GetYaxis()->SetRangeUser(0, 2);
	  gHPF->GetYaxis()->SetRangeUser(0, 2);
	  gHPu->GetYaxis()->SetRangeUser(0, 2);
	gHCoPF->GetYaxis()->SetRangeUser(0, 2);
	gHCoPu->GetYaxis()->SetRangeUser(0, 2);

	  gHGen->SetMarkerStyle(20);
	  gHPF->SetMarkerStyle(20);
	  gHPu->SetMarkerStyle(20);
	gHCoPF->SetMarkerStyle(20);
	gHCoPu->SetMarkerStyle(20);
	  
	gHGen->SetLineColor(kGreen+3);
	  gHPF->SetLineColor(kBlue);
	  gHPu->SetLineColor(kRed);
	gHCoPF->SetLineColor(kBlue);
	gHCoPu->SetLineColor(kRed);
	 gHGen->SetLineWidth(2);
	  gHPF->SetLineWidth(2);
	  gHPu->SetLineWidth(2);
	gHCoPF->SetLineWidth(2);
	gHCoPu->SetLineWidth(2);

   TLegend *lg1 = new TLegend(0.4175434,0.6922664,0.8580077,0.8533835,NULL,"brNDC");

	lg1->SetLineWidth(0);
	lg1->AddEntry(gHGen, "Gen MET Response", "l");
	lg1->AddEntry(gHPF, "PF MET Response", "l");
	lg1->AddEntry(gHPu, "Puppi MET Response", "l");
	
	TCanvas *c1 = new TCanvas("c1", "", 1000, 500);
	c1->Divide(2, 1);

	c1->cd(1);
	gHPF->SetTitle("Uncorrected MET response");
	gHGen->GetYaxis()->SetTitle("- <u_{||}> / <q_{T}>");
	gHGen->GetXaxis()->SetTitle("<q_{T}>");
	gHGen->Draw("APL");
	gHPF->Draw("PLSAME");
	gHPu->Draw("PLSAME");
	lg1->Draw();

	c1->cd(2);
	gHCoPF->SetTitle("Corrected MET response");
	gHGen->Draw("APL");
	gHCoPF->Draw("PLSAME");
	gHCoPu->Draw("PLSAME");
	lg1->Draw();

	c1->Print(sDir+"/MET_res_"+sName+"pu200.pdf");

	TGraphErrors *gHGen_pu0 =   new TGraphErrors(bin, aZMean_pu0, aGenRes_pu0  , 0, aGenResEr_pu0  );
	TGraphErrors *gHPF_pu0 =   new TGraphErrors(bin, aZMean_pu0, aPFRes_pu0  , 0, aPFResEr_pu0  );
	TGraphErrors *gHPu_pu0 =   new TGraphErrors(bin, aZMean_pu0, aPuRes_pu0  , 0, aPuResEr_pu0  );
	TGraphErrors *gHCoPF_pu0 = new TGraphErrors(bin, aZMean_pu0, aCoPFRes_pu0, 0, aCoPFResEr_pu0);
	TGraphErrors *gHCoPu_pu0 = new TGraphErrors(bin, aZMean_pu0, aCoPuRes_pu0, 0, aCoPuResEr_pu0);

	  gHGen_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	  gHPF_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	  gHPu_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	gHCoPF_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	gHCoPu_pu0->GetXaxis()->SetRangeUser(0, maxi+20);

	  gHGen_pu0->GetYaxis()->SetRangeUser(0, 2);
	  gHPF_pu0->GetYaxis()->SetRangeUser(0, 2);
	  gHPu_pu0->GetYaxis()->SetRangeUser(0, 2);
	gHCoPF_pu0->GetYaxis()->SetRangeUser(0, 2);
	gHCoPu_pu0->GetYaxis()->SetRangeUser(0, 2);

	  gHGen_pu0->SetMarkerStyle(20);
	  gHPF_pu0->SetMarkerStyle(20);
	  gHPu_pu0->SetMarkerStyle(20);
	gHCoPF_pu0->SetMarkerStyle(20);
	gHCoPu_pu0->SetMarkerStyle(20);
	  
	  gHGen_pu0->SetLineColor(kGreen+3);
	  gHPF_pu0->SetLineColor(kBlue);
	  gHPu_pu0->SetLineColor(kRed);
	gHCoPF_pu0->SetLineColor(kBlue);
	gHCoPu_pu0->SetLineColor(kRed);
	 gHGen_pu0->SetLineWidth(2);
	  gHPF_pu0->SetLineWidth(2);
	  gHPu_pu0->SetLineWidth(2);
	gHCoPF_pu0->SetLineWidth(2);
	gHCoPu_pu0->SetLineWidth(2);

   TLegend *lg2 = new TLegend(0.4175434,0.6922664,0.8580077,0.8533835,NULL,"brNDC");

	lg2->SetLineWidth(0);
	lg2->AddEntry(gHGen_pu0, "Gen MET Response", "l");
	lg2->AddEntry(gHPF_pu0, "PF MET Response", "l");
	lg2->AddEntry(gHPu_pu0, "Puppi MET Response", "l");
	
	TCanvas *c2 = new TCanvas("c2", "", 1000, 500);
	c2->Divide(2, 1);

	c2->cd(1);
	gHPF_pu0->SetTitle("Uncorrected MET response");
	gHGen_pu0->GetYaxis()->SetTitle("- <u_{||}> / <q_{T}>");
	gHGen_pu0->GetXaxis()->SetTitle("<q_{T}>");
	gHGen_pu0->Draw("APL");
	gHPF_pu0->Draw("PLSAME");
	gHPu_pu0->Draw("PLSAME");
	lg2->Draw();

	c2->cd(2);
	gHCoPF_pu0->SetTitle("Corrected MET response");
	gHGen_pu0->Draw("APL");
	gHCoPF_pu0->Draw("PLSAME");
	gHCoPu_pu0->Draw("PLSAME");
	lg2->Draw();

	c2->Print(sDir+"/MET_res_"+sName+"pu0.pdf");

	float ymax = 200.;

	TGraphErrors *gParaGen  = new TGraphErrors(bin, aZMean,  aGenParaSol, 0,  aGenParaSolEr);
	TGraphErrors *gParaPF   = new TGraphErrors(bin, aZMean,   aPFParaSol, 0,   aPFParaSolEr);
	TGraphErrors *gParaPu   = new TGraphErrors(bin, aZMean,   aPuParaSol, 0,   aPuParaSolEr);
	TGraphErrors *gParaCoPF = new TGraphErrors(bin, aZMean, aCoPFParaSol, 0, aCoPFParaSolEr);
	TGraphErrors *gParaCoPu = new TGraphErrors(bin, aZMean, aCoPuParaSol, 0, aCoPuParaSolEr);
	
      gParaGen->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaPF->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaPu->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaCoPF->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaCoPu->GetXaxis()->SetRangeUser(0, maxi+20);

	   gParaGen->GetYaxis()->SetRangeUser(0, ymax);
	    gParaPF->GetYaxis()->SetRangeUser(0, ymax);
	    gParaPu->GetYaxis()->SetRangeUser(0, ymax);
	  gParaCoPF->GetYaxis()->SetRangeUser(0, ymax);
	  gParaCoPu->GetYaxis()->SetRangeUser(0, ymax);

	  gParaGen->SetMarkerStyle(20);
	  gParaPF->SetMarkerStyle(20);
	  gParaPu->SetMarkerStyle(20);
	  gParaCoPF->SetMarkerStyle(20);
	  gParaCoPu->SetMarkerStyle(20);
	  
	  gParaGen->SetLineColor(kGreen+3);
	  gParaPF->SetLineColor(kBlue);
	  gParaPu->SetLineColor(kRed);
	  gParaCoPF->SetLineColor(kBlue);
	  gParaCoPu->SetLineColor(kRed);
	   gParaGen->SetLineWidth(2);
	    gParaPF->SetLineWidth(2);
	    gParaPu->SetLineWidth(2);
	  gParaCoPF->SetLineWidth(2);
	  gParaCoPu->SetLineWidth(2);

   TLegend *lg3 = new TLegend(0.1649549,0.6944146,0.6054192,0.8555317,NULL,"brNDC");

	lg3->SetLineWidth(0);
	 lg3->AddEntry(gParaGen, "Gen MET Resolution", "l");
	   lg3->AddEntry(gParaPF, "PF MET Resolution", "l");
	lg3->AddEntry(gParaPu, "Puppi MET Resolution", "l");
	
	TCanvas *cPa = new TCanvas("cPa", "", 1000, 500);
	cPa->Divide(2, 1);

	cPa->cd(1);
	gParaPF->SetTitle("Uncorrected MET response");
	gParaGen->GetYaxis()->SetTitle("- #sigma(u_{||})");
	gParaGen->GetXaxis()->SetTitle("<q_{T}>");
	gParaGen->Draw("APL");
	gParaPF->Draw("PLSAME");
	gParaPu->Draw("PLSAME");
	lg3->Draw();

	cPa->cd(2);
	gParaCoPF->SetTitle("Corrected MET response");
	gParaGen->Draw("APL");
	gParaCoPF->Draw("PLSAME");
	gParaCoPu->Draw("PLSAME");
	lg3->Draw();

	cPa->Print(sDir+"/MET_resol_para_"+sName+"pu200.pdf");

	TGraphErrors *gParaGen_pu0  = new TGraphErrors(bin, aZMean_pu0,  aGenParaSol_pu0, 0,  aGenParaSolEr_pu0);
	TGraphErrors *gParaPF_pu0   = new TGraphErrors(bin, aZMean_pu0,   aPFParaSol_pu0, 0,   aPFParaSolEr_pu0);
	TGraphErrors *gParaPu_pu0   = new TGraphErrors(bin, aZMean_pu0,   aPuParaSol_pu0, 0,   aPuParaSolEr_pu0);
	TGraphErrors *gParaCoPF_pu0 = new TGraphErrors(bin, aZMean_pu0, aCoPFParaSol_pu0, 0, aCoPFParaSolEr_pu0);
	TGraphErrors *gParaCoPu_pu0 = new TGraphErrors(bin, aZMean_pu0, aCoPuParaSol_pu0, 0, aCoPuParaSolEr_pu0);

      gParaGen_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaPF_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaPu_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaCoPF_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaCoPu_pu0->GetXaxis()->SetRangeUser(0, maxi+20);

	   gParaGen_pu0->GetYaxis()->SetRangeUser(0, ymax);
	    gParaPF_pu0->GetYaxis()->SetRangeUser(0, ymax);
	    gParaPu_pu0->GetYaxis()->SetRangeUser(0, ymax);
	  gParaCoPF_pu0->GetYaxis()->SetRangeUser(0, ymax);
	  gParaCoPu_pu0->GetYaxis()->SetRangeUser(0, ymax);

	  gParaGen_pu0->SetMarkerStyle(20);
	  gParaPF_pu0->SetMarkerStyle(20);
	  gParaPu_pu0->SetMarkerStyle(20);
	  gParaCoPF_pu0->SetMarkerStyle(20);
	  gParaCoPu_pu0->SetMarkerStyle(20);
	  
	  gParaGen_pu0->SetLineColor(kGreen+3);
	  gParaPF_pu0->SetLineColor(kBlue);
	  gParaPu_pu0->SetLineColor(kRed);
	  gParaCoPF_pu0->SetLineColor(kBlue);
	  gParaCoPu_pu0->SetLineColor(kRed);
	   gParaGen_pu0->SetLineWidth(2);
	    gParaPF_pu0->SetLineWidth(2);
	    gParaPu_pu0->SetLineWidth(2);
	  gParaCoPF_pu0->SetLineWidth(2);
	  gParaCoPu_pu0->SetLineWidth(2);

	TCanvas *cPa_pu0 = new TCanvas("cPa_pu0", "", 1000, 500);
	cPa_pu0->Divide(2, 1);

	cPa_pu0->cd(1);
	gParaPF_pu0->SetTitle("Uncorrected MET response");
	gParaGen_pu0->GetYaxis()->SetTitle("- #sigma(u_{||})");
	gParaGen_pu0->GetXaxis()->SetTitle("<q_{T}>");
	gParaGen_pu0->Draw("APL");
	gParaPF_pu0->Draw("PLSAME");
	gParaPu_pu0->Draw("PLSAME");
	lg3->Draw();

	cPa_pu0->cd(2);
	gParaCoPF_pu0->SetTitle("Corrected MET response");
	gParaGen_pu0->Draw("APL");
	gParaCoPF_pu0->Draw("PLSAME");
	gParaCoPu_pu0->Draw("PLSAME");
	lg3->Draw();

	cPa_pu0->Print(sDir+"/MET_resol_para_"+sName+"pu0.pdf");

	TGraphErrors *gPerpGen  = new TGraphErrors(bin, aZMean,  aGenPerpSol, 0,  aGenPerpSolEr);
	TGraphErrors *gPerpPF   = new TGraphErrors(bin, aZMean,   aPFPerpSol, 0,   aPFPerpSolEr);
	TGraphErrors *gPerpPu   = new TGraphErrors(bin, aZMean,   aPuPerpSol, 0,   aPuPerpSolEr);
	TGraphErrors *gPerpCoPF = new TGraphErrors(bin, aZMean, aCoPFPerpSol, 0, aCoPFPerpSolEr);
	TGraphErrors *gPerpCoPu = new TGraphErrors(bin, aZMean, aCoPuPerpSol, 0, aCoPuPerpSolEr);
	
      gPerpGen->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpPF->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpPu->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpCoPF->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpCoPu->GetXaxis()->SetRangeUser(0, maxi+20);

	   gPerpGen->GetYaxis()->SetRangeUser(0, ymax);
	    gPerpPF->GetYaxis()->SetRangeUser(0, ymax);
	    gPerpPu->GetYaxis()->SetRangeUser(0, ymax);
	  gPerpCoPF->GetYaxis()->SetRangeUser(0, ymax);
	  gPerpCoPu->GetYaxis()->SetRangeUser(0, ymax);

	  gPerpGen->SetMarkerStyle(20);
	  gPerpPF->SetMarkerStyle(20);
	  gPerpPu->SetMarkerStyle(20);
	  gPerpCoPF->SetMarkerStyle(20);
	  gPerpCoPu->SetMarkerStyle(20);
	  
	  gPerpGen->SetLineColor(kGreen+3);
	  gPerpPF->SetLineColor(kBlue);
	  gPerpPu->SetLineColor(kRed);
	  gPerpCoPF->SetLineColor(kBlue);
	  gPerpCoPu->SetLineColor(kRed);
	   gPerpGen->SetLineWidth(2);
	    gPerpPF->SetLineWidth(2);
	    gPerpPu->SetLineWidth(2);
	  gPerpCoPF->SetLineWidth(2);
	  gPerpCoPu->SetLineWidth(2);

   TLegend *lg_per = new TLegend(0.1649549,0.6944146,0.6054192,0.8555317,NULL,"brNDC");

	lg_per->SetLineWidth(0);
	lg_per->AddEntry(gPerpGen, "Gen MET Resolution", "l");
	lg_per->AddEntry(gPerpPF, "PF MET Resolution", "l");
	lg_per->AddEntry(gPerpPu, "Puppi MET Resolution", "l");
	
	TCanvas *cPe = new TCanvas("cPe", "", 1000, 500);
	cPe->Divide(2, 1);

	cPe->cd(1);
	gPerpPF->SetTitle("Uncorrected MET response");
	gPerpGen->GetYaxis()->SetTitle("- #sigma(u_{#perp}  )");
	gPerpGen->GetXaxis()->SetTitle("<q_{T}>");
	gPerpGen->Draw("APL");
	gPerpPF->Draw("PLSAME");
	gPerpPu->Draw("PLSAME");
	lg_per->Draw();

	cPe->cd(2);
	gPerpCoPF->SetTitle("Corrected MET response");
	gPerpGen->Draw("APL");
	gPerpCoPF->Draw("PLSAME");
	gPerpCoPu->Draw("PLSAME");
	lg_per->Draw();

	cPe->Print(sDir+"/MET_resol_perp_"+sName+"pu200.pdf");

	TGraphErrors *gPerpGen_pu0  = new TGraphErrors(bin, aZMean_pu0,  aGenPerpSol_pu0, 0,  aGenPerpSolEr_pu0);
	TGraphErrors *gPerpPF_pu0   = new TGraphErrors(bin, aZMean_pu0,   aPFPerpSol_pu0, 0,   aPFPerpSolEr_pu0);
	TGraphErrors *gPerpPu_pu0   = new TGraphErrors(bin, aZMean_pu0,   aPuPerpSol_pu0, 0,   aPuPerpSolEr_pu0);
	TGraphErrors *gPerpCoPF_pu0 = new TGraphErrors(bin, aZMean_pu0, aCoPFPerpSol_pu0, 0, aCoPFPerpSolEr_pu0);
	TGraphErrors *gPerpCoPu_pu0 = new TGraphErrors(bin, aZMean_pu0, aCoPuPerpSol_pu0, 0, aCoPuPerpSolEr_pu0);

      gPerpGen_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpPF_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpPu_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpCoPF_pu0->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpCoPu_pu0->GetXaxis()->SetRangeUser(0, maxi+20);

	   gPerpGen_pu0->GetYaxis()->SetRangeUser(0, ymax);
	    gPerpPF_pu0->GetYaxis()->SetRangeUser(0, ymax);
	    gPerpPu_pu0->GetYaxis()->SetRangeUser(0, ymax);
	  gPerpCoPF_pu0->GetYaxis()->SetRangeUser(0, ymax);
	  gPerpCoPu_pu0->GetYaxis()->SetRangeUser(0, ymax);

	  gPerpGen_pu0->SetMarkerStyle(20);
	  gPerpPF_pu0->SetMarkerStyle(20);
	  gPerpPu_pu0->SetMarkerStyle(20);
	  gPerpCoPF_pu0->SetMarkerStyle(20);
	  gPerpCoPu_pu0->SetMarkerStyle(20);
	  
	  gPerpGen_pu0->SetLineColor(kGreen+3);
	  gPerpPF_pu0->SetLineColor(kBlue);
	  gPerpPu_pu0->SetLineColor(kRed);
	  gPerpCoPF_pu0->SetLineColor(kBlue);
	  gPerpCoPu_pu0->SetLineColor(kRed);
	   gPerpGen_pu0->SetLineWidth(2);
	    gPerpPF_pu0->SetLineWidth(2);
	    gPerpPu_pu0->SetLineWidth(2);
	  gPerpCoPF_pu0->SetLineWidth(2);
	  gPerpCoPu_pu0->SetLineWidth(2);

	TCanvas *cPe_pu0 = new TCanvas("cPe_pu0", "", 1000, 500);
	cPe_pu0->Divide(2, 1);

	cPe_pu0->cd(1);
	gPerpPF_pu0->SetTitle("Uncorrected MET response");
	gPerpGen_pu0->GetYaxis()->SetTitle("#sigma(u_{#perp}  )");
	gPerpGen_pu0->GetXaxis()->SetTitle("<q_{T}>");
	gPerpGen_pu0->Draw("APL");
	gPerpPF_pu0->Draw("PLSAME");
	gPerpPu_pu0->Draw("PLSAME");
	lg_per->Draw();

	cPe_pu0->cd(2);
	gPerpCoPF_pu0->SetTitle("Corrected MET response");
	gPerpGen_pu0->Draw("APL");
	gPerpCoPF_pu0->Draw("PLSAME");
	gPerpCoPu_pu0->Draw("PLSAME");
	lg_per->Draw();

	cPe_pu0->Print(sDir+"/MET_resol_perp_"+sName+"pu0.pdf");
/*
	TCanvas *c3 = new TCanvas("c3", "", 1000, 500);
	c3->Divide(2,1);

	c3->cd(1);
	hInv->Draw();

	c3->cd(2);
	hInv_pu0->Draw();
*/
}
