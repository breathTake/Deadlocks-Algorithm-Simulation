#include "processworker.h"

#include <QSemaphore>
#include <QThread>
#include <QDebug>

QSemaphore semaphorePrinter(0);
QSemaphore semaphoreCD(0);
QSemaphore semaphorePlotter(0);
QSemaphore semaphoreTapeDrive(0);

ProcessWorker::ProcessWorker(SystemProcess process, int availableResources_E[4], int differenceResources_A[4])
{
    for(int i = 0; i < 4; i++){
        this->differenceResources_A[i] = differenceResources_A[i];
        this->availableResources_E[i] = availableResources_E[i];
    }
    this->process = SystemProcess();
    this->process.setAssignedResources(process.getAssignedResources());
    this->process.setNeededResources(process.getNeededResources());
    this->process.setProcessId(process.getProcessId());
    this->process.setName(process.getName());

    semaphorePrinter.release(availableResources_E[0]);
    semaphoreCD.release(availableResources_E[1]);
    semaphorePlotter.release(availableResources_E[2]);
    semaphoreTapeDrive.release(availableResources_E[3]);

}

void ProcessWorker::requestResource()
{
    int nextResource = -1;
    int countResouce = 0;
    for(int i = 0; i < process.getNeededResources().count(); i++)
    {
        if(process.getNeededResources().at(i).getCount() < differenceResources_A[i] && process.getNeededResources().at(i).getCount() > 0){
            nextResource = i;
            countResouce = rand() % process.getNeededResources().at(i).getCount() + 1;
            break;
        }
    }

    qDebug() << "r:" << nextResource << "c:" << countResouce;
    if(nextResource == -1){
        //there are no resources left to request or they dont fit into available resources
    } else {
        switch (nextResource) {
        case 0:
            semaphorePrinter.acquire(countResouce);
        case 1:
            semaphoreCD.acquire(countResouce);
        case 2:
            semaphorePlotter.acquire(countResouce);
        case 3:
            semaphoreTapeDrive.acquire(countResouce);
        default:
            //something went wrong
            return;
        }

        emit resouceReserved(process.getProcessId(), nextResource, countResouce);

        QThread::sleep(countResouce*2000);
        qDebug() << "Printing";

        //Hier muss dann später die nächste resource angefordert werden, dafür code oben in eine schleife packen

        switch (nextResource) {
        case 0:
            semaphorePrinter.release(countResouce);
        case 1:
            semaphoreCD.release(countResouce);
        case 2:
            semaphorePlotter.release(countResouce);
        case 3:
            semaphoreTapeDrive.release(countResouce);
        default:
            //something went wrong
            return;
        }
        emit resouceReleased(process.getProcessId(), nextResource, countResouce);
    }
}
