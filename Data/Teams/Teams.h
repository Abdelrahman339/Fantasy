#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Teams
{
    int points;
    string name;
    string id;
    //vector of footballer size[11];
};

class Footballer //the squad that the user own's
{
protected:
    //static
    string name;
    int age;
    string team;
    string position;
    //dynamic
    float price;
    float rating;
    bool captain;
    // per season
    int totalGoals;      
    int totalAssists;    
    int totalRedCard;    
    int totalYellowCard; 
    int totalCleansheets;
    //per match 
    int goals;
    int points; // footballer points should be intialized as 1 as he starts in the starting eleven
    int assists;
    bool redCards;
    bool yellowCards;
    bool cleanSheets; // For updating goalKeepers and defenders points
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
