#include "Teams.h"

//Teams::Teams()
//{
//
//	this->name = "";
//	this->points = 0;
//	this->wins = 0;
//	this->lose = 0;
//	this->draw = 0;
//
//}
//
//Teams::Teams(string name, int points, int wins, int lose, int draw, unordered_map<string, Footballer> players)
//{
//	this->name = name;
//	this->points = points;
//	this->wins = wins;
//	this->lose = lose;
//	this->draw = draw;
//	this->players = players;
//}

unordered_map<string, Footballer> Teams::getFootballPlayer()
{
	return this->players;
}

string Teams::getName()
{
	return name;
}

int Teams::getwins()
{
	return wins;
}

int Teams::getlose()
{
	return lose;
}

int Teams::getdraw()
{
	return draw;
}

int Teams::getPoints()
{
	return points;
}

void Teams::SetPoints(int num)
{
	this->points = num;
}

void Teams::addPoints(int num)
{
	points += num;
}
