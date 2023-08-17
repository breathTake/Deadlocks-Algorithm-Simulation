#ifndef BANKIERSALGORITHM_H
#define BANKIERSALGORITHM_H

#include <Objects/systemprocess.h>
#include <Algorithms/deadlock_avoidance_api.h>

using namespace std;

/**
 * @brief Class represents the Bankier Algorithm to prevent Deadlocks
 */
class BankiersAlgorithm : public deadlock_avoidance_api
{
public:
    /**
     * @brief BankiersAlgorithm standard constructor
     */
    BankiersAlgorithm();
    ~BankiersAlgorithm();


    /**
     * @brief findNextResource function that will find the next resource,
     * @param process is the process of the thread
     * @param availableResources_E is an array with the over all available resources
     * @param differenceResources_A is an array with the current available resources
     * @param assignedResources_C matrix containing which and how many resources a process is occupying
     * @param stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     * @param result from type @List<int>: first int is nextResource, second int is nextResourceCount, third int is indexResourceList
     */
    QList<int> findNextResource(SystemProcess process)  override;

    /**
     * @brief avoidance_algorithm algorithm which checks for deadlocks
     * @param stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     * @param assignedResources_C matrix containing which and how many resources a process is occupying
     * @param differenceResources_A is an array with the current available resources
     * @param availableResources_E is an array with the over all available resources
     * @return returns false if the current state is a deadlock or true if not
     */
    bool avoidance_algorithm();
};

#endif // BANKIERSALGORITHM_H
