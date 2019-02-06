cplusplus {{
#include "modules/messages/WaveShortMessage_m.h"
#define DONTCARE 99
#define LTE 100
#define DSRC 101
#define LOCAL 102
#define OTHER 103

#define CAM_TYPE 42
#define CAM_ERROR_TYPE 43
#define BEACON_TYPE 44
}}

class WaveShortMessage;

// The basic message for the heterogeneous network - it is used by the decision maker.

message HeterogeneousMessage extends WaveShortMessage {
	string sourceAddress;
	string destinationAddress;
	int networkType;
	simtime_t sendingTime;
}
