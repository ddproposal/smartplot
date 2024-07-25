#include "pwidget.h"
#include "mywidget.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    mywidget w;
//    PWidget w;
    MainWindow w;
    w.show();
    return a.exec();
}
