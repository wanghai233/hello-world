/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditId;
    QLineEdit *lineEditPassword;
    QPushButton *pushButtonDefine;
    QPushButton *pushButtonCancel;
    QLabel *label_3;
    QComboBox *comboBox;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(494, 348);
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 120, 111, 41));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 170, 111, 31));
        label_2->setFont(font);
        lineEditId = new QLineEdit(login);
        lineEditId->setObjectName(QStringLiteral("lineEditId"));
        lineEditId->setGeometry(QRect(230, 130, 113, 20));
        lineEditPassword = new QLineEdit(login);
        lineEditPassword->setObjectName(QStringLiteral("lineEditPassword"));
        lineEditPassword->setGeometry(QRect(230, 180, 113, 20));
        lineEditPassword->setEchoMode(QLineEdit::Password);
        pushButtonDefine = new QPushButton(login);
        pushButtonDefine->setObjectName(QStringLiteral("pushButtonDefine"));
        pushButtonDefine->setGeometry(QRect(110, 240, 111, 51));
        pushButtonCancel = new QPushButton(login);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(270, 240, 111, 51));
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 50, 531, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(20);
        label_3->setFont(font1);
        comboBox = new QComboBox(login);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(330, 60, 51, 22));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "login", 0));
        label->setText(QApplication::translate("login", "ID\357\274\232", 0));
        label_2->setText(QApplication::translate("login", "Password\357\274\232", 0));
        pushButtonDefine->setText(QApplication::translate("login", "Define", 0));
        pushButtonCancel->setText(QApplication::translate("login", "Cancel", 0));
        label_3->setText(QApplication::translate("login", "\347\231\273\351\231\206\347\225\214\351\235\242", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("login", "123", 0)
         << QApplication::translate("login", "456", 0)
         << QApplication::translate("login", "789", 0)
         << QApplication::translate("login", "000", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
