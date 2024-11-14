#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <iostream>
#include <QDebug>
#include <QString>
#include <QMessageBox>
#include "game.h"

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
    QPainter *painter;
    Game *game;

    std::pair<int, int> getPointAbsLocation(int mouseX, int mouseY);


signals:
    void goBackStart();


};

#endif // BOARD_H
