#ifndef ENDDIALOG_H
#define ENDDIALOG_H

#include <QDialog>

namespace Ui {
class EndDialog;
}

class EndDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EndDialog(QWidget *parent = nullptr);
    ~EndDialog();

private slots:
    void on_end_pushButton_clicked();

private:
    Ui::EndDialog *ui;
};

#endif // ENDDIALOG_H
