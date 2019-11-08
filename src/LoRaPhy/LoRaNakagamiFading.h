#ifndef LORAPHY_LORANAKAGAMIFADING_H_
#define LORAPHY_LORANAKAGAMIFADING_H_

#include <inet/physicallayer/pathloss/FreeSpacePathLoss.h>

namespace inet{

namespace physicallayer{

class INET_API LoRaNakagamiFading : public FreeSpacePathLoss
{
	protected:
		double shapeFactor;
		m d0;
   		double gamma;
 //   	double sigma;


	protected:
		virtual void initialize(int stage) override;

	public:
		LoRaNakagamiFading();
	    virtual std::ostream& printToStream(std::ostream& stream, int level) const override;
   		virtual double computePathLoss(mps propagationSpeed, Hz frequency, m distance) const override;

};

}

}

#endif