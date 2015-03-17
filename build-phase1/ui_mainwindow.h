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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_ImageDirectory;
    QPushButton *pushButton_LoadImagesFromDirectory;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_DisplaySIFT;
    QPushButton *pushButton_DisplaySIFT_2;
    QPushButton *pushButton_DisplaySIFT_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_DisplaySURF;
    QPushButton *pushButton_DisplaySURF_2;
    QPushButton *pushButton_DisplaySURF_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_DisplayMSER;
    QPushButton *pushButton_DisplayMSER_2;
    QPushButton *pushButton_DisplayMSER_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_DisplayHARRIS;
    QPushButton *pushButton_DisplayHARRIS_2;
    QPushButton *pushButton_DisplayHARRIS_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_DisplayRepair;
    QPushButton *pushButton_DisplayRepair_2;
    QPushButton *pushButton_DisplayRepair_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_DisplayFund7;
    QPushButton *pushButton_DisplayFund8;
    QLabel *label_5;
    QTextEdit *textEdit_DisplayStatus;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(646, 554);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 628, 511));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_ImageDirectory = new QLineEdit(widget);
        lineEdit_ImageDirectory->setObjectName(QStringLiteral("lineEdit_ImageDirectory"));

        horizontalLayout->addWidget(lineEdit_ImageDirectory);

        pushButton_LoadImagesFromDirectory = new QPushButton(widget);
        pushButton_LoadImagesFromDirectory->setObjectName(QStringLiteral("pushButton_LoadImagesFromDirectory"));
        pushButton_LoadImagesFromDirectory->setAcceptDrops(false);

        horizontalLayout->addWidget(pushButton_LoadImagesFromDirectory);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_DisplaySIFT = new QPushButton(widget);
        pushButton_DisplaySIFT->setObjectName(QStringLiteral("pushButton_DisplaySIFT"));

        horizontalLayout_2->addWidget(pushButton_DisplaySIFT);

        pushButton_DisplaySIFT_2 = new QPushButton(widget);
        pushButton_DisplaySIFT_2->setObjectName(QStringLiteral("pushButton_DisplaySIFT_2"));

        horizontalLayout_2->addWidget(pushButton_DisplaySIFT_2);

        pushButton_DisplaySIFT_3 = new QPushButton(widget);
        pushButton_DisplaySIFT_3->setObjectName(QStringLiteral("pushButton_DisplaySIFT_3"));

        horizontalLayout_2->addWidget(pushButton_DisplaySIFT_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_DisplaySURF = new QPushButton(widget);
        pushButton_DisplaySURF->setObjectName(QStringLiteral("pushButton_DisplaySURF"));

        horizontalLayout_3->addWidget(pushButton_DisplaySURF);

        pushButton_DisplaySURF_2 = new QPushButton(widget);
        pushButton_DisplaySURF_2->setObjectName(QStringLiteral("pushButton_DisplaySURF_2"));

        horizontalLayout_3->addWidget(pushButton_DisplaySURF_2);

        pushButton_DisplaySURF_3 = new QPushButton(widget);
        pushButton_DisplaySURF_3->setObjectName(QStringLiteral("pushButton_DisplaySURF_3"));

        horizontalLayout_3->addWidget(pushButton_DisplaySURF_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_DisplayMSER = new QPushButton(widget);
        pushButton_DisplayMSER->setObjectName(QStringLiteral("pushButton_DisplayMSER"));

        horizontalLayout_4->addWidget(pushButton_DisplayMSER);

        pushButton_DisplayMSER_2 = new QPushButton(widget);
        pushButton_DisplayMSER_2->setObjectName(QStringLiteral("pushButton_DisplayMSER_2"));

        horizontalLayout_4->addWidget(pushButton_DisplayMSER_2);

        pushButton_DisplayMSER_3 = new QPushButton(widget);
        pushButton_DisplayMSER_3->setObjectName(QStringLiteral("pushButton_DisplayMSER_3"));

        horizontalLayout_4->addWidget(pushButton_DisplayMSER_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_DisplayHARRIS = new QPushButton(widget);
        pushButton_DisplayHARRIS->setObjectName(QStringLiteral("pushButton_DisplayHARRIS"));

        horizontalLayout_5->addWidget(pushButton_DisplayHARRIS);

        pushButton_DisplayHARRIS_2 = new QPushButton(widget);
        pushButton_DisplayHARRIS_2->setObjectName(QStringLiteral("pushButton_DisplayHARRIS_2"));

        horizontalLayout_5->addWidget(pushButton_DisplayHARRIS_2);

        pushButton_DisplayHARRIS_3 = new QPushButton(widget);
        pushButton_DisplayHARRIS_3->setObjectName(QStringLiteral("pushButton_DisplayHARRIS_3"));

        horizontalLayout_5->addWidget(pushButton_DisplayHARRIS_3);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_DisplayRepair = new QPushButton(widget);
        pushButton_DisplayRepair->setObjectName(QStringLiteral("pushButton_DisplayRepair"));

        horizontalLayout_6->addWidget(pushButton_DisplayRepair);

        pushButton_DisplayRepair_2 = new QPushButton(widget);
        pushButton_DisplayRepair_2->setObjectName(QStringLiteral("pushButton_DisplayRepair_2"));

        horizontalLayout_6->addWidget(pushButton_DisplayRepair_2);

        pushButton_DisplayRepair_3 = new QPushButton(widget);
        pushButton_DisplayRepair_3->setObjectName(QStringLiteral("pushButton_DisplayRepair_3"));

        horizontalLayout_6->addWidget(pushButton_DisplayRepair_3);


        verticalLayout->addLayout(horizontalLayout_6);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_DisplayFund7 = new QPushButton(widget);
        pushButton_DisplayFund7->setObjectName(QStringLiteral("pushButton_DisplayFund7"));

        horizontalLayout_7->addWidget(pushButton_DisplayFund7);

        pushButton_DisplayFund8 = new QPushButton(widget);
        pushButton_DisplayFund8->setObjectName(QStringLiteral("pushButton_DisplayFund8"));

        horizontalLayout_7->addWidget(pushButton_DisplayFund8);


        verticalLayout->addLayout(horizontalLayout_7);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        textEdit_DisplayStatus = new QTextEdit(widget);
        textEdit_DisplayStatus->setObjectName(QStringLiteral("textEdit_DisplayStatus"));
        textEdit_DisplayStatus->setAcceptDrops(false);
        textEdit_DisplayStatus->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_DisplayStatus->setReadOnly(true);

        verticalLayout->addWidget(textEdit_DisplayStatus);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "COMP5421 P1", 0));
        lineEdit_ImageDirectory->setPlaceholderText(QApplication::translate("MainWindow", "Enter directory to images...", 0));
        pushButton_LoadImagesFromDirectory->setText(QApplication::translate("MainWindow", "Load Images", 0));
        label->setText(QApplication::translate("MainWindow", "Dataset: A & B", 0));
        label_2->setText(QApplication::translate("MainWindow", "Dataset: C & D", 0));
        label_3->setText(QApplication::translate("MainWindow", "Dataset: E & F", 0));
        pushButton_DisplaySIFT->setText(QApplication::translate("MainWindow", "Display SIFT Results", 0));
        pushButton_DisplaySIFT_2->setText(QApplication::translate("MainWindow", "Display SIFT Results", 0));
        pushButton_DisplaySIFT_3->setText(QApplication::translate("MainWindow", "Display SIFT Results", 0));
        pushButton_DisplaySURF->setText(QApplication::translate("MainWindow", "Display SURF Results", 0));
        pushButton_DisplaySURF_2->setText(QApplication::translate("MainWindow", "Display SURF Results", 0));
        pushButton_DisplaySURF_3->setText(QApplication::translate("MainWindow", "Display SURF Results", 0));
        pushButton_DisplayMSER->setText(QApplication::translate("MainWindow", "Display MSER Results", 0));
        pushButton_DisplayMSER_2->setText(QApplication::translate("MainWindow", "Display MSER Results", 0));
        pushButton_DisplayMSER_3->setText(QApplication::translate("MainWindow", "Display MSER Results", 0));
        pushButton_DisplayHARRIS->setText(QApplication::translate("MainWindow", "Display HARRIS Results", 0));
        pushButton_DisplayHARRIS_2->setText(QApplication::translate("MainWindow", "Display HARRIS Results", 0));
        pushButton_DisplayHARRIS_3->setText(QApplication::translate("MainWindow", "Display HARRIS Results", 0));
        pushButton_DisplayRepair->setText(QApplication::translate("MainWindow", "Repair Damaged Image", 0));
        pushButton_DisplayRepair_2->setText(QApplication::translate("MainWindow", "Repair Damaged Image", 0));
        pushButton_DisplayRepair_3->setText(QApplication::translate("MainWindow", "Repair Damaged Image", 0));
        label_4->setText(QApplication::translate("MainWindow", "Using rotation and translation datasets", 0));
        pushButton_DisplayFund7->setText(QApplication::translate("MainWindow", "Fundamental matrix with 7 pts", 0));
        pushButton_DisplayFund8->setText(QApplication::translate("MainWindow", "Fundamental matrix with >8 pts", 0));
        label_5->setText(QApplication::translate("MainWindow", "Status:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
