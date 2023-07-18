#ifndef PROCESSWORKER_H
#define PROCESSWORKER_H

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
    ProcessWorker(SystemProcess processes, int availableResources_E[4], int differenceResources_A[4]);

signals:
    /**
     * @brief resourceReserved
     *        notifies the main thread, that the given resource has been reserved and can not be used anymore
     * @param processID is the ID of the process member to determin the process in the main thread
     * @param resource is the resource ID of the resource that has been reserved
     * @param count is the count of reserved resources
     */
    void resourceReserved(int processID, int resource, int count);

    void waitingForNext();

    /**
     * @brief resourceReleased
     *        notifies the main thread, that the given resource has been released
     * @param processID is the ID of the process member to determin the process in the main thread
     * @param resource is the resource ID of the resource that has been released
     * @param count is the count of released resources
     */
    void resourceReleased(int processID, int resource, int count);

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
     * @brief process is the process of the thread
     */
    int availableResources_E[4];
    int differenceResources_A[4];
    SystemProcess process;
    /**
     * @brief semaphorePrinter regulates how many printers can be used by threads
     * @brief semaphoreCD regulates how many cds can be used by threads
     * @brief semaphorePlotter regulates how many plotters can be used by threads
     * @brief semaphoreTapeDrive regulates how many tape drives can be used by threads
     */
    QSemaphore *semaphorePrinter;
    QSemaphore *semaphoreCD;
    QSemaphore *semaphorePlotter;
    QSemaphore *semaphoreTapeDrive;
};

#endif // PROCESSWORKER_H
