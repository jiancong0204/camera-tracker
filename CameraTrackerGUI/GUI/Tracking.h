#pragma once
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <QImage>
#include <QString>
#include "ChessboardDetector.h"
#include "PoseEstimation.h"
#include "RotationStage.h"

class Tracking : public QThread
{
	Q_OBJECT
public:
	Tracking(QObject* parent = 0);
	~Tracking() {};

protected:
	void run();
	void tracking();
	double theta[2]; // stores the angular displacement for tracking.
	RotationStage mover; // instance for moveing the stage.


private:
	cv::Mat img;
	QTimer *timer;
	LPCWSTR COM1 = L"COM3";
	LPCWSTR COM2 = L"COM4";

signals:
	void returnQString(QString);
};