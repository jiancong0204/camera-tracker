/**
* @file RotationStage.h
* 
* @brief This file contains the declaration of the RotationStage class.
* 
* @author Jiancong Zheng 
* @date 2020-06-10
* 
*/

#pragma once
#include <string>
#include <iostream>
#include "Conex.h"

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

/** 
* @class RotationStage 
* @brief Control of the encoder
*
* This class wraps the driver controlling the encoder to rotate the camera
**/
class RotationStage
{
public:
    /**
	* @brief Construct the RotationStage object
	*/
	RotationStage() {};

	/**
	* @brief Deconstructor
	*/
	~RotationStage() {};
    
	/**
    * @brief Set port for elevation
	* @param portName Name of the port for elevation
	*/
	void setElevationPort(std::string portName="USB0");

    /**
	* @brief set port for azimuth
	* @param portName Name of the port for azimuth
	*/
	void setAzimuthPort(std::string portName="USB1");

	/** 
	* @brief Function that inializes the elevation angle
	* @param address Controller address
	* @param homeSearchType Type of home search, search velocity
	* @param searchVelocity Velocity of home search
	* @param searchTimeOut Home search time-out
	*/
	void initializeElevation(int address=1, int homeSearchType=0, float searchVelocity=50, float searchTimeOut=2.2);

	/** 
	* @brief Function that inializes the azimuth angle
	* @param address Controller address
	* @param homeSearchType Type of home search, search velocity
	* @param searchVelocity Velocity of home search
	* @param searchTimeOut Home search time-out
	*/
	void initializeAzimuth(int address=1, int homeSearchType=0, float searchVelocity=50, float searchTimeOut=2.2);

	/** 
	* @brief Function that rotates the camera tracker for a certain elevation angle
	* @param displacement Displacement of the intended rotation
	* @param address Controller address
	*/
	void relativeMoveElevation(float displacement, int address=1);
    
	/** 
	* @brief Function that rotates the camera tracker for a certain azimuth angle
	* @param displacement Displacement of the intended rotation
	* @param address Controller address
	*/
	void relativeMoveAzimuth(float displacement, int address=1);

	/** 
	* @brief Function that rotates the camera tracker to a ceratain elevation position
	* @param position Destination of the intended rotation
	* @param address Controller address
	*/
	void absoluteMoveElevation(float position, int address=1);

	/** 
	* @brief Function that rotates the camera tracker to a ceratain azimuth position
	* @param position Destination of the intended rotation
	* @param address Controller address
	*/
	void absoluteMoveAzimuth(float position, int address=1);

private:

    int             serialPort;        //< Number of the serial port
	std::string     elevationPort;     //< Port for elevation
	std::string     azimuthPort;       //< port for azimuth

	/** 
	* @brief Function used to open the corresponding port
	* @param USB File name of the corresponding serial port
	*/
	void _openPort(std::string USB);

	/**
	* @brief Function used to write through a open serial port
	* @param USB File name of the corresponding serial port
	* @param code Code to send
	*/
	void _write(std::string USB, std::string code);

};