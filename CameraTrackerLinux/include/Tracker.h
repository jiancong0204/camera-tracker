/**
 * @file Tracker.h
 * @author Jiancong Zheng
 * @brief This file contains declarations of the Tracker class
 * @date 2020-06-17
 */

#include "ChessboardDetector.h"
#include "BaslerGigECamera.h"
#include "RotationStage.h"
#include "PoseEstimation.h"

/**
 * @brief 
 * 
 */
class Tracker
{
public:
    /**
     * @brief Construct a new Tracker object
     * 
     */
    Tracker() {};

    /**
     * @brief Destroy the Tracker object
     * 
     */
    ~Tracker() {};

    /**
     * @brief Start tracking
     * 
     */
    void startTracking();

    /**
     * @brief Get azimuth angle
     * 
     * @return Azimuth angle 
     */
    double getAzimuth();

    /**
     * @brief Get elevation angle
     * 
     * @return Elevation angle 
     */
    double getElevation();

private:
    double             azimuthAngle;       //< Azimuth angle
    double             elevationAngle;     //< Elevation angle
    RotationStage      rs;                 //< RotationStage object


    /**
     * @brief 
     * 
     * @param azimuthAngle 
     * @param elevationAngle 
     */
    void _moveCamera(double azimuthAngle, double elevationAngle);

    /**
     * @brief Compute rotation angles
     * 
     * @param img Current image
     */
    void _computeRotationAngles(cv::Mat img);

}