#include "JsonUtilization.h"

json jsonUtilization::loadJson(std::string filename)
{
	json params;
	std::ifstream read(filename);
	params = json::parse(read);
	return params;
}