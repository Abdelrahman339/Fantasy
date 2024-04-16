#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Teams
{
    int points;
};

class Footballer //the squad that the user own's
{
protected:
    string name;
    int age;
    string position;
    float price;
    bool captain;
    string team;
    int goals;      // per season
    int assists;    // per season
    int redCard;    // per season
    int yellowCard; // per season
public:
    void SetName(string name);
    void SetAge(int age);
    void SetPosition(string position);
    void SetPrice(float price);
    void SetCaptain(bool Captaine);
    void SetGoals(int goals);
    void SetAssists(int assists);
    void SetRedCard(int redCard);
    void SetYellowCard(int yellowCard);
    void SetTeam(string team);
    string GetName();
    int GetAge();
    string GetPosition();
    float GetPrice();
    bool GetCaptain();
    int GetGoals();
    int GetAssists();
    int GetRedCard();
    int GetYellowCard();
    string GetTeam();
};
