#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

int countRepititions = 5;
int countRepititionsDone = 0;
int system_resource_count = 4;
int system_process_count = 3;
QTimer *secondTimer;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    secondTimer = new QTimer(this);


    QPixmap Pixmap_Printer_off= QPixmap(":/resources/Printer_off.png");
    ui->Printer_background_label->setPixmap(Pixmap_Printer_off);
    QPixmap Pixmap_CD_off= QPixmap(":/resources/cd_off.png");
    ui->Cd_background_label->setPixmap(Pixmap_CD_off);
    QPixmap Pixmap_Plotter_off= QPixmap(":/resources/plotter_off.png");
    ui->Plotter_background_label->setPixmap(Pixmap_Plotter_off);
    QPixmap Pixmap_Tapedrive_off= QPixmap(":/resources/tapedrive_off.png");
    ui->Tapedrive_background_label->setPixmap(Pixmap_Tapedrive_off);

    int assignedRessources_C[3][4] = {{3, 0, 1, 1},
                                          {0, 1, 0, 0},
                                          {1, 1, 1, 0}};
    int availableRessources_E[4] = {4, 4, 4, 4};
    int occupiedRessources_P[4] = {0, 0, 0, 0};


    update_occupation_matrix(assignedRessources_C);
    update_resource_occupation(availableRessources_E, occupiedRessources_P);

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
}



void MainWindow::on_pushButton_clicked()
{
    QPixmap Pixmap_Printer_on= QPixmap(":/resources/Printer_on.png");
    ui->Printer_background_label->setPixmap(Pixmap_Printer_on);
    ui->Printer_label_occupation->setStyleSheet("QLabel { color: rgb(217, 217, 217); font: 500 12pt; background-color : #9cb792; }");
    secondTimer->start(1000);
}


void MainWindow::update_occupation_matrix(int occupiedResources[3][4])
{
    ui->A1_label_occupation->setNum(occupiedResources[0][0]);
    ui->A2_label_occupation->setNum(occupiedResources[0][1]);
    ui->A3_label_occupation->setNum(occupiedResources[0][2]);
    ui->A4_label_occupation->setNum(occupiedResources[0][3]);
    ui->B1_label_occupation->setNum(occupiedResources[1][0]);
    ui->B2_label_occupation->setNum(occupiedResources[1][1]);
    ui->B3_label_occupation->setNum(occupiedResources[1][2]);
    ui->B4_label_occupation->setNum(occupiedResources[1][3]);
    ui->C1_label_occupation->setNum(occupiedResources[2][0]);
    ui->C2_label_occupation->setNum(occupiedResources[2][1]);
    ui->C3_label_occupation->setNum(occupiedResources[2][2]);
    ui->C4_label_occupation->setNum(occupiedResources[2][3]);
}

void MainWindow::update_resource_occupation(int availableRessources_E[4], int occupiedRessources_P[4])
{
    ui->Printer_label_occupation->setText(QString::number(occupiedRessources_P[0]) + "/" + QString::number(availableRessources_E[0]));
    ui->Cd_label_occupation->setText(QString::number(occupiedRessources_P[1]) + "/" + QString::number(availableRessources_E[1]));
    ui->Plotter_label_occupation->setText(QString::number(occupiedRessources_P[2]) + "/" + QString::number(availableRessources_E[2]));
    ui->Tapedrive_label_occupation->setText(QString::number(occupiedRessources_P[3]) + "/" + QString::number(availableRessources_E[3]));
}

QList<SystemRessource> setUpResources()
{
    QList<SystemRessource> resources;
    return resources;
}

QList<SystemProcess> setUpProcesses()
{
    QList<SystemProcess> processes;
    return processes;
}



