#include "eliminateholdandwait.h"
#include "nopreemption.h"
#include <QDebug>

EliminateHoldAndWait::EliminateHoldAndWait()
{
    mutex = new QMutex();
}

QList<int> EliminateHoldAndWait::findNextResource(SystemProcess process, int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4]){

    QList<int> result;

    //nextResouce is the next resource that should get reserved. If it is -1 the next Resource has either not been found yet or there is no resource left. -5 is the flag that there is no resourc left.
    int nextResource = -1;
    //countResource is the amount of the resource that should be reserved. The Algorithm will try to reserve the amount that is given as count in neededResources of the process
    int countResource = -1;
    //indexResourceList is the index of the nextResource in the neededResources list of process as they are in random order
    int indexResourceList = -1;

    //Step 1: Copy of neededResources
    QList<SystemResource> copyNeededResources =  process.getNeededResources();


    //Step 4: Get nextResource
    if(avoidance_algorithm(process, differenceResources_A)){

        mutex->lock();

        //going through the neededResources list to find the next needed resource
        for(int i = 0; i < process.getNeededResources().count(); i++){

            //the resource has to have a count > 0 but < the over all available resources
            if(process.getNeededResources().at(i).getCount() <= availableResources_E[process.getNeededResources().at(i).getResourceId()] && process.getNeededResources().at(i).getCount() > 0){

                //if the next resource was found set the nextResource, countResource and indexResourceList variables
                nextResource = process.getNeededResources().at(i).getResourceId();
                indexResourceList = i;
                countResource = process.getNeededResources().at(i).getCount();
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

    }else{
        //Deadlock found
        nextResource = -2;
    }

    //Step 6: Return the list of Values
    qDebug() << "Result: Process " << process.getProcessId() << " reserved Resource " << nextResource;

    if(nextResource == -5){
        mutex->unlock();
    }

    return result;
}

bool EliminateHoldAndWait::avoidance_algorithm(SystemProcess process, int differenceResources_A[4])
{
    //Steop 2: Check if enough Resources are available. If NOT -> Step 5
    bool allConditionsMet = true;
    for(int i = 0 ; i < process.getNeededResources().count(); i++){
        if(process.getNeededResources().at(i).getCount() > differenceResources_A[process.getNeededResources().at(i).getResourceId()]){
            allConditionsMet = false;
        }
    }

    //Step 3: Check No-Preemption. Yes -> Step 4 , No -> Step 5
    /*if(allConditionsMet){

        //If the algorithm No-Preemption is true, the next resource can be assigned
        NoPreemption nopreemption = *new NoPreemption();

        //If the Result, the No-Preemption algorithm is giving equals our expectations
        nopreemption.avoidance_algorithm(copyNeededResources);
        //ToDo .. check no preemption status...

        bool checkNoPreemption = true;
        if(!checkNoPreemption){
            allConditionsMet = false;
        }
    }*/

    return allConditionsMet;
}
