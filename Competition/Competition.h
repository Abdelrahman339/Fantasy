#include <iostream>
#include <queue>
#include "Game/Game.h"
using namespace std;

class competition {

protected:

    void static UpdateFootballerPoints(queue<Game>& GameHighlights , int CurrentGoals, int CurrentAssists, bool redCard, bool yellowCard, bool cleanSheet) {};
    void static UpdateFootballerPrice() {};//based on points for EVERY player (even if not in user's squad)
    bool checkPosition(string& footballerName, queue<Game>& GameHighlights) {};
    void addPointsToMOTM(queue<Game>& GameHighlights) {}; //Adds extra points to the man of the match
};
