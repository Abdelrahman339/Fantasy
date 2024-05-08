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
	void static AboutUsers(unordered_map<string, User>& Users, vector<TheLeague> leagues);
	void static DisplayAllUsers(unordered_map<string, User>& Users, vector<TheLeague> leagues);
	void static ShowAndEditUser(unordered_map<string, User>& Users, vector<TheLeague> leagues);
	void static ViewProfile(unordered_map<string, User>& Users, User& CurrentUser, vector<TheLeague> leagues);
	void static EditProfile(unordered_map<string, User>& Users, User& CurrentUser, vector<TheLeague> leagues);
	void static EditBalancePointsRank(User& CurrentUser, int choice, string information, vector<TheLeague> leagues);
	bool static CheckBalancePointsRank(string information, vector<TheLeague> leagues);
	void static UserSquadAndPlayers(unordered_map<string, User>& Users, vector<TheLeague> leagues);
	void static DeleteUser(unordered_map<string, User>& Users, vector<TheLeague> leagues);
	void static Deletion(unordered_map<string, User>& Users, User DeletedUser, vector<TheLeague> leagues);

	//players
	void static handlePlayersUpdate(unordered_map<string, Footballer>& players, string oldName);
	string static checkStrLengthFootballers(string strs);
	bool static handleFootballerExistance(unordered_map<string, Footballer> players, Footballer& PlayerToBeModified, string& playerName);

	void static FootballerMenu(map<string, Teams> teams);
	void static ModifyFootballer(unordered_map<string, Footballer>& players);
	void static DisplayFootballersForSpecificTeam(Teams selectedTeam);


	bool static handleTeamExistance(map<string, Teams> teams, Teams& TeamToBeModified, string teamName);
	//teams
	void static handleTeamsUpdate(map<string, Teams>& teams, string oldName);

	void static TeamMenu(vector<TheLeague> leagues);
	map<string, Teams> static ModifyTeams(map<string, Teams> teams);
	void static displayTeamsForSpecificLeague(TheLeague league);
	//leagues
	bool static handleLeagueExistance(vector<TheLeague> leagues, TheLeague& leagueToBeModified, string leagueName);
	void static LeaguesMenu(vector<TheLeague>& leagues);
	void static DisplayAllLeagues(vector<TheLeague> leagues);
	void static UpdateLeagueName(vector<TheLeague>& leagues);
	void DeleteLeague(void);
	void static PauseAndClear();
};
#endif

