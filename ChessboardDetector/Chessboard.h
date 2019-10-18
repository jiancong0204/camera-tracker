#pragma once
#include <core.hpp>

using namespace std;
class Chessboard
{
public:
	Chessboard(int width, int height, float size);
	~Chessboard() {};
	int getWidth();
	int getHeight();
	float getSize();
	// vector<cv::Point3f> getGrid();

private:
	int width;
	int height;
	float size;
	// vector<cv::Point3f> grid;
	// vector<cv::Point3f> computeGrid();
};
