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

#ifndef DECISIONMAKER_H
#define DECISIONMAKER_H

#include <omnetpp.h>
#include "base/modules/BaseApplLayer.h"
#include "application/traci/HeterogeneousMessage_m.h"
#include "modules/mobility/traci/TraCIMobility.h"
#include "UDPControlInfo_m.h"
#include "modules/world/annotations/AnnotationManager.h"
#include "base/connectionManager/ChannelAccess.h"
#include "MobilityBase.h"
#include "modules/utility/Consts80211p.h"
#include "base/utils/SimpleLogger.h"

using Veins::AnnotationManager;
using Veins::AnnotationManagerAccess;

const simsignalwrap_t mobilityStateChangedSignal = simsignalwrap_t(MIXIM_SIGNAL_MOBILITY_CHANGE_NAME);

/**
 * @brief
 * The decision maker layer for the heterogeneous stack in a car.
 *
 * It either sends the message via LTE or DSRC.
 * Additionally the user can specify DONTCARE in which case the decision maker will decide
 * how to send.
 *
 * @author Florian Hagenauer
 *
 */

class BasicDecisionMaker: public BaseApplLayer {

    protected:
        /** Various gates for the communication. */
        int fromApplication;
        int toApplication;
        int fromLte;
        int toLte;
        int fromDSRC;
        int toDSRC;
        std::string id;  /** The id of the car. */
        Coord currentPosition;
        double maxOffset;
        double individualOffset;
        bool infoLogging;

        // statistic collection
        simsignal_t DSRCMessagesSent;
        simsignal_t lteMessagesSent;
        simsignal_t dontCareMessagesSent;
        simsignal_t DSRCMessagesReceived;
        simsignal_t lteMessagesReceived;

    public:
        BasicDecisionMaker();
        virtual ~BasicDecisionMaker();
        Coord getPosition() {
            return currentPosition;
        }

    protected:
        virtual int numInitStages() const {
            return std::max(4, cSimpleModule::numInitStages());
        }

        virtual void initialize(int stage);
        virtual void finish();
        virtual void handleLowerMessage(cMessage* msg);
        virtual void handleMessage(cMessage* msg);
        virtual void sendLteMessage(HeterogeneousMessage* msg) = 0;
        virtual void sendDSRCMessage(HeterogeneousMessage* msg) = 0;
        virtual void sendDontCareMessage(HeterogeneousMessage* msg) = 0;

        /* Functions from the BaseWaveApplLaver.cc */
        virtual void receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj);
        virtual void handlePositionUpdate(cObject* obj);
        void sendWSM(WaveShortMessage* wsm);
};

#endif /* DECISIONMAKER_H */
