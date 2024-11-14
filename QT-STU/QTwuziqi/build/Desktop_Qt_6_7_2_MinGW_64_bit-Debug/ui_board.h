/********************************************************************************
** Form generated from reading UI file 'board.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOARD_H
#define UI_BOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_board
{
public:
    QListWidget *playboard;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *huiqi;
    QPushButton *restart;
    QPushButton *letAIdo;
    QPushButton *save;
    QPushButton *out;

    void setupUi(QWidget *board)
    {
        if (board->objectName().isEmpty())
            board->setObjectName("board");
        board->resize(489, 325);
        playboard = new QListWidget(board);
        playboard->setObjectName("playboard");
        playboard->setGeometry(QRect(10, 20, 271, 261));
        layoutWidget = new QWidget(board);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(310, 70, 131, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        huiqi = new QPushButton(layoutWidget);
        huiqi->setObjectName("huiqi");
        QFont font;
        font.setPointSize(15);
        huiqi->setFont(font);

        verticalLayout->addWidget(huiqi);

        restart = new QPushButton(layoutWidget);
        restart->setObjectName("restart");
        restart->setFont(font);

        verticalLayout->addWidget(restart);

        letAIdo = new QPushButton(layoutWidget);
        letAIdo->setObjectName("letAIdo");
        letAIdo->setFont(font);

        verticalLayout->addWidget(letAIdo);

        save = new QPushButton(layoutWidget);
        save->setObjectName("save");
        save->setFont(font);

        verticalLayout->addWidget(save);

        out = new QPushButton(layoutWidget);
        out->setObjectName("out");
        out->setFont(font);

        verticalLayout->addWidget(out);


        retranslateUi(board);

        QMetaObject::connectSlotsByName(board);
    } // setupUi

    void retranslateUi(QWidget *board)
    {
        board->setWindowTitle(QCoreApplication::translate("board", "Form", nullptr));
        huiqi->setText(QCoreApplication::translate("board", "\346\202\224\346\243\213", nullptr));
        restart->setText(QCoreApplication::translate("board", "\351\207\215\346\226\260\345\274\200\345\247\213", nullptr));
        letAIdo->setText(QCoreApplication::translate("board", "AI\344\273\243\346\211\223", nullptr));
        save->setText(QCoreApplication::translate("board", "\344\277\235\345\255\230\345\257\271\345\261\200", nullptr));
        out->setText(QCoreApplication::translate("board", "\351\200\200\345\207\272\345\257\271\345\261\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class board: public Ui_board {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOARD_H
