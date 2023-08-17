/********************************************************************************
** Form generated from reading UI file 'startdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTDIALOG_H
#define UI_STARTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StartDialog
{
public:
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radio_holdwait;
    QRadioButton *radio_preempt;
    QRadioButton *radio_circularw;
    QRadioButton *radio_bankier;
    QPushButton *startSimulationButton;
    QLabel *label_background;
    QLabel *label_Header;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_Printer;
    QSpinBox *spinBox_TapeDrive;
    QSpinBox *spinBox_Cd;
    QLabel *label_CD_Icon;
    QLabel *label_Printer_Icon;
    QLabel *label_Plotter_Icon;
    QLabel *label_TapeDrive_Icon;
    QSpinBox *spinBox_Plotter;
    QPushButton *openGithubButton;

    void setupUi(QDialog *StartDialog)
    {
        if (StartDialog->objectName().isEmpty())
            StartDialog->setObjectName("StartDialog");
        StartDialog->resize(500, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartDialog->sizePolicy().hasHeightForWidth());
        StartDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/Icon_White.png"), QSize(), QIcon::Normal, QIcon::Off);
        StartDialog->setWindowIcon(icon);
        StartDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 61, 85);"));
        frame = new QFrame(StartDialog);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(140, 100, 231, 151));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(73, 81, 103);\n"
""));
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName("verticalLayout_3");
        radio_holdwait = new QRadioButton(frame);
        radio_holdwait->setObjectName("radio_holdwait");
        radio_holdwait->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 14pt \"Futura Bk BT\";\n"
"	color: rgb(105, 111, 128);\n"
"    spacing: 20px;\n"
"	background-color:none;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 19px;\n"
"    height: 19px;\n"
"}\n"
"\n"
"QRadioButton::hover,\n"
"QRadioButton::checked {\n"
"	color:  rgb(217, 217, 217);\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"	image: url(:/resources/checkBox_off.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"	image: url(:/resources/checkBox_on_hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"	image: url(:/resources/checkBox_off_hover.png);\n"
"}\n"
""));

        verticalLayout_3->addWidget(radio_holdwait);

        radio_preempt = new QRadioButton(frame);
        radio_preempt->setObjectName("radio_preempt");
        radio_preempt->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 14pt \"Futura Bk BT\";\n"
"	color: rgb(105, 111, 128);\n"
"    spacing: 20px;\n"
"	background-color:none;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 19px;\n"
"    height: 19px;\n"
"}\n"
"\n"
"QRadioButton::hover,\n"
"QRadioButton::checked {\n"
"	color:  rgb(217, 217, 217);\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"	image: url(:/resources/checkBox_off.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"	image: url(:/resources/checkBox_on_hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"	image: url(:/resources/checkBox_off_hover.png);\n"
"}\n"
""));

        verticalLayout_3->addWidget(radio_preempt);

        radio_circularw = new QRadioButton(frame);
        radio_circularw->setObjectName("radio_circularw");
        radio_circularw->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 14pt \"Futura Bk BT\";\n"
"	color: rgb(105, 111, 128);\n"
"    spacing: 20px;\n"
"	background-color:none;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 19px;\n"
"    height: 19px;\n"
"}\n"
"\n"
"QRadioButton::hover,\n"
"QRadioButton::checked {\n"
"	color:  rgb(217, 217, 217);\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"	image: url(:/resources/checkBox_off.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"	image: url(:/resources/checkBox_on_hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"	image: url(:/resources/checkBox_off_hover.png);\n"
"}\n"
""));

        verticalLayout_3->addWidget(radio_circularw);

        radio_bankier = new QRadioButton(frame);
        radio_bankier->setObjectName("radio_bankier");
        radio_bankier->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 14pt \"Futura Bk BT\";\n"
"	color: rgb(105, 111, 128);\n"
"    spacing: 20px;\n"
"	background-color:none;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"    width: 19px;\n"
"    height: 19px;\n"
"}\n"
"\n"
"QRadioButton::hover,\n"
"QRadioButton::checked {\n"
"	color:  rgb(217, 217, 217);\n"
"}\n"
"\n"
"\n"
"QRadioButton::indicator:unchecked {\n"
"	image: url(:/resources/checkBox_off.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"	image: url(:/resources/checkBox_on_hover.png);\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"	image: url(:/resources/checkBox_off_hover.png);\n"
"}\n"
""));

        verticalLayout_3->addWidget(radio_bankier);

        startSimulationButton = new QPushButton(StartDialog);
        startSimulationButton->setObjectName("startSimulationButton");
        startSimulationButton->setGeometry(QRect(110, 410, 271, 51));
        startSimulationButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(105, 111, 128);\n"
"	color: rgb(235, 235, 235);\n"
"	font: 18pt \"Futura Hv BT\";\n"
"}\n"
"QPushButton::pressed {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(43, 48, 63);\n"
"	color: rgb(217, 217, 217);\n"
"	font: 18pt \"Futura Hv BT\";\n"
"}\n"
"QPushButton::hover {\n"
"	background-color: rgb(152, 161, 186);\n"
"}\n"
""));
        startSimulationButton->setCheckable(false);
        label_background = new QLabel(StartDialog);
        label_background->setObjectName("label_background");
        label_background->setGeometry(QRect(60, 30, 371, 531));
        label_background->setStyleSheet(QString::fromUtf8("background-color: rgb(73, 81, 103);\n"
"border-radius: 5px;"));
        label_Header = new QLabel(StartDialog);
        label_Header->setObjectName("label_Header");
        label_Header->setGeometry(QRect(110, 60, 271, 31));
        label_Header->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 18pt \"Futura Hv BT\";\n"
"background-color: none;\n"
""));
        label_Header->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(StartDialog);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(100, 260, 291, 116));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: none;"));
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName("gridLayout");
        spinBox_Printer = new QSpinBox(frame_2);
        spinBox_Printer->setObjectName("spinBox_Printer");
        spinBox_Printer->setStyleSheet(QString::fromUtf8(" QSpinBox {\n"
"    padding-right: 15px; /* make room for the arrows */\n"
"    border-width: 5px;\n"
"	border-radius: 3px;\n"
"	color: rgb(217, 217, 217);\n"
"	background-color: rgb(105, 111, 128);\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"	border-radius: 3px;\n"
"    subcontrol-position:  top right; \n"
"	background-color: rgb(152, 161, 186);\n"
"    width: 20px;\n"
"    border-width: 3px;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"	background-color: rgb(183, 194, 224);\n"
"}\n"
"\n"
"QSpinBox::up-arrow {\n"
"	image: url(:/resources/arrow_up.png);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"	border-radius: 3px;\n"
"    subcontrol-position:  bottom right; /* position at the top right corner */\n"
"	background-color: rgb(152, 161, 186);\n"
"    width: 20px; /* 16 + 2*1px border-width = 15px padding + 3px parent border */\n"
"    border-width: 3px;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"	background-color: rgb"
                        "(183, 194, 224);\n"
"}\n"
"\n"
"QSpinBox::down-arrow {\n"
"	image: url(:/resources/arrow_down.png);\n"
"}\n"
""));
        spinBox_Printer->setMinimum(2);
        spinBox_Printer->setMaximum(10);

        gridLayout->addWidget(spinBox_Printer, 1, 0, 1, 1);

        spinBox_TapeDrive = new QSpinBox(frame_2);
        spinBox_TapeDrive->setObjectName("spinBox_TapeDrive");
        spinBox_TapeDrive->setStyleSheet(QString::fromUtf8(" QSpinBox {\n"
"    padding-right: 15px; /* make room for the arrows */\n"
"    border-width: 5px;\n"
"	border-radius: 3px;\n"
"	color: rgb(217, 217, 217);\n"
"	background-color: rgb(105, 111, 128);\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"	border-radius: 3px;\n"
"    subcontrol-position:  top right; \n"
"	background-color: rgb(152, 161, 186);\n"
"    width: 20px;\n"
"    border-width: 3px;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"	background-color: rgb(183, 194, 224);\n"
"}\n"
"\n"
"QSpinBox::up-arrow {\n"
"	image: url(:/resources/arrow_up.png);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"	border-radius: 3px;\n"
"    subcontrol-position:  bottom right; /* position at the top right corner */\n"
"	background-color: rgb(152, 161, 186);\n"
"    width: 20px; /* 16 + 2*1px border-width = 15px padding + 3px parent border */\n"
"    border-width: 3px;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"	background-color: rgb"
                        "(183, 194, 224);\n"
"}\n"
"\n"
"QSpinBox::down-arrow {\n"
"	image: url(:/resources/arrow_down.png);\n"
"}\n"
""));
        spinBox_TapeDrive->setMinimum(2);
        spinBox_TapeDrive->setMaximum(10);

        gridLayout->addWidget(spinBox_TapeDrive, 1, 3, 1, 1);

        spinBox_Cd = new QSpinBox(frame_2);
        spinBox_Cd->setObjectName("spinBox_Cd");
        spinBox_Cd->setStyleSheet(QString::fromUtf8(" QSpinBox {\n"
"    padding-right: 15px; /* make room for the arrows */\n"
"    border-width: 5px;\n"
"	border-radius: 3px;\n"
"	color: rgb(217, 217, 217);\n"
"	background-color: rgb(105, 111, 128);\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"	border-radius: 3px;\n"
"    subcontrol-position:  top right; \n"
"	background-color: rgb(152, 161, 186);\n"
"    width: 20px;\n"
"    border-width: 3px;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"	background-color: rgb(183, 194, 224);\n"
"}\n"
"\n"
"QSpinBox::up-arrow {\n"
"	image: url(:/resources/arrow_up.png);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"	border-radius: 3px;\n"
"    subcontrol-position:  bottom right; /* position at the top right corner */\n"
"	background-color: rgb(152, 161, 186);\n"
"    width: 20px; /* 16 + 2*1px border-width = 15px padding + 3px parent border */\n"
"    border-width: 3px;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"	background-color: rgb"
                        "(183, 194, 224);\n"
"}\n"
"\n"
"QSpinBox::down-arrow {\n"
"	image: url(:/resources/arrow_down.png);\n"
"}\n"
"\n"
""));
        spinBox_Cd->setMinimum(2);
        spinBox_Cd->setMaximum(10);

        gridLayout->addWidget(spinBox_Cd, 1, 1, 1, 1);

        label_CD_Icon = new QLabel(frame_2);
        label_CD_Icon->setObjectName("label_CD_Icon");
        label_CD_Icon->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/CD-ROM_Icon.png);"));

        gridLayout->addWidget(label_CD_Icon, 0, 1, 1, 1);

        label_Printer_Icon = new QLabel(frame_2);
        label_Printer_Icon->setObjectName("label_Printer_Icon");
        label_Printer_Icon->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/Printer_Icon.png);"));

        gridLayout->addWidget(label_Printer_Icon, 0, 0, 1, 1);

        label_Plotter_Icon = new QLabel(frame_2);
        label_Plotter_Icon->setObjectName("label_Plotter_Icon");
        label_Plotter_Icon->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/Plotter_Icon.png);"));

        gridLayout->addWidget(label_Plotter_Icon, 0, 2, 1, 1);

        label_TapeDrive_Icon = new QLabel(frame_2);
        label_TapeDrive_Icon->setObjectName("label_TapeDrive_Icon");
        label_TapeDrive_Icon->setStyleSheet(QString::fromUtf8("background-color: none;\n"
"image: url(:/resources/TapeDrive_Icon.png);"));

        gridLayout->addWidget(label_TapeDrive_Icon, 0, 3, 1, 1);

        spinBox_Plotter = new QSpinBox(frame_2);
        spinBox_Plotter->setObjectName("spinBox_Plotter");
        spinBox_Plotter->setStyleSheet(QString::fromUtf8(" QSpinBox {\n"
"    padding-right: 15px; /* make room for the arrows */\n"
"    border-width: 5px;\n"
"	border-radius: 3px;\n"
"	color: rgb(217, 217, 217);\n"
"	background-color: rgb(105, 111, 128);\n"
"    padding: 8px;\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"    subcontrol-origin: border;\n"
"	border-radius: 3px;\n"
"    subcontrol-position:  top right; \n"
"	background-color: rgb(152, 161, 186);\n"
"    width: 20px;\n"
"    border-width: 3px;\n"
"}\n"
"\n"
"QSpinBox::up-button:hover {\n"
"	background-color: rgb(183, 194, 224);\n"
"}\n"
"\n"
"QSpinBox::up-arrow {\n"
"	image: url(:/resources/arrow_up.png);\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"    subcontrol-origin: border;\n"
"	border-radius: 3px;\n"
"    subcontrol-position:  bottom right; /* position at the top right corner */\n"
"	background-color: rgb(152, 161, 186);\n"
"    width: 20px; /* 16 + 2*1px border-width = 15px padding + 3px parent border */\n"
"    border-width: 3px;\n"
"}\n"
"\n"
"QSpinBox::down-button:hover {\n"
"	background-color: rgb"
                        "(183, 194, 224);\n"
"}\n"
"\n"
"QSpinBox::down-arrow {\n"
"	image: url(:/resources/arrow_down.png);\n"
"}\n"
""));
        spinBox_Plotter->setMinimum(2);
        spinBox_Plotter->setMaximum(10);

        gridLayout->addWidget(spinBox_Plotter, 1, 2, 1, 1);

        spinBox_Printer->raise();
        spinBox_TapeDrive->raise();
        spinBox_Cd->raise();
        label_CD_Icon->raise();
        label_Printer_Icon->raise();
        label_Plotter_Icon->raise();
        spinBox_Plotter->raise();
        label_TapeDrive_Icon->raise();
        openGithubButton = new QPushButton(StartDialog);
        openGithubButton->setObjectName("openGithubButton");
        openGithubButton->setGeometry(QRect(110, 480, 271, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura Hv BT")});
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setStrikeOut(false);
        font.setStyleStrategy(QFont::PreferDefault);
        openGithubButton->setFont(font);
        openGithubButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(105, 111, 128);\n"
"	color: rgb(235, 235, 235);\n"
"	font: 16pt \"Futura Hv BT\";\n"
"}\n"
"QPushButton::pressed {\n"
"    border-radius: 5px;\n"
"	background-color: rgb(43, 48, 63);\n"
"	color: rgb(217, 217, 217);\n"
"	font: 18pt \"Futura Hv BT\";\n"
"}\n"
"QPushButton::hover {\n"
"	background-color: rgb(152, 161, 186);\n"
"}\n"
""));
        openGithubButton->setCheckable(false);
        label_background->raise();
        frame->raise();
        startSimulationButton->raise();
        label_Header->raise();
        frame_2->raise();
        openGithubButton->raise();

        retranslateUi(StartDialog);
        QObject::connect(startSimulationButton, &QPushButton::clicked, StartDialog, qOverload<>(&QDialog::accept));
        QObject::connect(StartDialog, &QDialog::rejected, StartDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(StartDialog);
    } // setupUi

    void retranslateUi(QDialog *StartDialog)
    {
        StartDialog->setWindowTitle(QCoreApplication::translate("StartDialog", "Dialog", nullptr));
        radio_holdwait->setText(QCoreApplication::translate("StartDialog", "Hold and Wait", nullptr));
        radio_preempt->setText(QCoreApplication::translate("StartDialog", "No Preemption", nullptr));
        radio_circularw->setText(QCoreApplication::translate("StartDialog", "Circular Wait", nullptr));
        radio_bankier->setText(QCoreApplication::translate("StartDialog", "Bankier-Algorithm", nullptr));
        startSimulationButton->setText(QCoreApplication::translate("StartDialog", "confirm", nullptr));
        label_background->setText(QString());
        label_Header->setText(QCoreApplication::translate("StartDialog", "Deadlock Simulation", nullptr));
        label_CD_Icon->setText(QString());
        label_Printer_Icon->setText(QString());
        label_Plotter_Icon->setText(QString());
        label_TapeDrive_Icon->setText(QString());
        openGithubButton->setText(QCoreApplication::translate("StartDialog", "Our GitHub", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartDialog: public Ui_StartDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTDIALOG_H
