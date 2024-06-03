/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *secondLine;
    QLabel *label;
    QLineEdit *firstLine;
    QPushButton *firstButton;
    QPushButton *secondButton;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listOfDuplicates;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        secondLine = new QLineEdit(centralwidget);
        secondLine->setObjectName("secondLine");

        gridLayout->addWidget(secondLine, 1, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 1, 1, 1);

        firstLine = new QLineEdit(centralwidget);
        firstLine->setObjectName("firstLine");

        gridLayout->addWidget(firstLine, 0, 2, 1, 1);

        firstButton = new QPushButton(centralwidget);
        firstButton->setObjectName("firstButton");

        gridLayout->addWidget(firstButton, 0, 3, 1, 1);

        secondButton = new QPushButton(centralwidget);
        secondButton->setObjectName("secondButton");

        gridLayout->addWidget(secondButton, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        listOfDuplicates = new QListWidget(centralwidget);
        listOfDuplicates->setObjectName("listOfDuplicates");

        verticalLayout_2->addWidget(listOfDuplicates);


        verticalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "2nd folder", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "1st folder", nullptr));
        firstButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        secondButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
