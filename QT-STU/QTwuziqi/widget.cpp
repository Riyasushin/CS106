#include "widget.h"
#include "ui_widget.h"
#include "board.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    bb = new Board;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pve_clicked()
{
    this->hide();
    bb->show();
}

