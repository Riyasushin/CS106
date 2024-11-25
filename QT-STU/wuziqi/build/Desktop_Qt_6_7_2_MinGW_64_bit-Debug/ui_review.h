/********************************************************************************
** Form generated from reading UI file 'review.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVIEW_H
#define UI_REVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Review
{
public:

    void setupUi(QWidget *Review)
    {
        if (Review->objectName().isEmpty())
            Review->setObjectName("Review");
        Review->resize(937, 548);

        retranslateUi(Review);

        QMetaObject::connectSlotsByName(Review);
    } // setupUi

    void retranslateUi(QWidget *Review)
    {
        Review->setWindowTitle(QCoreApplication::translate("Review", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Review: public Ui_Review {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVIEW_H
