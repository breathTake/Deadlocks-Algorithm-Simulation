#ifndef CAREFULRESOURCEDISTRIBUTION_H
#define CAREFULRESOURCEDISTRIBUTION_H

#include <deadlock_avoidance_api.h>



class CarefulResourceDistribution : public deadlock_avoidance_api
{
public:
    CarefulResourceDistribution();

    QList<int> findNextResource(SystemProcess process, int stillNeededResources_RCopy[3][4], int assignedResources_CCopy[3][4], int differenceResources_ACopy[4], int availableResources_ECopy[4]);
};

#endif // CAREFULRESOURCEDISTRIBUTION_H
