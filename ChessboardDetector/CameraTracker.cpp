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
	Chessboard chessboard = Chessboard(9, 7, 20);
	Grid gridPoints;
	int number = chessboard.getHeight() * chessboard.getWidth();
	vector<Point3f> grid(number);
	grid = gridPoints.computeGrid(chessboard);
	
	ChessboardDetector detector = ChessboardDetector(chessboard);
	ChessboardDetectorResult detectionResult = detector.getResult();
	vector<Point2f> corners(number);
	corners = detectionResult.corners;
	
	JsonFile jsonFile;
	json cameraParams = jsonFile.loadJson("camera_parameters.json");
	vector<float> cameraMatrix = cameraParams["matrix"];
	vector<float> distCoeffs = cameraParams["distortion"];
	Mat raux, taux;
	solvePnP(grid, corners, cameraMatrix, distCoeffs, raux, taux);
	cout << raux << endl << endl;
	BarcodeScanner barcode = BarcodeScanner(detectionResult);
	QrcodeScanner qrcode = QrcodeScanner(detectionResult);
	namedWindow("Perspective", WINDOW_NORMAL);
	imshow("Perspective", detectionResult.perspective);
	waitKey();
}