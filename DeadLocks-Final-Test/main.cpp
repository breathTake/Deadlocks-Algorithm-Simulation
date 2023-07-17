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

bool bankiersAlgorithm(int stillNeededRessources_R[3][4], int assignedRessources_C[3][4], int availableRessources_E[4], int occupiedRessources_P[4] , int differenceRessources_A[4]) {
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++) {
            if(stillNeededRessources_R[i][j] <= differenceRessources_A[j]) {
                differenceRessources_A[j] += assignedRessources_C[i][j];
                availableRessources_E[j] -= assignedRessources_C[i][j];
                stillNeededRessources_R[i][j] = 0;
                return true; // kein deadlock
            }
            else {
                return false; // Deadlock
            }
        }
    }
}

