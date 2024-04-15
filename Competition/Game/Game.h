#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Game
{
protected:

    void static UpdateFootballerPoints(/*FootballerName  ,*/ int CurrentGoals, int CurrentAssists, bool redCard, bool yellowCard, bool cleanSheet) {};
    void static UpdateFootballerPrice() {};//based on points
    bool checkPosition(footballPlayer& player) {
    
class footballPlayer
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