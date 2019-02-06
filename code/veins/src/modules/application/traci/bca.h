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

#ifndef BCA_H_
#define BCA_H_
#include <omnetpp.h>
class bca: public cSimpleModule {
public:

    bca();
    virtual ~bca();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    public:
    int M =1;
       int pop;
       int dim;
       int FQ ;
       double c1;
      double c2 ;
      double a1 ;
      double a2 ;
      double FitFunc(double x );
      double min(double* array, int size);
      int getbestIndex(double* array, int size);
      double Bounds(double s, double Lb, double Ub);
      double randiTabu(int min, int max, int tabu, int dim);
      double mean(double dArray[], int iSize);
      int getmaxIndex(double* array, int size);

      double bcasmartcontract(int M, int pop, int dim, int FQ, double c1, double c2, double a1, double a2 );
};

#endif /* BCA_H_ */
