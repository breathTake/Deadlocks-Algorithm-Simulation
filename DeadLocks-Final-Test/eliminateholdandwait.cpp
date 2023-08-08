#include "eliminateholdandwait.h"
#include "nopreemption.h"
#include <QDebug>

EliminateHoldAndWait::EliminateHoldAndWait()
{

}

QList<int> EliminateHoldAndWait::findNextResource(SystemProcess process, int stillNeededResources_RCopy[3][4], int assignedResources_CCopy[3][4], int differenceResources_ACopy[4], int availableResources_ECopy[4]){

    QList<int> result;

    //nextResouce is the next resource that should get reserved. If it is -1 the next Resource has either not been found yet or there is no resource left. -5 is the flag that there is no resourc left.
    int nextResource = -1;
    //countResource is the amount of the resource that should be reserved. The Algorithm will try to reserve the amount that is given as count in neededResources of the process
    int countResource = -1;
    //indexResourceList is the index of the nextResource in the neededResources list of process as they are in random order
    int indexResourceList = -1;

    //Step 1: Copy of neededResources
    QList<SystemResource> copyNeededResources =  process.getNeededResources();

    //Steop 2: Check if enough Resources are available. If NOT -> Step 5
    bool allConditionsMet = true;
    for(int i = 0 ; i <copyNeededResources.count(); i++){
        if(copyNeededResources.at(i).getCount()> availableResources_ECopy[i] && process.getNeededResources().at(i).getCount() > 0){
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


    //Step 4: Get nextResource
    if(allConditionsMet){

        //going through the neededResources list to find the next needed resource
        for(int i = 0; i < process.getNeededResources().count(); i++){

            //if the next resource was found set the nextResource, countResource and indexResourceList variables
            nextResource = process.getNeededResources().at(i).getResourceId();
            indexResourceList = copyNeededResources.indexOf(process.getNeededResources().at(i));
            countResource = process.getNeededResources().at(i).getCount();

            result.append(nextResource);
            result.append(countResource);
            result.append(indexResourceList);
        }


    }


    //Step 5: No Resource found (Not enough resources OR No-Preemption not fulfilled)
    if(!allConditionsMet){
        //Deadlock found
        result = {-2};
    }

    //Step 6: Return the list of Values
    qDebug() << "Result: Process " << process.getProcessId() << " reserved Resource " << nextResource;
    return result;
}

QList<SystemResource> EliminateHoldAndWait::avoidance_algorithm(QList<SystemResource> neededResources)
{
    std::sort(neededResources.begin(), neededResources.end(), [](const SystemResource& a, const SystemResource& b) {
        return a.getResourceId() < b.getResourceId();
    });
    return neededResources;
}
