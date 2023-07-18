#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <SystemResource.h>
#include <SystemProcess.h>

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
    void run();
    void update_occupation_matrix();
    void update_needed_matrix();
    void update_resource_occupation();
    void updateStillNeededRessources_R();

    void on_button_start_simulation_clicked();

private:
    Ui::MainWindow *ui;
    bool bankiersAlgorithm();

};
#endif // MAINWINDOW_H
