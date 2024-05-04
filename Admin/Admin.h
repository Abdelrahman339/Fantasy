#pragma once
#include <iostream>
#include <vector>
#include "list"
#include "queue"
#include "User.h"
#include "unordered_map"
#include "Teams.h"
#include "TheLeague.h"
using namespace std;
class Admin
{
protected:




public:

	//admin
	void static CheckAdmin(unordered_map<string, User>& Users);

	void static AdminMenu(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League*/);

	//users
	void static AboutUsers(unordered_map<string, User>& Users/*, unordered_map<string, Teams>& Team, unordered_map<string, Leagues>& League*/);
	void static DisplayAllUsers(unordered_map<string, User>& Users);
	void static ShowAndEditUser(unordered_map<string, User>& Users);
	void static ViewProfile(unordered_map<string, User>& Users, User& CurrentUser);
	void static EditProfile(unordered_map<string, User>& Users, User& CurrentUser);
	void static EditBalancePointsRank(User& CurrentUser, int choice, string information);
	bool static CheckBalancePointsRank(string information);
	void static UserSquadAndPlayers(unordered_map<string, User>& Users);
	void static DeleteUser(unordered_map<string, User>& Users);
	void static Deletion(unordered_map<string, User>& Users, User DeletedUser);

	//teams
	//void displayTeamsForSpecificLeague(unordered_map<string, League> leagues);
	//Footballer* getFootballerToBeUpdated(vector<League> allleagues, string teamName, string footballerName);
	//void updateFootballer(Footballer* footballerToBeUpdated, vector<League> allleagues, string teamName, string footballerName);
	//void DeletePlayersInTeam(string Leaguename, map <string, Teams> teams);

	//leagues
	//void DisplayAllLeagues(void);
	//void UpdateLeague(void);
	//void DeleteLeague(void);
	void static PauseAndClear();
};