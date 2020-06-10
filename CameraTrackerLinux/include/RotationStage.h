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
	* @brief Function that inializes the camera tracker
	* @param address Controller address
	* @param homeSearchType Type of home search, search velocity
	* @param searchVelocity Velocity of home search
	* @param searchTimeOut Home search time-out
	*/
	void initialize(std::string USB, int address=1, int homeSearchType=0, float searchVelocity=50, float searchTimeOut=2.2);

	/** 
	* @brief Function that rotates the camera tracker for a certain angle
	* @param USB File name of the corresponding serial port
	* @param displacement Displacement of the intended rotation
	* @param address Controller address
	*/
	void relativeMove(std::string USB, float displacement, int address=1);
    
	/** 
	* @brief Function that rotates the camera tracker to a ceratain position
	* @param USB File name of the corresponding serial port
	* @param position Destination of the intended rotation
	* @param address Controller address
	*/
	void absoluteMove(std::string USB, float position, int address=1);

private:

    int serialPort; //< Number of the serial port

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