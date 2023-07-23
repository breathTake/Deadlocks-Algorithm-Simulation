#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <SystemResource.h>
#include <SystemProcess.h>
#include <ProcessWorker.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<SystemResource> setUpResources(int countPrinters, int countCD, int countPlotters, int countTapeDrive);
    void setUpProcesses();

private slots:
    //UI update slots
    void update_occupation_matrix();
    void update_needed_matrix();
    void update_resource_occupation();
    void update_resource_occupation_list();
    void updateTimeRunning();

    //update variables when occupation changed
    void updateStillNeededRessources_R();

    //thread slots
    void reserveResources(int process, int resource, int count);
    void releaseResources(int process, int resource, int count);

    //button slots
    void on_button_stop_simulation_clicked();

    void on_button_start_simulation_clicked();

private:
    Ui::MainWindow *ui;
    bool bankiersAlgorithm(int stillNeededResources_RCopy[3][4], int assignedResources_CCopy[3][4], int differenceResources_ACopy[4], int availableResources_ECopy[4]);
    QThread *threadProcessA, *threadProcessB, *threadProcessC;
    ProcessWorker *workerA, *workerB, *workerC;

};
#endif // MAINWINDOW_H
