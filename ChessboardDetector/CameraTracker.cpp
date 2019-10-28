#include "Chessboard.h"
#include "ChessboardDetector.h"
#include "Scanner.h"
#include "CameraParams.h"
#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	CameraParams cameraParams;
	json params = cameraParams.getCameraParams();
	cout << params << endl << endl;
	Chessboard chessboard = Chessboard(9, 7, 19);
	ChessboardDetector detector = ChessboardDetector(chessboard);
	ChessboardDetectorResult detectionResult = detector.getResult();
	BarcodeScanner barcode = BarcodeScanner(detectionResult);
	QrcodeScanner qrcode = QrcodeScanner(detectionResult);
	namedWindow("Perspective", WINDOW_NORMAL);
	imshow("Perspective", detectionResult.perspective);
	waitKey();
}