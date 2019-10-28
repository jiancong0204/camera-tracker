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
	ChessboardDetector detector = ChessboardDetector(chessboard);
	ChessboardDetectorResult detectionResult = detector.getResult();

	////////////////////////////////////////////////////////////////////
	Grid gridPoints;
	int number = chessboard.getHeight() * chessboard.getWidth();
	vector<Point3f> grid(number);
	grid = gridPoints.computeGrid(chessboard);
	vector<Point2f> corners(number);
	corners = detectionResult.corners;
	JsonFile jsonFile;
	json cameraParams = jsonFile.loadJson("camera_parameters.json");
	double cam[9];
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cam[k] = cameraParams["matrix"][i][j];
			k++;
		}
	}
	double dist[5];
	for (int i = 0; i < 5; i++)
	{
		dist[i] = cameraParams["distortion"][0][i];
	}
	Mat raux, taux;
	Mat camera_matrix = Mat(3, 3, CV_64FC1, cam);
	Mat distortion_coefficients = Mat(5, 1, CV_64FC1, dist);
	solvePnP(grid, corners, camera_matrix, distortion_coefficients, raux, taux);
	cout << raux << endl << endl;
	cout << taux << endl << endl;
	////////////////////////////////////////////////////////////////////

	BarcodeScanner barcode = BarcodeScanner(detectionResult);
	QrcodeScanner qrcode = QrcodeScanner(detectionResult);
	namedWindow("Perspective", WINDOW_NORMAL);
	imshow("Perspective", detectionResult.perspective);
	waitKey();
}