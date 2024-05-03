#pragma once
#include <iostream>
#include "Teams.h"
#include <map>
using namespace std;
class League
{
public:
	string name;
	map <string, Teams> teams;

public:
	League();
	League(string name, map <string, Teams> teams);
	//void displayTeams(unordered_map<string, Teams> & Teams);
	//void updatePoints( list <Game> allgames);
	//void displayPointTable();

	map <string, Teams> GetTeams();

};