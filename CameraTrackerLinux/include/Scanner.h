/**
* @file Scanner.h
* 
* @brief This file contains the declaration of the Scanner class.
* 
* @author Jiancong Zheng 
* @date 2020-05-29
* 
*/

#pragma once
#include <zbar.h>
#include "ChessboardDetector.h"

/** 
* @struct  CodeInfo
* @brief Structure that contains the related information of the code.
**/
typedef struct CodeInfo
{
	float        originX;      //< X-Coordinate of upper left corner of code.
 	float        endX;         //< X-Coordinates of lower right corner of code.
	float        originY;      //< Y-Coordinates of upper left corner of code.
	float        endY;         //< Y-Coordinates of lower right corner of code.
	float        codeWidth;    //< Width of the code.
	float        codeHeight;   //< Height of the code.
	cv::String   codeType;     //< Type of the code.
	cv::String   codeData;     //< Content of the code.
	cv::Mat      code;         //< Matrix image of the corresponding image.
} CodeInfo;

/** 
* @class CodeScanner
* @brief Class that contains the precedures of finding the position of code and decoding the code. 
**/
class CodeScanner
{
public:
    /**
	* @brief Constructor of CodeScanner class.
	**/
    CodeScanner() {};

    /**
	* @brief Deconstructor of CodeScanner class.
    **/
    ~CodeScanner() {};

	/** 
	* @brief Function that estimates the coordinates of code's corners based on the upper left corner of the chessboard. 
	* 
	* @param detection Result of chessboard detection.
	* @param findOriginX X-coordinate of the down left corner of the code.
	* @param findOriginY Y-coordinate of the down left corner of the code.
	* @param findEndX X-coordinate of the up right corner of the code.
	* @param findEndY Y-coordinate of the up right corner of the code.
	* @return A structure of the partial information about the code
	**/
	CodeInfo getCodeInfo(ChessboardDetectorResult detection, float findOriginX, float findOriginY, float findEndX, float findEndY);
	
	/** 
	* @brief Function that decodes the code to get the type and data. 
	*
	* @param detection Result of chessboard detection.
	* @param codeInfo Related information about the code.
	* @param name Name of the code. (Only used for displaying the code)
	* @return A structure of the complete information about the code
	**/
	CodeInfo decode(ChessboardDetectorResult detection, CodeInfo codeInfo, const std::string& name);

	CodeInfo codeInfo;
};

/** 
* @class BarcodeScanner
* @brief Class that contains the precedures of finding the position of barcode and decoding the barcode. 
* This class is a child class of CodeScanner.
*/
class BarcodeScanner : public CodeScanner
{
public:

    /**
	* @brief Constructor that performs code decoding.
	**/
	BarcodeScanner(ChessboardDetectorResult detection);

	/**
	* @brief Deconstructor of BarcodeScanner class.
	**/
	~BarcodeScanner() {};

	/**
	* @brief Function that is used to get code content.
	**/
	CodeInfo getBarCode();

private:
	CodeInfo barCodeInfo; //< Structure that stores the content of the code.
};

/** 
* @class QrcodeScanner
* @brief Class that contains the precedures of finding the position of QR-code and decoding the QR-code.
* This is a child class of CodeScanner.
*/
class QrcodeScanner : public CodeScanner
{
public:
    /**
	* @brief Constructor that performs code decoding.
	**/
	QrcodeScanner(ChessboardDetectorResult detectionResult);

	/**
	* @brief Deconstructor of QrcodeScanner class.
	**/
	~QrcodeScanner() {};

	/**
	* @brief Function that is used to get code content.
	**/
	CodeInfo getQrCode();

private:
	CodeInfo qrCodeInfo; //< Structure that stores the content of the code.
};
