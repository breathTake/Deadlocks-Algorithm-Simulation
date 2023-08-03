#include "enddialog.h"
#include "ui_enddialog.h"

#include <QGraphicsDropShadowEffect>

EndDialog::EndDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndDialog)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect* effectShadow = new QGraphicsDropShadowEffect();
    effectShadow->setBlurRadius(10);
    effectShadow->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow->setOffset(0,2);
    ui->end_pushButton->setGraphicsEffect(effectShadow);
}

EndDialog::~EndDialog()
{
    delete ui;
}

void EndDialog::on_end_pushButton_clicked()
{
    qApp->quit();
}

