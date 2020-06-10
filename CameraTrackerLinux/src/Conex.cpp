#include "Conex.h"

std::string conex::getAcceleration(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "AC?" + "\r\n";
	return code;
}

std::string conex::setAcceleration(int addressValue, float accelerationValue)
{
	std::string address = std::to_string(addressValue);
	std::string acceleration = std::to_string(accelerationValue);
	std::string code = address + "AC" + acceleration + "\r\n";
	return code;
}

std::string conex::getBacklashCompensation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "BA?" + "\r\n";
	return code;
}

std::string conex::setBacklashCompensation(int addressValue, float backlashValue)
{
	std::string address = std::to_string(addressValue);
	std::string backlash = std::to_string(backlashValue);
	std::string code = address + "BA" + backlash + "\r\n";
	return code;
}

std::string conex::getHysteresisCompensation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "BH?" + "\r\n";
	return code;
}

std::string conex::setHysteresisCompensation(int addressValue, float hysteresisValue)
{
	std::string address = std::to_string(addressValue);
	std::string hysteresis = std::to_string(hysteresisValue);
	std::string code = address + "BH" + hysteresis + "\r\n";
	return code;
}

std::string conex::getDriverVoltage(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "DV?" + "\r\n";
	return code;
}

std::string conex::setDriverVoltage(int addressValue, float driverVoltageValue)
{
	std::string address = std::to_string(addressValue);
	std::string driverVoltage = std::to_string(driverVoltageValue);
	std::string code = address + "DV" + driverVoltage + "\r\n";
	return code;
}

std::string conex::getLowPassFilterCutOffFrequency(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "FD?" + "\r\n";
	return code;
}

std::string conex::setLowPassFilterCutOffFrequency(int addressValue, float cutOffValue)
{
	std::string address = std::to_string(addressValue);
	std::string cutOff = std::to_string(cutOffValue);
	std::string code = address + "FD" + cutOff + "\r\n";
	return code;
}

std::string conex::getFollowingErrorLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "FE?" + "\r\n";
	return code;
}

std::string conex::setFollowingErrorLimit(int addressValue, float errorLimitValue)
{
	std::string address = std::to_string(addressValue);
    std::string errorLimit = std::to_string(errorLimitValue);
	std::string code = address + "FE" + errorLimit + "\r\n";
	return code;
}

std::string conex::getFrictionCompensation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "FF?" + "\r\n";
	return code;
}

std::string conex::setFrictionCompensation(int addressValue, float frictionCompensationValue)
{
	std::string address = std::to_string(addressValue);
	std::string frictionCompensation = std::to_string(frictionCompensationValue);
	std::string code = address + "FF" + frictionCompensation + "\r\n";
	return code;
}

std::string conex::getHomeSearchType(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "HT?" + "\r\n";
	return code;
}

std::string conex::setHomeSearchType(int addressValue, int homeTypeValue)
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
    return code;
}

std::string conex::getStageIdentifier(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "ID?" + "\r\n";
	return code;
}

std::string conex::setStageIdentifier(int addressValue, float modelNumberValue)
{
	std::string address = std::to_string(addressValue);
	std::string modelNumber = std::to_string(modelNumberValue);
	std::string code = address + "ID" + modelNumber + "\r\n";
	return code;
}

std::string conex::getJerkTime(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "JR?" + "\r\n";
	return code;
}

std::string conex::setJerkTime(int addressValue, float jerkTimeValue)
{
	std::string address = std::to_string(addressValue);
	std::string jerkTime = std::to_string(jerkTimeValue);
	std::string code = address + "JR" + jerkTime + "\r\n";
	return code;
}

std::string conex::getDerivativeGain(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "KD?" + "\r\n";
	return code;
}

std::string conex::setDerivativeGain(int addressValue, float derivativeGainValue)
{
	std::string address = std::to_string(addressValue);
	std::string derivativeGain = std::to_string(derivativeGainValue);
	std::string code = address + "KD" + derivativeGain + "\r\n";
	return code;
}

std::string conex::getIntegralGain(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "KI?" + "\r\n";
	return code;
}

std::string conex::setIntegralGain(int addressValue, float integralGainValue)
{
	std::string address = std::to_string(addressValue);
	std::string integralGain = std::to_string(integralGainValue);
	std::string code = address + "KI" + integralGain + "\r\n";
	return code;
}

std::string conex::getProportionalGain(int addressValue)
{
    std::string address = std::to_string(addressValue);
	std::string code = address + "KP?" + "\r\n";
	return code;
}

std::string conex::setProportionalGain(int addressValue, float proportionalGainValue)
{
    std::string address = std::to_string(addressValue);
	std::string proportionalGain = std::to_string(proportionalGainValue);
	std::string code = address + "KP" + proportionalGain + "\r\n";
	return code;
}

std::string conex::getVelocityFeedForward(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "KV?" + "\r\n";
	return code;
}

std::string conex::setVelocityFeedForward(int addressValue, float velocityFeedForwardValue)
{
	std::string address = std::to_string(addressValue);
	std::string velocityFeedForward = std::to_string(velocityFeedForwardValue);
	std::string code = address + "KV" + velocityFeedForward + "\r\n";
	return code;
}

std::string conex::getDisableState(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "MM?" + "\r\n";
	return code;
}

std::string conex::disableState(int addressValue, bool commandValue)
{
	/*0: changes state from READY to DISABLE.
	  1: changes state from DISABLE to READY.*/
	std::string address = std::to_string(addressValue);
	std::string command = std::to_string(commandValue);
	std::string code = address + "MM" + command + "\r\n";
	return code;
}

std::string conex::getHomeSearchVelocity(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "OH?" + "\r\n";
	return code;
}

std::string conex::setHomeSearchVelocity(int addressValue, float velocityValue)
{
	std::string address = std::to_string(addressValue);
	std::string velocity = std::to_string(velocityValue);
	std::string code = address + "OH" + velocity + "\r\n";
	return code;
}

std::string conex::executeHomeSearch(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "OR" + "\r\n";
	return code;
}

std::string conex::getHomeSearchTimeOut(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "OT?" + "\r\n";
	return code;
}

std::string conex::setHomeSearchTimeOut(int addressValue, float timeOutValue)
{
	std::string address = std::to_string(addressValue);
	std::string timeOut = std::to_string(timeOutValue);
	std::string code = address + "OT" + timeOut + "\r\n";
	return code;
}

std::string conex::moveAbsolute(int addressValue, float targetPositionValue)
{
	std::string address = std::to_string(addressValue);
	std::string targetPosition = std::to_string(targetPositionValue);
	std::string code = address + "PA" + targetPosition + "\r\n";
	return code;
}

std::string conex::moveRelative(int addressValue, float displacementValue)
{
	std::string address = std::to_string(addressValue);
	std::string displacement = std::to_string(displacementValue);
	std::string code = address + "PR" + displacement + "\r\n";
	return code;
}

std::string conex::getMotionTimeForRelativeMove(int addressValue, float displacementValue)
{
	std::string address = std::to_string(addressValue);
	std::string displacement = std::to_string(displacementValue);
	std::string code = address + "PT" + displacement + "\r\n";
	return code;
}

std::string conex::configurationState(int addressValue, bool commandValue)
{
	/*0: changes state from NOT REFERENCE to CONFIGURATION.
      1: changes state from CONFIGURATION to NOT REFERENCE.*/
	std::string address = std::to_string(addressValue);
	std::string command = std::to_string(commandValue);
	std::string code = address + "PW" + command + "\r\n";
	return code;
}

std::string conex::getPeakCurrentLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "QIL?" + "\r\n";
	return code;
}

std::string conex::setPeakCurrentLimit(int addressValue, float limitValue)
{
	std::string address = std::to_string(addressValue);
	std::string limit = std::to_string(limitValue);
	std::string code = address + "QIL" + limit + "\r\n";
	return code;
}

std::string conex::getRMSCurrentLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "QIR?" + "\r\n";
	return code;
}

std::string conex::setRMSCurrentLimit(int addressValue, float limitValue)
{
	std::string address = std::to_string(addressValue);
	std::string limit = std::to_string(limitValue);
	std::string code = address + "QIR" + limit + "\r\n";
	return code;
}

std::string conex::getRMSAveragingTime(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "QIT?" + "\r\n";
	return code;
}

std::string conex::setRMSAveragingTime(int addressValue, float timeValue)
{
	std::string address = std::to_string(addressValue);
	std::string time = std::to_string(timeValue);
	std::string code = address + "QIT" + time + "\r\n";
	return code;
}

std::string conex::resetController(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "RS" + "\r\n";
	return code;
}

std::string conex::resetControllerAddress() 
{
	std::string code = "RS##\r\n";
	return code;
}

std::string conex::getControlLoopState(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "SC?" + "\r\n";
	return code;
}

std::string conex::setControlLoopState(int addressValue, bool stateValue)
{
	/* 1: CLOSED loop control.
	   0: OPEN loop control.*/
	std::string address = std::to_string(addressValue);
	std::string state = std::to_string(stateValue);
	std::string code = address + "SC" + state + "\r\n";
	return code;
}

std::string conex::configureSimultaneousStartedMove(int addressValue, float targetPositionValue)
{
	std::string address = std::to_string(addressValue);
	std::string targetPosition = std::to_string(targetPositionValue);
	std::string code = address + "SE" + targetPosition + "\r\n";
	return code;
}

std::string conex::getSimultaneousConfiguration(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "SE?" + "\r\n";
	return code;
}

std::string conex::executeSimultaneousStartedMove()
{
	std::string code = "SE\r\n";
	return code;
}

std::string conex::getNegativeSoftwareLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "SL?" + "\r\n";
	return code;
}

std::string conex::setNegativeSoftwareLimit(int addressValue, float limitValue)
{
	std::string address = std::to_string(addressValue);
	std::string limit = std::to_string(limitValue);
	std::string code = address + "SL" + limit + "\r\n";
	return code;
}

std::string conex::getPositiveSoftwareLimit(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "SR?" + "\r\n";
	return code;
}

std::string conex::setPositiveSoftwareLimit(int addressValue, float limitValue)
{
	std::string address = std::to_string(addressValue);
	std::string limit = std::to_string(limitValue);
	std::string code = address + "SR" + limit + "\r\n";
	return code;
}

std::string conex::stopMotion(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "ST\r\n";
	return code;
}

std::string conex::getEncoderIncrementValue(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "SU?\r\n";
	return code;
}

std::string conex::setEncoderIncrementValue(int addressValue, float incrementValue)
{
	std::string address = std::to_string(addressValue);
	std::string increment = std::to_string(incrementValue);
	std::string code = address + "SU" + increment + "\r\n";
	return code;
}

std::string conex::getCommandErrorString(int addressValue, char error)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "TB" + error + "\r\n";
	return code;
}

std::string conex::getLastCommandError(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "TE\r\n";
	return code;
}

std::string conex::getSetPointPosition(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "TH\r\n";
	return code;
}

std::string conex::trackingMode(int addressValue, bool modeValue)
{
	/*1: ENTER
	  0: LEAVE*/
	std::string address = std::to_string(addressValue);
	std::string mode = std::to_string(modeValue);
	std::string code = address + "TK" + mode + "\r\n";
	return code;
}

std::string conex::getCurrentPostion(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "TP" + "\r\n";
	return code;
}

std::string conex::getPostionerErrorAndControllerState(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "TS" + "\r\n";
	return code;
}

std::string conex::getVelocity(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "VA?" + "\r\n";
	return code;
}

std::string conex::setVelocity(int addressValue, float velocityValue)
{
	std::string address = std::to_string(addressValue);
	std::string velocity = std::to_string(velocityValue);
	std::string code = address + "VA" + velocity + "\r\n";
	return code;
}

std::string conex::getControllerRevisionInformation(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "VE" + "\r\n";
	return code;
}

std::string conex::getAllConfigurationParameters(int addressValue)
{
	std::string address = std::to_string(addressValue);
	std::string code = address + "ZT" + "\r\n";
	return code;
}