#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <Windows.h>


class MoveComputer
{
public:
	MoveComputer() {};
	~MoveComputer() {};
	void initialization(HANDLE hSerial);
	void rotateA(HANDLE hSerial);
	HANDLE OpenPort(LPCSTR COM);
private:
	void _sendToEncoder(std::string text, HANDLE hSerial);
};