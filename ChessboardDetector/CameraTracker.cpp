#include "Chessboard.h"
#include "ChessboardDetector.h"
#include "Scanner.h"
#include "Calibration.h"
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
	//JsonFile jsonFile;
	//json cameraParams = jsonFile.loadJson("camera_parameters.json");

	//int height = chessboard.getHeight();
	//int width = chessboard.getWidth();
	//float size = chessboard.getSize();
	//
	//int number = height * width;
	//Grid gridPoints;
	//vector<Point3f> grid;
	//grid = gridPoints.computeGrid(height, width, size);
	//vector<Point2f> corners;
	//corners = detectionResult.corners;

	//double cam[9];
	//int k = 0;
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		cam[k] = cameraParams["matrix"][i][j];
	//		k++;
	//	}
	//}
	//double dist[5];
	//for (int i = 0; i < 5; i++)
	//{
	//	dist[i] = cameraParams["distortion"][0][i];
	//}
	//Mat raux, taux;
	//Mat camera_matrix = Mat(3, 3, CV_64FC1, cam);
	//Mat distortion_coefficients = Mat(5, 1, CV_64FC1, dist);
	//solvePnP(grid, corners, camera_matrix, distortion_coefficients, raux, taux);
	PoseEstimation poseEstimation = PoseEstimation(chessboard.getHeight(), chessboard.getWidth(), chessboard.getSize(), detectionResult.corners);

	Mat raux = poseEstimation.getRvecs();
	Mat taux = poseEstimation.getTvecs();
	cout << raux << endl << endl;
	cout << taux << endl << endl;
	////////////////////////////////////////////////////////////////////

	BarcodeScanner barcode = BarcodeScanner(detectionResult);
	QrcodeScanner qrcode = QrcodeScanner(detectionResult);
	namedWindow("Perspective", WINDOW_NORMAL);
	imshow("Perspective", detectionResult.perspective);
	waitKey();
}