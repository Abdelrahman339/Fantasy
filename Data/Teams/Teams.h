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


    ////////////////////////////////////////////////////////////////////////
    /////////////////// setters and getters ////////////////////////////////
    ////////////////////////////////////////////////////////////////////////
public:
    void SetName(string name);
    void SetAge(int age);
    void SetPosition(string position);
    void SetPrice(float price);
    void SetCaptain(bool Captaine);
    void SetTotalGoals(int goals);
    void SetTotalAssists(int assists);
    void SetTotalRedCard(int redCard);
    void SetTotalCleansheets(int yellowCard);
    void SetTeam(string team);
    //per match
    void setGoals(int goals);
    void setAssists(int assists);
    void setYellowCards(bool card);
    void setRedCard(bool card);
    void setCleanSheets(bool cleanSheet);
    void setPrice(float price);
    void setPoints(int points);



    string GetName();
    int GetAge();
    string GetPosition();
    float GetPrice();
    bool GetCaptain();
    int GetTotalGoals();
    int GetTotalAssists();
    int GetTotalRedCard();
    int GetTotalYellowCard();
    string GetTeam();

    int getGoals();
    int getAssists();
    bool getYellowCards();
    bool getRedCard();
    bool getCleanSheets();
    float getPrice();
    int getPoints();

};
