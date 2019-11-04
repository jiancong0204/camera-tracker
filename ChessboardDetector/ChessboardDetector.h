#pragma once
#include "Chessboard.h"
#include <opencv.hpp>

typedef struct FindCornersResult 
{
	bool success;
	std::vector<cv::Point2f> corners;
	cv::Mat image;
} FindCornersResult;

typedef struct PerspectiveResult
{
	std::vector<cv::Point2f> boundingBox;
	std::vector<cv::Point2f> boundingRectangle;
	cv::Mat perspective;
} PerspectiveResult;

typedef struct ChessboardDetectorResult 
{
	bool success;
	std::vector<cv::Point2f> corners;
	std::vector<cv::Point2f> boundingBox;
	std::vector<cv::Point2f> boundingRectangle;
	cv::Mat perspective;
	float unitWidth;
	float unitHeight;
	// float scale;
	// float threshold;
} ChessboardDetectorResult;

class ChessboardDetector
{
public:
	ChessboardDetector(Chessboard chessboard);
	~ChessboardDetector() {};
	FindCornersResult findChessboardCorners(cv::Mat image, Chessboard chessboard);
	PerspectiveResult perspectiveChessboard(FindCornersResult corners);
	ChessboardDetectorResult detectionResult(cv::Mat originalImage, Chessboard chessboard);
	ChessboardDetectorResult getResult();
	
private:
	ChessboardDetectorResult deResult;
	int maxAxis = 860;
	cv::Mat _preprocess(cv::Mat original_image);
	cv::Mat _compute_perspective_transform(std::vector<cv::Point2f> src, std::vector<cv::Point2f> dst, cv::Mat image);
	std::vector<cv::Point2f> _compute_bounding_box(std::vector<cv::Point2f> corners);
	std::vector<cv::Point2f> _compute_bounding_rectangle(std::vector<cv::Point2f> src);
	
};