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
	void initialization(LPCWSTR COM, int address=1, int homeSearchType=0, float searchVelocity=50, float searchTimeOut=2.2);
	void relativeMove(LPCWSTR COM, float displacement, int address=1);
	void absoluteMove(LPCWSTR COM, float position, int address = 1);
private:
	HANDLE _openPort(LPCWSTR COM);
	void _write(unsigned char* tmpBuffer, LPCWSTR COM);
	unsigned char _read(HANDLE hSerial, int NumBitToRead);
};