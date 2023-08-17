/********************************************************************************
** Form generated from reading UI file 'enddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENDDIALOG_H
#define UI_ENDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EndDialog
{
public:
    QLabel *label_background;
    QPushButton *end_pushButton;
    QLabel *label;
    QPushButton *restart_pushButton;
    QLabel *end_runtime_label;
    QLabel *resources;
    QLabel *end_resources_label;
    QLabel *statistics_label;
    QLabel *avg_A_value_label;
    QLabel *avg_A_label;
    QLabel *avg_C_value_label;
    QLabel *avg_B_label;
    QLabel *avg_B_value_label;
    QLabel *avg_C_label;
    QLabel *resources_5;

    void setupUi(QDialog *EndDialog)
    {
        if (EndDialog->objectName().isEmpty())
            EndDialog->setObjectName("EndDialog");
        EndDialog->resize(500, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/Icon_White.png"), QSize(), QIcon::Normal, QIcon::Off);
        EndDialog->setWindowIcon(icon);
        EndDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 61, 85);"));
        label_background = new QLabel(EndDialog);
        label_background->setObjectName("label_background");
        label_background->setGeometry(QRect(60, 60, 371, 501));
        label_background->setStyleSheet(QString::fromUtf8("background-color: rgb(73, 81, 103);\n"
"border-radius: 5px;"));
        end_pushButton = new QPushButton(EndDialog);
        end_pushButton->setObjectName("end_pushButton");
        end_pushButton->setGeometry(QRect(110, 480, 261, 51));
        end_pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label = new QLabel(EndDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 90, 291, 51));
        label->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 18pt \"Futura Hv BT\";\n"
"background-color: none;"));
        label->setAlignment(Qt::AlignCenter);
        restart_pushButton = new QPushButton(EndDialog);
        restart_pushButton->setObjectName("restart_pushButton");
        restart_pushButton->setGeometry(QRect(110, 420, 261, 51));
        restart_pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        end_runtime_label = new QLabel(EndDialog);
        end_runtime_label->setObjectName("end_runtime_label");
        end_runtime_label->setGeometry(QRect(220, 210, 151, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Futura Bk BT")});
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        end_runtime_label->setFont(font);
        end_runtime_label->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";\n"
"background-color: none;"));
        end_runtime_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        resources = new QLabel(EndDialog);
        resources->setObjectName("resources");
        resources->setGeometry(QRect(110, 240, 121, 31));
        resources->setFont(font);
        resources->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";\n"
"background-color: none;"));
        resources->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        end_resources_label = new QLabel(EndDialog);
        end_resources_label->setObjectName("end_resources_label");
        end_resources_label->setGeometry(QRect(220, 240, 151, 31));
        end_resources_label->setFont(font);
        end_resources_label->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";\n"
"background-color: none;"));
        end_resources_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        statistics_label = new QLabel(EndDialog);
        statistics_label->setObjectName("statistics_label");
        statistics_label->setGeometry(QRect(100, 130, 291, 51));
        statistics_label->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 14pt \"Futura Hv BT\";\n"
"background-color: none;"));
        statistics_label->setAlignment(Qt::AlignCenter);
        avg_A_value_label = new QLabel(EndDialog);
        avg_A_value_label->setObjectName("avg_A_value_label");
        avg_A_value_label->setGeometry(QRect(220, 270, 151, 31));
        avg_A_value_label->setFont(font);
        avg_A_value_label->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";\n"
"background-color: none;"));
        avg_A_value_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        avg_A_label = new QLabel(EndDialog);
        avg_A_label->setObjectName("avg_A_label");
        avg_A_label->setGeometry(QRect(110, 270, 251, 31));
        avg_A_label->setFont(font);
        avg_A_label->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";\n"
"background-color: none;"));
        avg_A_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        avg_C_value_label = new QLabel(EndDialog);
        avg_C_value_label->setObjectName("avg_C_value_label");
        avg_C_value_label->setGeometry(QRect(220, 330, 151, 31));
        avg_C_value_label->setFont(font);
        avg_C_value_label->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";\n"
"background-color: none;"));
        avg_C_value_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        avg_B_label = new QLabel(EndDialog);
        avg_B_label->setObjectName("avg_B_label");
        avg_B_label->setGeometry(QRect(110, 300, 261, 31));
        avg_B_label->setFont(font);
        avg_B_label->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";\n"
"background-color: none;"));
        avg_B_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        avg_B_value_label = new QLabel(EndDialog);
        avg_B_value_label->setObjectName("avg_B_value_label");
        avg_B_value_label->setGeometry(QRect(220, 300, 151, 31));
        avg_B_value_label->setFont(font);
        avg_B_value_label->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";\n"
"background-color: none;"));
        avg_B_value_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        avg_C_label = new QLabel(EndDialog);
        avg_C_label->setObjectName("avg_C_label");
        avg_C_label->setGeometry(QRect(110, 330, 251, 31));
        avg_C_label->setFont(font);
        avg_C_label->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";\n"
"background-color: none;"));
        avg_C_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        resources_5 = new QLabel(EndDialog);
        resources_5->setObjectName("resources_5");
        resources_5->setGeometry(QRect(110, 210, 121, 31));
        resources_5->setFont(font);
        resources_5->setStyleSheet(QString::fromUtf8("color: rgb(235, 235, 235);\n"
"font: 12pt \"Futura Bk BT\";\n"
"background-color: none;"));
        resources_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        retranslateUi(EndDialog);

        QMetaObject::connectSlotsByName(EndDialog);
    } // setupUi

    void retranslateUi(QDialog *EndDialog)
    {
        EndDialog->setWindowTitle(QCoreApplication::translate("EndDialog", "Deadlock Algorithm Simulation", nullptr));
        label_background->setText(QString());
        end_pushButton->setText(QCoreApplication::translate("EndDialog", "Close", nullptr));
        label->setText(QCoreApplication::translate("EndDialog", "Test Completed", nullptr));
        restart_pushButton->setText(QCoreApplication::translate("EndDialog", "Restart", nullptr));
        end_runtime_label->setText(QCoreApplication::translate("EndDialog", "0.00 s", nullptr));
        resources->setText(QCoreApplication::translate("EndDialog", "Resources:", nullptr));
        end_resources_label->setText(QCoreApplication::translate("EndDialog", "0", nullptr));
        statistics_label->setText(QCoreApplication::translate("EndDialog", "Statistics", nullptr));
        avg_A_value_label->setText(QCoreApplication::translate("EndDialog", "0", nullptr));
        avg_A_label->setText(QCoreApplication::translate("EndDialog", "average Resource Time A:", nullptr));
        avg_C_value_label->setText(QCoreApplication::translate("EndDialog", "0", nullptr));
        avg_B_label->setText(QCoreApplication::translate("EndDialog", "average Resource Time B:", nullptr));
        avg_B_value_label->setText(QCoreApplication::translate("EndDialog", "0", nullptr));
        avg_C_label->setText(QCoreApplication::translate("EndDialog", "average Resource Time C:", nullptr));
        resources_5->setText(QCoreApplication::translate("EndDialog", "Runtime", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EndDialog: public Ui_EndDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENDDIALOG_H
