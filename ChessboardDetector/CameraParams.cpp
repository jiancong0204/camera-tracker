#include "nlohmann/json.hpp"
#include "CameraParams.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace nlohmann;

CameraParams::CameraParams()
{
	json params;
	ifstream read("camera_parameters.json");
	params = json::parse(read);
	this->params = params;
}

json CameraParams::getCameraParams()
{
	return this->params;
}