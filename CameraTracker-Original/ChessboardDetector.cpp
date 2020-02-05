#include "ChessboardDetector.h"

ChessboardDetector::ChessboardDetector(std::unique_ptr<ChessboardDetectorParameters> parameters)
{
	this->parameters = std::move(parameters);
}

ChessboardDetector::~ChessboardDetector()
{
}

json ChessboardDetectorResult::serialize()
{
	// TODO implement
	return json();
}

ChessboardDetectorResult::ChessboardDetectorResult(json dictionary)
{
	// TODO implement
}
