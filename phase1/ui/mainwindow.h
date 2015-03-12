#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cvtool.h"

typedef enum {
	METHOD_SIFT = 0,
	METHOD_SURF,
	METHOD_MSER,
	METHOD_HARRIS
} MethodType;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_loadImagesFromDirectory_clicked();

    void on_pushButton_DisplayFund7_clicked();

    void on_pushButton_DisplayFund8Epi_clicked();

    void on_pushButton_DisplayFund8_clicked();

    void on_pushButton_DisplayRepair_clicked();

    void on_pushButton_DisplayHARRIS_clicked();

    void on_pushButton_DisplayMSER_clicked();

    void on_pushButton_DisplaySURF_clicked();

    void on_pushButton_DisplaySIFT_clicked();

    void on_lineEdit_ImageDirectory_returnPressed();

private:
    void setPushButtonStatus(bool isEnabled);
    void loadImagesFromDirectory(QString qdir);
    // method can be: SIFT, SURF, MSER, HARRIS
    cv::Mat featureExtractionAndMatch(MethodType method);

private:
    Ui::MainWindow *ui;
    CVTool cvtool_ab;
    CVTool cvtool_forward_translation;
    CVTool cvtool_rotation;
    CVTool cvtool_translation;
};

#endif // MAINWINDOW_H
