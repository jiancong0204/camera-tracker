/** @file BaslerGigECamera.cpp
* @brief Body file for the Basler GigE Camera class.
*
* File that contains the implementation of the Basler GigE Camera class. It relies on Pylon/Basler inlcudes but not on Qt.
* @author Benjamin Montavon
* @date 27.11.2015
*/

#include <chrono>
#include "constants.h"
#include "BaslerGigECamera.h"
#include <pylon/PylonUtilityIncludes.h>

using namespace GenICam;
BaslerGigECamera::BaslerGigECamera() : GenericCamera()
{
	Pylon::PylonInitialize();
	device = nullptr;
	pitch = BASLER_DEFAULT_PITCH;
}


BaslerGigECamera::~BaslerGigECamera()
{
	if (device != nullptr)
	{
		if (device->IsOpen())
		{
			device->Close();
		}
		delete device;
	}
	Pylon::PylonTerminate();
}

std::vector<std::string> BaslerGigECamera::listAvailableDevices(void)  throw(std::exception)
{
	std::vector<std::string> foundDevices;
	try
	{
		Pylon::PylonInitialize();
		Pylon::DeviceInfoList_t lstDevices;
		Pylon::CTlFactory::GetInstance().EnumerateDevices(lstDevices);
		if (!lstDevices.empty())
		{
			Pylon::DeviceInfoList_t::const_iterator it;
			for (it = lstDevices.begin(); it != lstDevices.end(); ++it)
			{
				if (it->GetDeviceClass() == Pylon::CBaslerGigEInstantCamera::DeviceClass())
				{
					foundDevices.push_back(it->GetFullName().c_str());
				}
			}
		}
		Pylon::PylonTerminate();
	}
	catch (GenericException& e)
	{
		throw std::exception(e.GetDescription());
	}
	return foundDevices;
}


bool BaslerGigECamera::initialize(const std::string id)  throw(std::exception)
{
	if (device != nullptr)
	{
		detach();
	}
	name = id;
	try
	{
		Pylon::DeviceInfoList_t lstDevices;
		Pylon::CTlFactory& TlFactory = Pylon::CTlFactory::GetInstance();
		TlFactory.EnumerateDevices(lstDevices);
		if (!lstDevices.empty())
		{
			Pylon::DeviceInfoList_t::const_iterator it;
			for (it = lstDevices.begin(); it != lstDevices.end(); ++it)
			{
				if (it->GetFullName().c_str() == id)
				{
					break;
				}
			}
			if (it == lstDevices.end())
			{
				throw std::runtime_error("Camera not found in list of availabe devices");
			}
			this->id = id;
			device = new Pylon::CBaslerGigEInstantCamera(TlFactory.CreateDevice(*it));
			device->Open();
			device->PixelFormat.SetValue(Basler_GigECameraParams::PixelFormat_Mono8);
			device->ExposureAuto.SetValue(Basler_GigECameraParams::ExposureAuto_Off);
			device->RegisterConfiguration(new Pylon::CSoftwareTriggerConfiguration, Pylon::RegistrationMode_ReplaceAll, Pylon::Cleanup_Delete);
			exposureStep = device->ExposureTimeAbs.GetMin() / 1000.0;
			device->ExposureAuto.SetValue(Basler_GigECameraParams::ExposureAuto_Continuous);
			device->StartGrabbing(Pylon::GrabStrategy_LatestImageOnly);
			return true;
		}
	}
	catch (GenericException& e)
	{
		if (device->IsOpen())
		{
			device->Close();
		}
		throw std::exception(e.GetDescription());
	}
	return false;
}

bool BaslerGigECamera::reset() throw(std::exception)
{	
	this->detach();
	return this->initialize(this->id);
}

void BaslerGigECamera::detach(void)  throw(std::exception)
{
	if (this->device != nullptr)
	{
		try
		{
			if (this->device->IsOpen())
			{
				this->device->StopGrabbing();
				this->device->Close();
			}
			delete this->device;
		}
		catch (GenericException& e)
		{
			throw std::exception(e.GetDescription());
		}
	}
}

cv::Mat BaslerGigECamera::getFrame(void)  throw(std::exception)
{
	//std::cout << "start: " << std::chrono::system_clock::now().time_since_epoch().count() << std::endl;
	if (device == nullptr)
	{
		throw std::logic_error("Trying to read from uninitialized device!");
		return cv::Mat().clone();
	}
	try
	{
		Pylon::CGrabResultPtr grabResult;
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			//std::cout << "WaitForFrameTriggerReady: " << std::chrono::system_clock::now().time_since_epoch().count() << std::endl;
			device->WaitForFrameTriggerReady(10000);
			//std::cout << "ExecuteSoftwareTrigger: " << std::chrono::system_clock::now().time_since_epoch().count() << std::endl;
			device->ExecuteSoftwareTrigger();
			//std::cout << "RetrieveResult: " << std::chrono::system_clock::now().time_since_epoch().count() << std::endl;
			device->RetrieveResult(10000, grabResult);
			if (grabResult->GrabSucceeded())
			{
				break;
			}
		}
		if (i == 10)
		{
			throw std::runtime_error("No Valid Image acquired in 10 attempts!");
		}
		int width = grabResult->GetWidth();
		int height = grabResult->GetHeight();
		uint16_t* buffer = static_cast<uint16_t*>(grabResult->GetBuffer());
		cv::Mat cvImage(height, width, CV_8U, buffer, cv::Mat::AUTO_STEP);
		//cvImage *= 1.0 * CV_DOWNSCALE_12_8;
		if (exposureMode == LASER)
		{
			laserExposure(cvImage);
		}
		cvImage.convertTo(cvImage, CV_8U);
		//std::cout << "Finish: " << std::chrono::system_clock::now().time_since_epoch().count() << std::endl;
		return cvImage.clone();
	}
	catch (GenericException& e)
	{
		if (device->IsCameraDeviceRemoved())
		{
			throw disconnected_exception((std::string("Connection to ") + name + std::string(" lost!")).c_str());
		}
		throw std::exception(e.GetDescription());
	    return cv::Mat().clone();
	}
}

bool BaslerGigECamera::setExposureMode(ExposureModes mode)  throw(std::exception)
{
	GenericCamera::setExposureMode(mode);
	if (device != nullptr)
	{
		try
		{
			if (device->IsOpen() && !device->IsCameraDeviceRemoved())
			{
				if (mode == AUTO)
				{
					device->ExposureAuto.SetValue(Basler_GigECameraParams::ExposureAuto_Continuous);
					// std::cout << "Set Exposure mode to AUTO" << std::endl;
					return true;
				}
				if ((mode == MANUAL) || (mode == LASER))
				{
					device->ExposureAuto.SetValue(Basler_GigECameraParams::ExposureAuto_Off);
					// std::cout << "Set Exposure mode to MANUAL" << std::endl;
					return true;
				}
			}
		}
		catch (GenericException& e)
		{
			throw std::exception(e.GetDescription());
		}
	}
	else
	{
		throw std::logic_error("Trying to set exposure mode for unitialized device!");
	}
	return false;
}

bool BaslerGigECamera::setExposure(const double time)  throw(std::exception)
{
	if (device != nullptr)
	{
		try
		{
			if (device->IsOpen() && !device->IsCameraDeviceRemoved())
			{
				if (device->ExposureAuto.GetValue() == Basler_GigECameraParams::ExposureAuto_Off)
				{
					device->ExposureTimeAbs.SetValue(time * 1000, false);
					return true;
				}
			}
		}
		catch (GenericException& e)
		{
			throw std::exception(e.GetDescription());
		}
	}
	else
	{
		throw std::logic_error("Trying to set exposure mode for unitialized device!");
	}
	return false;
}

double BaslerGigECamera::getExposure(void) const  throw(std::exception)
{
	if (device != nullptr)
	{
		try
		{
			if (device->IsOpen() && !device->IsCameraDeviceRemoved())
			{
				return device->ExposureTimeAbs.GetValue() / 1000;
			}
		}
		catch (GenericException& e)
		{
			throw std::exception(e.GetDescription());
		}
	}
	else
	{
		throw std::logic_error("Trying to read exposure mode from unitialized device!");
	}
	return 0.0;
}

void BaslerGigECamera::loadFeatureFile(const std::string filename) throw(std::exception)
{
	if (device != nullptr)
	{
		try
		{
			if (device->IsOpen() && !device->IsCameraDeviceRemoved())
			{
				Pylon::CFeaturePersistence::Load(filename.c_str(), &(device->GetNodeMap()), true);
			}
		}
		catch (GenericException& e)
		{
			throw std::exception(e.GetDescription());
		}
	}
	else
	{
		throw std::logic_error("Trying to load feature file to an unitialized device!");
	}
}
