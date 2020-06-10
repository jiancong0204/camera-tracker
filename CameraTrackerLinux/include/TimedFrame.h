#pragma once
#include <opencv2/core.hpp>

class TimedFrame
{
public:
	cv::Mat frame;
	double timestamp;

	TimedFrame();
	TimedFrame(cv::Mat frame, double timestamp);
	~TimedFrame() {}
};
