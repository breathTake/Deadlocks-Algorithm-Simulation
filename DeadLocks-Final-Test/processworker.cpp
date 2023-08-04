#include "processworker.h"

#include <QThread>
#include <QDebug>
#include <BankiersAlgorithm.h>

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
int ProcessWorker::assignedResources_C[3][4];
int ProcessWorker::stillNeededResources_R[3][4];

ProcessWorker::ProcessWorker(SystemProcess process, int availableResources_E[4], int differenceResources_A[4])
{
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

    //the process works as long as there are still resources left to be processed in neededResources
    while(lastResource != -5){

        //if interruption was requested return
        if(QThread::currentThread()->isInterruptionRequested()){
            qDebug() << "interrupting";
            return;
        }

        //finding the next Resource and count to be reserved
        //nextResouce is the next resource that should get reserved. If it is -1 the next Resource has either not been found yet or there is no resource left. -5 is the flag that there is no resourc left.
        int nextResource = -1;
        //countResource is the amount of the resource that should be reserved. The Algorithm will try to reserve the amount that is given as count in neededResources of the process
        int countResource = 0;
        //indexResourceList is the index of the nextResourc in the neededResources list of process as they are in random order
        int indexResourceList;

        //going through the neededResources list to find the next needed resource
        for(int i = 0; i < process.getNeededResources().count(); i++){
            //the resource has to have a count > 0 but < the over all available resources
            if(process.getNeededResources().at(i).getCount() <= availableResources_E[process.getNeededResources().at(i).getResourceId()] && process.getNeededResources().at(i).getCount() > 0){
                //if the next resource was found set the nextResource, countResource and indexResourceList variables
                nextResource = process.getNeededResources().at(i).getResourceId();
                indexResourceList = i;
                countResource = process.getNeededResources().at(i).getCount();
                break;
            }
            if(i == process.getNeededResources().count() - 1 && nextResource == -1){
                //in this case there are no resources left to process (all are either 0 or can't be processed because they exeed the over all available resource count
                //no return yet because last resource has to be released
                nextResource = - 5;
            }
        }

        //now that the next resource to be reserved has been found the algorithm(s) will check if it is allowed to do this
        //first the matrices are beeing updated to what they should be after reserving the wanted resources so bankiers can check if the current state is save
        assignedResources_C[process.getProcessId()][nextResource] += countResource;
        stillNeededResources_R[process.getProcessId()][nextResource] -= countResource;
        differenceResources_A[nextResource] -= countResource;

        //debugging
        qDebug() << "process " << process.getProcessId() << " requested " << countResource << " of resource " << nextResource;
        printStillNeeded();

        //new bankiers algorithm object to check if state is save
        BankiersAlgorithm bankier = *new BankiersAlgorithm();
        if(nextResource != -5){
            if(bankier.avoidance_algorithm(stillNeededResources_R, assignedResources_C, differenceResources_A, availableResources_E)){
                //state is save
                qDebug() << "no Deadlock";
            } else {
                //state is not save
                qDebug() << "deadlock";
                assignedResources_C[process.getProcessId()][nextResource] -= countResource;
                stillNeededResources_R[process.getProcessId()][nextResource] += countResource;
                return;
            }
        }
        differenceResources_A[nextResource] += countResource; //change back because it will be changed when aquiring



        //resource will be reserved (switching the nextresourc and reserving the proper semaphore + setting the differenceResources_A array;
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
            //emiiting resourcesReleased to notify mainwindow of changes and change ui
            emit resourceReleased(process.getProcessId(), lastResource, lastCount);

            //updating assignedResources_C because resources have been released
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
