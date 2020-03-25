#include "Tracking.h"

Tracking::Tracking(QObject* parent) : QThread(parent)
{

}

void Tracking::run()
{
	while (TRUE) {
		tracking();
	}
	this->exec();
}

void Tracking::tracking()
{
	srand((unsigned)time(NULL));
	int a = rand() % 20;
	QString warning;
	// cv::Mat sourceImg = _getImage();
	 cv::Mat sourceImg = cv::imread("Images/01.jpg", cv::IMREAD_GRAYSCALE);
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
		warning = "Move " + QString::number(a) + " " + QString::number(a);
	}
	else
	{
		warning = "Detection failed!";
	}
	emit returnQString(warning);
}