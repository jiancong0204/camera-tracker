/** @file _BaslerUSBCamera.cpp
* @brief Body file for the Basler USB Camera class.
*
* File that contains the implementation of the Basler USB Camera class. It relies on Pylon/Basler inlcudes but not on Qt.
* Except minor changes, the file _BaslerUSBCamera.h, developed by Benjamin Montavon, is used.
* @author Matthias Bodenbenner
* @date 26.04.2017
*/

#include "constants.h"
#include "_BaslerUSBCamera.h"
#include <pylon/PylonUtilityIncludes.h>
#include <opencv2/imgproc.hpp>

using namespace GenICam;

_BaslerUSBCamera::_BaslerUSBCamera() : _GenericCamera()
{
	Pylon::PylonInitialize();
	device = nullptr;
	pitch = BASLER_DEFAULT_PITCH;
}

_BaslerUSBCamera::~_BaslerUSBCamera()
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

std::vector<std::string> _BaslerUSBCamera::listAvailableDevices(void)
{
	std::vector<std::string> foundDevices;
	try
	{
		//Pylon::PylonInitialize();
		Pylon::DeviceInfoList_t lstDevices;
		Pylon::CTlFactory::GetInstance().EnumerateDevices(lstDevices);
		if (!lstDevices.empty())
		{
			Pylon::DeviceInfoList_t::const_iterator it;
			for (it = lstDevices.begin(); it != lstDevices.end(); ++it)
			{
				if (it->GetDeviceClass() == Pylon::CBaslerUsbInstantCamera::DeviceClass())
				{
					foundDevices.push_back(it->GetSerialNumber().c_str());
				}
			}
		}
		//Pylon::PylonTerminate();
	}
	catch (GenericException& e)
	{
		throw std::exception(e.GetDescription());
	}
	return foundDevices;
}


bool _BaslerUSBCamera::initialize(const std::string id)
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
				if (it->GetSerialNumber().c_str() == id)
				{
					break;
				}
			}
			if (it == lstDevices.end())
			{
				throw std::runtime_error("Camera not found in list of availabe devices");
			}
			device = new Pylon::CBaslerUsbInstantCamera(TlFactory.CreateDevice(*it));
			device->Open();
			device->PixelFormat.SetValue(Basler_UsbCameraParams::PixelFormat_RGB8);
			device->ExposureAuto.SetValue(Basler_UsbCameraParams::ExposureAuto_Off);
			//device->RegisterConfiguration(new Pylon::CSoftwareTriggerConfiguration, Pylon::RegistrationMode_ReplaceAll, Pylon::Cleanup_Delete);
			exposureStep = device->ExposureTime.GetMin() / 1000.0;
			device->ExposureAuto.SetValue(Basler_UsbCameraParams::ExposureAuto_Continuous);
			//device->StartGrabbing(Pylon::GrabStrategy_LatestImageOnly);
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

void _BaslerUSBCamera::detach(void)
{
	if (device != nullptr)
	{
		try
		{
			if (device->IsOpen())
			{
				//device->StopGrabbing();
				device->Close();
			}
			delete device;
		}
		catch (GenericException& e)
		{
			throw std::exception(e.GetDescription());
		}
	}
}

cv::Mat _BaslerUSBCamera::getFrame(void)
{
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
			//device->WaitForFrameTriggerReady(10000);
			//device->ExecuteSoftwareTrigger();
			device->GrabOne(10000, grabResult);
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
		uint8_t* buffer = static_cast<uint8_t*>(grabResult->GetBuffer());
		cv::Mat cv_image(height, width, CV_8UC3, buffer, cv::Mat::AUTO_STEP);
		cvtColor(cv_image, cv_image, cv::COLOR_RGB2BGR);

		return cv_image.clone();
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

bool _BaslerUSBCamera::setExposureMode(ExposureModes mode)
{
	_GenericCamera::setExposureMode(mode);
	if (device != nullptr)
	{
		try
		{
			if (device->IsOpen() && !device->IsCameraDeviceRemoved())
			{
				if (mode == AUTO)
				{
					device->ExposureAuto.SetValue(Basler_UsbCameraParams::ExposureAuto_Continuous);
					return true;
				}
				if ((mode == MANUAL) || (mode == LASER))
				{
					device->ExposureAuto.SetValue(Basler_UsbCameraParams::ExposureAuto_Off);
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

bool _BaslerUSBCamera::setExposure(const double time)
{
	if (device != nullptr)
	{
		try
		{
			if (device->IsOpen() && !device->IsCameraDeviceRemoved())
			{
				if (device->ExposureAuto.GetValue() == Basler_UsbCameraParams::ExposureAuto_Off)
				{
					device->ExposureTime.SetValue(time * 1000, false);
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

double _BaslerUSBCamera::getExposure(void) const
{
	if (device != nullptr)
	{
		try
		{
			if (device->IsOpen() && !device->IsCameraDeviceRemoved())
			{
				return device->ExposureTime.GetValue() / 1000;
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

void _BaslerUSBCamera::loadFeatureFile(const std::string filename)
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