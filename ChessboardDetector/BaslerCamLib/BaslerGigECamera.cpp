/** @file BaslerGigECamera.cpp
* @brief Body file for the Basler GigE Camera class.
*
* File that contains the implementation of the Basler GigE Camera class. It relies on Pylon/Basler inlcudes but not on Qt.
* @author Benjamin Montavon
* @date 27.11.2015
*/

#include "constants.h"
#include "_BaslerGigECamera.h"
#include "BaslerGigECamera.h"

BaslerGigECamera::BaslerGigECamera() 
{
	this->device = new _BaslerGigECamera();
}


BaslerGigECamera::~BaslerGigECamera()
{
	delete this->device;
}

std::vector<std::string> BaslerGigECamera::listAvailableDevices(void)
{
	return _BaslerGigECamera::listAvailableDevices();
}


bool BaslerGigECamera::initialize(const std::string id)
{
	return this->device->initialize(id);
}

bool BaslerGigECamera::reset() throw(std::exception)
{
	return this->device->reset();
}

void BaslerGigECamera::detach(void)
{
	this->device->detach();
}

cv::Mat BaslerGigECamera::getFrame(void)
{
	return this->device->getFrame();
}

bool BaslerGigECamera::setExposureMode(std::string mode)
{	
	if (mode.compare("AUTO") == 0) {
		return this->device->setExposureMode(AUTO);
	}
	else if (mode.compare("MANUAL") == 0) {
		return this->device->setExposureMode(MANUAL);
	}
	else if (mode.compare("LASER") == 0) {
		return this->device->setExposureMode(LASER);
	}
	return false;
}

bool BaslerGigECamera::setExposure(const double time)
{
	return this->device->setExposure(time);
}

double BaslerGigECamera::getExposure(void) const
{
	return this->device->getExposure();
}

void BaslerGigECamera::loadFeatureFile(const std::string filename)
{
	this->device->loadFeatureFile(filename);
}
