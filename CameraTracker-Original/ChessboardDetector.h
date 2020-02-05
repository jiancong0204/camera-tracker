#pragma once
#include <opencv2\core\types.hpp>
#include <nlohmann\json.hpp>
#include "Chessboard.h"

using json = nlohmann::json;

typedef struct {
	std::unique_ptr<Chessboard> chessboard;
	float scale;
	std::unique_ptr<cv::TermCriteria> terminationCriteria;
} ChessboardDetectorParameters;

ChessboardDetectorParameters cdParameters = { std::make_unique<Chessboard>(Chessboard(9,7,19)), 1, std::make_unique<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::EPS | cv::TermCriteria::MAX_ITER, 30, 0.001)) };

typedef struct ChessboardDetectorResult{
	bool success;
	std::vector<cv::Point2f> corners;
	std::vector<cv::Point2f> boundingBox;
	std::vector<cv::Point2f> bondingRectangle;
	cv::Mat perspective;
	float scale;
	float threshold;

	json serialize();
	ChessboardDetectorResult() {};
	ChessboardDetectorResult(json dictionary);

} ChessboardDetectorResult;

class ChessboardDetector
{
public:
	ChessboardDetector(std::unique_ptr<ChessboardDetectorParameters> parameters);
	~ChessboardDetector();

private:
	std::unique_ptr<ChessboardDetectorParameters> parameters;

	int preprocess(const cv::Mat* inImage, cv::Mat outImage, int threshold = -1);
	
};

