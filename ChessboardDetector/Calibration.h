#pragma once
#include "ChessboardDetector.h"
#include "JsonFile.h"

class PoseEstimation
{
public:
	PoseEstimation(std::vector<cv::Point3f> grid, std::vector<cv::Point2f> detectedCorners);
	~PoseEstimation() {};
	cv::Mat getRvecs();
	cv::Mat getTvecs();
private:
	cv::Mat rvecs, tvecs;
	void _get_camera_matrix(json cameraParams, double cam[9]);
	void _get_distortion_coefficients(json cameraParams, double dist[5]);
	
};