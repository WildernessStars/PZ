/********************************************************************************
** Form generated from reading UI file 'PVZ_Qt.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PVZ_QT_H
#define UI_PVZ_QT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PVZ_QtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PVZ_QtClass)
    {
        if (PVZ_QtClass->objectName().isEmpty())
            PVZ_QtClass->setObjectName(QStringLiteral("PVZ_QtClass"));
        PVZ_QtClass->resize(600, 400);
        menuBar = new QMenuBar(PVZ_QtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        PVZ_QtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PVZ_QtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PVZ_QtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(PVZ_QtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        PVZ_QtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(PVZ_QtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PVZ_QtClass->setStatusBar(statusBar);

        retranslateUi(PVZ_QtClass);

        QMetaObject::connectSlotsByName(PVZ_QtClass);
    } // setupUi

    void retranslateUi(QMainWindow *PVZ_QtClass)
    {
        PVZ_QtClass->setWindowTitle(QApplication::translate("PVZ_QtClass", "PVZ_Qt", 0));
    } // retranslateUi

};

namespace Ui {
    class PVZ_QtClass: public Ui_PVZ_QtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PVZ_QT_H
