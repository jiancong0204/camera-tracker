#include "opencv.hpp"
#include "highgui/highgui.hpp"
#include "core.hpp"
#include "filter.h"
#include <fstream>
#include <typeinfo>
#include <iostream>
#include <string>
#include <math.h>
#include <zbar.h>

using namespace std;
using namespace cv;
using namespace zbar;
void scan(Mat code);
vector<Point2f> findBoundingCorners(Mat image);
Mat resizeImage(Mat original_image);
Mat computePerspectiveTransform(vector<Point2f> corners);
Mat chessboardDetector(Mat image);
void barcodeDetector(Mat perspective_image, vector<Point2f> corners);
void qrcodeDetector(Mat perspective_image, vector<Point2f> corners);
void displayImage(const string& name, Mat image);

int main()
{
	Mat original_image = imread("Images/01.jpg"); // , CV_8UC1);
	// 8-bit/single-channel image (adaptiveThreshold() can only process 8-bit single-channel image) 
	// resize the image ///////////////////////////////////////////////////////////////////////
	Mat resized_image = resizeImage(original_image);

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// apply binarization //////////////////////
	// Mat binarized_image; // image after binarization
	// threshold(resized_image, binarized_image, 100, 255, THRESH_BINARY); // naive threshold
	// adaptiveThreshold(resized_image, binarized_image, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	Mat perspective_image = chessboardDetector(resized_image);
	vector<Point2f> corners = findBoundingCorners(perspective_image);
	rectangle(perspective_image, corners[0], corners[62], Scalar(0, 0, 250), 2);
	barcodeDetector(perspective_image, corners);
	qrcodeDetector(perspective_image, corners);
	displayImage("Perspective", perspective_image);
	waitKey();
}

void scan(Mat code) {
	ImageScanner scanner;
	scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
	Mat gray_image;
	cvtColor(code, gray_image, COLOR_RGB2GRAY);
	uchar* raw = (uchar*)gray_image.data;
	Image imageZbar(gray_image.cols, gray_image.rows, "Y800", raw, gray_image.cols * gray_image.rows);
	scanner.scan(imageZbar);
	Image::SymbolIterator symbol = imageZbar.symbol_begin();
	if (imageZbar.symbol_begin() == imageZbar.symbol_end())
	{
		cout << "Failed" << endl;
	}
	for (; symbol != imageZbar.symbol_end(); ++symbol)
	{
		cout << "Type: " << symbol->get_type_name() << endl;
		cout << "Code: " << symbol->get_data() << endl << endl;
	}
	imageZbar.set_data(NULL, 0);
}

Mat resizeImage(Mat original_image) {
	double image_height = original_image.rows; // height of the original image (pixel)
	double image_width = original_image.cols; // width of the original image (pixel)
	double factor;
	int max_axis = 860;
	Mat resized_image;
	// Calculate the resize factor /////////////////
	if (image_height > image_width)
	{
		factor = max_axis / image_height;
	}
	else
	{
		factor = max_axis / image_width;
	}
	resize(original_image, resized_image, Size(), factor, factor); // resize the image
	return resized_image;
}

vector<Point2f> findBoundingCorners(Mat image) {
	vector<Point2f> corners;
	Size pattern_size;
	pattern_size.width = 9;
	pattern_size.height = 7;
	bool result = findChessboardCornersSB(image, pattern_size, corners);
	// drawChessboardCorners(image, pattern_size, Mat(corners), result);
	return corners;
}

Mat chessboardDetector(Mat image) {
	vector<Point2f> corners = findBoundingCorners(image);
	Mat M = computePerspectiveTransform(corners);
	Mat perspective_image;
	warpPerspective(image, perspective_image, M, Size(), INTER_LINEAR); // result of perspective transformation
	return perspective_image;
}

Mat computePerspectiveTransform(vector<Point2f> corners) {
	// Perspective ///////////////////////////////////////////////////
	float x_coordinate[4];
	float y_coordinate[4];
	double x_max;
	double y_max;
	double x_min;
	double y_min;

	x_coordinate[0] = corners[0].x;
	x_coordinate[1] = corners[8].x;
	x_coordinate[2] = corners[54].x;
	x_coordinate[3] = corners[62].x;
	y_coordinate[0] = corners[0].y;
	y_coordinate[1] = corners[8].y;
	y_coordinate[2] = corners[54].y;
	y_coordinate[3] = corners[62].y;
	x_max = *max_element(x_coordinate, x_coordinate + 4);
	y_max = *max_element(y_coordinate, y_coordinate + 4);
	x_min = *min_element(x_coordinate, x_coordinate + 4);
	y_min = *min_element(y_coordinate, y_coordinate + 4);

	//////////////////////////////////////////////////////
	Point2f src[] = {
		corners[0],
		corners[8],
		corners[54],
		corners[62]
	}; // for source image
	Point2f dst[] = {
		Point2f(x_max, y_max),
		Point2f(x_min, y_max),
		Point2f(x_max, y_min),
		Point2f(x_min, y_min)
	}; // corresponding points for perspective transformation
	Mat M = getPerspectiveTransform(src, dst);
	return M;
}

void barcodeDetector(Mat perspective_image, vector<Point2f> corners) {
	double grid_height;
	double grid_width;
	double barcode_x, barcode_y;
	grid_height = (corners[8].y - corners[62].y) / 6;
	grid_width = (corners[0].x - corners[8].x) / 8;
	barcode_x = corners[8].x - 1.1 * grid_width;
	barcode_y = corners[8].y + 1.2 * grid_height;
	double barcode_end_x = barcode_x + 14.5 * grid_width;
	double barcode_end_y = barcode_y + 1.85 * grid_height;
	if (barcode_end_y > perspective_image.rows) {
		barcode_end_y = perspective_image.rows;
	}
	if (barcode_x > perspective_image.cols || barcode_y > perspective_image.rows || barcode_end_x < 0 || barcode_end_y < 0) {
		cout << "No barcode detected!" << endl << endl;
	}
	else if (barcode_end_x > perspective_image.cols || barcode_x < 0) {
		cout << "Barcode is not complete!" << endl << endl;
	}
	else {
		// crop the region of barcode
		double barcode_width = barcode_end_x - barcode_x;
		double barcode_height = barcode_end_y - barcode_y;
		Mat image_src = perspective_image.clone();			// clone the image
		Mat barcode_ROI = image_src(Rect(barcode_x, barcode_y, barcode_width, barcode_height));	// ROI
		Mat barcode;
		barcode_ROI.convertTo(barcode, barcode.type());
		resize(barcode, barcode, Size(300, 200));
		rectangle(perspective_image, Point2f(barcode_x, barcode_y), Point2f(barcode_end_x, barcode_end_y), Scalar(0, 250, 0), 2);
		displayImage("Barcode", barcode);
		// imwrite("Images/barcode.png", barcode);
		scan(barcode);
	}
}

void qrcodeDetector(Mat perspective_image, vector<Point2f> corners) {
	double grid_height;
	double grid_width;
	double qrcode_x, qrcode_y;
	grid_height = (corners[8].y - corners[62].y) / 6;
	grid_width = (corners[0].x - corners[8].x) / 8;
	qrcode_x = corners[54].x + 1.25 * grid_width;
	qrcode_y = corners[54].y + 1 * grid_height;
	double qrcode_end_x = qrcode_x + 4.1 * grid_width;
	double qrcode_end_y = qrcode_y + 4.1 * grid_height;
	if (qrcode_x > perspective_image.cols || qrcode_y > perspective_image.rows || qrcode_end_x < 0 || qrcode_end_y < 0) {
		cout << "No QR-Code detected!" << endl << endl;
	}
	else if (qrcode_end_y > perspective_image.rows || qrcode_end_x > perspective_image.cols) {
		cout << "QR-Code is not complete!" << endl << endl;
	}
	else {
		// crop the region of qrcode
		Mat image_src = perspective_image.clone();			// clone the image
		Mat qrcode_ROI = image_src(Rect(qrcode_x, qrcode_y, 4.1 * grid_width, 4.1 * grid_height));	// ROI
		Mat qrcode;
		qrcode_ROI.convertTo(qrcode, qrcode.type());
		resize(qrcode, qrcode, Size(400, 400));
		rectangle(perspective_image, Point2f(qrcode_x, qrcode_y), Point2f(qrcode_end_x, qrcode_end_y), Scalar(250, 0, 0), 2);
		displayImage("QRcode", qrcode);
		// imwrite("Images/qrcode.png", qrcode);
		scan(qrcode);
	}

}

void displayImage(const string& name, Mat image) {
	namedWindow(name, WINDOW_NORMAL);
	imshow(name, image);
}