#include "cvtool.h"

using namespace cv;

CVTool::CVTool(std::string path_to_image1, std::string path_to_image2){

	initModule_nonfree();
	image1_ = imread(path_to_image1);
	image2_ = imread(path_to_image2);
	CV_Assert(!image1_.empty() && !image2_.empty());

	/**
	 * @brief Initialize SIFT structure
	 */
/*
	m_sift_nfeatures = 0;
	m_sift_nOctaveLayers = 3;
	m_sift_contrastThreshold = 0.04;
	m_sift_edgeThreshold = 10;
	m_sift_sigma = 1.6;
	m_sift = SIFT(
		m_sift_nfeatures,
		m_sift_nOctaveLayers,
		m_sift_contrastThreshold,
		m_sift_edgeThreshold,
		m_sift_sigma);
*/

	/**
	 * @brief Initialize SURF structure
	 */
/*
	m_surf_hessianThreshold = 300;
	m_surf_nOctaves = 4;
	m_surf_nOctaveLayers = 2;
	m_surf_extended = true;
	m_surf_upright = false;
	m_surf = SURF(
		m_surf_hessianThreshold,
		m_surf_nOctaves,
		m_surf_nOctaveLayers,
		m_surf_extended,
		m_surf_upright);
*/
	/**
	 * @brief Initialize MSER structure
	 */
	/* Using default parameters for now
	m_mser_delta = ;
	m_mser_min_area =;
	m_mser_max_area =;
	m_mser_max_variation = ;
	m_mser_min_diversity = ;
	m_mser_max_evolution = ;
	m_mser_area_threshold = ;
	m_mser_min_margin = ;
	m_mser_edge_blur_size = ; */
	//m_mser = MSER();

	/**
	 * @brief Initialize Harris Corner Detector params
	 */
/*
	m_harris_blockSize = 10;
	m_harris_ksize = 3;
	m_harris_k = 100;
	m_harris_borderType = BORDER_DEFAULT;
*/

}

CVTool::CVTool(const cv::Mat & image1, const cv::Mat & image2) {
	initModule_nonfree();
	image1_ = Mat(image1);
	image2_ = Mat(image2);
	CV_Assert(!image1_.empty() && !image2_.empty());
}

void CVTool::detectFeatureSIFT(std::vector<cv::KeyPoint>& keypoints1, std::vector<cv::KeyPoint>& keypoints2) {
	Ptr<FeatureDetector> sift = FeatureDetector::create("SIFT");
	sift->detect(image1_, keypoints1, Mat());
	sift->detect(image2_, keypoints2, Mat());
}

void CVTool::detectFeatureSURF(std::vector<cv::KeyPoint>& keypoints1, std::vector<cv::KeyPoint>& keypoints2){
	Ptr<FeatureDetector> surf = FeatureDetector::create("SURF");
	surf->detect(image1_, keypoints1, Mat());
	surf->detect(image2_, keypoints2, Mat());
}

void CVTool::detectFeatureMSER(std::vector<cv::KeyPoint>& keypoints1, std::vector<cv::KeyPoint>& keypoints2){
	Ptr<FeatureDetector> mser = FeatureDetector::create("MSER");
	mser->detect(image1_, keypoints1, Mat());
	mser->detect(image2_, keypoints2, Mat());
}

void CVTool::detectFeatureHaris(std::vector<cv::KeyPoint>& keypoints1, std::vector<cv::KeyPoint>& keypoints2){
	Ptr<FeatureDetector> harris = FeatureDetector::create("HARRIS");
	harris->detect(image1_, keypoints1, Mat());
	harris->detect(image2_, keypoints2, Mat());
}

void CVTool::matchFeatures(std::vector<cv::KeyPoint>& keypoints1, std::vector<cv::KeyPoint>& keypoints2){
	int size1 = keypoints1.size();
	int size2 = keypoints2.size();
	// Nearest Neighbour matching of keypoints1 to keypoints2
	for (int idx1 = 0; idx1 < size1; idx1++) {
		for (int idx2 = 0; idx2 < size1; idx2++) {
			// TODO: study notes on what is approximation/enumeration method...
		}
	}
}

void CVTool::visualizeMatching(std::vector<cv::KeyPoint>& keypoints1, std::vector<cv::KeyPoint>& keypoints2){
	Mat out1, out2;
	drawKeypoints(image1_, keypoints1, out1);
	drawKeypoints(image2_, keypoints1, out2);
	/*
	imshow("Image 1", out1);
	imshow("image 2", out2);
	waitKey();
	destroyWindow("Image 1");
	destroyWindow("Image 2");
	*/

}

Mat CVTool::repairImage(const cv::Mat & damaged_img_a, const cv::Mat & complete_img_b){

}

void CVTool::visualizeDiffence(const cv::Mat & repaired_img_a, const cv::Mat & complete_img_a){

}

void CVTool::computeFundMatrix(){

}

void CVTool::visualizeEpipolarLine(){

}
