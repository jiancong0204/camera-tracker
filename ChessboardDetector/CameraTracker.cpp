#include "ChessboardDetector.h"
#include "Scanner.h"
#include "Calibration.h"


int main()
{

	Chessboard chessboard = Chessboard(9, 7, 20);
	ChessboardDetector detector = ChessboardDetector(chessboard);
	ChessboardDetectorResult detectionResult = detector.getResult();
	FindCornersResult originalCorners = detector.getOriginalCorners();
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

	PoseEstimation poseEstimation = PoseEstimation(chessboard.getGrid(), detectionResult.scale, chessboard, originalCorners.corners);

	cv::Mat raux = poseEstimation.getRvecs();
	cv::Mat taux = poseEstimation.getTvecs();
	std::cout << originalCorners.corners << std::endl << std::endl;
	std::cout << detectionResult.corners << std::endl << std::endl;
	std::cout << raux << std::endl << std::endl;
	std::cout << taux << std::endl << std:: endl;
	////////////////////////////////////////////////////////////////////

	BarcodeScanner barcode = BarcodeScanner(detectionResult);
	QrcodeScanner qrcode = QrcodeScanner(detectionResult);
	cv::namedWindow("Perspective", cv::WINDOW_NORMAL);
	imshow("Perspective", detectionResult.perspective);
	cv::waitKey();
}