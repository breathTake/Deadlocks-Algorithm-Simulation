#ifndef PREEMPTIONWORKER_H
#define PREEMPTIONWORKER_H

#include "qtimer.h"
#include <QObject>

#include <Objects/SystemProcess.h>

class PreemptionWorker : public QObject
{
    Q_OBJECT
public:
    explicit PreemptionWorker(QObject *parent = 0);

public slots:
    void reservationStarted(int processId, int nextResource, int nextCount);
    void reservationFinished(int processId, int nextResource, int nextCount);

    void initTimers();

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
    void revokedProcess(int process, int resourceId);

private:
    QTimer *timerPrinter, *timerCD, *timerPlotter, *timerTapeDrive;
    int nextPrinterResource = -1, nextCDResource = -1,nextPlotterResource = -1, nextTapeDriveResource = -1;
    int nextPrinterCount = 0, nextCDCount = 0, nextPlotterCount = 0, nextTapeDriveCount = 0;
    int processPrinter, processCD, processPlotter, processTapeDrive;
};

#endif // PREEMPTIONWORKER_H