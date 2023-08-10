#ifndef BANKIERSALGORITHM_H
#define BANKIERSALGORITHM_H

#include <Objects/systemprocess.h>
#include <Algorithms/deadlock_avoidance_api.h>

using namespace std;

class BankiersAlgorithm : public deadlock_avoidance_api
{
public:

    BankiersAlgorithm();


    /**
     * @brief findNextResource function that will find the next resource
     * @param process is the process of the thread
     * @param availableResources_E is an array with the over all available resources
     * @param differenceResources_A is an array with the current available resources
     * @param assignedResources_C matrix containing which and how many resources a process is occupying
     * @param stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     * @param result from type @List<int>: first int is nextResource, second int is nextResourceCount, third int is indexResourceList
     * @return
     */
    QList<int> findNextResource(SystemProcess process, int stillNeededResources_RCopy[3][4], int assignedResources_CCopy[3][4], int differenceResources_ACopy[4], int availableResources_ECopy[4]);

    /**
     * @brief avoidance_algorithm avoids a deadlock with the algorithm specifice limitations
     * @param stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     * @param assignedResources_C matrix containing which and how many resources a process is occupying
     * @param differenceResources_A is an array with the current available resources
     * @param availableResources_E is an array with the over all available resources
     * @return
     */
    bool avoidance_algorithm(int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4]);
};

#endif // BANKIERSALGORITHM_H
