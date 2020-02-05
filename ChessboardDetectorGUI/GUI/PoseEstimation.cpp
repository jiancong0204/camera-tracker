#include "PoseEstimation.h"

PoseEstimation::PoseEstimation(std::vector<cv::Point3f> grid, float scale, Chessboard chessboard, std::vector<cv::Point2f> corners)
{
	int number = chessboard.getHeight() * chessboard.getWidth();
	PoseEstimation::corners = _rescale_image(corners, scale, number);
	double cam[9];
	double dist[5];
	JsonFile jsonFile;
	json cameraParams = jsonFile.loadJson("camera_parameters.json");
	_get_camera_matrix(cameraParams, cam);
	_get_distortion_coefficients(cameraParams, dist);
	cv::Mat cameraMatrix = cv::Mat(3, 3, CV_64FC1, cam);
	cv::Mat distortionCoefficients = cv::Mat(5, 1, CV_64FC1, dist);
	cv::Mat rvecs, tvecs;
	solvePnP(grid, PoseEstimation::corners, cameraMatrix, distortionCoefficients, this->rvecs, this->tvecs);
	// std::cout << PoseEstimation::corners << std::endl << std::endl;
}

cv::Mat PoseEstimation::getRvecs()
{
	return this->rvecs;
}

cv::Mat PoseEstimation::getTvecs()
{
	return this->tvecs;
}

void PoseEstimation::_get_camera_matrix(json cameraParams, double cam[9])
{
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cam[k] = cameraParams["matrix"][i][j];
			k++;
		}
	}
}

void PoseEstimation::_get_distortion_coefficients(json cameraParams, double dist[5])
{
	for (int i = 0; i < 5; i++)
	{
		dist[i] = cameraParams["distortion"][0][i];
	}
}

std::vector<cv::Point2f> PoseEstimation::_rescale_image(std::vector<cv::Point2f> resizedCorners, float scale, int number)
{
	std::vector<cv::Point2f> originalCorners(number);
	float x;
	float y;
	for (int i = 0; i < number; i++) 
	{
		x = resizedCorners[i].x / scale;
		y = resizedCorners[i].y / scale;
		originalCorners[i] = cv::Point2f(x, y);
	}
	return originalCorners;
}