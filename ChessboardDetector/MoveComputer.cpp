#include "MoveComputer.h"

HANDLE MoveComputer::openPort(LPCSTR COM)
{
	DWORD dwError;
	HANDLE hSerial;
	DCB config = { 0 };
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

void MoveComputer::_sendToEncoder(std::string text, HANDLE hSerial) {
	int len = text.length();
	unsigned char *tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, text.data(), text.length());  // copy count bytes (convert string to )

	DWORD dwBytesWrite, dwBytesToWrite;
	dwBytesToWrite = sizeof(tmpBuffer);
	dwBytesWrite = 0;
	WriteFile(hSerial, tmpBuffer, dwBytesToWrite, &dwBytesWrite, NULL);
}

void MoveComputer::initialization(HANDLE hSerial)
{
	//_sendToEncoder("RS##\r\n", hSerial);
	_sendToEncoder("1HT0\r\n", hSerial);
	_sendToEncoder("1OH50\r\n", hSerial);
	_sendToEncoder("1OT2.2\r\n", hSerial);
	_sendToEncoder("1OR\r\n", hSerial);
}


void MoveComputer::rotateA(HANDLE hSerial)
{
	_sendToEncoder("1PR6\r\n", hSerial);
}