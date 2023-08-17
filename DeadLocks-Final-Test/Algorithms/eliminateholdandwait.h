#ifndef ELIMINATEHOLDANDWAIT_H
#define ELIMINATEHOLDANDWAIT_H

#include <Algorithms/deadlock_avoidance_api.h>
#include <QSemaphore>


/**
 * @brief Class represents the algorithm to eliminate HoldAndWait
 */
class EliminateHoldAndWait : public deadlock_avoidance_api
{
public:
    /**
     * @brief EliminateHoldAndWait standard constuctor
     */
    EliminateHoldAndWait();
    ~EliminateHoldAndWait();

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
     * @brief avoidance_algorithm algorithm which checks for deadlocks
     * @param process process which runs in the current thread
     * @param differenceResources_A is an array with the current available resources
     * @return returns false if the current state is a deadlock or true if not
     */
    bool avoidance_algorithm(SystemProcess process, int differenceResources_A[4]);

private:
    static QSemaphore *semaphore;
    static QList<int>currentProcess;
    static int copyDifference[4];
};


#endif // ELIMINATEHOLDANDWAIT_H
