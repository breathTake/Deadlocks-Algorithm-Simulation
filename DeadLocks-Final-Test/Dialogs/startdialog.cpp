#include "startdialog.h"
#include "ui_startdialog.h"

#include <QGraphicsDropShadowEffect>
#include <QDesktopServices>

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);

    //shadow effects
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

    ui->startSimulationButton->setGraphicsEffect(effectShadow1);
    ui->spinBox_Cd->setGraphicsEffect(effectShadow2);
    ui->spinBox_Plotter->setGraphicsEffect(effectShadow3);
    ui->spinBox_Printer->setGraphicsEffect(effectShadow4);
    ui->spinBox_TapeDrive->setGraphicsEffect(effectShadow5);
    ui->openGithubButton->setGraphicsEffect(effectShadow6);

}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::getResourceCount(){
    int counts[4];
    counts[0] = ui->spinBox_Printer->value();
    counts[1] = ui->spinBox_Cd->value();
    counts[2] = ui->spinBox_Plotter->value();
    counts[3] = ui->spinBox_TapeDrive->value();

    emit countsFinished(counts);
}

void StartDialog::getAlgorithm(){
    if(ui->radio_holdwait->isChecked()){
        emit algorithmsFinished(0);
    } else if(ui->radio_preempt->isChecked()){
        emit algorithmsFinished(1);
    } else if(ui->radio_circularw->isChecked()){
        emit algorithmsFinished(2);
    } else if(ui->radio_bankier->isChecked()){
        emit algorithmsFinished(3);
    }
}

void StartDialog::on_openGithubButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/breathTake/Deadlocks-Algorithm-Simulation", QUrl::TolerantMode));
}

