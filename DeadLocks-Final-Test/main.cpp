#include "mainwindow.h"
#include "systemprocess.h"
#include "systemressource.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
