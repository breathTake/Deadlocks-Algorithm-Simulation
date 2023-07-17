#include "systemprocess.h"


SystemProcess::SystemProcess(QString name,int processId, int min, int max)
{
    this->name = name;
    this->processId = processId;



    while(neededResources.count() < 4){
        QList<int> done;
        int randomProcess = rand() % 4;
        int randomResourceCount= rand() % (max - min + 1) + min;

        if(randomProcess == 0 && !done.contains(0)){
            neededResources.append(SystemResource("Printer", randomResourceCount));
            done.append(0);
        } else if(randomProcess == 1 && !done.contains(1)){
            neededResources.append(SystemResource("CD-ROM", randomResourceCount));
            done.append(1);
        } else if(randomProcess == 2 && !done.contains(2)){
            neededResources.append(SystemResource("Plotter", randomResourceCount));
            done.append(2);
        } else if(randomProcess == 3 && !done.contains(3)){
            neededResources.append(SystemResource("TapeDrive", randomResourceCount));
            done.append(3);
        }

    }
}
