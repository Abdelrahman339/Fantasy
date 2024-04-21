#include <iostream>	
#include "Teams.h"
#include <vector>
string Footballer::GetName() {
	return this->name;
}

void Footballer::SetName(string name) {
	this->name = name;
}

int Footballer::GetAge() {
	return age;
}

void Footballer::SetAge(int age) {
	this->age = age;
}

void Footballer::SetTeam(string team) {
	this->team = team;
}

string Footballer::GetTeam() {
	return team;
}
string Footballer::GetPosition() {
	return position;
}

void Footballer::SetPosition(string position) {
	this->position = position;
}

float Footballer::GetPrice() {
	return price;
}

void Footballer::SetPrice(float price) {
	this->price = price;
}

bool Footballer::GetCaptain() {
	return captain;
}

void Footballer::SetCaptain(bool captain) {
	this->captain = captain;
}

int Footballer::GetGoals() {
	return goals;
}

void Footballer::setGoals(int goals) {
	this->goals = goals;
}

int Footballer::GetAssists() {
	return assists;
}

void Footballer::setAssists(int assists) {
	this->assists = assists;
}

bool Footballer::GetRedCard() {
	return redCards;
}

void Footballer::setRedCard(bool redCard) {
	this->redCards = redCard;
}

bool Footballer::GetYellowCards() {
	return yellowCards;
}

void Footballer::setYellowCards(bool yellowCard) {
	this->yellowCards = yellowCard;
}

bool  Footballer::GetCleanSheets() {
	return cleanSheets;
}
int Footballer::GetPoints() {
	return points;
}
void Footballer::setCleanSheets(bool cleanSheet) {
	this->cleanSheets = cleanSheet;
};
void Footballer::setPoints(int points) {
	this->points = points;
};
void Footballer::SetRating(float rating) {
	this->rating = rating;
};
void Footballer::SetTotalGoals(int goals) {
	this->totalGoals = goals;
};
void Footballer::SetTotalAssists(int assists) {
	this->totalAssists = assists;
};
void Footballer::SetTotalYellowcard(int yellowCard) {
	this->totalYellowCard = yellowCard;
};
void Footballer::SetTotalRedCard(int redCard) {
	this->totalRedCard = redCard;
};
int Footballer::GetTotalGoals() {
	return totalGoals;
}
int Footballer::GetTotalAssists() {
	return totalAssists;
}
int Footballer::GetTotalRedCard() {
	return totalRedCard;
}
int Footballer::GetTotalYellowCard() {
	return totalYellowCard;
}
int Footballer::GetTotalCleansheets() {
	return totalCleansheets;
}

int Footballer::GetTotalpoints() {
	return totalPoints;
}

void Footballer::SetTotalCleansheets(int cleanSheets) {
	this->totalCleansheets = cleanSheets;
};
void Footballer::SetTotalpoints(int points) {
	this->totalPoints = points;
};

vector<Footballer> Teams::getFootballPlayer(int index) {
	return footballPlayers[index];
}

int Teams::getScore() {
	return score;
}