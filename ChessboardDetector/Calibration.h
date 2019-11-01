#pragma once
#include <opencv.hpp>
#include <iostream>
#include "Grid.h"
#include "ChessboardDetector.h"
#include "JsonFile.h"

using namespace std;
using namespace cv;

class PoseEstimation
{
public:
	PoseEstimation(int height, int width, float size, vector<Point2f> detectedCorners);
	~PoseEstimation() {};
	Mat getRvecs();
	Mat getTvecs();
private:
	Mat rvecs, tvecs;
	vector<Point3f> grid;
	void _get_camera_matrix(json cameraParams, double cam[9]);
	void _get_distortion_coefficients(json cameraParams, double dist[5]);
	
};