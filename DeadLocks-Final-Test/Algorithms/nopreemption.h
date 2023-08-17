#ifndef NOPREEMPTION_H
#define NOPREEMPTION_H

#include <Algorithms/deadlock_avoidance_api.h>


/**
 * @brief Class represents the algorithm to eliminate NoPreemption
 */
class NoPreemption : public deadlock_avoidance_api
{
public:
    /**
     * @brief NoPreemption standard constuctor
     */
    NoPreemption();
    ~NoPreemption();

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

    void aquireConditionMet(int processId) override;
    bool checkAquireCondition(int processId) override;


public:
    static bool slotPrinterLocked;
    static bool slotCDLocked;
    static bool slotPlotterLocked;
    static bool slotTapeDriveLocked;
    static bool lastRevokedProcessA, lastRevokedProcessB, lastRevokedProcessC;
    static QMutex *mutex;
};

#endif // NOPREEMPTION_H
