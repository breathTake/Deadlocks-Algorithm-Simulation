#ifndef PROCESSWORKER_H
#define PROCESSWORKER_H

#include "qdebug.h"
#include <QObject>
#include <SystemProcess.h>
#include <systemresource.h>
#include <QSemaphore>

//Q_DECLARE_METATYPE(QList<SystemProcess>)


class ProcessWorker : public QObject
{
    Q_OBJECT
public:
    /**
     * \brief creates ProcessWorker
     *        creates a Process Worker with the given parameters and also initializes the semaphores
     * \param processes is the process belonging to the worker object
     * \param availableResources_E is an int array with 4 ints. Each int corresponds to a resource and how many are available at the start
     * \param differenceResources_A is an int array with 4 ints. Each int corresponds to a resource that is available right now
     */
    ProcessWorker(SystemProcess processes, int availableResources_E[4], int differenceResources_A[4], int selectedAlgorithm);

    /**
     * @brief updateProcess
     * updates the neededResources List in the member Process
     * \param nextResource is the ID of the resource that has been reserved
     * \param countResource is the count of the reserce
     */
    void updateProcess(int nextResource, int countResource);

    /**
     * @brief setUpOccupations used to copy the assignedResources_C and stillNeededResources_R from mainwindow to the threads
     * @param assignedResources_C matrix containing which and how many resources a process is occupying
     * @param stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     */
    void setUpOccupations(int assignedResources_C[3][4], int stillNeededResources_R[3][4]){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 4; j++){
                this->assignedResources_C[i][j] = assignedResources_C[i][j];
                this->stillNeededResources_R[i][j] = stillNeededResources_R[i][j];
            }
        }
    }

    void setAlgorithm(int algorithm){
        this->selectedAlgorithm = algorithm;
    }

    //temporary debug method to check variables
    void printStillNeeded(){
        QDebug dbg(QtDebugMsg);
        dbg << "R:" << "\n";
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 4; j++){
                dbg << stillNeededResources_R[i][j];
            }
            dbg << "\n";
        }
        dbg << "A: " << differenceResources_A[0] << differenceResources_A[1] << differenceResources_A[2] << differenceResources_A[3] << "\n";
    }

signals:
    /**
     * @brief resourceReserved
     *        notifies the main thread, that the given resource has been reserved and can not be used anymore
     * @param processID is the ID of the process member to determin the process in the main thread
     * @param resource is the resource ID of the resource that has been reserved
     * @param count is the count of reserved resources
     */
    void resourceReserved(int processID, int resource, int count);

    //not implemented yet
    void waitingForNext();

    /**
     * @brief resourceReleased
     *        notifies the main thread, that the given resource has been released
     * @param processID is the ID of the process member to determin the process in the main thread
     * @param resource is the resource ID of the resource that has been released
     * @param count is the count of released resources
     */
    void resourceReleased(int processID, int resource, int count);

    //not implemented yet
    void finishedResourceProcessing(int information);

public slots:
    /**
     * @brief requestResource
     *        a slot that will request the resources a process needs until all resources were processed. It will notify the main thread throughout the process about changes in the resource occupation
     */
    void requestResource();

private:
    /**
     * @brief availableResources_E is an array with the over all available resources
     * @brief differenceResources_A is an array with the current available resources
     * @brief assignedResources_C matrix containing which and how many resources a process is occupying
     * @brief stillNeededResources_R matix containing which and how many resources a process will still need to occupie throughout the simulation
     * @brief process is the process of the thread
     * @brief selectedAlgorithmNumber is the algorithm used to prevent deadlocks
     */
    int availableResources_E[4];
    static int differenceResources_A[4];
    static int assignedResources_C[3][4];
    static int stillNeededResources_R[3][4];
    SystemProcess process;
    int selectedAlgorithm;
};

#endif // PROCESSWORKER_H
