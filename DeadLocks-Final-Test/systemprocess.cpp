#include "systemprocess.h"


SystemProcess::SystemProcess(QString name,int processId, int min, int max)
{
    this->name = name;
    this->processId = processId;
    assignedResources.append(SystemResource("Printer", 0));
    assignedResources.append(SystemResource("CD-ROM", 0));
    assignedResources.append(SystemResource("Plotter", 0));
    assignedResources.append(SystemResource("TapeDrive", 0));

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

int* SystemProcess::requestResource(const int* &differenceResources_A) const
{
    int indexArray[2] = {-1,-1};
    for(int i = 0; i < neededResources.count(); i++)
    {
        while(neededResources.at(i).getCount() > differenceResources_A[i]){

        }
        int randomCount = rand() % (neededResources.at(i).getCount());
        indexArray[0] = i;
        indexArray[1] = randomCount;
        return indexArray;

    }
    return indexArray;
}
