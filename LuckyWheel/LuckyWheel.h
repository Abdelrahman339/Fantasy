#pragma once
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <vector>
#include <set>
#include <chrono>
#include <thread>

#include "TheLeague.h"
#include "Teams.h"
#include "User.h"

using namespace std;
using namespace chrono_literals;

class LuckyWheel {
public:
	void static playLuckyWheel(vector<TheLeague> leagues, User& user);
private:
	//Method to use leagues to randomly display a vector of footballers in which one picked from.
	void static getFootballPlayersToBeDisplayed(vector<TheLeague> leagues, int& numberOfFootballersToBeDisplayed, unordered_map<string, Footballer>& footballersToBeDisplayed, bool& isRandomGeneratorSeeded);
	string static generateCongratulatoryMessage(string lottery, float discount);
	pair<string, pair<float, Footballer>> static displayLuckyWheel(vector<TheLeague> leagues);
	void static displayFootballersInLuckyWheel(unordered_map<string, Footballer>& footballersToBeDisplayed);

};

