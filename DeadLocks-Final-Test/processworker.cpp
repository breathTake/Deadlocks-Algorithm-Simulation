#include "processworker.h"

#include <QThread>
#include <QDebug>

ProcessWorker::ProcessWorker(SystemProcess process, int availableResources_E[4], int differenceResources_A[4])
{
    for(int i = 0; i < 4; i++){
        this->differenceResources_A[i] = differenceResources_A[i];
        this->availableResources_E[i] = availableResources_E[i];
    }
    this->process = SystemProcess();
    this->process.setAssignedResources(process.getAssignedResources());
    this->process.setNeededResources(process.getNeededResources());
    this->process.setProcessId(process.getProcessId());
    this->process.setName(process.getName());

    semaphorePrinter = new QSemaphore(availableResources_E[0]);
    semaphoreCD = new QSemaphore(availableResources_E[1]);
    semaphorePlotter = new QSemaphore(availableResources_E[2]);
    semaphoreTapeDrive = new QSemaphore(availableResources_E[3]);

}

void ProcessWorker::requestResource()
{
    int nextResource = -1;
    int countResource = 0;

    //find the next resource the process needs to use
    for(int i = 0; i < process.getNeededResources().count(); i++)
    {
        //the resource has to have a count > 0 but < the currently free resource count
        if(process.getNeededResources().at(i).getCount() < differenceResources_A[i] && process.getNeededResources().at(i).getCount() > 0){
            nextResource = i;
            countResource = rand() % process.getNeededResources().at(i).getCount() + 1;
            break;
        }
    }


    if(nextResource == -1){
        //there are no resources left to request or they dont fit into available resources
    } else {
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
        default:
            //something went wrong
            return;
        }

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
        qDebug() << "nach release" << semaphorePrinter->available();
        emit resourceReleased(process.getProcessId(), nextResource, countResource);
    }
}
