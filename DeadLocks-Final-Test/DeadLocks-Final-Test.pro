QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Algorithms/bankiersalgorithm.cpp \
    Algorithms/carefulresourcedistribution.cpp \
    Algorithms/deadlock_avoidance_api.cpp \
    Algorithms/eliminatecircularwait.cpp \
    Algorithms/eliminateholdandwait.cpp \
    Algorithms/preemptionworker.cpp \
    Dialogs/enddialog.cpp \
    Main/main.cpp \
    Main/mainwindow.cpp \
    Algorithms/noavoidancesimulation.cpp \
    Algorithms/nopreemption.cpp \
    Objects/processworker.cpp \
    Dialogs/startdialog.cpp \
    Objects/systemprocess.cpp \
    Objects/systemresource.cpp

HEADERS += \
    Algorithms/bankiersalgorithm.h \
    Algorithms/carefulresourcedistribution.h \
    Algorithms/deadlock_avoidance_api.h \
    Algorithms/eliminatecircularwait.h \
    Algorithms/eliminateholdandwait.h \
    Algorithms/preemptionworker.h \
    Dialogs/enddialog.h \
    Main/mainwindow.h \
    Algorithms/noavoidancesimulation.h \
    Algorithms/nopreemption.h \
    Objects/processworker.h \
    Dialogs/startdialog.h \
    Objects/systemprocess.h \
    Objects/systemresource.h

FORMS += \
    Dialogs/enddialog.ui \
    Main/mainwindow.ui \
    Dialogs/startdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    resources/checkBox_off.png \
    resources/checkBox_off_hover.png \
    resources/checkBox_on.png \
    resources/checkBox_on_hover.png \
    resources/reset_Icon.png \
    resources/restet_Icon.png
