#pragma once

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QThread>
#include <QTimer>
#include <QMessageBox>
#include <QPushButton>
#include <atlstr.h>
#include "ui_GUI.h"
#include "Scanner.h"
#include "ChessboardDetector.h"
#include "MoveComputer.h"
#include "Calibration.h"
#include "Calibration.h"
#include <sstream>
#include <iostream>
#include "BaslerGigECamera.h"

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
	Ui::GUIClass ui;
	bool trackingFlag = false;
	LPCWSTR COM1 = L"COM3";
	LPCWSTR COM2 = L"COM4";
	QString warning;
	MoveComputer mover;
	QString displacement;
	double dispValue;
	std::stringstream stream;
	void _labelDisplayMat(QLabel* label, cv::Mat mat);
	bool _isNumber(std::string str);
private slots:
	void initializationSlot();
	void movePositiveXSlot();
	void moveNegativeXSlot();
	void movePositiveYSlot();
	void moveNegativeYSlot();
	void cameraPoseEstimationSlot();
	void trackingModeSlot();
	void gotoXSlot();
	void gotoYSlot();
};