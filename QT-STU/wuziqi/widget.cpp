#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("五子棋v1.12.0");

    board = new Board;
    connect(board, &Board::goBackStart, this, [=](){
        this->show();
        board->hide();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pvp_clicked()
{
    this->hide();
    board->show();
}

