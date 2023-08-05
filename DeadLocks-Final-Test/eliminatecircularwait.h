#ifndef ELIMINATECIRCULARWAIT_H
#define ELIMINATECIRCULARWAIT_H

#include <deadlock_avoidance_api.h>



class EliminateCircularWait : public deadlock_avoidance_api
{
public:
    EliminateCircularWait();

    QList<int> findNextResource(SystemProcess process, int stillNeededResources_RCopy[3][4], int assignedResources_CCopy[3][4], int differenceResources_ACopy[4], int availableResources_ECopy[4]);

    QList<SystemResource> avoidance_algorithm(QList<SystemResource> neededResources);
};

#endif // ELIMINATECIRCULARWAIT_H
