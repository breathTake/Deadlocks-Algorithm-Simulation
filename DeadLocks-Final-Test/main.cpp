#include "mainwindow.h"
#include "systemprocess.h"
#include "systemresource.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}



