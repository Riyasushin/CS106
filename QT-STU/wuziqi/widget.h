#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "board.h"
#include "filemul.h"


///// 登录界面和设计界面
///

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pvp_clicked();

    void on_load_clicked();

private:
    Ui::Widget *ui;
    /// 为什么不是Ui::
    Board *board;
};
#endif // WIDGET_H
