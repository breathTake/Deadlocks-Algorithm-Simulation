#include "bankiersalgorithm.h"
#include "QDebug"
#include "qmutex.h"
#include <QThread>


QMutex *mutexOne = new QMutex();


BankiersAlgorithm::BankiersAlgorithm()
{
    lastWasDeadlock = -1;
}


QList<int> BankiersAlgorithm::findNextResource(SystemProcess process, int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4])
{
    mutexOne->lock();

    //finding the next Resource and count to be reserved
    QList<int> result;

    //nextResouce is the next resource that should get reserved. If it is -1 the next Resource has either not been found yet or there is no resource left. -2 is the flag that the request has to be repeated. -5 is the flag that there is no resourc left.
    int nextResource = -1;
    //countResource is the amount of the resource that should be reserved. The Algorithm will try to reserve the amount that is given as count in neededResources of the process
    int countResource = -1;
    //indexResourceList is the index of the nextResourc in the neededResources list of process as they are in random order
    int indexResourceList = -1;
    //bool if there was a deadlock in this round of checking for next resource
    bool deadlock = false;


    //going through the neededResources list to find the next needed resource
    for(int i = 0; i < process.getNeededResources().count(); i++){

        //the resource has to have a count > 0 but < the available resources we will check for the next resource
        if(process.getNeededResources().at(i).getCount() <= differenceResources_A[process.getNeededResources().at(i).getResourceId()] && process.getNeededResources().at(i).getCount() > 0){
            //reserve the resources that would be the potential next resource to find out if it is a state is save

            differenceResources_A[process.getNeededResources().at(i).getResourceId()] -= process.getNeededResources().at(i).getCount();
            stillNeededResources_R[process.getProcessId()][process.getNeededResources().at(i).getResourceId()] -= process.getNeededResources().at(i).getCount();

            if(avoidance_algorithm(stillNeededResources_R, assignedResources_C, differenceResources_A, availableResources_E)){
                //if the state is save the nextResources, indexResourcesList and countResources will be set, and marked as not a deadlock

                //differenceResources_A is returned to former state because it will be changed when resource is aquired
                differenceResources_A[process.getNeededResources().at(i).getResourceId()] += process.getNeededResources().at(i).getCount();
                nextResource = process.getNeededResources().at(i).getResourceId();
                indexResourceList = i;
                countResource = process.getNeededResources().at(i).getCount();
                deadlock = false;
                break;
            } else{
                //if the state is not save it is a potential deadlock an the requested resource will not be reserved

                deadlock = true;
                //-2 as nextResource indicates deadlock
                nextResource = -2;
                stillNeededResources_R[process.getProcessId()][process.getNeededResources().at(i).getResourceId()] += process.getNeededResources().at(i).getCount();
                //differenceResources_A is returned to former state because it will be changed when resource is aquired
                differenceResources_A[process.getNeededResources().at(i).getResourceId()] += process.getNeededResources().at(i).getCount();

            }

        } else if(process.getNeededResources().at(i).getCount() > 0 && process.getNeededResources().at(i).getCount()){
            //there are still needed Resources that need to be reserved that are currently occupied

            nextResource = -2;

        } else if(!deadlock && i == process.getNeededResources().count() - 1 && nextResource == -1){
            //in this case there are no resources left to process (all are either 0 or can't be processed because they exeed the over all available resource count
            //no return yet because last resource has to be released
            nextResource = - 5;
            break;
        }

    }

    result.append(nextResource);
    result.append(countResource);
    result.append(indexResourceList);

    mutexOne->unlock();
    return result;
}


bool BankiersAlgorithm::avoidance_algorithm(int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4]){
    //countFinished counts the processes that have been completely analyzed
    int countFinished = 0;
    //markedFinished contains the id of the processes that have been completely analyzed
    vector<int> markedFinished;
    while(countFinished < 3) {
        bool found = false;
        for(int i = 0; i < 3; i++){
            //check if the process has been analyzed
            if(!binary_search(markedFinished.begin(), markedFinished.end(), i)) {
                int count = 0;
                for(int j = 0; j < 4; j++) {
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
            return false; // Deadlock
        }
    }
    return true; // No Deadlock
}



