#include "eliminatecircularwait.h"

#include <Objects/ProcessWorker.h>


EliminateCircularWait::EliminateCircularWait()
{

}

EliminateCircularWait::~EliminateCircularWait()
{

}

QList<int> EliminateCircularWait::findNextResource(SystemProcess process)
{
    //finding the next Resource and count to be reserved
    QList<int> result;

    //copy of the neededResources list to find the right index because the sorting is local and not in the process list in the worker object
    QList<SystemResource> copyNeededResources = process.getNeededResources();
    //using the avoidance algorithm which sorts the neededResources list
    process.setNeededResources(avoidance_algorithm(process.getNeededResources()));


    //nextResouce is the next resource that should get reserved. If it is -1 the next Resource has either not been found yet or there is no resource left. -5 is the flag that there is no resourc left.
    int nextResource = -1;
    //countResource is the amount of the resource that should be reserved. The Algorithm will try to reserve the amount that is given as count in neededResources of the process
    int countResource = -1;
    //indexResourceList is the index of the nextResource in the neededResources list of process as they are in random order
    int indexResourceList = -1;

    //going through the neededResources list to find the next needed resource
    for(int i = 0; i < process.getNeededResources().count(); i++){

        //the resource has to have a count > 0 but < the over all available resources
        if(process.getNeededResources().at(i).getCount() <= ProcessWorker::availableResources_E[process.getNeededResources().at(i).getResourceId()] && process.getNeededResources().at(i).getCount() > 0){

            //if the next resource was found set the nextResource, countResource and indexResourceList variables
            nextResource = process.getNeededResources().at(i).getResourceId();
            indexResourceList = copyNeededResources.indexOf(process.getNeededResources().at(i));
            countResource = process.getNeededResources().at(i).getCount();
            break;
        } else if(i == process.getNeededResources().count() - 1 && nextResource == -1){
            //in this case there are no resources left to process (all are either 0 or can't be processed because they exceed the over all available resource count
            //no return yet because last resource has to be released
            nextResource = - 5;
            break;
        }
    }

    result.append(nextResource);
    result.append(countResource);
    result.append(indexResourceList);

    return result;
}


QList<SystemResource> EliminateCircularWait::avoidance_algorithm(QList<SystemResource> neededResources)
{
    std::sort(neededResources.begin(), neededResources.end(), [](const SystemResource& a, const SystemResource& b) {
        return a.getResourceId() < b.getResourceId();
    });
    return neededResources;
}
