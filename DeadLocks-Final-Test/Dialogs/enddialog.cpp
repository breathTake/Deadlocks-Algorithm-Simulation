#include "enddialog.h"
#include "ui_enddialog.h"

#include <QGraphicsDropShadowEffect>
#include <QMainWindow>
#include <qprocess.h>

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

    QGraphicsDropShadowEffect* effectShadow1 = new QGraphicsDropShadowEffect();
    effectShadow1->setBlurRadius(10);
    effectShadow1->setColor(QColor(0, 0, 0, 255 * 0.2));
    effectShadow1->setOffset(0,2);
    ui->restart_pushButton->setGraphicsEffect(effectShadow1);

    //ui->end_runtime_label->setText(
}

EndDialog::~EndDialog()
{
    delete ui;
}

void EndDialog::on_end_pushButton_clicked()
{
    qApp->quit();
}


void EndDialog::on_restart_pushButton_clicked()
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

void EndDialog::getEndResults(QString textFromRuntime, int numOfResources)
{
    ui->end_runtime_label->setText(textFromRuntime);
    ui->end_resources_label->setText(QString::number(numOfResources));

}

