#ifndef PREEMPTIONWORKER_H
#define PREEMPTIONWORKER_H

#include "qtimer.h"
#include <QObject>

#include <Objects/SystemProcess.h>

/**
 * @brief The PreemptionWorker class is for the NoPreemption algorithm to have a seperate Thread which can take resources out of other threads
 */
class PreemptionWorker : public QObject
{
    Q_OBJECT
public:
    explicit PreemptionWorker(QObject *parent = 0);


public slots:
    /**
     * @brief reservationStarted Slot when the reservation starts
     * @param processId ID from the called process
     * @param nextResource is the next needed resource
     * @param nextCount count of the next needed resource
     */
    void reservationStarted(int processId, int nextResource, int nextCount);

    /**
     * @brief reservationFinished Slot when the reservation is finished
     * @param processId ID from the called process
     * @param nextResource is the next needed resource
     * @param nextCount count of the next needed resource
     * @param notProcessedYet true if some resources are not proccessed yet
     */
    void reservationFinished(int processId, int nextResource, int nextCount, bool notProcessedYet);

    void initTimers();

    /**
     * @brief revokePrinter When the Printer surpassed the timeslot it will be revoked
     * @brief revokeCD When the CD surpassed the timeslot it will be revoked
     * @brief revokePlotter When the Plotter surpassed the timeslot it will be revoked
     * @brief revokeTapeDrive When the TapeDrive surpassed the timeslot it will be revoked
     */
    void revokePrinter();
    void revokeCD();
    void revokePlotter();
    void revokeTapeDrive();

    bool getTimerPrinterStatus(){
        return timerPrinter->isActive();
    }

    bool getTimerCDStatus(){
        return timerCD->isActive();
    }

    bool getTimerPlotterStatus(){
        return timerPlotter->isActive();
    }

    bool getTimerTapeDriveStatus(){
        return timerTapeDrive->isActive();
    }

signals:
    void resourceReleased(int processID, int resource, int count, bool notProcessedYet);

private:
    QTimer *timerPrinter, *timerCD, *timerPlotter, *timerTapeDrive;
    int nextPrinterResource = -1, nextCDResource = -1,nextPlotterResource = -1, nextTapeDriveResource = -1;
    int nextPrinterCount = 0, nextCDCount = 0, nextPlotterCount = 0, nextTapeDriveCount = 0;
    int processPrinter, processCD, processPlotter, processTapeDrive;
};

#endif // PREEMPTIONWORKER_H
