

package org.car2x.veins.modules.lte;

import org.car2x.veins.modules.application.ieee80211p.BaseWaveApplLayer;

simple DecisionMaker extends BaseWaveApplLayer {

	parameters:
		@class(DecisionMaker);

	//	bool debug = default(false);
		bool infoLogging = default(true);

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

    gates:
        input fromApplication;
        output toApplication;

        input fromLte;
        output toLte;
}
