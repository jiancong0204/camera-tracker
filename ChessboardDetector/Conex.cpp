#include "Conex.h"

unsigned char* getAcceleration(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "AC?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);  // copy count bytes from the memory
	return tmpBuffer;
}

unsigned char* setAcceleration(int addressValue, float accelerationValue)
{
	std::string address = std::to_string(addressValue);
	std::string acceleration = std::to_string(accelerationValue);
	std::string codeToSend = address + "AC" + acceleration + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);  
	return tmpBuffer;
}

unsigned char* getBacklashCompensation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "BA?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setBacklashCompensation(int addressValue, float backlashValue)
{
	std::string address = std::to_string(addressValue);
	std::string backlash = std::to_string(backlashValue);
	std::string codeToSend = address + "BA" + backlash + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* getHysteresisCompensation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "BH?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setHysteresisCompensation(int addressValue, float hysteresisValue)
{
	std::string address = std::to_string(addressValue);
	std::string hysteresis = std::to_string(hysteresisValue);
	std::string codeToSend = address + "BH" + hysteresis + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* getDriverVoltage(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "DV?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setDriverVoltage(int addressValue, float driverVoltageValue)
{
	std::string address = std::to_string(addressValue);
	std::string driverVoltage = std::to_string(driverVoltageValue);
	std::string codeToSend = address + "DV" + driverVoltage + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* getLowPassFilterCutOffFrequency(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "FD?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setLowPassFilterCutOffFrequency(int addressValue, float cutOffValue)
{
	std::string address = std::to_string(addressValue);
	std::string cutOff = std::to_string(cutOffValue);
	std::string codeToSend = address + "FD" + cutOff + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* getFollowingErrorLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "FE?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setFollowingErrorLimit(int addressValue, float errorLimitValue)
{
	std::string address = std::to_string(addressValue);
    std::string errorLimit = std::to_string(errorLimitValue);
	std::string codeToSend = address + "FE" + errorLimit + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* getFrictionCompensation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "FF?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setFrictionCompensation(int addressValue, float frictionCompensationValue)
{
	std::string address = std::to_string(addressValue);
	std::string frictionCompensation = std::to_string(frictionCompensationValue);
	std::string codeToSend = address + "FF" + frictionCompensation + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* getHomeSearchType(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "HT?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setHomeSearchType(int addressValue, int homeTypeValue)
{
	/*Home Type nn:
	  0: use MZ switch and encoder Index.
	  1: use current position as HOME.
	  2: use MZ switch only.
	  3: use EoR- switch and encoder Index.
	  4: use EoR- switch only.*/
	std::string address = std::to_string(addressValue);
	std::string homeType = std::to_string(homeTypeValue);
	std::string codeToSend = address + "HT" + homeType + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);  
	return tmpBuffer;
}

unsigned char* getStageIdentifier(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "ID?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setStageIdentifier(int addressValue, float modelNumberValue)
{
	std::string address = std::to_string(addressValue);
	std::string modelNumber = std::to_string(modelNumberValue);
	std::string codeToSend = address + "ID" + modelNumber + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* getJerkTime(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "JR?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setJerkTime(int addressValue, float jerkTimeValue)
{
	std::string address = std::to_string(addressValue);
	std::string jerkTime = std::to_string(jerkTimeValue);
	std::string codeToSend = address + "JR" + jerkTime + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* getDerivativeGain(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "KD?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setDerivativeGain(int addressValue, float derivativeGainValue)
{
	std::string address = std::to_string(addressValue);
	std::string derivativeGain = std::to_string(derivativeGainValue);
	std::string codeToSend = address + "KD" + derivativeGain + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* getIntegralGain(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "KI?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setIntegralGain(int addressValue, float integralGainValue)
{
	std::string address = std::to_string(addressValue);
	std::string integralGain = std::to_string(integralGainValue);
	std::string codeToSend = address + "KI" + integralGain + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* getProportionalGain(int addressValue)
{
    std::string address = std::to_string(addressValue);
	std::string codeToSend = address + "KP?" + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}

unsigned char* setProportionalGain(int addressValue, float proportionalGainValue)
{
    std::string address = std::to_string(addressValue);
	std::string proportionalGain = std::to_string(proportionalGainValue);
	std::string codeToSend = address + "KP" + proportionalGain + "\r\n";
	int len = codeToSend.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, codeToSend.data(), len);
	return tmpBuffer;
}