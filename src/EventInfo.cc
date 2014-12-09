/**\class EventInfo EventInfo.cc Analysis/Ntuplizer/src/EventInfo.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Roberval Walsh Bastos Rangel
//         Created:  Mon, 20 Oct 2014 14:24:08 GMT
//
//

// system include files
// 
// user include files
#include "FWCore/Framework/interface/Event.h"
// 
#include "FWCore/ParameterSet/interface/ParameterSet.h"
 
#include "Analysis/Ntuplizer/interface/EventInfo.h"

//
// class declaration
//

using namespace mssmhbb;
using namespace mssmhbb::ntuple;

//
// constructors and destructor
//
EventInfo::EventInfo()
{
   // default constructor
}

EventInfo::EventInfo(TTree* tree)
{
   tree_ = tree;
   
}

EventInfo::~EventInfo()
{
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)
}


//
// member functions
//

// ------------ method called for each event  ------------
void EventInfo::fill(const edm::Event& event)
{
   using namespace edm;
   
   const edm::EventAuxiliary evt = event.eventAuxiliary();
   event_ = evt.event();
   run_   = evt.run();
   lumi_  = evt.luminosityBlock();
   orbit_ = evt.orbitNumber();
   bx_    = evt.bunchCrossing();
   
   tree_ -> Fill();
   
}

// ------------ method called once each job just before starting event loop  ------------
void EventInfo::branches()
{
   
   // event output info
   tree_->Branch("event", &event_, "event/I");
   tree_->Branch("run"  , &run_  , "run/I");
   tree_->Branch("lumisection" , &lumi_ , "lumisection/I");
   tree_->Branch("bx"   , &bx_   , "bx/I");
   tree_->Branch("orbit", &orbit_, "orbit/I");
}
