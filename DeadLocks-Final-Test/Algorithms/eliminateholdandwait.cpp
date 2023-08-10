#include "eliminateholdandwait.h"
#include <QDebug>

QList<int> EliminateHoldAndWait::currentProcess;
QSemaphore* EliminateHoldAndWait::semaphore = new QSemaphore(1);
int EliminateHoldAndWait::copyDifference[4];

EliminateHoldAndWait::EliminateHoldAndWait()
{

}

QList<int> EliminateHoldAndWait::findNextResource(SystemProcess process, int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4]){

    QList<int> result;

    //nextResouce is the next resource that should get reserved. If it is -1 the next Resource has either not been found yet or there is no resource left. -5 is the flag that there is no resourc left.
    int nextResource = -1;
    //countResource is the amount of the resource that should be reserved. The Algorithm will try to reserve the amount that is given as count in neededResources of the process
    int countResource = -1;
    //indexResourceList is the index of the nextResource in the neededResources list of process as they are in random order
    int indexResourceList = -1;

    //if this is the first call set up the copy of the differenceResources because it has to be changed seperatly
    if(currentProcess.empty()){
        //flag as not empty
        currentProcess.append(-1);
        for(int i = 0; i < 4; i++){
            copyDifference[i] = differenceResources_A[i];
        }
    }

    //test if it hasn't requested anything yet
    if(!currentProcess.contains(process.getProcessId())){
        //try to acquire a semaphore
        semaphore->acquire(1);
        //if everything is free we can continue to reserve
        if(avoidance_algorithm(process, copyDifference)){
            //add process to currentProcess to show that it has now requested its resources
            currentProcess.append(process.getProcessId());

            //update copyDifference Array with all the counts of the current process
            for(int i = 0; i < 4; i++){
                copyDifference[process.getNeededResources().at(i).getResourceId()] -= process.getNeededResources().at(i).getCount();
            }

            //if there are still free resources then another process can try to reserve some
            if(copyDifference[0] > 0 || copyDifference[1] > 0 || copyDifference[2] > 0 || copyDifference[3] > 0){
                semaphore->release(1);
            }

        }  else { //not enough free, return to retry at a later point
            semaphore->release(1);
            nextResource = -2;
            result.append(nextResource);
            result.append(countResource);
            result.append(indexResourceList);
            return result;
        }
    }

    //going through the neededResources list to find the next needed resource
    for(int i = 0; i < process.getNeededResources().count(); i++){
        //the resource has to have a count > 0 but < the over all available resources
        if(process.getNeededResources().at(i).getCount() <= availableResources_E[process.getNeededResources().at(i).getResourceId()] && process.getNeededResources().at(i).getCount() > 0){
            //if the next resource was found set the nextResource, countResource and indexResourceList variables
            nextResource = process.getNeededResources().at(i).getResourceId();
            indexResourceList = i;
            countResource = process.getNeededResources().at(i).getCount();
            //update copyDifference
            copyDifference[nextResource] += countResource;
            break;

        } else if(i == process.getNeededResources().count() - 1 && nextResource == -1){
            //in this case there are no resources left to process (all are either 0 or can't be processed because they exeed the over all available resource count
            //no return yet because last resource has to be released
            nextResource = - 5;
            break;
        }
    }

    result.append(nextResource);
    result.append(countResource);
    result.append(indexResourceList);

    //if there are no resources left to reserve a semaphore will be released
    if(nextResource == -5){
       qDebug() << "unlocked";
       semaphore->release(1);
    }

    return result;
}

bool EliminateHoldAndWait::avoidance_algorithm(SystemProcess process, int copyDifference[4])
{
    bool resourcesAvailable = true;
    //Check if all needed Resources are available
    for(int i = 0 ; i < process.getNeededResources().count(); i++){
        if(process.getNeededResources().at(i).getCount() > copyDifference[process.getNeededResources().at(i).getResourceId()]){
            resourcesAvailable = false;
        }
    }

    return resourcesAvailable;
}
