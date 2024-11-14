#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "board.h"

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
    void on_pve_clicked();

private:
    Ui::Widget *ui;
    Ui::Board * bb;
};
#endif // WIDGET_H
