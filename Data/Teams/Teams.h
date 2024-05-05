#ifndef TEAMS_H
#define TEAMS_H

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include "Footballer.h"
//#include "Game.h"

//using namespace std;

using namespace std;

class Teams
{
protected:
	string name;
	int points;
	int wins;
	int lose;
	int draw;

	unordered_map<string, Footballer> players;

public:
	Teams();

	Teams(string name, int points, int wins, int lose, int draw, unordered_map<string, Footballer> footballers);
	unordered_map<string, Footballer>getFootballPlayer();
	Teams static getTeamByName(map<string, Teams> teams, string name);

	string getName();
	int getwins();
	int getlose();
	int getdraw();
	int getPoints();
	void SetPoints(int num);
	void addPoints(int num);

	void SetName(string);
	//Footballer getFootballerByTeamName(Teams team, string footballerName);
	unordered_map<string, Footballer> getFootballersByTeam(Teams team);

};

#endif

