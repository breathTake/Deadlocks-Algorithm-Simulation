#include "processworker.h"

#include <QThread>
#include <QDebug>
#include <BankiersAlgorithm.h>
#include <NoAvoidanceSimulation.h>

/**
 * @brief semaphorePrinter regulates how many printers can be used by threads
 * @brief semaphoreCD regulates how many cds can be used by threads
 * @brief semaphorePlotter regulates how many plotters can be used by threads
 * @brief semaphoreTapeDrive regulates how many tape drives can be used by threads
 */
QSemaphore *semaphorePrinter;
QSemaphore *semaphoreCD;
QSemaphore *semaphorePlotter;
QSemaphore *semaphoreTapeDrive;
//initializing the static matrices
int ProcessWorker::differenceResources_A[4];
int ProcessWorker::assignedResources_C[3][4];
int ProcessWorker::stillNeededResources_R[3][4];

ProcessWorker::ProcessWorker(SystemProcess process, int availableResources_E[4], int differenceResources_A[4], int selectedAlgorithm)
{
    this->selectedAlgorithm = selectedAlgorithm;
    //"copying" the process belonging to thread with all attributes
    this->process = SystemProcess();
    this->process.setNeededResources(process.getNeededResources());
    this->process.setProcessId(process.getProcessId());
    this->process.setName(process.getName());

    //"copying" the arrays differenceResources_A, availableResources_E and the stillNeededResources_R Matrix to thread
    for(int i = 0; i < 4; i++){
        this->differenceResources_A[i] = differenceResources_A[i];
        this->availableResources_E[i] = availableResources_E[i];
        //resourceID is needet because the still Needed Resources is ordered by resources but the process neededResources list from processes is in random order
        int resourceID  = process.getNeededResources().at(i).getResourceId();
        this->stillNeededResources_R[process.getProcessId()][resourceID] = process.getNeededResources().at(i).getCount();
    }

    //initializing the semaphores
    semaphorePrinter = new QSemaphore(availableResources_E[0]);
    semaphoreCD = new QSemaphore(availableResources_E[1]);
    semaphorePlotter = new QSemaphore(availableResources_E[2]);
    semaphoreTapeDrive = new QSemaphore(availableResources_E[3]);
}

void ProcessWorker::requestResource()
{
    //id of the last resource, if it is -1 there was no resource before this one, if its -5 then all resources have been processed)
    int lastResource = -1;
    //count of the last resource that has been reserved (-1 means there was no resource before)
    int lastCount = -1;
    //deadlock_avoidance_api object
    deadlock_avoidance_api *algorithm;

    //the process works as long as there are still resources left to be processed in neededResources
    while(lastResource != -5){

        //if interruption was requested return
        if(QThread::currentThread()->isInterruptionRequested()){
            qDebug() << "interrupting";
            return;
        }

        //initializing the algorithm with the right one selected at the start (default is no algorithm running it into a deadlock
        switch(selectedAlgorithm){
            default:
                algorithm = new NoAvoidanceSimulation();
        }


        //the findNextResources funtion will be called upon the right algorithm
        QList<int> foundNextResouce = algorithm->findNextResource(process, stillNeededResources_R, assignedResources_C, differenceResources_A, availableResources_E);
        int nextResource = foundNextResouce.at(0);
        int countResource = foundNextResouce.at(1);
        int indexResourceList = foundNextResouce.at(2);


        //resource will be reserved (switching the nextresourc and reserving the proper semaphore + setting the differenceResources_A array;
        if(nextResource != -5){
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
            differenceResources_A[nextResource] -= countResource;
            assignedResources_C[process.getProcessId()][nextResource] += countResource;
            stillNeededResources_R[process.getProcessId()][nextResource] += countResource;
            updateProcess(indexResourceList, process.getNeededResources().at(indexResourceList).getCount() - countResource);
            emit resourceReserved(process.getProcessId(), nextResource, countResource);
        }


        //resources have been acquired, the last resource (from befor) can be released, if they were set
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
            //if nextResource is -5 all resources are processed and finishedResourceProcessing can be emitted
            if(nextResource == -5){
                break;
            }
            //emiiting resourcesReleased to notify mainwindow of changes and change ui
            emit resourceReleased(process.getProcessId(), lastResource, lastCount);

            //updating assignedResources_C because resources have been released
            differenceResources_A[lastResource] += lastCount;
            assignedResources_C[process.getProcessId()][lastResource] -= lastCount;
        }

        //waiting 2*countResource to simulate the resource writing etc.
        QThread::sleep(2*countResource);

        //seting the lastResource and count to current resouce and count to be released in next iteration
        lastResource = nextResource;
        lastCount = countResource;
    }
    emit finishedResourceProcessing(lastResource);
}

//updating the neededResources list by changing the count of the resource at nextResource
void ProcessWorker::updateProcess(int nextResource, int countResource)
{
    QList<SystemResource> resourcesCopy = process.getNeededResources();
    SystemResource resourceCopy = process.getNeededResources().at(nextResource);
    resourceCopy.setCount(countResource);
    resourcesCopy.replace(nextResource, resourceCopy);
    process.setNeededResources(resourcesCopy);
}
