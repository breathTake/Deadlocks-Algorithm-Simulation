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
    int lastResource = -1;
    //count of the last resource that has been reserved (-1 means there was no resource before)
    int lastCount = -1;
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
            qDebug() << "bankiers";
            break;
        default:
            algorithm = new NoAvoidanceSimulation();
            qDebug() << "none";
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

        qDebug()<< "find next Resource process"<< process.getName() << ":" << countResource << "of resource" << nextResource;
        //process.printNeededResources();

        //if the next Resource doesn't exist it will not be acquired
        if(nextResource >= 0){
            bool hasBeenEmitted = false;
            //problem: startet acquire countdown auch wenn resource garnicht belegt werden kann
            //resource will be reserved (switching the nextresource and reserving the proper semaphore + setting the differenceResources_A array)
            switch (nextResource) {
            case 0:
                if(semaphorePrinter->available() >= countResource){
                    emit startedAcquire(process.getProcessId(), nextResource, countResource);
                    qDebug() << "\nstart Acquire" << process.getName() << countResource << "of resource" << nextResource << ",semaphores are:" << semaphorePrinter->available() << semaphoreCD->available() << semaphorePlotter->available() << semaphoreTapeDrive->available();
                    hasBeenEmitted = true;
                }
                semaphorePrinter->acquire(countResource);
                break;
            case 1:
                if(semaphoreCD->available() >= countResource){
                    emit startedAcquire(process.getProcessId(), nextResource, countResource);
                    qDebug() << "\nstart Acquire" << process.getName() << countResource << "of resource" << nextResource << ",semaphores are:" << semaphorePrinter->available() << semaphoreCD->available() << semaphorePlotter->available() << semaphoreTapeDrive->available();
                    hasBeenEmitted = true;
                }
                semaphoreCD->acquire(countResource);
                break;
            case 2:
                if(semaphorePlotter->available() >= countResource){
                    emit startedAcquire(process.getProcessId(), nextResource, countResource);
                    qDebug() << "\nstart Acquire" << process.getName() << countResource << "of resource" << nextResource << ",semaphores are:" << semaphorePrinter->available() << semaphoreCD->available() << semaphorePlotter->available() << semaphoreTapeDrive->available();
                    hasBeenEmitted = true;
                }
                semaphorePlotter->acquire(countResource);
                break;
            case 3:
                if(semaphoreTapeDrive->available() >= countResource){
                    emit startedAcquire(process.getProcessId(), nextResource, countResource);
                    qDebug() << "\nstart Acquire" << process.getName() << countResource << "of resource" << nextResource << ",semaphores are:" << semaphorePrinter->available() << semaphoreCD->available() << semaphorePlotter->available() << semaphoreTapeDrive->available();
                    hasBeenEmitted = true;
                }
                semaphoreTapeDrive->acquire(countResource);
                break;
            }

            if(!hasBeenEmitted){
                emit startedAcquire(process.getProcessId(), nextResource, countResource);
                qDebug() << "\nstart Acquire" << process.getName() << countResource << "of resource" << nextResource << ",semaphores are:" << semaphorePrinter->available() << semaphoreCD->available() << semaphorePlotter->available() << semaphoreTapeDrive->available();
            }

            //update the occupation array and process list
            emit resourceReserved(process.getProcessId(), nextResource, countResource);
            differenceResources_A[nextResource] -= countResource;
            assignedResources_C[process.getProcessId()][nextResource] += countResource;
            updateProcess(indexResourceList, process.getNeededResources().at(indexResourceList).getCount() - countResource);
        }

        if(lastResource >= 0){
            if((NoPreemption::lastRevokedProcessA && process.getProcessId() == 0) || (NoPreemption::lastRevokedProcessB && process.getProcessId() == 1) || (NoPreemption::lastRevokedProcessC && process.getProcessId() == 2)){

                emit resourceReleased(process.getProcessId(), lastResource, lastCount, true);

                //emitting resourcesReleased to notify mainwindow of changes and change ui

                //updating assignedResources_C because resources have been released
                qDebug() << "last Count:" << lastCount << "of resource" << lastResource;
                differenceResources_A[lastResource] += lastCount;
                assignedResources_C[process.getProcessId()][lastResource] -= lastCount;
                updateProcess(indexResourceList, process.getNeededResources().at(indexResourceList).getCount() + countResource);
                stillNeededResources_R[process.getProcessId()][lastResource] += lastCount;
                qDebug() << "shuffled and changed back";
                process.shuffleNeededResources();


                switch(process.getProcessId()){
                case 0:
                    NoPreemption::lastRevokedProcessA = false;
                    break;
                case 1:
                    NoPreemption::lastRevokedProcessB = false;
                    break;
                case 2:
                    NoPreemption::lastRevokedProcessC = false;
                    break;
                }

                lastResource = -1;
                lastCount = -1;

                qDebug() << "difference:" << differenceResources_A[0] << differenceResources_A[1] << differenceResources_A[2] << differenceResources_A[3];
            }
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
        qDebug() << "end of the loop for process:" << process.getName();
    }
    emit finishedResourceProcessing(lastResource);
}

void ProcessWorker::gotRevoked(int process, int resource){
    if(this->process.getProcessId() == process){
        //qDebug() << "gotRevoked";
        //this->process.setRevokedResourceId(resource);
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
