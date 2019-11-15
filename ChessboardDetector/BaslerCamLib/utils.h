#pragma once
/** @file utils.h
* @brief Header for common used utility functions.
*
* @author Matthias Bodenbenner
* @date 27.04.2017
*/

#include <opencv2/imgproc.hpp>
#include "constants.h"

#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))

namespace utils
{
	/**
	 * Resizes a given image
	 * After resizing the longer axis (x or y) of the image has length max_axis.
	 * Preserves aspect ratio.
	 * 
	 * @param[in]	src		the source image
	 * @param[out]	dst		the resized destination image
	 * @param[in]	max_axis	length of the longer axis in pixels
	 */
	void resize(const cv::Mat& src, cv::Mat& dst, int max_axis);

	/**
	* Resizes a given image by the given factor.
	* Preserves aspect ratio.
	*
	* @param[in]	src		the source image
	* @param[out]	dst		the resized destination image
	* @param[in]	factor	for resizing
	*/
	void resize(const cv::Mat& src, cv::Mat& dst, double factor);

	/**
	* Resizes a given image
	* After resizing the stated axis has the given length.
	* Preserves aspect ratio.
	*
	* @param[in]	src		the source image
	* @param[out]	dst		the resized destination image
	* @param[in]	length	of the stated axis after resizing
	* @param[in]	axis	which should have given length (0 = x-axis, 1 = y-axis)
	*/
	void resize(const cv::Mat& src, cv::Mat& dst, int length, int axis);

	/**
	* Resizes a given rectangle
	* After resizing the longer axis (x or y) of the rectangle has length max_axis.
	* Preserves aspect ratio.
	*
	* @param[in]	src		the source rectangle
	* @param[out]	dst		the resized destination rectangle
	* @param[in]	max_axis	length of the longer axis in pixels
	*/
	void resize(const cv::Rect& src, cv::Rect& dst, int max_axis);

	/**
	 * Rotates an image
	 * Rotates an image around the center by the given angle.
	 * 
	 * @param[in]	src		the source image
	 * @param[out]	dst		the rotated destination image
	 * @param[in]	angle	rotation angle, given in degrees
	 */
	void rotate(const cv::Mat& src, cv::Mat& dst, int angle);

	/**
	 * Automatically cuts an image to relevant data
	 * The image is processed with Canny edge detection and the most outer pixels define a region of interest.
	 * The image is then cutted to this region.
	 * 
	 * @param[in]	src		the source image
	 * @param[out]	dst		the cutted destination image
	 * @param[out]	rect	the region of interest having same size and position as dst
	 * @return	true, if process is succesful, false otherwise
	 */
	bool autocut(const cv::Mat& src, cv::Mat& dst, cv::Rect& rect);

	/**
	 * Shows an image ba calling cv::imshow
	 * Sets the size and position of the window.
	 * 
	 * @param[in]	window_name		of the window
	 * @param[in]	image	the image to be shown in the image
	 * @param[in]	size	of the image as desribed in @see resize(src, dst, max_axis)
	 */
	void showImage(const char* window_name, cv::Mat& image, int size = MAX_IMAGE_AXIS);

	/**
	 * Shows two images aligned horizontally
	 * Sets the size and position of the window.
	 * For better overview images are seperated by a vertical blue line.
	 * 
	 * @param[in]	window_name		of the window
	 * @param[in]	images	vector of images (must have exactly two entries)
	 * @param[in]	size	of the aligned images as desribed in @see resize(src, dst, max_axis)
	 */
	void showStereoImage(const char* window_name, std::vector<cv::Mat>& images, int size = MAX_IMAGE_AXIS);

	/**
	 * Shows two images aligned horizontally
	 * This is an overloaded member function, provided for convenience. 
	 * It differs from the above function only in what argument(s) it accepts.
	 */
	void showStereoImage(const char* window_name, const cv::Mat& left_image, const cv::Mat& right_image, int size = MAX_IMAGE_AXIS);

	/**
	 * Shows a set of images aligen horizontally
	 * Sets the size and position of the window.
	 * For better overview images are seperated by a vertical blue line.
	 * 
	 * @param[in]	window_name		of the window
	 * @param[in]	images	vector of images
	 * @param[in]	size	of the aligned images as desribed in @see resize(src, dst, max_axis)
	 */
	void showCombinedImages(const char* window_name, std::vector<cv::Mat>& images, int size = MAX_IMAGE_AXIS);

	/**
	 * Returns length of shorter axis, x or y, respectively.
	 * 
	 * @param[in] size
	 * @return length of shorter axis (x or y)
	 */
	int min_size(cv::Size size);

	/**
	* Returns length of longer axis, x or y, respectively.
	*
	* @param[in] size
	* @return length of longer axis (x or y)
	*/
	int max_size(cv::Size size);

	/**
	 * Extracts the coordinates of a given set of keypoints.
	 * 
	 * @param[in]	src	set of keypoints
	 * @param[out]	dst	the set of points of the keypoints
	 */
	void getCoordinates(const std::vector<cv::KeyPoint>& src, std::vector<cv::Point2f>& dst);

	/**
	 * Converts a 3D Point into a 1x3 matrix.
	 * 
	 * @param[in] point	to be converted to a matrix
	 * @return	the matrix
	 */
	cv::Mat PointToMat(const cv::Point3f& point);

	/**
	* Converts a 1x3 matrix into a 3D Point.
	*
	* @param[in] mat	to be converted to a point
	* @return	the point
	*/
	cv::Point3f MatToPoint(const cv::Mat& mat);

	/**
	 * Computes the crossproduct matrix of a vector.
	 * 
	 * @param[in] src a 1x3 column vector 
	 * @param[out] dst a 3x3 matrix
	 */
	void crossproductMatrix(const cv::Mat& src, cv::Mat& dst);

	/**
	 * Converts points into homogeneneous coordinates
	 * 
	 * @param[in] src	XxN (X \in {2,3}) matrix of N XD-points
	 * @param[out] dst	(X+1)xN matrix of N (X+1)D-points  
	 */
	void convertPointsToHomogeneous(const cv::Mat& src, cv::Mat& dst);

	/**
	* Converts points from homogeneneous coordinates
	*
	* @param[in] src	XxN (X \in {3,4}) matrix of N XD-points
	* @param[out] dst	(X+1)xN matrix of N (X-1)D-points
	*/
	void convertPointsFromHomogeneous(const cv::Mat& src, cv::Mat& dst);

	/**
	* Finds intersection point of two lines.
	* Each line is given by two points (p1,p2) (q1,q2)
	* 
	* @param[in]	p1	first point of first line
	* @param[in]	p2	second point of first line
	* @param[in]	q1	first point of second line
	* @param[in]	q2	second point of second line
	* @param[out]	r	intersection point
	* @return	true, if the two lines intersect between the given points, false otherwise
	*/
	bool intersection(cv::Point2f p1, cv::Point2f p2, cv::Point2f q1, cv::Point2f q2,
	                  cv::Point2f& r);

	/**
	 * Transforms the representation of a line.
	 * Given: one point and the normal vector
	 * Result: two points on the line´having distance length
	 * 
	 * @param[in]	line	a line given by one point and the normal vector
	 * @param[out]	p1	first point on the line
	 * @param[out]	p2	second point on the line
	 */
	void PointsOnLine(cv::Vec4f& line, cv::Point2f& p1, cv::Point2f& p2, int length);

	/**
	 * Computes the pair-wise distance matrix for a set of keypoints.
	 * 
	 * @param[in]	keypoints	a set of keypoints
	 * @param[out]	dist_mat	the symmetric distance matrix
	 */
	void computeDistanceMatrix(std::vector<cv::KeyPoint>& keypoints, cv::Mat& dist_mat);

	/**
	 * Checks whether a given vector contains the given element
	 * 
	 * @param[in]	vec	the vector which is tested for inheritence of elem
	 * @param[in]	elem	the element which should be found in vec
	 * @return	true, if vec contains elem, false otherwise
	 */
	template <typename T>
	bool contains(std::vector<T> vec, T elem)
	{
		return std::find(vec.begin(), vec.end(), elem) != vec.end();
	}

	/**
	 * Computes the center point of a set of points.
	 * @param[in] pts	a set of points
	 * @return	the center point
	 */
	cv::Point2f computeCenter(const std::vector<cv::Point2f>& pts);

	/**
	* Computes the center point of a set of points.
	* @param[in] pts	a set of points
	* @return	the center point
	*/
	cv::Point3f computeCenter(const std::vector<cv::Point3f>& pts);

	/**
	 * Saves a frame at a specified position. The name of the jpg file is the current time stamp.
	 * @param[in]	frame	an arbitrary image
	 */
	void saveFrame(const cv::Mat& frame);

	/**
	 * Splits a string into a vector of strings according to the given delimiter.
	 * @param[in] str	the string which should be splitted
	 * @param[in] delim	the delimiter used for splitting
	 */
	cv::Point3f split(const std::string& str, const char delim);

	inline std::string cvMatTypeToString(const int type)
	{
		switch (type)
		{
		case 0: return "CV_8U -C1";
		case 1: return "CV_8S -C1";
		case 2: return "CV_16U -C1";
		case 3: return "CV_16S -C1";
		case 4: return "CV_32S	-C1";
		case 5: return "CV_32F -C1";
		case 6: return "CV_64F -C1";
		case 8: return "CV_8UC2";
		case 9: return "CV_8SC2";
		case 10: return "CV_16UC2";
		case 11: return "CV_16SC2";
		case 12: return "CV_32SC2";
		case 13: return "CV_32FC2";
		case 14: return "CV_64FC2";
		case 16: return "CV_8UC3";
		case 17: return "CV_8SC3";
		case 18: return "CV_16UC3";
		case 19: return "CV_16SC3";
		case 20: return "CV_32SC3";
		case 21: return "CV_32FC3";
		case 22: return "CV_64FC3";
		case 24: return "CV_8UC4";
		case 25: return "CV_8SC4";
		case 26: return "CV_16UC4";
		case 27: return "CV_16SC4";
		case 28: return "CV_32SC4";
		case 29: return "CV_32FC4";
		case 30: return "CV_64FC4";
		default:
			return "No Mat Type";
		}
	}
}
