/********************************************************************************
** Form generated from reading UI file 'mytime.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYTIME_H
#define UI_MYTIME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_myTime
{
public:
    QLabel *labTimer;

    void setupUi(QDialog *myTime)
    {
        if (myTime->objectName().isEmpty())
            myTime->setObjectName(QStringLiteral("myTime"));
        myTime->resize(669, 380);
        labTimer = new QLabel(myTime);
        labTimer->setObjectName(QStringLiteral("labTimer"));
        labTimer->setGeometry(QRect(60, 110, 581, 171));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(16);
        labTimer->setFont(font);

        retranslateUi(myTime);

        QMetaObject::connectSlotsByName(myTime);
    } // setupUi

    void retranslateUi(QDialog *myTime)
    {
        myTime->setWindowTitle(QApplication::translate("myTime", "myTime", 0));
        labTimer->setText(QApplication::translate("myTime", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class myTime: public Ui_myTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYTIME_H
