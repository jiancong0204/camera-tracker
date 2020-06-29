#include "Tracker.h"

void Tracker::run()
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
    while (true)
    {
        if (this->quitting) {
            return;
        }
        else 
        {
            this->img = camera.getFrame();
            // this->img = cv::imread("../Images/01.jpg",cv::IMREAD_GRAYSCALE);
            _emitImage();
            _computeRotationAngles(this->img);
            this->rs.relativeMoveElevation(this->elevationAngle);
            this->rs.relativeMoveAzimuth(this->azimuthAngle);
        }
    }
    // camera.detach();
}

float Tracker::getAzimuth()
{
    return this->azimuthAngle;
}

float Tracker::getElevation()
{
    return this->elevationAngle;
}

void Tracker::_computeRotationAngles(cv::Mat image)
{
    image.convertTo(image, CV_8U);
    Chessboard chessboard(9, 7, 20);
	ChessboardDetector detector(chessboard, image);
	ChessboardDetectorResult detectionResullt = detector.getResult();

    if (detectionResullt.success)
    {
        printf("Chessboard detection is successful!\n");
        PoseEstimation pose = PoseEstimation(chessboard.getGrid(), detectionResullt.scale, chessboard, detectionResullt.corners);
        cv::Mat raux = pose.getRvecs();
        cv::Mat taux = pose.getTvecs();
        this->resizedImg = detector.preprocess(image);
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

void Tracker::quitThread()
{
    this->quitting = true;
}

void Tracker::_emitImage()
{
    QImage qImg;
	cv::Mat rgb;
	if (this->resizedImg.channels() == 3)//RGB Img
	{
		cv::cvtColor(this->resizedImg, rgb, cv::COLOR_BGR2RGB);
		qImg = QImage((const uchar*)(rgb.data), rgb.cols, rgb.rows, rgb.cols * rgb.channels(), QImage::Format_RGB888);
	}
	else//Gray Img
	{
		qImg = QImage((const uchar*)(this->resizedImg.data), this->resizedImg.cols, this->resizedImg.rows, this->resizedImg.cols * this->resizedImg.channels(), QImage::Format_Indexed8);
	}
        
    emit returnQImage(qImg);
}
