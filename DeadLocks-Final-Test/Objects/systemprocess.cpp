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

    std::random_shuffle(neededResources.begin(), neededResources.end());

    QList<int> done;
    int neededResourcesCounter = 0;

    /*//the neededResources List will be filled with 4 Resources (1 of each) in a random order
    while(neededResourcesCounter < 4){

        int randomProcess = QRandomGenerator::global()->bounded(0, 4);
        int randomResourceCount= QRandomGenerator::global()->bounded(min, max);

        if(randomProcess == 0 && !done.contains(0)){
            neededResources.append(SystemResource("Printer", 0, randomResourceCount));
            done.append(0);
        } else if(randomProcess == 1 && !done.contains(1)){
            neededResources.append(SystemResource("CD-ROM", 1, randomResourceCount));
            done.append(1);
        } else if(randomProcess == 2 && !done.contains(2)){
            neededResources.append(SystemResource("Plotter", 2, randomResourceCount));
            done.append(2);
        } else if(randomProcess == 3 && !done.contains(3)){
            neededResources.append(SystemResource("TapeDrive", 3, randomResourceCount));
            done.append(3);
        }
        neededResourcesCounter = neededResources.count();
    }*/

    for(int i = 0; i < neededResources.count(); i++){
        qDebug() << "Process " << processId << " has " << neededResources.at(i).getCount() << " " << neededResources.at(i).getName() << "s in List index: " << i;
    }
}





