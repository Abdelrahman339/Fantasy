#pragma once
#include <iostream>
#include <string>
#include "Teams.h"
#include <map>
using namespace std;
class TheLeague
{
protected:
	string name;
	map <string, Teams> teams;

public:
	TheLeague();
	TheLeague(string name, map <string, Teams> teams);
	//void displayTeams(unordered_map<string, Teams> & Teams);
	//void updatePoints( list <Game> allgames);
	//void displayPointTable();

	map <string, Teams> GetTeams();


private:

};
