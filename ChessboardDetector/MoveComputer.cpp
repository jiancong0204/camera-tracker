#include "MoveComputer.h"
HANDLE MoveComputer::OpenPort(LPCSTR COM)
{
	DWORD dwError;
	HANDLE hSerial;
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
	return hSerial;
}

void MoveComputer::_sendToEncoder(std::string text, HANDLE hSerial) {
	
	std::string code = "";
	int ascii_value;
	for (char c : text)
	{
		ascii_value = (int)c;
		code = code.append(std::bitset<8>(ascii_value).to_string());
	}
	char* tmpBuffer = (char*)code.data();
	std::cout << tmpBuffer << std::endl;
	//DCB dcbSerialParams = { 0 };
	//dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
	//if (!GetCommState(hSerial, &dcbSerialParams)) {
	//	//error getting state
	//}
	//dcbSerialParams.BaudRate = 57600;
	//dcbSerialParams.ByteSize = 8;
	//dcbSerialParams.StopBits = ONESTOPBIT;
	//dcbSerialParams.Parity = NOPARITY;
	//if (!SetCommState(hSerial, &dcbSerialParams)) {
	//	//error setting serial port state
	//}
	//COMMTIMEOUTS timeouts = { 0 };
	//timeouts.ReadIntervalTimeout = 500;
	//timeouts.ReadTotalTimeoutConstant = 500;
	//timeouts.ReadTotalTimeoutMultiplier = 100;
	//timeouts.WriteTotalTimeoutConstant = 500;
	//timeouts.WriteTotalTimeoutMultiplier = 100;
	//if (!SetCommTimeouts(hSerial, &timeouts)) {
	//	//error occureed. Inform user
	//}
	DWORD dwBytesWrite, dwBytesToWrite;
	dwBytesToWrite = sizeof(tmpBuffer);
	dwBytesWrite = 0;
	WriteFile(hSerial, tmpBuffer, dwBytesToWrite, &dwBytesWrite, NULL);
}

void MoveComputer::initialization(HANDLE hSerial)
{
	//_sendToEncoder("1RS", hSerial);
	_sendToEncoder("1HT0", hSerial);
	_sendToEncoder("1OH50", hSerial);
	_sendToEncoder("1OT2", hSerial);
	_sendToEncoder("1OR", hSerial);
	//_sendToEncoder("2RS", hSerial);
}


void MoveComputer::rotateA(HANDLE hSerial)
{
	_sendToEncoder("1PR6", hSerial);
}