#ifndef ELIMINATECIRCULARWAIT_H
#define ELIMINATECIRCULARWAIT_H

#include <Algorithms/deadlock_avoidance_api.h>



class EliminateCircularWait : public deadlock_avoidance_api
{
public:
    /**
     * @brief EliminateCircularWait standard constructor
     */
    EliminateCircularWait();

    /**
     * @brief findNextResource function that will find the next resource,
     * @param process is the process of the thread
     * @param availableResources_E is an array with the over all available resources
     * @param differenceResources_A is an array with the current available resources
     * @param assignedResources_C matrix containing which and how many resources a process is occupying
     * @param stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     * @param result from type @List<int>: first int is nextResource, second int is nextResourceCount, third int is indexResourceList
     */
    QList<int> findNextResource(SystemProcess process, int stillNeededResources_RCopy[3][4], int assignedResources_CCopy[3][4], int differenceResources_ACopy[4], int availableResources_ECopy[4]);

    /**
     * @brief avoidance_algorithm the function integrating the core algorithm
     * @param neededResources a copy of the neededResources list of the process in the current worker object
     * @return the sorted neededResources list
     */
    QList<SystemResource> avoidance_algorithm(QList<SystemResource> neededResources);
};

#endif // ELIMINATECIRCULARWAIT_H
