#include "board.h"
#include "ui_board.h"
#include "game.h"


Board::Board(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Board)
{
    ui->setupUi(this);
    this->setWindowTitle("五子棋");

    /// START THE GAME
    game = new Game;

    //game->MakeMove(true, 0, 0);
    //game->MakeMove(false, 0, 1);

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

/// 绘制棋盘
void Board::paintEvent(QPaintEvent *event){



    painter = new QPainter;
    painter->begin(this);

    /// draw lines
    for (int i = 0; i <= LINE; ++i) {
        painter->drawLine(x, y + WIDTH * i, x + WIDTH * LINE, y + WIDTH * i);
    }
    for (int i = 0; i <= LINE; ++i) {
        painter->drawLine(x + WIDTH * i, y, x + WIDTH * i, y + WIDTH * LINE);
    }

    /// draw chequers
    const std::vector<Game::Move> s = game->getChequers();
    for (int i = 0, len = s.size(); i < len; ++i) {
        int x1 = s[i].x, y1 = s[i].y;
         //// TODO 把画棋子封装成小函数
        if (s[i].bai) { /// BAO LOU JIE KOU LE
            painter->setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter->drawEllipse(x + WIDTH * x1 - R, y + WIDTH * y1 - R, R * 2, R * 2);

        } else {
            painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));
            painter->drawEllipse(x + WIDTH * x1 - R, y + WIDTH * y1 - R, R * 2, R * 2);
        }
    }

    painter->end();
}


/// 判断鼠标移动，预先画
/// todo
void Board::mouseMoveEvent(QMouseEvent *event) {
    int mouseX = event->x(), mouseY = event->y();
    /// around the board ,in play
    if (mouseX >= MARGEIN / 2 && mouseX <= MARGEIN + WIDTH * LINE + MARGEIN / 2
        && mouseY >= MARGEIN / 2 && mouseY <= MARGEIN + WIDTH * LINE + MARGEIN / 2) {

        qDebug() << mouseX << " " << mouseY;

    }

}

/// 鼠标释放，画实心的
void Board::mousePressEvent(QMouseEvent *event) {

    if (game->isOver())
        return;

    int mouseX = event->x(), mouseY = event->y();
    /// around the board ,in play
    if (mouseX >= MARGEIN / 2 && mouseX <= MARGEIN + WIDTH * LINE + MARGEIN / 2
        && mouseY >= MARGEIN / 2 && mouseY <= MARGEIN + WIDTH * LINE + MARGEIN / 2) {

        qDebug() << mouseX << " " << mouseY;
        auto [absX, absY] = Board::getPointAbsLocation(mouseX, mouseY);

        bool canMove = game->canMakeMove(absX, absY);
        if (canMove) {


            game->MakeMove(absX, absY);

            update();

            if (game->win()) {
                //// todo 有BUG
                QString winner;
                QString title = "CONGRATULATION!!!";
                int whiteWin = game->getWinner();
                if (whiteWin == 1) {
                    //// TODO 人机时提示不一样的支付
                    winner = "白子胜";
                } else if (whiteWin == 0){
                    winner = "黑子胜";
                }
                QMessageBox::information(this, title, winner, QMessageBox::Ok, QMessageBox::NoButton);
            }
        }





    }
}

//// TODO 自定义内容
void Board::closeEvent(QCloseEvent *event) {
    if (game->hasSaved()) {

    } else {
        /// 没有被保存，弹出提示框进行保存
        QString dialtitle = "Warning";
        QString strInfo = "你的对局还没有保存，是否确定保存并退出";
        QMessageBox::StandardButton result=QMessageBox::question(this, dialtitle, strInfo,
                                                                   QMessageBox::Yes|QMessageBox::No |  QMessageBox::Cancel);
        if (result == QMessageBox::Yes) {
            /// TODO
            /// SAVE IT!!!
            event->accept();
        } else {
            event->ignore();
        }
    }
}


std::pair<int, int> Board::getPointAbsLocation(int mouseX, int mouseY) {
    int x, y;
    x = ( mouseX - MARGEIN + EDGE  - 1) / WIDTH;
    y = ( mouseY - MARGEIN + EDGE  - 1) / WIDTH;
    return std::make_pair(x, y);
}
