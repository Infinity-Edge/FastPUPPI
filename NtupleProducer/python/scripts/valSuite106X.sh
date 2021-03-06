#!/bin/bash

V="106X_v0"; 
PLOTDIR="plots/106X/from106X/${V/106X_v/v}/val"
SAMPLES="--$V";

W=$1; shift;
case $W in
    run-pgun)
        bash scripts/doRespCorrs106X.sh rerun
        ;;
    plot-pgun)
         for PU in PU0 PU200; do
             NTUPLES=$(ls respTupleNew_{SinglePion_PT0to200,SinglePion_PT2to100,SinglePion0_FlatPt-8to100,PhotonFlatPt8To150,Mu_FlatPt2to100}_${PU}.${V}.root);
             if [[ "$PU" == "PU0" ]]; then
                 python scripts/respPlots.py $NTUPLES $PLOTDIR/ParticleGun_${PU} -w l1pf -p electron,photon,pizero -g  --ymaxRes 0.35 --ptmax 150 -E 3.0
                 python scripts/respPlots.py $NTUPLES $PLOTDIR/ParticleGun_${PU} -w l1pf -p pion,klong,pimix       -g  --ymaxRes 1.2  --ptmax 150 -E 3.0
                 python scripts/respPlots.py $NTUPLES $PLOTDIR/ParticleGun_${PU} -w l1pf -p pion,pizero,pimix      -g  --eta 3.0 5.0  --ymax 3 --ymaxRes 1.5 --label hf  --no-fit 
             else
                 python scripts/respPlots.py $NTUPLES $PLOTDIR/ParticleGun_${PU} -w l1pf -p electron,photon,pizero -g  --ymax 2.5 --ymaxRes 0.6 --ptmax 80 -E 3.0
                 python scripts/respPlots.py $NTUPLES $PLOTDIR/ParticleGun_${PU} -w l1pf -p pion,klong,pimix       -g  --ymax 2.5 --ymaxRes 1.5 --ptmax 80 -E 3.0
                 python scripts/respPlots.py $NTUPLES $PLOTDIR/ParticleGun_${PU} -w l1pf -p pion,pizero,pimix      -g  --ymax 3.0 --ymaxRes 1.5 --ptmax 80 --eta 3.0 5.0 --label hf  --no-fit 
             fi;
         done
         ;;
    run-jets-nopu)
         python runPerformanceNTuple.py || exit 1;
         for X in TTbar_PU0; do
             ./scripts/prun.sh runPerformanceNTuple.py  $SAMPLES $X ${X}.${V}  --inline-customize 'addCHS();addTKs();addCalib()'; 
         done
         ;;
    plot-jets-nopu)
         for X in TTbar_PU0; do
            #python scripts/respPlots.py perfTuple_${X}.${V}.root $PLOTDIR/${X} -w l1pf -p jet -g
            #python scripts/respPlots.py perfTuple_${X}.${V}.root $PLOTDIR/${X} -w l1pf -p jet -g --eta 3.5 4.5 --no-eta --ptmax 100 
            f104v0=plots/106X/from104X/v0/val/${X}
            me=$PLOTDIR/${X}
            PT="pt"; X="jet"; 
            #for W in PF Calo; do for G in "" _gauss; do for R in "" _res; do for E in 00_13 13_17 17_25 25_30 30_50 35_45; do
            for W in PF Calo; do for G in "" _gauss; do for R in "" _res; do for E in 35_45; do
                    plot=${X}_eta_${E}${R}${G}-l1pf_${PT}
                    python scripts/stackPlotsFromFiles.py --legend="TR" $me/${plot}-comp-${W}.png ${W}${G}${R} MTD_MC=$f104v0/$plot.root,Azure+2 L1T_MC=$me/$plot.root,Green+2;
            done; done; done; done;
         done
         ;;
    run-jets)
         python runPerformanceNTuple.py || exit 1;
         for X in {,VBF_HToInvisible,SingleNeutrino}_PU200; do
             ./scripts/prun.sh runPerformanceNTuple.py  $SAMPLES $X ${X}.${V}  --inline-customize 'addCHS();addTKs()';
         done
         ;;
    plot-jets)
         #for X in {TTbar,VBF_HToInvisible}_PU200; do
         X=TTbar_PU200
            #python scripts/respPlots.py perfTuple_${X}.${V}.root -p jet --no-eta -G $PLOTDIR/${X} -w l1pfpu --ymax 2.2 --ymaxRes 0.9 -E 3.0
            f104v0=plots/106X/from104X/v0/val/${X}
            me=$PLOTDIR/${X}
            PT="pt"; X="jet"; 
            for W in Puppi; do for G in _gauss; do for R in "" _res; do for E in 00_13 13_17 17_25 25_30; do  
                    plot=${X}_eta_${E}${R}${G}-l1pfpu_${PT}
                    python scripts/stackPlotsFromFiles.py --legend="TR" $me/${plot}-comp-${W}.png ${W}${G}${R} MTD_MC=$f104v0/$plot.root,Azure+2 L1T_MC=$me/$plot.root,Green+2;
            done; done; done; done;
          X=VBF_HToInvisible_PU200
            #python scripts/respPlots.py perfTuple_${X}.${V}.root -p jet --no-eta -G $PLOTDIR/${X} -w l1pfpu --ymax 2.5 --ymaxRes 0.9 --eta 3.0 5.0 --ptmax 150
            #python scripts/respPlots.py perfTuple_${X}.${V}.root -p jet --no-eta -G $PLOTDIR/${X} -w l1pfpu --ymax 2.5 --ymaxRes 0.9 --eta 3.5 4.5 --ptmax 150
            f104v0=plots/106X/from104X/v0/val/${X}
            me=$PLOTDIR/${X}
            PT="pt"; X="jet"; 
            for W in Puppi; do for G in _gauss; do for R in "" _res; do for E in 35_45 30_50; do  
                    plot=${X}_eta_${E}${R}${G}-l1pfpu_${PT}
                    python scripts/stackPlotsFromFiles.py --legend="TR" $me/${plot}-comp-${W}.png ${W}${G}${R} MTD_MC=$f104v0/$plot.root,Azure+2 L1T_MC=$me/$plot.root,Green+2;
            done; done; done; done;
            #done
         ;;
    run-rates)
         python runPerformanceNTuple.py || exit 1;
         for X in {SingleNeutrino,VBF_HToInvisible}_PU200; do
             ./scripts/prun.sh runPerformanceNTuple.py  $SAMPLES $X ${X}.${V}  --inline-customize 'addCHS();addTKs()';
         done
         ;;
    jecs)
         X=TTbar_PU200; Y=VBF_HToInvisible_PU200;
         python scripts/makeJecs.py perfNano_${X}.${V}.root perfNano_${Y}.${V}.root  -A  -o jecs.${V}.root 
         ;;
    plot-rates)
         X=TTbar_PU200; Y=VBF_HToInvisible_PU200;
         #python scripts/makeJecs.py perfNano_${X}.${V}.root perfNano_${Y}.${V}.root  -A  -o jecs.${V}.root 
         for X in {TTbar,VBF_HToInvisible}_PU200; do 
         #    python scripts/jetHtSuite.py perfNano_${X}.${V}.root perfNano_SingleNeutrino_PU200.${V}.root $PLOTDIR/met/$X -j jecs.${V}.root -w l1pfpu -v met --eta 5.0
            f104v0=plots/106X/from104X/v0/val/met/${X}
            me=$PLOTDIR/met/${X}
            W="Puppi"; 
            for plot in metisorate-l1pfpu_eta5.0_pt30_{1,2,5}0kHz; do
                python scripts/stackPlotsFromFiles.py --legend="TR" $me/${plot}-comp-${W}.png ${W}_eff MTD_MC=$f104v0/$plot.root,Azure+2 L1T_MC=$me/$plot.root,Green+2;
            done
         done
         X=TTbar_PU200; 
         #python scripts/jetHtSuite.py perfNano_${X}.${V}.root perfNano_SingleNeutrino_PU200.${V}.root $PLOTDIR/ht/$X -j jecs.${V}.root -w l1pfpu -v jet1 --eta 2.4
         #python scripts/jetHtSuite.py perfNano_${X}.${V}.root perfNano_SingleNeutrino_PU200.${V}.root $PLOTDIR/ht/$X -j jecs.${V}.root -w l1pfpu -v jet4 --eta 2.4
         #python scripts/jetHtSuite.py perfNano_${X}.${V}.root perfNano_SingleNeutrino_PU200.${V}.root $PLOTDIR/ht/$X -j jecs.${V}.root -w l1pfpu -v ht   --eta 2.4
         #python scripts/jetHtSuite.py perfNano_${X}.${V}.root perfNano_SingleNeutrino_PU200.${V}.root $PLOTDIR/ht/$X -j jecs.${V}.root -w l1pfpu -v ht   --eta 3.5
            f104v0=plots/106X/from104X/v0/val/ht/${X}
            me=$PLOTDIR/ht/${X}
            W="Puppi"; 
            for plot in jet{1,4}isorate-l1pfpu_eta2.4_pt10_20kHz htisorate-l1pfpu_eta{2.4,3.5}_pt30_20kHz; do
                python scripts/stackPlotsFromFiles.py --legend="TR" $me/${plot}-comp-${W}.png ${W}_eff MTD_MC=$f104v0/$plot.root,Azure+2 L1T_MC=$me/$plot.root,Green+2;
            done
         X=VBF_HToInvisible_PU200; 
         #python scripts/jetHtSuite.py perfNano_${X}.${V}.root perfNano_SingleNeutrino_PU200.${V}.root $PLOTDIR/ht/$X -j jecs.${V}.root -w l1pfpu -v jet2       --eta 4.7
         #python scripts/jetHtSuite.py perfNano_${X}.${V}.root perfNano_SingleNeutrino_PU200.${V}.root $PLOTDIR/ht/$X -j jecs.${V}.root -w l1pfpu -v ptj-mjj620 --eta 4.7

         ;;
esac;
