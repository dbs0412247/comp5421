#include "cvtool.h"

// Debug
#include <iostream>

using namespace cv;
using namespace std;

CVTool::CVTool()
{
	image1_ = Mat();
	image2_ = Mat();
	keypoints1_ = vector<KeyPoint>();
	keypoints2_ = vector<KeyPoint>();
	descriptors1_ = Mat();
	descriptors2_ = Mat();
	matches_ = std::vector< std::vector<cv::DMatch> >();
}

CVTool::CVTool(std::string path_to_image1, std::string path_to_image2)
{
	initModule_nonfree();
	//cout << "Reading from: " << path_to_image1 << endl;
	//cout << "Reading from: " << path_to_image2 << endl;
	image1_ = imread(path_to_image1);
	image2_ = imread(path_to_image2);
	keypoints1_ = vector<KeyPoint>();
	keypoints2_ = vector<KeyPoint>();
	descriptors1_ = Mat();
	descriptors2_ = Mat();
	matches_ = std::vector< std::vector<cv::DMatch> >();
	CV_Assert(!image1_.empty() && !image2_.empty());
}

CVTool::CVTool(const cv::Mat & image1, const cv::Mat & image2)
{
	initModule_nonfree();
	image1_ = Mat(image1);
	image2_ = Mat(image2);
	keypoints1_ = vector<KeyPoint>();
	keypoints2_ = vector<KeyPoint>();
	descriptors1_ = Mat();
	descriptors2_ = Mat();
	matches_ = std::vector< std::vector<cv::DMatch> >();
	CV_Assert(!image1_.empty() && !image2_.empty());
}

void CVTool::detectFeatureSIFT()
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	Ptr<FeatureDetector> sift = FeatureDetector::create("SIFT");
	sift->detect(image1_, keypoints1_, Mat());
	sift->detect(image2_, keypoints2_, Mat());
}

void CVTool::detectFeatureSURF()
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	Ptr<FeatureDetector> surf = FeatureDetector::create("SURF");
	surf->detect(image1_, keypoints1_, Mat());
	surf->detect(image2_, keypoints2_, Mat());
}

void CVTool::detectFeatureMSER()
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	Ptr<FeatureDetector> mser = FeatureDetector::create("MSER");
	mser->detect(image1_, keypoints1_, Mat());
	mser->detect(image2_, keypoints2_, Mat());
}

void CVTool::detectFeatureHaris()
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	Ptr<FeatureDetector> harris = FeatureDetector::create("HARRIS");
	harris->detect(image1_, keypoints1_, Mat());
	harris->detect(image2_, keypoints2_, Mat());
}

void CVTool::matchFeatures()
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	CV_Assert(!keypoints1_.empty() && !keypoints2_.empty());
	Ptr<DescriptorExtractor> sift_extractor = DescriptorExtractor::create("SIFT");
	sift_extractor->compute(image1_, keypoints1_, descriptors1_);
	sift_extractor->compute(image2_, keypoints2_, descriptors2_);

	BFMatcher matcher(NORM_L2, true);
	matcher.knnMatch( descriptors1_, descriptors2_, matches_, 1);
}

Mat CVTool::visualizeMatching(){
	CV_Assert(!image1_.empty() && !image2_.empty());
	CV_Assert(!keypoints1_.empty() && !keypoints2_.empty());
	CV_Assert(!matches_.empty());
	Mat img_matches;
	drawMatches( image1_, keypoints1_, image2_, keypoints2_, matches_, img_matches);
	return img_matches;
}

Mat CVTool::repairImage(const cv::Mat & damaged_img_a, const cv::Mat & complete_img_b){

}

void CVTool::visualizeDiffence(const cv::Mat & repaired_img_a, const cv::Mat & complete_img_a){

}

void CVTool::computeFundMatrix(){

}

void CVTool::visualizeEpipolarLine(){

}

/*double CVTool::computeEuclideanDistance(cv::Point2f a, cv::Point2f b) {
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}*/
