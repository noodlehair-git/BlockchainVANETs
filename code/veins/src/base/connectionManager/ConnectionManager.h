#ifndef CONNECTIONMANAGER_H_
#define CONNECTIONMANAGER_H_

#include "MiXiMDefs.h"
#include "BaseConnectionManager.h"
extern "C"
{
    #include <stdlib.h>
    #include <assert.h>
    #include <string.h>
}

#include <math.h>
/**
 * @brief BaseConnectionManager implementation which only defines a
 * specific max interference distance.
 *
 * Calculates the maximum interference distance based on the transmitter
 * power, wavelength, pathloss coefficient and a threshold for the
 * minimal receive Power.
 *
 * @ingroup connectionManager
 */
class MIXIM_API ConnectionManager : public BaseConnectionManager
{
protected:
    typedef enum Velocity {
           Slow, vMedium, fast

       }velocity;

       typedef enum Traffic_density {
           Light, tdMedium, heavy

          }traffic_density;

       typedef enum Channel_Condition {
              cc_bad, ccMedium, cc_good

             }channel_condition;
       typedef enum Rank {
                 bad, veryBad, Acceptable,Unpreferable,Perfect,good

                }rank;
              //  static const double ALFA=-0.4527;
               // static const double BETA= 0.0218;
               // static const double GAMA= 0.86;
                //static const double pi= 3.14159;

                //iteration parameter
                //static const int ITERATION= 1000;
                //static const double SIGMA_BEGIN= 0.2;
                //static const double SIGMA_PRECISION= 0.0001;

                //check irregular: 1;
                //check regular: 0;
                bool chk_irre;

                // parameter used in phi_inv
                // phi_inv_sample
                //static const int PHI_SAMPLE_LENGTH = 100000;
               // static const double PHI_SAMPLE_RANGE = 40;
                //static const double PHI_SAMPLE_STEP = 0.0004;

                // phi_inv function in and out vector


                //---------------------------------
                //regular LDPC degree
                //---------------------------------
                int dv,dc;

                double code_rate;

                //----------------------------------
                //irregular LDPC degree distribution
                //----------------------------------


                //edge perspective
                double vdd_e[20][2];
                double cdd_e[20][2];
                //node perspective
                double vdd_n[20][2];
                double cdd_n[20][2];

	/**
	 * @brief Calculate interference distance
	 *
	 * Calculation of the interference distance based on the transmitter
	 * power, wavelength, pathloss coefficient and a threshold for the
	 * minimal receive Power
	 *
	 * You may want to overwrite this function in order to do your own
	 * interference calculation
	 */
	virtual double calcInterfDist();

};

#endif /*CONNECTIONMANAGER_H_*/
