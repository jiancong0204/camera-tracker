/**
* @file JsonUtilization.h
* 
* @brief This file contains the declaration of the namespace jsonUtilization.
* 
* @author Jiancong Zheng 
* @date 2020-06-10
* 
*/

#pragma once
#include "nlohmann/json.hpp"
#include <fstream>

using json = nlohmann::json;

namespace jsonUtilization
{
	/**
	* @brief Load json file
	* @param filename Name of thejson file
	*/
	json loadJson(std::string filename);
};