/**
 * @file Tracker.h
 * @author Jiancong Zheng
 * @brief This file contains declarations of the Tracker class
 * @date 2020-06-17
 */

#pragma once
#include <QThread>
#include <QImage>

#include "ChessboardDetector.h"
#include "BaslerGigECamera.h"
#include "RotationStage.h"
#include "PoseEstimation.h"

/**
 * @brief Tracker class
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
    Tracker(QObject* parent = 0) : QThread(parent) 
    {
        this->quitting = false;
    };

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

signals:

    /**
     * @brief Signal for transmitting the image
     * 
     */
    void returnQImage(QImage);

private:

    float              azimuthAngle;       //< Azimuth angle
    float              elevationAngle;     //< Elevation angle
    RotationStage      rs;                 //< RotationStage object
    bool               quitting;           //< Flag for quitting the thread
    cv::Mat            img;                //< Image from Gige-camera
    cv::Mat            resizedImg;         //< Resized image
    /**
     * @brief Compute rotation angles
     * 
     * @param img Current image
     */
    void _computeRotationAngles(cv::Mat img);

    /**
     * @brief Emit the image
     * 
     * @param img Image
     */
    void _emitImage();
};