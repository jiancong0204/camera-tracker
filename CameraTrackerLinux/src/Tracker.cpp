#include "Tracker.h"

void Tracker::tracking()
{
    // Initialize the rotation stage
    this->rs.setElevationPort();
    this->rs.setAzimuthPort();
    this->rs.initializeElevation();
    this->rs.initializeAzimuth();
    
    // Initialize the Gige camera
    BaslerGigECamera camera;
    std::vector<std::string> cameraList = camera.listAvailableDevices();
	std::string name = cameraList[0];
	camera.initialize(name);

    // TODO: while loop
	    cv::Mat img = camera.getFrame();
        _computeRotationAngles(img);
        this->rs.relativeMoveElevation(this->elevationAngle);
        this->rs.relativeMoveAzimuth(this->azimuthAngle);

    camera.detach();
}

float Tracker::getAzimuth()
{
    return this->azimuthAngle;
}

float Tracker::getElevation()
{
    return this->elevationAngle;
}

void Tracker::_computeRotationAngles(cv::Mat img)
{
    img.convertTo(img, CV_8U);
    Chessboard chessboard(9, 7, 20);
	ChessboardDetector detector(chessboard, img);
	ChessboardDetectorResult detectionResullt = detector.getResult();

    if (detectionResullt.success)
    {
        printf("Chessboard detection is successful!\n");
        PoseEstimation pose = PoseEstimation(chessboard.getGrid(), detectionResullt.scale, chessboard, detectionResullt.corners);
	    cv::Mat raux = pose.getRvecs();
	    cv::Mat taux = pose.getTvecs();
        this->elevationAngle = atan(taux.at<double>(1, 0) / taux.at<double>(2, 0)) * (180 / atan(1) / 4) * -1;
		this->azimuthAngle = atan(taux.at<double>(0, 0) / taux.at<double>(2, 0)) * (180 / atan(1) / 4);
    }
    else
    {
        printf("Chessboard detection is failed!\n");
        this->elevationAngle = 0;
        this->azimuthAngle = 0;
    }
}