#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Game
{
protected:

    void static UpdateFootballerPoints(/*FootballerName  ,*/ int CurrentGoals, int CurrentAssists, bool redCard, bool yellowCard, bool cleanSheet) {};
    void static UpdateFootballerPrice() {};//based on points
    bool checkPosition(FootballerInTheMatch& player) {
    
    };
};
class FootballerInTheMatch //the team that will play the match (11 footballer from the same team)
{
    string name;
    string position;
    float rating;
    int goals;
    int assists;
    bool redCards;
    bool yellowCards;
    bool cleanSheets; // For updating goalKeepers and defenders points
};
