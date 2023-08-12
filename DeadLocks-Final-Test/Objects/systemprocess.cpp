#include "systemprocess.h"
#include <algorithm>
#include <QDebug>
#include <QRandomGenerator>


SystemProcess::SystemProcess(QString name,int processId)
{
    this->name = name;
    this->processId = processId;
}


SystemProcess::SystemProcess(QString name,int processId, int maxPrinters, int maxCDs, int maxPlotters, int maxTapeDrives)
{
    this->name = name;
    this->processId = processId;

    int randomPrinterCount= QRandomGenerator::global()->bounded(1, maxPrinters);
    int randomCDCount= QRandomGenerator::global()->bounded(1, maxCDs);
    int randomPlotterCount= QRandomGenerator::global()->bounded(1, maxPlotters);
    int randomTapeDriveCount= QRandomGenerator::global()->bounded(1, maxTapeDrives);

    neededResources.append(SystemResource("Printer", 0, randomPrinterCount));
    neededResources.append(SystemResource("CD-ROM", 1, randomCDCount));
    neededResources.append(SystemResource("Plotter", 2, randomPlotterCount));
    neededResources.append(SystemResource("TapeDrive", 3, randomTapeDriveCount));

    shuffleNeededResources();

    QList<int> done;
    int neededResourcesCounter = 0;


    for(int i = 0; i < neededResources.count(); i++){
        qDebug() << "Process " << processId << " has " << neededResources.at(i).getCount() << " " << neededResources.at(i).getName() << "s in List index: " << i;
    }
}





