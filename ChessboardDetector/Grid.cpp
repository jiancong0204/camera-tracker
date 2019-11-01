#include <iostream>
#include "Grid.h"

vector<Point3f> Grid::computeGrid(int height, int width, int size)
{

	int half_height, half_width;
	half_height = (int)floor(height / 2);
	half_width = (int)floor(width / 2);
	Point3f origin(0, 0, 0);
	int number = height * width;
	vector<Point3f> grid(number);
	for (int y = origin.y + half_height * size; y >= origin.y - half_height * size; y -= size)
	{
		for (int x = origin.x + half_width * size; x >= origin.x - half_width * size; x -= size)
		{
			int num = (3 - (y - origin.y) / size) * 9 + (4 - (x - origin.x) / size);
			grid[num].x = x;
			grid[num].y = y;
			grid[num].z = origin.z;
		}
	}
	return grid;
}