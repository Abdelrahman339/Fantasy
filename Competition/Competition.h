#include <iostream>
#include <queue>
#include <vector>
#include "Game/Game.h"
using namespace std;

class competition {

protected:


    const static int goalPoints = 4;
    const static int assistPoints = 2;
    const static int cleanSheetPoints = 3;
    const static int redCardDeduction = 2;
    const static int yellowCardDeduction = 1;
    const static int numOfPlayers = 22;




    void static UpdateFootballerPoints(queue<Game>& GameHighlights, list<FootballerInTheMatch>& players) ; // updating all the players in a game
    void static UpdateFootballerPrice() ;//based on points for EVERY player (even if not in user's squad)
    bool checkPosition(queue<Game>& GameHighlights,string& footballerPosition) ;
    void addPointsToMOTM(queue<Game>& GameHighlights) ; //Adds extra points to the man of the match
    string priceCalculation(list<FootballerInTheMatch>& player); //containing five tiers for changing the players price 
    
    
};
