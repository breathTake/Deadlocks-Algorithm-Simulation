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

    //nextResouce is the next resource that should get reserved. If it is -1 the next Resource has either not been found yet or there is no resource left. -5 is the flag that there is no resourc left.
    int nextResource = -1;
    //countResource is the amount of the resource that should be reserved. The Algorithm will try to reserve the amount that is given as count in neededResources of the process
    int countResource = -1;
    //indexResourceList is the index of the nextResourc in the neededResources list of process as they are in random order
    int indexResourceList = -1;
    bool deadlock = false;
    bool anydeadlock = false;

    /*for(int i = 0; i < process.getNeededResources().count(); i++){
        if(process.getNeededResources().at(i).getCount() <= differenceResources_A[process.getNeededResources().at(i).getResourceId()] && process.getNeededResources().at(i).getCount() > 0){
            if(lastWasDeadlock == i){
                process.shuffleNeededResources();
                lastWasDeadlock = -1;
                qDebug() << "shuffled:" << process.getNeededResources().at(0).getName() << ", " << process.getNeededResources().at(1).getName() << ", " << process.getNeededResources().at(2).getName() << ", " << process.getNeededResources().at(3).getName() << ", ";
                break;
            }
        }
    }*/
    //going through the neededResources list to find the next needed resource
    qDebug() << "\n";
    for(int i = 0; i < process.getNeededResources().count(); i++){

        //the resource has to have a count > 0 but < the over all available resources
        if(process.getNeededResources().at(i).getCount() <= differenceResources_A[process.getNeededResources().at(i).getResourceId()] && process.getNeededResources().at(i).getCount() > 0){
            //if the next resource was found set the nextResource, countResource and indexResourceList variables

            differenceResources_A[process.getNeededResources().at(i).getResourceId()] -= process.getNeededResources().at(i).getCount();
            stillNeededResources_R[process.getProcessId()][process.getNeededResources().at(i).getResourceId()] -= process.getNeededResources().at(i).getCount();

            qDebug() << "Process" << process.getName() << "trying to reserve" << process.getNeededResources().at(i).getCount() << " of resource " << process.getNeededResources().at(i).getResourceId();
            if(avoidance_algorithm(stillNeededResources_R, assignedResources_C, differenceResources_A, availableResources_E)){
                printStillNeeded(stillNeededResources_R, differenceResources_A);
                differenceResources_A[process.getNeededResources().at(i).getResourceId()] += process.getNeededResources().at(i).getCount();
                nextResource = process.getNeededResources().at(i).getResourceId();
                indexResourceList = i;
                countResource = process.getNeededResources().at(i).getCount();
                deadlock = false;
                qDebug() << "succeded___process: " << process.getName() << " reserved " << countResource << " of resource " << nextResource;
                if(i == process.getNeededResources().count() - 1){
                    anydeadlock = false;
                }
                break;
            } else{
                //lastWasDeadlock = i;
                deadlock = true;
                anydeadlock = true;
                nextResource = -2;
                stillNeededResources_R[process.getProcessId()][process.getNeededResources().at(i).getResourceId()] += process.getNeededResources().at(i).getCount();
                differenceResources_A[process.getNeededResources().at(i).getResourceId()] += process.getNeededResources().at(i).getCount();
                if(i == process.getNeededResources().count() - 1){
                    qDebug() << "denied";
                    printStillNeeded(stillNeededResources_R, differenceResources_A);
                    break;
                }



                /*qDebug() << process.getNeededResources().at(i).getName();

                qDebug() << process.getNeededResources().at(i).getName();

                result.append(nextResource);
                result.append(countResource);
                result.append(indexResourceList);
                break;


                mutexOne->unlock();
                return result;*/
            }



        } else if(process.getNeededResources().at(i).getCount() > 0){

            nextResource = -2;
            qDebug() << "denied--not available right now";
            //printStillNeeded(stillNeededResources_R, differenceResources_A);
            //deadlock = false;


        } else if(!deadlock && i == process.getNeededResources().count() - 1 && nextResource == -1){
            //in this case there are no resources left to process (all are either 0 or can't be processed because they exeed the over all available resource count
            //no return yet because last resource has to be released
            qDebug() << "position:" << i << "has count" << process.getNeededResources().at(i).getCount();
            nextResource = - 5;
            qDebug() << process.getName() << "finished";
            break;
        }

    }

    qDebug() << "process: " << process.getName() << " will give back " << countResource << " of resource " << nextResource;


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



