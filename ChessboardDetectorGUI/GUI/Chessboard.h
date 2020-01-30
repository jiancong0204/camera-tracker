#pragma once
#include <core.hpp>

class Chessboard
{
public:
	Chessboard(int width, int height, float size);
	~Chessboard() {};
	int getWidth();
	int getHeight();
	float getSize();
	std::vector<cv::Point3f> getGrid();

private:
	int width;
	int height;
	float size;
	std::vector<cv::Point3f> grid;
	std::vector<cv::Point3f> computeGrid();
};
