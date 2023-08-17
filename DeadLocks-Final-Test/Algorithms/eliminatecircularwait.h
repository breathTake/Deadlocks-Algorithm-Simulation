#ifndef ELIMINATECIRCULARWAIT_H
#define ELIMINATECIRCULARWAIT_H

#include <Algorithms/deadlock_avoidance_api.h>


/**
 * @brief Class represents the algorithm to eliminate CircularWait
 */
class EliminateCircularWait : public deadlock_avoidance_api
{
public:
    /**
     * @brief EliminateCircularWait standard constructor
     */
    EliminateCircularWait();
    ~EliminateCircularWait();

    /**
     * @brief findNextResource function that will find the next resource,
     * @param process is the process of the thread
     * @param availableResources_E is an array with the over all available resources
     * @param differenceResources_A is an array with the current available resources
     * @param assignedResources_C matrix containing which and how many resources a process is occupying
     * @param stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     * @return result from type @List<int>: first int is nextResource, second int is nextResourceCount, third int is indexResourceList
     */
    QList<int> findNextResource(SystemProcess process) override;

    /**
     * @brief avoidance_algorithm algorithm which sorts the neededResources to avoid a deadlock
     * @param neededResources List of the SystemResources the process needs to work currectly
     * @return returns the sorted list of resources
     */
    QList<SystemResource> avoidance_algorithm(QList<SystemResource> neededResources);
};

#endif // ELIMINATECIRCULARWAIT_H
