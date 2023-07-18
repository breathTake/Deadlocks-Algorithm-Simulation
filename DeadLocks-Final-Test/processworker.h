#ifndef PROCESSWORKER_H
#define PROCESSWORKER_H

#include <QObject>
#include <SystemProcess.h>
#include <systemresource.h>

//Q_DECLARE_METATYPE(QList<SystemProcess>)


class ProcessWorker : public QObject
{
    Q_OBJECT
public:
    ProcessWorker(SystemProcess processes, int availableResources_E[4], int differenceResources_A[4]);

signals:
    void resouceReserved(int processID, int resouce, int count);
    void waitingForNext();
    void resouceReleased(int processID, int resouce, int count);

public slots:
    void requestResource();
private:
    int availableResources_E[4];
    int differenceResources_A[4];
    SystemProcess process;
};

#endif // PROCESSWORKER_H
