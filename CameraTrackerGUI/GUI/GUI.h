#pragma once

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <atlstr.h>
#include "ui_GUI.h"
#include "Scanner.h"
#include <sstream>
#include <iostream>
#include "BaslerGigECamera.h"
#include "Tracking.h"
#include "mqttPublish.h"

#ifdef _UNICODE
typedef wchar_t TCHAR;
#else
typedef char TCHAR;
#endif // _UNICODE

typedef const TCHAR* LPCTSTR;

class TrackerGUI : public QMainWindow
{
	Q_OBJECT

public:
	TrackerGUI(QWidget *parent = Q_NULLPTR);
	~TrackerGUI() {};

private:
	Publish publisher;
	Ui::GUIClass ui;
	LPCWSTR COM1 = L"COM3";
	LPCWSTR COM2 = L"COM4";
	double theta[2]; // stores the angular displacement for tracking.
	double* distance; // stores the 3-dimensional distance between the center of chessboard and the center of the image
	QString warning;
	RotationStage mover; // instance for moveing the stage.
	QString displacement; // 
	double dispValue = 0;
	std::stringstream stream;
	QImage Img;
	cv::Mat sourceImg;

	BaslerGigECamera camera;
	/** Function that displays the matrix image from opencv in a chosen label of the GUI*/
	void _labelDisplayMat(QLabel* label, cv::Mat mat);
	
	/** Function that checks if the input is a valid real number
	* @return a boolean data type.
	*/
	bool _isNumber(std::string str);

	/** Thread for tracking.*/
	Tracking* tracking = new Tracking();
	bool trackingFlag = false;

private slots:
	void initializationSlot();

	/** Functions to control relative retation. */
	void movePositiveXSlot();
	void moveNegativeXSlot();
	void movePositiveYSlot();
	void moveNegativeYSlot();

	/** Functions used to control relative retation. */
	void gotoXSlot();
	void gotoYSlot();

	/** Function that calculates the camera pose, triggered by a related button*/
	void cameraPoseEstimationSlot();

	/** Function that decides to enter or leave the tracking mode*/
	void trackingModeSlot();
	
	/*get warning from tracking thread. */
	void getQString(QString warning);
	
};