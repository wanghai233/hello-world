/********************************************************************************
** Form generated from reading UI file 'mycontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCONTROL_H
#define UI_MYCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mycontrol
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Mycontrol)
    {
        if (Mycontrol->objectName().isEmpty())
            Mycontrol->setObjectName(QStringLiteral("Mycontrol"));
        Mycontrol->resize(604, 459);
        centralWidget = new QWidget(Mycontrol);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 50, 111, 16));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(10);
        label->setFont(font);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(20, 40, 221, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 80, 121, 71));
        QFont font1;
        font1.setFamily(QStringLiteral("Agency FB"));
        font1.setPointSize(18);
        label_2->setFont(font1);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 270, 338, 91));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(16);
        pushButton->setFont(font2);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QFont font3;
        font3.setFamily(QStringLiteral("Agency FB"));
        font3.setPointSize(14);
        pushButton_2->setFont(font3);

        horizontalLayout->addWidget(pushButton_2);

        Mycontrol->setCentralWidget(centralWidget);
        label->raise();
        lineEdit->raise();
        label_2->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_2->raise();
        menuBar = new QMenuBar(Mycontrol);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 604, 21));
        Mycontrol->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Mycontrol);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Mycontrol->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Mycontrol);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Mycontrol->setStatusBar(statusBar);

        retranslateUi(Mycontrol);

        QMetaObject::connectSlotsByName(Mycontrol);
    } // setupUi

    void retranslateUi(QMainWindow *Mycontrol)
    {
        Mycontrol->setWindowTitle(QApplication::translate("Mycontrol", "Mycontrol", 0));
        label->setText(QApplication::translate("Mycontrol", "TextLabel", 0));
        label_2->setText(QApplication::translate("Mycontrol", "\350\275\254\346\215\242\347\273\223\346\236\234", 0));
        pushButton->setText(QApplication::translate("Mycontrol", "\346\217\220\345\217\226\345\201\266\346\225\260\346\225\260\345\255\227", 0));
        pushButton_2->setText(QApplication::translate("Mycontrol", "\346\217\220\345\217\226\345\245\207\346\225\260\346\225\260\345\255\227", 0));
    } // retranslateUi

};

namespace Ui {
    class Mycontrol: public Ui_Mycontrol {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCONTROL_H
