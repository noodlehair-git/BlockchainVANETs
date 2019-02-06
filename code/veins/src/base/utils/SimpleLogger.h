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

#ifndef SIMPLE_LOGGER
#define SIMPLE_LOGGER

/**
 * @file SimpleLogger.h
 * @author Florian Hagenauer
 * @date: 2016-06-20
 * A simple logging framework for simple logging with three levels (DEBUG, INFO, WARN).
 * Prints: [LEVEL][simTime][module/filename:line] Message
 */

#include <omnetpp.h>

#define DEBUG(x) if(debug) {std::cout << "[DBG][" << simTime().trunc(SIMTIME_US) << "][" << __FILE__ << ":" << __LINE__ << "] "; std::cout << x << std::endl;}
#define DEBUG_ID(x) if(debug) {std::cout << "[DBG][" << simTime().trunc(SIMTIME_US) << "][" << getId() << "][" << getFullPath() << ":" << __LINE__ << "] "; std::cout << x << std::endl;}

#define INFO(x) if(infoLogging || debug) {std::cout << "[INF][" << simTime().trunc(SIMTIME_US) << "][" << __FILE__ << ":" << __LINE__ << "] "; std::cout << x << std::endl;}
#define INFO_ID(x) if(infoLogging || debug) {std::cout << "[INF][" << simTime().trunc(SIMTIME_US) << "][" << getId() << "][" << getFullPath() << ":" << __LINE__ << "] "; std::cout << x << std::endl;}

#define WARN(x) {std::cout << "[WAR][" << simTime().trunc(SIMTIME_US) << "][" << __FILE__ << ":" << __LINE__ << "] "; std::cout << x << std::endl;}
#define WARN_ID(x) {std::cout << "[WAR][" << simTime().trunc(SIMTIME_US) << "][" << getId() << "][" << getFullPath() << ":" << __LINE__ << "] "; std::cout << x << std::endl;}

#endif
