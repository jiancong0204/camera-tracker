#pragma once
#include <string>
#include <iostream>

unsigned char* getAcceleration(int addressValue); //xxAC?
unsigned char* setAcceleration(int addressValue, float accelerationValue); //xxACnn
unsigned char* getBacklashCompensation(int addressValue); //xxBA?
unsigned char* setBacklashCompensation(int addressValue, float backlashValue); //xxBAnn
unsigned char* getHysteresisCompensation(int addressValue); //xxBH?
unsigned char* setHysteresisCompensation(int addressValue, float hysteresisValue); //xxBHnn
unsigned char* getDriverVoltage(int addressValue); //xxBH?
unsigned char* setDriverVoltage(int addressValue, float driverVoltageValue); //xxBHnn
unsigned char* getLowPassFilterCutOffFrequency(int addressValue);
unsigned char* setLowPassFilterCutOffFrequency(int addressValue, float cutOffValue);
unsigned char* getFollowingErrorLimit(int addressValue);
unsigned char* setFollowingErrorLimit(int addressValue, float errorLimitValue);
unsigned char* getFrictionCompensation(int addressValue);
unsigned char* setFrictionCompensation(int addressValue, float frictionCompensationValue);
unsigned char* getHomeSearchType(int addressValue);
unsigned char* setHomeSearchType(int addressValue, int homeTypeValue);
unsigned char* getStageIdentifier(int addressValue);
unsigned char* setStageIdentifier(int addressValue, float modelNumberValue); ////////////////////////////////
unsigned char* getJerkTime(int addressValue);
unsigned char* setJerkTime(int addressValue, float jerkTimeValue);
unsigned char* getDerivativeGain(int addressValue);
unsigned char* setDerivativeGain(int addressValue, float derivativeGainValue);
unsigned char* getIntegralGain(int addressValue);
unsigned char* setIntegralGain(int addressValue, float integralGainValue);
unsigned char* getProportionalGain(int addressValue);
unsigned char* setProportionalGain(int addressValue, float proportionalGainValue);
unsigned char* getVelocityFeedForward(int addressValue);
unsigned char* setVelocityFeedForward(int addressValue, float velocityFeedForwardValue);
unsigned char* getDisableState(int addressValue);
unsigned char* disableState(int addressValue, bool commandValue);
unsigned char* getHomeSearchVelocity(int addressValue);
unsigned char* setHomeSearchVelocity(int addressValue, float velocityValue);
unsigned char* executeHomeSearch(int addressValue);
unsigned char* getHomeSearchTimeOut(int addressValue);
unsigned char* setHomeSearchTimeOut(int addressValue, float timeOutValue);
unsigned char* moveAbsolute(int addressValue, float targetPositionValue);
unsigned char* moveRelative(int addressValue, float displacementValue);
unsigned char* getMotionTimeForRelativeMoce(int addressValue, float displacementValue);
unsigned char* configurationState(int addressValue, bool commandValue);
unsigned char* getPeakCurrentLimit(int addressValue);
unsigned char* setPeakCurrentLimit(int addressValue, float limitValue);
unsigned char* getRMSCurrentLimit(int addressValue);
unsigned char* setRMSCurrentLimit(int addressValue, float limitValue);
unsigned char* getRMSAveragingTime(int addressValue);
unsigned char* setRMSAveragingTime(int addressValue, float timeValue);
unsigned char* resetController(int addressValue);
unsigned char* resetControllerAddress();
unsigned char* getControlLoopState(int addressValue);
unsigned char* setControlLoopState(int addressValue, bool stateValue);
unsigned char* configureSimultaneousStartedMove(int addressValue, float targetPositionValue);
unsigned char* executeSimultaneousStartedMove();
unsigned char* getSimultaneousConfiguration(int addressValue);
unsigned char* getNegativeSoftwareLimit(int addressValue);
unsigned char* setNegativeSoftwareLimit(int addressValue, float LimitValue);
unsigned char* getPositiveSoftwareLimit(int addressValue);
unsigned char* setPositiveSoftwareLimit(int addressValue, float LimitValue);
unsigned char* stopMotion(int addressValue);
unsigned char* getEncoderIncrementValue(int addressValue);
unsigned char* setEncoderIncrementValue(int addressValue, float incrementValue);
unsigned char* getCommandErrorString(int addressValue, char error);
unsigned char* getLastCommandError(int addressValue);
unsigned char* getSetPointPosition(int addressValue);
unsigned char* TrackingMode(int addressValue, bool modeValue);
unsigned char* getCurrentPostion(int addressValue);
unsigned char* getPostionerErrorAndControllerState(int addressValue);
unsigned char* getVelocity(int addressValue);
unsigned char* setVelocity(int addressValue, float velocityValue);
unsigned char* getControllerRevisionInformation(int addressValue);
unsigned char* getAllConfigurationParameters(int addressValue);