#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>

namespace Ui {
class StartDialog;
}

/**
 * @brief The StartDialog class represents the initial menu for selecting the algorithm
 * and the number of resources the user wishes to use for the simulation
 */
class StartDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a StartDialog object
     * @param parent The parent widget (default is nullptr)
     */
    explicit StartDialog(QWidget *parent = nullptr);

    /**
     * @brief Destructor for the StartDialog
     */
    ~StartDialog();

public slots:
    /**
     * @brief Slot to retrieve the chosen resource count from the user
     */
    void getResourceCount();

    /**
     * @brief Slot to retrieve the chosen algorithm from the user
     */
    void getAlgorithm();

signals:
    /**
     * @brief Signal emitted when resource counts are finished being collected
     * @param resourcesCounts An array of resource counts
     */
    void countsFinished(int* resourcesCounts);

    /**
     * @brief Signal emitted when the algorithm is finished
     * @param algorithm The chosen algorithm identifier
     */
    void algorithmsFinished(int algorithm);

private:
    Ui::StartDialog *ui; /**< Pointer to the UI object. */
};

#endif // STARTDIALOG_H
