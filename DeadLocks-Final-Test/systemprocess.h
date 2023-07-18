#ifndef SYSTEMPROCESS_H
#define SYSTEMPROCESS_H

#include <QList>
#include "systemresource.h"

class SystemProcess
{

private:
    QString name;
    int processId;

    QList<SystemResource> neededResources;
    QList<SystemResource> assignedResources;

public:
    SystemProcess(){

    };
    SystemProcess(QString name,int processId);
    SystemProcess(QString name,int processId, int min, int max);

    int getProcessId() const{
        return processId;
    }

    void setProcessId(int processId){
        this->processId = processId;
    }


    QString getName() const{
        return name;
    }

    void setName(QString name){
        this->name = name;
    }


    const QList<SystemResource> getNeededResources() const {
        return neededResources;
    }

    void setNeededResources(const QList<SystemResource> neededResources) {
        SystemProcess::neededResources = neededResources;
    }

    const QList<SystemResource> getAssignedResources() const {
        return assignedResources;
    }

    void setAssignedResources(const QList<SystemResource> assignedResources) {
        SystemProcess::assignedResources = assignedResources;
    }

    bool eliminateHoldAndWait(QList<SystemResource> &resources, const QList<int>& counts);
    QList<SystemResource> eliminateCircularWait(QList<SystemResource> neededResources);
    void eliminateNoPreemption(SystemResource resource, int count);
    bool cautiousResourceAllocation(const QList<SystemProcess>& processes, const QList<SystemResource>& resources);

    void print();

signals:

};

#endif // SYSTEMPROCESS_H
