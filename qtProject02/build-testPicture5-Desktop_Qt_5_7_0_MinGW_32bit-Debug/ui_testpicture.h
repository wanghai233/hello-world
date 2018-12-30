/********************************************************************************
** Form generated from reading UI file 'testpicture.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTPICTURE_H
#define UI_TESTPICTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testPicture
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *testPicture)
    {
        if (testPicture->objectName().isEmpty())
            testPicture->setObjectName(QStringLiteral("testPicture"));
        testPicture->resize(797, 878);
        centralWidget = new QWidget(testPicture);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 0, 731, 831));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/\347\250\213\345\272\217\345\221\230.jpg")));
        testPicture->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(testPicture);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 797, 21));
        testPicture->setMenuBar(menuBar);
        mainToolBar = new QToolBar(testPicture);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        testPicture->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(testPicture);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        testPicture->setStatusBar(statusBar);

        retranslateUi(testPicture);

        QMetaObject::connectSlotsByName(testPicture);
    } // setupUi

    void retranslateUi(QMainWindow *testPicture)
    {
        testPicture->setWindowTitle(QApplication::translate("testPicture", "testPicture", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class testPicture: public Ui_testPicture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTPICTURE_H
