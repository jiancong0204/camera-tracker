#include "Tracker.h"

void Tracker::startTracking()
{
    this->rs.setElevationPort();
    this->rs.initializeElevation();
    this->rs.initializeAzimuth();
    BaslerGigECamera camera;
    std::vector<std::string> cameraList = camera.listAvailableDevices();
	std::string name = cameraList[0];
	camera.initialize(name);

    // TODO: while loop
	    cv::Mat img = camera.getFrame();
        _computeRotationAngles(img);
        this->rs.relativeMove("USB0", 15);
        this->rs.absoluteMove("USB1", 15);
}