#include "Calibration.h"

PoseEstimation::PoseEstimation(int height, int width, float size, vector<Point2f> detectedCorners)
{
	double cam[9];
	double dist[5];
	Grid gridPoints;
	this->grid = gridPoints.computeGrid(height, width, size);
	JsonFile jsonFile;
	json cameraParams = jsonFile.loadJson("camera_parameters.json");
	_get_camera_matrix(cameraParams, cam);
	_get_distortion_coefficients(cameraParams, dist);
	Mat cameraMatrix = Mat(3, 3, CV_64FC1, cam);
	Mat distortionCoefficients = Mat(5, 1, CV_64FC1, dist);
	Mat rvecs, tvecs;
	solvePnP(this->grid, detectedCorners, cameraMatrix, distortionCoefficients, this->rvecs, this->tvecs);
}

Mat PoseEstimation::getRvecs()
{
	return this->rvecs;
}

Mat PoseEstimation::getTvecs()
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