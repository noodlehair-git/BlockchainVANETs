package org.car2x.veins.modules.lte;

import org.car2x.veins.base.modules.IBaseApplLayer;

simple ExampleDecisionMaker like IBaseApplLayer {

	parameters:
		@class(ExampleDecisionMaker);
		@signal[DSRCMessagesSent](type="long");
		@statistic[DSRCMessagesSent](title="DSRCMessagesSent"; source="DSRCMessagesSent"; record=vector, stats, histogram);
		@signal[lteMessagesSent](type="long");
		@statistic[lteMessagesSent](title="lteMessagesSent"; source="lteMessagesSent"; record=vector, stats, histogram);
		@signal[dontCareMessagesSent](type="long");
		@statistic[dontCareMessagesSent](title="dontCareMessagesSent"; source="dontCareMessagesSent"; record=vector, stats, histogram);
		@signal[DSRCMessagesReceived](type="long");
		@statistic[DSRCMessagesReceived](title="DSRCMessagesReceived"; source="DSRCMessagesReceived"; record=vector, stats, histogram);
		@signal[lteMessagesReceived](type="long");
		@statistic[lteMessagesReceived](title="lteMessagesReceived"; source="lteMessagesReceived"; record=vector, stats, histogram);
		int headerLength = default(88bit) @unit(bit);
		double maxOffset = default(0s) @unit(s);
		bool infoLogging = default(true);

    gates:
        input fromApplication;
        output toApplication;

        input fromLte;
        output toLte;

        input lowerLayerIn;
        output lowerLayerOut;
        input lowerControlIn;
        output lowerControlOut;
}
