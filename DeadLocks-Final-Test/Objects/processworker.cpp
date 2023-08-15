#include "processworker.h"

/**
 * @brief semaphorePrinter regulates how many printers can be used by threads
 * @brief semaphoreCD regulates how many cds can be used by threads
 * @brief semaphorePlotter regulates how many plotters can be used by threads
 * @brief semaphoreTapeDrive regulates how many tape drives can be used by threads
 */
QSemaphore* ProcessWorker::semaphorePrinter;
QSemaphore* ProcessWorker::semaphoreCD;
QSemaphore* ProcessWorker::semaphorePlotter;
QSemaphore* ProcessWorker::semaphoreTapeDrive;

int lastResource = -1;
int lastCount = -1;

//initializing the static matrices
int ProcessWorker::differenceResources_A[4];
int ProcessWorker::assignedResources_C[3][4];
int ProcessWorker::stillNeededResources_R[3][4];

ProcessWorker::ProcessWorker(SystemProcess process, int availableResources_E[4], int differenceResources_A[4], int selectedAlgorithm, QObject *parent) :
    QObject(parent)
{
    this->selectedAlgorithm = selectedAlgorithm;
    //"copying" the process belonging to thread with all attributes
    this->process = SystemProcess();
    this->process.setNeededResources(process.getNeededResources());
    this->process.setProcessId(process.getProcessId());
    this->process.setName(process.getName());
    this->process.setRevokedResourceId(process.getRevokedResourceId());

    //"copying" the arrays differenceResources_A, availableResources_E and the stillNeededResources_R Matrix to thread
    for(int i = 0; i < 4; i++){
        this->differenceResources_A[i] = differenceResources_A[i];
        this->availableResources_E[i] = availableResources_E[i];
        //resourceID is needed because the still Needed Resources is ordered by resources but the process neededResources list from processes is in random order
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

    //count of the last resource that has been reserved (-1 means there was no resource before)

    //deadlock_avoidance_api object
    deadlock_avoidance_api *algorithm;
    //initializing the algorithm with the right one selected at the start (default is no algorithm running it into a deadlock
    switch(selectedAlgorithm){
        case 0:
            algorithm = new EliminateHoldAndWait();
            break;
        case 1:
            algorithm = new NoPreemption();
            break;
        case 2:
            algorithm = new EliminateCircularWait();
            break;
        case 3:
            algorithm = new BankiersAlgorithm();
            break;
        default:
            algorithm = new NoAvoidanceSimulation();
            break;
    }

    int nextResource, countResource, indexResourceList;

    //the process works as long as there are still resources left to be processed in neededResources
    while(lastResource != -5 || nextResource == -2){

        //if interruption was requested return
        if(QThread::currentThread()->isInterruptionRequested()){
            qDebug() << "interrupting";
            return;
        }

        //the findNextResources function will be called upon the right algorithm
        QList<int> foundNextResouce = algorithm->findNextResource(process, stillNeededResources_R, assignedResources_C, differenceResources_A, availableResources_E);
        nextResource = foundNextResouce.at(0);
        countResource = foundNextResouce.at(1);
        indexResourceList = foundNextResouce.at(2);
        //process.printNeededResources();


        //if the next Resource doesn't exist it will not be acquired but later the last will still be released
        if(nextResource >= 0){
            emit startedAcquire(process.getProcessId(), nextResource, countResource);
            //resource will be reserved (switching the nextresource and reserving the proper semaphore + setting the differenceResources_A array)
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
            updateProcess(indexResourceList, process.getNeededResources().at(indexResourceList).getCount() - countResource);
            emit resourceReserved(process.getProcessId(), nextResource, countResource);
        }


        //resources have been acquired, the last resource (from before) can be released, if they were set
        if(lastResource != -1 && lastResource != -2 && nextResource != -2 && nextResource != -1){
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

            emit resourceReleased(process.getProcessId(), lastResource, lastCount, false);

            //emitting resourcesReleased to notify mainwindow of changes and change ui

            //updating assignedResources_C because resources have been released
            differenceResources_A[lastResource] += lastCount;
            assignedResources_C[process.getProcessId()][lastResource] -= lastCount;
            //if nextResource is -5 all resources are processed and finishedResourceProcessing can be emitted
            if(nextResource == -5){
                break;
            }
        }

        //waiting 2 * countResource to simulate the resource writing etc.
        if(countResource >= 0){
            QThread::sleep(2*countResource);
        } else {
            QThread::sleep(2);
        }

        //seting the lastResource and count to current resource and count to be released in next iteration
        if(nextResource != -1 && nextResource != -2){
            lastResource = nextResource;
            lastCount = countResource;
        }
    }
    emit finishedResourceProcessing(lastResource);
}

void ProcessWorker::gotRevoked(int process, int resource, int count){
    if(this->process.getProcessId() == process){
        qDebug() << "gotRevoked";
        this->process.setRevokedResourceId(resource);
        differenceResources_A[resource] += count;
        assignedResources_C[process][resource] -= count;
        emit resourceReleased(process, resource, count, true);
        lastCount = 0;
    }
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
