#include "startdialog.h"
#include "ui_startdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
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
    //emit algorithmsFinished();
}
