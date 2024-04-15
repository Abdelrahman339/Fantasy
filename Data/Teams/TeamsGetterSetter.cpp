#include <iostream>	
#include "Teams.h"
string Footballer::GetName()  {
    return this->name;
}

void Footballer::SetName(string name) {
    this->name = name;
}

int Footballer::GetAge()  {
    return age;
}

void Footballer::SetAge(int age) {
    this->age = age;
}

string Footballer::GetPosition()  {
    return position;
}

void Footballer::SetPosition(string position) {
    this->position = position;
}

float Footballer::GetPrice()  {
    return price;
}

void Footballer::SetPrice(float price) {
    this->price = price;
}

bool Footballer::GetCaptain()  {
    return captain;
}

void Footballer::SetCaptain(bool captain) {
    this->captain = captain;
}

int Footballer::GetGoals()  {
    return goals;
}

void Footballer::SetGoals(int goals) {
    this->goals = goals;
}

int Footballer::GetAssists()  {
    return assists;
}

void Footballer::SetAssists(int assists) {
    this->assists = assists;
}

int Footballer::GetRedCard()  {
    return redCard;
}

void Footballer::SetRedCard(int redCard) {
    this->redCard = redCard;
}

int Footballer::GetYellowCard()  {
    return yellowCard;
}

void Footballer::SetYellowCard(int yellowCard) {
    this->yellowCard = yellowCard;
}
void Footballer::SetTeam(string team) {
    this->team = team;
}string Footballer::GetTeam() {
    return team;
}