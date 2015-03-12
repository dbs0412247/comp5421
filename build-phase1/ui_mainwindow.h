/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_ImageDirectory;
    QPushButton *pushButton_loadImagesFromDirectory;
    QPushButton *pushButton_DisplaySIFT;
    QPushButton *pushButton_DisplaySURF;
    QPushButton *pushButton_DisplayMSER;
    QPushButton *pushButton_DisplayHARRIS;
    QPushButton *pushButton_DisplayRepair;
    QPushButton *pushButton_DisplayFund8;
    QPushButton *pushButton_DisplayFund8Epi;
    QPushButton *pushButton_DisplayFund7;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(256, 381);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 236, 326));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_ImageDirectory = new QLineEdit(layoutWidget);
        lineEdit_ImageDirectory->setObjectName(QStringLiteral("lineEdit_ImageDirectory"));

        verticalLayout->addWidget(lineEdit_ImageDirectory);

        pushButton_loadImagesFromDirectory = new QPushButton(layoutWidget);
        pushButton_loadImagesFromDirectory->setObjectName(QStringLiteral("pushButton_loadImagesFromDirectory"));
        pushButton_loadImagesFromDirectory->setAcceptDrops(false);

        verticalLayout->addWidget(pushButton_loadImagesFromDirectory);

        pushButton_DisplaySIFT = new QPushButton(layoutWidget);
        pushButton_DisplaySIFT->setObjectName(QStringLiteral("pushButton_DisplaySIFT"));

        verticalLayout->addWidget(pushButton_DisplaySIFT);

        pushButton_DisplaySURF = new QPushButton(layoutWidget);
        pushButton_DisplaySURF->setObjectName(QStringLiteral("pushButton_DisplaySURF"));

        verticalLayout->addWidget(pushButton_DisplaySURF);

        pushButton_DisplayMSER = new QPushButton(layoutWidget);
        pushButton_DisplayMSER->setObjectName(QStringLiteral("pushButton_DisplayMSER"));

        verticalLayout->addWidget(pushButton_DisplayMSER);

        pushButton_DisplayHARRIS = new QPushButton(layoutWidget);
        pushButton_DisplayHARRIS->setObjectName(QStringLiteral("pushButton_DisplayHARRIS"));

        verticalLayout->addWidget(pushButton_DisplayHARRIS);

        pushButton_DisplayRepair = new QPushButton(layoutWidget);
        pushButton_DisplayRepair->setObjectName(QStringLiteral("pushButton_DisplayRepair"));

        verticalLayout->addWidget(pushButton_DisplayRepair);

        pushButton_DisplayFund8 = new QPushButton(layoutWidget);
        pushButton_DisplayFund8->setObjectName(QStringLiteral("pushButton_DisplayFund8"));

        verticalLayout->addWidget(pushButton_DisplayFund8);

        pushButton_DisplayFund8Epi = new QPushButton(layoutWidget);
        pushButton_DisplayFund8Epi->setObjectName(QStringLiteral("pushButton_DisplayFund8Epi"));

        verticalLayout->addWidget(pushButton_DisplayFund8Epi);

        pushButton_DisplayFund7 = new QPushButton(layoutWidget);
        pushButton_DisplayFund7->setObjectName(QStringLiteral("pushButton_DisplayFund7"));

        verticalLayout->addWidget(pushButton_DisplayFund7);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lineEdit_ImageDirectory->setPlaceholderText(QApplication::translate("MainWindow", "Enter directory to images...", 0));
        pushButton_loadImagesFromDirectory->setText(QApplication::translate("MainWindow", "Load Images", 0));
        pushButton_DisplaySIFT->setText(QApplication::translate("MainWindow", "Display SIFT Results", 0));
        pushButton_DisplaySURF->setText(QApplication::translate("MainWindow", "Display SURF Results", 0));
        pushButton_DisplayMSER->setText(QApplication::translate("MainWindow", "Display MSER Results", 0));
        pushButton_DisplayHARRIS->setText(QApplication::translate("MainWindow", "Display HARRIS Results", 0));
        pushButton_DisplayRepair->setText(QApplication::translate("MainWindow", "Repair Damaged Image", 0));
        pushButton_DisplayFund8->setText(QApplication::translate("MainWindow", "Fundamental matrix with >8 pts", 0));
        pushButton_DisplayFund8Epi->setText(QApplication::translate("MainWindow", "Draw Epipolar Lines", 0));
        pushButton_DisplayFund7->setText(QApplication::translate("MainWindow", "Fundamental matrix with 7 pts", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
