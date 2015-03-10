#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <string>

#ifndef CVTOOL_H
#define CVTOOL_H


/**
 * @brief The CVTool class
 * This class contains all the functions you should implement in the project.
 * The member functions are initially defined, but you should define the parameters and return value yourself.
 * The name of the public member functions cannot be modified.
 * You can add any protected functions or members.
 */
class CVTool
{
public:

    CVTool(std::string path_to_image1, std::string path_to_image2);
    CVTool(const cv::Mat & image1, const cv::Mat & image2);
    /**
     * @brief detectFeatureSIFT takes an image and
     *
     */
    void detectFeatureSIFT(std::vector<cv::KeyPoint>& keypoints1, std::vector<cv::KeyPoint>& keypoints2);
    void detectFeatureSURF(std::vector<cv::KeyPoint>& keypoints1, std::vector<cv::KeyPoint>& keypoints2);
    void detectFeatureMSER(std::vector<cv::KeyPoint>& keypoints1, std::vector<cv::KeyPoint>& keypoints2);
    void detectFeatureHaris(std::vector<cv::KeyPoint>& keypoints1, std::vector<cv::KeyPoint>& keypoints2);

    /*
     * @brief for function 2.
     */
    void matchFeatures(
    		std::vector<cv::KeyPoint>& keypoints1,
    		std::vector<cv::KeyPoint>& keypoints2,
				cv::Mat& descriptors1, cv::Mat& descriptors2,
				std::vector< std::vector<cv::DMatch> >& matches) ;

    void visualizeMatching(
    		const std::vector<cv::KeyPoint>& keypoints1,
        const std::vector<cv::KeyPoint>& keypoints2,
        const std::vector< std::vector<cv::DMatch> >& matches,
				cv::Mat& img_matches);

    /**
     * @brief repairImage
     * @param damaged_img_a
     * @param complete_img_b
     * @return repaired_img_a
     */
    cv::Mat repairImage(const cv::Mat & damaged_img_a, const cv::Mat & complete_img_b);


    /**
     * @brief visualizeDiffence
     * @param repaired_img_a
     * @param complete_img_a
     * compute the difference between the repaired image and the complete image
     */
    void visualizeDiffence(const cv::Mat & repaired_img_a, const cv::Mat & complete_img_a);

    /**
     * @brief for function 4.
     */
    void computeFundMatrix();

    void visualizeEpipolarLine();

protected:
    /**
      * You can add any protected function to help.
      */
    double computeEuclideanDistance(cv::Point2f a, cv::Point2f b);

protected:
    /**
     * @brief image1_, image2_ are the two input images for testing
     */
    cv::Mat image1_, image2_;
/*
    int 		m_sift_nfeatures;
		int 		m_sift_nOctaveLayers;
		double 	m_sift_contrastThreshold;
		double 	m_sift_edgeThreshold;
		double 	m_sift_sigma;
    cv::SIFT::SIFT m_sift;

    double 	m_surf_hessianThreshold;
    int 		m_surf_nOctaves;
    int 		m_surf_nOctaveLayers;
    bool 		m_surf_extended;
    bool 		m_surf_upright;
    cv::SURF::SURF m_surf;

    int 		m_mser_delta;
    int 		m_mser_min_area;
    int 		m_mser_max_area;
    float 	m_mser_max_variation;
    float 	m_mser_min_diversity;
    int 		m_mser_max_evolution;
    double 	m_mser_area_threshold;
    double 	m_mser_min_margin;
    int 		m_mser_edge_blur_size;
    cv::MSER::MSER m_mser;

    int m_harris_blockSize;
		int m_harris_ksize;
		double m_harris_k;
		int m_harris_borderType;
*/


    cv::MserFeatureDetector m_mser;
};

#endif // CVTOOL_H
