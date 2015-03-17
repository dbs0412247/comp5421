#include "cvtool.h"

// Debug
#include <iostream>
#include <iomanip>

using namespace cv;
using namespace std;


static Scalar randomColor( RNG& rng )
{
	int icolor = (unsigned) rng;
	return Scalar( icolor&255, (icolor>>8)&255, (icolor>>16)&255 );
}

CVTool::CVTool()
{
	image1_ = Mat();
	image2_ = Mat();
	keypoints1_ = vector<KeyPoint>();
	keypoints2_ = vector<KeyPoint>();
	descriptors1_ = Mat();
	descriptors2_ = Mat();
	matches_ = std::vector<cv::DMatch>();
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
	matches_ = std::vector<cv::DMatch>();
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
	matches_ = std::vector<cv::DMatch>();
	CV_Assert(!image1_.empty() && !image2_.empty());
}

void CVTool::detectFeatureSIFT(bool isMask)
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	Mat mask1 = Mat();
	Mat mask2 = Mat();
	if (isMask) {
		mask1 = getMask(image1_);
		mask2 = getMask(image2_);
	}
	Ptr<FeatureDetector> sift = FeatureDetector::create("SIFT");
	sift->detect(image1_, keypoints1_, mask1);
	sift->detect(image2_, keypoints2_, mask2);
}

void CVTool::detectFeatureSURF(bool isMask)
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	Mat mask1 = Mat();
	Mat mask2 = Mat();
	if (isMask) {
		mask1 = getMask(image1_);
		mask2 = getMask(image2_);
	}
	Ptr<FeatureDetector> surf = FeatureDetector::create("SURF");
	surf->detect(image1_, keypoints1_, mask1);
	surf->detect(image2_, keypoints2_, mask2);
}

void CVTool::detectFeatureMSER(bool isMask)
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	Mat mask1 = Mat();
	Mat mask2 = Mat();
	if (isMask) {
		mask1 = getMask(image1_);
		mask2 = getMask(image2_);
	}
	Ptr<FeatureDetector> mser = FeatureDetector::create("MSER");
	mser->detect(image1_, keypoints1_, mask1);
	mser->detect(image2_, keypoints2_, mask2);
}

void CVTool::detectFeatureHaris(bool isMask)
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	Mat mask1 = Mat();
	Mat mask2 = Mat();
	if (isMask) {
		mask1 = getMask(image1_);
		mask2 = getMask(image2_);
	}
	Ptr<FeatureDetector> harris = FeatureDetector::create("HARRIS");
	harris->detect(image1_, keypoints1_, mask1);
	harris->detect(image2_, keypoints2_, mask2);
}

void CVTool::matchFeatures()
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	CV_Assert(!keypoints1_.empty() && !keypoints2_.empty());
	Ptr<DescriptorExtractor> sift_extractor = DescriptorExtractor::create("SURF");
	sift_extractor->compute(image1_, keypoints1_, descriptors1_);
	sift_extractor->compute(image2_, keypoints2_, descriptors2_);

	BFMatcher matcher(NORM_L2, true);
	matcher.match( descriptors1_, descriptors2_, matches_);
}

Mat CVTool::visualizeMatching()
{
	CV_Assert(!image1_.empty() && !image2_.empty());
	CV_Assert(!keypoints1_.empty() && !keypoints2_.empty());
	CV_Assert(!matches_.empty());
	Mat img_matches, img_kpt1, img_kpt2;
	drawMatches( image1_, keypoints1_, image2_, keypoints2_, matches_, img_matches);
	drawKeypoints(image1_, keypoints1_, img_kpt1);
	drawKeypoints(image2_, keypoints2_, img_kpt2);
	Mat img_out (img_matches.rows*2, img_matches.cols, img_matches.type());
	Rect top_roi (0,0,img_matches.cols,img_matches.rows);
	Rect bot_left_roi (0,img_matches.rows,img_kpt1.cols,img_kpt1.rows);
	Rect bot_right_roi (img_kpt1.cols,img_kpt1.rows,img_kpt1.cols,img_kpt1.rows);
	img_matches.copyTo(img_out(top_roi));
	img_kpt1.copyTo(img_out(bot_left_roi));
	img_kpt2.copyTo(img_out(bot_right_roi));
	return img_out;
}

Mat CVTool::repairImage(const Mat &damaged_img_a, const Mat &complete_img_b)
{
	CV_Assert(!damaged_img_a.empty() && !complete_img_b.empty());
	image1_ = damaged_img_a;
	image2_ = complete_img_b;
	cout << "Repairing images" << endl;
	// detect points and match for calculating homography
	//detectFeatureSIFT();
	detectFeatureSURF();
	//detectFeatureMSER();
	//detectFeatureHaris();
	matchFeatures();
	cout << "Done matching" << endl;
	// extract point2f array from matches
	vector<Point2f> match_pt1, match_pt2;
	//matches2points(matches_, keypoints1_, keypoints2_, match_pt1, match_pt2);
	for (int i = 0; i < matches_.size(); i++)
	{
		//cout << "i = " << i << endl;
		// should only have 1 element for each inner loop
		DMatch dmatch = matches_[i];
		//cout << dmatch.queryIdx << '/' << keypoints1_.size() << endl;
		//cout << dmatch.trainIdx << '/' << keypoints2_.size() << endl;
		match_pt1.push_back(keypoints1_[dmatch.queryIdx].pt);
		match_pt2.push_back(keypoints2_[dmatch.trainIdx].pt);
	}
	Mat homo = findHomography(match_pt1, match_pt2, RANSAC);
	Mat homo_inv = homo.inv();
	Rect damaged_region = findDamagedRegion(damaged_img_a);
	Mat transformed_image;
	warpPerspective(complete_img_b, transformed_image, homo_inv, complete_img_b.size());
	imshow("transformed_image",transformed_image);
	Mat repaired_image  = damaged_img_a.clone();
	Mat repaired_image_roi (repaired_image, damaged_region);
	Mat transformed_image_roi (transformed_image, damaged_region);
	transformed_image_roi.copyTo(repaired_image_roi);
	//imshow("transformed_image", transformed_image);
	//imshow("repaired_image", repaired_image);
	return repaired_image;
}

void CVTool::visualizeDiffence(const Mat &repaired_img_a, const Mat &complete_img_a)
{
	CV_Assert(!repaired_img_a.empty() && !complete_img_a.empty());
	Rect roi_left = Rect(0,0,repaired_img_a.cols, repaired_img_a.rows);
	Rect roi_right = Rect(repaired_img_a.cols,0,repaired_img_a.cols, repaired_img_a.rows);
	Mat output (repaired_img_a.rows, repaired_img_a.cols*2, repaired_img_a.type());
	repaired_img_a.copyTo(output(roi_left));
	complete_img_a.copyTo(output(roi_right));
	imshow("Repaired (left) vs Original (right)", output);

	// Calculate differences
	Mat diff;
	absdiff(repaired_img_a, complete_img_a, diff);
	pow(diff, 2, diff);
	Scalar total_sq_diff = sum(diff);
	double ave = (total_sq_diff[0]+total_sq_diff[1]+total_sq_diff[2]) / 3;
	cout << "Total square difference = " << total_sq_diff << " -> " << fixed << ave << endl;
}

Mat CVTool::computeFundMatrix(bool isUserInput)
{
	Mat fund;
	if (isUserInput)
	{
		//fund = findFundamentalMat(match_pt1, match_pt2, CV_FM_7POINT);

	}

	else // ! using user input
	{
		// get keypoints into vector<Point2f>
		vector<Point2f> match_pt1, match_pt2;
		for (int i = 0; i < matches_.size(); i++)
		{
			//cout << "i = " << i << endl;
			// should only have 1 element for each inner loop
			DMatch dmatch = matches_[i];
			//cout << dmatch.queryIdx << '/' << keypoints1_.size() << endl;
			//cout << dmatch.trainIdx << '/' << keypoints2_.size() << endl;
			match_pt1.push_back(keypoints1_[dmatch.queryIdx].pt);
			match_pt2.push_back(keypoints2_[dmatch.trainIdx].pt);
		}
		fund = findFundamentalMat(match_pt1, match_pt1);
	}
	return fund;
}

Mat CVTool::visualizeEpipolarLine(const Mat& fund)
{
	// get keypoints into vector<Point2f>
	vector<Point2f> match_pt1, match_pt2;
	for (int i = 0; i < 15; i++)
	{
		//cout << "i = " << i << endl;
		// should only have 1 element for each inner loop
		DMatch dmatch = matches_[i];
		//cout << dmatch.queryIdx << '/' << keypoints1_.size() << endl;
		//cout << dmatch.trainIdx << '/' << keypoints2_.size() << endl;
		match_pt1.push_back(keypoints1_[dmatch.queryIdx].pt);
		match_pt2.push_back(keypoints2_[dmatch.trainIdx].pt);
	}
	vector<Point3f> vLine1, vLine2;
	computeCorrespondEpilines(match_pt1, 1, fund, vLine1);
	computeCorrespondEpilines(match_pt2, 2, fund, vLine2);
	RNG rng (0xFFFFFFFF);
	Mat outImage1 = image1_.clone();
	Mat outImage2 = image2_.clone();
	for (int i = 0; i < vLine1.size(); i++) {
		Point3f line1 = vLine1[i];
		Point3f line2 = vLine2[i];
		float a1 = line2.x;
		float b1 = line2.y;
		float c1 = line2.z;
		float a2 = line1.x;
		float b2 = line1.y;
		float c2 = line1.z;
		Point2f pt11 (0, -c1/b1);
		Point2f pt12 (image1_.cols, -(c1+a1*image1_.cols)/b1);
		Point2f pt21 (0, -c2/b2);
		Point2f pt22 (image2_.cols, -(c2+a2*image2_.cols)/b2);
		cv::Scalar color = randomColor(rng);
		line(outImage2, pt11, pt12, color);
		circle(outImage1, match_pt1[i], 3, color);
		line(outImage1, pt21, pt22, color);
		circle(outImage2, match_pt2[i], 3, color);
	}
	Mat img (outImage1.rows, outImage1.cols*2, outImage1.type());
	Rect roiLeft (0,0,outImage1.cols,outImage1.rows);
	Rect roiRight (outImage1.cols,0,outImage1.cols,outImage1.rows);
	outImage1.copyTo(img(roiLeft));
	outImage2.copyTo(img(roiRight));
	return img;
}

// find the box such that the damaged region is enclosed in box
Rect CVTool::findDamagedRegion(const Mat &dmg)
{
	CV_Assert(!dmg.empty());
	int box_x = 0,
			box_y = 0,
			box_width = 1,
			box_length = 1;
	bool first_dmg_px = true;
	for (int row = 0; row < dmg.rows; row++) {
		Mat img_row = dmg.row(row);
		for (int col = 0; col < img_row.cols; col++) {
			Vec3b color = img_row.at<Vec3b>(col);
			if (color[0] == 0 && color[1] == 0 && color[2] == 255) {
				if (first_dmg_px)
				{
					first_dmg_px = false;
					box_x = col;
					box_y = row;
				}
				else
				{
					if ( col < box_x )
					{
						box_width += box_x - col;
						box_x = col;
					}
					if ( row < box_y )
					{
						box_length += box_y - row;
						box_y = row;
					}
					if ( col >= (box_x+box_width) )
						box_width = (col-box_x) + 1;
					if ( row >= (box_y+box_length) )
						box_length = (row-box_y) + 1;
				}	// end else (not first damaged pixel)
			} // end if color is red
	} }// end for

	// enlarge region by 10 pixels in all 4 directions
	if (box_x > 10)
		box_x -= 10;
	else
		box_x = 0;
	if (box_y > 10)
		box_y -= 10;
	else
		box_y = 0;
	if ( (box_x + box_width + 20) < dmg.cols-10 )
		box_width += 20;
	else
		box_width += dmg.cols - box_x - 1;
	if ( (box_y + box_length + 20) < dmg.rows-10 )
		box_length += 20;
	else
		box_length += dmg.rows - box_y - 1;
	cout << box_x << ' ' << box_y << ' ' << box_width << ' ' << box_length << endl;
	return Rect(box_x, box_y, box_width, box_length);
}

Mat CVTool::getMask(const Mat &img, Scalar color_bgr)
{
	CV_Assert(!img.empty());
	CV_Assert(img.channels() == 3);
	vector<Mat> img_bgr;
	split(img, img_bgr);
	vector<Mat> mask_bgr (img_bgr.size());
	for (int i = 0; i < img_bgr.size(); i++)
		compare(img_bgr[i], color_bgr[i], mask_bgr[i], CMP_EQ);
	Mat result;
	bitwise_and(mask_bgr[0], mask_bgr[1], result);
	bitwise_and(mask_bgr[2], result, result);
	// up to here, the result is that all color = color_bgr is high in mask
	bitwise_not(result, result);
	return result;
}
