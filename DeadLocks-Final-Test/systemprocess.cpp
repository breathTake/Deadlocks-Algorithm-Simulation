#include "systemprocess.h"
#include <algorithm>
#include <QDebug>
#include <QRandomGenerator>

//TestConstructor to produce deadlocks
SystemProcess::SystemProcess(QString name,int processId, bool f)
{
    this->name = name;
    this->processId = processId;
    assignedResources.append(SystemResource("Printer", 0));
    assignedResources.append(SystemResource("CD-ROM", 0));
    assignedResources.append(SystemResource("Plotter", 0));
    assignedResources.append(SystemResource("TapeDrive", 0));

    if(processId == 0){
        neededResources.append(SystemResource("CD-ROM", 3));
        neededResources.append(SystemResource("Printer", 3));
        neededResources.append(SystemResource("Plotter", 3));
        neededResources.append(SystemResource("TapeDrive", 3));
    } else if(processId == 1){
        neededResources.append(SystemResource("Printer", 3));
        neededResources.append(SystemResource("CD-ROM", 3));
        neededResources.append(SystemResource("Plotter", 3));
        neededResources.append(SystemResource("TapeDrive", 3));
    } else if(processId == 2){
        neededResources.append(SystemResource("Printer", 3));
        neededResources.append(SystemResource("Plotter", 3));
        neededResources.append(SystemResource("CD-ROM", 3));
        neededResources.append(SystemResource("TapeDrive", 3));
    }


    for(int i = 0; i < neededResources.count(); i++){
        qDebug() << "Process " << processId << " has " << neededResources.at(i).getCount() << " " << neededResources.at(i).getName() << "s in List index: " << i;
    }
}

SystemProcess::SystemProcess(QString name,int processId)
{
    this->name = name;
    this->processId = processId;
}


SystemProcess::SystemProcess(QString name,int processId, int min, int max)
{
    this->name = name;
    this->processId = processId;
    assignedResources.append(SystemResource("Printer", 0));
    assignedResources.append(SystemResource("CD-ROM", 0));
    assignedResources.append(SystemResource("Plotter", 0));
    assignedResources.append(SystemResource("TapeDrive", 0));

    QList<int> done;
    int neededResourcesCounter = 0;

    //Problem: hier wird davon ausgegangen, dass jeder Prozess die reihenfolge der resourcen einhält, was oft nicht der fall ist.
    while(neededResourcesCounter < 4){

        int randomProcess = QRandomGenerator::global()->bounded(0, 4);
        int randomResourceCount= QRandomGenerator::global()->bounded(min, max);
        //= rand() % (max - min + 1) + min;

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
    }

    for(int i = 0; i < neededResources.count(); i++){
        qDebug() << "Process " << processId << " has " << neededResources.at(i).getCount() << " " << neededResources.at(i).getName() << "s in List index: " << i;
    }
}

/*
 * eliminateHoldAndWait
 *
 * @resources: Resources a process needs
 * @counts:    number of Resources, wich are available
 *
 * If all resources are available, the function returns true
 */
bool SystemProcess::eliminateHoldAndWait(QList<SystemResource> &resources, const QList<int>& counts)
{
        // Überprüfen, ob genügend Ressourcen vorhanden sind
        for (int i = 0; i < resources.size(); ++i)
        {
            if (resources[i].getCount() < counts[i])
            {
                // Nicht genügend Ressourcen vorhanden, Hold and Wait verhindern
                return false;
            }
        }

        // Alle Ressourcen sind verfügbar, Ressourcen anfordern
        for (int i = 0; i < resources.size(); ++i)
        {
            resources[i].setCount(resources[i].getCount()-counts[i]);
        }

        // Weitere Aktionen durchführen, da die Ressourcen zugewiesen wurden
        return true;
}


/*
 * eliminateCircularWait
 *
 * @neededResources: Resources the process wants
 *
 * Sorts the neededResources from a Process by their id number to
 * prevent a Circular Wait
 *
 * return: sorted QList
 */
QList<SystemResource> SystemProcess::eliminateCircularWait(QList<SystemResource> neededResources)
{
    std::sort(neededResources.begin(), neededResources.end(), [](const SystemResource& a, const SystemResource& b) {
        return a.getResourceId() < b.getResourceId();
    });
    return neededResources;
}


/*
 *
 * eliminateNoPreemption
 *
 * @resource: The resource which should be requested
 * @count:    The number of available resources of the same type
 *
 *
 *
 */
void SystemProcess::eliminateNoPreemption(SystemResource resource, int count)
{
    // Überprüfen, ob ausreichend Ressourcen vorhanden sind
    if (resource.getCount() >= count)
    {
        // Ressourcen zuweisen
        resource.setCount(count-1);
        // Weitere Aktionen durchführen, da die Ressourcen zugewiesen wurden

        //...
    }
    else
    {
        // Ressourcen nicht ausreichend vorhanden, Handhabung der No-Preemption-Bedingung
        // Hier kannst du verschiedene Ansätze verwenden:
        // - Warteschlange: Prozess in Warteschlange einreihen, bis Ressourcen verfügbar sind
        // - Priorisierung: Prozesse mit höherer Priorität bevorzugen
        // - Blockierung: Prozess blockieren und später erneut versuchen, Ressourcen anzufordern
        // Implementiere hier deine gewünschte Logik entsprechend der No-Preemption-Anforderung
    }
}

/*
 * cautiousResourceAllocation
 *
 * @processes: list of SystemProcesses
 * @resources: list of Resources the processes need
 *
 * Cautious checking the availability of resources
 *
 */

bool SystemProcess::cautiousResourceAllocation(const QList<SystemProcess>& processes, const QList<SystemResource>& resources)
{
    // Make a copy of available resources to track changes
    QList<SystemResource> availableResources = resources;

    for (const SystemProcess& process : processes)
    {
        // Check that the process can request all the resources it needs at once
        if (process.getNeededResources().size() != availableResources.size())
        {
            return false;
        }

        // Chat that enought resources are available
        for (const SystemResource& neededResource : process.getNeededResources())
        {
            // Double check that the resources in the avalaibleResources are really available
            auto it = std::find_if(availableResources.begin(), availableResources.end(), [&](const SystemResource& availableResource) {
                return availableResource.getName() == neededResource.getName();
            });

            if (it == availableResources.end() || it->getCount() < neededResource.getCount())
            {
                return false;
            }
        }

        // Allocate resources for the process as they are available
        for (const SystemResource& neededResource : process.getNeededResources())
        {
            auto it = std::find_if(availableResources.begin(), availableResources.end(), [&](const SystemResource& availableResource) {
                return availableResource.getName() == neededResource.getName();
            });

            it->decreaseCount(neededResource.getCount());
        }
    }

    // All resource requirements have been met and allocated
    return true;
}





