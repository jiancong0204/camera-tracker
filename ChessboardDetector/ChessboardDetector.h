#pragma once
#include "Chessboard.h"

using namespace std;
using namespace cv;

typedef struct FindCornersResult 
{
	bool success;
	vector<Point2f> corners;
	Mat image;
} FindCornersResult;

typedef struct PerspectiveResult
{
	vector<Point2f> boundingBox;
	vector<Point2f> boundingRectangle;
	Mat perspective;
} PerspectiveResult;

typedef struct ChessboardDetectorResult 
{
	bool success;
	vector<Point2f> corners;
	vector<Point2f> boundingBox;
	vector<Point2f> boundingRectangle;
	Mat perspective;
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
	FindCornersResult findChessboardCorners(Mat image, Chessboard chessboard);
	PerspectiveResult perspectiveChessboard(FindCornersResult corners);
	ChessboardDetectorResult detectionResult(Mat originalImage, Chessboard chessboard);
	ChessboardDetectorResult getResult();
	
private:
	ChessboardDetectorResult deResult;
	int maxAxis = 860;
	Mat _preprocess(Mat original_image);
	Mat _compute_perspective_transform(vector<Point2f> src, vector<Point2f> dst, Mat image);
	vector<Point2f> _compute_bounding_box(vector<Point2f> corners);
	vector<Point2f> _compute_bounding_rectangle(vector<Point2f> src);
	
};