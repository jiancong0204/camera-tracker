#include "ChessboardDetector.h"
#include "Scanner.h"
#include "Calibration.h"
#include <pylon/PylonIncludes.h>
#include "BaslerGigECamera.h"
#include <conio.h>

int main()
{
	BaslerGigECamera camera;
	std::vector<std::string> cameraList = camera.listAvailableDevices();
	std::string name = cameraList[0];
	camera.initialize(name);
	while (TRUE)
	{
		if (_kbhit() && _getch() == 0x1b)
			break;
		cv::Mat sourceImage = camera.getFrame();
		// camera.detach();
		Chessboard chessboard(9, 7, 20);
		ChessboardDetector detector(chessboard, sourceImage);
		ChessboardDetectorResult detectionResult = detector.getResult();
		if (detectionResult.success)
		{
			PoseEstimation poseEstimation = PoseEstimation(chessboard.getGrid(), detectionResult.scale, chessboard, detectionResult.corners);
			cv::Mat raux = poseEstimation.getRvecs();
			cv::Mat taux = poseEstimation.getTvecs();
			// std::cout << detectionResult.corners << std::endl << std::endl;
			std::cout << raux << std::endl << std::endl;
			std::cout << taux << std::endl << std::endl;
			BarcodeScanner barcode = BarcodeScanner(detectionResult);
			QrcodeScanner qrcode = QrcodeScanner(detectionResult);
			//cv::namedWindow("Perspective", cv::WINDOW_NORMAL);
			//imshow("Perspective", detectionResult.perspectiveCopy);
		}
		else 
		{
			std::cout << "Chessboard detection failed!" << std::endl << std::endl;
		}
	}
	cv::waitKey();
}