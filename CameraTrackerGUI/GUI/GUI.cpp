#include "GUI.h"

TrackerGUI::TrackerGUI(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);
	tracking = new Tracking();
	QObject::connect(tracking, SIGNAL(returnQString(QString)), this, SLOT(getQString(QString)));
	QObject::connect(ui.initialization, SIGNAL(clicked()), this, SLOT(initializationSlot()));
	QObject::connect(ui.movePositive_x, SIGNAL(clicked()), this, SLOT(movePositiveXSlot()));
	QObject::connect(ui.moveNegative_x, SIGNAL(clicked()), this, SLOT(moveNegativeXSlot()));
	QObject::connect(ui.movePositive_y, SIGNAL(clicked()), this, SLOT(movePositiveYSlot()));
	QObject::connect(ui.moveNegative_y, SIGNAL(clicked()), this, SLOT(moveNegativeYSlot()));
	QObject::connect(ui.goto_x, SIGNAL(clicked()), this, SLOT(gotoXSlot()));
	QObject::connect(ui.goto_y, SIGNAL(clicked()), this, SLOT(gotoYSlot()));
	QObject::connect(ui.cameraPoseEstimate, SIGNAL(clicked()), this, SLOT(cameraPoseEstimationSlot()));
	QObject::connect(ui.trackingMode, SIGNAL(clicked()), this, SLOT(trackingModeSlot()));

	ui.streaming->adjustSize();
	ui.warning->adjustSize();
	ui.warning->setWordWrap(true);
	ui.warning->setAlignment(Qt::AlignTop);
	ui.warning->setStyleSheet("color:red;");
	ui.warning->setText("Please initialize first!");
	ui.goto_x->setEnabled(false);
	ui.goto_y->setEnabled(false);
	ui.cameraPoseEstimate->setEnabled(false);
	ui.displacement_x->setEnabled(false);
	ui.displacement_y->setEnabled(false);
	ui.trackingModePin->setEnabled(false);
	ui.trackingMode->setEnabled(false);
	ui.moveNegative_x->setEnabled(false);
	ui.moveNegative_y->setEnabled(false);
	ui.movePositive_x->setEnabled(false);
	ui.movePositive_y->setEnabled(false);
}

void TrackerGUI::initializationSlot()
{
	mover.initialization(COM1);
	bool echo1 = mover.getOpenPortEcho(); // check if opening is successful.
	mover.initialization(COM2);
	bool echo2 = mover.getOpenPortEcho(); // check if opening is successful.
	if (echo1 && echo2)
	{
		_initCamera();
		sourceImg = _getImage();
		
		warning = "Initialized!";
		ui.trackingMode->setEnabled(true);
		ui.cameraPoseEstimate->setEnabled(true);
		ui.moveNegative_x->setEnabled(true);
		ui.moveNegative_y->setEnabled(true);
		ui.movePositive_x->setEnabled(true);
		ui.movePositive_y->setEnabled(true);
		ui.displacement_x->setEnabled(true);
		ui.displacement_y->setEnabled(true);
		ui.trackingModePin->setEnabled(true);
		ui.goto_x->setEnabled(true);
		ui.goto_y->setEnabled(true);

	}
	else
	{
		warning = "Conection failed! Please restart.";
		ui.trackingMode->setEnabled(true);
		ui.cameraPoseEstimate->setEnabled(true);
		ui.moveNegative_x->setEnabled(true);
		ui.moveNegative_y->setEnabled(true);
		ui.movePositive_x->setEnabled(true);
		ui.movePositive_y->setEnabled(true);
		ui.displacement_x->setEnabled(true);
		ui.displacement_y->setEnabled(true);
		ui.trackingModePin->setEnabled(true);
		ui.goto_x->setEnabled(true);
		ui.goto_y->setEnabled(true);
	}
	ui.warning->setText(warning);
}

void TrackerGUI::movePositiveXSlot()
{
	displacement = ui.displacement_x->text();
	if (_isNumber(displacement.toUtf8().constData()))
	{
		dispValue = ui.displacement_x->text().toDouble();
		warning = "Rotate " + ui.displacement_x->text() + " counterclockwise around the x-axis";
	}
	else 
	{
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
	}
	mover.relativeMove(COM1, dispValue);
	ui.warning->setText(warning);
}

void TrackerGUI::moveNegativeXSlot()
{
	displacement = ui.displacement_x->text();
	if (_isNumber(displacement.toUtf8().constData()))
	{
		dispValue = ui.displacement_x->text().toDouble() * -1;
		warning = "Rotate " + ui.displacement_x->text() + " clockwise around the x-axis";
	}
	else
	{
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
	}
	mover.relativeMove(COM1, dispValue);
	ui.warning->setText(warning);
	
}

void TrackerGUI::movePositiveYSlot()
{
	displacement = ui.displacement_y->text();
	if (_isNumber(displacement.toUtf8().constData()))
	{
		dispValue = ui.displacement_y->text().toDouble();
		warning = "Rotate " + ui.displacement_y->text() + " clockwise around the y-axis";
	}
	else
	{
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
	}
	mover.relativeMove(COM2, dispValue);
	ui.warning->setText(warning);
}

void TrackerGUI::moveNegativeYSlot()
{
	displacement = ui.displacement_y->text();
	if (_isNumber(displacement.toUtf8().constData()))
	{
		dispValue = ui.displacement_y->text().toDouble() * -1;
		warning = "Rotate " + ui.displacement_y->text() + " counterclockwise around the y-axis";
	}
	else
	{
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
	}
	mover.relativeMove(COM2, dispValue);
	ui.warning->setText(warning);
}

bool TrackerGUI::_isNumber(std::string str)
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

void TrackerGUI::_labelDisplayMat(QLabel *label, cv::Mat mat)
{
	cv::Mat Rgb;
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

void TrackerGUI::_initCamera()
{
	std::vector<std::string> cameraList = camera.listAvailableDevices();
	std::string name = cameraList[0];
	camera.initialize(name);
}

cv::Mat TrackerGUI::_getImage()
{
	cv::Mat sourceImg = camera.getFrame();
	return sourceImg;
}

void TrackerGUI::cameraPoseEstimationSlot()
{
	QString warning1, warning2;
	QString barData, qrData, barType, qrType;
	// sourceImg = _getImage();
	sourceImg = cv::imread("Images/02.jpg",cv::IMREAD_GRAYSCALE);
	sourceImg.convertTo(sourceImg, CV_8U);
	Chessboard chessboard(9, 7, 20);
	ChessboardDetector detector(chessboard, sourceImg);
	ChessboardDetectorResult detectionResullt = detector.getResult();
	if (detectionResullt.success)
	{
		PoseEstimation pose = PoseEstimation(chessboard.getGrid(), detectionResullt.scale, chessboard, detectionResullt.corners);
		cv::Mat raux = pose.getRvecs();
		cv::Mat taux = pose.getTvecs();
		QString rVector[3];
		QString tVector[3];
		char const* rPayload;
		char const* tPayload;
		std::string rString[3];
		std::string tString[3];
		for (int i = 0; i < 3; i++)
		{
			rVector[i] = QString::number(raux.at<double>(i, 0));
			rString[i] = std::to_string(raux.at<double>(i, 0));
			tVector[i] = QString::number(taux.at<double>(i, 0));
			tString[i] = std::to_string(taux.at<double>(i, 0));
		}
		rString[0] = rString[0] + " " + rString[1] + " " + rString[2];
		rPayload = rString[0].c_str();
		publisher.publishPayload(rPayload, "Rotation");
		tString[0] = tString[0] + " " + tString[1] + " " + tString[2];
		tPayload = tString[0].c_str();
		publisher.publishPayload(tPayload, "Translation");
		ui.rotation_x->setText(rVector[0]);
		ui.rotation_y->setText(rVector[1]);
		ui.rotation_z->setText(rVector[2]);
		ui.translation_x->setText(tVector[0]);
		ui.translation_y->setText(tVector[1]);
		ui.translation_z->setText(tVector[2]);
		BarcodeScanner barcode = BarcodeScanner(detectionResullt);
		QrcodeScanner qrcode = QrcodeScanner(detectionResullt);
		CodeInfo qr = qrcode.getQrCode();
		CodeInfo bar = barcode.getBarCode();
		if (qr.codeType == "null")
		{
			warning1 = QString::fromStdString(qr.codeData);
			ui.qrcode->setText("");
		}
		else
		{
			warning1 = "";
			qrData = QString::fromStdString(qr.codeData);
			qrType = QString::fromStdString(qr.codeType);
			ui.qrcode->setText("Type: " + qrType + "; " + "Data: " + qrData + ";");
		}
		if (bar.codeType == "null")
		{
			warning2 = QString::fromStdString(bar.codeData);
			ui.barcode->setText("");
		}
		else 
		{
			warning2 = "";
			barData = QString::fromStdString(bar.codeData);
			barType = QString::fromStdString(bar.codeType);
			ui.barcode->setText("Type: " + barType + "; " + "Data: " + barData + ";");
		}
		warning = warning1 + "\n" + warning2;
		_labelDisplayMat(ui.streaming, detectionResullt.image);

	}
	else
	{
		cv::Mat resizedImg = detector.preprocess(sourceImg);
		_labelDisplayMat(ui.streaming, resizedImg);
		warning = "Chessboard detection failed!";
		ui.barcode->setText("");
		ui.qrcode->setText("");
		const char* tmpChar = warning.toStdString().c_str();
		publisher.publishPayload(tmpChar, "Rotation");
		publisher.publishPayload(tmpChar, "Translation");
	}
	ui.warning->setText(warning);
}

void TrackerGUI::gotoXSlot()
{
	displacement = ui.displacement_x->text();
	if (_isNumber(displacement.toUtf8().constData()))
	{
		dispValue = ui.displacement_x->text().toDouble();
		warning = "Rotate to " + QString::number(dispValue);
	}
	else
	{
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
	}
	mover.absoluteMove(COM1, dispValue);
	ui.warning->setText(warning);
}

void TrackerGUI::gotoYSlot()
{
	displacement = ui.displacement_y->text();
	if (_isNumber(displacement.toUtf8().constData()))
	{
		dispValue = ui.displacement_y->text().toDouble();
		warning = "Rotate to " + QString::number(dispValue);
		mover.absoluteMove(COM2, dispValue);
	}
	else
	{
		warning = "Warning: The input value must be a valid real number!";
	}
	ui.warning->setText(warning);
}


void TrackerGUI::trackingModeSlot()
{
	if (trackingFlag == false)
	{
		if (ui.trackingModePin->text().toStdString() == "WZL")
		{
			tracking->start();
			trackingFlag = true; 
			ui.trackingModePin->setText("WZL");
			ui.trackingMode->setText("Stop tracking");
			//warning = "Tracking...";
			//ui.warning->setText(warning);
			ui.initialization->setEnabled(false);
			ui.cameraPoseEstimate->setEnabled(false);
			ui.moveNegative_x->setEnabled(false);
			ui.moveNegative_y->setEnabled(false);
			ui.movePositive_x->setEnabled(false);
			ui.movePositive_y->setEnabled(false);
			ui.displacement_x->setEnabled(false);
			ui.displacement_y->setEnabled(false);
			ui.trackingModePin->setEnabled(false);
			ui.goto_x->setEnabled(false);
			ui.goto_y->setEnabled(false);
		}
		else
		{
			warning = "Incorrect PIN!";
			ui.trackingModePin->setText("WZL");
			ui.warning->setText(warning);
		}
	}
	else
	{
		tracking->quit();
		warning = "Tracking mode stopped!";
		trackingFlag = false;
		ui.trackingMode->setText("Tracking");
		ui.warning->setText(warning);
		ui.initialization->setEnabled(true);
		ui.cameraPoseEstimate->setEnabled(true);
		ui.moveNegative_x->setEnabled(true);
		ui.moveNegative_y->setEnabled(true);
		ui.movePositive_x->setEnabled(true);
		ui.movePositive_y->setEnabled(true);
		ui.displacement_x->setEnabled(true);
		ui.displacement_y->setEnabled(true);
		ui.trackingModePin->setEnabled(true);
		ui.goto_x->setEnabled(true);
		ui.goto_y->setEnabled(true);
	}
}

void TrackerGUI::getQString(QString warning)
{
	ui.warning->setText(warning);
}