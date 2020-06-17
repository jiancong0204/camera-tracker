#include "ChessboardDetector.h"
#include "BaslerGigECamera.h"
#include "Scanner.h"
#include "RotationStage.h"
#include "PoseEstimation.h"
#include "Tracker.h"
#include "GUI.h"

int main(int argc, char* argv[])
{
    // BaslerGigECamera camera;
    // std::vector<std::string> cameraList = camera.listAvailableDevices();
	// std::string name = cameraList[0];
	// camera.initialize(name);
	// cv::Mat img = camera.getFrame();
    // // cv::Mat img = cv::imread("../Images/01.jpg",cv::IMREAD_GRAYSCALE);
    // img.convertTo(img, CV_8U);
    // Chessboard chessboard(9, 7, 20);
	// ChessboardDetector detector(chessboard, img);
	// ChessboardDetectorResult detectionResullt = detector.getResult();

    // if (detectionResullt.success)
    // {
    //     printf("Chessboard detection is successful!\n");
    //     PoseEstimation pose = PoseEstimation(chessboard.getGrid(), detectionResullt.scale, chessboard, detectionResullt.corners);
	//     cv::Mat raux = pose.getRvecs();
	//     cv::Mat taux = pose.getTvecs();
    //     for (int i = 0; i < 3; i++)
    //     {    
    //         std::cout << raux.at<double>(i, 0) << std::endl;
    //     }

    //     BarcodeScanner barcode = BarcodeScanner(detectionResullt);
    //     QrcodeScanner qrcode = QrcodeScanner(detectionResullt);
    //     CodeInfo qr = qrcode.getQrCode();
    //     CodeInfo bar = barcode.getBarCode();
    //     if (qr.codeType == "null")
    //     {
    //         std::cout << qr.codeData << std::endl;
    //     }
    //     else 
    //     {
    //         std::cout << "Type: " + qr.codeType + "; " + "Data: " + qr.codeData + ";" << std::endl;
    //     }
        
    //     if (bar.codeType == "null")
    //     {
    //         std::cout << bar.codeData << std::endl;
    //     }
    //     else 
    //     {
    //         std::cout << "Type: " + bar.codeType + "; " + "Data: " + bar.codeData + ";" << std::endl;
    //     }
    // }
    // else
    // {
    //     printf("Chessboard detection is failed!\n");
    //     // return -1;
    // }

    // cv::namedWindow( "Display window", cv::WINDOW_NORMAL ); // Create a window for display
    // cv::imshow( "Display window", img );
    // cv::waitKey(0); // Wait for a keystroke in the window

    // RotationStage rs;
    // rs.setElevationPort();
    // rs.setAzimuthPort();
    // rs.initializeElevation();
    // rs.initializeAzimuth();
    // rs.relativeMoveElevation(15);
    // rs.relativeMoveAzimuth(15);

    // Tracker tracker;
    // tracker.tracking();

    QApplication GUI(argc, argv);
    QMainWindow *window = new QMainWindow;
    window->setFixedSize(500, 500);
    // window->setLayout(vbLayout);
    window->show();
    return GUI.exec();

    return 0;
}