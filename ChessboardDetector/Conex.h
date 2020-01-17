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