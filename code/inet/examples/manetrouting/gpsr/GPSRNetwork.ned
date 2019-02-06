//
// This program is property of its copyright holder. All rights reserved.
// 

package inet.examples.manetrouting.gpsr;

import inet.base.LifecycleController;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.nodes.gpsr.GPSRRouter;
import inet.world.radio.ChannelControl;
import inet.world.scenario.ScenarioManager;


network ZRP
{
    parameters:
        int numHosts;
    submodules:
        channelControl: ChannelControl {
            parameters:
                @display("p=50,50");
        }
        configurator: IPv4NetworkConfigurator {
            parameters:
                config = xml("<config><interface hosts='*' address='145.236.x.x' netmask='255.255.0.0'/></config>");
                @display("p=50,100");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=50,150");
        }
        lifecycleController: LifecycleController {
            parameters:
                @display("p=50,200");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=50,250");
        }
        ZRPNODE[numHosts]: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070");
        }
    connections allowunconnected:
}

network GPSRNetworkManual
{
    @display("bgb=722,558");
    submodules:
        channelControl: ChannelControl {
            parameters:
                @display("p=50,50");
        }
        configurator: IPv4NetworkConfigurator {
            parameters:
                config = xml("<config><interface hosts='*' address='145.236.x.x' netmask='255.255.0.0'/></config>");
                @display("p=50,100");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=50,150");
        }
        host0: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=148,323");
        }
        host1: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=335,313");
        }
        host2: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=254,313");
        }
        host3: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=407,323");
        }
        host4: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=346,194");
        }
        host5: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=254,194");
        }
        host6: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=169,239");
        }
        host7: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=325,416");
        }
        host8: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=201,400");
        }
        host9: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=476,370");
        }
        host10: GPSRRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=446,229");
        }
}
