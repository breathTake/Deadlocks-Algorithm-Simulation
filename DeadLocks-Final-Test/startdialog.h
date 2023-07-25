#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();

public slots:
    void getResourceCount();
    void getAlgorithm();
signals:
    void countsFinished(int* resourcesCounts);
    void algorithmsFinished(int algorithm);
private:
    Ui::StartDialog *ui;
};

#endif // STARTDIALOG_H
