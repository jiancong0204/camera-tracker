#include "Chessboard.h"

Chessboard::Chessboard(int width, int height, float size)
{
	if (width <= 0 || width % 2 == 0)
		throw std::invalid_argument("The width of the chessboard must be greater zero and odd.");
	if (height <= 0 || height % 2 == 0)
		throw std::invalid_argument("The height of the chessboard must be greater zero and odd.");
	if (size <= 0)
		throw std::invalid_argument("The size of the chessboard must be greater zero.");
	this->width = width;
	this->height = height;
	this->size = size;
	this->grid = this->_computeGrid();
}

int Chessboard::getWidth()
{
	return this->width;
}

int Chessboard::getHeight()
{
	return this->height;
}

float Chessboard::getSize()
{
	return this->size;
}

 std::vector<cv::Point3f> Chessboard::getGrid()\
{
	return this->grid;
}

std::vector<cv::Point3f> Chessboard::_computeGrid()
{
	int half_height, half_width;
	half_height = (int)floor(this->height / 2);
	half_width = (int)floor(this->width / 2);
	cv::Point3f origin(0, 0, 0);
	int number = this->height * this->width;
	std::vector<cv::Point3f> grid(number);
	for (int y = origin.y + half_height * this->size; y >= origin.y - half_height * this->size; y -= this->size)
	{
		for (int x = origin.x + half_width * this->size; x >= origin.x - half_width * this->size; x -= this->size)
		{
			int num = (3 - (y - origin.y) / this->size) * 9 + (4 - (x - origin.x) / this->size);
			grid[num].x = x;
			grid[num].y = y;
			grid[num].z = origin.z;
		}
	}
	return grid;
}
