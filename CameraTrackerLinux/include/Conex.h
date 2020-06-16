/**
 * @file Conex.h
 * @author Jiancong Zheng
 * @brief This file contains declarations of functions creating CONEX-CC commands
 * @date 2020-06-12
 */

#pragma once
#include <string>
#include <cstring>

/** 
* @brief Generate commands to configure encoders
* This namespace Contains the generation of all the supported two-letter ASCII commands used to configure and operate the CONEX-CC.
* The individual explanation can be found in the file 'CONEX-CC - Controller Documentation.pdf'
*/
namespace conex
{
    /**
     * @brief Get accelaration
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getAcceleration(int addressValue); //xxAC?
    
    /**
     * @brief Set acceleration
     * 
     * @param addressValue Controller address
     * @param accelerationValue Acceleration
     * @return Command code
     */
    std::string setAcceleration(int addressValue, float accelerationValue); //xxACnn

    /**
     * @brief Get backlash compensation
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getBacklashCompensation(int addressValue); //xxBA?

    /**
     * @brief Set backlash compensation
     * 
     * @param addressValue Controller address
     * @param backlashValue Backlash compensation value
     * @return Command code 
     */
    std::string setBacklashCompensation(int addressValue, float backlashValue); //xxBAnn

    /**
     * @brief Get hysteresis compensation 
     * 
     * @param addressValue Controller address
     * @return Command code 
     */
    std::string getHysteresisCompensation(int addressValue); //xxBH?

    /**
     * @brief Set hysteresis compensation
     * 
     * @param addressValue Controller address
     * @param hysteresisValue Hysteresis compensation value
     * @return Command code 
     */
    std::string setHysteresisCompensation(int addressValue, float hysteresisValue); //xxBHnn

    /**
     * @brief Get driver voltage
     * 
     * @param addressValue Controller address
     * @return Command code 
     */
    std::string getDriverVoltage(int addressValue); //xxBH?

    /**
     * @brief Set driver voltage
     * 
     * @param addressValue Controller address
     * @param driverVoltageValue Driver voltage value
     * @return Command code
     */
    std::string setDriverVoltage(int addressValue, float driverVoltageValue); //xxBHnn

    /**
     * @brief Get low-pass filter cut-off frequency
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getLowPassFilterCutOffFrequency(int addressValue); //xxFD?

    /**
     * @brief Set low-pass filter cut-off frequency
     * 
     * @param addressValue Controller address
     * @param cutOffValue Cut-off value
     * @return Command code
     */
    std::string setLowPassFilterCutOffFrequency(int addressValue, float cutOffValue); //xxFDnn

    /**
     * @brief Get following error limit
     * 
     * @param addressValue Contrller address
     * @return Command code
     */
    std::string getFollowingErrorLimit(int addressValue); // FE

    /**
     * @brief Set following error limit
     * 
     * @param addressValue Controller address
     * @param errorLimitValue Following error limit value
     * @return Command code
     */
    std::string setFollowingErrorLimit(int addressValue, float errorLimitValue); //FE

    /**
     * @brief Get friction compensation
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getFrictionCompensation(int addressValue); // FF

    /**
     * @brief Set friction compensation
     * 
     * @param addressValue Controller address
     * @param frictionCompensationValue Friction compensation value
     * @return Command code
     */
    std::string setFrictionCompensation(int addressValue, float frictionCompensationValue); // FF
    
    /**
     * @brief Get HOME search type
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getHomeSearchType(int addressValue); // HT

    /**
     * @brief Set HOME search type
     * 
     * @param addressValue Controller address
     * @param homeTypeValue HOME search type
     * @return Command code
     */
    std::string setHomeSearchType(int addressValue, int homeTypeValue);

    /**
     * @brief Get stage identifier
     * 
     * @param addressValue Controller value
     * @return Command code
     * 
     * Home Type nn:
     * 0: use MZ switch and encoder Index.
	 * 1: use current position as HOME.
	 * 2: use MZ switch only.
	 * 3: use EoR- switch and encoder Index.
	 * 4: use EoR- switch only.
     */
    std::string getStageIdentifier(int addressValue); // ID

    /**
     * @brief Set stage identifier
     * 
     * @param addressValue Controller address
     * @param modelNumberValue Model number
     * @return Command code
     */
    std::string setStageIdentifier(int addressValue, float modelNumberValue);

    /**
     * @brief Get jerk time
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getJerkTime(int addressValue); // JR

    /**
     * @brief Set jerk time
     * 
     * @param addressValue Controller address
     * @param jerkTimeValue Jerk time value
     * @return Command code
     */
    std::string setJerkTime(int addressValue, float jerkTimeValue);

    /**
     * @brief Get the derivative gain
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getDerivativeGain(int addressValue); // KD

    /**
     * @brief Set derivative gain
     * 
     * @param addressValue Controller address
     * @param derivativeGainValue Derivative gain value
     * @return Command code
     */
    std::string setDerivativeGain(int addressValue, float derivativeGainValue);

    /**
     * @brief Get integral gain
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getIntegralGain(int addressValue); // KI

    /**
     * @brief Set integral gain
     * 
     * @param addressValue Controller address
     * @param integralGainValue Integral gain value
     * @return Command code
     */
    std::string setIntegralGain(int addressValue, float integralGainValue);

    /**
     * @brief Get proportional gain 
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getProportionalGain(int addressValue); //KP

    /**
     * @brief Set proportional gain
     * 
     * @param addressValue Controller address
     * @param proportionalGainValue Proportional gain value
     * @return Command code
     */
    std::string setProportionalGain(int addressValue, float proportionalGainValue);

    /**
     * @brief Get velocity feed forward
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getVelocityFeedForward(int addressValue); // KV

    /**
     * @brief Set velocity feed forward
     * 
     * @param addressValue Controller address
     * @param velocityFeedForwardValue Velocity feed forward
     * @return Command code
     */
    std::string setVelocityFeedForward(int addressValue, float velocityFeedForwardValue);

    /**
     * @brief Get disable state 
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getDisableState(int addressValue); // MM

    /**
     * @brief Enter/Leave DISABLE state
     * 
     * @param addressValue Controller address
     * @param commandValue Enter/Leave command
     * @return Command code
     */
    std::string disableState(int addressValue, bool commandValue);

    /**
     * @brief Get HOME search velocity
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getHomeSearchVelocity(int addressValue); // OH

    /**
     * @brief Set HOME search velocity
     * 
     * @param addressValue Controller address
     * @param velocityValue HOME search velocity
     * @return Command code
     */
    std::string setHomeSearchVelocity(int addressValue, float velocityValue);

    /**
     * @brief Execute HOME search
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string executeHomeSearch(int addressValue); // OR

    /**
     * @brief Get HOME search time out
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getHomeSearchTimeOut(int addressValue); // OT

    /**
     * @brief Set HOME search time-out
     * 
     * @param addressValue Controller value
     * @param timeOutValue HOME search time-out value
     * @return Command code
     */
    std::string setHomeSearchTimeOut(int addressValue, float timeOutValue);

    /**
     * @brief Move absolute
     * 
     * @param addressValue Controller address
     * @param targetPositionValue Destination position
     * @return Command code
     */
    std::string moveAbsolute(int addressValue, float targetPositionValue); // PA

    /**
     * @brief Move relative
     * 
     * @param addressValue Controller address
     * @param displacementValue Displacement to move
     * @return Command code
     */
    std::string moveRelative(int addressValue, float displacementValue); // PR

    /**
     * @brief Get motion time for relative move
     * 
     * @param addressValue Controller address
     * @param displacementValue Displacement to move
     * @return Command code
     */
    std::string getMotionTimeForRelativeMove(int addressValue, float displacementValue); // PT

    /**
     * @brief Enter/Leave CONFIGURATION state
     * 
     * @param addressValue Controller address
     * @param commandValue Enter/Leave command
     * @return Command code
     */
    std::string configurationState(int addressValue, bool commandValue); // PW

    /**
     * @brief Get peak current limit
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getPeakCurrentLimit(int addressValue); // QIL

    /**
     * @brief Set peak current limit
     * 
     * @param addressValue Controller address
     * @param limitValue Peak current limit value 
     * @return Command code
     */
    std::string setPeakCurrentLimit(int addressValue, float limitValue);

    /**
     * @brief Get RMS current limit
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getRMSCurrentLimit(int addressValue); // QIR

    /**
     * @brief Set RMS current limit
     * 
     * @param addressValue Controller address
     * @param limitValue RMS current limit value
     * @return Command code
     */
    std::string setRMSCurrentLimit(int addressValue, float limitValue);

    /**
     * @brief Get RMS averaging time
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getRMSAveragingTime(int addressValue); // QIT

    /**
     * @brief Set RMS average time
     * 
     * @param addressValue Controller address
     * @param timeValue RMS average time value
     * @return Command code
     */
    std::string setRMSAveragingTime(int addressValue, float timeValue);

    /**
     * @brief Reset controller
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string resetController(int addressValue); // RS

    /**
     * @brief Reset controller's address to 1
     * 
     * @return Command code
     */
    std::string resetControllerAddress(); // RS##

    /**
     * @brief Get control loop state
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getControlLoopState(int addressValue); // SC

    /**
     * @brief Set control loop state
     * 
     * @param addressValue Controller address
     * @param stateValue State
     * @return Command code
     */
    std::string setControlLoopState(int addressValue, bool stateValue);

    /**
     * @brief Configure simultaneous started move
     * 
     * @param addressValue Controller address
     * @param targetPositionValue Destination to move
     * @return Command code
     */
    std::string configureSimultaneousStartedMove(int addressValue, float targetPositionValue); //SE
    
    /**
     * @brief Execute simultaneous started move
     * 
     * @return Command code
     */
    std::string executeSimultaneousStartedMove();

    /**
     * @brief Get configuration of simultaneous started move
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getSimultaneousConfiguration(int addressValue); 

    /**
     * @brief Get negative software limit 
     * 
     * @param addressValue 
     * @return Command code
     */
    std::string getNegativeSoftwareLimit(int addressValue); // SL

    /**
     * @brief Set negative software limit 
     * 
     * @param addressValue 
     * @param LimitValue 
     * @return Command code 
     */
    std::string setNegativeSoftwareLimit(int addressValue, float LimitValue);

    /**
     * @brief Get positive software limit
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getPositiveSoftwareLimit(int addressValue); // SR

    /**
     * @brief Set positive software limit
     * 
     * @param addressValue Controller address
     * @param LimitValue Positive software limit value
     * @return Command code
     */
    std::string setPositiveSoftwareLimit(int addressValue, float LimitValue);

    /**
     * @brief Stop motion
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string stopMotion(int addressValue); // ST

    /**
     * @brief Get encoder increment value
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getEncoderIncrementValue(int addressValue); // SU

    /**
     * @brief Set encoder increment value 
     * 
     * @param addressValue Controller address
     * @param incrementValue Encoder increment value
     * @return Command code
     */
    std::string setEncoderIncrementValue(int addressValue, float incrementValue);

    /**
     * @brief Get command error string 
     * 
     * @param addressValue Controller address
     * @param error Error string
     * @return Command code
     */
    std::string getCommandErrorString(int addressValue, char error); // TB

    /**
     * @brief Get last command error 
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getLastCommandError(int addressValue); // TE

    /**
     * @brief Get set-point position
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getSetPointPosition(int addressValue); // TH

    /**
     * @brief Enter/Leave tracking mode
     * 
     * @param addressValue Controller address
     * @param modeValue Enter/Leave command
     * @return Command code
     */
    std::string trackingMode(int addressValue, bool modeValue); // TK

    /**
     * @brief Get current postion
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getCurrentPostion(int addressValue); // TP

    /**
     * @brief Get postioner error and controller state
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getPostionerErrorAndControllerState(int addressValue); // TS

    /**
     * @brief Get velocity
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getVelocity(int addressValue); // VA

    /**
     * @brief Set velocity
     * 
     * @param addressValue Controller address
     * @param velocityValue Velocity
     * @return Command code
     */
    std::string setVelocity(int addressValue, float velocityValue); 

    /**
     * @brief Get controller revision information
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getControllerRevisionInformation(int addressValue); // VE

    /**
     * @brief Get all configuration parameters
     * 
     * @param addressValue Controller address
     * @return Command code
     */
    std::string getAllConfigurationParameters(int addressValue); // ZT
}
