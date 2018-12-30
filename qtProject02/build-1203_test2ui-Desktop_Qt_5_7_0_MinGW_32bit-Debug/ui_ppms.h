/********************************************************************************
** Form generated from reading UI file 'ppms.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PPMS_H
#define UI_PPMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ppms
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *labellabel;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ppms)
    {
        if (ppms->objectName().isEmpty())
            ppms->setObjectName(QStringLiteral("ppms"));
        ppms->resize(736, 362);
        label = new QLabel(ppms);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 70, 701, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        label->setFont(font);
        lineEdit = new QLineEdit(ppms);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(120, 160, 231, 21));
        pushButton = new QPushButton(ppms);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 250, 121, 51));
        pushButton_2 = new QPushButton(ppms);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 250, 111, 51));
        labellabel = new QLabel(ppms);
        labellabel->setObjectName(QStringLiteral("labellabel"));
        labellabel->setGeometry(QRect(120, 212, 341, 20));
        pushButton_3 = new QPushButton(ppms);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 250, 111, 51));

        retranslateUi(ppms);

        QMetaObject::connectSlotsByName(ppms);
    } // setupUi

    void retranslateUi(QWidget *ppms)
    {
        ppms->setWindowTitle(QApplication::translate("ppms", "Form", 0));
        label->setText(QApplication::translate("ppms", "PPMS \347\224\265\345\212\233\345\244\232\345\205\203\345\214\226\346\224\266\350\264\271\347\263\273\347\273\237", 0));
        pushButton->setText(QApplication::translate("ppms", "\346\217\220\345\217\226\345\245\207\346\225\260", 0));
        pushButton_2->setText(QApplication::translate("ppms", "\346\217\220\345\217\226\345\201\266\346\225\260", 0));
        labellabel->setText(QApplication::translate("ppms", "TextLabel", 0));
        pushButton_3->setText(QApplication::translate("ppms", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class ppms: public Ui_ppms {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PPMS_H
