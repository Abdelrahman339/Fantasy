#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include "User.h"
#include "Teams.h"
#include"Leagues.h"
using namespace std;
class Admin
{
protected:




public:

	//admin
	bool CheckAdmin();
	void AdminMenu(unordered_map<string, User>& Users, map<string, Teams>& teams, vector<League> leagues);

private:
	//users
	void AboutUsers(unordered_map<string, User>& Users);
	void DisplayAllUsers(unordered_map<string, User>& Users);
	void ShowAndEditUser(unordered_map<string, User>& Users);
	void ViewProfile(unordered_map<string, User>& Users, User CurrentUser);
	void EditProfile(unordered_map<string, User>& Users, User CurrentUser);
	void UserSquadAndPlayers(unordered_map<string, User>& Users);
	void DeleteUser(unordered_map<string, User>& Users);
	void Deletion(unordered_map<string, User>& Users, User DeletedUser);


	//players
	void static handleFootballerExistance(unordered_map<string, Footballer> players, Footballer& PlayerToBeModified, string& playerName);

	void FootballerMenu(unordered_map<string, Footballer>& players);
	void ModifyFootballer(unordered_map<string, Footballer> players, Footballer& footballerToBeModified);
	void DisplayFootballersForSpecificTeam(map<string, Teams> teams);


	void static handleTeamExistance(map<string, Teams> teams, Teams& TeamToBeModified, string teamName);
	//teams
	void TeamMenu(map<string, Teams> teams);
	void static ModifyTeams(map<string, Teams> teams);
	void displayTeamsForSpecificLeague(vector<League> leagues);

	//leagues
	void LeaguesMenu(vector<League> leagues, map<string, Teams> teams);
	void static DisplayAllLeagues(vector<League> allleagues);
	void UpdateLeagueName(vector<League> leagues);
	void DeleteLeague(void);

	void PauseAndClear();
};

//vector<League> allleagues
//unordered_map of user
//map ll team
//unordered map ll footballer