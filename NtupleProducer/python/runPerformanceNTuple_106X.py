import FWCore.ParameterSet.Config as cms
from  PhysicsTools.NanoAOD.common_cff import *
from Configuration.StandardSequences.Eras import eras
from math import sqrt
import files

process = cms.Process("RESP", eras.Phase2C8_trigger)

process.load('Configuration.StandardSequences.Services_cff')
process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True), allowUnscheduled = cms.untracked.bool(False) )
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1))
#process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100))
process.MessageLogger.cerr.FwkReport.reportEvery = 1

ttbar_files = ['file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_1.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_2.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_3.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_4.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_5.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_6.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_7.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_8.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_9.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_10.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_11.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_12.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_13.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_14.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_15.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_16.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_17.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_18.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_19.root',
               'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/TTbar_PU200/inputs104X_20.root']

vbf_files = ['file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job1.root']
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job2.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job3.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job4.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job5.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job6.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job7.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job8.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job9.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job10.root',
#           'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job11.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job12.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job13.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job14.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job15.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job16.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job17.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job18.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job19.root',
#            'file:/eos/cms/store/cmst3/group/l1tr/gpetrucc/106X/NewInputs104X/240719_oldhgc.done/VBF_HToInvisible_PU200/inputs104X_VBF_HToInvisible_PU200_job20.root']

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(vbf_files
                            ),
                            #fileNames = cms.untracked.vstring(files.DY_files
                            #),
                            #fileNames = cms.untracked.vstring('file:./inputs106X_DY_M50.root'
                            #),
    duplicateCheckMode = cms.untracked.string("noDuplicateCheck"),
    skipBadFiles = cms.untracked.bool(True),
    inputCommands = cms.untracked.vstring("keep *", 
            "drop l1tPFClusters_*_*_*",
            "drop l1tPFTracks_*_*_*",
            "drop l1tPFCandidates_*_*_*")
)

process.load('Configuration.Geometry.GeometryExtended2023D41Reco_cff')
process.load('Configuration.Geometry.GeometryExtended2023D41_cff')
process.load('Configuration.StandardSequences.MagneticField_cff')
process.load('SimCalorimetry.HcalTrigPrimProducers.hcaltpdigi_cff') # needed to read HCal TPs
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load('RecoMET.Configuration.GenMETParticles_cff')
process.load('RecoMET.METProducers.genMetTrue_cfi')

from RecoJets.JetProducers.ak4PFJets_cfi import ak4PFJets
from RecoMET.METProducers.PFMET_cfi import pfMet

from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '103X_upgrade2023_realistic_v2', '') 

process.load("L1Trigger.Phase2L1ParticleFlow.l1ParticleFlow_cff")
process.load("L1Trigger.Phase2L1ParticleFlow.l1ParticleFlow_old_cff")

process.extraPFStuff = cms.Task()

process.runPF = cms.Sequence( 
    process.l1ParticleFlow 
)

process.centralGen = cms.EDFilter("CandPtrSelector", src = cms.InputTag("genParticlesForMETAllVisible"), cut = cms.string("abs(eta) < 2.4"))
process.barrelGen = cms.EDFilter("CandPtrSelector", src = cms.InputTag("genParticlesForMETAllVisible"), cut = cms.string("abs(eta) < 1.5"))
process.genMetCentralTrue = process.genMetTrue.clone(src = cms.InputTag("centralGen"))
process.genMetBarrelTrue = process.genMetTrue.clone(src = cms.InputTag("barrelGen"))
process.extraPFStuff.add(
    process.genParticlesForMETAllVisible,
    process.centralGen,
    process.barrelGen,
    process.genMetCentralTrue,
    process.genMetBarrelTrue
)

def monitorPerf(label, tag, makeResp=True, makeRespSplit=True, makeJets=True, makeMET=True, makeCentralMET=True, makeBarrelMET=True,
                makeInputMultiplicities=False, makeOutputMultiplicities=False):
    def _add(name, what):
        setattr(process, name, what)
        process.extraPFStuff.add(what)
    if type(tag) != str and len(tag) > 1:
        _add('merged'+label, cms.EDProducer("L1TPFCandMerger", src = cms.VInputTag(cms.InputTag(x) for x in tag)))
        tag = 'merged'+label
    if makeResp:
        setattr(process.ntuple.objects, label, cms.VInputTag(cms.InputTag(tag)))
        if makeRespSplit:
            setattr(process.ntuple.objects, label+"Charged", cms.VInputTag(cms.InputTag(tag)))
            setattr(process.ntuple.objects, label+"Charged_sel", cms.string("charge != 0"))
            setattr(process.ntuple.objects, label+"Photon",  cms.VInputTag(cms.InputTag(tag)))
            setattr(process.ntuple.objects, label+"Photon_sel", cms.string("pdgId == 22"))
            setattr(process.ntuple.objects, label+"Neutral",  cms.VInputTag(cms.InputTag(tag)))
            setattr(process.ntuple.objects, label+"Neutral_sel", cms.string("charge == 0"))
            setattr(process.ntuple.objects, label+"NeutralHad",  cms.VInputTag(cms.InputTag(tag)))
            setattr(process.ntuple.objects, label+"NeutralHad_sel", cms.string("charge == 0 && pdgId != 22"))
    if makeJets:
        _add('ak4'+label, ak4PFJets.clone(src = tag, doAreaFastjet = False))
        setattr(process.l1pfjetTable.jets, label, cms.InputTag('ak4'+label))
    if makeMET:
        _add('met'+label, pfMet.clone(src = tag, calculateSignificance = False))
        setattr(process.l1pfmetTable.mets, label, cms.InputTag('met'+label))
        if makeCentralMET:
            _add('central'+label, cms.EDFilter("CandPtrSelector", src = cms.InputTag(tag), cut = cms.string("abs(eta) < 2.4")))
            _add('met'+label+'Central', pfMet.clone(src = 'central'+label, calculateSignificance = False))
            setattr(process.l1pfmetCentralTable.mets, label, cms.InputTag('met'+label+'Central'))
        if makeBarrelMET:
            _add('barrel'+label, cms.EDFilter("CandPtrSelector", src = cms.InputTag(tag), cut = cms.string("abs(eta) < 1.5")))
            _add('met'+label+'Barrel', pfMet.clone(src = 'barrel'+label, calculateSignificance = False))
            setattr(process.l1pfmetBarrelTable.mets, label, cms.InputTag('met'+label+'Barrel'))
    if makeInputMultiplicities:
        D = tag.split(":")[0] # l1pfProducer[Barrel,HGCal,HF] usually
        I = tag.split(":")[1] # Calo, EmCalo, TK, or Mu, usually
        for X in ["tot","max"]:
            process.ntuple.copyUInts.append( "%s:%sNL1%s" % (D,X,I))
        process.ntuple.copyVecUInts.append( "%s:vecNL1%s" % (D,I))
    if makeOutputMultiplicities:
        D = tag.split(":")[0] # l1pfProducer[Barrel,HGCal,HF] usually
        P = tag.split(":")[1] # PF or Puppi, usually
        for O in [""] + "Charged Neutral ChargedHadron NeutralHadron Photon Electron Muon".split():
            for X in ["tot","max"]:
                process.ntuple.copyUInts.append( "%s:%sNL1%s%s" % (D,X,P,O))
            process.ntuple.copyVecUInts.append( "%s:vecNL1%s%s" % (D,P,O))

process.ntuple = cms.EDAnalyzer("ResponseNTuplizer",
    genJets = cms.InputTag("ak4GenJetsNoNu"),
    genParticles = cms.InputTag("genParticles"),
    isParticleGun = cms.bool(False),
    doRandom = cms.bool(False),
    objects = cms.PSet(
        # -- inputs and PF --
        RawTK  = cms.VInputTag('pfTracksFromL1Tracks',),
        # outputs
    ),
    copyUInts = cms.VInputTag(),
    copyFloats = cms.VInputTag(),
    copyVecUInts = cms.VInputTag(),
)

process.extraPFStuff.add(process.pfTracksFromL1Tracks)


process.l1pfjetTable = cms.EDProducer("L1PFJetTableProducer",
    gen = cms.InputTag("ak4GenJetsNoNu"),
    commonSel = cms.string("pt > 5 && abs(eta) < 5.0"),
    drMax = cms.double(0.2),
    minRecoPtOverGenPt = cms.double(0.1),
    jets = cms.PSet(
        Gen = cms.InputTag("ak4GenJetsNoNu"),
        Gen_sel = cms.string("pt > 15"),
    ),
    moreVariables = cms.PSet(
    ),
)

process.l1pfmetTable = cms.EDProducer("L1PFMetTableProducer",
    genMet = cms.InputTag("genMetTrue"), 
    flavour = cms.string(""),
    mets = cms.PSet(
    ),
)

# Add all PFCandi info
process.pfCandiTable = cms.EDProducer("SimpleCandidateFlatTableProducer",
        src = cms.InputTag("l1pfCandidates:PF"),
        cut = cms.string("pt > 3 && abs(eta) < 2.4"),
        name= cms.string("PFCandidate"),
        doc = cms.string("reco Candidate"),
        singleton = cms.bool(False), # the number of entries is variable
        extension = cms.bool(False), # this is the main table
        variables = cms.PSet(
            pt  = Var("pt",  float,precision=8),
            phi = Var("phi", float,precision=8),
            eta = Var("eta", float,precision=8),
            mass = Var("mass", float,precision=8),
            vz  = Var("vz",  float,precision=8),
            pdgId  = Var("pdgId", int, doc="pdg id"),
            charge  = Var("charge", int, doc="charge id"),
            )
        )
process.extraPFStuff.add(process.pfCandiTable)

# Add all PuppiCandi info
process.puppiCandiTable = cms.EDProducer("SimpleCandidateFlatTableProducer",
        src = cms.InputTag("l1pfCandidates:Puppi"),
        cut = cms.string("pt > 3 && abs(eta) < 2.4"),
        name= cms.string("PuppiCandidate"),
        doc = cms.string("reco Candidate"),
        singleton = cms.bool(False), # the number of entries is variable
        extension = cms.bool(False), # this is the main table
        variables = cms.PSet(
            pt  = Var("pt",  float,precision=8),
            phi = Var("phi", float,precision=8),
            eta = Var("eta", float,precision=8),
            mass = Var("mass", float,precision=8),
            vz  = Var("vz",  float,precision=8),
            pdgId  = Var("pdgId", int, doc="pdg id"),
            charge  = Var("charge", int, doc="charge id"),
            )
        )
process.extraPFStuff.add(process.puppiCandiTable)

# Add Muon info
process.pfMuTable = cms.EDProducer("SimpleCandidateFlatTableProducer",
        src = cms.InputTag("l1pfCandidates:PF"),
        cut = cms.string("abs(pdgId) == 13 && pt > 3 && abs(eta) < 2.4"),
        name= cms.string("PFMu"),
        doc = cms.string("reco leptons"),
        singleton = cms.bool(False), # the number of entries is variable
        extension = cms.bool(False), # this is the main table
        variables = cms.PSet(
            pt  = Var("pt",  float,precision=8),
            phi = Var("phi", float,precision=8),
            eta = Var("eta", float,precision=8),
            mass = Var("mass", float,precision=8),
            vz  = Var("vz",  float,precision=8),
            charge  = Var("charge", int, doc="charge id"),
            quality = Var("? muon.isNonnull ? muon.hwQual : -1", int, doc="Quality"),
            )
        )
process.extraPFStuff.add(process.pfMuTable)
'''
# Add Vertex
process.pfVertexTable = cms.EDProducer("SimpleCandidateFlatTableProducer",
        src = cms.InputTag("VertexProducer:l1vertices"),
        name= cms.string("nVertex"),
        doc = cms.string("reco vertices"),
        singleton = cms.bool(False), # the number of entries is variable
        extension = cms.bool(False), # this is the main table
        )
process.extraPFStuff.add(process.pfVertexTable)

# Add Gen Particle info
process.genMuTable = cms.EDProducer("SimpleCandidateFlatTableProducer",
        src = cms.InputTag("genParticles"),
        cut = cms.string("abs(pdgId) == 13 && pt > 3 && abs(eta) < 2.4"),
        name= cms.string("GenMu"),
        doc = cms.string("gen leptons"),
        singleton = cms.bool(False), # the number of entries is variable
        extension = cms.bool(False), # this is the main table
        variables = cms.PSet(
            pt  = Var("pt",  float,precision=8),
            phi = Var("phi", float,precision=8),
            eta = Var("eta", float,precision=8),
            mass = Var("mass", float,precision=8),
            vz  = Var("vz",  float,precision=8),
            charge  = Var("charge", int, doc="charge id"),
            quality = Var("? muon.isNonnull ? muon.hwQual : -1", int, doc="Quality"),
            )
        )
process.extraPFStuff.add(process.genMuTable)
'''
process.l1pfmetCentralTable = process.l1pfmetTable.clone(genMet = "genMetCentralTrue", flavour = "Central")
process.l1pfmetBarrelTable  = process.l1pfmetTable.clone(genMet = "genMetBarrelTrue", flavour = "Barrel")

monitorPerf("L1Calo", "l1pfCandidates:Calo", makeRespSplit = False)
monitorPerf("L1TK", "l1pfCandidates:TK", makeRespSplit = False, makeJets=False, makeMET=False)
monitorPerf("L1TKV", "l1pfCandidates:TKVtx", makeRespSplit = False, makeJets=False, makeMET=False)
monitorPerf("L1PF", "l1pfCandidates:PF")
monitorPerf("L1Puppi", "l1pfCandidates:Puppi")

for D in ['Barrel','HF','HGCal','HGCalNoTK']:
    monitorPerf("L1%sCalo"%D,"l1pfProducer%s:Calo"%D, makeResp=False, makeRespSplit=False, makeJets=False, makeMET=False, 
               makeCentralMET=False, makeBarrelMET=False, makeInputMultiplicities=True)
    monitorPerf("L1%sEmCalo"%D,"l1pfProducer%s:EmCalo"%D, makeResp=False, makeRespSplit=False, makeJets=False, makeMET=False, 
               makeCentralMET=False, makeBarrelMET=False, makeInputMultiplicities=True)
    monitorPerf("L1%sTK"%D,"l1pfProducer%s:TK"%D, makeResp=False, makeRespSplit=False, makeJets=False, makeMET=False, 
               makeCentralMET=False, makeBarrelMET=False, makeInputMultiplicities=True)
    monitorPerf("L1%sMu"%D,"l1pfProducer%s:Mu"%D, makeResp=False, makeRespSplit=False, makeJets=False, makeMET=False, 
               makeCentralMET=False, makeBarrelMET=False, makeInputMultiplicities=True)

    monitorPerf("L1%sPF"%D,"l1pfProducer%s:PF"%D, makeResp=False, makeRespSplit=False, makeJets=False, makeMET=False, 
               makeCentralMET=False, makeBarrelMET=False, makeOutputMultiplicities=True)
    monitorPerf("L1%sPuppi"%D,"l1pfProducer%s:Puppi"%D, makeResp=False, makeRespSplit=False, makeJets=False, makeMET=False, 
               makeCentralMET=False, makeBarrelMET=False, makeOutputMultiplicities=True)

# define regions
def goRegional():
    process.l1pfProducerBarrel.regions = cms.VPSet(
        cms.PSet(
            etaBoundaries = cms.vdouble(-1.5, -0.5, 0.5, 1.5),
            etaExtra = cms.double(0.25),
            phiExtra = cms.double(0.25),
            phiSlices = cms.uint32(9)
        )
    )
    process.l1pfProducerHGCalNoTK.regions = cms.VPSet(
        cms.PSet(
            etaBoundaries = cms.vdouble(-3, -2.5),
            etaExtra = cms.double(0.25),
            phiExtra = cms.double(0.25),
            phiSlices = cms.uint32(9)
        ),
        cms.PSet(
            etaBoundaries = cms.vdouble(2.5, 3),
            etaExtra = cms.double(0.25),
            phiExtra = cms.double(0.25),
            phiSlices = cms.uint32(9)
        )
    )
    process.l1pfProducerHGCal.regions = cms.VPSet(
        cms.PSet(
            etaBoundaries = cms.vdouble(-2.5, -1.5),
            etaExtra = cms.double(0.25),
            phiExtra = cms.double(0.25),
            phiSlices = cms.uint32(9)
        ),
        cms.PSet(
            etaBoundaries = cms.vdouble(1.5, 2.5),
            etaExtra = cms.double(0.25),
            phiExtra = cms.double(0.25),
            phiSlices = cms.uint32(9)
        )
    )
    process.l1pfProducerHF.regions = cms.VPSet(
        cms.PSet(
            # 72 regions in HF:
            #etaBoundaries = cms.vdouble(-5, -4.5, -4, -3.5, -3),
            # 36 regions in HF:
            etaBoundaries = cms.vdouble(-5, -4, -3),
            etaExtra = cms.double(0.25),
            phiExtra = cms.double(0.25),
            phiSlices = cms.uint32(9)
        ),
        cms.PSet(
            # 72 regions in HF:
            #etaBoundaries = cms.vdouble(3, 3.5, 4, 4.5, 5),
            # 36 regions in HF:
            etaBoundaries = cms.vdouble(3, 4, 5),
            etaExtra = cms.double(0.25),
            phiExtra = cms.double(0.25),
            phiSlices = cms.uint32(9)
        )
    )

goRegional()

# turn on Manos HGC MVA ID
process.pfClustersFromHGC3DClusters.emVsPionID.method = cms.string("BDT")
process.pfClustersFromHGC3DClusters.emVsPUID.method = cms.string("BDT")
# add 17 GeV HF hadPtCut from Daekwon
process.l1pfProducerHF.hadPtCut = 15.0

process.runPF.associate(process.extraPFStuff)
# to check available tags:
#process.content = cms.EDAnalyzer("EventContentAnalyzer")
process.p = cms.Path(
        process.runPF + 
        process.ntuple + #process.content +
        process.l1pfjetTable + 
        process.l1pfmetTable + process.l1pfmetCentralTable + process.l1pfmetBarrelTable
        )
#process.TFileService = cms.Service("TFileService", fileName = cms.string("perfTuple_36regions_15thr_DY.root"))
process.TFileService = cms.Service("TFileService", fileName = cms.string("perfTuple_test.root"))

# for full debug:
#process.out = cms.OutputModule("PoolOutputModule",
#                               fileName = cms.untracked.string("debugPF.root"),
#                               SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring("p"))
#                           )
#process.end = cms.EndPath(process.out)

process.outnano = cms.OutputModule("NanoAODOutputModule",
    #fileName = cms.untracked.string("perfNano_36regions_15thr_DY.root"),
    fileName = cms.untracked.string("perfNano_test_puppiCandi.root"),
    SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring('p')),
    outputCommands = cms.untracked.vstring("drop *", "keep nanoaodFlatTable_*Table_*_*"),
    compressionLevel = cms.untracked.int32(4),
    compressionAlgorithm = cms.untracked.string("ZLIB"),
)
process.end = cms.EndPath(process.outnano)

# Below for more debugging
if True:
    process.genInAcceptance = cms.EDFilter("GenParticleSelector",
        src = cms.InputTag("genParticles"),
        cut = cms.string("status == 1 && (abs(pdgId) != 12 && abs(pdgId) != 14 && abs(pdgId) != 16) && "+
                         "(abs(eta) < 2.5 && pt > 2 && charge != 0 || "+
                         "abs(pdgId) == 22 && pt > 1 || "+
                         "charge == 0 && pt > 1 || "+
                         "charge != 0 && abs(eta) > 2.5 && pt > 2) ") # tracks below pT 2 bend by more than 0.4,
    )
    process.ntuple.objects.GenAcc = cms.VInputTag(cms.InputTag("genInAcceptance"))
    process.ntuple.objects.ChGenAcc = cms.VInputTag(cms.InputTag("genInAcceptance"))
    process.ntuple.objects.ChGenAcc_sel = cms.string("(abs(eta) < 2.5 && pt > 2 && charge != 0)")
    process.ntuple.objects.PhGenAcc = cms.VInputTag(cms.InputTag("genInAcceptance"))
    process.ntuple.objects.PhGenAcc_sel = cms.string("pdgId == 22")
    process.ntuple.objects.MuGenAcc = cms.VInputTag(cms.InputTag("genInAcceptance"))
    process.ntuple.objects.MuGenAcc_sel = cms.string("abs(pdgId) == 13")
    process.extraPFStuff.add(process.genInAcceptance)
if False: # test also PF leptons
    process.ntuple.objects.L1PFMuon = cms.VInputTag("l1pfCandidates:PF",)
    process.ntuple.objects.L1PFMuon_sel = cms.string("abs(pdgId) == 13")
    process.ntuple.objects.L1PFElectron = cms.VInputTag("l1pfCandidates:PF",)
    process.ntuple.objects.L1PFElectron_sel = cms.string("abs(pdgId) == 11")
def respOnly():
    process.p.remove(process.l1pfjetTable)
    process.p.remove(process.l1pfmetTable)
    process.p.remove(process.l1pfmetCentralTable)
    process.p.remove(process.l1pfmetBarrelTable)
    process.end.remove(process.outnano)
def addCHS():
    process.l1PuppiCharged = cms.EDFilter("L1TPFCandSelector",
        src = cms.InputTag("l1pfCandidates:Puppi"),
        cut = cms.string("charge != 0"))
    process.l1PFNeutral = cms.EDFilter("L1TPFCandSelector",
        src = cms.InputTag("l1pfCandidates:PF"),
        cut = cms.string("charge == 0"))
    process.extraPFStuff.add(process.l1PuppiCharged, process.l1PFNeutral)
    monitorPerf("L1CHS", [ "l1PuppiCharged", "l1PFNeutral" ], makeRespSplit = False)
def addOld():
    process.extraPFStuff.add(
        process.pfClustersFromHGC3DClustersEM, 
        process.pfClustersFromCombinedCalo, 
        process.l1pfProducerOld,
        process.l1OldPuppiForMET
    )
    monitorPerf("L1OldCalo", "l1pfProducerOld:Calo", makeRespSplit = False)
    monitorPerf("L1OldPF", "l1pfProducerOld:PF")
    monitorPerf("L1OldPuppi", "l1pfProducerOld:Puppi")
    monitorPerf("L1OldPuppiForMET", "l1OldPuppiForMET")
def addPFnoMu():
    process.l1pfProducerBarrelPFnoMu = process.l1pfProducerBarrel.clone()
    process.l1pfProducerBarrelPFnoMu.useStandaloneMuons       = cms.bool(False) 
    process.l1pfProducerBarrelPFnoMu.useTrackerMuons          = cms.bool(False)
    #
    process.l1pfProducerHGCalPFnoMu = process.l1pfProducerHGCal.clone()
    process.l1pfProducerHGCalPFnoMu.useStandaloneMuons       = cms.bool(False) 
    process.l1pfProducerHGCalPFnoMu.useTrackerMuons          = cms.bool(False)
    #
    process.l1pfProducerHFPFnoMu = process.l1pfProducerHF.clone()
    process.l1pfProducerHFPFnoMu.useStandaloneMuons       = cms.bool(False) 
    process.l1pfProducerHFPFnoMu.useTrackerMuons          = cms.bool(False)
    #
    process.l1pfCandidatesPFnoMu = process.l1pfCandidates.clone(
            pfProducers = ["l1pfProducerBarrelPFnoMu", "l1pfProducerHGCalPFnoMu", "l1pfProducerHFPFnoMu"], 
            labelsToMerge = [ "Puppi", "PF" ])
    process.extraPFStuff.add(process.l1pfProducerBarrelPFnoMu, process.l1pfProducerHGCalPFnoMu, process.l1pfProducerHFPFnoMu, process.l1pfCandidatesPFnoMu)
    monitorPerf("L1PuppinoMu", "l1pfCandidatesPFnoMu:Puppi")
    monitorPerf("L1PFnoMu", "l1pfCandidatesPFnoMu:PF")
def addPFtkMu():
    process.l1pfProducerBarrelPFtkMu = process.l1pfProducerBarrel.clone()
    process.l1pfProducerBarrelPFtkMu.useStandaloneMuons       = cms.bool(False) 
    process.l1pfProducerBarrelPFtkMu.useTrackerMuons          = cms.bool(True)
    #
    process.l1pfProducerHGCalPFtkMu = process.l1pfProducerHGCal.clone()
    process.l1pfProducerHGCalPFtkMu.useStandaloneMuons       = cms.bool(False) 
    process.l1pfProducerHGCalPFtkMu.useTrackerMuons          = cms.bool(True)
    #
    process.l1pfProducerHFPFtkMu = process.l1pfProducerHF.clone()
    process.l1pfProducerHFPFtkMu.useStandaloneMuons       = cms.bool(False) 
    process.l1pfProducerHFPFtkMu.useTrackerMuons          = cms.bool(True)
    #
    process.l1pfCandidatesPFtkMu = process.l1pfCandidates.clone(
            pfProducers = ["l1pfProducerBarrelPFtkMu", "l1pfProducerHGCalPFtkMu", "l1pfProducerHFPFtkMu"], 
            labelsToMerge = [ "Puppi", "PF" ])
    process.extraPFStuff.add(process.l1pfProducerBarrelPFtkMu, process.l1pfProducerHGCalPFtkMu, process.l1pfProducerHFPFtkMu, process.l1pfCandidatesPFtkMu)
    monitorPerf("L1PuppitkMu", "l1pfCandidatesPFtkMu:Puppi")
    monitorPerf("L1PFtkMu", "l1pfCandidatesPFtkMu:PF")
def addPuppiOld():
    process.l1pfProducerBarrelPuppiOld = process.l1pfProducerBarrel.clone(puAlgo = "Puppi")
    process.l1pfProducerBarrelPuppiOld.puppiEtaCuts       = cms.vdouble(1.5) 
    process.l1pfProducerBarrelPuppiOld.puppiPtCuts        = cms.vdouble(0.0)
    process.l1pfProducerBarrelPuppiOld.puppiPtCutsPhotons = cms.vdouble(0.0)
    #
    process.l1pfProducerHGCalPuppiOld = process.l1pfProducerHGCal.clone(puAlgo = "Puppi")
    process.l1pfProducerHGCalPuppiOld.puppiEtaCuts       = cms.vdouble(2.5, 2.85,  3.0) 
    process.l1pfProducerHGCalPuppiOld.puppiPtCuts        = cms.vdouble( 20,  40,  9999)
    process.l1pfProducerHGCalPuppiOld.puppiPtCutsPhotons = cms.vdouble( 20,  40,  9999)
    #
    process.l1pfProducerHFPuppiOld = process.l1pfProducerHF.clone(puAlgo = "Puppi")
    process.l1pfProducerHFPuppiOld.puppiEtaCuts       = cms.vdouble(5.5) 
    process.l1pfProducerHFPuppiOld.puppiPtCuts        = cms.vdouble( 30)
    process.l1pfProducerHFPuppiOld.puppiPtCutsPhotons = cms.vdouble( 30)
    #
    process.l1pfCandidatesPuppiOld = process.l1pfCandidates.clone(
            pfProducers = ["l1pfProducerBarrelPuppiOld", "l1pfProducerHGCalPuppiOld", "l1pfProducerHFPuppiOld"], 
            labelsToMerge = [ "Puppi" ])
    process.extraPFStuff.add(process.l1pfProducerBarrelPuppiOld, process.l1pfProducerHGCalPuppiOld, process.l1pfProducerHFPuppiOld, process.l1pfCandidatesPuppiOld)
    monitorPerf("L1PuppiOld", "l1pfCandidatesPuppiOld:Puppi")
def addTKs():
    process.l1tkv5Stubs = cms.EDFilter("L1TPFCandSelector", src = cms.InputTag("l1pfCandidates:TKVtx"), cut = cms.string("pfTrack.nStubs >= 5"))
    process.l1tkv6Stubs = cms.EDFilter("L1TPFCandSelector", src = cms.InputTag("l1pfCandidates:TKVtx"), cut = cms.string("pfTrack.nStubs >= 6"))
    process.extraPFStuff.add(process.l1tkv5Stubs, process.l1tkv6Stubs)
    monitorPerf("L1TKV5", "l1tkv5Stubs", makeRespSplit = False)
    monitorPerf("L1TKV6", "l1tkv6Stubs", makeRespSplit = False)
    monitorPerf("L1TK", "l1pfCandidates:TK", makeRespSplit = False)
    monitorPerf("L1TKV", "l1pfCandidates:TKVtx", makeRespSplit = False)
def addCalib():
    process.pfClustersFromL1EGClustersRaw    = process.pfClustersFromL1EGClusters.clone(corrector = "")
    process.pfClustersFromHGC3DClustersRaw   = process.pfClustersFromHGC3DClusters.clone(corrector = "")
    process.pfClustersFromHGC3DClustersEMRaw = process.pfClustersFromHGC3DClustersRaw.clone(emOnly = True, etMin = 0.)
    process.extraPFStuff.add(
            process.pfClustersFromL1EGClustersRaw, 
            process.pfClustersFromHGC3DClustersRaw, 
            process.pfClustersFromHGC3DClustersEMRaw)
    process.ntuple.objects.L1RawBarrelEcal   = cms.VInputTag('pfClustersFromL1EGClustersRaw' )
    process.ntuple.objects.L1RawBarrelCalo   = cms.VInputTag('pfClustersFromCombinedCaloHCal:uncalibrated')
    process.ntuple.objects.L1RawBarrelCaloEM = cms.VInputTag('pfClustersFromCombinedCaloHCal:emUncalibrated')
    process.ntuple.objects.L1RawHGCal   = cms.VInputTag('pfClustersFromHGC3DClustersRaw')
    process.ntuple.objects.L1RawHGCalEM = cms.VInputTag('pfClustersFromHGC3DClustersEMRaw')
    process.ntuple.objects.L1RawHFCalo  = cms.VInputTag('pfClustersFromCombinedCaloHF:uncalibrated')
    process.ntuple.objects.L1BarrelEcal = cms.VInputTag('pfClustersFromL1EGClusters' )
    process.ntuple.objects.L1BarrelCalo = cms.VInputTag('pfClustersFromCombinedCaloHCal:calibrated')
    process.ntuple.objects.L1HGCal   = cms.VInputTag('pfClustersFromHGC3DClusters')
    process.ntuple.objects.L1HFCalo  = cms.VInputTag('pfClustersFromCombinedCaloHF:calibrated')
    if hasattr(process.ntuple.objects, 'L1OldPF'):
        process.ntuple.objects.L1HGCalEM = cms.VInputTag('pfClustersFromHGC3DClustersEM', )
        process.ntuple.objects.L1OldRawCalo = cms.VInputTag('pfClustersFromCombinedCalo:uncalibrated')
        process.ntuple.objects.L1OldRawCaloEM = cms.VInputTag('pfClustersFromCombinedCalo:emUncalibrated')
        process.ntuple.objects.L1OldRawEcal = cms.VInputTag('pfClustersFromL1EGClustersRaw', 'pfClustersFromHGC3DClustersEMRaw')
        process.ntuple.objects.L1OldEcal = cms.VInputTag(cms.InputTag('l1pfProducerOld','EmCalo'))

def goGun(calib=1):
    process.ntuple.isParticleGun = True
    respOnly()
    if calib: 
        addCalib()
def goMT(nthreads=2):
    process.options.numberOfThreads = cms.untracked.uint32(nthreads)
    process.options.numberOfStreams = cms.untracked.uint32(0)
