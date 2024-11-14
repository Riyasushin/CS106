#ifndef BOARD_H
#define BOARD_H

#include <QWidget>

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
    const int MARGE = 50;
    const int GRID_SIZE = 50;
    const int qiziR = 10;

    Ui::Board *ui;
    void DrawGameBoard();


signals:
    void goBackStart();

};

#endif // BOARD_H
