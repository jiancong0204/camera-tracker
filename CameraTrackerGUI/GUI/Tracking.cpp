#include "Tracking.h"

Tracking::Tracking(QObject* parent) : QThread(parent)
{

}

void Tracking::run()
{
		timer = new QTimer;
		timer->start(100);
		connect(timer, &QTimer::timeout, this, &Tracking::showImage);
		//QThread::sleep(0.5);
		this->exec();
}

void Tracking::showImage()
{
	cv::Mat imgBuffer;
	double scale;
	double max = 860;
	int a = 1;
	int b = 6;
	int i = (rand() % (b - a)) + a;
		if (i % 2 == 1)
		{
			imgBuffer = cv::imread("02.jpg", cv::IMREAD_GRAYSCALE);
		}
		else
		{
			imgBuffer = cv::imread("01.jpg", cv::IMREAD_GRAYSCALE);
		}
	scale = max / imgBuffer.cols;
	resize(imgBuffer, img, cv::Size(), scale, scale);
	if (img.channels() == 3)//RGB Img
	{
		cv::Mat Rgb;
		cv::cvtColor(img, Rgb, cv::COLOR_BGR2RGB);
		qImg = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
	}
	else//Gray Img
	{
		qImg = QImage((const uchar*)(img.data), img.cols, img.rows, img.cols * img.channels(), QImage::Format_Indexed8);
	}
	emit returnQImage(qImg);
}
