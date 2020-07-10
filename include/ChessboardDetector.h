/**
* @file ChessboardDetector.h
* 
* @brief This file contains the declaration of the ChessboardDetector class
* 
* @author Jiancong Zheng 
* @date 2020-05-29
* 
*/

#pragma once
#include "Chessboard.h"
#include <opencv2/calib3d/calib3d.hpp>

/** 
* @struct FindCornersResult
* @brief Structure that contains the result of corner detection
**/
typedef struct FindCornersResult 
{
	bool                       success;   /**< Indicates whether the searching is successful. */
	std::vector<cv::Point2f>   corners;   /**< Saves the coordinates of corners in the image coordinate system. */
	cv::Mat                    image;     /**< Contains the original image taken by the camera. */
} FindCornersResult;

/** 
* @struct PerspectiveResult
* @brief Structure that contains the result of perspective transformation. 
**/
typedef struct PerspectiveResult
{
	std::vector<cv::Point2f>   boundingBox;         /**< Parallelogram that surrounds all the corners. */
	std::vector<cv::Point2f>   boundingRectangle;   /**< Perspective tansformation of the bounding box. */
	cv::Mat                    image;               /**< Original image. */
	cv::Mat                    perspective;         /**< image after perspection. */
} PerspectiveResult;

/** 
* @struct ChessboardDetectorResult
* @brief Structure that contains the result of chessboard detection
**/
typedef struct ChessboardDetectorResult 
{
	bool                       success;             /**< Indicates whether the detection is successful */
	std::vector<cv::Point2f>   corners;             /**< Coordinates of the corners in the original image. */
	std::vector<cv::Point2f>   boundingBox;         /**< in original image. */
	std::vector<cv::Point2f>   boundingRectangle;   /**< after perspective transformation. */
	cv::Mat                    image;               /**< Original image. */
	cv::Mat                    perspective;         /**< Perspective image. */
	cv::Mat                    perspectiveCopy;     /**< Perspective image with bounding box remarked. */
	float                      unitWidth;           /**< The width of each block in the image. */
	float                      unitHeight;          /**< The height of each block in the image. */
	float                      scale;               /**< The scale used to reduce the size of the image. */
//  float                      threshold;
} ChessboardDetectorResult;

/** 
* @class ChessboardDetector 
* @brief Implementation of chessboard detection.
*
* This class wraps the preprocessing of a image and the detection of the chessboard in the image.
**/
class ChessboardDetector
{
public:

	/** 
    * @brief Constructor that performs the whole procedure to get the chessboard detection result.
    * 
    * @param chessboard Chessboard to detect.
    * @param sourceImage Input image.
    **/
	ChessboardDetector(Chessboard chessboard, cv::Mat sourceImage);

    /**
    * @brief Deconstructor of ChessboardDetector class
    **/
	~ChessboardDetector() {};

	/** 
    * @brief Function that finds the corners in the original image. 
    *
    * @param image Input image.
    * @param chessboard Configuration of the chessboard.
	* @return Structured data of FindCornersResult.
	**/
	FindCornersResult findChessboardCorners(cv::Mat image, Chessboard chessboard);

	/** 
    * @brief Functions that contains the whole procedure of perspective transformation.
    *
    * @param corners Result of finding corners in the image.
	* @return Structured data of PerspectiveResult.
	**/
	PerspectiveResult perspectiveChessboard(FindCornersResult corners);

	/** 
    * @brief Functions that returns the result of chessboard detection.
    *
    * @param originalImage Input image without any preprocessing.
    * @param chessboard Configuration of the chessboard.
	* @return Structured data of ChessboardDetectorResult.
	**/
	ChessboardDetectorResult detectionResult(cv::Mat originalImage, Chessboard chessboard);

	/** 
    * @brief Function used to get the detection result outside the class. 
	* @return structure of ChessboardDetectorResult.
	**/
	ChessboardDetectorResult getResult();

	/** 
    * @brief Function that finds the corners in the original image.
	* @return structure of FindCornersResult.
	**/
	FindCornersResult getOriginalCorners();

	/** 
    * @brief Function that resize the image so that the longest side has 860 pixels.
    *
    * @param originalimage Input image for preprocessing.
	* @return a matrix containing all the intensity values of the pixel points.
	**/
	cv::Mat preprocess(cv::Mat originalImage);

private:
	ChessboardDetectorResult   fianlDetectionResult;   /**< Final result of chessboard detection. */
	FindCornersResult          originalCorners;        /**< Corners of the origianl image. */
	int                        maxAxis;                /**< Desired maximal axis of the image after preprocessing. */
	float                      scale;                  /**< Scale used to reduce the size of the image. */

	/** 
    * @brief Function that calculates the matrix to perfrom perspective transformation. 
    *
    * @param src Source points.s
    * @param dst Destination points.
    * @param image Image before transform.
	* @return an opencv matrix.
	**/
	cv::Mat _compute_perspective_transform(std::vector<cv::Point2f> src, std::vector<cv::Point2f> dst, cv::Mat image);

	/** 
    * @brief Function that estimates the coordinates of corners in the bounding box in the original image. 
    *
    * @param corners Coordinates of the corners.
	* @return a vector of two-dimensional points.
	**/
	std::vector<cv::Point2f> _compute_bounding_box(std::vector<cv::Point2f> corners);

	/** 
    * @brief Function that claculates the coordinates of corners in the assumed bounding box after perspective transformation.
    * 
    * @param src Source points for boundding rectangle computation.
	* @return a vector of two-dimensional points.
	**/
	std::vector<cv::Point2f> _compute_bounding_rectangle(std::vector<cv::Point2f> src);
};
