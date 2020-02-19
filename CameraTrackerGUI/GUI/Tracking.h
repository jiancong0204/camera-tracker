#pragma once
#include <QThread>
#include <QTimer>
#include <QDebug>
#include <QImage>
#include <QString>
#include "ChessboardDetector.h"

class Tracking : public QThread
{
	Q_OBJECT
public:
	Tracking(QObject* parent = 0);
	~Tracking() {};
	void showImage();

protected:
	void run();

private:
	QImage qImg;
	cv::Mat img;
	QTimer *timer;

signals:
	void returnQImage(QImage qImg);
};