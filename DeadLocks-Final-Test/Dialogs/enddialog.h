#ifndef ENDDIALOG_H
#define ENDDIALOG_H

#include <QDialog>

namespace Ui {

/**
 * @brief Class represents the Ending Dialog which appears with the result data after the simulation
 */
class EndDialog;
}

class EndDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief EndDialog constructor
     * @param parent is the mainwindow
     */
    explicit EndDialog(QWidget *parent = nullptr);
    /**
     * @brief destructor
     */
    ~EndDialog();

private slots:
    /**
     * @brief on_end_pushButton_clicked dialog closes the complete window on button click
     */
    void on_end_pushButton_clicked();

private:
    Ui::EndDialog *ui;
};

#endif // ENDDIALOG_H
