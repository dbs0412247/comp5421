#ifndef CVTOOL_H
#define CVTOOL_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <string>


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
    void detectFeatureSIFT(bool isMask = false);
    void detectFeatureSURF(bool isMask = false);
    void detectFeatureMSER(bool isMask = false);
    void detectFeatureHaris(bool isMask = false);

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
    cv::Mat computeFundMatrix(bool isUserInput);

    cv::Mat visualizeEpipolarLine(const cv::Mat &fund);

protected:
    /**
      * You can add any protected function to help.
      */
    cv::Rect findDamagedRegion(const cv::Mat&);
    cv::Mat createImage1MaskByColor(const cv::Scalar &color);
    cv::Mat createImage2MaskByColor(const cv::Scalar &color);
    cv::Mat getMask(const cv::Mat &img, cv::Scalar color = cv::Scalar(0,0,0));

protected:
    /**
     * @brief image1_, image2_ are the two input images for testing
     */
    cv::Mat image1_, image2_;
    std::vector<cv::KeyPoint> keypoints1_, keypoints2_;
    cv::Mat descriptors1_, descriptors2_;
    std::vector<cv::DMatch> matches_;
};

#endif // CVTOOL_H
