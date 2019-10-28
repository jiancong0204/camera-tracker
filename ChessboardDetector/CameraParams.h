#pragma once
#include "nlohmann/json.hpp"
#include <iostream>

using namespace nlohmann;

class CameraParams
{
private:
	json params;

public:
	CameraParams();
	json getCameraParams();
};