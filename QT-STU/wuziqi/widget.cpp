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

/// 准备载入残局
/// TODO
void Widget::on_load_clicked()
{
    /// 弹出一个列表选择读取哪一个棋局

    /// 向游戏界面传递选择的棋局
    /// 需要一个信号槽吗？？？？？？
}

