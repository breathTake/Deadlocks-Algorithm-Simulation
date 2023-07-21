#include "processworker.h"

#include <QThread>
#include <QDebug>

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
    int lastResource = -1;
    int lastCount = -1;

    int nextResource = -1;
    int countResource = 0;
    int indexResourceList;

    //find the next resource the process needs to use
    for(int i = 0; i < process.getNeededResources().count(); i++)
    {
        //the resource has to have a count > 0 but < the currently free resource count
        if(process.getNeededResources().at(i).getCount() < differenceResources_A[process.getNeededResources().at(i).getResourceId()] && process.getNeededResources().at(i).getCount() > 0){
            nextResource = process.getNeededResources().at(i).getResourceId();
            indexResourceList = i;
            countResource = process.getNeededResources().at(i).getCount();
            break;
        } else{
            nextResource = -1;
        }
    }

    if(nextResource == -1){
        qDebug() << "-1";
        //there are no resources left to request or they dont fit into available resources
    } else {
        //resource will be reserved
        switch (nextResource) {
        case 0:
            semaphorePrinter->acquire(countResource);
            differenceResources_A[0] -= countResource;
            break;
        case 1:
            semaphoreCD->acquire(countResource);
            differenceResources_A[1] -= countResource;
            stillNeededResources_R[1] -= countResource;
            break;
        case 2:
            semaphorePlotter->acquire(countResource);
            differenceResources_A[2] -= countResource;
            stillNeededResources_R[2] -= countResource;
            break;
        case 3:
            semaphoreTapeDrive->acquire(countResource);
            differenceResources_A[3] -= countResource;
            stillNeededResources_R[3] -= countResource;
            break;
        default:
            //something went wrong
            return;
        }
        updateProcess(indexResourceList, process.getNeededResources().at(indexResourceList).getCount() - countResource);

        differenceResources_A[nextResource] -= countResource;
        emit resourceReserved(process.getProcessId(), nextResource, countResource);

        //waiting 2*countResource to simulate the resource writing etc.
        QThread::sleep(2*countResource);

        //Hier muss dann später die nächste resource angefordert werden, dafür code oben in eine schleife packen

        switch (nextResource) {
        case 0:
            semaphorePrinter->release(countResource);
            break;
        case 1:
            semaphoreCD->release(countResource);
            break;
        case 2:
            semaphorePlotter->release(countResource);
            break;
        case 3:
            semaphoreTapeDrive->release(countResource);
            break;
        default:
            return;
        }
        emit resourceReleased(process.getProcessId(), nextResource, countResource);
    }
}

void ProcessWorker::updateProcess(int nextResource, int countResource)
{
    QList<SystemResource> resourcesCopy = process.getNeededResources();
    SystemResource resourceCopy = process.getNeededResources().at(nextResource);
    resourceCopy.setCount(countResource);
    resourcesCopy.replace(nextResource, resourceCopy);
    process.setNeededResources(resourcesCopy);
}
