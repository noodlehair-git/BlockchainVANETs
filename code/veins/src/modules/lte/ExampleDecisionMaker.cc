#include "ExampleDecisionMaker.h"

Define_Module(ExampleDecisionMaker);

ExampleDecisionMaker::ExampleDecisionMaker(){
	// Empty
}

ExampleDecisionMaker::~ExampleDecisionMaker(){
	// Empty
}

void ExampleDecisionMaker::sendLteMessage(HeterogeneousMessage* msg) {
	// MobilityBase* eNodeBMobility = dynamic_cast<MobilityBase*>(getModuleByPath("scenario.eNodeB1")->getSubmodule("mobility"));
	// ASSERT(eNodeBMobility);
	// AnnotationManager* annotations = AnnotationManagerAccess().getIfExists();
	// annotations->scheduleErase(1, annotations->drawLine(eNodeBMobility->getCurrentPosition(), getPosition(), "yellow"));
	send(msg, toLte);
}

void ExampleDecisionMaker::sendDSRCMessage(HeterogeneousMessage* msg) {
	msg->addBitLength(headerLength);
	msg->setChannelNumber(Channels::CCH);
	msg->setPsid(0);
	msg->setWsmVersion(2);
	msg->setTimestamp(simTime());
//	msg->setRecipientAddress(BROADCAST);
	msg->setSenderPos(currentPosition);
	msg->setSerial(2);
	sendWSM(msg);
}

void ExampleDecisionMaker::sendDontCareMessage(HeterogeneousMessage* msg) {
	if (dblrand() > 0.5) {
		msg->setNetworkType(LTE);
		sendLteMessage(msg);
	} else {
		msg->setNetworkType(DSRC);
		sendDSRCMessage(msg);
	}
}
