#include "Chessboard.h"
#include "ChessboardDetector.h"
#include "Scanner.h"
#include "JsonFile.h"
#include "Grid.h"
#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;


int main()
{
	JsonFile jsonFile;
	json params = jsonFile.loadJson("camera_parameters.json");
	cout << params["distortion"] << endl << endl;
	Chessboard chessboard = Chessboard(9, 7, 20);
	Grid gridPoints;
	int number = chessboard.getHeight() * chessboard.getWidth();
	vector<Point3f> grid(number);
	grid = gridPoints.computeGrid(chessboard);
	
	ChessboardDetector detector = ChessboardDetector(chessboard);
	ChessboardDetectorResult detectionResult = detector.getResult();

	BarcodeScanner barcode = BarcodeScanner(detectionResult);
	QrcodeScanner qrcode = QrcodeScanner(detectionResult);
	namedWindow("Perspective", WINDOW_NORMAL);
	imshow("Perspective", detectionResult.perspective);
	waitKey();
}