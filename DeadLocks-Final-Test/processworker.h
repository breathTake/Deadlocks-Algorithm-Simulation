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
    explicit ProcessWorker(QObject *parent = nullptr);

signals:
    void resouceReserved(int processID, int resouce, int count);
    void waitingForNext();
    void resouceReleased(int processID, int resouce, int count);

public slots:
    void requestResource(QList<SystemProcess> processes, int availableResources_E[4], int differenceResources_A[4]);
};

#endif // PROCESSWORKER_H
