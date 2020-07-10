#include "RotationStage.h"

void RotationStage::setElevationPort(std::string portName)
{
    this->elevationPort = portName;
}

void RotationStage::setAzimuthPort(std::string portName)
{
    this->azimuthPort = portName;
}

void RotationStage::_openPort(std::string USB)
{
    std::string tmpString = "/dev/tty" + USB;
	const char* tmpChar = tmpString.c_str();
	this->serialPort = open(tmpChar, O_RDWR);
    // Check for errors
    if (this->serialPort < 0)
    {
        printf("Error %i from open: %s\n", errno, strerror(errno));
    }
    
    // Create new termios struc
    struct termios tty;
    memset(&tty, 0, sizeof tty);

    // Read in existing settings, and handle any error
    if (tcgetattr(this->serialPort, &tty) != 0)
    {
        printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
    }

    tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity
    tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication
    tty.c_cflag |= CS8; // 8 bits per byte
    tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)
    tty.c_lflag &= ~ICANON;

    // Set in/out baud rate to be 921600
    cfsetispeed(&tty, B921600);
    cfsetospeed(&tty, B921600);

    // Save tty settings, also checking for error
    if (tcsetattr(this->serialPort, TCSANOW, &tty) != 0)
    {
        printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
    }
}

void RotationStage::_write(std::string USB, std::string code)
{
	_openPort(USB);
    unsigned char tmpBuffer[code.length()];
    std::copy(code.begin(), code.end(), tmpBuffer);
    write(this->serialPort, tmpBuffer, sizeof(tmpBuffer));
	close(this->serialPort);
}

void RotationStage::initializeElevation(int address, int homeSearchType, float searchVelocity, float searchTimeOut)
{
    std::string code;

    code = conex::resetController(1);
    _write(this->elevationPort, code);
    sleep(1);

	code = conex::setHomeSearchType(1, 0);
    _write(this->elevationPort, code);

	code = conex::setHomeSearchVelocity(1, 50);
    _write(this->elevationPort, code);

	code = conex::setHomeSearchTimeOut(1, 2.200);
    _write(this->elevationPort, code);

	code = conex::executeHomeSearch(1);
    _write(this->elevationPort, code);
}

void RotationStage::initializeAzimuth(int address, int homeSearchType, float searchVelocity, float searchTimeOut)
{
    std::string code;

    code = conex::resetController(1);
    _write(this->azimuthPort, code);
    sleep(1);

	code = conex::setHomeSearchType(1, 0);
    _write(this->azimuthPort, code);

	code = conex::setHomeSearchVelocity(1, 50);
    _write(this->azimuthPort, code);

	code = conex::setHomeSearchTimeOut(1, 2.200);
    _write(this->azimuthPort, code);

	code = conex::executeHomeSearch(1);
    _write(this->azimuthPort, code);
}


void RotationStage::relativeMoveElevation(float displacement, int address)
{
    std::string code;
	code = conex::moveRelative(address, displacement);
    _write(this->elevationPort, code);
}

void RotationStage::relativeMoveAzimuth(float displacement, int address)
{
    std::string code;
	code = conex::moveRelative(address, displacement);
    _write(this->azimuthPort, code);
}


void RotationStage::absoluteMoveElevation(float position, int address)
{
    std::string code;
	code = conex::moveAbsolute(address, position);
    _write(this->elevationPort, code);
}

void RotationStage::absoluteMoveAzimuth(float position, int address)
{
    std::string code;
	code = conex::moveAbsolute(address, position);
    _write(this->azimuthPort, code);
}