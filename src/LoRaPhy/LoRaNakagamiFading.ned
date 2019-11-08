package loranetwork.LoRaPhy;

import inet.physicallayer.pathloss.FreeSpacePathLoss;

module LoRaNakagamiFading extends FreeSpacePathLoss
{
    parameters:
        double shapeFactor = default(1); 
        double d0 = default(1000m) @unit(m); //Usei as medidas do Petäjäjärvi => nao são as que o FLoRa usa normalmente
        double gamma = default(2.32);
 //       double sigma = default(3.57);
        @class(inet::physicallayer::LoRaNakagamiFading);
}
