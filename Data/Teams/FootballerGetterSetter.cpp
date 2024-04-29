#include <iostream>	
#include "Teams.h"
#include <vector>
string Footballer::GetName() {
	return this->name;
}

//Footballer::Footballer(string name, int age, string team, string position, float price, float rating, bool captain, bool matchWinner, int totalGoals, int totalAssists, int totalRedCard, int totalYellowCard, int totalCleansheets, int totalPoints)
//{
//	this->name = name;
//	this->age = age;
//	this->team = team;
//	this->position = position;
//	this->price = price;
//	this->rating = rating;
//	this->captain = captain;
//	this->matchWinner = matchWinner;
//	this->totalGoals = totalGoals;
//	this->totalAssists = totalAssists;
//	this->totalRedCard = totalRedCard;
//	this->totalYellowCard = totalYellowCard;
//	this->totalCleansheets = totalCleansheets;
//	this->totalPoints = totalPoints;
//}

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
}
void Footballer::AddTotalpoints(int points)
{
	this->totalPoints += points;
}
;


