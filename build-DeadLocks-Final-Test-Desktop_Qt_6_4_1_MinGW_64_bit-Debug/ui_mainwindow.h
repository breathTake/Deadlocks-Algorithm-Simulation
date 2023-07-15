/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *C3_label_occupation;
    QLabel *C1_label_occupation;
    QLabel *B1_label_occupation;
    QLabel *B2_label_occupation;
    QLabel *A1_label_occupation;
    QLabel *A3_label_occupation;
    QLabel *B3_label_occupation;
    QLabel *C2_label_occupation;
    QLabel *B4_label_occupation;
    QLabel *A2_label_occupation;
    QLabel *C4_label_occupation;
    QLabel *A4_label_occupation;
    QLabel *Occupation_Matrix_Label;
    QPushButton *pushButton;
    QLabel *background_resources;
    QLabel *Printer_background_label;
    QLabel *Cd_background_label;
    QLabel *Plotter_background_label;
    QLabel *Tapedrive_background_label;
    QLabel *Printer_label_occupation_list;
    QLabel *Cd_label_occupation_list;
    QLabel *Tapedrive_label_occupation_list_2;
    QLabel *Plotter_label_occupation_list;
    QLabel *Printer_label_occupation;
    QLabel *Cd_label_occupation;
    QLabel *Tapedrive_label_occupation;
    QLabel *Plotter_label_occupation;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1314, 855);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/Icon_White.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 61, 85);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        C3_label_occupation = new QLabel(centralwidget);
        C3_label_occupation->setObjectName("C3_label_occupation");
        C3_label_occupation->setGeometry(QRect(1040, 637, 50, 80));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura PT")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        C3_label_occupation->setFont(font);
        C3_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C1_label_occupation = new QLabel(centralwidget);
        C1_label_occupation->setObjectName("C1_label_occupation");
        C1_label_occupation->setGeometry(QRect(870, 640, 50, 80));
        C1_label_occupation->setFont(font);
        C1_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B1_label_occupation = new QLabel(centralwidget);
        B1_label_occupation->setObjectName("B1_label_occupation");
        B1_label_occupation->setGeometry(QRect(870, 592, 50, 60));
        B1_label_occupation->setFont(font);
        B1_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B2_label_occupation = new QLabel(centralwidget);
        B2_label_occupation->setObjectName("B2_label_occupation");
        B2_label_occupation->setGeometry(QRect(950, 590, 51, 60));
        B2_label_occupation->setFont(font);
        B2_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A1_label_occupation = new QLabel(centralwidget);
        A1_label_occupation->setObjectName("A1_label_occupation");
        A1_label_occupation->setGeometry(QRect(870, 543, 50, 42));
        A1_label_occupation->setFont(font);
        A1_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A3_label_occupation = new QLabel(centralwidget);
        A3_label_occupation->setObjectName("A3_label_occupation");
        A3_label_occupation->setGeometry(QRect(1040, 540, 50, 42));
        A3_label_occupation->setFont(font);
        A3_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B3_label_occupation = new QLabel(centralwidget);
        B3_label_occupation->setObjectName("B3_label_occupation");
        B3_label_occupation->setGeometry(QRect(1040, 589, 50, 60));
        B3_label_occupation->setFont(font);
        B3_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C2_label_occupation = new QLabel(centralwidget);
        C2_label_occupation->setObjectName("C2_label_occupation");
        C2_label_occupation->setGeometry(QRect(950, 638, 51, 80));
        C2_label_occupation->setFont(font);
        C2_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B4_label_occupation = new QLabel(centralwidget);
        B4_label_occupation->setObjectName("B4_label_occupation");
        B4_label_occupation->setGeometry(QRect(1120, 592, 52, 60));
        B4_label_occupation->setFont(font);
        B4_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A2_label_occupation = new QLabel(centralwidget);
        A2_label_occupation->setObjectName("A2_label_occupation");
        A2_label_occupation->setGeometry(QRect(950, 541, 50, 42));
        A2_label_occupation->setFont(font);
        A2_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C4_label_occupation = new QLabel(centralwidget);
        C4_label_occupation->setObjectName("C4_label_occupation");
        C4_label_occupation->setGeometry(QRect(1120, 640, 50, 80));
        C4_label_occupation->setFont(font);
        C4_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(73, 81, 103);\n"
"font: 500 12pt \"Futura PT\";"));
        A4_label_occupation = new QLabel(centralwidget);
        A4_label_occupation->setObjectName("A4_label_occupation");
        A4_label_occupation->setGeometry(QRect(1120, 543, 50, 42));
        A4_label_occupation->setFont(font);
        A4_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        Occupation_Matrix_Label = new QLabel(centralwidget);
        Occupation_Matrix_Label->setObjectName("Occupation_Matrix_Label");
        Occupation_Matrix_Label->setGeometry(QRect(654, 397, 591, 371));
        Occupation_Matrix_Label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Occupation_Matrix.png);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(120, 80, 83, 29));
        background_resources = new QLabel(centralwidget);
        background_resources->setObjectName("background_resources");
        background_resources->setGeometry(QRect(90, 400, 531, 371));
        background_resources->setStyleSheet(QString::fromUtf8("image: url(:/resources/Background_resources.png);"));
        Printer_background_label = new QLabel(centralwidget);
        Printer_background_label->setObjectName("Printer_background_label");
        Printer_background_label->setGeometry(QRect(130, 430, 231, 151));
        Printer_background_label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Printer_off.png);\n"
"background-color: rgb(73, 81, 103);"));
        Printer_background_label->setScaledContents(true);
        Cd_background_label = new QLabel(centralwidget);
        Cd_background_label->setObjectName("Cd_background_label");
        Cd_background_label->setGeometry(QRect(360, 430, 231, 151));
        Cd_background_label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Printer_off.png);\n"
"background-color: rgb(73, 81, 103);"));
        Cd_background_label->setScaledContents(true);
        Plotter_background_label = new QLabel(centralwidget);
        Plotter_background_label->setObjectName("Plotter_background_label");
        Plotter_background_label->setGeometry(QRect(130, 590, 231, 151));
        Plotter_background_label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Printer_off.png);\n"
"background-color: rgb(73, 81, 103);"));
        Plotter_background_label->setScaledContents(true);
        Tapedrive_background_label = new QLabel(centralwidget);
        Tapedrive_background_label->setObjectName("Tapedrive_background_label");
        Tapedrive_background_label->setGeometry(QRect(360, 590, 231, 151));
        Tapedrive_background_label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Printer_off.png);\n"
"background-color: rgb(73, 81, 103);"));
        Tapedrive_background_label->setScaledContents(true);
        Printer_label_occupation_list = new QLabel(centralwidget);
        Printer_label_occupation_list->setObjectName("Printer_label_occupation_list");
        Printer_label_occupation_list->setGeometry(QRect(170, 541, 141, 16));
        Printer_label_occupation_list->setFont(font);
        Printer_label_occupation_list->setStyleSheet(QString::fromUtf8("color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Printer_label_occupation_list->setAlignment(Qt::AlignCenter);
        Cd_label_occupation_list = new QLabel(centralwidget);
        Cd_label_occupation_list->setObjectName("Cd_label_occupation_list");
        Cd_label_occupation_list->setGeometry(QRect(400, 540, 141, 16));
        Cd_label_occupation_list->setFont(font);
        Cd_label_occupation_list->setStyleSheet(QString::fromUtf8("color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Cd_label_occupation_list->setAlignment(Qt::AlignCenter);
        Tapedrive_label_occupation_list_2 = new QLabel(centralwidget);
        Tapedrive_label_occupation_list_2->setObjectName("Tapedrive_label_occupation_list_2");
        Tapedrive_label_occupation_list_2->setGeometry(QRect(400, 700, 141, 16));
        Tapedrive_label_occupation_list_2->setFont(font);
        Tapedrive_label_occupation_list_2->setStyleSheet(QString::fromUtf8("color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Tapedrive_label_occupation_list_2->setAlignment(Qt::AlignCenter);
        Plotter_label_occupation_list = new QLabel(centralwidget);
        Plotter_label_occupation_list->setObjectName("Plotter_label_occupation_list");
        Plotter_label_occupation_list->setGeometry(QRect(170, 700, 141, 16));
        Plotter_label_occupation_list->setFont(font);
        Plotter_label_occupation_list->setStyleSheet(QString::fromUtf8("color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Plotter_label_occupation_list->setAlignment(Qt::AlignCenter);
        Printer_label_occupation = new QLabel(centralwidget);
        Printer_label_occupation->setObjectName("Printer_label_occupation");
        Printer_label_occupation->setGeometry(QRect(250, 490, 71, 42));
        Printer_label_occupation->setFont(font);
        Printer_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(106, 112, 129);\n"
""));
        Printer_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Cd_label_occupation = new QLabel(centralwidget);
        Cd_label_occupation->setObjectName("Cd_label_occupation");
        Cd_label_occupation->setGeometry(QRect(480, 490, 71, 42));
        Cd_label_occupation->setFont(font);
        Cd_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(106, 112, 129);"));
        Cd_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Tapedrive_label_occupation = new QLabel(centralwidget);
        Tapedrive_label_occupation->setObjectName("Tapedrive_label_occupation");
        Tapedrive_label_occupation->setGeometry(QRect(480, 650, 71, 42));
        Tapedrive_label_occupation->setFont(font);
        Tapedrive_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(106, 112, 129);"));
        Tapedrive_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Plotter_label_occupation = new QLabel(centralwidget);
        Plotter_label_occupation->setObjectName("Plotter_label_occupation");
        Plotter_label_occupation->setGeometry(QRect(250, 650, 71, 42));
        Plotter_label_occupation->setFont(font);
        Plotter_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(106, 112, 129);"));
        Plotter_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralwidget);
        background_resources->raise();
        Occupation_Matrix_Label->raise();
        C3_label_occupation->raise();
        C1_label_occupation->raise();
        B1_label_occupation->raise();
        B2_label_occupation->raise();
        A1_label_occupation->raise();
        A3_label_occupation->raise();
        B3_label_occupation->raise();
        C2_label_occupation->raise();
        B4_label_occupation->raise();
        A2_label_occupation->raise();
        C4_label_occupation->raise();
        A4_label_occupation->raise();
        pushButton->raise();
        Printer_background_label->raise();
        Cd_background_label->raise();
        Plotter_background_label->raise();
        Tapedrive_background_label->raise();
        Printer_label_occupation_list->raise();
        Cd_label_occupation_list->raise();
        Tapedrive_label_occupation_list_2->raise();
        Plotter_label_occupation_list->raise();
        Printer_label_occupation->raise();
        Cd_label_occupation->raise();
        Tapedrive_label_occupation->raise();
        Plotter_label_occupation->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1314, 31));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Deadlock Algorithm Simulation", nullptr));
        C3_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C1_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B1_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B2_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A1_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A3_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B3_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C2_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B4_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A2_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C4_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A4_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Occupation_Matrix_Label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        background_resources->setText(QString());
        Printer_background_label->setText(QString());
        Cd_background_label->setText(QString());
        Plotter_background_label->setText(QString());
        Tapedrive_background_label->setText(QString());
        Printer_label_occupation_list->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Cd_label_occupation_list->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Tapedrive_label_occupation_list_2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Plotter_label_occupation_list->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Printer_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Cd_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Tapedrive_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Plotter_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
