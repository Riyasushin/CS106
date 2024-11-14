/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pve_3;
    QPushButton *pve;
    QPushButton *pvp;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(200, 100, 121, 151));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pve_3 = new QPushButton(layoutWidget);
        pve_3->setObjectName("pve_3");
        QFont font;
        font.setPointSize(15);
        pve_3->setFont(font);

        verticalLayout->addWidget(pve_3);

        pve = new QPushButton(layoutWidget);
        pve->setObjectName("pve");
        pve->setFont(font);

        verticalLayout->addWidget(pve);

        pvp = new QPushButton(layoutWidget);
        pvp->setObjectName("pvp");
        pvp->setFont(font);

        verticalLayout->addWidget(pvp);

        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 40, 231, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267")});
        font1.setPointSize(30);
        font1.setBold(false);
        label->setFont(font1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pve_3->setText(QCoreApplication::translate("Widget", "\345\212\240\350\275\275\345\257\271\345\261\200", nullptr));
        pve->setText(QCoreApplication::translate("Widget", "\344\272\272\346\234\272\345\257\271\346\210\230", nullptr));
        pvp->setText(QCoreApplication::translate("Widget", "\345\245\275\345\217\213\345\206\263\346\226\227", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\272\224\345\255\220\346\243\213V0.1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
