#pragma once
#include <zbar.h>
#include "ChessboardDetector.h"

typedef struct CodeInfo
{
	float originX;
	float endX;
	float originY;
	float endY;
	float codeWidth;
	float codeHeight;
	cv::String codeType;
	cv::String codeData;
	cv::Mat code;
} CodeInfo;

class CodeScanner
{
public:
	CodeInfo getCodeInfo(ChessboardDetectorResult detection, float findOriginX, float findOriginY, float findEndX, float findEndY);
	CodeInfo decode(ChessboardDetectorResult detection, CodeInfo codeInfo, const std::string& name);
	CodeInfo codeInfo;
};

class BarcodeScanner : public CodeScanner
{
public:
	BarcodeScanner(ChessboardDetectorResult detection);
	~BarcodeScanner() {};
	CodeInfo getBarCode();
private:
	CodeInfo barCodeInfo;
};

class QrcodeScanner : public CodeScanner
{
public:
	QrcodeScanner(ChessboardDetectorResult detectionResult);
	~QrcodeScanner() {};
	CodeInfo getQrCode();
private:
	CodeInfo qrCodeInfo;
};
