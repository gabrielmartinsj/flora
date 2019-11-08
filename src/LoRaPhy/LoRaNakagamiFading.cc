/*#ifndef LORAPHY_LORANAKAGAMIFADING_H_
#define LORAPHY_LORANAKAGAMIFADING_H_
*/
#include "LoRaPhy/LoRaNakagamiFading.h"

namespace inet {

namespace physicallayer {

Define_Module(LoRaNakagamiFading);

LoRaNakagamiFading::LoRaNakagamiFading()
{
}

void LoRaNakagamiFading::initialize(int stage)
{
	FreeSpacePathLoss::initialize(stage);
	if (stage == INITSTAGE_LOCAL){
		shapeFactor = par("shapeFactor");
	//	sigma = par("sigma");
        gamma = par("gamma");
        d0 = m(par("d0"));

	}
}

std::ostream& LoRaNakagamiFading::printToStream(std::ostream& stream, int level) const
{
	stream << "LoRaNakagamiFading";
	if (level <= PRINT_LEVEL_TRACE)
		stream << ", alpha = " << alpha
			   << ", systemLoss = " << systemLoss
			   << ", shapeFactor = " << shapeFactor;               
//			   << ", sigma = " << sigma;

	return stream;	
}

//GGMJ: Perguntar ao Richard se devo usar log-normal + nakagami

double LoRaNakagamiFading::computePathLoss(mps propagationSpeed, Hz frequency, m distance) const
{
	m wavelength = propagationSpeed / frequency;
	//double freeSpacePathLoss = computeFreeSpacePathLoss(wavelength, distance, alpha, systemLoss);
    double PL_d0_db = 128.95; //Medidas do Petäjäjärvi
    double PL_db = PL_d0_db + 10 * gamma * log10(unit(distance / d0).get()); //+ normal(0.0, sigma);
 	double PL_lin = pow(10,PL_db/10);
	return gamma_d(shapeFactor, (1/PL_lin)/shapeFactor);
}


}

}