#include "Chessboard.h"
#include "ChessboardDetector.h"
#include "Scanner.h"
#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;
Chessboard chessboard = Chessboard(9, 7, 19);
ChessboardDetector detector;
ChessboardDetectorResult detectionResult = detector.getResult();

int main()
{
	BarcodeScanner barcode;
	QrcodeScanner qrcode;
	namedWindow("Perspective", WINDOW_NORMAL);
	imshow("Perspective", detectionResult.perspective);
	waitKey();
}