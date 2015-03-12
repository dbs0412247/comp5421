#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setPushButtonStatus(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setPushButtonStatus(bool isEnabled) {
	ui->pushButton_DisplayFund7->setEnabled(isEnabled);
	ui->pushButton_DisplayFund8->setEnabled(isEnabled);
	ui->pushButton_DisplayFund8Epi->setEnabled(isEnabled);
	ui->pushButton_DisplayHARRIS->setEnabled(isEnabled);
	ui->pushButton_DisplayMSER->setEnabled(isEnabled);
	ui->pushButton_DisplayRepair->setEnabled(isEnabled);
	ui->pushButton_DisplaySIFT->setEnabled(isEnabled);
	ui->pushButton_DisplaySURF->setEnabled(isEnabled);
}

void MainWindow::loadImagesFromDirectory(QString qdir) {

	if (!qdir.endsWith(QChar('/')))
		qdir.append(QChar('/'));

	//std::string string = qdir.toUtf8().constData();
	QString qdir_a_complete = QString(qdir).append("a_complete.png");
	QString qdir_a_damage = QString(qdir).append("a_damage.png");
	QString qdir_b = QString(qdir).append("b.png");
	QString qdir_forward_translation1 = QString(qdir).append("forward_translation1.png");
	QString qdir_forward_translation2 = QString(qdir).append("forward_translation2.png");
	QString qdir_rotation1 = QString(qdir).append("rotation1.png");
	QString qdir_rotation2 = QString(qdir).append("rotation2.png");
	QString qdir_translation1 = QString(qdir).append("translation1.png");
	QString qdir_translation2 = QString(qdir).append("translation2.png");

	cvtool_ab = CVTool(qdir_a_complete.toUtf8().constData(),qdir_b.toUtf8().constData());
	cvtool_forward_translation = CVTool(qdir_forward_translation1.toUtf8().constData(), qdir_forward_translation2.toUtf8().constData());
	cvtool_rotation = CVTool(qdir_rotation1.toUtf8().constData(), qdir_rotation2.toUtf8().constData());
	cvtool_translation = CVTool(qdir_translation1.toUtf8().constData(), qdir_translation2.toUtf8().constData());

	// ui modifications
	setPushButtonStatus(true);
	ui->pushButton_loadImagesFromDirectory->setEnabled(false);
	ui->lineEdit_ImageDirectory->setReadOnly(true);
}

Mat MainWindow::featureExtractionAndMatch(MethodType method) {
	switch (method) {
	case METHOD_SIFT:
		cvtool_ab.detectFeatureSIFT();
		break;
	case METHOD_SURF:
		cvtool_ab.detectFeatureSURF();
		break;
	case METHOD_MSER:
		cvtool_ab.detectFeatureMSER();
		break;
	case METHOD_HARRIS:
		cvtool_ab.detectFeatureHaris();
		break;
	}
	cvtool_ab.matchFeatures();
	return cvtool_ab.visualizeMatching();
}

void MainWindow::on_pushButton_loadImagesFromDirectory_clicked()
{
  loadImagesFromDirectory(ui->lineEdit_ImageDirectory->text());
}

void MainWindow::on_lineEdit_ImageDirectory_returnPressed()
{
  loadImagesFromDirectory(ui->lineEdit_ImageDirectory->text());
}

void MainWindow::on_pushButton_DisplayHARRIS_clicked()
{
	// display results of harris corner detection
	Mat result = featureExtractionAndMatch(METHOD_HARRIS);
	imshow("Result", result);
	waitKey();
}

void MainWindow::on_pushButton_DisplayMSER_clicked()
{
  // display results of MSER feature detection
	Mat result = featureExtractionAndMatch(METHOD_MSER);
	imshow("Result", result);
	waitKey();
}

void MainWindow::on_pushButton_DisplaySURF_clicked()
{
  // display SURF
	Mat result = featureExtractionAndMatch(METHOD_SURF);
	imshow("Result", result);
	waitKey();
}

void MainWindow::on_pushButton_DisplaySIFT_clicked()
{
  // display SIFT
	Mat result = featureExtractionAndMatch(METHOD_SIFT);
	imshow("Result", result);
	waitKey();
}

void MainWindow::on_pushButton_DisplayFund7_clicked()
{
    // display UI to allow user to select 7 points
    // and display epipolar lines
}

void MainWindow::on_pushButton_DisplayFund8Epi_clicked()
{
  // display epipolar lines
  // with > 8 points
}

void MainWindow::on_pushButton_DisplayFund8_clicked()
{
    // calculate fundamental matrix with > 8 points
}

void MainWindow::on_pushButton_DisplayRepair_clicked()
{
    // repair damaged image
}
