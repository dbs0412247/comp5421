#include "cvtool.h"

using namespace cv;

CVTool::CVTool(){

	/**
	 * @brief Initialize SIFT structure
	 */
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

	/**
	 * @brief Initialize SURF structure
	 */
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
	m_mser = MSER();

	/**
	 * @brief Initialize Harris Corner Detector params
	 */
	m_harris_blockSize = 10;
	m_harris_ksize = 3;
	m_harris_k = 100;
	m_harris_borderType = BORDER_DEFAULT;
}

void CVTool::detectFeatureSIFT() {

}

void CVTool::detectFeatureSURF(){

}

void CVTool::detectFeatureMSER(){

}

void CVTool::detectFeatureHaris(){

}

void CVTool::matchFeatures(){

}

void CVTool::visualizeMatching(){

}

Mat CVTool::repairImage(const cv::Mat & damaged_img_a, const cv::Mat & complete_img_b){

}

void CVTool::visualizeDiffence(const cv::Mat & repaired_img_a, const cv::Mat & complete_img_a){

}

void CVTool::computeFundMatrix(){

}

void CVTool::visualizeEpipolarLine(){

}
