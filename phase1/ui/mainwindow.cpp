#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setPushButtonStatus(false);
    addStatusText("Waiting for a directory...\n");
}

MainWindow::~MainWindow()
{
	destroyAllWindows();
	delete ui;
}

void MainWindow::setPushButtonStatus(bool isEnabled)
{
	ui->pushButton_DisplayFund7->setEnabled(isEnabled);
	ui->pushButton_DisplayFund8->setEnabled(isEnabled);
	ui->pushButton_DisplayHARRIS->setEnabled(isEnabled);
	ui->pushButton_DisplayHARRIS_2->setEnabled(isEnabled);
	ui->pushButton_DisplayHARRIS_3->setEnabled(isEnabled);
	ui->pushButton_DisplayMSER->setEnabled(isEnabled);
	ui->pushButton_DisplayMSER_2->setEnabled(isEnabled);
	ui->pushButton_DisplayMSER_3->setEnabled(isEnabled);
	ui->pushButton_DisplayRepair->setEnabled(isEnabled);
	ui->pushButton_DisplayRepair_2->setEnabled(isEnabled);
	ui->pushButton_DisplayRepair_3->setEnabled(isEnabled);
	ui->pushButton_DisplaySIFT->setEnabled(isEnabled);
	ui->pushButton_DisplaySIFT_2->setEnabled(isEnabled);
	ui->pushButton_DisplaySIFT_3->setEnabled(isEnabled);
	ui->pushButton_DisplaySURF->setEnabled(isEnabled);
	ui->pushButton_DisplaySURF_2->setEnabled(isEnabled);
	ui->pushButton_DisplaySURF_3->setEnabled(isEnabled);
}

void MainWindow::addStatusText(string msg)
{
	QString text (msg.c_str());
	ui->textEdit_DisplayStatus->insertPlainText(text);
}

void MainWindow::loadImagesFromDirectory(QString qdir)
{
	if (!qdir.endsWith(QChar('/')))
			qdir.append(QChar('/'));
	//std::string string = qdir.toUtf8().constData();
	QString qdir_a_complete = QString(qdir).append("a_complete.png");
	QString qdir_a_damage = QString(qdir).append("a_damage.png");
	QString qdir_b = QString(qdir).append("b.png");
	QString qdir_c_complete = QString(qdir).append("c_complete.png");
	QString qdir_c_damage = QString(qdir).append("c_damage.png");
	QString qdir_d = QString(qdir).append("d.png");
	QString qdir_e_complete = QString(qdir).append("e_complete.png");
	QString qdir_e_damage = QString(qdir).append("e_damage.png");
	QString qdir_f = QString(qdir).append("f.png");
	QString qdir_forward_translation1 = QString(qdir).append("forward_translation1.png");
	QString qdir_forward_translation2 = QString(qdir).append("forward_translation2.png");
	QString qdir_rotation1 = QString(qdir).append("rotation1.png");
	QString qdir_rotation2 = QString(qdir).append("rotation2.png");
	QString qdir_translation1 = QString(qdir).append("translation1.png");
	QString qdir_translation2 = QString(qdir).append("translation2.png");
	m_cmp_a = imread(qdir_a_complete.toUtf8().constData());
	m_dmg_a = imread(qdir_a_damage.toUtf8().constData());
	m_b = imread(qdir_b.toUtf8().constData());

	m_cmp_c = imread(qdir_c_complete.toUtf8().constData());
	m_dmg_c = imread(qdir_c_damage.toUtf8().constData());
	m_d = imread(qdir_d.toUtf8().constData());

	m_cmp_e = imread(qdir_e_complete.toUtf8().constData());
	m_dmg_e = imread(qdir_e_damage.toUtf8().constData());
	m_f = imread(qdir_f.toUtf8().constData());

  m_ft_1 = imread(qdir_forward_translation1.toUtf8().constData());
  m_ft_2 = imread(qdir_forward_translation2.toUtf8().constData());
	m_r_1 = imread(qdir_rotation1.toUtf8().constData());
	m_r_2 = imread(qdir_rotation2.toUtf8().constData());
	m_t_1 = imread(qdir_translation1.toUtf8().constData());
	m_t_2 = imread(qdir_translation2.toUtf8().constData());
	addStatusText("Directory scanned. Images loaded.\n");
	setPushButtonStatus(true);
	ui->pushButton_LoadImagesFromDirectory->setEnabled(false);
	ui->lineEdit_ImageDirectory->setReadOnly(true);
}

Mat MainWindow::featureExtractionAndMatch(MethodType method, CVTool &cvtool, bool isMask) {
	switch (method) {
	case METHOD_SIFT:
		cvtool.detectFeatureSIFT(isMask);
		break;
	case METHOD_SURF:
		cvtool.detectFeatureSURF(isMask);
		break;
	case METHOD_MSER:
		cvtool.detectFeatureMSER(isMask);
		break;
	case METHOD_HARRIS:
		cvtool.detectFeatureHaris(isMask);
		break;
	}
	cvtool.matchFeatures();
	return cvtool.visualizeMatching();
}

void MainWindow::on_pushButton_LoadImagesFromDirectory_clicked()
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
	CVTool cvtool_ab(m_cmp_a, m_b);
	Mat result = featureExtractionAndMatch(METHOD_HARRIS, cvtool_ab);
	imshow("Harris on A & B", result);
}
void MainWindow::on_pushButton_DisplayHARRIS_2_clicked()
{
	// display results of harris corner detection
	CVTool cvtool_cd(m_cmp_c, m_d);
	Mat result = featureExtractionAndMatch(METHOD_HARRIS, cvtool_cd);
	imshow("Harris on C & D", result);
}
void MainWindow::on_pushButton_DisplayHARRIS_3_clicked()
{
	// display results of harris corner detection
	CVTool cvtool_ef(m_cmp_e, m_f);
	Mat result = featureExtractionAndMatch(METHOD_HARRIS, cvtool_ef);
	imshow("Harris on E & F", result);
}

void MainWindow::on_pushButton_DisplayMSER_clicked()
{
  // display results of MSER feature detection
	CVTool cvtool_ab(m_cmp_a, m_b);
	Mat result = featureExtractionAndMatch(METHOD_MSER, cvtool_ab);
	imshow("MSER on A & B", result);
}
void MainWindow::on_pushButton_DisplayMSER_2_clicked()
{
  // display results of MSER feature detection
	CVTool cvtool_cd(m_cmp_c, m_d);
	Mat result = featureExtractionAndMatch(METHOD_MSER, cvtool_cd);
	imshow("MSER on C & D", result);
}
void MainWindow::on_pushButton_DisplayMSER_3_clicked()
{
  // display results of MSER feature detection
	CVTool cvtool_ef(m_cmp_e, m_f);
	Mat result = featureExtractionAndMatch(METHOD_MSER, cvtool_ef);
	imshow("MSER on E & F", result);
}

void MainWindow::on_pushButton_DisplaySURF_clicked()
{
  // display SURF
	CVTool cvtool_ab(m_cmp_a, m_b);
	Mat result = featureExtractionAndMatch(METHOD_SURF, cvtool_ab);
	imshow("SURF on A & B", result);
}
void MainWindow::on_pushButton_DisplaySURF_2_clicked()
{
  // display SURF
	CVTool cvtool_cd(m_cmp_c, m_d);
	Mat result = featureExtractionAndMatch(METHOD_SURF, cvtool_cd);
	imshow("SURF on C & D", result);
}
void MainWindow::on_pushButton_DisplaySURF_3_clicked()
{
	// display SURF
	CVTool cvtool_ef(m_cmp_e, m_f);
	Mat result = featureExtractionAndMatch(METHOD_SURF, cvtool_ef);
	imshow("SURF on E & F", result);
}

void MainWindow::on_pushButton_DisplaySIFT_clicked()
{
  // display SIFT
	CVTool cvtool_ab(m_cmp_a, m_b);
	Mat result = featureExtractionAndMatch(METHOD_SIFT, cvtool_ab);
	imshow("SIFT on A & B", result);
}
void MainWindow::on_pushButton_DisplaySIFT_2_clicked()
{
  // display SIFT
	CVTool cvtool_cd(m_cmp_c, m_d);
	Mat result = featureExtractionAndMatch(METHOD_SIFT, cvtool_cd);
	imshow("SIFT on C & D", result);
}
void MainWindow::on_pushButton_DisplaySIFT_3_clicked()
{
  // display SIFT
	CVTool cvtool_ef(m_cmp_e, m_f);
	Mat result = featureExtractionAndMatch(METHOD_SIFT, cvtool_ef);
	imshow("SIFT on E & F", result);
}

void MainWindow::on_pushButton_DisplayFund7_clicked()
{
	// display UI to allow user to select 7 points
	// and display epipolar lines
	addStatusText("Epipolar lines with 7 user-selected points under developement...\n");
}

void MainWindow::on_pushButton_DisplayFund8_clicked()
{

	CVTool cvtool_forward_translation;
	CVTool cvtool_rotation;
	CVTool cvtool_translation;
	cvtool_forward_translation = CVTool(m_ft_1, m_ft_2);
	cvtool_rotation = CVTool(m_r_1, m_r_2);
	cvtool_translation = CVTool(m_t_1, m_t_2);

	addStatusText("Calculating epipolar lines for forward translation images...");
	featureExtractionAndMatch(METHOD_SURF, cvtool_forward_translation, true);
	Mat fund_ft = cvtool_forward_translation.computeFundMatrix(false);
	Mat epi_ft = cvtool_forward_translation.visualizeEpipolarLine(fund_ft);
	imshow("Epipolar Lines (x15) for forward translation images", epi_ft);
	addStatusText("Done\n");

	addStatusText("Calculating epipolar lines for rotation images...");
	featureExtractionAndMatch(METHOD_SURF, cvtool_rotation, true);
	Mat fund_r = cvtool_rotation.computeFundMatrix(false);
	Mat epi_r = cvtool_rotation.visualizeEpipolarLine(fund_r);
	imshow("Epipolar Lines (x15) for rotation images", epi_r);
	addStatusText("Done\n");

	addStatusText("Calculating epipolar lines for translation images...");
	featureExtractionAndMatch(METHOD_SURF, cvtool_translation, true);
	Mat fund_t = cvtool_translation.computeFundMatrix(false);
	Mat epi_t = cvtool_translation.visualizeEpipolarLine(fund_t);
	imshow("Epipolar Lines (x15) for translation images", epi_t);
	addStatusText("Done\n");
}

void MainWindow::on_pushButton_DisplayRepair_clicked()
{
	addStatusText("Repairing image set a & b..");
	CVTool cvtool_repair;
	m_rp_a = cvtool_repair.repairImage(m_dmg_a, m_b);
	addStatusText("Done\n");
	cvtool_repair.visualizeDiffence(m_rp_a, m_cmp_a);
}
void MainWindow::on_pushButton_DisplayRepair_2_clicked()
{
	addStatusText("Repairing image set c & d..");
	CVTool cvtool_repair;
	m_rp_c = cvtool_repair.repairImage(m_dmg_c, m_d);
	addStatusText("Done\n");
	cvtool_repair.visualizeDiffence(m_rp_c, m_cmp_c);
}
void MainWindow::on_pushButton_DisplayRepair_3_clicked()
{
	addStatusText("Repairing image set e & f..");
	CVTool cvtool_repair;
	m_rp_e = cvtool_repair.repairImage(m_dmg_e, m_f);
	addStatusText("Done\n");
	cvtool_repair.visualizeDiffence(m_rp_e, m_cmp_e);
}
