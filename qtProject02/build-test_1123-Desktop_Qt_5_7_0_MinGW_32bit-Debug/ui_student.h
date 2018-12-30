/********************************************************************************
** Form generated from reading UI file 'student.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_H
#define UI_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_student
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *student)
    {
        if (student->objectName().isEmpty())
            student->setObjectName(QStringLiteral("student"));
        student->resize(524, 357);
        centralWidget = new QWidget(student);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 50, 311, 91));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(28);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 160, 141, 91));
        pushButton->setFont(font);
        student->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(student);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 524, 21));
        student->setMenuBar(menuBar);
        mainToolBar = new QToolBar(student);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        student->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(student);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        student->setStatusBar(statusBar);

        retranslateUi(student);

        QMetaObject::connectSlotsByName(student);
    } // setupUi

    void retranslateUi(QMainWindow *student)
    {
        student->setWindowTitle(QApplication::translate("student", "student", 0));
        label->setText(QApplication::translate("student", "hello word", 0));
        pushButton->setText(QApplication::translate("student", "ok", 0));
    } // retranslateUi

};

namespace Ui {
    class student: public Ui_student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_H
