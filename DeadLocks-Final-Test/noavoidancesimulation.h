#ifndef NOAVOIDANCESIMULATION_H
#define NOAVOIDANCESIMULATION_H

#include <deadlock_avoidance_api.h>


class NoAvoidanceSimulation : public deadlock_avoidance_api
{
public:
    NoAvoidanceSimulation();
    QList<int> findNextResource(SystemProcess process, int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4]);
};

#endif // NOAVOIDANCESIMULATION_H
