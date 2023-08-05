#ifndef ELIMINATEHOLDANDWAIT_H
#define ELIMINATEHOLDANDWAIT_H

#include <deadlock_avoidance_api.h>



class EliminateHoldAndWait : public deadlock_avoidance_api
{
public:
    EliminateHoldAndWait();

    QList<int> findNextResource(SystemProcess process, int stillNeededResources_RCopy[3][4], int assignedResources_CCopy[3][4], int differenceResources_ACopy[4], int availableResources_ECopy[4]);
};

#endif // ELIMINATEHOLDANDWAIT_H
