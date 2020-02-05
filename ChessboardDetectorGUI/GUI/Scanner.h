#pragma once
#include <zbar.h>
#include "ChessboardDetector.h"

/** Structure that contains the related information of the code. */
typedef struct CodeInfo
{
	float originX; // X-Coordinate of upper left corner of code.
 	float endX; // X-Coordinates of lower right corner of code.
	float originY; // Y-Coordinates of upper left corner of code.
	float endY; // Y-Coordinates of lower right corner of code.
	float codeWidth;
	float codeHeight;
	cv::String codeType;
	cv::String codeData;
	cv::Mat code; // Matrix image of the corresponding image.
} CodeInfo;

/** Class that contains the precedures of finding the position of code and decoding the code. */
class CodeScanner
{
public:

	/** Function that estimates the coordinates of code's corners based on the upper left corner of the chessboard. */
	CodeInfo getCodeInfo(ChessboardDetectorResult detection, float findOriginX, float findOriginY, float findEndX, float findEndY);
	
	/** Function that decodes the code to get the type and data. */
	CodeInfo decode(ChessboardDetectorResult detection, CodeInfo codeInfo, const std::string& name);

	CodeInfo codeInfo;
};

/** Class that contains the precedures of finding the position of barcode and decoding the barcode. 
* This is a child class of CodeScanner.
*/
class BarcodeScanner : public CodeScanner
{
public:
	BarcodeScanner(ChessboardDetectorResult detection);
	~BarcodeScanner() {};
	CodeInfo getBarCode();
private:
	CodeInfo barCodeInfo;
};

/** Class that contains the precedures of finding the position of QR-code and decoding the QR-code.
* This is a child class of CodeScanner.
*/
class QrcodeScanner : public CodeScanner
{
public:
	QrcodeScanner(ChessboardDetectorResult detectionResult);
	~QrcodeScanner() {};
	CodeInfo getQrCode();
private:
	CodeInfo qrCodeInfo;
};
