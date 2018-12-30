/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myWidget
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *cb_remember;
    QCheckBox *cb_auto;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QRadioButton *rb_gb2312;
    QRadioButton *rb_gbk;
    QRadioButton *rb_gb18030;
    QLabel *lb_time;
    QLabel *lb_picture;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *myWidget)
    {
        if (myWidget->objectName().isEmpty())
            myWidget->setObjectName(QStringLiteral("myWidget"));
        myWidget->resize(996, 597);
        groupBox = new QGroupBox(myWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 20, 231, 101));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 30, 201, 56));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        cb_remember = new QCheckBox(widget);
        cb_remember->setObjectName(QStringLiteral("cb_remember"));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(12);
        cb_remember->setFont(font);

        verticalLayout_2->addWidget(cb_remember);

        cb_auto = new QCheckBox(widget);
        cb_auto->setObjectName(QStringLiteral("cb_auto"));
        cb_auto->setFont(font);

        verticalLayout_2->addWidget(cb_auto);

        cb_auto->raise();
        cb_remember->raise();
        cb_remember->raise();
        pushButton = new QPushButton(myWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 350, 121, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(16);
        pushButton->setFont(font1);
        groupBox_2 = new QGroupBox(myWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 160, 231, 131));
        widget1 = new QWidget(groupBox_2);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 35, 201, 91));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        rb_gb2312 = new QRadioButton(widget1);
        rb_gb2312->setObjectName(QStringLiteral("rb_gb2312"));
        rb_gb2312->setFont(font);

        verticalLayout->addWidget(rb_gb2312);

        rb_gbk = new QRadioButton(widget1);
        rb_gbk->setObjectName(QStringLiteral("rb_gbk"));
        rb_gbk->setFont(font);

        verticalLayout->addWidget(rb_gbk);

        rb_gb18030 = new QRadioButton(widget1);
        rb_gb18030->setObjectName(QStringLiteral("rb_gb18030"));
        rb_gb18030->setFont(font);

        verticalLayout->addWidget(rb_gb18030);

        lb_time = new QLabel(myWidget);
        lb_time->setObjectName(QStringLiteral("lb_time"));
        lb_time->setGeometry(QRect(300, 70, 681, 41));
        lb_time->setFont(font1);
        lb_picture = new QLabel(myWidget);
        lb_picture->setObjectName(QStringLiteral("lb_picture"));
        lb_picture->setGeometry(QRect(310, 150, 511, 351));
        lb_picture->setFont(font1);
        pushButton_2 = new QPushButton(myWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 530, 271, 41));
        pushButton_2->setFont(font1);
        pushButton_3 = new QPushButton(myWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(60, 430, 221, 51));
        pushButton_3->setFont(font1);

        retranslateUi(myWidget);

        QMetaObject::connectSlotsByName(myWidget);
    } // setupUi

    void retranslateUi(QWidget *myWidget)
    {
        myWidget->setWindowTitle(QApplication::translate("myWidget", "myWidget", 0));
        groupBox->setTitle(QApplication::translate("myWidget", "\347\231\273\351\231\206\351\200\211\351\241\271", 0));
        cb_remember->setText(QApplication::translate("myWidget", "\350\256\260\344\275\217\345\257\206\347\240\201", 0));
        cb_auto->setText(QApplication::translate("myWidget", "\350\207\252\345\212\250\347\231\273\351\231\206", 0));
        pushButton->setText(QApplication::translate("myWidget", "OK", 0));
        groupBox_2->setTitle(QApplication::translate("myWidget", "\346\261\211\345\255\227\347\274\226\347\240\201", 0));
        rb_gb2312->setText(QApplication::translate("myWidget", "GB2312", 0));
        rb_gbk->setText(QApplication::translate("myWidget", "GBK", 0));
        rb_gb18030->setText(QApplication::translate("myWidget", "GB18030", 0));
        lb_time->setText(QApplication::translate("myWidget", "TextLabel", 0));
        lb_picture->setText(QApplication::translate("myWidget", "TextLabel", 0));
        pushButton_2->setText(QApplication::translate("myWidget", "\350\216\267\345\217\226\347\263\273\347\273\237\346\227\266\351\227\264", 0));
        pushButton_3->setText(QApplication::translate("myWidget", "\346\230\276\347\244\272\345\233\276\347\211\207", 0));
    } // retranslateUi

};

namespace Ui {
    class myWidget: public Ui_myWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
