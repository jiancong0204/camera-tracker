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
	void initialization(std::string port, int address=1, int homeSearchType=0, float searchVelocity=50, float searchTimeOut=2.2);
	void relativeMove(std::string port, float displacement, int address=1);
	
private:
	HANDLE _openPort(std::string port);
	void _write(unsigned char* tmpBuffer, HANDLE hSerial);
	unsigned char _read(HANDLE hSerial, int NumBitToRead);
};