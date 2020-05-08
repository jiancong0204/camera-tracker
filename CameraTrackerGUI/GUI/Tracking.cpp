#include "Tracking.h"

Tracking::Tracking(QObject* parent) : QThread(parent)
{}

void Tracking::run()
{
	BaslerGigECamera temp_camera;
	camera = temp_camera;
	std::vector<std::string> cameraList = camera.listAvailableDevices();
	std::string name = cameraList[0];
	camera.initialize(name);
	while (true) {
		tracking();
		if (isExist) {
			camera.detach();
			break;
		}
	}
	this->exec();
}

void Tracking::exitThread()
{
    isExist = true;
}

void Tracking::tracking()
{
	QString warning;
	sourceImg = camera.getFrame();
	sourceImg.convertTo(sourceImg, CV_8U);
	//sourceImg = cv::imread("Images/01.jpg", cv::IMREAD_GRAYSCALE);
	Chessboard chessboard(9, 7, 20);
	ChessboardDetector detector(chessboard, sourceImg);
	ChessboardDetectorResult detectionResullt = detector.getResult();
	if (detectionResullt.success)
	{
		PoseEstimation pose = PoseEstimation(chessboard.getGrid(), detectionResullt.scale, chessboard, detectionResullt.corners);
		cv::Mat taux = pose.getTvecs();
		theta[0] = atan(taux.at<double>(1, 0) / taux.at<double>(2, 0)) * (180 / atan(1) / 4) * -1;
		theta[1] = atan(taux.at<double>(0, 0) / taux.at<double>(2, 0)) * (180 / atan(1) / 4);
		////ui.displacement_x->setText(QString::number(theta[0]));
		////ui.displacement_y->setText(QString::number(theta[1]));		
		mover.relativeMove(COM1, theta[0]);
		mover.relativeMove(COM2, theta[1]);
		warning = "Moving";
	}
	else
	{
		warning = "Detection failed!";
	}
	emit returnQString(warning);
}
