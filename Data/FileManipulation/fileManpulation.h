#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <Leagues.h>
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
	vector<League> static getLeagueData(map<string, Teams> allTeams);
	list<Game> static getGamesData();
	map<string, Teams> static getTeamsData(map<string, unordered_map<string, Footballer>> footballersOfTeam);
	map<string, unordered_map<string, Footballer>> static getFootballersOfTeamData();


	vector<League> static parseLeagues(vector<string> parts, string regex, map<string, Teams> allTeams);
	list<Game> static parseGames(vector<string> parts, string regex);
	map<string, Teams> static parseTeams(map<string, unordered_map<string, Footballer>> footballersOfTeam,vector<string> parts, string regex);
	pair<string, unordered_map<string, Footballer>> static parseFootballersOfTeam(pair<string, string> teamFootballers, string regex);

	Game static parseGame(vector<string> gameLines);
	League static parseLeague(vector<string> leagueLines, map<string, Teams> allTeams);
	Teams static parseTeam(vector<string> teamLines, unordered_map<string, Footballer> footballers);
	Footballer static parseFootballer(vector<string> footballerLines, string teamName);
	HighlightsOfTheMatch static parseHighlight(vector<string> highlight, int gameId);
	string static parseGameStatistics(vector<string>);
	stack<HighlightsOfTheMatch> static parseHighlights(vector<string> highlights, int gameId, string regex);
	stack<HighlightsOfTheMatch> static getHighlights(int gameID);
};