#include "Scanner.h"

CodeInfo CodeScanner::decode(ChessboardDetectorResult detection, CodeInfo codeInfo, const std::string& name)
{
	codeInfo.codeWidth = codeInfo.endX - codeInfo.originX;
	codeInfo.codeHeight = codeInfo.endY - codeInfo.originY;
	cv::Mat image_src = detection.perspective.clone();			// clone the image
	cv::Mat codeROI = image_src(cv::Rect(codeInfo.originX, codeInfo.originY, codeInfo.codeWidth, codeInfo.codeHeight));	// ROI
	codeROI.convertTo(codeInfo.code, codeInfo.code.type());
	resize(codeInfo.code, codeInfo.code, cv::Size(300, 300));
	rectangle(detection.perspective, cv::Point2f(codeInfo.originX, codeInfo.originY), cv::Point2f(codeInfo.endX, codeInfo.endY), cv::Scalar(0, 250, 0), 2);
	
	//display the codes
	//cv::namedWindow(name, cv::WINDOW_NORMAL);
	//cv::imshow(name, codeInfo.code);

	cv::Mat grayImage = codeInfo.code;
	zbar::ImageScanner scanner;
	scanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);
	uchar* raw = (uchar*)grayImage.data;
	zbar::Image imageZbar(grayImage.cols, grayImage.rows, "Y800", raw, grayImage.cols * grayImage.rows);
	scanner.scan(imageZbar);
	zbar::Image::SymbolIterator symbol = imageZbar.symbol_begin();
	if (imageZbar.symbol_begin() == imageZbar.symbol_end())
	{
		std::cout << "Failed" << std::endl;
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
	rectangle(detection.perspectiveCopy, cv::Point2f(codeInfo.originX, codeInfo.originY), cv::Point2f(codeInfo.endX, codeInfo.endY), cv::Scalar(0, 250, 0), 2);
	return codeInfo;
}

BarcodeScanner::BarcodeScanner(ChessboardDetectorResult detectionResult)
{
	CodeInfo barcodeInfo = getCodeInfo(detectionResult, -1.1, 1.2, 14.5, 1.85);

	if (barcodeInfo.endY > detectionResult.perspective.rows) {
		barcodeInfo.endY = detectionResult.perspective.rows;
	}
	if (barcodeInfo.originX > detectionResult.perspective.cols || barcodeInfo.originY > detectionResult.perspective.rows || barcodeInfo.endX < 0 || barcodeInfo.endY < 0) {
		barcodeInfo.codeData = "No barcode detected!";
		barcodeInfo.codeType = "null";
	}
	else if (barcodeInfo.endX > detectionResult.perspective.cols || barcodeInfo.originX < 0) {
		barcodeInfo.codeData = "Barcode is not complete!";
		barcodeInfo.codeType = "null";
	}
	else {
		barcodeInfo = decode(detectionResult, barcodeInfo, "Barcode");
	}
	BarcodeScanner::barCodeInfo = barcodeInfo;
}

QrcodeScanner::QrcodeScanner(ChessboardDetectorResult detectionResult)
{
	CodeInfo qrcodeInfo = getCodeInfo(detectionResult, 9.2, -5.1, 4.2, 4.2);
	if (qrcodeInfo.originX > detectionResult.perspective.cols || qrcodeInfo.originY > detectionResult.perspective.rows || qrcodeInfo.endX < 0 || qrcodeInfo.endY < 0) {
		qrcodeInfo.codeData =  "No QR-Code detected!";
		qrcodeInfo.codeType = "null";
	}
	else if (qrcodeInfo.endY > detectionResult.perspective.rows || qrcodeInfo.endX > detectionResult.perspective.cols) {
		qrcodeInfo.codeData = "QR-Code is not complete!";
		qrcodeInfo.codeType = "null";
	}
	else {
		qrcodeInfo = decode(detectionResult, qrcodeInfo, "QRcode");
	}
	QrcodeScanner::qrCodeInfo = qrcodeInfo;
}

CodeInfo BarcodeScanner::getBarCode()
{
	return BarcodeScanner::barCodeInfo;
}

CodeInfo QrcodeScanner::getQrCode()
{
	return QrcodeScanner::qrCodeInfo;
}