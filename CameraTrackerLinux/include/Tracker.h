/**
 * @file Tracker.h
 * @author Jiancong Zheng
 * @brief This file contains declarations of the Tracker class
 * @date 2020-06-17
 */

#pragma once
#include <QThread>
#include <QTimer>

#include "ChessboardDetector.h"
#include "BaslerGigECamera.h"
#include "RotationStage.h"
#include "PoseEstimation.h"

/**
 * @brief 
 * 
 */
class Tracker : public QThread
{

    Q_OBJECT

public:

    /**
     * @brief Construct a new Tracker object
     * 
     */
    Tracker(QObject* parent = 0) : QThread(parent) {};

    /**
     * @brief Destroy the Tracker object
     * 
     */
    ~Tracker() {};

    /**
     * @brief Start tracking
     * 
     */
    void run();

    /**
     * @brief Get azimuth angle
     * 
     * @return Azimuth angle 
     */
    float getAzimuth();

    /**
     * @brief Get elevation angle
     * 
     * @return Elevation angle 
     */
    float getElevation();

    /**
     * @brief Exit the thread
     * 
     */
    void quitThread();

private:
    float              azimuthAngle;       //< Azimuth angle
    float              elevationAngle;     //< Elevation angle
    RotationStage      rs;                 //< RotationStage object
    bool               quitting;           //< Flag for quitting the thread
    /**
     * @brief Compute rotation angles
     * 
     * @param img Current image
     */
    void _computeRotationAngles(cv::Mat img);
};