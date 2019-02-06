//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

import org.car2x.veins.modules.world.annotations.Cloudsim;
import org.car2x.veins.modules.world.annotations.Statplot;
import org.car2x.veins.nodes.RSU;
import org.car2x.veins.nodes.OBU;
import org.car2x.veins.nodes.Scenario;
import inet.networklayer.autorouting.ipv4.IPv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.nodes.ethernet.Eth1G;
import inet.nodes.inet.Router;
import inet.nodes.inet.StandardHost;

network Vanet extends Scenario
{
    submodules:



        routingRecorder: RoutingTableRecorder {
            @display("p=50,75;is=s");
        }
        configurator: IPv4NetworkConfigurator {
            @display("p=50,125");
            config = xmldoc("demo.xml");
        }


        rsu[1]: RSU {
            @display("p=16,50;i=device/antennatower;is=vl");
        }

        obu: OBU {

            @display("p=176,174;i=old/bwcomp;is=vl;t=OBU");

        }




    connections:
    //    server.pppg++ <--> Eth1G <--> router.pppg++;
      //  router.pppg++ <--> Eth1G <--> pgw.filterGate;
      ///  pgw.pppg++ <--> Eth1G <--> rsu[1].ppp;
       // pgw.pppg++ <--> Eth1G <--> rsu1[1].ppp;

        //# X2 connections
     //  rsu[1].x2++ <--> Eth1G <--> rsu1[1].x2++;
     //  eNodeB3.x2++ <--> Eth1G <--> eNodeB1.x2++;
       // pgw.ethg++ <--> rsu[0].ppp;

        //    pgw.pp <--> rsu[0].ppp;
        //   pgw.pppg++ <--> rsu1[0].ppp;
        //  pgw.pppg++ <--> rsu[0].ppp;
        //    enodeB[0].pp <--> router.pp;
        //  enodeB1[0].pp <--> router.pp;
        //  router.pppg++ <--> enodeB1[0].ppp;
        //  router.pppg++ <--> enodeB[0].ppp;
    //    enodeB1[0].ppp <--> router.pp++;
      //  router.pp++ <--> enodeB[0].ppp;

      //  enodeB1[0].pp --> router.pp++;
     //   enodeB[0].pp --> router.pp++;

     //   cloudsim.out++ --> rsu[0].in1;
      //  cloudsim.out++ --> rsu1[0].in1;
     //   cloudsim.out++ --> rsu2[0].in1;
}
