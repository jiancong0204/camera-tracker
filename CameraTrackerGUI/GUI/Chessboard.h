#pragma once
#include <core.hpp>
#include <opencv.hpp>


/** Class that wraps the creation of chessboard. */
class Chessboard
{
public:
	/**Constructor that creates the chessboard with specific width 
	* (number of corners per row), height (number of corners per 
	* column) and size (side length of each block). 
	*/
	Chessboard(int width, int height, float size); 
	~Chessboard() {}; // Deconstructor

	/** Function used to obtain the width outside the class. */
	int getWidth();

	/** Function used to obtain the height outside the class. */
	int getHeight();

	/** Function used to obtain the height outside the class. */
	float getSize();

	/** Function used to get the coordinates of all the corners 
	* in the local coordiante system of the model outside the 
	* class.
	* @return a standard vector of three-dimensional points.
	*/
	std::vector<cv::Point3f> getGrid();

private:
	int width;
	int height;
	float size;
	std::vector<cv::Point3f> grid;

	/** Function that estimates the coordinate of each corner in
	* the local coordinate sytem.
	* @return a standard vector of three-dimensional points.
	*/
	std::vector<cv::Point3f> computeGrid();
};
