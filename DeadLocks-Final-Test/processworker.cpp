#include "processworker.h"

#include <QSemaphore>
#include <QThread>

ProcessWorker::ProcessWorker(QObject *parent) : QObject(parent)
{

}

void ProcessWorker::requestResource(QList<SystemProcess> processes, int availableResources_E[4], int differenceResources_A[4])
{
    QSemaphore semaphorePrinter(availableResources_E[0]);
    QSemaphore semaphoreCD(availableResources_E[1]);
    QSemaphore semaphorePlotter(availableResources_E[2]);
    QSemaphore semaphoreTapeDrive(availableResources_E[3]);


    int nextResource = -1;
    int countResouce = 0;
    for(int i = 0; i < processes.at(0).getNeededResources().count(); i++)
    {
        while(processes.at(0).getNeededResources().at(i).getCount() > differenceResources_A[i]){

        }
        int randomCount = rand() % (processes.at(0).getNeededResources().at(i).getCount());
        nextResource = i;
        countResouce = randomCount;
    }

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

        emit resouceReserved(processes.at(0).getProcessId(), nextResource, countResouce);

        QThread::sleep(countResouce*2000);

        emit resouceReleased(processes.at(0).getProcessId(), nextResource, countResouce);
    }
}
