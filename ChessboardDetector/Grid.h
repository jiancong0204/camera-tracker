#pragma once
#include <iostream>
#include "Chessboard.h"
#include "ChessboardDetector.h"
#include "nlohmann/json.hpp"

using namespace std;
using namespace nlohmann;

class Grid
{
public :
	vector<Point3f> computeGrid(Chessboard chessboard);
private:
	
	json params;
	int height;
	int width;
	float size;
};