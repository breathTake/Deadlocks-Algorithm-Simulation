#ifndef NOAVOIDANCESIMULATION_H
#define NOAVOIDANCESIMULATION_H

#include <Algorithms/deadlock_avoidance_api.h>

/**
 * @brief Class represents the standard algorithm to sort and use the resources, normally leads to a deadlock
 */
class NoAvoidanceSimulation : public deadlock_avoidance_api
{
public:
    /**
     * @brief NoAvoidanceSimulation standard constructor
     */
    NoAvoidanceSimulation();
    ~NoAvoidanceSimulation();
};

#endif // NOAVOIDANCESIMULATION_H
