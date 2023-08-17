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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *Explanation;
    QLabel *explanation_Background_Label;
    QLabel *explanation_Title_label;
    QPlainTextEdit *explanation_plainTextEdit;
    QWidget *layoutWidget;
    QVBoxLayout *OverviewAndResources;
    QGroupBox *Overview;
    QLabel *Overview_background_label;
    QLabel *Overview_title_label;
    QLabel *label_time;
    QPushButton *button_start_simulation;
    QPushButton *button_restart_simulation;
    QLabel *CurrentAlgorithm_label_indicator;
    QPlainTextEdit *plainTextEdit_RequestInfo;
    QPushButton *button_stop_simulation;
    QLabel *CurrentAlgorithm_label;
    QGroupBox *Resources;
    QLabel *background_resources;
    QLabel *free_Printer_label;
    QLabel *Tapedrive_background_label;
    QLabel *TapeDrive_Icon_label;
    QLabel *Tapedrive_label_occupation_list;
    QLabel *free_TapeDrive_label;
    QLabel *Tapedrive_label_occupation;
    QLabel *free_CD_label;
    QLabel *TapeDrive_Header_Label;
    QLabel *free_Plotter_label;
    QLabel *Cd_label_occupation_list;
    QLabel *Printer_label_occupation;
    QLabel *CD_Icon_label;
    QLabel *CD_Header_Label;
    QLabel *Plotter_label_occupation_list;
    QLabel *Printer_label_occupation_list;
    QLabel *Cd_label_occupation;
    QLabel *Cd_background_label;
    QLabel *Plotter_label_occupation;
    QLabel *Printer_Header_Label;
    QLabel *Plotter_Header_Label;
    QLabel *Plotter_Icon_label;
    QLabel *Plotter_background_label;
    QLabel *Printer_background_label;
    QLabel *Printer_Icon_label;
    QWidget *layoutWidget1;
    QVBoxLayout *Matrices;
    QGroupBox *RequirementsMatrix;
    QLabel *Needed_Matrix_Label;
    QLabel *Requirements_headline_label;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *A2_label_needed;
    QLabel *B4_label_needed;
    QLabel *Requirements_Plotter_Icon_label;
    QLabel *A3_label_needed;
    QLabel *Requirements_CD_Icon_label;
    QLabel *C2_label_needed;
    QLabel *Requirements_Process_B_Label;
    QLabel *A1_label_needed;
    QLabel *B2_label_needed;
    QLabel *Requirements_Process_A_Label;
    QLabel *Requirements_TapeDrive_Icon_label;
    QLabel *C4_label_needed;
    QLabel *Requirements_Printer_Icon_label;
    QLabel *Requirements_Process_C_Label;
    QLabel *B3_label_needed;
    QLabel *A4_label_needed;
    QLabel *B1_label_needed;
    QLabel *C3_label_needed;
    QLabel *C1_label_needed;
    QGroupBox *OccupationMatrix;
    QLabel *Occupation_Matrix_Label;
    QLabel *Occupation_headline_label;
    QFrame *occupation_frame;
    QGridLayout *gridLayout;
    QLabel *Occupation_Printer_Icon_label;
    QLabel *Occupation_CD_Icon_label;
    QLabel *Occupation_Plotter_Icon_label;
    QLabel *Occupation_TapeDrive_Icon_label;
    QLabel *Occupation_Process_A_Label;
    QLabel *A1_label_occupation;
    QLabel *A2_label_occupation;
    QLabel *A3_label_occupation;
    QLabel *A4_label_occupation;
    QLabel *Occupation_Process_B_Label;
    QLabel *B3_label_occupation;
    QLabel *B1_label_occupation;
    QLabel *B2_label_occupation;
    QLabel *B4_label_occupation;
    QLabel *C3_label_occupation;
    QLabel *C4_label_occupation;
    QLabel *C2_label_occupation;
    QLabel *C1_label_occupation;
    QLabel *Occupation_Process_C_Label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1550, 810);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1550, 810));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/Icon_White.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 61, 85);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Explanation = new QGroupBox(centralwidget);
        Explanation->setObjectName("Explanation");
        Explanation->setGeometry(QRect(1170, 20, 351, 751));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Explanation->sizePolicy().hasHeightForWidth());
        Explanation->setSizePolicy(sizePolicy1);
        Explanation->setStyleSheet(QString::fromUtf8("border: none;"));
        explanation_Background_Label = new QLabel(Explanation);
        explanation_Background_Label->setObjectName("explanation_Background_Label");
        explanation_Background_Label->setGeometry(QRect(0, 0, 351, 751));
        explanation_Background_Label->setStyleSheet(QString::fromUtf8("background-color: rgb(73, 81, 103);\n"
"border-radius: 10px;\n"
""));
        explanation_Title_label = new QLabel(Explanation);
        explanation_Title_label->setObjectName("explanation_Title_label");
        explanation_Title_label->setGeometry(QRect(30, 20, 171, 61));
        explanation_Title_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(235, 235, 235);\n"
"font: 18pt \"Futura Hv BT\";"));
        explanation_plainTextEdit = new QPlainTextEdit(Explanation);
        explanation_plainTextEdit->setObjectName("explanation_plainTextEdit");
        explanation_plainTextEdit->setGeometry(QRect(30, 90, 281, 591));
        explanation_plainTextEdit->setTabletTracking(false);
        explanation_plainTextEdit->setAcceptDrops(false);
        explanation_plainTextEdit->setLayoutDirection(Qt::LeftToRight);
        explanation_plainTextEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit{ \n"
"	padding-top: 5px;\n"
"	padding-left: 0px;\n"
"	border-radius: 5px;\n"
"	border: none;\n"
"	background-color: rgb(73, 81, 103);\n"
"	font: 12pt \"Futura Bk BT\";\n"
"	color: rgb(217, 217, 217);\n"
"	alignment: AlignCenter;\n"
"    }"));
        explanation_plainTextEdit->setInputMethodHints(Qt::ImhNone);
        explanation_plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        explanation_plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        explanation_plainTextEdit->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        explanation_plainTextEdit->setTextInteractionFlags(Qt::NoTextInteraction);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 20, 491, 801));
        OverviewAndResources = new QVBoxLayout(layoutWidget);
        OverviewAndResources->setObjectName("OverviewAndResources");
        OverviewAndResources->setContentsMargins(0, 0, 0, 0);
        Overview = new QGroupBox(layoutWidget);
        Overview->setObjectName("Overview");
        Overview->setStyleSheet(QString::fromUtf8("border: none;"));
        Overview_background_label = new QLabel(Overview);
        Overview_background_label->setObjectName("Overview_background_label");
        Overview_background_label->setGeometry(QRect(0, 1, 491, 371));
        Overview_background_label->setStyleSheet(QString::fromUtf8("background-color: rgb(73, 81, 103);\n"
"border-radius: 10px;"));
        Overview_title_label = new QLabel(Overview);
        Overview_title_label->setObjectName("Overview_title_label");
        Overview_title_label->setGeometry(QRect(40, 31, 361, 31));
        Overview_title_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(235, 235, 235);\n"
"font: 18pt \"Futura Hv BT\";"));
        label_time = new QLabel(Overview);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(340, 21, 121, 51));
        label_time->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 14pt \"Futura Bk BT\";"));
        label_time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        button_start_simulation = new QPushButton(Overview);
        button_start_simulation->setObjectName("button_start_simulation");
        button_start_simulation->setGeometry(QRect(40, 241, 421, 41));
        button_start_simulation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(105, 111, 128);\n"
"	color: rgb(235, 235, 235);\n"
"	font: 18pt \"Futura Hv BT\";\n"
"}\n"
"QPushButton::!enabled {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(43, 48, 63);\n"
"	font: 18pt \"Futura Hv BT\";\n"
"	color: rgb(217, 217, 217);\n"
"}\n"
"QPushButton::hover {\n"
"	background-color: rgb(152, 161, 186);\n"
"}\n"
""));
        button_restart_simulation = new QPushButton(Overview);
        button_restart_simulation->setObjectName("button_restart_simulation");
        button_restart_simulation->setGeometry(QRect(40, 301, 41, 41));
        button_restart_simulation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(105, 111, 128);\n"
"	font: 18pt \"Futura BdCn BT\";\n"
"	color: rgb(217, 217, 217);\n"
"}\n"
"QPushButton::pressed {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(43, 48, 63);\n"
"	font: 18pt \"Futura BdCn BT\";\n"
"	color: rgb(217, 217, 217);\n"
"}\n"
"QPushButton::hover {\n"
"	background-color: rgb(152, 161, 186);\n"
"}\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/reset_Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_restart_simulation->setIcon(icon1);
        CurrentAlgorithm_label_indicator = new QLabel(Overview);
        CurrentAlgorithm_label_indicator->setObjectName("CurrentAlgorithm_label_indicator");
        CurrentAlgorithm_label_indicator->setGeometry(QRect(40, 81, 111, 31));
        CurrentAlgorithm_label_indicator->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(235, 235, 235);\n"
"font: 14pt \"Futura Bk BT\";"));
        plainTextEdit_RequestInfo = new QPlainTextEdit(Overview);
        plainTextEdit_RequestInfo->setObjectName("plainTextEdit_RequestInfo");
        plainTextEdit_RequestInfo->setGeometry(QRect(40, 130, 421, 91));
        plainTextEdit_RequestInfo->setTabletTracking(false);
        plainTextEdit_RequestInfo->setLayoutDirection(Qt::LeftToRight);
        plainTextEdit_RequestInfo->setStyleSheet(QString::fromUtf8("QPlainTextEdit{ \n"
"	padding-top: 15px;\n"
"	padding-left: 50px;\n"
"	border-radius: 5px;\n"
"	border: none;\n"
"	background-color: rgb(105, 111, 128);\n"
"	font: 12pt \"Futura Bk BT\";\n"
"	color: rgb(217, 217, 217);\n"
"	alignment: AlignCenter;\n"
"    }"));
        plainTextEdit_RequestInfo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_RequestInfo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_RequestInfo->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        plainTextEdit_RequestInfo->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        button_stop_simulation = new QPushButton(Overview);
        button_stop_simulation->setObjectName("button_stop_simulation");
        button_stop_simulation->setGeometry(QRect(100, 301, 361, 41));
        button_stop_simulation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(105, 111, 128);\n"
"	color: rgb(235, 235, 235);\n"
"	font: 18pt \"Futura Hv BT\";\n"
"}\n"
"QPushButton::pressed {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(43, 48, 63);\n"
"	font: 18pt \"Futura Hv BT\";\n"
"	color: rgb(217, 217, 217);\n"
"}\n"
"QPushButton::hover {\n"
"	background-color: rgb(152, 161, 186);\n"
"}\n"
""));
        CurrentAlgorithm_label = new QLabel(Overview);
        CurrentAlgorithm_label->setObjectName("CurrentAlgorithm_label");
        CurrentAlgorithm_label->setGeometry(QRect(160, 81, 301, 31));
        CurrentAlgorithm_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";"));
        CurrentAlgorithm_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        OverviewAndResources->addWidget(Overview);

        Resources = new QGroupBox(layoutWidget);
        Resources->setObjectName("Resources");
        Resources->setStyleSheet(QString::fromUtf8("border: none;"));
        background_resources = new QLabel(Resources);
        background_resources->setObjectName("background_resources");
        background_resources->setGeometry(QRect(0, 0, 491, 351));
        background_resources->setStyleSheet(QString::fromUtf8("background-color: rgb(73, 81, 103);\n"
"border-radius: 10px;"));
        free_Printer_label = new QLabel(Resources);
        free_Printer_label->setObjectName("free_Printer_label");
        free_Printer_label->setGeometry(QRect(50, 100, 81, 16));
        free_Printer_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 12pt \"Futura Bk BT\";"));
        Tapedrive_background_label = new QLabel(Resources);
        Tapedrive_background_label->setObjectName("Tapedrive_background_label");
        Tapedrive_background_label->setGeometry(QRect(250, 190, 201, 141));
        Tapedrive_background_label->setStyleSheet(QString::fromUtf8("background-color: rgb(106, 112, 129);\n"
"border-radius: 5px;"));
        Tapedrive_background_label->setScaledContents(true);
        TapeDrive_Icon_label = new QLabel(Resources);
        TapeDrive_Icon_label->setObjectName("TapeDrive_Icon_label");
        TapeDrive_Icon_label->setGeometry(QRect(270, 210, 30, 30));
        TapeDrive_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/TapeDrive_Icon.png);"));
        Tapedrive_label_occupation_list = new QLabel(Resources);
        Tapedrive_label_occupation_list->setObjectName("Tapedrive_label_occupation_list");
        Tapedrive_label_occupation_list->setGeometry(QRect(270, 290, 161, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura PT")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        Tapedrive_label_occupation_list->setFont(font);
        Tapedrive_label_occupation_list->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Tapedrive_label_occupation_list->setAlignment(Qt::AlignCenter);
        free_TapeDrive_label = new QLabel(Resources);
        free_TapeDrive_label->setObjectName("free_TapeDrive_label");
        free_TapeDrive_label->setGeometry(QRect(270, 260, 81, 16));
        free_TapeDrive_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 12pt \"Futura Bk BT\";"));
        Tapedrive_label_occupation = new QLabel(Resources);
        Tapedrive_label_occupation->setObjectName("Tapedrive_label_occupation");
        Tapedrive_label_occupation->setGeometry(QRect(360, 250, 71, 42));
        Tapedrive_label_occupation->setFont(font);
        Tapedrive_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: none;\n"
""));
        Tapedrive_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        free_CD_label = new QLabel(Resources);
        free_CD_label->setObjectName("free_CD_label");
        free_CD_label->setGeometry(QRect(270, 100, 81, 16));
        free_CD_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 12pt \"Futura Bk BT\";"));
        TapeDrive_Header_Label = new QLabel(Resources);
        TapeDrive_Header_Label->setObjectName("TapeDrive_Header_Label");
        TapeDrive_Header_Label->setGeometry(QRect(320, 210, 111, 31));
        TapeDrive_Header_Label->setLayoutDirection(Qt::RightToLeft);
        TapeDrive_Header_Label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(235, 235, 235);\n"
"font: 16pt \"Futura Hv BT\";"));
        TapeDrive_Header_Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        free_Plotter_label = new QLabel(Resources);
        free_Plotter_label->setObjectName("free_Plotter_label");
        free_Plotter_label->setGeometry(QRect(50, 260, 91, 16));
        free_Plotter_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 12pt \"Futura Bk BT\";"));
        Cd_label_occupation_list = new QLabel(Resources);
        Cd_label_occupation_list->setObjectName("Cd_label_occupation_list");
        Cd_label_occupation_list->setGeometry(QRect(270, 130, 161, 21));
        Cd_label_occupation_list->setFont(font);
        Cd_label_occupation_list->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Cd_label_occupation_list->setAlignment(Qt::AlignCenter);
        Printer_label_occupation = new QLabel(Resources);
        Printer_label_occupation->setObjectName("Printer_label_occupation");
        Printer_label_occupation->setGeometry(QRect(140, 90, 71, 42));
        Printer_label_occupation->setFont(font);
        Printer_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: none;\n"
""));
        Printer_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        CD_Icon_label = new QLabel(Resources);
        CD_Icon_label->setObjectName("CD_Icon_label");
        CD_Icon_label->setGeometry(QRect(270, 50, 30, 30));
        CD_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/CD-ROM_Icon.png);"));
        CD_Header_Label = new QLabel(Resources);
        CD_Header_Label->setObjectName("CD_Header_Label");
        CD_Header_Label->setGeometry(QRect(320, 50, 111, 31));
        CD_Header_Label->setLayoutDirection(Qt::RightToLeft);
        CD_Header_Label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(235, 235, 235);\n"
"font: 16pt \"Futura Hv BT\";"));
        CD_Header_Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Plotter_label_occupation_list = new QLabel(Resources);
        Plotter_label_occupation_list->setObjectName("Plotter_label_occupation_list");
        Plotter_label_occupation_list->setGeometry(QRect(50, 290, 161, 21));
        Plotter_label_occupation_list->setFont(font);
        Plotter_label_occupation_list->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Plotter_label_occupation_list->setAlignment(Qt::AlignCenter);
        Printer_label_occupation_list = new QLabel(Resources);
        Printer_label_occupation_list->setObjectName("Printer_label_occupation_list");
        Printer_label_occupation_list->setGeometry(QRect(50, 130, 161, 20));
        Printer_label_occupation_list->setFont(font);
        Printer_label_occupation_list->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"color: rgb(52, 61, 85);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(237, 237, 237);"));
        Printer_label_occupation_list->setAlignment(Qt::AlignCenter);
        Cd_label_occupation = new QLabel(Resources);
        Cd_label_occupation->setObjectName("Cd_label_occupation");
        Cd_label_occupation->setGeometry(QRect(360, 90, 71, 42));
        Cd_label_occupation->setFont(font);
        Cd_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: none;\n"
""));
        Cd_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Cd_background_label = new QLabel(Resources);
        Cd_background_label->setObjectName("Cd_background_label");
        Cd_background_label->setGeometry(QRect(250, 30, 201, 141));
        Cd_background_label->setStyleSheet(QString::fromUtf8("background-color: rgb(106, 112, 129);\n"
"border-radius: 5px;"));
        Cd_background_label->setScaledContents(true);
        Plotter_label_occupation = new QLabel(Resources);
        Plotter_label_occupation->setObjectName("Plotter_label_occupation");
        Plotter_label_occupation->setGeometry(QRect(140, 250, 71, 42));
        Plotter_label_occupation->setFont(font);
        Plotter_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: none;\n"
""));
        Plotter_label_occupation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Printer_Header_Label = new QLabel(Resources);
        Printer_Header_Label->setObjectName("Printer_Header_Label");
        Printer_Header_Label->setGeometry(QRect(100, 50, 111, 31));
        Printer_Header_Label->setLayoutDirection(Qt::RightToLeft);
        Printer_Header_Label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(235, 235, 235);\n"
"font: 16pt \"Futura Hv BT\";"));
        Printer_Header_Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Plotter_Header_Label = new QLabel(Resources);
        Plotter_Header_Label->setObjectName("Plotter_Header_Label");
        Plotter_Header_Label->setGeometry(QRect(100, 210, 111, 31));
        Plotter_Header_Label->setLayoutDirection(Qt::RightToLeft);
        Plotter_Header_Label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(235, 235, 235);\n"
"font: 16pt \"Futura Hv BT\";"));
        Plotter_Header_Label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        Plotter_Icon_label = new QLabel(Resources);
        Plotter_Icon_label->setObjectName("Plotter_Icon_label");
        Plotter_Icon_label->setGeometry(QRect(50, 210, 30, 30));
        Plotter_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/Plotter_Icon.png);"));
        Plotter_background_label = new QLabel(Resources);
        Plotter_background_label->setObjectName("Plotter_background_label");
        Plotter_background_label->setGeometry(QRect(30, 190, 201, 141));
        Plotter_background_label->setStyleSheet(QString::fromUtf8("background-color: rgb(106, 112, 129);\n"
"border-radius: 5px;"));
        Plotter_background_label->setScaledContents(true);
        Printer_background_label = new QLabel(Resources);
        Printer_background_label->setObjectName("Printer_background_label");
        Printer_background_label->setGeometry(QRect(30, 30, 201, 141));
        Printer_background_label->setStyleSheet(QString::fromUtf8("background-color: rgb(106, 112, 129);\n"
"border-radius: 5px;"));
        Printer_background_label->setScaledContents(true);
        Printer_Icon_label = new QLabel(Resources);
        Printer_Icon_label->setObjectName("Printer_Icon_label");
        Printer_Icon_label->setGeometry(QRect(50, 50, 30, 30));
        Printer_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/Printer_Icon.png);"));
        background_resources->raise();
        Printer_background_label->raise();
        Plotter_background_label->raise();
        Plotter_Icon_label->raise();
        Plotter_Header_Label->raise();
        Printer_Header_Label->raise();
        Plotter_label_occupation->raise();
        Cd_background_label->raise();
        Cd_label_occupation->raise();
        Printer_label_occupation_list->raise();
        Cd_label_occupation_list->raise();
        Plotter_label_occupation_list->raise();
        CD_Header_Label->raise();
        CD_Icon_label->raise();
        Printer_label_occupation->raise();
        free_Printer_label->raise();
        Tapedrive_background_label->raise();
        TapeDrive_Icon_label->raise();
        Tapedrive_label_occupation_list->raise();
        free_TapeDrive_label->raise();
        Tapedrive_label_occupation->raise();
        free_CD_label->raise();
        TapeDrive_Header_Label->raise();
        free_Plotter_label->raise();
        Printer_Icon_label->raise();

        OverviewAndResources->addWidget(Resources);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(550, 20, 591, 801));
        Matrices = new QVBoxLayout(layoutWidget1);
        Matrices->setObjectName("Matrices");
        Matrices->setContentsMargins(0, 0, 0, 0);
        RequirementsMatrix = new QGroupBox(layoutWidget1);
        RequirementsMatrix->setObjectName("RequirementsMatrix");
        RequirementsMatrix->setStyleSheet(QString::fromUtf8("border: none;"));
        RequirementsMatrix->setFlat(true);
        Needed_Matrix_Label = new QLabel(RequirementsMatrix);
        Needed_Matrix_Label->setObjectName("Needed_Matrix_Label");
        Needed_Matrix_Label->setGeometry(QRect(0, 0, 591, 371));
        Needed_Matrix_Label->setStyleSheet(QString::fromUtf8("background-color: rgb(73, 81, 103);\n"
"border-radius: 10px;\n"
""));
        Requirements_headline_label = new QLabel(RequirementsMatrix);
        Requirements_headline_label->setObjectName("Requirements_headline_label");
        Requirements_headline_label->setGeometry(QRect(40, 30, 171, 31));
        Requirements_headline_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(235, 235, 235);\n"
"font: 18pt \"Futura Hv BT\";"));
        frame = new QFrame(RequirementsMatrix);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(40, 100, 501, 211));
        frame->setStyleSheet(QString::fromUtf8("background-color: none;"));
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setObjectName("gridLayout_2");
        A2_label_needed = new QLabel(frame);
        A2_label_needed->setObjectName("A2_label_needed");
        A2_label_needed->setFont(font);
        A2_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A2_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(A2_label_needed, 1, 2, 1, 1);

        B4_label_needed = new QLabel(frame);
        B4_label_needed->setObjectName("B4_label_needed");
        B4_label_needed->setFont(font);
        B4_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B4_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(B4_label_needed, 2, 4, 1, 1);

        Requirements_Plotter_Icon_label = new QLabel(frame);
        Requirements_Plotter_Icon_label->setObjectName("Requirements_Plotter_Icon_label");
        Requirements_Plotter_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/Plotter_Icon.png);"));

        gridLayout_2->addWidget(Requirements_Plotter_Icon_label, 0, 3, 1, 1);

        A3_label_needed = new QLabel(frame);
        A3_label_needed->setObjectName("A3_label_needed");
        A3_label_needed->setFont(font);
        A3_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A3_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(A3_label_needed, 1, 3, 1, 1);

        Requirements_CD_Icon_label = new QLabel(frame);
        Requirements_CD_Icon_label->setObjectName("Requirements_CD_Icon_label");
        Requirements_CD_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/CD-ROM_Icon.png);"));

        gridLayout_2->addWidget(Requirements_CD_Icon_label, 0, 2, 1, 1);

        C2_label_needed = new QLabel(frame);
        C2_label_needed->setObjectName("C2_label_needed");
        C2_label_needed->setFont(font);
        C2_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C2_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(C2_label_needed, 3, 2, 1, 1);

        Requirements_Process_B_Label = new QLabel(frame);
        Requirements_Process_B_Label->setObjectName("Requirements_Process_B_Label");
        Requirements_Process_B_Label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 12pt \"Futura Bk BT\";"));

        gridLayout_2->addWidget(Requirements_Process_B_Label, 2, 0, 1, 1);

        A1_label_needed = new QLabel(frame);
        A1_label_needed->setObjectName("A1_label_needed");
        A1_label_needed->setFont(font);
        A1_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A1_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(A1_label_needed, 1, 1, 1, 1);

        B2_label_needed = new QLabel(frame);
        B2_label_needed->setObjectName("B2_label_needed");
        B2_label_needed->setFont(font);
        B2_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B2_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(B2_label_needed, 2, 2, 1, 1);

        Requirements_Process_A_Label = new QLabel(frame);
        Requirements_Process_A_Label->setObjectName("Requirements_Process_A_Label");
        Requirements_Process_A_Label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 12pt \"Futura Bk BT\";"));

        gridLayout_2->addWidget(Requirements_Process_A_Label, 1, 0, 1, 1);

        Requirements_TapeDrive_Icon_label = new QLabel(frame);
        Requirements_TapeDrive_Icon_label->setObjectName("Requirements_TapeDrive_Icon_label");
        Requirements_TapeDrive_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/TapeDrive_Icon.png);"));

        gridLayout_2->addWidget(Requirements_TapeDrive_Icon_label, 0, 4, 1, 1);

        C4_label_needed = new QLabel(frame);
        C4_label_needed->setObjectName("C4_label_needed");
        C4_label_needed->setFont(font);
        C4_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(73, 81, 103);\n"
"font: 500 12pt \"Futura PT\";"));
        C4_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(C4_label_needed, 3, 4, 1, 1);

        Requirements_Printer_Icon_label = new QLabel(frame);
        Requirements_Printer_Icon_label->setObjectName("Requirements_Printer_Icon_label");
        Requirements_Printer_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/Printer_Icon.png);"));

        gridLayout_2->addWidget(Requirements_Printer_Icon_label, 0, 1, 1, 1);

        Requirements_Process_C_Label = new QLabel(frame);
        Requirements_Process_C_Label->setObjectName("Requirements_Process_C_Label");
        Requirements_Process_C_Label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 12pt \"Futura Bk BT\";\n"
""));

        gridLayout_2->addWidget(Requirements_Process_C_Label, 3, 0, 1, 1);

        B3_label_needed = new QLabel(frame);
        B3_label_needed->setObjectName("B3_label_needed");
        B3_label_needed->setFont(font);
        B3_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B3_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(B3_label_needed, 2, 3, 1, 1);

        A4_label_needed = new QLabel(frame);
        A4_label_needed->setObjectName("A4_label_needed");
        A4_label_needed->setFont(font);
        A4_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A4_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(A4_label_needed, 1, 4, 1, 1);

        B1_label_needed = new QLabel(frame);
        B1_label_needed->setObjectName("B1_label_needed");
        B1_label_needed->setFont(font);
        B1_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B1_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(B1_label_needed, 2, 1, 1, 1);

        C3_label_needed = new QLabel(frame);
        C3_label_needed->setObjectName("C3_label_needed");
        C3_label_needed->setFont(font);
        C3_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C3_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(C3_label_needed, 3, 3, 1, 1);

        C1_label_needed = new QLabel(frame);
        C1_label_needed->setObjectName("C1_label_needed");
        C1_label_needed->setFont(font);
        C1_label_needed->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C1_label_needed->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(C1_label_needed, 3, 1, 1, 1);


        Matrices->addWidget(RequirementsMatrix);

        OccupationMatrix = new QGroupBox(layoutWidget1);
        OccupationMatrix->setObjectName("OccupationMatrix");
        OccupationMatrix->setStyleSheet(QString::fromUtf8("border: none;"));
        OccupationMatrix->setFlat(true);
        Occupation_Matrix_Label = new QLabel(OccupationMatrix);
        Occupation_Matrix_Label->setObjectName("Occupation_Matrix_Label");
        Occupation_Matrix_Label->setGeometry(QRect(0, 0, 591, 351));
        Occupation_Matrix_Label->setStyleSheet(QString::fromUtf8("background-color: rgb(73, 81, 103);\n"
"border-radius: 10px;"));
        Occupation_headline_label = new QLabel(OccupationMatrix);
        Occupation_headline_label->setObjectName("Occupation_headline_label");
        Occupation_headline_label->setGeometry(QRect(40, 30, 141, 31));
        Occupation_headline_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(235, 235, 235);\n"
"font: 18pt \"Futura Hv BT\";"));
        occupation_frame = new QFrame(OccupationMatrix);
        occupation_frame->setObjectName("occupation_frame");
        occupation_frame->setGeometry(QRect(40, 80, 501, 231));
        occupation_frame->setStyleSheet(QString::fromUtf8("background-color: none;"));
        gridLayout = new QGridLayout(occupation_frame);
        gridLayout->setObjectName("gridLayout");
        Occupation_Printer_Icon_label = new QLabel(occupation_frame);
        Occupation_Printer_Icon_label->setObjectName("Occupation_Printer_Icon_label");
        Occupation_Printer_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/Printer_Icon.png);"));

        gridLayout->addWidget(Occupation_Printer_Icon_label, 0, 1, 1, 1);

        Occupation_CD_Icon_label = new QLabel(occupation_frame);
        Occupation_CD_Icon_label->setObjectName("Occupation_CD_Icon_label");
        Occupation_CD_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/CD-ROM_Icon.png);"));

        gridLayout->addWidget(Occupation_CD_Icon_label, 0, 2, 1, 1);

        Occupation_Plotter_Icon_label = new QLabel(occupation_frame);
        Occupation_Plotter_Icon_label->setObjectName("Occupation_Plotter_Icon_label");
        Occupation_Plotter_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/Plotter_Icon.png);"));

        gridLayout->addWidget(Occupation_Plotter_Icon_label, 0, 3, 1, 1);

        Occupation_TapeDrive_Icon_label = new QLabel(occupation_frame);
        Occupation_TapeDrive_Icon_label->setObjectName("Occupation_TapeDrive_Icon_label");
        Occupation_TapeDrive_Icon_label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/TapeDrive_Icon.png);"));

        gridLayout->addWidget(Occupation_TapeDrive_Icon_label, 0, 4, 1, 1);

        Occupation_Process_A_Label = new QLabel(occupation_frame);
        Occupation_Process_A_Label->setObjectName("Occupation_Process_A_Label");
        Occupation_Process_A_Label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 12pt \"Futura Bk BT\";"));

        gridLayout->addWidget(Occupation_Process_A_Label, 1, 0, 1, 1);

        A1_label_occupation = new QLabel(occupation_frame);
        A1_label_occupation->setObjectName("A1_label_occupation");
        A1_label_occupation->setFont(font);
        A1_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A1_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(A1_label_occupation, 1, 1, 1, 1);

        A2_label_occupation = new QLabel(occupation_frame);
        A2_label_occupation->setObjectName("A2_label_occupation");
        A2_label_occupation->setFont(font);
        A2_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A2_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(A2_label_occupation, 1, 2, 1, 1);

        A3_label_occupation = new QLabel(occupation_frame);
        A3_label_occupation->setObjectName("A3_label_occupation");
        A3_label_occupation->setFont(font);
        A3_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A3_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(A3_label_occupation, 1, 3, 1, 1);

        A4_label_occupation = new QLabel(occupation_frame);
        A4_label_occupation->setObjectName("A4_label_occupation");
        A4_label_occupation->setFont(font);
        A4_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        A4_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(A4_label_occupation, 1, 4, 1, 1);

        Occupation_Process_B_Label = new QLabel(occupation_frame);
        Occupation_Process_B_Label->setObjectName("Occupation_Process_B_Label");
        Occupation_Process_B_Label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 12pt \"Futura Bk BT\";"));

        gridLayout->addWidget(Occupation_Process_B_Label, 2, 0, 1, 1);

        B3_label_occupation = new QLabel(occupation_frame);
        B3_label_occupation->setObjectName("B3_label_occupation");
        B3_label_occupation->setFont(font);
        B3_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B3_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(B3_label_occupation, 2, 3, 1, 1);

        B1_label_occupation = new QLabel(occupation_frame);
        B1_label_occupation->setObjectName("B1_label_occupation");
        B1_label_occupation->setFont(font);
        B1_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B1_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(B1_label_occupation, 2, 1, 1, 1);

        B2_label_occupation = new QLabel(occupation_frame);
        B2_label_occupation->setObjectName("B2_label_occupation");
        B2_label_occupation->setFont(font);
        B2_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B2_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(B2_label_occupation, 2, 2, 1, 1);

        B4_label_occupation = new QLabel(occupation_frame);
        B4_label_occupation->setObjectName("B4_label_occupation");
        B4_label_occupation->setFont(font);
        B4_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        B4_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(B4_label_occupation, 2, 4, 1, 1);

        C3_label_occupation = new QLabel(occupation_frame);
        C3_label_occupation->setObjectName("C3_label_occupation");
        C3_label_occupation->setFont(font);
        C3_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C3_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(C3_label_occupation, 3, 3, 1, 1);

        C4_label_occupation = new QLabel(occupation_frame);
        C4_label_occupation->setObjectName("C4_label_occupation");
        C4_label_occupation->setFont(font);
        C4_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"background-color: rgb(73, 81, 103);\n"
"font: 500 12pt \"Futura PT\";"));
        C4_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(C4_label_occupation, 3, 4, 1, 1);

        C2_label_occupation = new QLabel(occupation_frame);
        C2_label_occupation->setObjectName("C2_label_occupation");
        C2_label_occupation->setFont(font);
        C2_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C2_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(C2_label_occupation, 3, 2, 1, 1);

        C1_label_occupation = new QLabel(occupation_frame);
        C1_label_occupation->setObjectName("C1_label_occupation");
        C1_label_occupation->setFont(font);
        C1_label_occupation->setStyleSheet(QString::fromUtf8("color: rgb(217, 217, 217);\n"
"font: 500 12pt \"Futura PT\";\n"
"background-color: rgb(73, 81, 103);"));
        C1_label_occupation->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(C1_label_occupation, 3, 1, 1, 1);

        Occupation_Process_C_Label = new QLabel(occupation_frame);
        Occupation_Process_C_Label->setObjectName("Occupation_Process_C_Label");
        Occupation_Process_C_Label->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"color: rgb(237, 237, 237);\n"
"font: 12pt \"Futura Bk BT\";\n"
""));

        gridLayout->addWidget(Occupation_Process_C_Label, 3, 0, 1, 1);


        Matrices->addWidget(OccupationMatrix);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1550, 31));
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
        explanation_Background_Label->setText(QString());
        explanation_Title_label->setText(QCoreApplication::translate("MainWindow", "Algorithm:", nullptr));
        explanation_plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "testtext\n"
"", nullptr));
        Overview_background_label->setText(QString());
        Overview_title_label->setText(QCoreApplication::translate("MainWindow", "Simulation Running: ", nullptr));
        label_time->setText(QCoreApplication::translate("MainWindow", "00:00:000", nullptr));
        button_start_simulation->setText(QCoreApplication::translate("MainWindow", "Start Simulation", nullptr));
        button_restart_simulation->setText(QString());
        CurrentAlgorithm_label_indicator->setText(QCoreApplication::translate("MainWindow", "Algorithm:", nullptr));
        plainTextEdit_RequestInfo->setPlainText(QString());
        button_stop_simulation->setText(QCoreApplication::translate("MainWindow", "Stop Simulation", nullptr));
        CurrentAlgorithm_label->setText(QCoreApplication::translate("MainWindow", "Default", nullptr));
        background_resources->setText(QString());
        free_Printer_label->setText(QCoreApplication::translate("MainWindow", "occupied:", nullptr));
        Tapedrive_background_label->setText(QString());
        TapeDrive_Icon_label->setText(QString());
        Tapedrive_label_occupation_list->setText(QString());
        free_TapeDrive_label->setText(QCoreApplication::translate("MainWindow", "occupied:", nullptr));
        Tapedrive_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        free_CD_label->setText(QCoreApplication::translate("MainWindow", "occupied:", nullptr));
        TapeDrive_Header_Label->setText(QCoreApplication::translate("MainWindow", "TapeDrive", nullptr));
        free_Plotter_label->setText(QCoreApplication::translate("MainWindow", "occupied:", nullptr));
        Cd_label_occupation_list->setText(QString());
        Printer_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        CD_Icon_label->setText(QString());
        CD_Header_Label->setText(QCoreApplication::translate("MainWindow", "CD-ROM", nullptr));
        Plotter_label_occupation_list->setText(QString());
        Printer_label_occupation_list->setText(QString());
        Cd_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Cd_background_label->setText(QString());
        Plotter_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Printer_Header_Label->setText(QCoreApplication::translate("MainWindow", "Printer", nullptr));
        Plotter_Header_Label->setText(QCoreApplication::translate("MainWindow", "Plotter", nullptr));
        Plotter_Icon_label->setText(QString());
        Plotter_background_label->setText(QString());
        Printer_background_label->setText(QString());
        Printer_Icon_label->setText(QString());
        Needed_Matrix_Label->setText(QString());
        Requirements_headline_label->setText(QCoreApplication::translate("MainWindow", "Requirements", nullptr));
        A2_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B4_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Requirements_Plotter_Icon_label->setText(QString());
        A3_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Requirements_CD_Icon_label->setText(QString());
        C2_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Requirements_Process_B_Label->setText(QCoreApplication::translate("MainWindow", "Process B", nullptr));
        A1_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B2_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Requirements_Process_A_Label->setText(QCoreApplication::translate("MainWindow", "Process A", nullptr));
        Requirements_TapeDrive_Icon_label->setText(QString());
        C4_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Requirements_Printer_Icon_label->setText(QString());
        Requirements_Process_C_Label->setText(QCoreApplication::translate("MainWindow", "Process C", nullptr));
        B3_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A4_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B1_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C3_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C1_label_needed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Occupation_Matrix_Label->setText(QString());
        Occupation_headline_label->setText(QCoreApplication::translate("MainWindow", "Occupation", nullptr));
        Occupation_Printer_Icon_label->setText(QString());
        Occupation_CD_Icon_label->setText(QString());
        Occupation_Plotter_Icon_label->setText(QString());
        Occupation_TapeDrive_Icon_label->setText(QString());
        Occupation_Process_A_Label->setText(QCoreApplication::translate("MainWindow", "Process A", nullptr));
        A1_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A2_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A3_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        A4_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Occupation_Process_B_Label->setText(QCoreApplication::translate("MainWindow", "Process B", nullptr));
        B3_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B1_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B2_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        B4_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C3_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C4_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C2_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        C1_label_occupation->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Occupation_Process_C_Label->setText(QCoreApplication::translate("MainWindow", "Process C", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
