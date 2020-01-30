#include "GUI.h"

GUI::GUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.Initialization, SIGNAL(released()), this, SLOT(initializationSlot()));
	QObject::connect(ui.Move, SIGNAL(clicked()), this, SLOT(moveSlot()));
}

void GUI::initializationSlot()
{
	unsigned char* a = getAcceleration(1); 
	unsigned char* b = new unsigned char[strlen((const char*)a) - 6];
	memcpy(b, a, (strlen((char*)a) - 6));
	QString ss = QString::fromUtf8((char*)a);
	ui.label1->setText(ss);
}

void GUI::moveSlot() 
{
	QString ss = "ssssss";
	ui.label1->setText(ss);
}