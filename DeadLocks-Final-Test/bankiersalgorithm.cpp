#include "bankiersalgorithm.h"
#include "QDebug"
#include "qmutex.h"
#include <QThread>


QMutex *mutexOne = new QMutex();
QList<int> BankiersAlgorithm::findNextResource(SystemProcess process, int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4])
{
    mutexOne->lock();
    //finding the next Resource and count to be reserved
    QList<int> result;

    //nextResouce is the next resource that should get reserved. If it is -1 the next Resource has either not been found yet or there is no resource left. -5 is the flag that there is no resourc left.
    int nextResource = -1;
    //countResource is the amount of the resource that should be reserved. The Algorithm will try to reserve the amount that is given as count in neededResources of the process
    int countResource = -1;
    //indexResourceList is the index of the nextResourc in the neededResources list of process as they are in random order
    int indexResourceList = -1;

    //going through the neededResources list to find the next needed resource
    for(int i = 0; i < process.getNeededResources().count(); i++){
        //the resource has to have a count > 0 but < the over all available resources
        if(process.getNeededResources().at(i).getCount() <= availableResources_E[process.getNeededResources().at(i).getResourceId()] && process.getNeededResources().at(i).getCount() > 0){
            //if the next resource was found set the nextResource, countResource and indexResourceList variables
            stillNeededResources_R[process.getProcessId()][process.getNeededResources().at(i).getResourceId()] -= process.getNeededResources().at(i).getCount();
            qDebug() << "trying to reserve" << process.getNeededResources().at(i).getCount() << " of resource " << process.getNeededResources().at(i).getResourceId();
            if(avoidance_algorithm(stillNeededResources_R, assignedResources_C, differenceResources_A, availableResources_E)){
                nextResource = process.getNeededResources().at(i).getResourceId();
                indexResourceList = i;
                countResource = process.getNeededResources().at(i).getCount();
                break;
            }
            stillNeededResources_R[process.getProcessId()][process.getNeededResources().at(i).getResourceId()] += process.getNeededResources().at(i).getCount();
            qDebug() << process.getNeededResources().at(i).getName();
            process.moveNeededResourceToBack(i);
            qDebug() << process.getNeededResources().at(i).getName();
            i=0;


        } else if(i == process.getNeededResources().count() - 1 && nextResource == -1){
            //in this case there are no resources left to process (all are either 0 or can't be processed because they exeed the over all available resource count
            //no return yet because last resource has to be released
            nextResource = - 5;
            break;
        }
    }

    qDebug() << "process: " << process.getName() << " requested " << countResource << " of resource " << nextResource;
    printStillNeeded(stillNeededResources_R, differenceResources_A);

    if(nextResource == -1){
        qDebug() << "-1";
    }
    result.append(nextResource);
    result.append(countResource);
    result.append(indexResourceList);

    mutexOne->unlock();
    return result;
}


bool BankiersAlgorithm::avoidance_algorithm(int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4]){
    int countFinished = 0;
    //qDebug() << "\nR: \n";
        vector<int> markedFinished;
        while(countFinished < 3) {
            bool found = false;
            for(int i = 0; i < 3; i++){
                if(!binary_search(markedFinished.begin(), markedFinished.end(), i)) {
                    int count = 0;
                    for(int j = 0; j < 4; j++) {
                        //qDebug() << stillNeededResources_R[i][j];
                        if(stillNeededResources_R[i][j] <= differenceResources_A[j]) {
                            count++;
                            if(count == 4) {
                                markedFinished.push_back(j);
                                found = true;
                                countFinished++;
                            }
                        } else {
                            break;
                        }
                    }

                }
            }
            if(!found){
                qDebug() << "Deadlock";
                return false; // Deadlock
            }
        }
        qDebug() << "No deadlock";
        return true; // No Deadlock

}



