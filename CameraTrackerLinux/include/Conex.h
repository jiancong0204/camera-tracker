#pragma once
#include <string>
#include <cstring>

/** Contains the generation of all the supported two-letter ASCII commands used to configure and operate the CONEX-CC.
* @The individual explanation can be found in the file 'CONEX-CC - Controller Documentation.pdf'
*/

namespace conex{
    std::string getAcceleration(int addressValue); //xxAC?
    std::string setAcceleration(int addressValue, float accelerationValue); //xxACnn
    std::string getBacklashCompensation(int addressValue); //xxBA?
    std::string setBacklashCompensation(int addressValue, float backlashValue); //xxBAnn
    std::string getHysteresisCompensation(int addressValue); //xxBH?
    std::string setHysteresisCompensation(int addressValue, float hysteresisValue); //xxBHnn
    std::string getDriverVoltage(int addressValue); //xxBH?
    std::string setDriverVoltage(int addressValue, float driverVoltageValue); //xxBHnn
    std::string getLowPassFilterCutOffFrequency(int addressValue); //xxFD?
    std::string setLowPassFilterCutOffFrequency(int addressValue, float cutOffValue); //xxFDnn
    std::string getFollowingErrorLimit(int addressValue); // FE
    std::string setFollowingErrorLimit(int addressValue, float errorLimitValue); //FE
    std::string getFrictionCompensation(int addressValue); // FF
    std::string setFrictionCompensation(int addressValue, float frictionCompensationValue); // FF
    std::string getHomeSearchType(int addressValue); // HT
    std::string setHomeSearchType(int addressValue, int homeTypeValue);
    std::string getStageIdentifier(int addressValue); // ID
    std::string setStageIdentifier(int addressValue, float modelNumberValue); ////////////////////////////////
    std::string getJerkTime(int addressValue); // JR
    std::string setJerkTime(int addressValue, float jerkTimeValue);
    std::string getDerivativeGain(int addressValue); // KD
    std::string setDerivativeGain(int addressValue, float derivativeGainValue);
    std::string getIntegralGain(int addressValue); // KI
    std::string setIntegralGain(int addressValue, float integralGainValue);
    std::string getProportionalGain(int addressValue); //KP
    std::string setProportionalGain(int addressValue, float proportionalGainValue);
    std::string getVelocityFeedForward(int addressValue); // KV
    std::string setVelocityFeedForward(int addressValue, float velocityFeedForwardValue);
    std::string getDisableState(int addressValue); // MM
    std::string disableState(int addressValue, bool commandValue);
    std::string getHomeSearchVelocity(int addressValue); // OH
    std::string setHomeSearchVelocity(int addressValue, float velocityValue);
    std::string executeHomeSearch(int addressValue); // OR
    std::string getHomeSearchTimeOut(int addressValue); // OT
    std::string setHomeSearchTimeOut(int addressValue, float timeOutValue);
    std::string moveAbsolute(int addressValue, float targetPositionValue); // PA
    std::string moveRelative(int addressValue, float displacementValue); // PR
    std::string getMotionTimeForRelativeMove(int addressValue, float displacementValue); // PT
    std::string configurationState(int addressValue, bool commandValue); // PW
    std::string getPeakCurrentLimit(int addressValue); // QIL
    std::string setPeakCurrentLimit(int addressValue, float limitValue);
    std::string getRMSCurrentLimit(int addressValue); // QIR
    std::string setRMSCurrentLimit(int addressValue, float limitValue);
    std::string getRMSAveragingTime(int addressValue); // QIT
    std::string setRMSAveragingTime(int addressValue, float timeValue);
    std::string resetController(int addressValue); // RS
    std::string resetControllerAddress(); // RS##
    std::string getControlLoopState(int addressValue); // SC
    std::string setControlLoopState(int addressValue, bool stateValue);
    std::string configureSimultaneousStartedMove(int addressValue, float targetPositionValue); //SE
    std::string executeSimultaneousStartedMove();
    std::string getSimultaneousConfiguration(int addressValue); 
    std::string getNegativeSoftwareLimit(int addressValue); // SL
    std::string setNegativeSoftwareLimit(int addressValue, float LimitValue);
    std::string getPositiveSoftwareLimit(int addressValue); // SR
    std::string setPositiveSoftwareLimit(int addressValue, float LimitValue);
    std::string stopMotion(int addressValue); // ST
    std::string getEncoderIncrementValue(int addressValue); // SU
    std::string setEncoderIncrementValue(int addressValue, float incrementValue);
    std::string getCommandErrorString(int addressValue, char error); // TB
    std::string getLastCommandError(int addressValue); // TE
    std::string getSetPointPosition(int addressValue); // TH
    std::string trackingMode(int addressValue, bool modeValue); // TK
    std::string getCurrentPostion(int addressValue); // TP
    std::string getPostionerErrorAndControllerState(int addressValue); // TS
    std::string getVelocity(int addressValue); // VA
    std::string setVelocity(int addressValue, float velocityValue); 
    std::string getControllerRevisionInformation(int addressValue); // VE
    std::string getAllConfigurationParameters(int addressValue); // ZT
}
