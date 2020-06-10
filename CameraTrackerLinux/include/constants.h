/** @file constants.h
* @brief header for constant definitions.
*
* Header file that contains useful constant definitions together in one place, avoiding value hardcoding
* @author Benjamin Montavon
* @date 27.11.2015
*/

//#include "LogErrorHandler.h"

#pragma once

#include <opencv2/imgproc/imgproc.hpp>

#define PI 3.14159265359																			///< pi, to avoid potential hassle with M_PI

#define CV_MONO_TYPE CV_16UC1																		///< OpenCV type that will be used for monochroeme pictures, 16bit
#define CV_COLOR_TYPE CV_16UC3																		///< OpenCV colour type for displaying
#define CV_CPP_TYPE unsigned short																	///< internal data type that the openCV matrices use
#define CV_8_TYPE CV_8UC1																			///< openCV data type for 8 bit matrices
#define CV_CPP_8_TYPE unsigned char																	///< internal data type for 8 bit matrices
#define CV_MAX_VALUE 65535																			///< Maximum int value of 16 bit
#define CV_UPSCALE_12_16 16																			///< upscaling factor for 12 bit data
#define CV_DOWNSCALE_12_8 1/double(16)																///< downscaling factor for 12 bit data
#define CV_UPSCALE_8_16	256																			///< upscaling factor for 8 bit data
#define RWTH_BLUE_16 CV_RGB(0, 84*CV_UPSCALE_8_16, 159*CV_UPSCALE_8_16)								///< 16bit RWTH Blue corporate color definition
#define RWTH_RED_16 CV_RGB(204*CV_UPSCALE_8_16, 7*CV_UPSCALE_8_16, 30*CV_UPSCALE_8_16)				///< 16bit RWTH Red corporate color definition

//#define RWTH_ORANGE_QT QColor(246, 168, 0, 255)														///< RWTH corporate orange as Qt color
//#define RWTH_MAIGRUEN_QT QColor(189, 205, 0, 255)													///< RWTH corporate may green as Qt color

#define MUTEX_TIMEOUT 1000																			///< default timeout for mutex trylock in ms
#define IDS_TIMEOUT 10000																			///< response wait time for IDS3010 actions	in ms
#define IDS_DEFAULT_REFRESH 100																		///< default refresh rate for displacement data in ms
#define ECU_DEFAULT_REFRESH 10000																	///< default refresh rate for ECU data in ms
#define IDS_DEFAULT_AVERAGE 8																		///< default IDS average setting

#define BASLER_DEFAULT_PITCH 0.00167																///< default pitch value to set for Basler cameras
#define VIRTUAL_DEFAULT_PITCH 1.0																	///< default pitch value for virtual cameras
#define VIRTUAL_FPS 10																				///< theoretical frame rate of virtual cameras

#define BEEP_FREQUENCY 880																			///< frequency to use for beeps in Hz

#define RESULT_PRECISION 6																			///< default digit display if format
#define LASER_EXPOSE_ITERATIONS 50																	///< default limit before laser exposure is aborted

#define MEASURE_PERFORMANCE_BARRIER 500																///< security barrier between device measurements for low performance mode in ms

#define PE_DEFAULT	0x10101
#define PE_SINGLE	0x10101
#define PE_STEREO	0x10102

#define CD_DEFAULT  0x10202
#define CD_FEATURE	0x10201
#define CD_META		0x10202
#define CD_TEMPLATE	0x10203

#define TM_DEFAULT	0x20101
#define TM_CORR		0x20101
#define TM_COEF		0x20102
#define TM_MSQD		0x20103

#define MAX_IMAGE_AXIS 600			///< maximal length of the longer image axis
#define MAX_ANGLE 10				///< maximal allowed angle between the detected cable and the ideal position
#define MIN_DISTANCE 20

#define CANNY_MIN_THRESHOLD 50
#define CANNY_MAX_THRESHOLD 2 * CANNY_MIN_THRESHOLD

#define LEFT_CAM "22176689"
#define TOP_CAM "22176687"
#define RIGHT_CAM "22176686"

#define LEFT_CALIB_LOC "..\assets\calibration_images_labor\left_cam"
#define TOP_CALIB_LOC "..\assets\calibration_images_labor\top_cam"
#define RIGHT_CALIB_LOC "..\assets\calibration_images_labor\right_cam"

//-- DEBUG flags and output helper
#define DEBUG 2
#define DOUT(x) if (DEBUG > 0) {std::cout << x;}
#define DSHOW(x,y,z) if (DEBUG > 1) {utils::showImage(x, y, z);}

/** enumeration for identifiying different exposure types */
enum ExposureModes
{
	AUTO,
	MANUAL,
	LASER
};

/** enumeration for identifiying different exposure states */
enum ExposureStates
{
	BAD,
	GOOD
};

//extern LogErrorHandler* globalLogErrorHandler;														///< globally visible pointer to the error handler
