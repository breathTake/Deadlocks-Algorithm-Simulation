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
    QLabel *Printer_off_label;
    QPushButton *pushButton;
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
        Printer_off_label = new QLabel(centralwidget);
        Printer_off_label->setObjectName("Printer_off_label");
        Printer_off_label->setGeometry(QRect(100, 410, 171, 131));
        Printer_off_label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Printer_off.png);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 190, 83, 29));
        MainWindow->setCentralWidget(centralwidget);
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
        Printer_off_label->raise();
        pushButton->raise();
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
        Printer_off_label->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
