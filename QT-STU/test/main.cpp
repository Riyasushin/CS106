#include <QCoreApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
