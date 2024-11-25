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
    /// TODO

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
    const std::vector<Game::Move>* s = game->getChequers();

    for (auto it = s->begin(), ed = s->end(); it != ed; ++it) {
            int x1 = it->x, y1 = it->y;

         //// TODO 把画棋子封装成小函数
        if (it->bai) { /// BAO LOU JIE KOU LE
            painter->setBrush(QBrush(Qt::white, Qt::SolidPattern));
            painter->drawEllipse(x + WIDTH * x1 - R, y + WIDTH * y1 - R, R * 2, R * 2);

        } else {
            painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));
            painter->drawEllipse(x + WIDTH * x1 - R, y + WIDTH * y1 - R, R * 2, R * 2);
        }
    }

    /// TODO 画虚拟的棋子

    painter->end();
}


/// 判断鼠标移动，预先画
/// todo
void Board::mouseMoveEvent(QMouseEvent *event) {
    int mouseX = event->x(), mouseY = event->y();
    /// around the board ,in play
    if (mouseX >= MARGEIN / 2 && mouseX <= MARGEIN + WIDTH * LINE + MARGEIN / 2
        && mouseY >= MARGEIN / 2 && mouseY <= MARGEIN + WIDTH * LINE + MARGEIN / 2) {

        qDebug() << "mouse move:" << mouseX << " " << mouseY;

    }

}

/// 鼠标释放，画实心的
void Board::mousePressEvent(QMouseEvent *event) {

    if (game->getWinner() != -1)
        return;

    int mouseX = event->x(), mouseY = event->y();
    /// around the board ,in play
    if (mouseX >= MARGEIN / 2 && mouseX <= MARGEIN + WIDTH * LINE + MARGEIN / 2
        && mouseY >= MARGEIN / 2 && mouseY <= MARGEIN + WIDTH * LINE + MARGEIN / 2) {

        qDebug() << mouseX << " " << mouseY;
        auto [absX, absY] = Board::getPointAbsLocation(mouseX, mouseY);

        bool canMove = game->canMakeMove(absX, absY);
        if (canMove) {

            Board::turnToNotSaved();
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
    if (hasSaved()) {

    } else {
        /// 没有被保存，弹出提示框进行保存
        QString dialtitle = "Warning";
        QString strInfo = "你的对局还没有保存，是否确定保存并退出";
        QMessageBox::StandardButton result=QMessageBox::question(this, dialtitle, strInfo,
                                                                   QMessageBox::Yes|QMessageBox::No |  QMessageBox::Cancel);
        if (result == QMessageBox::Yes) {
            /// TODO
            /// SAVE IT!!!
            Board::saveFile();

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

/// 保存文件
void Board::saveFile() {
    //// TODO
    /// 如果处于已保存状态不用理会
    /// 更改是否保存过这一变量

    if (filename.size() == 0) {
        std::stringstream oss;
        oss << __DATE__ << " " << __TIME__ << ".dat";
        filename = oss.str();
        std::replace(filename.begin(), filename.end(), ':', '-');
    }

    if (filemul::writeToFile(game->getChequers(),  filename  ) ) {
        qDebug() << "succeed saving the game";
    }
}

/// 重新开始对局
void Board::on_restart_clicked()
{
    /// 友好提示框
    QString dialtitle = "Warning";
    QString strInfo = "本操作不可撤销，确定重新开始吗";
    QMessageBox::StandardButton result=QMessageBox::question(this, dialtitle, strInfo,
                                                               QMessageBox::Yes|QMessageBox::No );
    if (result == QMessageBox::Yes) {
        /// TODO
        /// SAVE IT!!!
        game->restart();
        update();
    }

}


void Board::on_huiqi_clicked()
{
    /// TODO 怎么禁止AI 悔棋， 好像不用，因为AI 不会悔棋
    game->huiqi();
    update();
}

/// 按键保存
void Board::on_save_clicked()
{
    Board::saveFile();
}


bool Board::hasSaved() {
    return isSaved;
}

/// 根据传输得到的文件名
/// TODO
void Board::openGameFile(std::string filename) {
    /// 打开文件
    std::vector<Game::Move> his;


    /// 读取成功让GAME更新issaved filename等变量

}

void Board::turnToNotSaved() {
    isSaved = false;
}
