#ifndef BANKIERSALGORITHM_H
#define BANKIERSALGORITHM_H

#include <SystemProcess.h>
#include <deadlock_avoidance_api.h>

using namespace std;

class BankiersAlgorithm : public deadlock_avoidance_api
{
public:
    BankiersAlgorithm() : deadlock_avoidance_api(){
    }


    QList<int> findNextResource(SystemProcess process, int stillNeededResources_RCopy[3][4], int assignedResources_CCopy[3][4], int differenceResources_ACopy[4], int availableResources_ECopy[4]);

    bool avoidance_algorithm(int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4]);
};

#endif // BANKIERSALGORITHM_H
