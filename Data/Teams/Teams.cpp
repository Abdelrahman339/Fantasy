#include "Teams.h"

Teams::Teams() {
	this->name = "";
	this->points = 0;
	this->wins = 0;
	this->lose = 0;
	this->draw = 0;
}

Teams::Teams(string name, int points, int wins, int lose, int draw, unordered_map<string, Footballer> footballers) {
	this->name = name;
	this->points = points;
	this->wins = wins;
	this->lose = lose;
	this->draw = draw;
	this->players = footballers;
}

unordered_map<string, Footballer> Teams::getFootballPlayer()
{
	return this->players;
}
Teams Teams::getTeamByName(map<string, Teams> teams, string name) {
	return teams.at(name);
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
Teams Teams::getTeamByName(vector<League> allleagues, string teamName) {
	Teams team;

	for (size_t i = 0; i < allleagues.size(); i++) {
		try {
			team = allleagues[i].GetTeams().at(teamName);
			break;
		}
		catch (const std::exception&) {
			cout << "Couldn't find the specified team";
			return {};
		}
	}
	return team;
}
Footballer* Teams::getFootballerByTeamName(Teams team, string footballerName)
{
	Footballer* footballerToBeUpdated;
	*footballerToBeUpdated = team.getFootballPlayer().at(footballerName);
	return footballerToBeUpdated;
}
