#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include <algorithm>
#include "game.h"
#include "filemul.h"
#include <stdio.h>


/// 棋盘界面

namespace Ui {
class Board;
}

class Board : public QWidget
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

private slots:
    void on_end_clicked();

    void on_restart_clicked();

    void on_huiqi_clicked();

    void on_save_clicked();

private:

    const int MARGEIN = 50;
    const int x = MARGEIN, y = MARGEIN;
    const int LINE = 15;
    const int WIDTH = 40;
    const int R = 15;
    const int EDGE = WIDTH / 2;

    Ui::Board *ui;
    void DrawGameBoard();

    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    void saveFile();
    QPainter *painter;
    Game *game;

    std::pair<int, int> getPointAbsLocation(int mouseX, int mouseY);

    bool isSaved = true; // 空棋盘或者刚打开，视作保存了的，没有更新过数据
    bool hasSaved(); /// TODO 保存对局后更新这一步，有新操作后更新
    void turnToNotSaved();
    std::string filename = "";

    void openGameFile(std::string filename);


signals:
    void goBackStart();


};

#endif // BOARD_H
