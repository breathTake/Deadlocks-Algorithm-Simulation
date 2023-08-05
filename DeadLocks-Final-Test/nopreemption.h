#ifndef NOPREEMPTION_H
#define NOPREEMPTION_H

#include <deadlock_avoidance_api.h>



class NoPreemption : public deadlock_avoidance_api
{
public:
    NoPreemption();

    QList<int> findNextResource(SystemProcess process, int stillNeededResources_RCopy[3][4], int assignedResources_CCopy[3][4], int differenceResources_ACopy[4], int availableResources_ECopy[4]);
};

#endif // NOPREEMPTION_H
