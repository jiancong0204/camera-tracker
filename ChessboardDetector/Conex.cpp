#include "Conex.h"

unsigned char* getAcceleration(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "AC?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);  // copy count bytes from the memory
	return tmpBuffer;
}

unsigned char* setAcceleration(int addressValue, float accelerationValue)
{
	std::string address = std::to_string(addressValue);
	std::string acceleration = std::to_string(accelerationValue);
	std::string code = address + "AC" + acceleration + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);  
	return tmpBuffer;
}

unsigned char* getBacklashCompensation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "BA?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setBacklashCompensation(int addressValue, float backlashValue)
{
	std::string address = std::to_string(addressValue);
	std::string backlash = std::to_string(backlashValue);
	std::string code = address + "BA" + backlash + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getHysteresisCompensation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "BH?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setHysteresisCompensation(int addressValue, float hysteresisValue)
{
	std::string address = std::to_string(addressValue);
	std::string hysteresis = std::to_string(hysteresisValue);
	std::string code = address + "BH" + hysteresis + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getDriverVoltage(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "DV?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setDriverVoltage(int addressValue, float driverVoltageValue)
{
	std::string address = std::to_string(addressValue);
	std::string driverVoltage = std::to_string(driverVoltageValue);
	std::string code = address + "DV" + driverVoltage + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getLowPassFilterCutOffFrequency(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "FD?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setLowPassFilterCutOffFrequency(int addressValue, float cutOffValue)
{
	std::string address = std::to_string(addressValue);
	std::string cutOff = std::to_string(cutOffValue);
	std::string code = address + "FD" + cutOff + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getFollowingErrorLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "FE?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setFollowingErrorLimit(int addressValue, float errorLimitValue)
{
	std::string address = std::to_string(addressValue);
    std::string errorLimit = std::to_string(errorLimitValue);
	std::string code = address + "FE" + errorLimit + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getFrictionCompensation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "FF?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setFrictionCompensation(int addressValue, float frictionCompensationValue)
{
	std::string address = std::to_string(addressValue);
	std::string frictionCompensation = std::to_string(frictionCompensationValue);
	std::string code = address + "FF" + frictionCompensation + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getHomeSearchType(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "HT?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
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
	std::string code = address + "HT" + homeType + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);  
	return tmpBuffer;
}

unsigned char* getStageIdentifier(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "ID?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setStageIdentifier(int addressValue, float modelNumberValue)
{
	std::string address = std::to_string(addressValue);
	std::string modelNumber = std::to_string(modelNumberValue);
	std::string code = address + "ID" + modelNumber + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getJerkTime(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "JR?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setJerkTime(int addressValue, float jerkTimeValue)
{
	std::string address = std::to_string(addressValue);
	std::string jerkTime = std::to_string(jerkTimeValue);
	std::string code = address + "JR" + jerkTime + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getDerivativeGain(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "KD?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setDerivativeGain(int addressValue, float derivativeGainValue)
{
	std::string address = std::to_string(addressValue);
	std::string derivativeGain = std::to_string(derivativeGainValue);
	std::string code = address + "KD" + derivativeGain + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getIntegralGain(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "KI?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setIntegralGain(int addressValue, float integralGainValue)
{
	std::string address = std::to_string(addressValue);
	std::string integralGain = std::to_string(integralGainValue);
	std::string code = address + "KI" + integralGain + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getProportionalGain(int addressValue)
{
    std::string address = std::to_string(addressValue);
	std::string code = address + "KP?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setProportionalGain(int addressValue, float proportionalGainValue)
{
    std::string address = std::to_string(addressValue);
	std::string proportionalGain = std::to_string(proportionalGainValue);
	std::string code = address + "KP" + proportionalGain + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getVelocityFeedForward(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "KV?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setVelocityFeedForward(int addressValue, float velocityFeedForwardValue)
{
	std::string address = std::to_string(addressValue);
	std::string velocityFeedForward = std::to_string(velocityFeedForwardValue);
	std::string code = address + "KV" + velocityFeedForward + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getDisableState(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "MM?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* disableState(int addressValue, bool commandValue)
{
	/*0: changes state from READY to DISABLE.
	  1: changes state from DISABLE to READY.*/
	std::string address = std::to_string(addressValue);
	std::string command = std::to_string(commandValue);
	std::string code = address + "MM" + command + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getHomeSearchVelocity(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "OH?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setHomeSearchVelocity(int addressValue, float velocityValue)
{
	std::string address = std::to_string(addressValue);
	std::string velocity = std::to_string(velocityValue);
	std::string code = address + "OH" + velocity + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* executeHomeSearch(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "OR" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getHomeSearchTimeOut(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "OT?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setHomeSearchTimeOut(int addressValue, float timeOutValue)
{
	std::string address = std::to_string(addressValue);
	std::string timeOut = std::to_string(timeOutValue);
	std::string code = address + "OT" + timeOut + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* moveAbsolute(int addressValue, float targetPositionValue)
{
	std::string address = std::to_string(addressValue);
	std::string targetPosition = std::to_string(targetPositionValue);
	std::string code = address + "PA" + targetPosition;
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* moveRelative(int addressValue, float displacementValue)
{
	std::string address = std::to_string(addressValue);
	std::string displacement = std::to_string(displacementValue);
	std::string code = address + "PR" + displacement;
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getMotionTimeForRelativeMoce(int addressValue, float displacementValue)
{
	std::string address = std::to_string(addressValue);
	std::string displacement = std::to_string(displacementValue);
	std::string code = address + "PT" + displacement;
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* configurationState(int addressValue, bool commandValue)
{
	/*0: changes state from NOT REFERENCE to CONFIGURATION.
      1: changes state from CONFIGURATION to NOT REFERENCE.*/
	std::string address = std::to_string(addressValue);
	std::string command = std::to_string(commandValue);
	std::string code = address + "PW" + command + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getPeakCurrentLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "QIL?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setPeakCurrentLimit(int addressValue, float limitValue)
{
	std::string address = std::to_string(addressValue);
	std::string limit = std::to_string(limitValue);
	std::string code = address + "QIL" + limit + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getRMSCurrentLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "QIR?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setRMSCurrentLimit(int addressValue, float limitValue)
{
	std::string address = std::to_string(addressValue);
	std::string limit = std::to_string(limitValue);
	std::string code = address + "QIR" + limit + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getRMSAveragingTime(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "QIT?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setRMSAveragingTime(int addressValue, float timeValue)
{
	std::string address = std::to_string(addressValue);
	std::string time = std::to_string(timeValue);
	std::string code = address + "QIT" + time + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* resetController(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "RS" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* resetControllerAddress() 
{
	std::string code = "RS##\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getControlLoopState(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "SC?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setControlLoopState(int addressValue, bool stateValue)
{
	/* 1: CLOSED loop control.
	   0: OPEN loop control.*/
	std::string address = std::to_string(addressValue);
	std::string state = std::to_string(stateValue);
	std::string code = address + "SC" + state + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* configureSimultaneousStartedMove(int addressValue, float targetPositionValue)
{
	std::string address = std::to_string(addressValue);
	std::string targetPosition = std::to_string(targetPositionValue);
	std::string code = address + "SE" + targetPosition + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getSimultaneousConfiguration(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "SE?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* executeSimultaneousStartedMove()
{
	std::string code = "SE\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getNegativeSoftwareLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "SL?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setNegativeSoftwareLimit(int addressValue, float limitValue)
{
	std::string address = std::to_string(addressValue);
	std::string limit = std::to_string(limitValue);
	std::string code = address + "SL" + limit + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getPositiveSoftwareLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "SR?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setPositiveSoftwareLimit(int addressValue, float limitValue)
{
	std::string address = std::to_string(addressValue);
	std::string limit = std::to_string(limitValue);
	std::string code = address + "SR" + limit + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* stopMotion(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "ST\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getEncoderIncrementValue(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "SU?\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setEncoderIncrementValue(int addressValue, float incrementValue)
{
	std::string address = std::to_string(addressValue);
	std::string increment = std::to_string(incrementValue);
	std::string code = address + "SU" + increment + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getCommandErrorString(int addressValue, char error)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "TB" + error + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getLastCommandError(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "TE\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getSetPointPosition(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "TH\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* TrackingMode(int addressValue, bool modeValue)
{
	/*1: ENTER
	  0: LEAVE*/
	std::string address = std::to_string(addressValue);
	std::string mode = std::to_string(modeValue);
	std::string code = address + "TK" + mode + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getCurrentPostion(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "TP" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getPostionerErrorAndControllerState(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "TS" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getVelocity(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "VA?" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* setVelocity(int addressValue, float velocityValue)
{
	std::string address = std::to_string(addressValue);
	std::string velocity = std::to_string(velocityValue);
	std::string code = address + "VA" + velocity + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getControllerRevisionInformation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "VE" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}

unsigned char* getAllConfigurationParameters(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "ZT" + "\r\n";
	int len = code.length();
	unsigned char* tmpBuffer = new unsigned char[len];
	memcpy(tmpBuffer, code.data(), len);
	return tmpBuffer;
}