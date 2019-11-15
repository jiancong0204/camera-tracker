/** @file BaslerUSBCamera.cpp
* @brief Body file for the Basler USB Camera class.
*
* File that contains the implementation of the Basler USB Camera class. It relies on Pylon/Basler inlcudes but not on Qt.
* Except minor changes, the file BaslerUSBCamera.h, developed by Benjamin Montavon, is used.
* @author Matthias Bodenbenner
* @date 26.04.2017
*/

#include "BaslerUSBCamera.h"


BaslerUSBCamera::BaslerUSBCamera()
{
	this->device = new _BaslerUSBCamera();
}

BaslerUSBCamera::~BaslerUSBCamera()
{
	delete device;
}

std::vector<std::string> BaslerUSBCamera::listAvailableDevices(void)
{
	return _BaslerUSBCamera::listAvailableDevices();
}


bool BaslerUSBCamera::initialize(const std::string id)
{	
	return this->device->initialize(id);
}

void BaslerUSBCamera::detach(void)
{
	this->device->detach();
}

cv::Mat BaslerUSBCamera::getFrame(void)
{
	return this->device->getFrame();
}

bool BaslerUSBCamera::setExposureMode(std::string mode)
{
	if (mode.compare("AUTO") == 0) {
		return device->setExposureMode(AUTO);
	}
	else if (mode.compare("MANUAL") == 0) {
		return device->setExposureMode(MANUAL);
	}
	else if (mode.compare("LASER") == 0) {
		return device->setExposureMode(LASER);
	}
	return false;
}

bool BaslerUSBCamera::setExposure(const double time)
{
	return this->device->setExposure(time);
}

double BaslerUSBCamera::getExposure(void) const
{
	return this->device->getExposure();
}

void BaslerUSBCamera::loadFeatureFile(const std::string filename)
{
	this->device->loadFeatureFile(filename);
}