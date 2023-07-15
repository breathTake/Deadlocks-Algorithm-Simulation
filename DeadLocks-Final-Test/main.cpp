#include "mainwindow.h"
#include "systemprocess.h"
#include "systemressource.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

void runSimulation() {
    QList<SystemProcess> processes;
    int processCount = 3;
    QList<SystemRessource> ressources;
    int ressourceCount = 4;

    processes.emplace_back("A", 0, 1, 3);
    processes.emplace_back("B", 1, 1, 6);
    processes.emplace_back("C", 2, 1, 4);

    ressources.emplace_back("Printer", 0, 4);
    ressources.emplace_back("Plotter", 1, 2);
    ressources.emplace_back("CD-ROM", 2, 3);
    ressources.emplace_back("Tape-Drive", 3, 1);

    int availableRessources_E[4] = {ressources.at(0).getCount(), ressources.at(1).getCount(),
                                    ressources.at(2).getCount(), ressources.at(3).getCount()};
    int occupiedRessources_P[4] = {0, 0, 0, 0};
    int differenceRessources_A[4] = {0, 0, 0, 0};

    int stillNeededRessources_R[3][4] = {{processes.at(0).getNeededRessources().at(0).getCount(), processes.at(
                                                                                                               0).getNeededRessources().at(1).getCount(),                                      processes.at(
                                                       0).getNeededRessources().at(2).getCount(),                                      processes.at(
                                                       0).getNeededRessources().at(3).getCount()},
                                         {processes.at(1).getNeededRessources().at(0).getCount(), processes.at(
                                                                                                               1).getNeededRessources().at(1).getCount(), processes.at(
                                                       1).getNeededRessources().at(2).getCount(), processes.at(
                                                       1).getNeededRessources().at(3).getCount()},
                                         {processes.at(2).getNeededRessources().at(0).getCount(), processes.at(
                                                                                                               2).getNeededRessources().at(1).getCount(), processes.at(
                                                       2).getNeededRessources().at(2).getCount(), processes.at(
                                                       2).getNeededRessources().at(3).getCount()}};
    int assignedRessources_C[3][4] = {{0, 0, 0, 0},
                                      {0, 0, 0, 0},
                                      {0, 0, 0, 0}};


    while (std::equal(std::begin(availableRessources_E), std::end(availableRessources_E),
                      std::begin(differenceRessources_A))) {
        int random = rand() % 4;
        int count = rand() % 2;
        if (occupiedRessources_P[random] < availableRessources_E[random]) {
            occupiedRessources_P[random] += count;


        } else {
            continue;
        }

    }

    for (int i = 0; i < processes.size(); i++) {
        processes[i].print();
    }
    qDebug() << "\n";
    for (int i = 0; i < ressources.size(); i++) {
        ressources[i].print();
    }
}
