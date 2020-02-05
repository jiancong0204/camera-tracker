/** @file GenericCamera.cpp
* @brief Boday of the camera base class.
*
* File implementing the abstract base class functions for any kind of camera devices
* @author Benjamin Montavon
* @date 27.11.2015
*/

//#include "stdafx.h"
#include "constants.h"
#include "GenericCamera.h"

GenericCamera::GenericCamera()
{
	exposureMode = AUTO;
	pitch = 1.0;
	//mutex = new QMutex(QMutex::RecursionMode::Recursive);
}


GenericCamera::~GenericCamera()
{
	//delete mutex;
}

bool GenericCamera::setExposureMode(ExposureModes mode)
{
	exposureMode = mode;
	if (mode == AUTO)
	{
		exposureState = GOOD;
	}
	else if (mode == MANUAL)
	{
		exposureState = GOOD;
	}
	else if (mode == LASER)
	{
		exposureState = BAD;
	}

	return true;
}

bool GenericCamera::laserExposure(cv::Mat& image)
{
	bool good = false;
	double currentExposure = getExposure();
	double newExposure = 0.0;

	int height = image.rows;
	int width = image.cols;
	int size = width * height;

	double lowLimit = 0.4;
	double highLimit = 0.95;

	double maxOverExposed = 1e-4;
	double minNormalExposed = 1e-3;

	int overExposed = 0;
	int normalExposed = 0;
	int underExposed = 0;

	CV_CPP_TYPE currentPixel = 0;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			currentPixel = image.at<CV_CPP_TYPE>(y, x);
			if (currentPixel > highLimit * CV_MAX_VALUE)
			{
				overExposed++;
			}
			else if ((currentPixel <= highLimit * CV_MAX_VALUE) && (currentPixel > lowLimit * CV_MAX_VALUE))
			{
				normalExposed++;
			}
		}
	}

	if (overExposed > lround(maxOverExposed * size))
	{
		good = false;
		newExposure = currentExposure / 2.0;
		if ((currentExposure - newExposure) < exposureStep)
		{
			newExposure = currentExposure - exposureStep;
		}
		setExposure(newExposure);
	}
	else if (normalExposed < lround(minNormalExposed * size))
	{
		good = false;
		newExposure = currentExposure * 1.5;
		if ((newExposure - currentExposure) < exposureStep)
		{
			newExposure = currentExposure + exposureStep;
		}
		setExposure(newExposure);
	}
	else
	{
		good = true;
	}
	if (good)
	{
		exposureState = GOOD;
	}
	else
	{
		exposureState = BAD;
	}
	return good;
}
