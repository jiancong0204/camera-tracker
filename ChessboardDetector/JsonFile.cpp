#include "nlohmann/json.hpp"
#include "JsonFile.h"
#include <iostream>
#include <fstream>

using namespace std;
using namespace nlohmann;

json JsonFile::loadJson(string filename)
{
	json params;
	ifstream read(filename);
	params = json::parse(read);
	return params;
}