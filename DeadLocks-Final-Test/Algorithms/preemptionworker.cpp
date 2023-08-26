#include "preemptionworker.h"
#include "Objects/ProcessWorker.h"

int maxWaitTime;


PreemptionWorker::PreemptionWorker(QObject *parent) :
    QObject{parent}
{
    //init the max slot time for the resources
    maxWaitTime = max(max(ProcessWorker::differenceResources_A[0],ProcessWorker::differenceResources_A[1]),max(ProcessWorker::differenceResources_A[2],ProcessWorker::differenceResources_A[3]));
    maxWaitTime *= 2500;
}

void PreemptionWorker::reservationStarted(int processId, int nextResource, int nextCount){
    //when the reservation was startet the coresponding timers have to be startet and the variables have to be saved for the release
    switch(nextResource){
    case 0:
        if(!NoPreemption::slotPrinterLocked){
            NoPreemption::slotPrinterLocked = true;
            timerPrinter->start(maxWaitTime);
            processPrinter = processId;
            nextPrinterResource = nextResource;
            nextPrinterCount = nextCount;
        }
        break;
    case 1:
        if(!NoPreemption::slotCDLocked){
            NoPreemption::slotCDLocked = true;
            timerCD->start(maxWaitTime);
            processCD = processId;
            nextCDResource = nextResource;
            nextCDCount = nextCount;
        }
         break;

    case 2:
        if(!NoPreemption::slotPlotterLocked){
            NoPreemption::slotPlotterLocked = true;
            timerPlotter->start(maxWaitTime);
            processPlotter = processId;
            nextPlotterResource = nextResource;
            nextPlotterCount = nextCount;
        }

        break;
    case 3:
        if(!NoPreemption::slotTapeDriveLocked){
            NoPreemption::slotTapeDriveLocked = true;
            timerTapeDrive->start(maxWaitTime);
            processTapeDrive = processId;
            nextTapeDriveResource = nextResource;
            nextTapeDriveCount = nextCount;
        }

        break;
    }
}

void PreemptionWorker::reservationFinished(int processId, int nextResource, int nextCount, bool notProcessedYet){
    //when the reservation was finished without exeeding the slot time the timers are stoped and no more action needs to be taken
    if(!notProcessedYet){
        switch(nextResource){
            case 0:
            NoPreemption::slotPrinterLocked = false;
            timerPrinter->stop();
            nextPrinterCount = -1;
            break;
            case 1:
            NoPreemption::slotCDLocked = false;
            timerCD->stop();
            nextCDCount = -1;
            break;
            case 2:
            NoPreemption::slotPlotterLocked = false;
            timerPlotter->stop();
            nextPlotterCount = -1;
            break;
            case 3:
            NoPreemption::slotTapeDriveLocked = false;
            timerTapeDrive->stop();
            nextTapeDriveCount = -1;
            break;
        }
    }
}

void PreemptionWorker::initTimers(){
    //initialize the timer objects and set up the connections
    timerPrinter  = new QTimer();
    timerCD = new QTimer();
    timerPlotter = new QTimer();
    timerTapeDrive = new QTimer();

    connect(timerPrinter, SIGNAL(timeout()), this, SLOT(revokePrinter()), Qt::QueuedConnection);
    connect(timerCD, SIGNAL(timeout()), this, SLOT(revokeCD()), Qt::QueuedConnection);
    connect(timerPlotter, SIGNAL(timeout()), this, SLOT(revokePlotter()), Qt::QueuedConnection);
    connect(timerTapeDrive, SIGNAL(timeout()), this, SLOT(revokeTapeDrive()), Qt::QueuedConnection);
}

void PreemptionWorker::revokePrinter(){
    //when the time slot of the printer is oversteped the process will be revoked from using the printer and emit that it was revoked
    ProcessWorker::semaphorePrinter->release(nextPrinterCount);
    switch(processPrinter){
    case 0:
        NoPreemption::lastRevokedProcessA = true;
        break;
    case 1:
        NoPreemption::lastRevokedProcessB = true;
        break;
    case 2:
        NoPreemption::lastRevokedProcessC = true;
        break;
    }
    NoPreemption::slotPrinterLocked = false;
    ProcessWorker::differenceResources_A[nextPrinterResource] += nextPrinterCount;
    ProcessWorker::assignedResources_C[processPrinter][nextPrinterResource] -= nextPrinterCount;
    emit resourceReleased(processPrinter, nextPrinterResource, nextPrinterCount, true);
}

void PreemptionWorker::revokeCD(){
    //when the time slot of the cd is oversteped the process will be revoked from using the cd and emit that it was revoked
    ProcessWorker::semaphoreCD->release(nextCDCount);
    switch(processCD){
    case 0:
        NoPreemption::lastRevokedProcessA = true;
        break;
    case 1:
        NoPreemption::lastRevokedProcessB = true;
        break;
    case 2:
        NoPreemption::lastRevokedProcessC = true;
        break;
    }
    NoPreemption::slotCDLocked = false;
    ProcessWorker::differenceResources_A[nextCDResource] += nextCDCount;
    ProcessWorker::assignedResources_C[processCD][nextCDResource] -= nextCDCount;
    emit resourceReleased(processCD, nextCDResource, nextCDCount, true);
}

void PreemptionWorker::revokePlotter(){
    //when the time slot of the plotter is oversteped the process will be revoked from using the plotter and emit that it was revoked
    ProcessWorker::semaphorePlotter->release(nextPlotterCount);
    switch(processPlotter){
    case 0:
        NoPreemption::lastRevokedProcessA = true;
        break;
    case 1:
        NoPreemption::lastRevokedProcessB = true;
        break;
    case 2:
        NoPreemption::lastRevokedProcessC = true;
        break;
    }
    NoPreemption::slotPlotterLocked = false;
    ProcessWorker::differenceResources_A[nextPlotterResource] += nextPlotterCount;
    ProcessWorker::assignedResources_C[processPlotter][nextPlotterResource] -= nextPlotterCount;
    emit resourceReleased(processPlotter, nextPlotterResource, nextPlotterCount, true);

}

void PreemptionWorker::revokeTapeDrive(){
    //when the time slot of the tapedrive is oversteped the process will be revoked from using the tapedrive and emit that it was revoked
    ProcessWorker::semaphoreTapeDrive->release(nextTapeDriveCount);
    switch(processTapeDrive){
    case 0:
        NoPreemption::lastRevokedProcessA = true;
        break;
    case 1:
        NoPreemption::lastRevokedProcessB = true;
        break;
    case 2:
        NoPreemption::lastRevokedProcessC = true;
        break;
    }
    NoPreemption::slotTapeDriveLocked = false;
    ProcessWorker::differenceResources_A[nextTapeDriveResource] += nextTapeDriveCount;
    ProcessWorker::assignedResources_C[processTapeDrive][nextTapeDriveResource] -= nextTapeDriveCount;
    emit resourceReleased(processTapeDrive, nextTapeDriveResource, nextTapeDriveCount, true);
}

