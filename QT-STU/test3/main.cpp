
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QListWidget>
#include <QHBoxLayout>
#include <QDialog>
#include <QDebug>
#include "mainwindow.h"


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;
    window.setWindowTitle("主窗口");
    window.resize(300, 200);
    window.show();

    return app.exec();
}
