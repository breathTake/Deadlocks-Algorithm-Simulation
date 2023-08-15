#include "preemptionworker.h"
#include "Objects/ProcessWorker.h"

int maxWaitTime = 4200;


PreemptionWorker::PreemptionWorker(QObject *parent) :
    QObject{parent}
{

}

void PreemptionWorker::reservationStarted(int processId, int nextResource, int nextCount){
    switch(nextResource){
    case 0:
        NoPreemption::slotPrinterLocked = true;

        qDebug() << "printer started by process" << processId;

        timerPrinter->start(timerPrinter->remainingTime() + maxWaitTime);
        processPrinter = processId;
        nextPrinterResource = nextResource;
        nextPrinterCount = nextCount;
        break;
    case 1:
        NoPreemption::slotCDLocked = true;
        qDebug() << "cd started by process" << processId;
        timerCD->start(timerCD->remainingTime() + maxWaitTime);
        processCD = processId;
        nextCDResource = nextResource;
        nextCDCount = nextCount;
        break;
    case 2:
        NoPreemption::slotPlotterLocked = true;

        qDebug() << "plotter started by process" << processId;
        timerPlotter->start(timerPlotter->remainingTime() + maxWaitTime);
        processPlotter = processId;
        nextPlotterResource = nextResource;
        nextPlotterCount = nextCount;
        break;
    case 3:
        NoPreemption::slotTapeDriveLocked = true;

        qDebug() << "tapedrive started by process" << processId;
        timerTapeDrive->start(timerTapeDrive->remainingTime() + maxWaitTime);
        processTapeDrive = processId;
        nextTapeDriveResource = nextResource;
        nextTapeDriveCount = nextCount;
        break;
    }
}

void PreemptionWorker::reservationFinished(int processId, int nextResource, int nextCount, bool notProcessedYet){
    if(!notProcessedYet){
        switch(nextResource){
            case 0:
            NoPreemption::slotPrinterLocked = false;
            qDebug() << "process" << processId << "finished using printer normaly";
            timerPrinter->stop();
            nextPrinterCount = -1;
            break;
            case 1:
            NoPreemption::slotCDLocked = false;
            qDebug() << "process" << processId << "finished using cd normaly";
            timerCD->stop();
            nextCDCount = -1;
            break;
            case 2:
            NoPreemption::slotPlotterLocked = false;
            qDebug() << "process" << processId << "finished using plotter normaly";
            timerPlotter->stop();
            nextPlotterCount = -1;
            break;
            case 3:
            NoPreemption::slotTapeDriveLocked = false;
            qDebug() << "process" << processId << "finished using tapedrive normaly";
            timerTapeDrive->stop();
            nextTapeDriveCount = -1;
            break;
        }
    }
}

void PreemptionWorker::initTimers(){
    qDebug() << "initialized timers";
    timerPrinter  = new QTimer();
    timerCD = new QTimer();
    timerPlotter = new QTimer();
    timerTapeDrive = new QTimer();

    connect(timerPrinter, SIGNAL(timeout()), this, SLOT(revokePrinter()));
    connect(timerCD, SIGNAL(timeout()), this, SLOT(revokeCD()));
    connect(timerPlotter, SIGNAL(timeout()), this, SLOT(revokePlotter()));
    connect(timerTapeDrive, SIGNAL(timeout()), this, SLOT(revokeTapeDrive()));
}

void PreemptionWorker::revokePrinter(){
    qDebug() << "printer revoked for process" << processPrinter;

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
    emit revokedProcess(processPrinter, nextPrinterResource);
}

void PreemptionWorker::revokeCD(){
    qDebug() << "cd revoked for process" << processCD;

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
    emit revokedProcess(processCD, nextCDResource);
}

void PreemptionWorker::revokePlotter(){
    qDebug() << "plotter revoked for process" << processPlotter;

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
    emit revokedProcess(processPlotter, nextPlotterResource);
}

void PreemptionWorker::revokeTapeDrive(){
    qDebug() << "tapedrive revoked for process" << processTapeDrive;
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
    emit revokedProcess(processTapeDrive, nextTapeDriveResource);

}

