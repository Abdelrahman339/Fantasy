#pragma once
#include <iostream>
#include <unordered_map>
#include <string>
#include "Teams.h"
#include <vector>
#include <map>
#include "Game.h"

using namespace std;

class League {
private:
	string name;
	map <string, Teams> teams;

public:
	League();
	League(string name, map <string, Teams> teams);
	void displayTeams(unordered_map<string, Teams>& Teams);
	void updatePoints( list <Game> allgames);
	void displayPointTable();

	map <string, Teams> GetTeams();

};