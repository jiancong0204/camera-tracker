#include "ChessboardDetector.h"

ChessboardDetector::ChessboardDetector(Chessboard chessboard, cv::Mat sourceImage)
{
	this->maxAxis = 860; // Set the maximal length
	cv::Mat originalImage = sourceImage.clone(); // Clone the image
	// 8-bit/single-channel image (adaptiveThreshold() can only process 8-bit single-channel image) 
	ChessboardDetector::fianlDetectionResult = detectionResult(originalImage, chessboard);
}

ChessboardDetectorResult ChessboardDetector::getResult()
{
	return this->fianlDetectionResult;
}

ChessboardDetectorResult ChessboardDetector::detectionResult(cv::Mat originalImage, Chessboard chessboard)
{
	ChessboardDetectorResult detectionResult;
	PerspectiveResult result;
	ChessboardDetector::originalCorners = findChessboardCorners(originalImage, chessboard);
	if (ChessboardDetector::originalCorners.success)
	{
		result = perspectiveChessboard(ChessboardDetector::originalCorners);
		detectionResult.scale = ChessboardDetector::scale;
		detectionResult.success = ChessboardDetector::originalCorners.success;
		detectionResult.corners = ChessboardDetector::originalCorners.corners;
		detectionResult.boundingBox = result.boundingBox;
		detectionResult.boundingRectangle = result.boundingRectangle;
		detectionResult.perspective = result.perspective;
		detectionResult.image = result.image;
		detectionResult.perspectiveCopy = cv::Mat(detectionResult.perspective.rows, detectionResult.perspective.cols, CV_8UC3);
		cv::cvtColor(detectionResult.perspective, detectionResult.perspectiveCopy, cv::COLOR_GRAY2BGR);
		cv::rectangle(detectionResult.perspectiveCopy, result.boundingRectangle[0], result.boundingRectangle[3], cv::Scalar(250, 0, 0), 2);
		detectionResult.unitWidth = (detectionResult.boundingRectangle[0].x - detectionResult.boundingRectangle[1].x) / (chessboard.getWidth() - 1);
		detectionResult.unitHeight = (detectionResult.boundingRectangle[0].y - detectionResult.boundingRectangle[2].y) / (chessboard.getHeight() - 1);
	}
	else
	{
		detectionResult.success = ChessboardDetector::originalCorners.success;
	}
	return detectionResult;
}

PerspectiveResult ChessboardDetector::perspectiveChessboard(FindCornersResult corners)
{
	PerspectiveResult result;
	result.boundingBox = _compute_bounding_box(corners.corners);
	result.boundingRectangle = _compute_bounding_rectangle(result.boundingBox);
	result.perspective = _compute_perspective_transform(result.boundingBox, result.boundingRectangle, corners.image);
	result.image = corners.image;
	return result;
}

FindCornersResult ChessboardDetector::findChessboardCorners(cv::Mat originalImage, Chessboard chessboard)
{
	FindCornersResult corners;
	corners.image = preprocess(originalImage);
	cv::Size patternSize;
	patternSize.width = chessboard.getWidth();
	patternSize.height = chessboard.getHeight();
	corners.success = cv::findChessboardCornersSB(corners.image, patternSize, corners.corners);
	return corners;
}

cv::Mat ChessboardDetector::preprocess(cv::Mat originalImage)
{
	double imageHeight = originalImage.rows; // height of the original image (pixel)
	double imageWidth = originalImage.cols; // width of the original image (pixel)
	cv::Mat resizedImage;
	// Calculate the resize factor
	if (imageHeight > imageWidth)
	{
		ChessboardDetector::scale = maxAxis / imageHeight;
	}                               
	else
	{
		ChessboardDetector::scale = maxAxis / imageWidth;
	}

	resize(originalImage, resizedImage, cv::Size(), ChessboardDetector::scale, ChessboardDetector::scale); // resize the image

	// apply binarization
	// threshold(resizedImage, resizedImage, 100, 200, THRESH_BINARY); // naive threshold
	// adaptiveThreshold(resizedImage, resizedImage, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);
	return resizedImage;
}

std::vector<cv::Point2f> ChessboardDetector::_compute_bounding_box(std::vector<cv::Point2f> corners)
{
	std::vector<cv::Point2f> src = {
		corners[0],
		corners[8],
		corners[54],
		corners[62]
	};
	return src;
}

std::vector<cv::Point2f> ChessboardDetector::_compute_bounding_rectangle(std::vector<cv::Point2f> src)
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
	x_max = *std::max_element(x_coordinate, x_coordinate + 4);
	y_max = *std::max_element(y_coordinate, y_coordinate + 4);
	x_min = *std::min_element(x_coordinate, x_coordinate + 4);
	y_min = *std::min_element(y_coordinate, y_coordinate + 4);
	std::vector<cv::Point2f> dst = {
	cv::Point2f(x_max, y_max),
	cv::Point2f(x_min, y_max),
	cv::Point2f(x_max, y_min),
	cv::Point2f(x_min, y_min)
	};
	return dst;
}

cv::Mat ChessboardDetector::_compute_perspective_transform(std::vector<cv::Point2f> src, std::vector<cv::Point2f> dst, cv::Mat image)
{
    // corresponding points for perspective transformation
	cv::Mat M = getPerspectiveTransform(src, dst);
	cv::Mat perspective;
	warpPerspective(image, perspective, M, cv::Size(), cv::INTER_LINEAR);
	return perspective;
}

FindCornersResult ChessboardDetector::getOriginalCorners()
{
	return ChessboardDetector::originalCorners;
}
