#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include "User.h"
#include "Teams.h"
#include "TheLeague.h"
using namespace std;
class Admin
{
protected:




public:

	//admin
	void static CheckAdmin(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues);
	void static AdminMenu(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues);
private:
	//users
	void static AboutUsers(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues);
	void static DisplayAllUsers(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues);
	void static ShowAndEditUser(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues);
	void static ViewProfile(unordered_map<string, User>& Users, User& CurrentUser, map<string, Teams>& teams, vector<TheLeague> leagues);
	void static EditProfile(unordered_map<string, User>& Users, User& CurrentUser, map<string, Teams>& teams, vector<TheLeague> leagues);
	void static EditBalancePointsRank(User& CurrentUser, int choice, string information, map<string, Teams>& teams, vector<TheLeague> leagues);
	bool static CheckBalancePointsRank(string information, map<string, Teams>& teams, vector<TheLeague> leagues);
	void static UserSquadAndPlayers(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues);
	void static DeleteUser(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<TheLeague> leagues);
	void static Deletion(unordered_map<string, User>& Users, User DeletedUser, map<string, Teams>& teams, vector<TheLeague> leagues);

	//players
	void static handleFootballerExistance(unordered_map<string, Footballer> players, Footballer& PlayerToBeModified, string& playerName);

	void static FootballerMenu(unordered_map<string, Footballer>& players);
	void static ModifyFootballer(unordered_map<string, Footballer> players, Footballer& footballerToBeModified);
	void static DisplayFootballersForSpecificTeam(map<string, Teams> teams);


	void static handleTeamExistance(map<string, Teams> teams, Teams& TeamToBeModified, string teamName);
	//teams
	void static TeamMenu(map<string, Teams> teams);
	void static ModifyTeams(map<string, Teams> teams);
	void static displayTeamsForSpecificLeague(vector<TheLeague> leagues);

	//leagues
	void static LeaguesMenu(vector<TheLeague> leagues, map<string, Teams> teams);
	void static DisplayAllLeagues(vector<TheLeague> allleagues);
	void static UpdateLeagueName(vector<TheLeague> leagues);
	void DeleteLeague(void);

	void static PauseAndClear();
};
