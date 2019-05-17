#pragma once
#include "Chessboard.h"
#include <opencv2\core\types.hpp>

class ChessboardDetectorParameters
{
public:
	ChessboardDetectorParameters(Chessboard* chessboard, float scale = 1,  cv::TermCriteria terminationCriteria = cv::TermCriteria(cv::TermCriteria::EPS | cv::TermCriteria::MAX_ITER, 30, 0.001));
	~ChessboardDetectorParameters() {};

	
private:
	Chessboard* chessboard;
	float scale;
	cv::TermCriteria terminationCriteria;
};

