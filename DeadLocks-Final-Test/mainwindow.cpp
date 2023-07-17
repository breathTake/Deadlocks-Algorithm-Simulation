#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

//how many times resources should request resources in the simulation
int countRepititions = 5;
int countRepititionsDone = 0;

//how many resources and processes the system has
int system_resource_count = 4;
int system_process_count = 3;

//A Timer object for the resource requests
QTimer *secondTimer;

//The Arrays for occupation etc.
int assignedResources_C[3][4];
int stillNeededResources_R[3][4] = {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}};
int availableResources_E[4];
int occupiedResources_P[4] = {0, 0, 0, 0};
int differenceResources_A[4];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    secondTimer = new QTimer(this);

    //Pixmaps for the Resource tab
    QPixmap Pixmap_Printer_off= QPixmap(":/resources/Printer_off.png");
    ui->Printer_background_label->setPixmap(Pixmap_Printer_off);
    QPixmap Pixmap_CD_off= QPixmap(":/resources/cd_off.png");
    ui->Cd_background_label->setPixmap(Pixmap_CD_off);
    QPixmap Pixmap_Plotter_off= QPixmap(":/resources/plotter_off.png");
    ui->Plotter_background_label->setPixmap(Pixmap_Plotter_off);
    QPixmap Pixmap_Tapedrive_off= QPixmap(":/resources/tapedrive_off.png");
    ui->Tapedrive_background_label->setPixmap(Pixmap_Tapedrive_off);

    update_occupation_matrix();
    setUpProcesses();
    setUpResources(5,7,6,5);

    connect(secondTimer, SIGNAL(timeout()), this, SLOT(run()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::run()
{
    if(countRepititionsDone < countRepititions)
    {
        ui->A1_label_occupation->setNum(countRepititionsDone);
        countRepititionsDone++;
    }
    secondTimer->start(1000);

    /*bool isDeadlock = bankiersAlgorithm();
    if(isDeadlock){
        ui->deadlockIndicator->setText("True");
    }else{
        ui->deadlockIndicator->setText("False");
    }*/
}

bool MainWindow::bankiersAlgorithm()
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++) {
            if(stillNeededResources_R[i][j] <= differenceResources_A[j]) {
                differenceResources_A[j] += assignedResources_C[i][j];
                availableResources_E[j] -= assignedResources_C[i][j];
                stillNeededResources_R[i][j] = 0;
                return true; // kein deadlock
            }
            else {
                return false; // Deadlock
            }
        }
    }
}

void MainWindow::on_button_start_simulation_clicked()
{
    QPixmap Pixmap_Printer_on= QPixmap(":/resources/Printer_on.png");
    ui->Printer_background_label->setPixmap(Pixmap_Printer_on);
    ui->Printer_label_occupation->setStyleSheet("QLabel { color: rgb(217, 217, 217); font: 500 12pt; background-color : #9cb792; }");
    secondTimer->start(1000);
}

void MainWindow::update_occupation_matrix()
{
    ui->A1_label_occupation->setNum(assignedResources_C[0][0]);
    ui->A2_label_occupation->setNum(assignedResources_C[0][1]);
    ui->A3_label_occupation->setNum(assignedResources_C[0][2]);
    ui->A4_label_occupation->setNum(assignedResources_C[0][3]);
    ui->B1_label_occupation->setNum(assignedResources_C[1][0]);
    ui->B2_label_occupation->setNum(assignedResources_C[1][1]);
    ui->B3_label_occupation->setNum(assignedResources_C[1][2]);
    ui->B4_label_occupation->setNum(assignedResources_C[1][3]);
    ui->C1_label_occupation->setNum(assignedResources_C[2][0]);
    ui->C2_label_occupation->setNum(assignedResources_C[2][1]);
    ui->C3_label_occupation->setNum(assignedResources_C[2][2]);
    ui->C4_label_occupation->setNum(assignedResources_C[2][3]);
}

void MainWindow::update_needed_matrix()
{
    ui->A1_label_needed->setNum(stillNeededResources_R[0][0]);
    ui->A2_label_needed->setNum(stillNeededResources_R[0][1]);
    ui->A3_label_needed->setNum(stillNeededResources_R[0][2]);
    ui->A4_label_needed->setNum(stillNeededResources_R[0][3]);
    ui->B1_label_needed->setNum(stillNeededResources_R[1][0]);
    ui->B2_label_needed->setNum(stillNeededResources_R[1][1]);
    ui->B3_label_needed->setNum(stillNeededResources_R[1][2]);
    ui->B4_label_needed->setNum(stillNeededResources_R[1][3]);
    ui->C1_label_needed->setNum(stillNeededResources_R[2][0]);
    ui->C2_label_needed->setNum(stillNeededResources_R[2][1]);
    ui->C3_label_needed->setNum(stillNeededResources_R[2][2]);
    ui->C4_label_needed->setNum(stillNeededResources_R[2][3]);
}

void MainWindow::update_resource_occupation()
{
    ui->Printer_label_occupation->setText(QString::number(occupiedResources_P[0]) + "/" + QString::number(availableResources_E[0]));
    ui->Cd_label_occupation->setText(QString::number(occupiedResources_P[1]) + "/" + QString::number(availableResources_E[1]));
    ui->Plotter_label_occupation->setText(QString::number(occupiedResources_P[2]) + "/" + QString::number(availableResources_E[2]));
    ui->Tapedrive_label_occupation->setText(QString::number(occupiedResources_P[3]) + "/" + QString::number(availableResources_E[3]));
}


QList<SystemResource> MainWindow::setUpResources(int countPrinters, int countCD, int countPlotters, int countTapeDrive)
{
    QList<SystemResource> resources;
    resources.append(SystemResource("Printer", 0, countPrinters));
    resources.append(SystemResource("CD-ROM", 1, countCD));
    resources.append(SystemResource("Plotter", 2, countPlotters));
    resources.append(SystemResource("TapeDrive", 3, countTapeDrive));

    for(int i = 0; i < resources.count(); i++){
        availableResources_E[i] = resources.at(i).getCount();
    }

    update_resource_occupation();

    return resources;
}

QList<SystemProcess> MainWindow::setUpProcesses()
{
    QList<SystemProcess> processes;
    processes.append(SystemProcess("Process A", 0, 1, 5));
    processes.append(SystemProcess("Process B", 1, 1, 5));
    processes.append(SystemProcess("Process C", 2, 1, 5));

    updateStillNeededRessources_R(processes);

    return processes;
}

void MainWindow::updateStillNeededRessources_R(QList<SystemProcess> processes)
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            stillNeededResources_R[i][j] = processes.at(i).getNeededResources().at(j).getCount();
        }
    }
    update_needed_matrix();
}



