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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
