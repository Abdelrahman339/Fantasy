#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Game
{
};
class FootballerInTheMatch //the team that will play the match (11 footballer from the same team)
{
    string name;
    string position;
    float rating;
    int goals;
    int points;
    int assists;
    bool redCards;
    bool yellowCards;
    bool cleanSheets; // For updating goalKeepers and defenders points
};
