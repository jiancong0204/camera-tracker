#pragma once
#include "nlohmann/json.hpp"
#include <iostream>

using namespace nlohmann;
using namespace std;

class JsonFile
{
private:
	json params;

public:
	json loadJson(string filename);
};