#include "preemptionworker.h"
#include "Objects/ProcessWorker.h"

PreemptionWorker::PreemptionWorker(QObject *parent) :
    QObject{parent}
{

}

void PreemptionWorker::reservationStarted(int processId, int nextResource, int nextCount){
    switch(nextResource){
        case 0:
        timerPrinter->start(nextCount * 2 * 1000 + 200);
        processPrinter = processId;
        nextPrinterResource = nextResource;
        nextPrinterCount = nextCount;
        break;
        case 1:
        timerCD->start(nextCount * 2 * 1000 + 200);
        processCD = processId;
        nextCDResource = nextResource;
        nextCDCount = nextCount;
        break;
        case 2:
        timerPlotter->start(nextCount * 2 * 1000 + 200);
        processPlotter = processId;
        nextPlotterResource = nextResource;
        nextPlotterCount = nextCount;
        break;
        case 3:
        timerTapeDrive->start(nextCount * 2 * 1000 + 200);
        processTapeDrive = processId;
        nextTapeDriveResource = nextResource;
        nextTapeDriveCount = nextCount;
        break;
    }
}

void PreemptionWorker::reservationFinished(int processId, int nextResource, int nextCount){
    switch(nextResource){
        case 0:
        timerPrinter->stop();
        nextPrinterCount = -1;
        break;
        case 1:
        timerCD->stop();
        nextCDCount = -1;
        break;
        case 2:
        timerPlotter->stop();
        nextPlotterCount = -1;
        break;
        case 3:
        timerTapeDrive->stop();
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
    emit revokedProcess(processPrinter, nextPrinterResource);
    NoPreemption::slotPrinterLocked = true;
    ProcessWorker::semaphorePrinter->release(nextPrinterCount);
}

void PreemptionWorker::revokeCD(){
    qDebug() << "cd revoked for process" << processCD;
    emit revokedProcess(processPrinter, nextPrinterResource);
    NoPreemption::slotCDLocked = true;
    ProcessWorker::semaphoreCD->release(nextCDCount);
}

void PreemptionWorker::revokePlotter(){
    qDebug() << "plotter revoked for process" << processPlotter;
    emit revokedProcess(processPrinter, nextPrinterResource);
    NoPreemption::slotPlotterLocked = true;
    ProcessWorker::semaphorePlotter->release(nextPlotterCount);
}

void PreemptionWorker::revokeTapeDrive(){
    qDebug() << "tapedrive revoked for process" << processTapeDrive;
    emit revokedProcess(processPrinter, nextPrinterResource);
    NoPreemption::slotTapeDriveLocked = true;
    ProcessWorker::semaphoreTapeDrive->release(nextTapeDriveCount);
}

