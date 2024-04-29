#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <Game.h>

#include <vector>
#include <regex>

using namespace std;
class fileManipulation {
public:
	string static parseGameStatistics(vector<string>);
	void static getGamesData();
};