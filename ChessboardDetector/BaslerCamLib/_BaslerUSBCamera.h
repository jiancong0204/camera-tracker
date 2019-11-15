#pragma once
/** @file BaslerUSBCamera.h
* @brief Header file for the Basler USB Camera class.
*
* File that contains the header of the Basler USB Camera class. It relies on Pylon/Basler inlcudes but not on Qt.
* Except minor changes, the file BaslerGigECamera.h, developed by Benjamin Montavon, is used.
* @author Matthias Bodenbenner
* @date 26.04.2017
*/

#include "_GenericCamera.h"
#include <pylon/PylonIncludes.h>
#include <pylon/usb/BaslerUsbInstantCamera.h>

class _BaslerUSBCamera : public _GenericCamera
{
private:
	Pylon::CBaslerUsbInstantCamera* device; ///< actual camera pointer as Basler device

public:
	/** constructor, takes no arguments */
	_BaslerUSBCamera();

	/** destructor */
	~_BaslerUSBCamera();

	/** static function that lists all available cameras on the network
	* @return standard vector with device names as string
	*/
	static std::vector<std::string> listAvailableDevices(void);

	/** initialize the choosen device, passing the name from the list as string
	* @param [in] id name of the device to start
	* @return success of initialization progress, i.e. if the camera could be activated
	*/
	bool initialize(const std::string id) override;

	/** close the attached pylon device */
	void detach(void) override;

	/** get a single frame from the camera and convert it to an openCV matrix
	* @return acquired frame in openCV matrix format.
	*/
	cv::Mat getFrame(void) override;

	// void voidFrame(void) override;

	/** set the exposure mode of the camera, choosing between automatic, manual and laser
	* @param [in] mode desired exposure setting
	* @return true if exposure mode could be set, false else
	*/
	bool setExposureMode(ExposureModes mode) override;

	/** manually set the exposure time of the camera, only works if the mode is not automatic
	* @param [in] time exposure time in milliseconds
	* @return true if exposure time vcould be written to the device, false else
	*/
	bool setExposure(const double time) override;

	/** get the current exposure time
	* @return current exposure time in milliseconds
	*/
	double getExposure(void) const override;

	/** load a basler specific feature file, containing settings stored with the Pylon Viewer application, to the device
	* @param [in] filename filename of the feature file
	*/
	void loadFeatureFile(const std::string filename) override;
};
