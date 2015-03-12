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

		CVTool();
    CVTool(std::string path_to_image1, std::string path_to_image2);
    CVTool(const cv::Mat & image1, const cv::Mat & image2);
    /**
     * @brief detectFeatureSIFT takes an image and
     *
     */
    void detectFeatureSIFT();
    void detectFeatureSURF();
    void detectFeatureMSER();
    void detectFeatureHaris();

    /*
     * @brief for function 2.
     */
    void matchFeatures();

    cv::Mat visualizeMatching();

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
    //double computeEuclideanDistance(cv::Point2f a, cv::Point2f b);

protected:
    /**
     * @brief image1_, image2_ are the two input images for testing
     */
    cv::Mat image1_, image2_;
    std::vector<cv::KeyPoint> keypoints1_, keypoints2_;
    cv::Mat descriptors1_, descriptors2_;
    std::vector< std::vector<cv::DMatch> > matches_;
};

#endif // CVTOOL_H
