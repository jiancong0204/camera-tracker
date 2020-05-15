#pragma once
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <QImage>
#include <QString>
#include <windows.h>
#include <ctime>

#include <fstream> 
#include <string>
#include <iostream>
#include <streambuf> 
#include "ChessboardDetector.h"
#include "PoseEstimation.h"
#include "RotationStage.h"
#include "BaslerGigECamera.h"

class Tracking : public QThread
{
	Q_OBJECT
public:
	Tracking(QObject* parent = 0);
	~Tracking() {};
	void exitThread();

protected:
	void run();
	void tracking();
	double theta[2]; // stores the angular displacement for tracking.
	RotationStage mover; // instance for moveing the stage.

private:
	std::ofstream oFile; // define the output stream.
	cv::Mat img;
	QTimer *timer;
	LPCWSTR COM1 = L"COM3";
	LPCWSTR COM2 = L"COM4";
	cv::Mat sourceImg;
	bool isExist = false;
	BaslerGigECamera camera;

signals:
	void returnQString(QString);
};