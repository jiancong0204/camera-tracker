#pragma once
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

class JsonFile
{
private:
	json params;

public:
	json loadJson(std::string filename);
};