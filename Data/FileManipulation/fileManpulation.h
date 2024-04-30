#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <Game.h>
#include <Teams.h>
#include <HighlightsOfTheMatch.h>

#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <regex>

using namespace std;
class fileManipulation {
public:
	string static parseGameStatistics(vector<string>);

	list<Game> static parseGames(vector<string> parts, string regex);
	stack<HighlightsOfTheMatch> static parseHighlights(vector<string> highlights, int gameId, string regex);
	map<string, Teams> static parseTeams(map<string, unordered_map<string, Footballer>> footballersOfTeam,vector<string> parts, string regex);
	Game static parseGame(vector<string> gameLines);
	Teams static parseTeam(vector<string> teamLines, unordered_map<string, Footballer> footballers);
	HighlightsOfTheMatch static parseHighlight(vector<string> highlight, int gameId);
	list<Game> static getGamesData();
	map<string, Teams> static getTeamsData(map<string, unordered_map<string, Footballer>> footballersOfTeam);
	map<string, unordered_map<string, Footballer>> static getFootballersOfTeamData();
	stack<HighlightsOfTheMatch> static getHighlights(int gameID);
	pair<string, unordered_map<string, Footballer>> static parseFootballersOfTeam(pair<string, string> teamFootballers, string regex);
	Footballer static parseFootballer(vector<string> footballerLines, string teamName);
};