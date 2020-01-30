#pragma once

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "ui_GUI.h"
#include "MoveComputer.h"
#include <atlstr.h>

class GUI : public QMainWindow
{
	Q_OBJECT
public:
	GUI(QWidget *parent = Q_NULLPTR);
	~GUI() {};
private:
	Ui::GUIClass ui;
private slots:
	void initializationSlot();
	void moveSlot();
};
