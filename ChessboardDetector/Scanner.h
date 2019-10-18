#pragma once
#include <opencv.hpp>
#include <zbar.h>
#include "ChessboardDetector.h"

using namespace std;
using namespace cv;
using namespace zbar;
extern ChessboardDetector detector;
extern ChessboardDetectorResult detectionResult;


typedef struct CodeInfo
{
	float originX;
	float endX;
	float originY;
	float endY;
	float codeWidth;
	float codeHeight;
	String codeType;
	String codeData;
	Mat code;
} CodeInfo;

class CodeScanner
{
public:
	CodeInfo getCodeInfo(ChessboardDetectorResult detection, float findOriginX, float findOriginY, float findEndX, float findEndY);
	CodeInfo decode(ChessboardDetectorResult detection, CodeInfo codeInfo, const string& name);

protected:
	CodeInfo codeInfo;
};

class BarcodeScanner:public CodeScanner
{
public:
	BarcodeScanner();
	~BarcodeScanner() {};
};

class QrcodeScanner:public CodeScanner
{
public:
	QrcodeScanner();
	~QrcodeScanner() {};
};
