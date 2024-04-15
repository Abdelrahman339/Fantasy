#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Game
{
protected:

    void static UpdateFootballerPoints(/*FootballerName  ,*/ int CurrentGoals, int CurrentAssists, bool redCard, bool yellowCard, bool cleanSheet) {};
    void static UpdateFootballerPrice() {};//based on points
    bool checkPosition() {};//will be used in  UpdateFootballerPoints function
};
class footballPlayer
{
    string name;
    float rating;
    int goals;
    int assists;
    bool redCards;
    bool yellowCards;
    bool cleanSheets; // For updating goalKeepers and defenders points
};