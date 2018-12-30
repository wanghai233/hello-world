/********************************************************************************
** Form generated from reading UI file 'picture.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURE_H
#define UI_PICTURE_H

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

class Ui_picture
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *picture)
    {
        if (picture->objectName().isEmpty())
            picture->setObjectName(QStringLiteral("picture"));
        picture->resize(731, 486);
        centralWidget = new QWidget(picture);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 631, 371));
        label->setPixmap(QPixmap(QString::fromUtf8(":/picture2/\347\250\213\345\272\217\345\221\230\350\277\233\351\230\266.jpg")));
        picture->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(picture);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 21));
        picture->setMenuBar(menuBar);
        mainToolBar = new QToolBar(picture);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        picture->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(picture);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        picture->setStatusBar(statusBar);

        retranslateUi(picture);

        QMetaObject::connectSlotsByName(picture);
    } // setupUi

    void retranslateUi(QMainWindow *picture)
    {
        picture->setWindowTitle(QApplication::translate("picture", "picture", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class picture: public Ui_picture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURE_H
