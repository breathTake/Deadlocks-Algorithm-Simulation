#include "startdialog.h"
#include "ui_startdialog.h"

#include <QGraphicsDropShadowEffect>

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect* effectShadow = new QGraphicsDropShadowEffect();
    effectShadow->setBlurRadius(40);
    effectShadow->setColor(Qt::black);
    effectShadow->setOffset(0,2);
    ui->startSimulationButton->setGraphicsEffect(effectShadow);

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
    } else if(ui->radio_distribution->isChecked()){
        emit algorithmsFinished(3);
    } else if(ui->radio_bankier->isChecked()){
        emit algorithmsFinished(4);
    }
}
