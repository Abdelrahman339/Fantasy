#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

//#include "Game.h"
#include "Footballer.h"
#include "User.h"
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
	//Teams static getTeamByName(map<string, Teams> teams, string name);

	string getName();
	int getwins();
	int getlose();
	int getdraw();
	int getPoints();
	void SetPoints(int num);
	void addPoints(int num);

	//Teams static getTeamByName(vector<League> allleagues, string teamName);

	//Footballer* getFootballerByTeamName(Teams team, string footballerName);

};
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



