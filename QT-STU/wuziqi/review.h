#ifndef REVIEW_H
#define REVIEW_H

#include <QWidget>

namespace Ui {
class Review;
}

class Review : public QWidget
{
    Q_OBJECT

public:
    explicit Review(QWidget *parent = nullptr);
    ~Review();

private:
    Ui::Review *ui;
};

#endif // REVIEW_H
