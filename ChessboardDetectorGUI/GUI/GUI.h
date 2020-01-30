#pragma once

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <atlstr.h>
#include "ui_GUI.h"
#include "Scanner.h"
#include "MoveComputer.h"
#include <sstream>
#include <iostream>

class GUI : public QMainWindow
{
	Q_OBJECT
public:
	GUI(QWidget *parent = Q_NULLPTR);
	~GUI() {};
private:
	Ui::GUIClass ui;
	QString warning;
	MoveComputer mover;
	QString displacement;
	double dispValue;
	std::stringstream stream;
	void _labelDisplayMat(QLabel* label);
	bool _isNumber(std::string str);
private slots:
	void initializationSlot();
	void movePositiveXSlot();
	void moveNegativeXSlot();
	void movePositiveYSlot();
	void moveNegativeYSlot();
};
