#ifndef DEADLOCK_AVOIDANCE_API_H
#define DEADLOCK_AVOIDANCE_API_H

#include <Objects/SystemProcess.h>
#include <QSemaphore>
#include <QDebug>

/**
 * @brief The virtual class represents an API the algorithms use
 */
class deadlock_avoidance_api
{
public:
    deadlock_avoidance_api();

    virtual ~deadlock_avoidance_api() = 0;
    /**
     * @brief findNextResource virtual function that will find the next resource,
     * @param process is the process of the thread
     * @param availableResources_E is an array with the over all available resources
     * @param differenceResources_A is an array with the current available resources
     * @param assignedResources_C matrix containing which and how many resources a process is occupying
     * @param stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     * @return result from type @List<int>: first int is nextResource, second int is nextResourceCount, third int is indexResourceList
     */
    virtual QList<int> findNextResource(SystemProcess process);

    virtual void aquireConditionMet(int processId){
    }

    virtual bool checkAquireCondition(int processId){
        return false;
    }
};

#endif // DEADLOCK_AVOIDANCE_API_H
