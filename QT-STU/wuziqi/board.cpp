#include "board.h"
#include "ui_board.h"

Board::Board(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Board)
{
    ui->setupUi(this);
}

Board::~Board()
{
    delete ui;
}

void Board::on_end_clicked()
{
    /// 判断保存了没有


    emit goBackStart();
}

