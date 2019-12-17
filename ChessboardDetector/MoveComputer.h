#pragma once
#include <atlbase.h>
#include <atlconv.h>
#include <string>
#include <cstring>
#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>  
#include <bitset>

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