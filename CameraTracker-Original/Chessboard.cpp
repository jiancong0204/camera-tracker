#include <iostream>
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
	this->grid = this->computeGrid();
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

std::vector<cv::Point3f> Chessboard::getGrid()
{
	return this->grid;
}

std::vector<cv::Point3f> Chessboard::computeGrid()
{
	std::vector<cv::Point3f> grid(this->height * this->width);
	int half_height = this->height / 2;
	int half_width = this->width / 2;
	int index = 0;
	for (float y = -half_height * size; y <= half_height * size; y += this->size)
	{
		for (float x = -half_width * size; x <= half_width * size; x += this->size)
		{
			grid.at(index) = cv::Point3f(x, y, 0);
			++index;
		}
	}
	return grid;
}
