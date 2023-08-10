#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <Objects/SystemResource.h>
#include <Objects/SystemProcess.h>
#include <Objects/ProcessWorker.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class represents the main window of the simulation application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a MainWindow object
     * @param parent The parent widget (default is nullptr)
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the MainWindow
     */
    ~MainWindow();

    /**
     * @brief Sets up the initial resources
     * @param countPrinters The count of printers
     * @param countCD The count of CD-ROMs
     * @param countPlotters The count of plotters
     * @param countTapeDrive The count of tape drives
     * @return A QList of SystemResource objects representing the setup resources
     */
    QList<SystemResource> setUpResources(int countPrinters, int countCD, int countPlotters, int countTapeDrive);

    /**
     * @brief Sets up the initial processes
     */
    void setUpProcesses();

private slots:
    ///< UI update slots
    void update_occupation_matrix();
    void update_needed_matrix();
    void update_resource_occupation();
    void update_resource_occupation_list();
    void updateElapsedTime(const QTime &startTime);

    void setShadows();
    void initResourceCount(int* resourcesCounts);
    void selectedAlgorithm(int algorithm);

    ///< update variables when occupation changed
    void updateStillNeededRessources_R();

    ///< thread slots
    void reserveResources(int process, int resource, int count);
    void releaseResources(int process, int resource, int count);
    void processFinished();

    ///< button slots
    void on_button_stop_simulation_clicked();
    void on_button_start_simulation_clicked();
    void on_button_restart_simulation_clicked();

private:
    Ui::MainWindow *ui;
    QThread *threadProcessA, *threadProcessB, *threadProcessC;
    ProcessWorker *workerA, *workerB, *workerC;
};

#endif // MAINWINDOW_H
