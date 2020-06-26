#ifndef TRACKERGUI_H
#define TRACKERGUI_H

#pragma once
#include <QMainWindow>
#include <QApplication>
#include <QLabel>

#include <sstream>
#include "ChessboardDetector.h"
#include "BaslerGigECamera.h"
#include "Scanner.h"
#include "RotationStage.h"
#include "PoseEstimation.h"


namespace Ui {
class TrackerGUI;
}

class TrackerGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrackerGUI(QWidget *parent = 0);
    ~TrackerGUI();

private:
    Ui::TrackerGUI       *ui;        /**< Object for UI */
    RotationStage        rs;         /**< Object for rotation stage control*/
    BaslerGigECamera     camera;     /**< Object for camera */

/**
 * @brief Function that comfirms the input is a valid number
 * 
 * @param str Input string
 * @return true The input is a valid number
 * @return false The input is not a valid number
 */
bool _isNumber(std::string str);

/**
 * @brief Display image of cv::Mat in a label
 * 
 * @param label Label for display
 * @param mat Image of cv::Mat
 */
void _labelDisplayMat(QLabel* label, cv::Mat mat);

private slots:

    /**
     * @brief Slot for initialization
     * 
     */
    void initializationSlot();

    /**
     * @brief  Slot for changing elevation angle in positive direction
     * 
     */
	void movePositiveElevationSlot();

    /**
     * @brief Slot for changing elevation angle in negative direction
     * 
     */
	void moveNegativeElevationSlot();

    /**
     * @brief Slot for changing azimuth angle in positive direction
     * 
     */
	void movePositiveAzimuthSlot();

    /**
     * @brief Slot for changing azimuth angle in negative direction
     * 
     */
	void moveNegativeAzimuthSlot();

    /**
     * @brief Slot for absolute moving in elevation-direction
     * 
     */
	void gotoElevationSlot();

    /**
     * @brief Slot for absolute moving in azimuth-direction
     * 
     */
	void gotoAzimuthSlot();

    /**
     * @brief Slot for pose estimation
     * 
     */
    void cameraPoseEstimationSlot();
};

#endif // TRACKERGUI_H
