/*
===============================
  COMP 5421 Project 1 
  By Adrian Yuen 
  hcayuen@connect.ust.hk
  Stu ID: 20029090
===============================
*/
#include "cvtool.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ui/mainwindow.h"
#include <QApplication>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[]) {
  // keyPoints
  vector<KeyPoint> keypoints_harris1, keypoints_harris2;

  // Run feature detectors
  //CVTool m_cvtool (a_complete, b);
  //m_cvtool.detectFeatureSIFT(keypoints_harris1, keypoints_harris2);
  //m_cvtool.detectFeatureSIFT(keypoints_harris1, keypoints_harris2);

  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec(); 
}
