#include <iostream>
#include <opencv.hpp>
#include "Chessboard.h"
#include "ChessboardDetector.h"

using namespace std;
using namespace cv;

ChessboardDetector::ChessboardDetector()
{
	Mat originalImage = imread("Images/12.jpg"); // , CV_8UC1);
	// 8-bit/single-channel image (adaptiveThreshold() can only process 8-bit single-channel image) 
	deResult = detectionResult(originalImage);
	this->deResult = deResult;
}

ChessboardDetectorResult ChessboardDetector::getResult()
{
	return this->deResult;
}

ChessboardDetectorResult ChessboardDetector::detectionResult(Mat originalImage)
{
	ChessboardDetectorResult detectionResult;
	FindCornersResult corners;
	PerspectiveResult result;
	corners = findChessboardCorners(originalImage);
	result = perspectiveChessboard(corners);
	detectionResult.success = corners.success;
	detectionResult.corners = corners.corners;
	detectionResult.boundingBox = result.boundingBox;
	detectionResult.boundingRectangle = result.boundingRectangle;
	detectionResult.perspective = result.perspective;
	detectionResult.unitWidth = (detectionResult.boundingRectangle[0].x - detectionResult.boundingRectangle[1].x) / (chessboard.getWidth() - 1);
	detectionResult.unitHeight = (detectionResult.boundingRectangle[0].y - detectionResult.boundingRectangle[2].y) / (chessboard.getHeight() - 1);
	return detectionResult;
}

PerspectiveResult ChessboardDetector::perspectiveChessboard(FindCornersResult corners)
{
	PerspectiveResult result;
	result.boundingBox = _compute_bounding_box(corners.corners);
	result.boundingRectangle = _compute_bounding_rectangle(result.boundingBox);
	result.perspective = _compute_perspective_transform(result.boundingBox, result.boundingRectangle, corners.image);
	rectangle(result.perspective, result.boundingRectangle[0], result.boundingRectangle[3], Scalar(250, 0, 0), 2);
	return result;
}

FindCornersResult ChessboardDetector::findChessboardCorners(Mat originalImage)
{
	FindCornersResult corners;
	corners.image = _preprocess(originalImage);
	Size patternSize;
	patternSize.width = chessboard.getWidth();
	patternSize.height = chessboard.getHeight();
	corners.success = findChessboardCornersSB(corners.image, patternSize, corners.corners);
	return corners;
}

Mat ChessboardDetector::_preprocess(Mat originalImage)
{
	double imageHeight = originalImage.rows; // height of the original image (pixel)
	double imageWidth = originalImage.cols; // width of the original image (pixel)
	double factor;
	Mat resizedImage;
	// Calculate the resize factor /////////////////
	if (imageHeight > imageWidth)
	{
		factor = maxAxis / imageHeight;
	}
	else
	{
		factor = maxAxis / imageWidth;
	}
	resize(originalImage, resizedImage, Size(), factor, factor); // resize the image

	// apply binarization //////////////////////
	// threshold(resizedImage, resizedImage, 100, 200, THRESH_BINARY); // naive threshold
	// adaptiveThreshold(resizedImage, resizedImage, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);

	return resizedImage;
}

vector<Point2f> ChessboardDetector::_compute_bounding_box(vector<Point2f> corners)
{
	vector<Point2f> src = {
		corners[0],
		corners[8],
		corners[54],
		corners[62]
	};
	return src;
}

vector<Point2f> ChessboardDetector::_compute_bounding_rectangle(vector<Point2f> src)
{
	double x_max;
	double y_max;
	double x_min;
	double y_min;
	float x_coordinate[4];
	float y_coordinate[4];
	x_coordinate[0] = src[0].x;
	x_coordinate[1] = src[1].x;
	x_coordinate[2] = src[2].x;
	x_coordinate[3] = src[3].x;
	y_coordinate[0] = src[0].y;
	y_coordinate[1] = src[1].y;
	y_coordinate[2] = src[2].y;
	y_coordinate[3] = src[3].y;
	x_max = *max_element(x_coordinate, x_coordinate + 4);
	y_max = *max_element(y_coordinate, y_coordinate + 4);
	x_min = *min_element(x_coordinate, x_coordinate + 4);
	y_min = *min_element(y_coordinate, y_coordinate + 4);
	vector<Point2f> dst = {
	Point2f(x_max, y_max),
	Point2f(x_min, y_max),
	Point2f(x_max, y_min),
	Point2f(x_min, y_min)
	};
	return dst;
}

Mat ChessboardDetector::_compute_perspective_transform(vector<Point2f> src, vector<Point2f> dst, Mat image)
{
 // corresponding points for perspective transformation
	Mat M = getPerspectiveTransform(src, dst);
	Mat perspective;
	warpPerspective(image, perspective, M, Size(), INTER_LINEAR);
	return perspective;
}