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
unsigned char* getLowPassFilterCutOffFrequency(int addressValue); //xxFD?
unsigned char* setLowPassFilterCutOffFrequency(int addressValue, float cutOffValue); //xxFDnn
unsigned char* getFollowingErrorLimit(int addressValue); // FE
unsigned char* setFollowingErrorLimit(int addressValue, float errorLimitValue); //FE
unsigned char* getFrictionCompensation(int addressValue); // FF
unsigned char* setFrictionCompensation(int addressValue, float frictionCompensationValue); // FF
unsigned char* getHomeSearchType(int addressValue); // HT
unsigned char* setHomeSearchType(int addressValue, int homeTypeValue);
unsigned char* getStageIdentifier(int addressValue); // ID
unsigned char* setStageIdentifier(int addressValue, float modelNumberValue); ////////////////////////////////
unsigned char* getJerkTime(int addressValue); // JR
unsigned char* setJerkTime(int addressValue, float jerkTimeValue);
unsigned char* getDerivativeGain(int addressValue); // KD
unsigned char* setDerivativeGain(int addressValue, float derivativeGainValue);
unsigned char* getIntegralGain(int addressValue); // KI
unsigned char* setIntegralGain(int addressValue, float integralGainValue);
unsigned char* getProportionalGain(int addressValue); //KP
unsigned char* setProportionalGain(int addressValue, float proportionalGainValue);
unsigned char* getVelocityFeedForward(int addressValue); // KV
unsigned char* setVelocityFeedForward(int addressValue, float velocityFeedForwardValue);
unsigned char* getDisableState(int addressValue); // MM
unsigned char* disableState(int addressValue, bool commandValue);
unsigned char* getHomeSearchVelocity(int addressValue); // OH
unsigned char* setHomeSearchVelocity(int addressValue, float velocityValue);
unsigned char* executeHomeSearch(int addressValue); // OR
unsigned char* getHomeSearchTimeOut(int addressValue); // OT
unsigned char* setHomeSearchTimeOut(int addressValue, float timeOutValue);
unsigned char* moveAbsolute(int addressValue, float targetPositionValue); // PA
unsigned char* moveRelative(int addressValue, float displacementValue); // PR
unsigned char* getMotionTimeForRelativeMove(int addressValue, float displacementValue); // PT
unsigned char* configurationState(int addressValue, bool commandValue); // PW
unsigned char* getPeakCurrentLimit(int addressValue); // QIL
unsigned char* setPeakCurrentLimit(int addressValue, float limitValue);
unsigned char* getRMSCurrentLimit(int addressValue); // QIR
unsigned char* setRMSCurrentLimit(int addressValue, float limitValue);
unsigned char* getRMSAveragingTime(int addressValue); // QIT
unsigned char* setRMSAveragingTime(int addressValue, float timeValue);
unsigned char* resetController(int addressValue); // RS
unsigned char* resetControllerAddress(); // RS##
unsigned char* getControlLoopState(int addressValue); // SC
unsigned char* setControlLoopState(int addressValue, bool stateValue);
unsigned char* configureSimultaneousStartedMove(int addressValue, float targetPositionValue); //SE
unsigned char* executeSimultaneousStartedMove();
unsigned char* getSimultaneousConfiguration(int addressValue); 
unsigned char* getNegativeSoftwareLimit(int addressValue); // SL
unsigned char* setNegativeSoftwareLimit(int addressValue, float LimitValue);
unsigned char* getPositiveSoftwareLimit(int addressValue); // SR
unsigned char* setPositiveSoftwareLimit(int addressValue, float LimitValue);
unsigned char* stopMotion(int addressValue); // ST
unsigned char* getEncoderIncrementValue(int addressValue); // SU
unsigned char* setEncoderIncrementValue(int addressValue, float incrementValue);
unsigned char* getCommandErrorString(int addressValue, char error); // TB
unsigned char* getLastCommandError(int addressValue); // TE
unsigned char* getSetPointPosition(int addressValue); // TH
unsigned char* TrackingMode(int addressValue, bool modeValue); // TK
unsigned char* getCurrentPostion(int addressValue); // TP
unsigned char* getPostionerErrorAndControllerState(int addressValue); // TS
unsigned char* getVelocity(int addressValue); // VA
unsigned char* setVelocity(int addressValue, float velocityValue); 
unsigned char* getControllerRevisionInformation(int addressValue); // VE
unsigned char* getAllConfigurationParameters(int addressValue); // ZT