#include "preemptionworker.h"
#include "Objects/ProcessWorker.h"

int maxWaitTime = 4200;
/*QMutex *mutexPrinter = new QMutex();
QMutex *mutexCD= new QMutex();
QMutex *mutexPlotter = new QMutex();
QMutex *mutexTapeDrive = new QMutex();*/


PreemptionWorker::PreemptionWorker(QObject *parent) :
    QObject{parent}
{

}

void PreemptionWorker::reservationStarted(int processId, int nextResource, int nextCount){
    switch(nextResource){
        case 0:
        NoPreemption::slotPrinterLocked = true;
        if(ProcessWorker::semaphorePrinter->available() < 1){

        }
        qDebug() << "printer started by process" << processId;
        timerPrinter->start(timerPrinter->remainingTime() + maxWaitTime);
        processPrinter = processId;
        nextPrinterResource = nextResource;
        nextPrinterCount = nextCount;
        break;
        case 1:
        NoPreemption::slotCDLocked = true;
        if(ProcessWorker::semaphorePrinter->available() < 1){
        }
        qDebug() << "cd started by process" << processId;
        timerCD->start(timerCD->remainingTime() + maxWaitTime);
        processCD = processId;
        nextCDResource = nextResource;
        nextCDCount = nextCount;
        break;
        case 2:
        NoPreemption::slotPlotterLocked = true;
        if(ProcessWorker::semaphorePrinter->available() < 1){
        }
        qDebug() << "plotter started by process" << processId;
        timerPlotter->start(timerPlotter->remainingTime() + maxWaitTime);
        processPlotter = processId;
        nextPlotterResource = nextResource;
        nextPlotterCount = nextCount;
        break;
        case 3:
        NoPreemption::slotTapeDriveLocked = true;
        if(ProcessWorker::semaphorePrinter->available() < 1){
        }
        qDebug() << "tapedrive started by process" << processId;
        timerTapeDrive->start(timerTapeDrive->remainingTime() + maxWaitTime);
        processTapeDrive = processId;
        nextTapeDriveResource = nextResource;
        nextTapeDriveCount = nextCount;
        break;
    }
}

void PreemptionWorker::reservationFinished(int processId, int nextResource, int nextCount){
    switch(nextResource){
        case 0:
        NoPreemption::slotPrinterLocked = false;
        qDebug() << "process" << processId << "finished using printer normaly";
        if(timerPrinter->remainingTime() - maxWaitTime <= 0){
            timerPrinter->stop();
        } else {
            timerPrinter->start(timerPrinter->remainingTime() - maxWaitTime);
        }
        nextPrinterCount = -1;
        break;
        case 1:
        NoPreemption::slotCDLocked = false;
        qDebug() << "process" << processId << "finished using cd normaly";
        if(timerCD->remainingTime() - maxWaitTime <= 0){
            timerCD->stop();
        } else {
            timerCD->start(timerCD->remainingTime() - maxWaitTime);
        }
        nextCDCount = -1;
        break;
        case 2:
        NoPreemption::slotPlotterLocked = false;
        qDebug() << "process" << processId << "finished using plotter normaly";
        if(timerPlotter->remainingTime() - maxWaitTime <= 0){
            timerPlotter->stop();
        } else {
            timerPlotter->start(timerPlotter->remainingTime() - maxWaitTime);
        }
        nextPlotterCount = -1;
        break;
        case 3:
        NoPreemption::slotTapeDriveLocked = false;
        qDebug() << "process" << processId << "finished using tapedrive normaly";
        if(timerTapeDrive->remainingTime() - maxWaitTime <= 0){
            timerTapeDrive->stop();
        } else {
            timerTapeDrive->start(timerTapeDrive->remainingTime() - maxWaitTime);
        }
        nextTapeDriveCount = -1;
        break;
    }
}

void PreemptionWorker::initTimers(){
    qDebug() << "initialized timers";
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
    qDebug() << "printer revoked for process" << processPrinter;

    ProcessWorker::semaphorePrinter->release(nextPrinterCount);
    switch(processPrinter){
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
    NoPreemption::slotPrinterLocked = false;
    emit revokedProcess(processPrinter, nextPrinterResource);
}

void PreemptionWorker::revokeCD(){
    qDebug() << "cd revoked for process" << processCD;

    ProcessWorker::semaphoreCD->release(nextCDCount);
    switch(processCD){
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
    NoPreemption::slotCDLocked = false;
    emit revokedProcess(processPrinter, nextPrinterResource);
}

void PreemptionWorker::revokePlotter(){
    qDebug() << "plotter revoked for process" << processPlotter;

    ProcessWorker::semaphorePlotter->release(nextPlotterCount);
    switch(processPlotter){
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
    NoPreemption::slotPlotterLocked = false;
    emit revokedProcess(processPrinter, nextPrinterResource);
}

void PreemptionWorker::revokeTapeDrive(){
    qDebug() << "tapedrive revoked for process" << processTapeDrive;
    ProcessWorker::semaphoreTapeDrive->release(nextTapeDriveCount);
    switch(processTapeDrive){
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
    NoPreemption::slotTapeDriveLocked = false;
    emit revokedProcess(processPrinter, nextPrinterResource);

}

