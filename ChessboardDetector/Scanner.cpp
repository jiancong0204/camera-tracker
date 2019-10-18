#include <iostream>
#include <opencv.hpp>
#include <zbar.h>
#include "Scanner.h"
#include "ChessboardDetector.h"

using namespace std;
using namespace cv;
using namespace zbar;


CodeInfo CodeScanner::decode(ChessboardDetectorResult detection, CodeInfo codeInfo, const string& name)
{
	codeInfo.codeWidth = codeInfo.endX - codeInfo.originX;
	codeInfo.codeHeight = codeInfo.endY - codeInfo.originY;
	Mat image_src = detection.perspective.clone();			// clone the image
	Mat codeROI = image_src(Rect(codeInfo.originX, codeInfo.originY, codeInfo.codeWidth, codeInfo.codeHeight));	// ROI
	codeROI.convertTo(codeInfo.code, codeInfo.code.type());
	resize(codeInfo.code, codeInfo.code, Size(300, 300));
	rectangle(detection.perspective, Point2f(codeInfo.originX, codeInfo.originY), Point2f(codeInfo.endX, codeInfo.endY), Scalar(0, 250, 0), 2);
	namedWindow(name, WINDOW_NORMAL);
	imshow(name, codeInfo.code);
	Mat code = codeInfo.code;
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
	Mat grayImage;
	cvtColor(code, grayImage, COLOR_RGB2GRAY);
	uchar* raw = (uchar*)grayImage.data;
	Image imageZbar(grayImage.cols, grayImage.rows, "Y800", raw, grayImage.cols * grayImage.rows);
	scanner.scan(imageZbar);
	Image::SymbolIterator symbol = imageZbar.symbol_begin();
	if (imageZbar.symbol_begin() == imageZbar.symbol_end())
	{
		cout << "Failed" << endl;
	}
	for (; symbol != imageZbar.symbol_end(); ++symbol)
	{
		codeInfo.codeType = symbol->get_type_name();
		codeInfo.codeData = symbol->get_data();
	}
	imageZbar.set_data(NULL, 0);
	return codeInfo;
}


CodeInfo CodeScanner::getCodeInfo(ChessboardDetectorResult detection, float findOriginX, float findOriginY, float findEndX, float findEndY)
{
	CodeInfo codeInfo;
	codeInfo.originX = detection.boundingRectangle[1].x + findOriginX * detection.unitWidth;
	codeInfo.originY = detection.boundingRectangle[1].y + findOriginY * detection.unitHeight;
	codeInfo.endX = codeInfo.originX + findEndX * detection.unitWidth;
	codeInfo.endY = codeInfo.originY + findEndY * detection.unitHeight;
	// crop the region of barcode
	return codeInfo;
}

//String CodeScanner::getType()
//{
//	return this->codeType;
//}
//
//String CodeScanner::getData()
//{
//	return this->codeData;
//}
//
//Mat CodeScanner::getCode()
//{
//	return this->code;
//}


BarcodeScanner::BarcodeScanner()
{
	CodeInfo barcodeInfo = getCodeInfo(detectionResult, -1.1, 1.2, 14.5, 1.85);

	if (barcodeInfo.endY > detectionResult.perspective.rows) {
		barcodeInfo.endY = detectionResult.perspective.rows;
	}
	if (barcodeInfo.originX > detectionResult.perspective.cols || barcodeInfo.originY > detectionResult.perspective.rows || barcodeInfo.endX < 0 || barcodeInfo.endY < 0) {
		cout << "No barcode detected!" << endl << endl;
	}
	else if (barcodeInfo.endX > detectionResult.perspective.cols || barcodeInfo.originX < 0) {
		cout << "Barcode is not complete!" << endl << endl;
	}
	else {
		barcodeInfo = decode(detectionResult, barcodeInfo, "Barcode");
		cout << "Type: " << barcodeInfo.codeType << endl;
		cout << "Data: " << barcodeInfo.codeData << endl << endl;
	}

}

QrcodeScanner::QrcodeScanner()
{
	CodeInfo qrcodeInfo = getCodeInfo(detectionResult, 9.3, -5, 4.1, 4.1);
	if (qrcodeInfo.originX > detectionResult.perspective.cols || qrcodeInfo.originY > detectionResult.perspective.rows || qrcodeInfo.endX < 0 || qrcodeInfo.endY < 0) {
		cout << "No QR-Code detected!" << endl << endl;
	}
	else if (qrcodeInfo.endY > detectionResult.perspective.rows || qrcodeInfo.endX > detectionResult.perspective.cols) {
		cout << "QR-Code is not complete!" << endl << endl;
	}
	else {
		qrcodeInfo = decode(detectionResult, qrcodeInfo, "QRcode");
		cout << "Type: " << qrcodeInfo.codeType << endl;
		cout << "Data: " << qrcodeInfo.codeData << endl << endl;
	}
}