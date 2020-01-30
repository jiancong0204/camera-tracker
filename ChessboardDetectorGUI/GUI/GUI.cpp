#include "GUI.h"

GUI::GUI(QWidget *parent): QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.Initialization, SIGNAL(clicked()), this, SLOT(initializationSlot()));
	QObject::connect(ui.MovePositive_x, SIGNAL(clicked()), this, SLOT(movePositiveXSlot()));
	QObject::connect(ui.MoveNegative_x, SIGNAL(clicked()), this, SLOT(moveNegativeXSlot()));
	QObject::connect(ui.MovePositive_y, SIGNAL(clicked()), this, SLOT(movePositiveYSlot()));
	QObject::connect(ui.MoveNegative_y, SIGNAL(clicked()), this, SLOT(moveNegativeYSlot()));
	ui.streaming->adjustSize();
	ui.warning->adjustSize();
	ui.warning->setWordWrap(true);
	ui.warning->setAlignment(Qt::AlignTop);
}

void GUI::initializationSlot()
{
	mover.initialization("COM5");
	mover.initialization("COM6");
	warning = "Initialized!";
	ui.warning->setText(warning);
	_labelDisplayMat(ui.streaming);
}

void GUI::movePositiveXSlot() 
{
	displacement = ui.displacement_x->text();
	if (_isNumber(displacement.toUtf8().constData()))
	{
		dispValue = ui.displacement_x->text().toDouble();
		warning = QString::number(dispValue);
	}
	else 
	{
		dispValue = 0;
		warning = "Warning: The input must be a valid real number!";
	}
	mover.relativeMove("COM5", dispValue);
	ui.warning->setText(warning);
}

void GUI::moveNegativeXSlot()
{
	displacement = ui.displacement_x->text();
	if (_isNumber(displacement.toUtf8().constData()))
	{
		dispValue = ui.displacement_x->text().toDouble() * -1;
		warning = QString::number(dispValue);
	}
	else
	{
		dispValue = 0;
		warning = "Warning: The input must be a valid real number!";
	}
	mover.relativeMove("COM5", dispValue);
	ui.warning->setText(warning);
	
}

void GUI::movePositiveYSlot()
{
	displacement = ui.displacement_y->text();
	if (_isNumber(displacement.toUtf8().constData()))
	{
		dispValue = ui.displacement_y->text().toDouble();
		warning = QString::number(dispValue);
	}
	else
	{
		dispValue = 0;
		warning = "Warning: The input must be a valid real number!";
	}
	mover.relativeMove("COM6", dispValue);
	ui.warning->setText(warning);
}

void GUI::moveNegativeYSlot()
{
	displacement = ui.displacement_y->text();
	if (_isNumber(displacement.toUtf8().constData()))
	{
		dispValue = ui.displacement_y->text().toDouble() * -1;
		warning = QString::number(dispValue);
	}
	else
	{
		dispValue = 0;
		warning = "Warning: The input must be a valid real number!";
	}
	mover.relativeMove("COM6", dispValue);
	ui.warning->setText(warning);
}

bool GUI::_isNumber(std::string str)
{
	stream.clear();
	stream.str("");
	stream << str;
	double d;
	char c;
	if (!(stream >> d))
		return false;
	if (stream >> c)
		return false;
	return true;
}

void GUI::_labelDisplayMat(QLabel *label)
{
	cv::Mat mat1 = cv::imread("Images/01.jpg");
	cv::Mat mat;
	cv::Mat Rgb;
	float scale;
	double imageHeight = mat1.rows; // height of the original image (pixel)
	double imageWidth = mat1.cols; // width of the original image (pixel)
	// Calculate the resize factor /////////////////
	if (imageHeight > imageWidth)
	{
		scale = 860 / imageHeight;
	}
	else
	{
		scale = 860 / imageWidth;
	}

	cv::resize(mat1, mat, cv::Size(), scale, scale); // resize the image

	QImage Img;
	if (mat.channels() == 3)//RGB Img
	{
		cv::cvtColor(mat, Rgb, cv::COLOR_BGR2RGB);
		Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
	}
	else//Gray Img
	{
		Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols * mat.channels(), QImage::Format_Indexed8);
	}
	
	label->clear();
	label->setPixmap(QPixmap::fromImage(Img));
	//ui->processPushButton->setEnabled(true);
	label->resize(label->pixmap()->size());
	label->show();
	}