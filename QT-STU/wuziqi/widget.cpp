#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{


    Widget::openGame("");

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
    std::vector<std::string> filelist = filemul::readFileList(Game::GAMEFILESUF);
    if (filelist.empty()) {
        /// 找不到可行的棋局
        /// 提示
        QString dialtitle = "prompt";
        QString strInfo = "没有找到可选择的对局文件，是否新建一个对局";
        QMessageBox::StandardButton result=QMessageBox::question(this, dialtitle, strInfo,
                                                                   QMessageBox::Yes|QMessageBox::No );
        if (result == QMessageBox::Yes) {
            Widget::openGame("");
        } else {

        }
    } else {


    }
    /// 弹出一个列表选择读取哪一个棋局

    /// 向游戏界面传递选择的棋局
    /// 需要一个信号槽吗？？？？？？
}

void Widget::openGame(std::string oldfiles){
    ui->setupUi(this);

    this->setWindowTitle("五子棋v1.12.0");

    board = new Board;
    if (oldfiles.size() > 0) {
        board->openGameFile(oldfiles);
    }
    connect(board, &Board::goBackStart, this, [=](){
        this->show();
        board->hide();
    });
}
