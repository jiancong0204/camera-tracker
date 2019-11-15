#pragma once
#pragma once
/** @file BaslerGigECamera.h
* @brief Header file for the Basler GigE Camera class.
*
* File that contains the header of the Basler GigE Camera class. It relies on Pylon/Basler inlcudes but not on Qt.
* @author Benjamin Montavon
* @date 27.11.2015
*/

#pragma once
#include <opencv2\core.hpp>
#include "_BaslerGigECamera.h"
#include "TimedFrame.h"

/** @class BaslerGigECamera
* @brief Implementation of Basler GigE Cameras.
*
* Class that wraps the Basler Pylon controls for GigE Camera to the generic camera controls used in the software and implements the image acquisistion
*/
class BaslerGigECamera
{
private:
	_BaslerGigECamera* device; ///< actual camera pointer as Basler device

public:
	/** constructor, takes no arguments */
	BaslerGigECamera();

	/** destructor */
	~BaslerGigECamera();

	/** static function that lists all available cameras on the network
	* @return standard vector with device names as string
	*/
	static std::vector<std::string> listAvailableDevices(void) throw(std::exception);

	/** initialize the choosen device, passing the name from the list as string
	* @param [in] id name of the device to start
	* @return success of initialization progress, i.e. if the camera could be activated
	*/
	bool initialize(const std::string id) throw(std::exception);

	/** reset the choosen device, i.e. first detach and then initialize it
	* @return success of initialization progress, i.e. if the camera could be activated
	*/
	bool reset() throw(std::exception);

	/** close the attached pylon device */
	void detach(void) throw(std::exception);

	/** get a single frame from the camera and convert it to an openCV matrix
	* @return acquired frame in openCV matrix format.
	*/
	cv::Mat getFrame(void) throw(std::exception);

	/** set the exposure mode of the camera, choosing between automatic, manual and laser
	* @param [in] mode desired exposure setting
	* @return true if exposure mode could be set, false else
	*/
	bool setExposureMode(std::string mode) throw(std::exception);

	/** manually set the exposure time of the camera, only works if the mode is not automatic
	* @param [in] time exposure time in milliseconds
	* @return true if exposure time vcould be written to the device, false else
	*/
	bool setExposure(const double time) throw(std::exception);

	/** get the current exposure time
	* @return current exposure time in milliseconds
	*/
	double getExposure(void) const throw(std::exception);

	/** load a basler specific feature file, containing settings stored with the Pylon Viewer application, to the device
	* @param [in] filename filename of the feature file
	*/
	void loadFeatureFile(const std::string filename) throw(std::exception);
};
