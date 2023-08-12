#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Objects/ProcessWorker.h>
#include <QProcess>
#include <QApplication>
#include <QThread>
#include <QTime>
#include <QTimer>
#include <Dialogs/StartDialog.h>
#include <Dialogs/EndDialog.h>
#include <QGraphicsDropShadowEffect>
#include <QFont>

//how many resources and processes the system has
int maxResourcesInProcess;
int system_resource_count = 4;
int system_process_count = 3;
int existingResources[4];
int selectedAlgorithmNumber = -1;
int finished = 0;

QTimer *timer;

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

    //shadow effects for buttons
    setShadows();

    //fonts
    QFontDatabase::addApplicationFont(":/resources/fonts/futuraHeavy.ttf");
    QFontDatabase::addApplicationFont(":/resources/fonts/futuraBook.ttf");

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

    setUpResources(existingResources[0], existingResources[1], existingResources[2], existingResources[3]);
    setUpProcesses();

    //initializing threads and workers
    threadProcessA = new QThread;
    workerA = new ProcessWorker(processes.at(0), availableResources_E, differenceResources_A, selectedAlgorithmNumber);
    threadProcessB = new QThread;
    workerB = new ProcessWorker(processes.at(1), availableResources_E, differenceResources_A, selectedAlgorithmNumber);
    threadProcessC = new QThread;
    workerC = new ProcessWorker(processes.at(2), availableResources_E, differenceResources_A, selectedAlgorithmNumber);

    //Set the Algorithm Label to the current one
    switch(selectedAlgorithmNumber){
    case 0:
        ui->CurrentAlgorithm_label->setText("Hold And Wait");
        break;
    case 1:
        ui->CurrentAlgorithm_label->setText("No Preemption");
        threadPreemption = new QThread;
        preemptionWorker = new PreemptionWorker();
        preemptionWorker->moveToThread(threadPreemption);
        QMetaObject::invokeMethod(preemptionWorker, "initTimers");

        connect(workerA, SIGNAL(startedAcquire(int, int, int)), preemptionWorker, SLOT(reservationStarted(int, int, int)));
        connect(workerA, SIGNAL(resourceReleased(int,int,int)), preemptionWorker, SLOT(reservationFinished(int,int,int)));
        connect(workerB, SIGNAL(startedAcquire(int, int, int)), preemptionWorker, SLOT(reservationStarted(int, int, int)));
        connect(workerB, SIGNAL(resourceReleased(int,int,int)), preemptionWorker, SLOT(reservationFinished(int,int,int)));
        connect(workerC, SIGNAL(startedAcquire(int, int, int)), preemptionWorker, SLOT(reservationStarted(int, int, int)));
        connect(workerC, SIGNAL(resourceReleased(int,int,int)), preemptionWorker, SLOT(reservationFinished(int,int,int)));

        connect(preemptionWorker, SIGNAL(revokedProcess(int, int)), workerA, SLOT(gotRevoked(int, int)));
        connect(preemptionWorker, SIGNAL(revokedProcess(int, int)), workerB, SLOT(gotRevoked(int, int)));
        connect(preemptionWorker, SIGNAL(revokedProcess(int, int)), workerC, SLOT(gotRevoked(int, int)));

        qDebug() << "Main Thread:" << QThread::currentThreadId();
        threadPreemption->start();
        break;
    case 2:
        ui->CurrentAlgorithm_label->setText("Circular Wait");
        break;
    case 3:
        ui->CurrentAlgorithm_label->setText("Bankiers Algorithm");
        break;
    default:
        ui->CurrentAlgorithm_label->setText("No Avoidance");
        break;
    }

    //connect(programTimer, SIGNAL(timeout()), this, SLOT(updateTimeRunning()));

    //connnecting workerAs signals and slots
    connect(ui->button_start_simulation, SIGNAL(clicked()), workerA, SLOT(requestResource()));
    connect(workerA, SIGNAL(resourceReserved(int,int,int)), this, SLOT(reserveResources(int,int,int)));
    connect(workerA, SIGNAL(resourceReleased(int,int,int)), this, SLOT(releaseResources(int,int,int)));
    connect(workerA, SIGNAL(finishedResourceProcessing(int)),this, SLOT(processFinished()));


    //connnecting workerBs signals and slots
    connect(ui->button_start_simulation, SIGNAL(clicked()), workerB, SLOT(requestResource()));
    connect(workerB, SIGNAL(resourceReserved(int,int,int)), this, SLOT(reserveResources(int,int,int)));
    connect(workerB, SIGNAL(resourceReleased(int,int,int)), this, SLOT(releaseResources(int,int,int)));
    connect(workerB, SIGNAL(finishedResourceProcessing(int)),this, SLOT(processFinished()));

    //connnecting workerCs signals and slots
    connect(ui->button_start_simulation, SIGNAL(clicked()), workerC, SLOT(requestResource()));
    connect(workerC, SIGNAL(resourceReserved(int,int,int)), this, SLOT(reserveResources(int,int,int)));
    connect(workerC, SIGNAL(resourceReleased(int,int,int)), this, SLOT(releaseResources(int,int,int)));
    connect(workerC, SIGNAL(finishedResourceProcessing(int)),this, SLOT(processFinished()));

    //moving and starting threads
    workerA->moveToThread(threadProcessA);
    threadProcessA->start();
    workerB->moveToThread(threadProcessB);
    threadProcessB->start();
    workerC->moveToThread(threadProcessC);
    threadProcessC->start();

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

    QString logMessage = QString("The Process %1 reserved %2 of the resource %3").arg(process).arg(count).arg(resource);
    ui->plainTextEdit_RequestInfo->appendPlainText(logMessage);

    switch(resource){
    case 0:
        ui->Printer_background_label->setStyleSheet("QLabel {background-color: rgb(156, 183, 146); border-radius: 5px; }");
        break;
    case 1:
        ui->Cd_background_label->setStyleSheet("QLabel {background-color: rgb(156, 183, 146); border-radius: 5px; }");
        break;
    case 2:
        ui->Plotter_background_label->setStyleSheet("QLabel {background-color: rgb(156, 183, 146); border-radius: 5px; }");
        break;
    case 3:
        ui->Tapedrive_background_label->setStyleSheet("QLabel {background-color: rgb(156, 183, 146); border-radius: 5px; }");
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

    if(occupiedResources_P[resource] == 0){
        switch(resource){
        case 0:
            ui->Printer_background_label->setStyleSheet("QLabel { background-color: rgb(106, 112, 129); border-radius: 5px; }");
            break;
        case 1:
            ui->Cd_background_label->setStyleSheet("QLabel { background-color: rgb(106, 112, 129); border-radius: 5px; }");
            break;
        case 2:
            ui->Plotter_background_label->setStyleSheet("QLabel { background-color: rgb(106, 112, 129); border-radius: 5px; }");
            break;
        case 3:
            ui->Tapedrive_background_label->setStyleSheet("QLabel { background-color: rgb(106, 112, 129); border-radius: 5px; }");
            break;
        }
    }

    update_occupation_matrix();
    update_needed_matrix();
    update_resource_occupation();
    update_resource_occupation_list();
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

    //set up processes
    processes.append(SystemProcess("A", 0, countPrinters + 1, countCD + 1, countPlotters + 1, countTapeDrive + 1));
    processes.append(SystemProcess("B", 1, countPrinters + 1, countCD + 1, countPlotters + 1, countTapeDrive + 1));
    processes.append(SystemProcess("C", 2, countPrinters + 1, countCD + 1, countPlotters + 1, countTapeDrive + 1));

    updateStillNeededRessources_R();

    return resources;
}

void MainWindow::setUpProcesses()
{


    //updateStillNeededRessources_R();
}

void MainWindow::processFinished()
{
    finished++;
    if(finished == 3){
        threadProcessA->deleteLater();
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
        delete workerC;
        timer->stop();

        EndDialog endDialog;
        endDialog.setWindowTitle("Deadlock Algorithm Simulation");
        endDialog.exec();
    }
}

void MainWindow::on_button_stop_simulation_clicked()
{
    threadProcessA->deleteLater();
    threadProcessA->terminate();
    threadProcessA->wait();
    delete threadProcessA;
    delete workerA;

    threadProcessB->deleteLater();
    threadProcessB->terminate();
    threadProcessB->wait();
    delete threadProcessB;
    delete workerB;

    threadProcessC->deleteLater();
    threadProcessC->terminate();
    threadProcessC->wait();
    delete threadProcessC;
    delete workerC;
    timer->stop();

    EndDialog endDialog;
    endDialog.setWindowTitle("Deadlock Algorithm Simulation");
    endDialog.exec();
}


void MainWindow::on_button_start_simulation_clicked()
{
    //on start button clicked the button will be disabled and the timer will be started
    ui->button_start_simulation->setEnabled(false);
    timer = new QTimer(this);
        QTime startTime = QTime::currentTime();
        connect(timer, &QTimer::timeout, [this, startTime]() {
            updateElapsedTime(startTime);
            timer->start(10);
        });

        timer->start(10);
}

void MainWindow::updateElapsedTime(const QTime &startTime)
{
    //function updating the time label with the elapsed time in fitting format
    QTime currentTime = QTime::currentTime();
    int elapsedMilliseconds = startTime.msecsTo(currentTime);
    int minutes = elapsedMilliseconds / 60000;
    int seconds = (elapsedMilliseconds % 60000) / 1000;
    int milliseconds = elapsedMilliseconds % 1000;

    QString formattedTime = QString("%1:%2:%3")
                            .arg(minutes, 2, 10, QChar('0'))
                            .arg(seconds, 2, 10, QChar('0'))
                            .arg(milliseconds, 3, 10, QChar('0'));

    ui->label_time->setText(formattedTime);
}

void MainWindow::initResourceCount(int* resourcesCounts)
{
    existingResources[0] = resourcesCounts[0];
    existingResources[1] = resourcesCounts[1];
    existingResources[2] = resourcesCounts[2];
    existingResources[3] = resourcesCounts[3];
}

void MainWindow::selectedAlgorithm(int algorithm){
    selectedAlgorithmNumber = algorithm;
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

void MainWindow::setShadows()
{
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
    QGraphicsDropShadowEffect* effectShadow4 = new QGraphicsDropShadowEffect();
    effectShadow4->setBlurRadius(10);
    effectShadow4->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow4->setOffset(0,2);
    QGraphicsDropShadowEffect* effectShadow5 = new QGraphicsDropShadowEffect();
    effectShadow5->setBlurRadius(10);
    effectShadow5->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow5->setOffset(0,2);
    QGraphicsDropShadowEffect* effectShadow6 = new QGraphicsDropShadowEffect();
    effectShadow6->setBlurRadius(10);
    effectShadow6->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow6->setOffset(0,2);
    QGraphicsDropShadowEffect* effectShadow7 = new QGraphicsDropShadowEffect();
    effectShadow7->setBlurRadius(10);
    effectShadow7->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow7->setOffset(0,2);
    QGraphicsDropShadowEffect* effectShadow8 = new QGraphicsDropShadowEffect();
    effectShadow8->setBlurRadius(10);
    effectShadow8->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow8->setOffset(0,2);
    QGraphicsDropShadowEffect* effectShadow9 = new QGraphicsDropShadowEffect();
    effectShadow9->setBlurRadius(10);
    effectShadow9->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow9->setOffset(0,2);
    QGraphicsDropShadowEffect* effectShadow10 = new QGraphicsDropShadowEffect();
    effectShadow10->setBlurRadius(10);
    effectShadow10->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow10->setOffset(0,2);
    QGraphicsDropShadowEffect* effectShadow11 = new QGraphicsDropShadowEffect();
    effectShadow11->setBlurRadius(10);
    effectShadow11->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow11->setOffset(0,2);
    ui->button_restart_simulation->setGraphicsEffect(effectShadow1);
    ui->button_start_simulation->setGraphicsEffect(effectShadow2);
    ui->button_stop_simulation->setGraphicsEffect(effectShadow3);
    ui->Printer_label_occupation_list->setGraphicsEffect(effectShadow4);
    ui->Cd_label_occupation_list->setGraphicsEffect(effectShadow5);
    ui->Plotter_label_occupation_list->setGraphicsEffect(effectShadow6);
    ui->Tapedrive_label_occupation_list->setGraphicsEffect(effectShadow7);
    ui->Printer_background_label->setGraphicsEffect(effectShadow8);
    ui->Cd_background_label->setGraphicsEffect(effectShadow9);
    ui->Plotter_background_label->setGraphicsEffect(effectShadow10);
    ui->Tapedrive_background_label->setGraphicsEffect(effectShadow11);
}
