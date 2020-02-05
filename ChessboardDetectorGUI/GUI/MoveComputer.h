#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <Windows.h>
#include "Conex.h"


class MoveComputer
{
public:

	MoveComputer() {};
	~MoveComputer() {};

	/** Function that inializes the camera tracker. 
	* Arguments: controller address, type of home search, search velocity, search time out.
	*/
	void initialization(LPCWSTR COM, int address=1, int homeSearchType=0, float searchVelocity=50, float searchTimeOut=2.2);

	/** Function that rotates the camera tracker for a certain angle. */
	void relativeMove(LPCWSTR COM, float displacement, int address=1);

	/** Function that rotates the camera tracker to a ceratain position. */
	void absoluteMove(LPCWSTR COM, float position, int address=1);

private:

	/** Function used to open the corresponding port. */
	HANDLE _openPort(LPCWSTR COM);

	/** Function used to write through a open serial port. */
	void _write(unsigned char* tmpBuffer, LPCWSTR COM);

	unsigned char _read(HANDLE hSerial, int NumBitToRead);
};