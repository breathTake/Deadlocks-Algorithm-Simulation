#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ProcessWorker.h>
#include <QProcess>
#include <QApplication>
#include <QThread>
#include <QTime>
#include <QTimer>
#include <StartDialog.h>
#include <EndDialog.h>
#include <QGraphicsDropShadowEffect>

//how many resources and processes the system has
int system_resource_count = 4;
int system_process_count = 3;
int existingResources[4];

//A Timer object updating the timer in ui
QTimer programTimer;

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

    //programTimer = *new QTimer(this);

    //shadow effects for buttons
    QGraphicsDropShadowEffect* effectShadow1 = new QGraphicsDropShadowEffect();
    effectShadow1->setBlurRadius(10);
    effectShadow1->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow1->setOffset(0,2);
    QGraphicsDropShadowEffect* effectShadow2 = new QGraphicsDropShadowEffect();
    effectShadow2->setBlurRadius(10);
    effectShadow2->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow2->setOffset(0,2);
    QGraphicsDropShadowEffect* effectShadow3 = new QGraphicsDropShadowEffect();
    effectShadow3->setBlurRadius(10);
    effectShadow3->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow3->setOffset(0,2);
    ui->button_restart_simulation->setGraphicsEffect(effectShadow1);
    ui->button_start_simulation->setGraphicsEffect(effectShadow2);
    ui->button_stop_simulation->setGraphicsEffect(effectShadow3);

    //Pixmaps for the Resource tab
    QPixmap Pixmap_Printer_off = QPixmap(":/resources/Printer_off.png");
    ui->Printer_background_label->setPixmap(Pixmap_Printer_off);
    QPixmap Pixmap_CD_off = QPixmap(":/resources/cd_off.png");
    ui->Cd_background_label->setPixmap(Pixmap_CD_off);
    QPixmap Pixmap_Plotter_off = QPixmap(":/resources/plotter_off.png");
    ui->Plotter_background_label->setPixmap(Pixmap_Plotter_off);
    QPixmap Pixmap_Tapedrive_off = QPixmap(":/resources/tapedrive_off.png");
    ui->Tapedrive_background_label->setPixmap(Pixmap_Tapedrive_off);


    //Start dialog and setting up resource counts etc.
    StartDialog startDialog;
    connect(&startDialog, SIGNAL(countsFinished(int*)), this, SLOT(initResourceCount(int*)));
    connect(&startDialog, SIGNAL(algorithmsFinished(int)), this, SLOT(selectedAlgorithm(int)));
    startDialog.setWindowTitle("Deadlock Algorithm Simulation");
    if(startDialog.exec() == QDialog::Accepted){
        startDialog.getResourceCount();
        startDialog.getAlgorithm();
    } else if(startDialog.exec() == QDialog::Rejected){
        this->close();
        startDialog.close();
    }

    //update matrix as it is all 0 at the start
    update_occupation_matrix();
    //seting up processes and resources
    setUpProcesses();
    setUpResources(existingResources[0], existingResources[1], existingResources[2], existingResources[3]);

    //initializing threads and workers
    threadProcessA = new QThread;
    workerA = new ProcessWorker(processes.at(0), availableResources_E, differenceResources_A);
    threadProcessB = new QThread;
    workerB = new ProcessWorker(processes.at(1), availableResources_E, differenceResources_A);
    threadProcessC = new QThread;
    workerC = new ProcessWorker(processes.at(2), availableResources_E, differenceResources_A);

    //connect(programTimer, SIGNAL(timeout()), this, SLOT(updateTimeRunning()));

    //connnecting workerAs signals and slots
    connect(ui->button_start_simulation, SIGNAL(clicked()), workerA, SLOT(requestResource()));
    connect(workerA, SIGNAL(resourceReserved(int,int,int)), this, SLOT(reserveResources(int,int,int)));
    connect(workerA, SIGNAL(resourceReleased(int,int,int)), this, SLOT(releaseResources(int,int,int)));


    //connnecting workerBs signals and slots
    connect(ui->button_start_simulation, SIGNAL(clicked()), workerB, SLOT(requestResource()));
    connect(workerB, SIGNAL(resourceReserved(int,int,int)), this, SLOT(reserveResources(int,int,int)));
    connect(workerB, SIGNAL(resourceReleased(int,int,int)), this, SLOT(releaseResources(int,int,int)));

    //connnecting workerCs signals and slots
    connect(ui->button_start_simulation, SIGNAL(clicked()), workerC, SLOT(requestResource()));
    connect(workerC, SIGNAL(resourceReserved(int,int,int)), this, SLOT(reserveResources(int,int,int)));
    connect(workerC, SIGNAL(resourceReleased(int,int,int)), this, SLOT(releaseResources(int,int,int)));

    //moving and starting threads
    workerA->moveToThread(threadProcessA);
    threadProcessA->start();
    workerB->moveToThread(threadProcessB);
    threadProcessB->start();
    workerC->moveToThread(threadProcessC);
    threadProcessC->start();
    //programTimer.start(1000);
    workerA->setUpOccupations(assignedResources_C, stillNeededResources_R);
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
    //bankiersAlgorithm(stillNeededResources_R, assignedResources_C, differenceResources_A, availableResources_E);
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

    if(occupiedResources_P[resource] == 0){
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
    }

    update_occupation_matrix();
    update_needed_matrix();
    update_resource_occupation();
    update_resource_occupation_list();
}

bool MainWindow::bankiersAlgorithm(int stillNeededResources_RCopy[3][4], int assignedResources_CCopy[3][4], int differenceResources_ACopy[4], int availableResources_ECopy[4])
{

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++) {
            if(stillNeededResources_RCopy[i][j] <= differenceResources_ACopy[j]) {
                differenceResources_ACopy[j] += assignedResources_CCopy[i][j];
                availableResources_ECopy[j] -= assignedResources_CCopy[i][j];
                stillNeededResources_RCopy[i][j] = 0;
                return true; // kein deadlock
            }
            else {
                qDebug() << "Deadlock";
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
                switch(i){
                case 0:
                    if(ListPrinter != ""){
                        ListPrinter.append(" | ");
                    }
                    ListPrinter.append(processes.at(j).getName());
                    break;
                case 1:
                    if(ListCd != ""){
                        ListCd.append(" | ");
                    }
                    ListCd.append(processes.at(j).getName());
                    break;
                case 2:
                    if(ListPlotter != ""){
                        ListPlotter.append(" | ");
                    }
                    ListPlotter.append(processes.at(j).getName());
                    break;
                case 3:
                    if(ListTapeDrive != ""){
                        ListTapeDrive.append(" | ");
                    }
                    ListTapeDrive.append(processes.at(j).getName());
                    break;
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
            int resourceID  = processes.at(i).getNeededResources().at(j).getResourceId();
            stillNeededResources_R[i][resourceID] = processes.at(i).getNeededResources().at(j).getCount();
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
    /*processes.append(SystemProcess("A", 0, false));
    processes.append(SystemProcess("B", 1, false));
    processes.append(SystemProcess("C", 2, false));*/
    processes.append(SystemProcess("A", 0, 1, 2));
    processes.append(SystemProcess("B", 1, 1, 2));
    processes.append(SystemProcess("C", 2, 1, 2));

    updateStillNeededRessources_R();

}

void MainWindow::on_button_stop_simulation_clicked()
{
    /*threadProcessA->deleteLater();
    threadProcessA->quit();
    threadProcessA->wait();
    delete threadProcessA;
    delete workerA;

    threadProcessB->deleteLater();
    threadProcessB->quit();
    threadProcessB->wait();
    delete threadProcessB;
    delete workerB;

    threadProcessC->deleteLater();
    threadProcessC->quit();
    threadProcessC->wait();
    delete threadProcessC;
    delete workerC;*/

    qDebug() << "deleted threads";
    EndDialog endDialog;
    endDialog.setWindowTitle("Deadlock Algorithm Simulation");
    endDialog.exec();
}


void MainWindow::on_button_start_simulation_clicked()
{
    ui->button_start_simulation->setEnabled(false);
    //ui->button_stop_simulation->setEnabled(true);
}

void MainWindow::updateTimeRunning()
{
    //ui->time_running_lcd_number->display(ui->time_running_lcd_number->intValue() + 1);
}

void MainWindow::initResourceCount(int* resourcesCounts)
{
    existingResources[0] = resourcesCounts[0];
    existingResources[1] = resourcesCounts[1];
    existingResources[2] = resourcesCounts[2];
    existingResources[3] = resourcesCounts[3];
}

void MainWindow::selectedAlgorithm(int algorithm){
    //qDebug() << "algorithm: " << algorithm;
}


//restarting the application
void MainWindow::on_button_restart_simulation_clicked()
{
    // Restart the application
    QApplication::quit();

#ifdef Q_OS_WIN
    // Restart the application on Windows
    QProcess::startDetached(QApplication::applicationFilePath());
#elif defined(Q_OS_MACOS)
    // Restart the application on macOS
    QStringList arguments = QApplication::arguments();
    arguments.removeFirst(); // Remove the current executable from the arguments
    QProcess::startDetached(QApplication::applicationFilePath(), arguments);
#else
    // Restart the application on other platforms (Linux, etc.)
    // You may need to implement a platform-specific method for other operating systems.
#endif
}

