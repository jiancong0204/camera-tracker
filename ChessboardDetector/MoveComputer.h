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
	void initialization(LPCSTR COM, int address=1, int homeSearchType=0, float searchVelocity=50, float searchTimeOut=2.2);
	void relativeMove(LPCSTR COM, float displacement, int address=1);
	
private:
	HANDLE _openPort(LPCSTR COM);
	void _write(unsigned char* tmpBuffer, HANDLE hSerial);
	unsigned char _read(HANDLE hSerial, int NumBitToRead);
};