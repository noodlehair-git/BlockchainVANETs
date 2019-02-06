//
// Copyright (C) 2006-2016 Florian Hagenauer <hagenauer@ccs-labs.org>
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

#include "HeterogeneousToLTE.h"
#include "modules/application/ieee80211p/BaseWaveApplLayer.h"
#include "modules/mobility/traci/TraCIMobility.h"

Define_Module(HeterogeneousToLTE);

void HeterogeneousToLTE::initialize() {
	toApplication = findGate("toApplication");
	toLTE = findGate("toLTE");
	fromApplication = findGate("fromApplication");
	fromLTE = findGate("fromLTE");

	socket.setOutputGate(gate(toLTE));
	ltePort = par("ltePort");
	socket.bind(ltePort);
	manager = Veins::TraCIScenarioManagerAccess().get();
	cModule *tmpMobility = getParentModule()->getSubmodule("veinsmobility");
	Veins::TraCIMobility* mobility = dynamic_cast<Veins::TraCIMobility *>(tmpMobility);
	assert(mobility);
	id = mobility->getExternalId();
	debug = par("debug").boolValue();
	infoLogging = par("infoLogging").boolValue();
}

void HeterogeneousToLTE::handleMessage(cMessage *msg) {
	int gateId = msg->getArrivalGateId();

	if (gateId == fromApplication) {
		HeterogeneousMessage *heterogeneousMessage = dynamic_cast<HeterogeneousMessage *>(msg);
		std::string destinationAddress = heterogeneousMessage->getDestinationAddress();
		if (destinationAddress == id) {
			INFO_ID("Sender and receiver are the same, message not sent!");
			delete msg;
			return;
		} else {
			cModule* destination = simulation.getModuleByPath(destinationAddress.c_str());
			if(!destination){
				WARN_ID("Can't find a module with destination " << destinationAddress << ", not sending message!");
				delete msg;
				return;
			}
			IPv4Address address = IPvXAddressResolver().resolve(destinationAddress.c_str()).get4();
			//if (address.isUnspecified()) {
				//address = manager->getIPAddressForID(destinationAddress);
		//	}
			if(address.isUnspecified()){
				WARN_ID("Address " << destinationAddress << " still unspecified!");
				delete msg;
				return;
			}
			socket.sendTo(heterogeneousMessage, address, ltePort);
		}
	} else if (gateId == fromLTE) {
		send(msg, toApplication);
	} else {
		WARN_ID("Unknown gate: " << msg->getArrivalGate()->getFullName());
	}
}

HeterogeneousToLTE::HeterogeneousToLTE() {
	/* Empty */
}

HeterogeneousToLTE::~HeterogeneousToLTE() {
	/* Empty */
}

