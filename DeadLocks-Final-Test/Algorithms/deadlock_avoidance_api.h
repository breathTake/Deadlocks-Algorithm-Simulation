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

    /**
     * @brief findNextResource virtual function that will find the next resource,
     * @param process is the process of the thread
     * @param availableResources_E is an array with the over all available resources
     * @param differenceResources_A is an array with the current available resources
     * @param assignedResources_C matrix containing which and how many resources a process is occupying
     * @param stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     * @return result from type @List<int>: first int is nextResource, second int is nextResourceCount, third int is indexResourceList
     */
    virtual QList<int> findNextResource(SystemProcess process, int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4]) = 0;

    virtual void aquireConditionMet(int processId){}
    virtual bool checkAquireCondition(int processId){
        return false;
    }

    /**
     * @brief printStillNeeded prints the still needed resources of a process
     * @param stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     * @param differenceResources_A is an array with the current available resources
     */
    void printStillNeeded(int stillNeededResources_R[3][4], int differenceResources_A[4]){
        QDebug dbg(QtDebugMsg);
        dbg << "R:" << "\n";
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 4; j++){
                dbg << stillNeededResources_R[i][j];
            }
            dbg << "\n";
        }
        dbg << "A: " << differenceResources_A[0] << differenceResources_A[1] << differenceResources_A[2] << differenceResources_A[3] << "\n";
    }
};

#endif // DEADLOCK_AVOIDANCE_API_H
