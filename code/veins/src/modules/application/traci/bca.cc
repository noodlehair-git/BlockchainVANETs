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

#include <bca.h>

#include <stdio.h>
#include <math.h>
#include<iostream>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
Define_Module(bca);
bca::bca() {
    // TODO Auto-generated constructor stub

}

bca::~bca() {
    // TODO Auto-generated destructor stub
}

void bca::initialize() {
    // TODO - Generated method body

    M = par("Maxmimal");
    pop = par("pop");
    dim = par("dim");
    FQ = par("FQ");
    c1 = par("c1");
    c2 = par("c2");
    a1 = par("a1");
    a2 = par("a2");
    bcasmartcontract(M, pop, dim, FQ, c1, c2, a1, a2);

}

void bca::handleMessage(cMessage *msg) {
    // TODO - Generated method body
}

double bca::bcasmartcontract(int M, int pop, int dim, int FQ, double c1, double c2,
        double a1, double a2) {


    double lb[dim] = { -100 };
    double ub[dim] = { 100 };
    double x[pop], fit[pop];

    double pX[pop];
    double pFit[pop];
    double realmin=1.0;

    srand(time(NULL));
    int ran = rand() % 100;
    for (int i = 1; i < pop; i++) {
        x[i] = lb[i] + (ub[i] - lb[i]) * ran;
        fit[i] = FitFunc(x[i]);
        pFit[i] = fit[i];
        pX[i] = x[i];
    }

    double fMin = min(fit, pop);
    int bestIndex = getbestIndex(fit, pop);
    double bestX = x[bestIndex];

    double sumPfit = 0.0;
    //===============================================
   double ans = min(pFit,M);


              double minIndex=getbestIndex(pFit,M);

    for (int iteration = 1; iteration < M; iteration++) {
        srand(time(NULL));
        int rp = rand() % pop;

        double prob = rp * 0.2 + 0.8;
       // printf("iteration=%d",iteration);

        if ((iteration % FQ) != 0) {

            sumPfit = sumPfit + pFit[iteration];
           double  meanP =mean(pX,iteration);
            for (int i = 1; i < pop; i++) {
                if (rp < prob) {
                    x[i] = x[i] + c1 * rp * (bestX - x[i])
                            + c2 * rp * (pX[i] - x[i]);
                } else {
                  int  person =(int) randiTabu(1, pop, i, 1);

                    x[i] = x[i]
                            + rp*(meanP - x[i]) * a1
                                    * exp(-pFit[i] / (sumPfit + realmin) * pop)
                            + a2 * (rp * 2 - 1) * (pX[person] - x[i])
                                    * exp(
                                            -(pFit[person] - pFit[i])
                                                    / (abs(
                                                            pFit[person]
                                                                    - pFit[i])
                                                            + realmin)
                                                    * pFit[person]
                                                    / (sumPfit + realmin)
                                                    * pop);
                }

                x[i] = Bounds(x[i], lb[i], ub[i]);
                fit[i] = FitFunc(x[i]);
            }

        }

        else {

            srand(time(NULL));
            int rappn = rand() % pop;
            double vl = (rappn * (0.4 + 0.5));
            double FL[pop] = { vl };


            double maxIndex = getmaxIndex(fit, pop);
            //   [ans, maxIndex ] = max( pFit );
        int    choose = 0;
            if (minIndex < 0.5 * pop && maxIndex < 0.5 * pop) {
                choose = 1;
            }
            if (minIndex > 0.5 * pop && maxIndex < 0.5 * pop) {
                choose = 2;
            }
            if (minIndex < 0.5 * pop && maxIndex > 0.5 * pop) {
                choose = 3;
            }
            if (minIndex > 0.5 * pop && maxIndex > 0.5 * pop) {
                choose = 4;
            }

            if (choose < 3) {
                for (int i = (pop / 2 + 1); i < pop; i++){
                    srand(time(NULL));
                int rann = rand() % pop;
                x[i] = x[i] * (1 + rann);
                x[i] = Bounds(x[i], lb[i], ub[i]);
                fit[i] = FitFunc(x[i]);
            }
            }
            if (choose == 1) {
                srand(time(NULL));
                int rann = rand() % pop;
            int minidx=(int)minIndex;
                x[minidx] = x[minidx] * (1 + rann);
                x[minidx] = Bounds(x[minidx], lb[minidx], ub[minidx]);
                fit[minidx] = FitFunc(x[minidx]);

                for (int i = 1; i < 0.5 * pop; i++) {
                    if (choose == 2 || minIndex != i) {
                        srand(time(NULL));
                        int ranp = rand() % (int) (0.5 * pop + 1);
                      int  person = ranp;
                        x[i] = x[i] + (pX[person] - x[i]) * FL[i];
                        x[i] = Bounds(x[i], lb[i], ub[i]);
                        fit[i] = FitFunc(x[i]);
                    }
                }

            } else {

                for (int i = 1.0; i < (0.5 * pop); i++) {

                    {
                        srand(time(NULL));
                        int rann = rand() % pop;

                        x[i] = x[i] * (1 + rann);
                        x[i] = Bounds(x[i], lb[i], ub[i]);
                        fit[i] = FitFunc(x[i]);
                    }

                    if (choose == 4) {
                        srand(time(NULL));
                        int rann = rand() % pop;
                        int minidx=(int)minIndex;
                        x[minidx] = x[minidx] * (1 + rann);
                        x[minidx] = Bounds(x[minidx], lb[minidx], ub[minidx]);
                        fit[minidx] = FitFunc(x[minidx]);
                    }

                    for (int i = (0.5 * pop + 1); i <= pop; i++) {
                        if (choose == 3 || minIndex != i) {

                            srand(time(NULL));
                            int ranp = rand() % (int) (0.5 * pop);
                          int  person = ranp;
                            x[i] = x[i] + (pX[person] - x[i]) * FL[i];
                            x[i] = Bounds(x[i], lb[i], ub[i]);
                            fit[i] = FitFunc(x[i]);
                        }

                    }
                }

            }
        }
    }

    for (int i = 1; i < pop; i++) {
        if (fit[i] < pFit[i]) {
            pFit[i] = fit[i];
            pX[i] = x[i];
        }

        if (pFit[i] < fMin) {
            fMin = pFit[i];
            bestX = pX[i];
        }
    }

    return bestX;
    //=======================

}

double bca::FitFunc(double x) {
    x = x * x;
    double y = x;
    return y;
}

double bca::min(double* array, int size) {
    // returns the fMin denotes the global optimum
    int i;
    double val = array[0];
    for (i = 1; i < size; ++i) {
        if (val > array[i]) {
            val = array[i];
        }
    }
    return val;
}

int bca::getbestIndex(double* array, int size) {
    // returns the fMin denotes the global optimum
    int i, j = 0;
 M=0;
    double val = array[0];
    for (i = 1; i < size; ++i) {
        if (val > array[i]) {
            val = array[i];
            j = i;
        }
    }
    return j;
}

double bca::Bounds(double s, double Lb, double Ub) {
    double temp = s;
    double I = 0.0;
    if (temp < Lb) {
        I = Lb;
        s = I;
    } else if (temp > Ub) {
        I = Ub;
        s = I;
    }

    return s;
}

double bca::randiTabu(int min, int max, int tabu, int dim) {

    int inv = max * 2;
    int val[dim] = { inv };
    int num = 1;
    while (num <= dim) {

        srand(time(NULL));
        int ranm = rand() % max;
     int   temp = ranm;
        if (temp != tabu) {
            val[num] = temp;
            num = num + 1;
        }
    }
    return val[num];

}


double bca::mean(double dArray[], int iSize) {
    double dSum = dArray[0];
    for (int i = 1; i < iSize; ++i) {
        dSum += dArray[i];
    }
    return dSum/iSize;
}


int bca::getmaxIndex(double* array, int size) {
    // returns the fMin denotes the global optimum
    int i, j = 0;
    double val = array[0];
    for (i = 1; i < size; ++i) {
        if (val < array[i]) {
            val = array[i];
            j = i;
        }
    }
    return j;
}
