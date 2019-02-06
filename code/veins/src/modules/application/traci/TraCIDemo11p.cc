//
// Copyright (C) 2006-2011 Christoph Sommer <christoph.sommer@uibk.ac.at>
//
// Documentation for these modules is at http://veins.car2x.org/
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#include "application/traci/TraCIDemo11p.h"
#include "omnetpp.h"
#include "bca.h"
using Veins::TraCIMobilityAccess;
using Veins::AnnotationManagerAccess;

const simsignalwrap_t TraCIDemo11p::parkingStateChangedSignal = simsignalwrap_t(TRACI_SIGNAL_PARKING_CHANGE_NAME);

Define_Module(TraCIDemo11p);

void TraCIDemo11p::initialize(int stage) {
	BaseWaveApplLayer::initialize(stage);
	if (stage == 0) {
		traci = TraCIMobilityAccess().get(getParentModule());
		annotations = AnnotationManagerAccess().getIfExists();
		ASSERT(annotations);

		sentMessage = false;
		lastDroveAt = simTime();
		findHost()->subscribe(parkingStateChangedSignal, this);
		isParking = false;
		sendWhileParking = par("sendWhileParking").boolValue();
	}
}

void TraCIDemo11p::onBeacon(WaveShortMessage* wsm) {
}

void TraCIDemo11p::onData(WaveShortMessage* wsm) {
	findHost()->getDisplayString().updateWith("r=16,green");
	annotations->scheduleErase(1, annotations->drawLine(wsm->getSenderPos(), traci->getPositionAt(simTime()), "blue"));

	if (traci->getRoadId()[0] != ':') traci->commandChangeRoute(wsm->getWsmData(), 9999);
	if (!sentMessage) sendMessage(wsm->getWsmData());
}

void TraCIDemo11p::sendMessage(std::string blockedRoadId) {
	sentMessage = true;

	t_channel channel = dataOnSch ? type_SCH : type_CCH;
	WaveShortMessage* wsm = prepareWSM("data", dataLengthBits, channel, dataPriority, -1,2);
	wsm->setWsmData(blockedRoadId.c_str());
	sendWSM(wsm);
}


void TraCIDemo11p::sendAttckMessage(std::string blockedRoadId)
{
    sentMessage = true;

        t_channel channel = dataOnSch ? type_SCH : type_CCH;
        WaveShortMessage* wsm = prepareWSM("drop the packet", dataLengthBits, channel, dataPriority, -1,2);
        wsm->setWsmData(blockedRoadId.c_str());
        sendWSM(wsm);
}


void TraCIDemo11p::receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj) {
	Enter_Method_Silent();
	if (signalID == mobilityStateChangedSignal) {
		handlePositionUpdate(obj);
	}
	else if (signalID == parkingStateChangedSignal) {
		handleParkingUpdate(obj);
	}
}
void TraCIDemo11p::handleParkingUpdate(cObject* obj) {
	isParking = traci->getParkingState();
	if (sendWhileParking == false) {
		if (isParking == true) {
			(FindModule<BaseConnectionManager*>::findGlobalModule())->unregisterNic(this->getParentModule()->getSubmodule("nic"));
		}
		else {
			Coord pos = traci->getCurrentPosition();
			(FindModule<BaseConnectionManager*>::findGlobalModule())->registerNic(this->getParentModule()->getSubmodule("nic"), (ChannelAccess*) this->getParentModule()->getSubmodule("nic")->getSubmodule("phy80211p"), &pos);
		}
	}
}
void TraCIDemo11p::handlePositionUpdate(cObject* obj) {
	BaseWaveApplLayer::handlePositionUpdate(obj);
	int st = par("st");
	// stopped for for at least 10s?
	//ev<<"vehicles are uploading (uplink) and downloading (downlink) :"<< traci->getId() <<"\n";




	 if(st==0)
	{



	     ev<<"vehicle NAME:"<< findHost()->getName()<<"\n";
	     int idx=findHost()->getIndex();
	       if((idx%2)==0){
	     ev<<"vehicle Address:"<< findHost()->getName()<<"  no:"<<findHost()->getIndex()+1<<"Anna Nagar,Chennai,TamilNadu,India";
	     ev<<"\n Electronic License Plate (ELP):TN01:12"<<findHost()->getIndex()<<"\n";
	       }else if((idx%3)==0)
	       {
	           ev<<"vehicle Address:"<< findHost()->getName()<<"  no:"<<findHost()->getIndex()+2<<"k k Nagar,Chennai,TamilNadu,India";
	           ev<<"\n Electronic License Plate (ELP):TN02:52"<<findHost()->getIndex()+6<<"\n";
	       }else
	       {
	           ev<<"vehicle Address:"<< findHost()->getName()<<"  no:"<<findHost()->getIndex()+2<<"omr,Chennai,TamilNadu,India";
	           ev<<"\n Electronic License Plate (ELP):TN01:2"<<findHost()->getIndex()+5<<"\n";
	       }
	    if (traci->getSpeed() > 1) {
	            if (simTime() - lastDroveAt >= 20 && simTime() - lastDroveAt <= 40) {
	               findHost()->getDisplayString().updateWith("r=25,green;t=Mutual_Authentication;");
	            //    if (!sentMessage) sendAttckMessage(traci->getRoadId());
	            //  ev<<"------------------------------------------>"<< simTime() <<"\n";


//bubble("protect the network against falsified information");
	            }else if (simTime() - lastDroveAt >= 40) {
	                findHost()->getDisplayString().updateWith("r=25,red;t=accident_emergency;");
                  //  findHost()->getDisplayString().updateWith("r=25,green;t=Best Forwarder; ");
                    //traci->getId();
                  // bubble("Remote server rerouted the vehicle ");
                 //   traci->getTotalObjectCount();
                //   ev<<"----------------------------->Data vehicles are secure message ("<< traci->getTotalObjectCount()<<"): road segment id------"<<traci->getRoadId()<<"\n" ;

                    if (!sentMessage) sendMessage(traci->getRoadId());
	            }

	            else if (simTime() - lastDroveAt >= 60) {
	                              //  findHost()->getDisplayString().updateWith("r=25,green;t=BSA_Route;");
	                                //traci->getId();
	                              // bubble("Remote server rerouted the vehicle ");
	                             //   traci->getTotalObjectCount();
	                            //   ev<<"----------------------------->Data vehicles are secure message ("<< traci->getTotalObjectCount()<<"): road segment id------"<<traci->getRoadId()<<"\n" ;

	                                if (!sentMessage) sendMessage(traci->getRoadId());
	                            }
	        }
	        else {
	          //  findHost()->getDisplayString().updateWith("r=20,green;t=Normal vehicle ");
	            lastDroveAt = simTime();

	        }


	}
}
void TraCIDemo11p::sendWSM(WaveShortMessage* wsm) {
	if (isParking && !sendWhileParking) return;
	sendDelayedDown(wsm,individualOffset);
}
