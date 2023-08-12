#include "preemptionworker.h"
#include "Objects/ProcessWorker.h"

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
        timerPrinter->start(nextCount * 2 * 1000 + 200);
        processPrinter = processId;
        nextPrinterResource = nextResource;
        nextPrinterCount = nextCount;
        break;
        case 1:
        NoPreemption::slotCDLocked = true;
        if(ProcessWorker::semaphorePrinter->available() < 1){
        }
        qDebug() << "cd started by process" << processId;
        timerCD->start(nextCount * 2 * 1000 + 200);
        processCD = processId;
        nextCDResource = nextResource;
        nextCDCount = nextCount;
        break;
        case 2:
        NoPreemption::slotPlotterLocked = true;
        if(ProcessWorker::semaphorePrinter->available() < 1){
        }
        qDebug() << "plotter started by process" << processId;
        timerPlotter->start(nextCount * 2 * 1000 + 200);
        processPlotter = processId;
        nextPlotterResource = nextResource;
        nextPlotterCount = nextCount;
        break;
        case 3:
        NoPreemption::slotTapeDriveLocked = true;
        if(ProcessWorker::semaphorePrinter->available() < 1){
        }
        qDebug() << "tapedrive started by process" << processId;
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
        qDebug() << "process" << processId << "finished using printer normaly";
        timerPrinter->stop();
        nextPrinterCount = -1;
        break;
        case 1:
        qDebug() << "process" << processId << "finished using cd normaly";
        timerCD->stop();
        nextCDCount = -1;
        break;
        case 2:
        qDebug() << "process" << processId << "finished using plotter normaly";
        timerPlotter->stop();
        nextPlotterCount = -1;
        break;
        case 3:
        qDebug() << "process" << processId << "finished using tapedrive normaly";
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
    ProcessWorker::semaphorePrinter->release(nextPrinterCount);
    emit revokedProcess(processPrinter, nextPrinterResource);
}

void PreemptionWorker::revokeCD(){
    qDebug() << "cd revoked for process" << processCD;
    ProcessWorker::semaphoreCD->release(nextCDCount);
    emit revokedProcess(processPrinter, nextPrinterResource);
}

void PreemptionWorker::revokePlotter(){
    qDebug() << "plotter revoked for process" << processPlotter;
    ProcessWorker::semaphorePlotter->release(nextPlotterCount);
    emit revokedProcess(processPrinter, nextPrinterResource);
}

void PreemptionWorker::revokeTapeDrive(){
    qDebug() << "tapedrive revoked for process" << processTapeDrive;
    ProcessWorker::semaphoreTapeDrive->release(nextTapeDriveCount);
    emit revokedProcess(processPrinter, nextPrinterResource);

}

