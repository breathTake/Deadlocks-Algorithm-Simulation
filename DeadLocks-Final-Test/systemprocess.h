#ifndef SYSTEMPROCESS_H
#define SYSTEMPROCESS_H

#include <QList>
#include "systemresource.h"
#include <QDebug>

class SystemProcess
{

private:
    /**
     * @brief name of the process
     * @brief processId (corresponding to name: A = id 1...)
     * @brief neededResources;
     */
    QString name;
    int processId;

    QList<SystemResource> neededResources;

public:
    /**
     * @brief SystemProcess standard constuctor with no parameter
     */
    SystemProcess(){};

    /**
     * @brief SystemProcess constructor setting name and processID
     * @param name of a process
     * @param processId (corresponding to name: A = id 1...)
     */
    SystemProcess(QString name,int processId);

    /**
     * @brief SystemProcess constructor setting name and processId and filling neededResources with a resource of each type with a count between min and max
     * @param name of a process
     * @param processId (corresponding to name: A = id 1...)
     * @param min the minimum count a resource in neededResources can have
     * @param max the maximum count a resource in neededResources can have
     */
    SystemProcess(QString name,int processId, int min, int max);

    /**
     * @brief getProcessId getter for processId
     * @return processId
     */
    int getProcessId() const{
        return processId;
    }

    /**
     * @brief setProcessId setter for processId
     * @param processId
     */
    void setProcessId(int processId){
        this->processId = processId;
    }


    /**
     * @brief getName getter for name
     * @return name
     */
    QString getName() const{
        return name;
    }

    /**
     * @brief setName setter for name
     * @param name
     */
    void setName(QString name){
        this->name = name;
    }


    /**
     * @brief getNeededResources list of needed resources
     * @return neededResources
     */
    const QList<SystemResource> getNeededResources() const{
        return neededResources;
    }

    /**
     * @brief setNeededResources setting the neededResources list
     * @param neededResources
     */
    void setNeededResources(QList<SystemResource> neededResources) {
        SystemProcess::neededResources = neededResources;
    }

    void moveNeededResourceToBack(int index){
        neededResources.swapItemsAt(index, neededResources.count()-1);
    }

    void printNeededResources(){
        QDebug dbg(QtDebugMsg);
        dbg << "Process " << name << ":" << "\n";
        for(int i = 0; i < neededResources.size(); i++){
            dbg << neededResources.at(i).getName() << " (" << neededResources.at(i).getCount() << "), ";
        }
    }

    //temporary. will be moved to extra classes
    bool eliminateHoldAndWait(QList<SystemResource> &resources, const QList<int>& counts);
    QList<SystemResource> eliminateCircularWait(QList<SystemResource> neededResources);
    void eliminateNoPreemption(SystemResource resource, int count);
    bool cautiousResourceAllocation(const QList<SystemProcess>& processes, const QList<SystemResource>& resources);
};

#endif // SYSTEMPROCESS_H
