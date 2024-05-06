#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include <TheLeague.h>
#include <Game.h>
#include <Teams.h>
#include <HighlightsOfTheMatch.h>

#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <regex>
#include <User.h>
enum Squad {
	MAIN = 1,
	SUBSTITUTION = 2
};
using namespace std;
class fileManipulation {
public:
	vector<TheLeague> static getLeagueData(map<string, Teams> allTeams);
	list<Game> static getGamesData(map<string, Teams> teams);
	map<string, Teams> static getTeamsData(map<string, unordered_map<string, Footballer>> footballersOfTeam);
	map<string, unordered_map<string, Footballer>> static getFootballersOfTeamData();
	unordered_map<string, User> static getUsersData(map<int, pair<unordered_map<string, Footballer>, unordered_map<string, Footballer>>> usersSquads);
	map<int, pair<unordered_map<string, Footballer>, unordered_map<string, Footballer>>> static getUserSquadsData(map<string, unordered_map<string, Footballer>> footballersOfTeam);

	vector<TheLeague> static parseLeagues(vector<string> parts, string regex, map<string, Teams> allTeams);
	list<Game> static parseGames(vector<string> parts, string regex, map<string, Teams> teams);
	map<string, Teams> static parseTeams(map<string, unordered_map<string, Footballer>> footballersOfTeam, vector<string> parts, string regex);
	pair<string, unordered_map<string, Footballer>> static parseFootballersOfTeam(pair<string, string> teamFootballers, string regex);
	pair<unordered_map<string, Footballer>, unordered_map<string, Footballer>> static parseUserSquads(vector<string> userIdMainSubSquads, string regex, map<string, unordered_map<string, Footballer>> footballersOfTeam);

	unordered_map<string, User> static parseUsers(vector<string> parts, string regex, map<int, pair<unordered_map<string, Footballer>, unordered_map<string, Footballer>>> usersSquads);

	Game static parseGame(vector<string> gameLines, map<string, Teams> teams);
	User static parseUser(vector<string> userLines, map<int, pair<unordered_map<string, Footballer>, unordered_map<string, Footballer>>> usersSquads);
	unordered_map<string, Footballer> static parseSquad(Squad squadType, vector<string> userIdMainSubSquads, string regex, map<string, unordered_map<string, Footballer>> footballersOfTeam);
	TheLeague static parseLeague(vector<string> leagueLines, map<string, Teams> allTeams);
	stack<HighlightsOfTheMatch> static analyzeTeamHighlights(string& teamName, int& gameID, stack<HighlightsOfTheMatch>& combinedHighlights, map<string, Teams> teams);
	Teams static parseTeam(vector<string> teamLines, unordered_map<string, Footballer> footballers);
	Footballer static parseFootballer(vector<string> footballerLines, string teamName);
	unordered_map<string, Footballer> static getSquadUsingAllFootballers(vector<string>userTeamAndFootballerNames, map<string, unordered_map<string, Footballer>> footballersOfTeam);
	HighlightsOfTheMatch static parseHighlight(vector<string> highlight, int gameId);
	string static parseGameStatistics(vector<string>);
	stack<HighlightsOfTheMatch> static parseHighlights(vector<string> highlights, int gameId, string regex);
	stack<HighlightsOfTheMatch> static getHighlights(int gameID);
};