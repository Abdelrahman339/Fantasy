#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <Game.h>
#include <Teams.h>

#include <vector>
#include <list>
#include <map>
#include <regex>

using namespace std;
class fileManipulation {
public:
	string static parseGameStatistics(vector<string>);

	list<Game> static parseGames(vector<string> parts, string regex);
	map<string, Teams> static parseTeams(vector<string> parts, string regex);
	Teams static parseTeam(vector<string> teamLines);
	list<Game> static getGamesData();
	Game static parseGame(vector<string> gameLines);
	map<string, Teams> static getTeamsData();
};