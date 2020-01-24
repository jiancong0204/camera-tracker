#include "MoveComputer.h"

HANDLE MoveComputer::_openPort(LPCSTR COM)
{
	DWORD dwError;
	HANDLE hSerial;
	DCB config = {0}; // DCB: device control block
	config.DCBlength = sizeof(config);
	COMMTIMEOUTS timeout = { 0 };
	hSerial = CreateFile(COM,
		GENERIC_READ | GENERIC_WRITE,
		0,
		0,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		0);
	if (hSerial == INVALID_HANDLE_VALUE) {
		dwError = GetLastError();
		std::cout << dwError << std::endl;
		//some other error occurred. Inform user.
	}
	else std::cout << "succeeded" << std::endl;

	timeout.ReadIntervalTimeout = 50;
	timeout.ReadTotalTimeoutConstant = 50;
	timeout.ReadTotalTimeoutMultiplier = 50;
	timeout.WriteTotalTimeoutConstant = 50;
	timeout.WriteTotalTimeoutMultiplier = 10;
	SetCommTimeouts(hSerial, &timeout);
	// Prepare serial communication format
	GetCommState(hSerial, &config);
	config.fBinary = true;
	config.fParity = false;
	config.BaudRate = 921600;
	config.ByteSize = 8;
	config.Parity = NOPARITY;
	config.StopBits = ONESTOPBIT;
	config.fOutX = true;
	config.fInX = true;
	config.fOutxCtsFlow = false;
	config.fOutxDsrFlow = false;
	config.fDsrSensitivity = false;
	config.fRtsControl = RTS_CONTROL_DISABLE;
	config.fDtrControl = DTR_CONTROL_DISABLE;
	SetCommState(hSerial, &config);
	// Set the port state
	/*if (SetCommState(hSerial, &config) == 0) {
		CloseHandle(hSerial);
	}*/
	return hSerial;
}

void MoveComputer::_write(unsigned char* tmpBuffer, HANDLE hSerial) {
	DWORD dwBytesWrite, dwBytesToWrite;
	dwBytesToWrite = sizeof(tmpBuffer);
	dwBytesWrite = 0;
	WriteFile(hSerial, tmpBuffer, dwBytesToWrite, &dwBytesWrite, NULL);
}

unsigned char MoveComputer::_read(HANDLE hSerial, int NumBytesToRead) {
	unsigned char* tmpBuffer = new unsigned char[NumBytesToRead + 1];
	DWORD dwBytesRead = 0;
	ReadFile(hSerial, tmpBuffer, NumBytesToRead, &dwBytesRead, NULL);
	// std::cout << tmpBuffer << std::endl;
	return* tmpBuffer;
}

void MoveComputer::initialization(LPCSTR COM, int address, int homeSearchType, float searchVelocity, float searchTimeOut)
{
	//_write("RS##\r\n", hSerial);
	HANDLE hSerial = _openPort(COM);
	unsigned char* bufferSearchType = setHomeSearchType(address, homeSearchType);
	unsigned char* bufferSearchVelocity = setHomeSearchVelocity(address, searchVelocity);
	unsigned char* bufferSearchTimeOut = setHomeSearchTimeOut(address, searchTimeOut);
	unsigned char* bufferHomeSearch = executeHomeSearch(address);
	_write(bufferSearchType, hSerial);
	_write(bufferSearchVelocity, hSerial);
	_write(bufferSearchTimeOut, hSerial);
	_write(bufferHomeSearch, hSerial);
	CloseHandle(hSerial);
}


void MoveComputer::relativeMove(LPCSTR COM, float displacement, int address)
{
	HANDLE hSerial = _openPort(COM);
	unsigned char* bufferMove = moveRelative(address, displacement);
	_write(bufferMove, hSerial);
	CloseHandle(hSerial);
}