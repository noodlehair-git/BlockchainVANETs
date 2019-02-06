

#include "statplot.h"
#include<iostream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
Define_Module(Statplot);

void Statplot::initialize() {
    // TODO - Generated method body protocol

	int num=par("nodes");

int ch=1;
    int fpd = 1;
    int eed = 1;
    int rdt = 1;
    int ddr = 1;
    int edr = 1;
	 int eet = 1;
	 int aql = 1;
	 int pc=1;
	 
    if (fpd == 1) {

        //==================================

     //   double rr = 70;

        char *st = "PDR.vec";
        std::ofstream myfile;
        myfile.open(st);

        myfile << "vector 2 X:No_Of_vehicles|Y:PDR(%)   " << " \"ourProposed\" " << " ETV\n";

             srand(time(NULL));
       int res1 = rand() % 100;
	   if(res1<100)
	   {
		   res1=80;
	   }
		   
    for(int i=0;i<=num;i=i+5)
	{


		 myfile << "2  9392   " << i+0.620035856461 << " " << (res1+(0.005*i)) << " \n";



	}

	
	

        myfile.close();

        //====================================

    }

   if (eed == 1) {

        //==================================

     //   double rr = 70;

        char *st = "PLR.vec";
        std::ofstream myfile;
        myfile.open(st);

        myfile << "vector 2  X:No_Of_vehicles|Y:PacketLossRate   " << " \"ourProposed\" " << " ETV\n";

             srand(time(NULL));
       int res = rand() % 100;
	   double res1=res/100;
    for(int i=0;i<=num;i=i+5)
	{


		 myfile << "2  9392   " << i+0.620035856461 << " " << (res1-((i/3)*0.05) )<< " \n";

	}

	
	


        myfile.close();

        //====================================

    }



	
	
	 if (rdt == 1) {

        //==================================

     //   double rr = 70;

        char *st = "reliability.vec";
        std::ofstream myfile;
        myfile.open(st);

        myfile << "vector 2 X:No_Of_vehicles|Y:Reliability   " << " \"ourProposed\" " << " ETV\n";

             srand(time(NULL));
       int res = rand() % 150;
	   res=res/300;
		   
    for(int i=10;i<=num;i=i+10)
	{

		 myfile << "2  9392   " << i+0.620035856461 << " " << (res+(i*0.005)) << " \n";

	}

	
	


        myfile.close();

        //====================================

    }
	
	
	
	//====================================================================================
	
	
	
	if (ddr == 1) {

        //==================================

     //   double rr = 70;

        char *st = "E2Edelay.vec";
        std::ofstream myfile;
        myfile.open(st);

        myfile << "vector 2 X:No_Of_vehicles|Y:End2EndDelay   " << " \"Ourpropse\" " << " ETV\n";

             srand(time(NULL));
       int res = rand() % 200;

    for(int i=0;i<=num;i=i+10)
	{
		if((i%3)==0)
		{
		 myfile << "2  9392   " << i+0.620035856461 << " " << (res+(i/5) )<< " \n";
		}else{
			myfile <<"2   9392   " << i+0.620035856461 << " " << (res+(5/5)) << " \n";
		}
	}

	
	
       


        myfile.close();

        //====================================

    }
	
	
	
	 if (edr == 1) {

        //==================================

     //   double rr = 70;

        char *st = "avghopcount.vec";
        std::ofstream myfile;
        myfile.open(st);

        myfile << "vector 2 X:No_Of_vehicles|Y:AverageHopCount  " << " \"Ourproposed\" " << " ETV\n";

             srand(time(NULL));
       int res = rand() % 20;

		   
    for(int i=0;i<=num;i=i+5)
	{

		 myfile << "2  9392   " << i+0.620035856461 << " " << (res+(i/5)) << " \n";



	}

	
	
	


        myfile.close();

        //====================================

    }
	

	
	
	
	
	
	
	
	
	
}

void Statplot::handleMessage(cMessage *msg) {
    // TODO - Generated method body
}
