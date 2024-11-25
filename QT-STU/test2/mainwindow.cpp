#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
     ui->setupUi(this);

    // 设置布局
    QVBoxLayout *layout = new QVBoxLayout(this);

    // 创建按钮并连接到弹出窗口
    QPushButton *openWindowButton = new QPushButton("打开项目列表", this);
    connect(openWindowButton, &QPushButton::clicked, this, &MainWindow::openItemListWindow);

    layout->addWidget(openWindowButton);
    setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
