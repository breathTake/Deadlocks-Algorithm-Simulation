#include "processworker.h"

#include <QThread>
#include <QDebug>
#include <BankiersAlgorithm.h>

QSemaphore *semaphorePrinter;
QSemaphore *semaphoreCD;
QSemaphore *semaphorePlotter;
QSemaphore *semaphoreTapeDrive;
int ProcessWorker::assignedResources_C[3][4];
int ProcessWorker::stillNeededResources_R[3][4];

ProcessWorker::ProcessWorker(SystemProcess process, int availableResources_E[4], int differenceResources_A[4])
{
    //memset(assignedResources_C, 0, 12);
    //memset(stillNeededResources_R, 0, 12);
    this->process = SystemProcess();
    this->process.setAssignedResources(process.getAssignedResources());
    this->process.setNeededResources(process.getNeededResources());
    this->process.setProcessId(process.getProcessId());
    this->process.setName(process.getName());

    for(int i = 0; i < 4; i++){
        this->differenceResources_A[i] = differenceResources_A[i];
        this->availableResources_E[i] = availableResources_E[i];
        int resourceID  = process.getNeededResources().at(i).getResourceId();
        this->stillNeededResources_R[process.getProcessId()][resourceID] = process.getNeededResources().at(i).getCount();
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
        if(QThread::currentThread()->isInterruptionRequested()){
            qDebug() << "interrupting";
            return;
        }
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

        assignedResources_C[process.getProcessId()][nextResource] += countResource;
        stillNeededResources_R[process.getProcessId()][nextResource] -= countResource;
        differenceResources_A[nextResource] -= countResource;
        qDebug() << "process " << process.getProcessId() << " requested " << countResource << " of resource " << nextResource;
        printStillNeeded();
        //next the selected algorithm will do its thing to prevent a deadlock
        BankiersAlgorithm bankier = *new BankiersAlgorithm();
        if(nextResource != -5){
            if(bankier.avoidance_algorithm(stillNeededResources_R, assignedResources_C, differenceResources_A, availableResources_E)){
                qDebug() << "no Deadlock";
            } else {
                qDebug() << "deadlock";
                assignedResources_C[process.getProcessId()][nextResource] -= countResource;
                stillNeededResources_R[process.getProcessId()][nextResource] += countResource;
                return;
            }
        }
        differenceResources_A[nextResource] += countResource;

        //resource will be reserved
        switch (nextResource) {
        case 0:
            semaphorePrinter->acquire(countResource);
            if(semaphorePrinter->available() < 0){
                differenceResources_A[nextResource] = 0;
            } else {
                differenceResources_A[nextResource] = semaphorePrinter->available();
            }
            break;
        case 1:
            semaphoreCD->acquire(countResource);
            if(semaphorePrinter->available() < 0){
                differenceResources_A[nextResource] = 0;
            } else {
                differenceResources_A[nextResource] = semaphoreCD->available();
            }
            break;
        case 2:
            semaphorePlotter->acquire(countResource);
            if(semaphorePrinter->available() < 0){
                differenceResources_A[nextResource] = 0;
            } else {
                differenceResources_A[nextResource] = semaphorePlotter->available();
            }
                break;
        case 3:
            semaphoreTapeDrive->acquire(countResource);
            if(semaphorePrinter->available() < 0){
                differenceResources_A[nextResource] = 0;
            } else {
                differenceResources_A[nextResource] = semaphoreTapeDrive->available();
            }
            break;
        }

        //update the occupation array and process list
        updateProcess(indexResourceList, process.getNeededResources().at(indexResourceList).getCount() - countResource);
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
            assignedResources_C[process.getProcessId()][lastResource] -= lastCount;
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
