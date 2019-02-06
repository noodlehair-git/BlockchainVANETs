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

#include "cloudsim.h"
#include <stdio.h>

Define_Module(Cloudsim);

void Cloudsim::initialize()
{
    // TODO - Generated method body
    int num=par("numusers");
    //execl( "java", "-jar"," E:/2017java/SDN_CLOUD/dist/SDN_CLOUD.jar", NULL);

   // system("java -jar E:/2017java/SDN_CLOUD/dist/SDN_CLOUD.jar");

}

void Cloudsim::handleMessage(cMessage *msg)
{
    // TODO - Generated method body
}
