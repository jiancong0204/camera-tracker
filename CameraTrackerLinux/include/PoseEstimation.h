#pragma once
#include "ChessboardDetector.h"
#include "JsonUtilization.h"

class PoseEstimation
{

public:

	/** Function that calculates the rotation vector and translation vector based on chessboard and corners. */
	PoseEstimation(std::vector<cv::Point3f> grid, float scale, Chessboard chessboard, std::vector<cv::Point2f> corners);
	~PoseEstimation() {};

	/** Function that gets the rotation vector. */
	cv::Mat getRvecs();

	/** Function that gets the translation vector. */
	cv::Mat getTvecs();

	double* getRotationAngle();

private:
	cv::Mat rvecs, tvecs;

	double rotation[2];

	/** Function that gets the camera matrix from json file. */
	void _get_camera_matrix(json cameraParams, double cam[9]);

	/** Function that gets the distortion coefficients from json file. */
	void _get_distortion_coefficients(json cameraParams, double dist[5]);

	/** Undo the resize in order to get the distance values in world coordinate system. */
	std::vector<cv::Point2f> _rescale_image(std::vector<cv::Point2f> corners, float sclae, int number);

	/** Function that calculates the rotation angles through applying Rodrigues transformation. */
	void _rodriguesTransformation(cv::Mat raux);

	std::vector<cv::Point2f> corners;
};