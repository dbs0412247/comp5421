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

#include <iostream>
using namespace std;
using namespace cv;

int main() {
  
  // read data
	Mat a_complete = imread("data/a_complete.png");
	Mat a_damage = imread("data/a_damage.png");
	Mat b = imread("data/b.png");
	Mat forward_translation1 = imread("data/forward_translation1.png");
	Mat forward_translation2 = imread("data/forward_translation2.png");
	Mat rotation1 = imread("data/rotation1.png");
	Mat rotation2 = imread("data/rotation2.png");
	Mat translation1 = imread("data/translation1.png");
	Mat translation2 = imread("data/translation2.png");

/* Debug: show images

	imshow("a_complete", a_complete);
	imshow("a_damage", a_damage);
	imshow("b", b);
	imshow("forward_translation1", forward_translation1);
	imshow("forward_translation2", forward_translation2);
	imshow("rotation1", rotation1);
	imshow("rotation2", rotation2);
	imshow("translation1", translation1);
	imshow("translation2", translation2);

	waitKey();
	destroyAllWindows();
*/
	// keyPoints
	vector<KeyPoint> keypoints_harris1, keypoints_harris2;

	// Run feature detectors
	CVTool m_cvtool (a_complete, b);
	m_cvtool.detectFeatureSIFT(keypoints_harris1, keypoints_harris2);
	m_cvtool.detectFeatureSIFT(keypoints_harris1, keypoints_harris2);

	return 0;
}
