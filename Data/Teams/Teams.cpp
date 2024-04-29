#include "Teams.h"

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
