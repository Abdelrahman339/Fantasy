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
	void static displayTeams(map<string, Teams> Teams);
	string static checkStrLengthTeams(const std::string& str);
	//void updatePoints( list <Game> allgames);
	//void displayPointTable();


	string getLeagueName();
	void setLeagueName(string);

	map <string,Teams>& GetTeams();


private:

};
