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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *background_resources;
    QLabel *Printer_background_label;
    QLabel *Cd_background_label;
    QLabel *Plotter_background_label;
    QLabel *Tapedrive_background_label;
    QLabel *Printer_label_occupation_list;
    QLabel *Cd_label_occupation_list;
    QLabel *Tapedrive_label_occupation_list;
    QLabel *Plotter_label_occupation_list;
    QLabel *Printer_label_occupation;
    QLabel *Cd_label_occupation;
    QLabel *Tapedrive_label_occupation;
    QLabel *Plotter_label_occupation;
    QLabel *Deadlock_test_running_label;
    QGroupBox *OccupationMatrix;
    QLabel *Occupation_Matrix_Label;
    QLabel *C2_label_occupation;
    QLabel *A1_label_occupation;
    QLabel *B1_label_occupation;
    QLabel *A3_label_occupation;
    QLabel *C3_label_occupation;
    QLabel *B2_label_occupation;
    QLabel *C4_label_occupation;
    QLabel *A4_label_occupation;
    QLabel *C1_label_occupation;
    QLabel *A2_label_occupation;
    QLabel *B3_label_occupation;
    QLabel *B4_label_occupation;
    QGroupBox *OccupationMatrix_2;
    QLabel *Needed_Matrix_Label;
    QLabel *C2_label_needed;
    QLabel *A1_label_needed;
    QLabel *B1_label_needed;
    QLabel *A3_label_needed;
    QLabel *C3_label_needed;
    QLabel *B2_label_needed;
    QLabel *C4_label_needed;
    QLabel *A4_label_needed;
    QLabel *C1_label_needed;
    QLabel *A2_label_needed;
    QLabel *B3_label_needed;
    QLabel *B4_label_needed;
    QPushButton *button_stop_simulation;
    QRadioButton *radio_preempt;
    QRadioButton *radio_bankier;
    QRadioButton *radio_holdwait;
    QRadioButton *radio_circularw;
    QPushButton *button_start_simulation;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1178, 845);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/Icon_White.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 61, 85);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        background_resources = new QLabel(centralwidget);
        background_resources->setObjectName("background_resources");
        background_resources->setGeometry(QRect(10, 410, 531, 371));
        background_resources->setStyleSheet(QString::fromUtf8("image: url(:/resources/Background_resources.png);"));
        Printer_background_label = new QLabel(centralwidget);
        Printer_background_label->setObjectName("Printer_background_label");
        Printer_background_label->setGeometry(QRect(50, 440, 231, 151));
        Printer_background_label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Printer_off.png);\n"
"background-color: rgb(73, 81, 103);"));
        Printer_background_label->setScaledContents(true);
        Cd_background_label = new QLabel(centralwidget);
        Cd_background_label->setObjectName("Cd_background_label");
        Cd_background_label->setGeometry(QRect(280, 440, 231, 151));
        Cd_background_label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Printer_off.png);\n"
"background-color: rgb(73, 81, 103);"));
        Cd_background_label->setScaledContents(true);
        Plotter_background_label = new QLabel(centralwidget);
        Plotter_background_label->setObjectName("Plotter_background_label");
        Plotter_background_label->setGeometry(QRect(50, 600, 231, 151));
        Plotter_background_label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Printer_off.png);\n"
"background-color: rgb(73, 81, 103);"));
        Plotter_background_label->setScaledContents(true);
        Tapedrive_background_label = new QLabel(centralwidget);
        Tapedrive_background_label->setObjectName("Tapedrive_background_label");
        Tapedrive_background_label->setGeometry(QRect(280, 600, 231, 151));
        Tapedrive_background_label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Printer_off.png);\n"
"background-color: rgb(73, 81, 103);"));
        Tapedrive_background_label->setScaledContents(true);
        Printer_label_occupation_list = new QLabel(centralwidget);
        Printer_label_occupation_list->setObjectName("Printer_label_occupation_list");
        Printer_label_occupation_list->setGeometry(QRect(90, 551, 141, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura PT")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        Printer_label_occupation_list->setFont(font);
        Printer_label_occupation_list->setStyleSheet(QString::fromUtf8("color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Printer_label_occupation_list->setAlignment(Qt::AlignCenter);
        Cd_label_occupation_list = new QLabel(centralwidget);
        Cd_label_occupation_list->setObjectName("Cd_label_occupation_list");
        Cd_label_occupation_list->setGeometry(QRect(320, 550, 141, 16));
        Cd_label_occupation_list->setFont(font);
        Cd_label_occupation_list->setStyleSheet(QString::fromUtf8("color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Cd_label_occupation_list->setAlignment(Qt::AlignCenter);
        Tapedrive_label_occupation_list = new QLabel(centralwidget);
        Tapedrive_label_occupation_list->setObjectName("Tapedrive_label_occupation_list");
        Tapedrive_label_occupation_list->setGeometry(QRect(320, 710, 141, 16));
        Tapedrive_label_occupation_list->setFont(font);
        Tapedrive_label_occupation_list->setStyleSheet(QString::fromUtf8("color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Tapedrive_label_occupation_list->setAlignment(Qt::AlignCenter);
        Plotter_label_occupation_list = new QLabel(centralwidget);
        Plotter_label_occupation_list->setObjectName("Plotter_label_occupation_list");
        Plotter_label_occupation_list->setGeometry(QRect(90, 710, 141, 16));
        Plotter_label_occupation_list->setFont(font);
        Plotter_label_occupation_list->setStyleSheet(QString::fromUtf8("color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Plotter_label_occupation_list->setAlignment(Qt::AlignCenter);
        Printer_label_occupation = new QLabel(centralwidget);
        Printer_label_occupation->setObjectName("Printer_label_occupation");
        Printer_label_occupation->setGeometry(QRect(170, 500, 71, 42));
        Printer_label_occupation->setFont(font);
        Printer_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(106, 112, 129);\n"
""));
        Printer_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Cd_label_occupation = new QLabel(centralwidget);
        Cd_label_occupation->setObjectName("Cd_label_occupation");
        Cd_label_occupation->setGeometry(QRect(400, 500, 71, 42));
        Cd_label_occupation->setFont(font);
        Cd_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(106, 112, 129);"));
        Cd_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Tapedrive_label_occupation = new QLabel(centralwidget);
        Tapedrive_label_occupation->setObjectName("Tapedrive_label_occupation");
        Tapedrive_label_occupation->setGeometry(QRect(400, 660, 71, 42));
        Tapedrive_label_occupation->setFont(font);
        Tapedrive_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(106, 112, 129);"));
        Tapedrive_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Plotter_label_occupation = new QLabel(centralwidget);
        Plotter_label_occupation->setObjectName("Plotter_label_occupation");
        Plotter_label_occupation->setGeometry(QRect(170, 660, 71, 42));
        Plotter_label_occupation->setFont(font);
        Plotter_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(106, 112, 129);"));
        Plotter_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Deadlock_test_running_label = new QLabel(centralwidget);
        Deadlock_test_running_label->setObjectName("Deadlock_test_running_label");
        Deadlock_test_running_label->setGeometry(QRect(30, 20, 491, 371));
        Deadlock_test_running_label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Oversight_background.png);"));
        OccupationMatrix = new QGroupBox(centralwidget);
        OccupationMatrix->setObjectName("OccupationMatrix");
        OccupationMatrix->setGeometry(QRect(543, 400, 601, 421));
        OccupationMatrix->setStyleSheet(QString::fromUtf8("border: none;"));
        OccupationMatrix->setFlat(true);
        Occupation_Matrix_Label = new QLabel(OccupationMatrix);
        Occupation_Matrix_Label->setObjectName("Occupation_Matrix_Label");
        Occupation_Matrix_Label->setGeometry(QRect(10, 10, 591, 371));
        Occupation_Matrix_Label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Occupation_Matrix.png);"));
        C2_label_occupation = new QLabel(OccupationMatrix);
        C2_label_occupation->setObjectName("C2_label_occupation");
        C2_label_occupation->setGeometry(QRect(300, 250, 51, 80));
        C2_label_occupation->setFont(font);
        C2_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A1_label_occupation = new QLabel(OccupationMatrix);
        A1_label_occupation->setObjectName("A1_label_occupation");
        A1_label_occupation->setGeometry(QRect(220, 155, 50, 42));
        A1_label_occupation->setFont(font);
        A1_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B1_label_occupation = new QLabel(OccupationMatrix);
        B1_label_occupation->setObjectName("B1_label_occupation");
        B1_label_occupation->setGeometry(QRect(220, 204, 50, 60));
        B1_label_occupation->setFont(font);
        B1_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A3_label_occupation = new QLabel(OccupationMatrix);
        A3_label_occupation->setObjectName("A3_label_occupation");
        A3_label_occupation->setGeometry(QRect(390, 152, 50, 42));
        A3_label_occupation->setFont(font);
        A3_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C3_label_occupation = new QLabel(OccupationMatrix);
        C3_label_occupation->setObjectName("C3_label_occupation");
        C3_label_occupation->setGeometry(QRect(390, 249, 50, 80));
        C3_label_occupation->setFont(font);
        C3_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B2_label_occupation = new QLabel(OccupationMatrix);
        B2_label_occupation->setObjectName("B2_label_occupation");
        B2_label_occupation->setGeometry(QRect(300, 202, 51, 60));
        B2_label_occupation->setFont(font);
        B2_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C4_label_occupation = new QLabel(OccupationMatrix);
        C4_label_occupation->setObjectName("C4_label_occupation");
        C4_label_occupation->setGeometry(QRect(470, 252, 50, 80));
        C4_label_occupation->setFont(font);
        C4_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(73, 81, 103);\n"
"font: 500 12pt \"Futura PT\";"));
        A4_label_occupation = new QLabel(OccupationMatrix);
        A4_label_occupation->setObjectName("A4_label_occupation");
        A4_label_occupation->setGeometry(QRect(470, 155, 50, 42));
        A4_label_occupation->setFont(font);
        A4_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C1_label_occupation = new QLabel(OccupationMatrix);
        C1_label_occupation->setObjectName("C1_label_occupation");
        C1_label_occupation->setGeometry(QRect(220, 252, 50, 80));
        C1_label_occupation->setFont(font);
        C1_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A2_label_occupation = new QLabel(OccupationMatrix);
        A2_label_occupation->setObjectName("A2_label_occupation");
        A2_label_occupation->setGeometry(QRect(300, 153, 50, 42));
        A2_label_occupation->setFont(font);
        A2_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B3_label_occupation = new QLabel(OccupationMatrix);
        B3_label_occupation->setObjectName("B3_label_occupation");
        B3_label_occupation->setGeometry(QRect(390, 201, 50, 60));
        B3_label_occupation->setFont(font);
        B3_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B4_label_occupation = new QLabel(OccupationMatrix);
        B4_label_occupation->setObjectName("B4_label_occupation");
        B4_label_occupation->setGeometry(QRect(470, 204, 52, 60));
        B4_label_occupation->setFont(font);
        B4_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        OccupationMatrix_2 = new QGroupBox(centralwidget);
        OccupationMatrix_2->setObjectName("OccupationMatrix_2");
        OccupationMatrix_2->setGeometry(QRect(543, 10, 601, 381));
        OccupationMatrix_2->setStyleSheet(QString::fromUtf8("border: none;"));
        OccupationMatrix_2->setFlat(true);
        Needed_Matrix_Label = new QLabel(OccupationMatrix_2);
        Needed_Matrix_Label->setObjectName("Needed_Matrix_Label");
        Needed_Matrix_Label->setGeometry(QRect(10, 10, 591, 371));
        Needed_Matrix_Label->setStyleSheet(QString::fromUtf8("image: url(:/resources/Required_Matrix.png);"));
        C2_label_needed = new QLabel(OccupationMatrix_2);
        C2_label_needed->setObjectName("C2_label_needed");
        C2_label_needed->setGeometry(QRect(300, 250, 51, 80));
        C2_label_needed->setFont(font);
        C2_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A1_label_needed = new QLabel(OccupationMatrix_2);
        A1_label_needed->setObjectName("A1_label_needed");
        A1_label_needed->setGeometry(QRect(220, 155, 50, 42));
        A1_label_needed->setFont(font);
        A1_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B1_label_needed = new QLabel(OccupationMatrix_2);
        B1_label_needed->setObjectName("B1_label_needed");
        B1_label_needed->setGeometry(QRect(220, 204, 50, 60));
        B1_label_needed->setFont(font);
        B1_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A3_label_needed = new QLabel(OccupationMatrix_2);
        A3_label_needed->setObjectName("A3_label_needed");
        A3_label_needed->setGeometry(QRect(390, 152, 50, 42));
        A3_label_needed->setFont(font);
        A3_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C3_label_needed = new QLabel(OccupationMatrix_2);
        C3_label_needed->setObjectName("C3_label_needed");
        C3_label_needed->setGeometry(QRect(390, 249, 50, 80));
        C3_label_needed->setFont(font);
        C3_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B2_label_needed = new QLabel(OccupationMatrix_2);
        B2_label_needed->setObjectName("B2_label_needed");
        B2_label_needed->setGeometry(QRect(300, 202, 51, 60));
        B2_label_needed->setFont(font);
        B2_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C4_label_needed = new QLabel(OccupationMatrix_2);
        C4_label_needed->setObjectName("C4_label_needed");
        C4_label_needed->setGeometry(QRect(470, 252, 50, 80));
        C4_label_needed->setFont(font);
        C4_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(73, 81, 103);\n"
"font: 500 12pt \"Futura PT\";"));
        A4_label_needed = new QLabel(OccupationMatrix_2);
        A4_label_needed->setObjectName("A4_label_needed");
        A4_label_needed->setGeometry(QRect(470, 155, 50, 42));
        A4_label_needed->setFont(font);
        A4_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C1_label_needed = new QLabel(OccupationMatrix_2);
        C1_label_needed->setObjectName("C1_label_needed");
        C1_label_needed->setGeometry(QRect(220, 252, 50, 80));
        C1_label_needed->setFont(font);
        C1_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A2_label_needed = new QLabel(OccupationMatrix_2);
        A2_label_needed->setObjectName("A2_label_needed");
        A2_label_needed->setGeometry(QRect(300, 153, 50, 42));
        A2_label_needed->setFont(font);
        A2_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B3_label_needed = new QLabel(OccupationMatrix_2);
        B3_label_needed->setObjectName("B3_label_needed");
        B3_label_needed->setGeometry(QRect(390, 201, 50, 60));
        B3_label_needed->setFont(font);
        B3_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B4_label_needed = new QLabel(OccupationMatrix_2);
        B4_label_needed->setObjectName("B4_label_needed");
        B4_label_needed->setGeometry(QRect(470, 204, 52, 60));
        B4_label_needed->setFont(font);
        B4_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        button_stop_simulation = new QPushButton(centralwidget);
        button_stop_simulation->setObjectName("button_stop_simulation");
        button_stop_simulation->setGeometry(QRect(60, 320, 431, 21));
        button_stop_simulation->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(106, 112, 129);\n"
"font: 500 13pt \"Futura PT\";"));
        radio_preempt = new QRadioButton(centralwidget);
        radio_preempt->setObjectName("radio_preempt");
        radio_preempt->setGeometry(QRect(60, 210, 240, 26));
        radio_preempt->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(106, 112, 129);\n"
"font: 500 13pt \"Futura PT\";"));
        radio_bankier = new QRadioButton(centralwidget);
        radio_bankier->setObjectName("radio_bankier");
        radio_bankier->setGeometry(QRect(60, 111, 240, 26));
        radio_bankier->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(106, 112, 129);\n"
"font: 500 13pt \"Futura PT\";"));
        radio_holdwait = new QRadioButton(centralwidget);
        radio_holdwait->setObjectName("radio_holdwait");
        radio_holdwait->setGeometry(QRect(60, 144, 240, 26));
        radio_holdwait->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(106, 112, 129);\n"
"font: 500 13pt \"Futura PT\";"));
        radio_circularw = new QRadioButton(centralwidget);
        radio_circularw->setObjectName("radio_circularw");
        radio_circularw->setGeometry(QRect(60, 177, 240, 26));
        radio_circularw->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(106, 112, 129);\n"
"font: 500 13pt \"Futura PT\";\n"
""));
        button_start_simulation = new QPushButton(centralwidget);
        button_start_simulation->setObjectName("button_start_simulation");
        button_start_simulation->setGeometry(QRect(60, 270, 431, 21));
        button_start_simulation->setStyleSheet(QString::fromUtf8("border: none;\n"
"background-color: rgb(106, 112, 129);\n"
"font: 500 13pt \"Futura PT\";"));
        MainWindow->setCentralWidget(centralwidget);
        Deadlock_test_running_label->raise();
        background_resources->raise();
        Printer_background_label->raise();
        Cd_background_label->raise();
        Plotter_background_label->raise();
        Tapedrive_background_label->raise();
        Printer_label_occupation_list->raise();
        Cd_label_occupation_list->raise();
        Tapedrive_label_occupation_list->raise();
        Plotter_label_occupation_list->raise();
        Printer_label_occupation->raise();
        Cd_label_occupation->raise();
        Tapedrive_label_occupation->raise();
        Plotter_label_occupation->raise();
        OccupationMatrix->raise();
        OccupationMatrix_2->raise();
        button_stop_simulation->raise();
        radio_preempt->raise();
        radio_bankier->raise();
        radio_holdwait->raise();
        radio_circularw->raise();
        button_start_simulation->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1178, 31));
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
        background_resources->setText(QString());
        Printer_background_label->setText(QString());
        Cd_background_label->setText(QString());
        Plotter_background_label->setText(QString());
        Tapedrive_background_label->setText(QString());
        Printer_label_occupation_list->setText(QString());
        Cd_label_occupation_list->setText(QString());
        Tapedrive_label_occupation_list->setText(QString());
        Plotter_label_occupation_list->setText(QString());
        Printer_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Cd_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Tapedrive_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Plotter_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Deadlock_test_running_label->setText(QString());
        Occupation_Matrix_Label->setText(QString());
        C2_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A1_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B1_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A3_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C3_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B2_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C4_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A4_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C1_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A2_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B3_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B4_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Needed_Matrix_Label->setText(QString());
        C2_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A1_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B1_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A3_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C3_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B2_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C4_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A4_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C1_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A2_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B3_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B4_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button_stop_simulation->setText(QCoreApplication::translate("MainWindow", "Stop Simulation", nullptr));
        radio_preempt->setText(QCoreApplication::translate("MainWindow", "No Preemption", nullptr));
        radio_bankier->setText(QCoreApplication::translate("MainWindow", "Bankier-Algorithm", nullptr));
        radio_holdwait->setText(QCoreApplication::translate("MainWindow", "Hold and Wait", nullptr));
        radio_circularw->setText(QCoreApplication::translate("MainWindow", "Circular Wait", nullptr));
        button_start_simulation->setText(QCoreApplication::translate("MainWindow", "Start Simulation", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
