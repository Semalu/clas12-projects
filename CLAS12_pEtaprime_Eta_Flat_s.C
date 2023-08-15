void CLAS12_pEtaprime_Eta_Flat_s(C12Config config) {
	
	config.Print();
	
	auto ebeamP=config._beamP;
	
	//define e- beam, pdg =11 momentum =_beamP
	auto elBeam = initial(11,ebeamP);
	auto elin=elBeam->GetInteracting4Vector();
	//proton target at rest
	auto prTarget= initial(2212,0);
	auto prin=prTarget->GetInteracting4Vector();	

	//produced eta decaying to 2 photons
	auto eta=particle(221,model(new PhaseSpaceDecay{{},{22, 22}}));

	//produced etaprime decaying to eta pi+ pi-
	auto etaprime=particle(331,model(new PhaseSpaceDecay{{eta},{211,-211}}));
		
	//decay of gamma* + p to p + etaprime
	auto pGammaStarDecay = model(new DecayModelst{ {etaprime},{2212} });
	
	
	mesonex( elBeam,prTarget , new DecayModelQ2W{0, pGammaStarDecay });
	
	
	c12process(config);
	
}