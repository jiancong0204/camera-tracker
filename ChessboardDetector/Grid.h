#pragma once
#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

class Grid
{
public :
	vector<Point3f> computeGrid(int height, int width, int size);
private:
	int height;
	int width;
	float size;
};