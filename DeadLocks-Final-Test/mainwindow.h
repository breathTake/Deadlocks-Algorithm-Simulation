#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <SystemRessource.h>
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
    QList<SystemRessource> setUpResources();
    QList<SystemProcess> setUpProcesses();

private slots:
    void on_pushButton_clicked();
    void run();
    void update_occupation_matrix(int occupiedResources[3][4]);
    void update_resource_occupation(int availableRessources_E[4], int occupiedRessources_P[4]);

private:
    Ui::MainWindow *ui;
    bool bankiersAlgorithm(int stillNeededRessources_R[5][4], int assignedRessources_C[5][4], int availableRessources_E[4], int occupiedRessources_P[4], int differenceRessources_A[4]);

};
#endif // MAINWINDOW_H
