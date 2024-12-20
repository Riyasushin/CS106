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
#include "ut-files.h"
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
    void openGameFile(std::string filename);
    ~Board();

private slots:
    void on_end_clicked();

    void on_restart_clicked();

    void on_huiqi_clicked();

    void on_save_clicked();

private:

    /**
     * @brief MARGEIN 边界距离，理边边差多少
     * @brief LINE 格线数量，实际有16条线，从0开始数的
     * @brief WIDTH 格的宽度
     * @brief R  棋子的半径
     * @brief EDGE  方便算棋子下的坐标
     *
     */
    const int MARGEIN = 50;
    const int x = MARGEIN, y = MARGEIN;
    const int LINE = 15;
    const int WIDTH = 40;
    const int R = 15;
    const int EDGE = WIDTH / 2;

    Ui::Board *ui;

    /**
     * @brief DrawGameBoard
     */
    void DrawGameBoard();

    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    void saveFile();
    QPainter *painter;
    game *Game;

    /**
     * @brief getPointAbsLocation
     * @param mouseX
     * @param mouseY
     * @return 根据鼠标真实坐标传回在棋盘上的相对坐标
     */
    std::pair<size_t, size_t> getPointAbsLocation(int mouseX, int mouseY);


    /**
     * @brief isSaved 状态量，目前棋盘中的数据和文件中数据不同就变成false
     * 空棋盘或者刚打开，视作保存了的
     */
    bool isSaved = true;

    /**
     * @brief hasSaved
     * @return 如果处于已保存状态返回TRUE,处于未保持状态返回false
     */
    bool hasSaved();

    /**
     * @brief turnToNotSaved
     * 更新后调用这个接口改变isSaved状态为false
     * 下完一棋后。悔棋后、重新开始后

     */
    void NotSave();

    /**
     * @brief YesSaved
     *   保存数据后
     */
    void YesSaved();

    /**
     * @brief filename : 这一场GAME最后被保存的地方，“”意味着从来没被保存
     */
    std::string filename = "";




signals:
    void goBackStart();


};

#endif // BOARD_H
