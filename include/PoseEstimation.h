/**
* @file PoseEstimation.h
* 
* @brief This file contains the declaration of the PoseEstimation class.
* 
* @author Jiancong Zheng 
* @date 2020-06-10
* 
*/

#pragma once
#include "ChessboardDetector.h"
#include "JsonUtilization.h"

/** 
* @class PoseEstimation 
* @brief Estimate the pose of the camera according to the target
*
**/
class PoseEstimation
{

public:

	/** 
	* @brief Constructor that calculates the rotation vector and translation vector based on chessboard and corners
	* @param grid The coordinates of all the corners in the chessboard
	* @param scale The scale used to reduce the size of the image
	* @param chessboard Configuration of the chessboard
	* @param corners Coordinates of the corners
	*/
	PoseEstimation(std::vector<cv::Point3f> grid, float scale, Chessboard chessboard, std::vector<cv::Point2f> corners);

	/**
	* @brief Deconstructor
	*/
	~PoseEstimation() {};

	/**
	* @brief Function that gets the rotation vector
	* @return A 3*1 rotation matrix 
	*/
	cv::Mat getRvecs();

	/** 
	* @brief Function that gets the translation vector
	* @return A 3*1 translation matrix 
	*/
	cv::Mat getTvecs();

    /**
	* @brief Get rotation angles
	* @return Array of rotation angles of elevation and azimuth
	*/
	double* getRotationAngle();


private:
	cv::Mat                    rvecs;         //< Matrix for rotation
	cv::Mat                    tvecs;         //< Matrix for translation

	double                     rotation[2];   //< Vector to store rotation angles
	std::vector<cv::Point2f>   corners;       //< Coordinates of the corners

	/** 
	* @brief Function that gets the camera matrix from json file. 
	* @param[in] cameraParams Parameters of the camera
	* @param[out] cam Camera matrix 
	*/
	void _get_camera_matrix(json cameraParams, double cam[9]);

	/** 
	* @brief Function that gets the distortion coefficients from json file
	* @param[in] cameraParams Parameters of the camera
	* @param[out] dist Distortion matrix 
	*/
	void _get_distortion_coefficients(json cameraParams, double dist[5]);

	/** 
	* @brief Undo the resize in order to get the distance values in world coordinate system
	* @param corners Coordinates of the corners in the image
	* @param scale The scale used to reduce the size of the image
	* @param number Number of the corners
	* @return Coordinates of the corners in the original image
	*/
	std::vector<cv::Point2f> _rescale_image(std::vector<cv::Point2f> corners, float scale, int number);

	/** 
	* @brief Function that calculates the rotation angles through applying Rodrigues transformation. 
	* @param raux Rotation vector in cv::Mat
	*/
	void _rodriguesTransformation(cv::Mat raux);


};