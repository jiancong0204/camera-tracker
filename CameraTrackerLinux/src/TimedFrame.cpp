#include "TimedFrame.h"

TimedFrame::TimedFrame()
{
	this->frame = cv::Mat().clone();
	this->timestamp = 0;
}

TimedFrame::TimedFrame(cv::Mat frame, double timestamp)
{
	this->frame = frame;
	this->timestamp = timestamp;
}
