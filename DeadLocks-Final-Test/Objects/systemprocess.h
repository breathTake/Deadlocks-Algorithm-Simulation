#ifndef SYSTEMPROCESS_H
#define SYSTEMPROCESS_H

#include <QList>
#include "Objects/systemresource.h"
#include <QDebug>
#include <random>
#include <QtGlobal>
#include <QVector>
#include <QRandomGenerator>


/**
 * @brief Class represents the processes which use the resources
 */
class SystemProcess
{

private:
    /**
     * @brief name of the process
     * @brief processId (corresponding to name: A = id 1...)
     * @brief neededResources resources the process needs to run
     */
    QString name;
    int processId;
    QList<SystemResource> neededResources;
    int revokedResourceId;

public:
    /**
     * @brief SystemProcess standard constuctor with no parameter
     */
    SystemProcess(){

    };

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
    SystemProcess(QString name,int processId, int maxPrinters, int maxCDs, int maxPlotters, int maxTapeDrives);

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

    int getRevokedResourceId() const{
        return revokedResourceId;
    }

    void setRevokedResourceId(int revokedResourceId){
        this->revokedResourceId = revokedResourceId;
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

    /**
     * @brief moveNeededResourceToBack the needed resource will be placed at the end of the list
     * @param index placed at index
     */
    void moveNeededResourceToBack(int index){
        neededResources.swapItemsAt(index, neededResources.count()-1);
    }

    void shuffleNeededResources(){
        int n = neededResources.size();
        QRandomGenerator rng = QRandomGenerator::securelySeeded();

        for (int i = n - 1; i > 0; --i) {
            int j = rng.bounded(i + 1); // Generate a random index in [0, i]
            std::swap(neededResources[i], neededResources[j]); // Swap the elements at indices i and j
        }

    }

    void printNeededResources(){
        QDebug dbg(QtDebugMsg);
        dbg << "Process " << name << ":" << "\n";
        for(int i = 0; i < neededResources.size(); i++){
            dbg << neededResources.at(i).getName() << " (" << neededResources.at(i).getCount() << "), ";
        }
    }
};

#endif // SYSTEMPROCESS_H
