#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ProcessWorker.h>
#include <QThread>
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

//List of the Processes in the Simulation
QList<SystemProcess> processes;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    secondTimer = new QTimer(this);

    //Pixmaps for the Resource tab
    QPixmap Pixmap_Printer_off = QPixmap(":/resources/Printer_off.png");
    ui->Printer_background_label->setPixmap(Pixmap_Printer_off);
    QPixmap Pixmap_CD_off = QPixmap(":/resources/cd_off.png");
    ui->Cd_background_label->setPixmap(Pixmap_CD_off);
    QPixmap Pixmap_Plotter_off = QPixmap(":/resources/plotter_off.png");
    ui->Plotter_background_label->setPixmap(Pixmap_Plotter_off);
    QPixmap Pixmap_Tapedrive_off = QPixmap(":/resources/tapedrive_off.png");
    ui->Tapedrive_background_label->setPixmap(Pixmap_Tapedrive_off);

    //update matrix as it is all 0 at the start
    update_occupation_matrix();
    //seting up processes and resources
    setUpProcesses();
    setUpResources(5,7,6,5);

    //initializing threads and workers
    threadProcessA = new QThread;
    workerA = new ProcessWorker(processes.at(0), availableResources_E, differenceResources_A);
    threadProcessB = new QThread;
    workerB = new ProcessWorker(processes.at(1), availableResources_E, differenceResources_A);
    threadProcessC = new QThread;
    workerC = new ProcessWorker(processes.at(2), availableResources_E, differenceResources_A);


    //connect(ui->button_start_simulation, SIGNAL(clicked()), this, SLOT(run()));
    //connect(secondTimer, SIGNAL(timeout()), this, SLOT(run()));

    //connnecting worker Signals and slots
    connect(ui->button_start_simulation, SIGNAL(clicked()), workerA, SLOT(requestResource()));
    connect(workerA, SIGNAL(resourceReserved(int,int,int)), this, SLOT(reserveResources(int,int,int)));
    connect(workerA, SIGNAL(resourceReleased(int,int,int)), this, SLOT(releaseResources(int,int,int)));
    connect(workerA, SIGNAL(waitingForNext()),this, SLOT(test()));

    //moving and starting threads
    workerA->moveToThread(threadProcessA);
    threadProcessA->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reserveResources(int process, int resource, int count)
{
    //adjusting the occupation matrixes and arrays
    assignedResources_C[process][resource] += count;
    stillNeededResources_R[process][resource] -= count;
    occupiedResources_P[resource] += count;
    differenceResources_A[resource] -= count;

    QPixmap Pixmap_Printer_on = QPixmap(":/resources/Printer_on.png");
    QPixmap Pixmap_CD_on= QPixmap(":/resources/cd_on.png");
    QPixmap Pixmap_Plotter_on= QPixmap(":/resources/plotter_on.png");
    QPixmap Pixmap_TapeDrive_on= QPixmap(":/resources/tapedrive_on.png");

    switch(resource){
    case 0:
        ui->Printer_background_label->setPixmap(Pixmap_Printer_on);
        ui->Printer_label_occupation->setStyleSheet("QLabel { color: rgb(217, 217, 217); font: 500 12pt; background-color : #9cb792; }");
        break;
    case 1:
        ui->Cd_background_label->setPixmap(Pixmap_CD_on);
        ui->Cd_label_occupation->setStyleSheet("QLabel { color: rgb(217, 217, 217); font: 500 12pt; background-color : #9cb792; }");
        break;
    case 2:
        ui->Plotter_background_label->setPixmap(Pixmap_Plotter_on);
        ui->Plotter_label_occupation->setStyleSheet("QLabel { color: rgb(217, 217, 217); font: 500 12pt; background-color : #9cb792; }");
        break;
    case 3:
        ui->Tapedrive_background_label->setPixmap(Pixmap_TapeDrive_on);
        ui->Tapedrive_label_occupation->setStyleSheet("QLabel { color: rgb(217, 217, 217); font: 500 12pt; background-color : #9cb792; }");
        break;
    }



    update_occupation_matrix();
    update_needed_matrix();
    update_resource_occupation();
    update_resource_occupation_list();
}

void MainWindow::releaseResources(int process, int resource, int count)
{
    //adjusting the occupation matrixes and arrays
    assignedResources_C[process][resource] -= count;
    occupiedResources_P[resource] -= count;
    differenceResources_A[resource] += count;

    QPixmap Pixmap_Printer_off = QPixmap(":/resources/Printer_off.png");
    QPixmap Pixmap_CD_off= QPixmap(":/resources/cd_off.png");
    QPixmap Pixmap_Plotter_off= QPixmap(":/resources/plotter_off.png");
    QPixmap Pixmap_TapeDrive_off= QPixmap(":/resources/tapedrive_off.png");

    switch(resource){
    case 0:
        ui->Printer_background_label->setPixmap(Pixmap_Printer_off);
        ui->Printer_label_occupation->setStyleSheet("QLabel { color: rgb(217, 217, 217); font: 500 12pt; background-color : #6a7081; }");
        break;
    case 1:
        ui->Cd_background_label->setPixmap(Pixmap_CD_off);
        ui->Cd_label_occupation->setStyleSheet("QLabel { color: rgb(217, 217, 217); font: 500 12pt; background-color : #6a7081; }");
        break;
    case 2:
        ui->Plotter_background_label->setPixmap(Pixmap_Plotter_off);
        ui->Plotter_label_occupation->setStyleSheet("QLabel { color: rgb(217, 217, 217); font: 500 12pt; background-color : #6a7081; }");
        break;
    case 3:
        ui->Tapedrive_background_label->setPixmap(Pixmap_TapeDrive_off);
        ui->Tapedrive_label_occupation->setStyleSheet("QLabel { color: rgb(217, 217, 217); font: 500 12pt; background-color : #6a7081; }");
        break;
    }

    update_occupation_matrix();
    update_needed_matrix();
    update_resource_occupation();
    update_resource_occupation_list();
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

//updates the occupation matrix GUI
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

//updates the required matrix GUI
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

//updates the free resources info in GUI
void MainWindow::update_resource_occupation()
{
    ui->Printer_label_occupation->setText(QString::number(occupiedResources_P[0]) + "/" + QString::number(availableResources_E[0]));
    ui->Cd_label_occupation->setText(QString::number(occupiedResources_P[1]) + "/" + QString::number(availableResources_E[1]));
    ui->Plotter_label_occupation->setText(QString::number(occupiedResources_P[2]) + "/" + QString::number(availableResources_E[2]));
    ui->Tapedrive_label_occupation->setText(QString::number(occupiedResources_P[3]) + "/" + QString::number(availableResources_E[3]));
}

//update the list which shows the processes using the resource
void MainWindow::update_resource_occupation_list()

{
    QString ListPrinter = "", ListCd = "", ListPlotter = "", ListTapeDrive = "";
    for(int i = 0; i < system_resource_count; i++){
        for(int j = 0; j < system_process_count; j++){
            for(int k = 0; k < assignedResources_C[j][i]; k++){
                if(k == 0 && j == 0){
                    switch(i){
                    case 0:
                        ListPrinter.append(processes.at(j).getName());
                        break;
                    case 1:
                        ListCd.append(processes.at(j).getName());
                        break;
                    case 2:
                        ListPlotter.append(processes.at(j).getName());
                        break;
                    case 3:
                        ListTapeDrive.append(processes.at(j).getName());
                        break;
                    }

                } else{
                    switch(i){
                    case 0:
                        ListPrinter.append(" | ").append(processes.at(j).getName());
                        break;
                    case 1:
                        ListCd.append(" | ").append(processes.at(j).getName());
                        break;
                    case 2:
                        ListPlotter.append(" | ").append(processes.at(j).getName());
                        break;
                    case 3:
                        ListTapeDrive.append(" | ").append(processes.at(j).getName());
                        break;
                    }
                }
            }
        }
    }

    ui->Printer_label_occupation_list->setText(ListPrinter);
    ui->Cd_label_occupation_list->setText(ListCd);
    ui->Plotter_label_occupation_list->setText(ListPlotter);
    ui->Tapedrive_label_occupation_list->setText(ListTapeDrive);
}

//updates the required matrix updateStillNeededRessources_R
void MainWindow::updateStillNeededRessources_R()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            stillNeededResources_R[i][j] = processes.at(i).getNeededResources().at(j).getCount();
        }
    }
    update_needed_matrix();
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
        differenceResources_A[i] = resources.at(i).getCount();
    }

    update_resource_occupation();

    return resources;
}

void MainWindow::setUpProcesses()
{
    processes.append(SystemProcess("A", 0, 1, 5));
    processes.append(SystemProcess("B", 1, 1, 5));
    processes.append(SystemProcess("C", 2, 1, 5));

    updateStillNeededRessources_R();

}

void MainWindow::on_button_stop_simulation_clicked()
{
    threadProcessA->quit();
    threadProcessA->wait();
    delete threadProcessA;
    delete workerA;
    ui->button_start_simulation->setEnabled(true);
    ui->button_stop_simulation->setEnabled(false);
}


void MainWindow::on_button_start_simulation_clicked()
{
    //ui->button_start_simulation->setEnabled(false);
    //ui->button_stop_simulation->setEnabled(true);
}

