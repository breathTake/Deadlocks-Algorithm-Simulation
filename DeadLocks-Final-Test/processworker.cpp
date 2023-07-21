#include "processworker.h"

#include <QThread>
#include <QDebug>

QSemaphore *semaphorePrinter;
QSemaphore *semaphoreCD;
QSemaphore *semaphorePlotter;
QSemaphore *semaphoreTapeDrive;

ProcessWorker::ProcessWorker(SystemProcess process, int availableResources_E[4], int differenceResources_A[4])
{
    this->process = SystemProcess();
    this->process.setAssignedResources(process.getAssignedResources());
    this->process.setNeededResources(process.getNeededResources());
    this->process.setProcessId(process.getProcessId());
    this->process.setName(process.getName());

    for(int i = 0; i < 4; i++){
        this->differenceResources_A[i] = differenceResources_A[i];
        this->availableResources_E[i] = availableResources_E[i];
        int resourceID  = process.getNeededResources().at(i).getResourceId();
        this->stillNeededResources_R[resourceID] = process.getNeededResources().at(i).getCount();
    }

    semaphorePrinter = new QSemaphore(availableResources_E[0]);
    semaphoreCD = new QSemaphore(availableResources_E[1]);
    semaphorePlotter = new QSemaphore(availableResources_E[2]);
    semaphoreTapeDrive = new QSemaphore(availableResources_E[3]);
}

void ProcessWorker::requestResource()
{
    int lastResource = -1; //-1: not yet set, -5: all resources 0
    int lastCount = -1;


    while(lastResource != -5){
        //find next resouce and count
        int nextResource = -1;
        int countResource = 0;
        int indexResourceList;

        for(int i = 0; i < process.getNeededResources().count(); i++){
            //the resource has to have a count > 0 but < the currently free resource count
            if(process.getNeededResources().at(i).getCount() <= differenceResources_A[process.getNeededResources().at(i).getResourceId()] && process.getNeededResources().at(i).getCount() > 0){
                nextResource = process.getNeededResources().at(i).getResourceId();
                indexResourceList = i;
                countResource = process.getNeededResources().at(i).getCount();
                break;
            }
            if(i == process.getNeededResources().count() - 1 && nextResource == -1){
                nextResource = - 5;
            }
        }

        //resource will be reserved
        switch (nextResource) {
        case 0:
            semaphorePrinter->acquire(countResource);
            break;
        case 1:
            semaphoreCD->acquire(countResource);
            break;
        case 2:
            semaphorePlotter->acquire(countResource);
            break;
        case 3:
            semaphoreTapeDrive->acquire(countResource);
            break;
        }

        //update the occupation array and process list
        updateProcess(indexResourceList, process.getNeededResources().at(indexResourceList).getCount() - countResource);
        differenceResources_A[nextResource] -= countResource;
        emit resourceReserved(process.getProcessId(), nextResource, countResource);

        //resources have been acquired, last resource can be released
        if(lastResource != -1){
            switch (lastResource) {
            case 0:
                semaphorePrinter->release(lastCount);
                break;
            case 1:
                semaphoreCD->release(lastCount);
                break;
            case 2:
                semaphorePlotter->release(lastCount);
                break;
            case 3:
                semaphoreTapeDrive->release(lastCount);
                break;
            }
            emit resourceReleased(process.getProcessId(), lastResource, lastCount);
        }

        //waiting 2*countResource to simulate the resource writing etc.
        QThread::sleep(2*countResource);
        lastResource = nextResource;
        lastCount = countResource;

    }

    emit finishedResourceProcessing(lastResource);
}

void ProcessWorker::updateProcess(int nextResource, int countResource)
{
    QList<SystemResource> resourcesCopy = process.getNeededResources();
    SystemResource resourceCopy = process.getNeededResources().at(nextResource);
    resourceCopy.setCount(countResource);
    resourcesCopy.replace(nextResource, resourceCopy);
    process.setNeededResources(resourcesCopy);
}
