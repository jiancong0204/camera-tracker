/** @file GenericCamera.h
* @brief Header of the camera base class.
*
* Header file defining the abstract base class for any kind of camera devices
* @author Benjamin Montavon
* @date 27.11.2015
*/

#pragma once
#include <exception>
#include <string>
#include <opencv2\core.hpp>
#include "constants.h"

/** @class GenericCamera
* @brief abstract camera base class.
*
* abstract camera base class where of all camera types used have to be derived, providing a unified interface
*/
class _GenericCamera
{
public:
	/** @class disconnected_exception
	* @brief Exception if device is is disconnected
	* Exception specificly for device disconnection, inherits from std exeception
	*/
	class disconnected_exception : public std::exception
	{
	public:
		/** constructor, calling the std exception construction
		* @param [in] description descriptive error text
		*/
		disconnected_exception(const char* description) : std::exception(description)
		{
		};
	};

	/** constructor, takes no arguments */
	_GenericCamera();

	/** virtual destructor */
	virtual ~_GenericCamera();

	/** initialize the choosen device, passing the name from the list as string, purely virtual
	* @param [in] id name of the device to start
	* @return success of initialization progress, i.e. if the camera could be activated
	*/
	virtual bool initialize(const std::string id) = 0;

	/** close the attached device, purely virtual */
	virtual void detach(void) = 0;

	/** get a single frame from the camera and convert it to an openCV matrix, purely virtual
	* @return acquired frame in openCV matrix format.
	*/
	virtual cv::Mat getFrame(void) = 0;

	/** set the exposure mode of the camera, choosing between automatic, manual and laser, purely virtual
	* @param [in] mode desired exposure setting
	* @return true if exposure mode could be set, false else
	*/
	virtual bool setExposureMode(ExposureModes mode) = 0;

	/** manually set the exposure time of the camera, only works if the mode is not automatic, purely virtual
	* @param [in] time exposure time in milliseconds
	* @return true if exposure time vcould be written to the device, false else
	*/
	virtual bool setExposure(const double time) = 0;

	/** get the current exposure time
	* @return current exposure time in milliseconds
	*/
	virtual double getExposure(void) const = 0;

	/** get the current exposure mode set
	* @return current exposure mode
	*/
	ExposureModes getExposureMode(void) const { return exposureMode; }

	/** get the current exposure state
	* @return current exposure state
	*/
	ExposureStates getExposureState(void) const { return exposureState; }

	/** set the exposure time more suited for a laser beam by checking whether any area is overexposed. the function should be called iteratively.
	* @return true if image is properly exposed, false else
	*/
	virtual bool laserExposure(cv::Mat& image);

	/** load a file containing predefined settings, purely virtual
	* @param [in] filename name of the file
	*/
	virtual void loadFeatureFile(const std::string filename) = 0;

	/** get a string as a human readable identifier, i.e. a name
	* @return camera name
	*/
	const std::string getName(void) const { return name; }

	/** lock a camera permamently to a thread
	* @param [in] timeout time in milliseconds for tryLock() to wait
	* @return output of tryLock()
	*/
	// inline bool lockToThread(int timeout) { return mutex->tryLock(timeout); }

	/** unlocks the camera from a thread */
	// inline void unlockFromThread(void) { mutex->unlock(); }

	/** set a new camera Pitch
	* @param [in] newPitch new pitch
	*/
	void setPitch(double newPitch) { pitch = newPitch; }

	/** get function for the camera pitch value
	* @return camera pitch value
	*/
	const double getPitch(void) const { return pitch; }

protected:
	std::string name; ///< device identifier
	double exposureStep; ///< smallest step between two exposure times
	ExposureModes exposureMode; ///< current exposure mode set
	// QMutex* mutex;								///< member Mutex for thread safety
	double pitch; ///< ratio of millimeter per pixel
	ExposureStates exposureState; ///< current state of the exposure
};
#pragma once
