#include "ChessboardDetector.h"
#include "BaslerGigECamera.h"
#include "Scanner.h"
#include "RotationStage.h"
#include "PoseEstimation.h"

int main()
{
    // BaslerGigECamera camera;
    // std::vector<std::string> cameraList = camera.listAvailableDevices();
	// std::string name = cameraList[0];
	// camera.initialize(name);
	// cv::Mat img = camera.getFrame();
    // // cv::Mat img = cv::imread("../Images/01.jpg",cv::IMREAD_GRAYSCALE);


    // cv::namedWindow( "Display window", cv::WINDOW_NORMAL ); // Create a window for display
    // cv::imshow( "Display window", img );
    // cv::waitKey(0); // Wait for a keystroke in the window
    RotationStage rs;
    rs.setElevationPort();
    rs.setAzimuthPort();
    rs.initializeElevation();
    rs.initializeAzimuth();
    // rs.relativeMoveElevation(15);
    // rs.relativeMoveAzimuth(15);
    return 0;
}