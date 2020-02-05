#pragma once
#include "Chessboard.h"
#include <opencv.hpp>

/** Structure that contains the result of corner searching. */
typedef struct FindCornersResult 
{
	bool success; // Indicates if the searching is successful.
	std::vector<cv::Point2f> corners; // Saves the coordinates of corners in the image coordinate system.
	cv::Mat image; // Contains the original image taken by the camera.
} FindCornersResult;

/** Structure that includes the result of perspective transformation. */
typedef struct PerspectiveResult
{
	std::vector<cv::Point2f> boundingBox; // Parallelogram that surrounds all the corners.
	std::vector<cv::Point2f> boundingRectangle; // Perspective tansformation of the bounding box.
	cv::Mat image; // Original image. 
	cv::Mat perspective; // image after perspection.
} PerspectiveResult;

typedef struct ChessboardDetectorResult 
{
	bool success; // Indicates if the detection is successful
	std::vector<cv::Point2f> corners; // Coordinates of the corners in the original image.
	std::vector<cv::Point2f> boundingBox; // in original image
	std::vector<cv::Point2f> boundingRectangle; // after perspective transformation
	cv::Mat image; // Original image
	cv::Mat perspective; // Perspective image
	cv::Mat perspectiveCopy; // Perspective image with bounding box remarked
	float unitWidth; // The width of each block in the image
	float unitHeight; // The height of each block in the image
	float scale;
	// float threshold;
} ChessboardDetectorResult;

class ChessboardDetector
{
public:

	/** Constructor that performs the whole procedure to get the chessboard detector result. */
	ChessboardDetector(Chessboard chessboard, cv::Mat sourceImage);
	~ChessboardDetector() {};

	/** Function that finds the corners in the original image. 
	* @return structure of FindCornersResult.
	*/
	FindCornersResult findChessboardCorners(cv::Mat image, Chessboard chessboard);

	/** Functions that contains the whole procedure of perspective transformation. 
	* @return structure of PerspectiveResult.
	*/
	PerspectiveResult perspectiveChessboard(FindCornersResult corners);

	/** Functions that contains the whole procedure of perspective transformation.
	* @return structure of ChessboardDetectorResult.
	*/
	ChessboardDetectorResult detectionResult(cv::Mat originalImage, Chessboard chessboard);

	/** Function used to get the detection result outside the class. 
	* @return structure of ChessboardDetectorResult.
	*/
	ChessboardDetectorResult getResult();

	/** Function that finds the corners in the 
	* @return structure of FindCornersResult.
	*/
	FindCornersResult getOriginalCorners();

	/** Function that resize the image so that the longest side has 860 pixels. 
	* @return a matrix containing all the intensity values of the pixel points.
	*/
	cv::Mat preprocess(cv::Mat original_image);

private:
	ChessboardDetectorResult deResult;
	FindCornersResult originalCorners;
	cv::Mat sourceImage;
	int maxAxis = 860;
	float scale;

	/** Function that calculates the matrix to perfrom perspective transformation. 
	* @return an opencv matrix.
	*/
	cv::Mat _compute_perspective_transform(std::vector<cv::Point2f> src, std::vector<cv::Point2f> dst, cv::Mat image);

	/** Function that estimates the coordinates of corners in the bounding box in the original image. 
	* @return a vector of two-dimensional points.
	*/
	std::vector<cv::Point2f> _compute_bounding_box(std::vector<cv::Point2f> corners);

	/** Function that claculates the coordinates of corners in the assumed bounding box after perspective transformation.
	* @return a vector of two-dimensional points.
	*/
	std::vector<cv::Point2f> _compute_bounding_rectangle(std::vector<cv::Point2f> src);
};