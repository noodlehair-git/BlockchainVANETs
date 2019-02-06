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

#ifndef HETEROGENEOUSTOLTE_H_
#define HETEROGENEOUSTOLTE_H_

#include <omnetpp.h>
#include "UDPSocket.h"
#include "IPvXAddressResolver.h"
#include "modules/mobility/traci/TraCIScenarioManager.h"
#include "application/traci/HeterogeneousMessage_m.h"
#include "base/utils/SimpleLogger.h"

#define BROADCAST -1

/**
 * @brief
 * This module sends messages via LTE and provides the transformation between packet types.
 *
 * @author Florian Hagenauer
 *
 */

class HeterogeneousToLTE: public cSimpleModule {

	private:
		std::string id;  /** The cars id. */
		int ltePort;  /** The port for the LTE messages. */

	protected:
		/** Various gates for the communication. */
		int toApplication;
		int toLTE;
		int fromApplication;
		int fromLTE;
		UDPSocket socket; /** The UDP socket for communication. */
		Veins::TraCIScenarioManager* manager;  /** The scenario manager. */
		bool debug;
		bool infoLogging;

	public:
		HeterogeneousToLTE();
		virtual ~HeterogeneousToLTE();
	protected:
		virtual void initialize();
		virtual void handleMessage(cMessage *msg);
};

#endif /* HETEROGENEOUSTOLTE_H_ */
