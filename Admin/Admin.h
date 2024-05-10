#ifndef ADMIN_H
#define ADMIN_H

#include <algorithm>
#include <sstream>
#include <limits>
#include <Windows.h>
#include "UserValidations.h"

using namespace std;

class Admin {
public:
//
//	//admin
	void static CheckAdmin(unordered_map<string, User>& Users, vector<TheLeague> leagues);
	void static AdminMenu(unordered_map<string, User>& Users, vector<TheLeague> leagues);
	//users
	void static AboutUsers(unordered_map<string, User>& Users);
	void static DisplayAllUsers(unordered_map<string, User>& Users);
	void static ShowAndEditUser(unordered_map<string, User>& Users);
	void static ViewProfile(unordered_map<string, User>& Users, User& CurrentUser);
	void static EditProfile(unordered_map<string, User>& Users, User& CurrentUser);
	void static EditBalancePoints(User& CurrentUser, int choice, string information);
	bool static CheckBalancePoints(string information);
	void static UserSquadAndPlayers(unordered_map<string, User>& Users);
	void static DeleteUser(unordered_map<string, User>& Users);
	void static Deletion(unordered_map<string, User>& Users, User DeletedUser);

	//players
	void static handlePlayersUpdate(unordered_map<string, Footballer>& players, string oldName);
	string static checkStrLengthFootballers(string strs);
	static Footballer* handleFootballerExistance(unordered_map<string, Footballer>& players, string playerName);

	void static FootballerMenu(map<string, Teams>& teams);
	unordered_map<string, Footballer> static ModifyFootballer(unordered_map<string, Footballer>& players);
	void static DisplayFootballersForSpecificTeam(Teams& selectedTeam);


	static Teams* handleTeamExistance(map<string, Teams>& teams, string teamName);
	//teams
	void static handleTeamsUpdate(map<string, Teams>& teams, string oldName);

	void static TeamMenu(vector<TheLeague>& leagues);
	map<string, Teams> static ModifyTeams(map<string, Teams>& teams);
	void static displayTeamsForSpecificLeague(TheLeague& league);
	//leagues
	static TheLeague* handleLeagueExistance(vector<TheLeague>& leagues, string leagueName);
	void static LeaguesMenu(vector<TheLeague>& leagues);
	void static DisplayAllLeagues(vector<TheLeague>& leagues);
	void static UpdateLeagueName(vector<TheLeague>& leagues);
	vector<string> static getStringsToSearchIn(vector<TheLeague>& leagues);
	vector<string> static getStringsToSearchIn(map<string, Teams>& teams);
	vector<string> static getStringsToSearchIn(unordered_map<string, Footballer>& players);
	string static getCorrectedString(vector<string> allNames, string stringToSearchFor);
	string static toLowerCase(const string& str);
	string static toProperCase(const string& str);
	void static PauseAndClear();
};
#endif

