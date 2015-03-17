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

/*
public signal:

	void pushButton_LoadImagesFromDirectory_clicked();
	void pushButton_DisplayFund7_clicked();
	void pushButton_DisplayFund8Epi_clicked();
	pushButton_DisplayFund8_clicked();
	pushButton_DisplayRepair_clicked();
	pushButton_DisplayHARRIS_clicked();
	pushButton_DisplayMSER_clicked();
	pushButton_DisplaySURF_clicked();
	pushButton_DisplaySIFT_clicked();
	lineEdit_ImageDirectory_returnPressed();
*/
private slots:
    void on_pushButton_LoadImagesFromDirectory_clicked();
    void on_lineEdit_ImageDirectory_returnPressed();

    void on_pushButton_DisplayFund7_clicked();
    void on_pushButton_DisplayFund8_clicked();

    void on_pushButton_DisplayRepair_clicked();
    void on_pushButton_DisplayRepair_2_clicked();
    void on_pushButton_DisplayRepair_3_clicked();

    void on_pushButton_DisplayHARRIS_clicked();
    void on_pushButton_DisplayHARRIS_2_clicked();
    void on_pushButton_DisplayHARRIS_3_clicked();

    void on_pushButton_DisplayMSER_clicked();
    void on_pushButton_DisplayMSER_2_clicked();
    void on_pushButton_DisplayMSER_3_clicked();

    void on_pushButton_DisplaySURF_clicked();
    void on_pushButton_DisplaySURF_2_clicked();
    void on_pushButton_DisplaySURF_3_clicked();

    void on_pushButton_DisplaySIFT_clicked();
    void on_pushButton_DisplaySIFT_2_clicked();
    void on_pushButton_DisplaySIFT_3_clicked();

private:
    void setPushButtonStatus(bool isEnabled);
    void loadImagesFromDirectory(QString qdir);
    // method can be: SIFT, SURF, MSER, HARRIS
    cv::Mat featureExtractionAndMatch(MethodType method, CVTool &cvtool, bool isMask = false);
    void addStatusText(std::string msg);

private:
    Ui::MainWindow *ui;
    cv::Mat m_dmg_a, m_cmp_a, m_b, m_rp_a;
    cv::Mat m_dmg_c, m_cmp_c, m_d, m_rp_c;
    cv::Mat m_dmg_e, m_cmp_e, m_f, m_rp_e;
    cv::Mat m_r_1, m_r_2, m_t_1, m_t_2, m_ft_1, m_ft_2;
};

#endif // MAINWINDOW_H
