#include "TrackerGUI.h"
#include "ui_TrackerGUI.h"

TrackerGUI::TrackerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrackerGUI)
{
    ui->setupUi(this);
    ui->streaming->setText("");

    // Connect slots and corresponding buttons
    QObject::connect(ui->initialization, SIGNAL(clicked()), this, SLOT(initializationSlot()));
    QObject::connect(ui->movePositive_x, SIGNAL(clicked()), this, SLOT(movePositiveElevationSlot()));
	QObject::connect(ui->moveNegative_x, SIGNAL(clicked()), this, SLOT(moveNegativeElevationSlot()));
	QObject::connect(ui->movePositive_y, SIGNAL(clicked()), this, SLOT(movePositiveAzimuthSlot()));
	QObject::connect(ui->moveNegative_y, SIGNAL(clicked()), this, SLOT(moveNegativeAzimuthSlot()));
	QObject::connect(ui->goto_x, SIGNAL(clicked()), this, SLOT(gotoElevationSlot()));
	QObject::connect(ui->goto_y, SIGNAL(clicked()), this, SLOT(gotoAzimuthSlot()));
	QObject::connect(ui->cameraPoseEstimate, SIGNAL(clicked()), this, SLOT(cameraPoseEstimationSlot()));
	QObject::connect(ui->trackingMode, SIGNAL(clicked()), this, SLOT(trackingModeSlot()));

    // Warning for initialization
	ui->streaming->adjustSize();
	ui->warning->adjustSize();
	ui->warning->setWordWrap(true);
	ui->warning->setAlignment(Qt::AlignTop);
	ui->warning->setStyleSheet("color:red;");
	ui->warning->setText("Initialization is required!");
    
    // Disable buttons before initialization
	ui->goto_x->setEnabled(false);
	ui->goto_y->setEnabled(false);
	ui->cameraPoseEstimate->setEnabled(false);
	ui->displacement_x->setEnabled(false);
	ui->displacement_y->setEnabled(false);
	ui->trackingModePin->setEnabled(false);
	ui->trackingMode->setEnabled(false);
	ui->moveNegative_x->setEnabled(false);
	ui->moveNegative_y->setEnabled(false);
	ui->movePositive_x->setEnabled(false);
	ui->movePositive_y->setEnabled(false);
}

TrackerGUI::~TrackerGUI()
{
    delete ui;
    delete tracking;
	delete camera;
}

void TrackerGUI::initializationSlot()
{
    // Initialize rotation stage
    rs.setElevationPort();
    rs.setAzimuthPort();
    rs.initializeElevation();
    rs.initializeAzimuth();

    if (this->isCameraInitialized == false)
	{
        // Initialize camera
	    this->tracking = new Tracker();
        this->camera = new BaslerGigECamera();
        std::vector<std::string> cameraList = this->camera->listAvailableDevices();
	    std::string name = cameraList[0];
	    this->camera->initialize(name);
		this->isCameraInitialized = true;
	}


    QString warning = "Initialized!";
	ui->trackingMode->setEnabled(true);
	ui->cameraPoseEstimate->setEnabled(true);
	ui->moveNegative_x->setEnabled(true);
	ui->moveNegative_y->setEnabled(true);
	ui->movePositive_x->setEnabled(true);
	ui->movePositive_y->setEnabled(true);
	ui->displacement_x->setEnabled(true);
	ui->displacement_y->setEnabled(true);
	ui->trackingModePin->setEnabled(true);
	ui->goto_x->setEnabled(true);
	ui->goto_y->setEnabled(true);
    ui->warning->setText(warning);
}

bool TrackerGUI::_isNumber(std::string str)
{
    std::stringstream stream;
    stream.clear();
    stream.str("");
    stream << str;
    double d;
    char c;
    if (!(stream >> d)) return false;
    if  (stream >> c) return false;
    return true;
}

void TrackerGUI::movePositiveElevationSlot()
{
    QString warning;
    double dispValue;
    QString displacement = ui->displacement_x->text();
    if (_isNumber(displacement.toUtf8().constData()))
    {
        dispValue = ui->displacement_x->text().toDouble();
		warning = "Rotate " + ui->displacement_x->text() + " in elevation direction";
    }
    else 
    {
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
    }
    rs.relativeMoveElevation(dispValue);
    ui->warning->setText(warning);
}

void TrackerGUI::moveNegativeElevationSlot()
{
    QString warning;
    double dispValue;
    QString displacement = ui->displacement_x->text();
    if (_isNumber(displacement.toUtf8().constData()))
    {
        dispValue = ui->displacement_x->text().toDouble() * -1;
		warning = "Rotate -" + ui->displacement_x->text() + " in elevation direction";
    }
    else 
    {
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
    }
    rs.relativeMoveElevation(dispValue);
    ui->warning->setText(warning);
}

void TrackerGUI::movePositiveAzimuthSlot()
{
    QString warning;
    double dispValue;
    QString displacement = ui->displacement_y->text();
    if (_isNumber(displacement.toUtf8().constData()))
    {
        dispValue = ui->displacement_y->text().toDouble();
		warning = "Rotate " + ui->displacement_y->text() + " in azimuth direction";
    }
    else 
    {
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
    }
    rs.relativeMoveAzimuth(dispValue);
    ui->warning->setText(warning);
}

void TrackerGUI::moveNegativeAzimuthSlot()
{
    QString warning;
    double dispValue;
    QString displacement = ui->displacement_y->text();
    if (_isNumber(displacement.toUtf8().constData()))
    {
        dispValue = ui->displacement_y->text().toDouble() * -1;
		warning = "Rotate -" + ui->displacement_y->text() + " in azimuth direction";
    }
    else 
    {
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
    }
    rs.relativeMoveAzimuth(dispValue);
    ui->warning->setText(warning);
}

void TrackerGUI::gotoElevationSlot()
{
    QString warning;
    double dispValue;
    QString displacement = ui->displacement_x->text();
    if (_isNumber(displacement.toUtf8().constData()))
    {
        dispValue = ui->displacement_x->text().toDouble();
		warning = "Rotate elevation angle to " + ui->displacement_x->text();
    }
    else 
    {
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
    }
    rs.absoluteMoveElevation(dispValue);
    ui->warning->setText(warning);
}

void TrackerGUI::gotoAzimuthSlot()
{
    QString warning;
    double dispValue;
    QString displacement = ui->displacement_y->text();
    if (_isNumber(displacement.toUtf8().constData()))
    {
        dispValue = ui->displacement_y->text().toDouble();
		warning = "Rotate azimuth angle to " + ui->displacement_x->text();
    }
    else 
    {
		dispValue = 0;
		warning = "Warning: The input value must be a valid real number!";
    }
    rs.absoluteMoveAzimuth(dispValue);
    ui->warning->setText(warning);
}

void TrackerGUI::cameraPoseEstimationSlot()
{
	cv::Mat sourceImg;
	QString warning, warning1, warning2;
	QString barData, qrData, barType, qrType;
	sourceImg = this->camera->getFrame();
	// sourceImg = cv::imread("../Images/01.jpg",cv::IMREAD_GRAYSCALE);
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
		// publisher.publishPayload(rPayload, "Rotation");
		tString[0] = tString[0] + " " + tString[1] + " " + tString[2];
		tPayload = tString[0].c_str();
		// publisher.publishPayload(tPayload, "Translation");
		ui->rotation_x->setText(rVector[0]);
		ui->rotation_y->setText(rVector[1]);
		ui->rotation_z->setText(rVector[2]);
		ui->translation_x->setText(tVector[0]);
		ui->translation_y->setText(tVector[1]);
		ui->translation_z->setText(tVector[2]);
		BarcodeScanner barcode = BarcodeScanner(detectionResullt);
		QrcodeScanner qrcode = QrcodeScanner(detectionResullt);
		CodeInfo qr = qrcode.getQrCode();
		CodeInfo bar = barcode.getBarCode();
		if (qr.codeType == "null")
		{
			warning1 = QString::fromStdString(qr.codeData);
			ui->qrcode->setText("");
		}
		else
		{
			warning1 = "";
			qrData = QString::fromStdString(qr.codeData);
			qrType = QString::fromStdString(qr.codeType);
			ui->qrcode->setText("Type: " + qrType + "; " + "Data: " + qrData + ";");
		}
		if (bar.codeType == "null")
		{
			warning2 = QString::fromStdString(bar.codeData);
			ui->barcode->setText("");
		}
		else 
		{
			warning2 = "";
			barData = QString::fromStdString(bar.codeData);
			barType = QString::fromStdString(bar.codeType);
			ui->barcode->setText("Type: " + barType + "; " + "Data: " + barData + ";");
		}
		warning = warning1 + "\n" + warning2;
		_labelDisplayMat(ui->streaming, detectionResullt.image);

	}
	else
	{
		cv::Mat resizedImg = detector.preprocess(sourceImg);
		_labelDisplayMat(ui->streaming, resizedImg);
		warning = "Chessboard detection failed!";
		ui->barcode->setText("");
		ui->qrcode->setText("");
		// const char* tmpChar = warning.toStdString().c_str();
		// publisher.publishPayload(tmpChar, "Rotation");
		// publisher.publishPayload(tmpChar, "Translation");
	}
	ui->warning->setText(warning);
}

void TrackerGUI::_labelDisplayMat(QLabel *label, cv::Mat mat)
{
    QImage Img;
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

void TrackerGUI::trackingModeSlot()
{
    if (this->trackingFlag == false)
	{
		if (ui->trackingModePin->text().toStdString() == "WZL")
		{
			// this->camera->detach();
			delete this->camera;
			this->isCameraInitialized = false;
			QObject::connect(tracking, SIGNAL(returnQString(QString)), this, SLOT(getQString(QString)));
			this->trackingFlag = true; 
			ui->trackingModePin->setText("WZL");
			ui->trackingMode->setText("Stop tracking");
			QString warning = "Tracking...";
			ui->warning->setText(warning);
			ui->initialization->setEnabled(false);
			ui->cameraPoseEstimate->setEnabled(false);
			ui->moveNegative_x->setEnabled(false);
			ui->moveNegative_y->setEnabled(false);
			ui->movePositive_x->setEnabled(false);
			ui->movePositive_y->setEnabled(false);
			ui->displacement_x->setEnabled(false);
			ui->displacement_y->setEnabled(false);
			ui->trackingModePin->setEnabled(false);
			ui->goto_x->setEnabled(false);
			ui->goto_y->setEnabled(false);
			
            this->tracking->start();
		}
		else
		{
			QString warning = "Incorrect PIN!";
			ui->trackingModePin->setText("WZL");
			ui->warning->setText(warning);
		}
	}
	else
	{
		this->tracking->quitThread();
		this->tracking->quit();
		this->tracking->wait();
		delete this->tracking;
		QString warning = "Tracking mode stopped!\nInitialization is required!";
		this->trackingFlag = false;
		ui->trackingMode->setText("Tracking");
		ui->warning->setText(warning);
		ui->initialization->setEnabled(true);
		ui->trackingModePin->setEnabled(false);
		ui->trackingMode->setEnabled(false);
	}
}