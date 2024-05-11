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
	void static writeSampleDataInFile(string filename);
	void static writeInfoInSpecificFile(string filename, vector<TheLeague>);

	//void static writeInfoInSpecificFile(string filename, map<string, Teams*>*);
	void static writeInfoInSpecificFile(string filename, map<string, Teams*>*);
	vector<TheLeague> static getLeagueData(map<string, Teams>& allTeams);
	list<Game> static getGamesData(map<string, Teams>& teams);
	void static getTeamsData(map<string, unordered_map<string, Footballer>>& footballersOfTeam, map<string, Teams>& parsedTeams);
	map<string, unordered_map<string, Footballer>> static getFootballersOfTeamData();
	unordered_map<string, User> static getUsersData(map<int, pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>>>& usersSquads);
	map<int, pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>>> static getUserSquadsData(map<string, unordered_map<string, Footballer>>& footballersOfTeam);

	vector<TheLeague> static parseLeagues(vector<string> parts, string regex, map<string, Teams>& allTeams);
	list<Game> static parseGames(vector<string> parts, string regex, map<string, Teams>& teams);
	void static parseTeams(map<string, unordered_map<string, Footballer>>& footballersOfTeam, map<string, Teams>& parsedTeams, vector<string> parts, string regex);
	pair<string, unordered_map<string, Footballer>> static parseFootballersOfTeam(pair<string, string> teamFootballers, string regex);
	pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>> static parseUserSquads(vector<string> userIdMainSubSquads, string regex, map<string, unordered_map<string, Footballer>>& footballersOfTeam);

	unordered_map<string, User> static parseUsers(vector<string> parts, string regex, map<int, pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>>>& usersSquads);

	Game static parseGame(vector<string> gameLines, map<string, Teams>& teams);
	User static parseUser(vector<string> userLines, map<int, pair<unordered_map<string, Footballer*>, unordered_map<string, Footballer*>>>& usersSquads);
	unordered_map<string, Footballer*> static parseSquad(Squad squadType, vector<string> userIdMainSubSquads, string regex, map<string, unordered_map<string, Footballer>>& footballersOfTeam);
	TheLeague static parseLeague(vector<string> leagueLines, map<string, Teams>& allTeams);
	stack<HighlightsOfTheMatch> static analyzeTeamHighlights(string& homeTeamName, string& awayTeamName, int& gameID, map<string, Teams>& teams);
	static Teams* parseTeam(vector<string> teamLines, unordered_map<string, Footballer>* footballers);
	Footballer static parseFootballer(vector<string> footballerLines, string teamName);
	unordered_map<string, Footballer*> static getSquadUsingAllFootballers(vector<string>userTeamAndFootballerNames, map<string, unordered_map<string, Footballer>>& footballersOfTeam);
	HighlightsOfTheMatch static parseHighlight(vector<string> highlight, int gameId, string* name);
	string static parseGameStatistics(vector<string>);
	map<string, HighlightsOfTheMatch> static parseHighlights(vector<string> highlights, int gameId, map<string, Teams>& teams, string regex, string& homeTeamName, string& awayTeamName);
	map<string, HighlightsOfTheMatch> static getHighlights(int gameID, map<string, Teams>& teams, string& homeTeamName, string& awayTeamName);
};